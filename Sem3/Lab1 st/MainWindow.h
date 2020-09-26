#pragma once

namespace Lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ InfoBox;
	private: System::Windows::Forms::TextBox^ InputBox;
	private: System::Windows::Forms::TextBox^ OutputBox;
	private: System::Windows::Forms::Button^ CalculateButton;

	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->InfoBox = (gcnew System::Windows::Forms::TextBox());
			this->InputBox = (gcnew System::Windows::Forms::TextBox());
			this->OutputBox = (gcnew System::Windows::Forms::TextBox());
			this->CalculateButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// InfoBox
			// 
			this->InfoBox->BackColor = System::Drawing::SystemColors::Control;
			this->InfoBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->InfoBox->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->InfoBox->Enabled = false;
			this->InfoBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->InfoBox->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->InfoBox->Location = System::Drawing::Point(12, 2);
			this->InfoBox->Multiline = true;
			this->InfoBox->Name = L"InfoBox";
			this->InfoBox->ReadOnly = true;
			this->InfoBox->ShortcutsEnabled = false;
			this->InfoBox->Size = System::Drawing::Size(221, 49);
			this->InfoBox->TabIndex = 0;
			this->InfoBox->Text = L"—ложение чисел в 12й системе счистлени€";
			this->InfoBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// InputBox
			// 
			this->InputBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->InputBox->Location = System::Drawing::Point(12, 57);
			this->InputBox->Multiline = true;
			this->InputBox->Name = L"InputBox";
			this->InputBox->Size = System::Drawing::Size(213, 50);
			this->InputBox->TabIndex = 1;
			this->InputBox->Text = L"„исла здесь";
			// 
			// OutputBox
			// 
			this->OutputBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OutputBox->Location = System::Drawing::Point(12, 155);
			this->OutputBox->Multiline = true;
			this->OutputBox->Name = L"OutputBox";
			this->OutputBox->Size = System::Drawing::Size(213, 30);
			this->OutputBox->TabIndex = 1;
			this->OutputBox->Text = L"–езультат здесь";
			// 
			// CalculateButton
			// 
			this->CalculateButton->Location = System::Drawing::Point(62, 231);
			this->CalculateButton->Name = L"CalculateButton";
			this->CalculateButton->Size = System::Drawing::Size(97, 37);
			this->CalculateButton->TabIndex = 2;
			this->CalculateButton->Text = L"—ложить";
			this->CalculateButton->UseVisualStyleBackColor = true;
			this->CalculateButton->Click += gcnew System::EventHandler(this, &MainWindow::CalculateButton_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(237, 324);
			this->Controls->Add(this->CalculateButton);
			this->Controls->Add(this->OutputBox);
			this->Controls->Add(this->InputBox);
			this->Controls->Add(this->InfoBox);
			this->ForeColor = System::Drawing::Color::Black;
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void CalculateButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
