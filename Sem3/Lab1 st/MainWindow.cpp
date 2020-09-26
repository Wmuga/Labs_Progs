#include "MainWindow.h"
#include "Windows.h"
#include "Converter.h"
#include <algorithm>
#include <iterator>
#include <msclr\marshal_cppstd.h>
#include <stdexcept>
using namespace Lab1;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MainWindow);
    return 0;
}

System::Void Lab1::MainWindow::CalculateButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    msclr::interop::marshal_context context;
    std::string inputText = context.marshal_as<std::string>(this->InputBox->Text);
    auto place = std::find(inputText.begin(), inputText.end(), '\n');

    std::string buffer;
    std::copy(inputText.begin(), place-1, std::back_inserter(buffer));
    
    try {
        double n1 = converter::stod(buffer, 12);
        buffer = "";
        auto place2 = std::find(place + 1, inputText.end(), '\n');
        if (place == inputText.end() || place == inputText.end() - 1 || place2 != inputText.end()) this->OutputBox->Text = "Неверные входные данные";
        else {
            std::copy(place + 1, place2, std::back_inserter(buffer));
            double n2 = converter::stod(buffer, 12);

            this->OutputBox->Text = context.marshal_as<System::String^>(converter::dtos(n1 + n2, 12));
        }
    }
    catch (const std::invalid_argument&) {
        this->OutputBox->Text = "Неверные входные данные";
    }
    return System::Void();
}
