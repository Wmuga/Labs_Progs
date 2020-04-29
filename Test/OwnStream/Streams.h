#include <sstream>
#include <string>
#include <vector>

using namespace std;

class numfilterbuf : public streambuf {
private:
    istream *in;
    ostream *out;

    int cur; //последнее считанное значение, используется в underflow()
protected:

    /* функции записи в поток: */

    virtual int overflow(int c) override {
        if (c == traits_type::eof()){
            return traits_type::eof();
        }

        char_type ch = static_cast<char_type>(c);
        if (ch == ' ' || (ch >= '0' && ch <= '9')){ // отдаем пробелы и цифры
            out->put(ch);
            //если что-то не записалось, отдаем EOF
            return out->good() ? ch : traits_type::eof();
        }

        return ch;
    }

    /* функции чтения из потока: */

    //реализация по-умолчанию инкрементирует позицию указателя в буфере и вызывает segmentation fault
    virtual int uflow() override {
        int c = underflow();
        cur = traits_type::eof(); //говорим underflow() считать следующий символ при следующем вызове
        return c;
    }

    virtual int underflow() override {
        if (cur != traits_type::eof()){
            return cur;
        }

        // пока можем читать, читаем
        while (in->good()){
            cur = in->get();
            if (cur == traits_type::eof()){
                return traits_type::eof();
            }

            char_type ch = static_cast<char_type>(cur);
            if (ch == ' ' || (ch >= '0' && ch <= '9')){ // отдаем только пробелы и цифры
                return ch;
            }
        }

        return traits_type::eof();
    }
public:
    numfilterbuf(istream &_in, ostream &_out)
            : in(&_in), out(&_out), cur(traits_type::eof())
    {}
};

class blockoutputbuf : public streambuf {
private:
    ostream *out;
    vector<char_type> buffer;
    string startb, endb;
protected:
    virtual int overflow(int c) override {
        if (out->good() && c != traits_type::eof()){
            *pptr() = c; //тут нам пригодился 1 "лишний" символ, убранный в конструкторе
            pbump(1); //смещаем указатель позиции буфера на реальный конец буфера
            return sync() == 0 ? c : traits_type::eof();
        }

        return traits_type::eof();
    }

    virtual int sync() override {
        if (pptr() == pbase()) //если буфер пуст, то и синхронизировать нечего
            return 0;

        ptrdiff_t sz = pptr() - pbase(); //вычисляем, сколько символов записано в буффер

        //заворачиваем буфер в наш блок
        *out << startb;
        out->write(pbase(), sz);
        *out << endb;

        if (out->good()){
            pbump(-sz); //при успехе перемещаем указатель позиции буфера в начало
            return 0;
        }

        return -1;
    }
public:
    blockoutputbuf(ostream &_out, size_t _bufsize, string _startb, string _endb)
            : out(&_out), buffer(_bufsize), startb(_startb), endb(_endb)
    {
        char_type *buf = buffer.data();
        setp(buf, buf + (buffer.size() - 1)); // -1 для того, чтобы упростить реализацию overflow()
    }
};