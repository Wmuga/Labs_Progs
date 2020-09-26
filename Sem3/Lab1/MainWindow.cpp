#include "MainWindow.h"
#include "windows.h"
#include "calculator.h"
#include <msclr\marshal_cppstd.h>

using namespace Lab1;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MainWindow);
    return 0;
}

System::Void Lab1::MainWindow::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string txt;
    msclr::interop::marshal_context context;
    txt = context.marshal_as<std::string>(this->textBox3->Text) + ";" + context.marshal_as<std::string>(this->textBox1->Text);
    std::stringstream out_stream;
    calculator Calc(txt,out_stream);
    this->textBox2->Text = context.marshal_as<System::String^>(out_stream.str());
    return System::Void();
}

System::Void Lab1::MainWindow::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string text = "������ ���� - ���� ����������\r\n���������:\"��� ����������\" = \'��������\'. ������ ���������� ����� ������\r\n";
    text+= "������ ���� - ���� ���������, ����������� \';\'.\r\n������ � ���������� ��������� ����� result\'N\',��� \'N\' - ����� ���������\r\n";
    text+="������ ���� - ���� ������";
    msclr::interop::marshal_context context;
    this->textBox2->Text = context.marshal_as<System::String^>(text);
    return System::Void();
}
