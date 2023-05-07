#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <vector>
//#include <msclr\marshal_cppstd.h>
using namespace std;
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::Text;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:

		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
	private: System::Windows::Forms::Button^ input_file_button;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ input_textBox;

	private: System::Windows::Forms::RichTextBox^ input_richTextBox;
	private: System::Windows::Forms::RichTextBox^ output_richTextBox;
	private: System::Windows::Forms::Button^ compute_button;




	private: System::Windows::Forms::TextBox^ output_textBox;
	private: System::Windows::Forms::Button^ button1;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->input_file_button = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->input_textBox = (gcnew System::Windows::Forms::TextBox());
			this->input_richTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->output_richTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->compute_button = (gcnew System::Windows::Forms::Button());
			this->output_textBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// folderBrowserDialog1
			// 
			this->folderBrowserDialog1->ShowNewFolderButton = false;
			this->folderBrowserDialog1->HelpRequest += gcnew System::EventHandler(this, &Form1::folderBrowserDialog1_HelpRequest);
			// 
			// input_file_button
			// 
			this->input_file_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->input_file_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_file_button->Location = System::Drawing::Point(320, 491);
			this->input_file_button->Name = L"input_file_button";
			this->input_file_button->Size = System::Drawing::Size(115, 27);
			this->input_file_button->TabIndex = 0;
			this->input_file_button->Text = L"Select a file";
			this->input_file_button->UseVisualStyleBackColor = true;
			this->input_file_button->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"example1-10x5.txt";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// input_textBox
			// 
			this->input_textBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->input_textBox->Location = System::Drawing::Point(12, 12);
			this->input_textBox->Name = L"input_textBox";
			this->input_textBox->Size = System::Drawing::Size(715, 22);
			this->input_textBox->TabIndex = 1;
			this->input_textBox->Text = L"Selected file\'s path appears here.";
			this->input_textBox->TextChanged += gcnew System::EventHandler(this, &Form1::input_textBox_TextChanged);
			// 
			// input_richTextBox
			// 
			this->input_richTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->input_richTextBox->BackColor = System::Drawing::SystemColors::InfoText;
			this->input_richTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->input_richTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->input_richTextBox->ForeColor = System::Drawing::Color::Lime;
			this->input_richTextBox->Location = System::Drawing::Point(12, 40);
			this->input_richTextBox->Name = L"input_richTextBox";
			this->input_richTextBox->Size = System::Drawing::Size(715, 445);
			this->input_richTextBox->TabIndex = 2;
			this->input_richTextBox->Text = L"Selected file\'s contents appear here.";
			this->input_richTextBox->WordWrap = false;
			this->input_richTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::input_richTextBox_TextChanged);
			// 
			// output_richTextBox
			// 
			this->output_richTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->output_richTextBox->BackColor = System::Drawing::Color::Black;
			this->output_richTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->output_richTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->output_richTextBox->ForeColor = System::Drawing::Color::Lime;
			this->output_richTextBox->Location = System::Drawing::Point(747, 40);
			this->output_richTextBox->Name = L"output_richTextBox";
			this->output_richTextBox->Size = System::Drawing::Size(543, 445);
			this->output_richTextBox->TabIndex = 3;
			this->output_richTextBox->Text = L"Messages and Output file\'s contents appear here.";
			// 
			// compute_button
			// 
			this->compute_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->compute_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->compute_button->Location = System::Drawing::Point(999, 491);
			this->compute_button->Name = L"compute_button";
			this->compute_button->Size = System::Drawing::Size(87, 23);
			this->compute_button->TabIndex = 4;
			this->compute_button->Text = L"Compute";
			this->compute_button->UseVisualStyleBackColor = true;
			this->compute_button->Click += gcnew System::EventHandler(this, &Form1::compute_button_Click);
			// 
			// output_textBox
			// 
			this->output_textBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->output_textBox->Location = System::Drawing::Point(747, 12);
			this->output_textBox->Name = L"output_textBox";
			this->output_textBox->Size = System::Drawing::Size(543, 22);
			this->output_textBox->TabIndex = 5;
			this->output_textBox->Text = L"Default output location: folder where apication is present";
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(1184, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Select folder";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DimGray;
			this->ClientSize = System::Drawing::Size(1302, 529);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->output_textBox);
			this->Controls->Add(this->compute_button);
			this->Controls->Add(this->output_richTextBox);
			this->Controls->Add(this->input_richTextBox);
			this->Controls->Add(this->input_textBox);
			this->Controls->Add(this->input_file_button);
			this->Name = L"Form1";
			this->Text = L"2022291 Assignment IV";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void change_text() {
		String^ fileName = this->openFileDialog1->FileName;
		this->input_textBox->Text = fileName;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//this->folderBrowserDialog1->ShowDialog();
		this->openFileDialog1->ShowDialog();
		this->change_text();
		input_richTextBox_TextChanged(sender, e);
	}

	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
	private: System::Void input_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	
	// from System::String^ to std::string
	std::string toStandardString(System::String^ string) {
		using System::Runtime::InteropServices::Marshal;
		System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
		char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
		std::string returnString(charPointer, string->Length);
		Marshal::FreeHGlobal(pointer);
		return returnString;
	}

	private: System::Void input_richTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		std::fstream readfile(toStandardString(this->openFileDialog1->FileName), ios::in);
		std::string src1;
		std::string all_txt;
		while (getline(readfile, src1)) {
			all_txt += src1 + "\n";
		}
		readfile.close();
		String^ str2 = gcnew String(all_txt.c_str());
		this->input_richTextBox->Text = str2;

	}


