#include "MyForm.h"
#include <iostream>
#include "functions.h"
#include "fpecs_des.h"
#include <string>
#include <chrono>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main() 
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	fpecsdesgui::MyForm frm;
	Application::Run(% frm);
}

System::Void fpecsdesgui::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ openDlg = gcnew OpenFileDialog();
	openDlg->Filter = "Text Files(*.TXT)|*.TXT|All files (*.*)|*.*";
	openDlg->ShowDialog();

	textBox1->Text = openDlg->FileName;	
	return System::Void();
}

System::Void fpecsdesgui::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ openDlg = gcnew OpenFileDialog();
	openDlg->Filter = "Text Files(*.TXT)|*.TXT|All files (*.*)|*.*";
	openDlg->ShowDialog();

	textBox2->Text = openDlg->FileName;
	return System::Void();
}

System::Void fpecsdesgui::MyForm::radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if(flag_textCng->Text == "0")
	{
		textBox2->Text = "_encrypted.txt";
		textBox1->Text = "_source.txt";
	}
	return System::Void();
}

System::Void fpecsdesgui::MyForm::radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (flag_textCng->Text == "0")
	{
		textBox2->Text = "_decrypted.txt";
		textBox1->Text = "_encrypted.txt";
	}

	return System::Void();
}

System::Void fpecsdesgui::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	char* param_ekey = Convert_String_to_char(textBox3->Text);
	string param_ipath;
	Convert_String_to_string(textBox1->Text, param_ipath);

	string param_opath;
	Convert_String_to_string(textBox2->Text, param_opath);

	if (radioButton2->Checked)
		MessageBox::Show(Convert_string_to_String( to_string( main_des_gui( "-e", param_ekey, param_ipath, param_opath) ) + " ms" ) );
	else
		MessageBox::Show(Convert_string_to_String( to_string( main_des_gui( "-d", param_ekey, param_ipath, param_opath) ) + " ms" ) );
	
	return System::Void();
}

System::Void fpecsdesgui::MyForm::flag_textCng_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void fpecsdesgui::MyForm::textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox3->Text->Length == 16)
		button3->Enabled = true;
	else
		button3->Enabled = false;
	
	return System::Void();
}

System::Void fpecsdesgui::MyForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{	
	flag_textCng->Text = "1";
	
	return System::Void();
}

System::Void fpecsdesgui::MyForm::textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	flag_textCng->Text = "1";

	return System::Void();
}
