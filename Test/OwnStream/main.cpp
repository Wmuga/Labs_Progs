#include <iostream>
#include "Streams.h"


int main(int argc, char **argv){
    const char str1[] = "In 4 bytes contains 32 bits";
    const char str2[] = "Unix time starts from Jan 1, 1970";
    istringstream str(str1);

    numfilterbuf buf(str, cout); // читать из stringstream, выводить в консоль
    iostream numfilter(&buf); // таким образом обходимся без реализации своего наследника iostream

    string val;
    getline(numfilter, val);
    numfilter.clear(); // сбросить невалидное состояние после EOF в процессе чтения из stringstream

    cout << "Original: '" << str1 << "'" << endl;
    cout << "Read from numfilter: '" << val << "'" << endl;

    cout << "Original: '" << str2 << "'" << endl;
    cout << "Written to numfilter: '";
    numfilter << str2;
    cout << "'" << endl;

    blockoutputbuf blockOut(cout,10,"<s>","</s>");
    ostream outBlock(&blockOut);

    outBlock<<str1; outBlock.flush();

    return 0;
}