//-----------------------------------------------------------------------------------------//
		   std::string Computing() {
			   std::fstream file;
			   std::string src1;

			   int number_of_zeros{ 0 };
			   
			   int number_of_polynomials;
			   int size_of_polynomials;

			   string input_file_name;

			   getline(cin, input_file_name);
			   file.open(toStandardString(this->openFileDialog1->FileName), ios::in);
			   file >> number_of_polynomials;
			   file >> size_of_polynomials;

			   char *polynomial = new char[number_of_polynomials * size_of_polynomials];
			   int *polynomial_in_int = new int[number_of_polynomials * size_of_polynomials];


			   for (int i = 0; i < number_of_polynomials; ++i)
				   for (int j = 0; j < size_of_polynomials; ++j)
					   file >> *(polynomial + i * size_of_polynomials + j);
			   file.close();

			   for (int i = 0; i < number_of_polynomials; ++i)
				   for (int j = 0; j < size_of_polynomials; ++j) {
					   if ((int)*(polynomial + i * size_of_polynomials + j) == 48) { *(polynomial_in_int + i * size_of_polynomials + j) = 0; number_of_zeros++; }
					   if ((int)*(polynomial + i * size_of_polynomials + j) == 49) *(polynomial_in_int + i * size_of_polynomials + j) = 1;
				   }

			   std::string output_file_name;
			   if (this->folderBrowserDialog1->SelectedPath->Length != 0) { output_file_name += toStandardString(this->folderBrowserDialog1->SelectedPath + "\\"); }
			   
			   output_file_name += "result_addition-";
			   output_file_name += std::to_string(number_of_polynomials) + "x" + to_string(size_of_polynomials) + ".txt";

			   std::fstream output_file(output_file_name, ios::out);
			   this->output_textBox->Text = gcnew String(output_file_name.c_str());
			   std::string out_res;
			   std::string other_info;
			   other_info += "example-" + to_string(number_of_polynomials) + "x" + to_string(size_of_polynomials) + "\n";
			   other_info += "number of polynomials: " + to_string(number_of_polynomials) + "\n";
			   cout << "number of variables: " << to_string(size_of_polynomials) + "\n";

			   output_file << "example-" << number_of_polynomials << "x" << size_of_polynomials << "\n";

			   string final{};

			   const auto time1 = chrono::system_clock::now();
			   int* result = new int[size_of_polynomials] {0};
			   for (int i = 0; i < number_of_polynomials; ++i)
			   {
				   for (int j = 0; j < size_of_polynomials; ++j) {
					   *(result + j) += *(polynomial_in_int + i * size_of_polynomials + j);
				   }
				   
			   }
			   const auto time2 = chrono::system_clock::now();
			   const auto TotalTime = chrono::duration_cast<chrono::milliseconds>(time2 - time1);
			   const auto TotalTime_in_nanoseconds = chrono::duration_cast<chrono::nanoseconds>(time2 - time1);

			   for (int i = 0; i < size_of_polynomials; ++i) {
				   out_res += to_string(*(result + i)) + " ";
				   output_file << *(result + i) << " ";
			   }

			   output_file.close();

			   //other_info += out_res + "\n";
			   other_info += "Total time taken for addition in milliseconds: " + to_string(TotalTime.count()) + "\n";
			   other_info += "Total time taken for addition in nanoseconds: " + to_string(TotalTime_in_nanoseconds.count()) + *"\n";
			   other_info += "A 2D array is used to represent the whole file.";
			   other_info += "\n";
			   other_info += "number of zeros: " + to_string(number_of_zeros) + "\n\n\t\t\tOUTPUT FILE\n\n";
			   other_info += "example-" + to_string(number_of_polynomials) + "x" + to_string(size_of_polynomials) + "\n";
			   other_info += out_res + "\n";
			   return other_info;
		   }



		  //-----------------------------------------------------------------------------------------//




private: System::Void compute_button_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ output_str = gcnew String(Computing().c_str());
	this->output_richTextBox->Text = output_str;
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	this->folderBrowserDialog1->ShowDialog();
	String^ str = this->folderBrowserDialog1->SelectedPath;
	this->output_textBox->Text = str;

}
private: System::Void folderBrowserDialog1_HelpRequest(System::Object^ sender, System::EventArgs^ e) {
}
};
}
