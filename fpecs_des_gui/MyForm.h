#pragma once

namespace fpecsdesgui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::TextBox^ flag_textCng;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->flag_textCng = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(52, 74);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"_source.txt";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(158, 74);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(24, 20);
			this->button1->TabIndex = 0;
			this->button1->Text = L"...";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(52, 100);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"_encrypted.txt";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(158, 100);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(24, 20);
			this->button2->TabIndex = 2;
			this->button2->Text = L"...";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox3
			// 
			this->textBox3->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->textBox3->Location = System::Drawing::Point(52, 126);
			this->textBox3->MaxLength = 16;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(130, 20);
			this->textBox3->TabIndex = 4;
			this->textBox3->Text = L"KEY";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(52, 152);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(130, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Go";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(119, 40);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(62, 17);
			this->radioButton1->TabIndex = 6;
			this->radioButton1->Text = L"Decrypt";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Checked = true;
			this->radioButton2->Location = System::Drawing::Point(52, 40);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(61, 17);
			this->radioButton2->TabIndex = 7;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Encrypt";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// flag_textCng
			// 
			this->flag_textCng->Location = System::Drawing::Point(12, 12);
			this->flag_textCng->Name = L"flag_textCng";
			this->flag_textCng->Size = System::Drawing::Size(17, 20);
			this->flag_textCng->TabIndex = 8;
			this->flag_textCng->Text = L"0";
			this->flag_textCng->Visible = false;
			this->flag_textCng->TextChanged += gcnew System::EventHandler(this, &MyForm::flag_textCng_TextChanged);
			// 
			// MyForm
			// 
			this->AcceptButton = this->button3;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(232, 220);
			this->Controls->Add(this->flag_textCng);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->Text = L"Cypher";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {};
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e); 
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void flag_textCng_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e);
};
}
