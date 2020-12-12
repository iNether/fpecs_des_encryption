#include "functions.h"
#include <iostream>
#include <string>


using namespace System;
using namespace System::Windows::Forms;

std::string& Convert_String_to_string(String^ s, std::string& os) 
{
	using namespace Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return os;
}

String^ Convert_string_to_String(std::string& os, String^ s)
{
	s = gcnew String(os.c_str());

	return s;
}

std::string& Convert_String_to_string(String^ s)
{
	std::string os;
	using namespace Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();

	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return os;
}

String^ Convert_string_to_String(std::string& os)
{
	System::String^ s = gcnew String(os.c_str());

	return s;
}

String^ Convert_char_to_String(char ch)
{
	char* chr = new char();
	chr[0] = ch;
	String^ str;
	for (int i = 0; chr[i] != '\0'; i++)
	{
		str += wchar_t(ch);
	}

	return str;
}

String^ Convert_char_to_String(char* ch)
{
	char* chr = new char();
	chr = ch;
	String^ str;
	for (int i = 0; chr[i] != '\0'; i++)
	{
		str += wchar_t(ch[i]);
	}

	return str;
}

char* Convert_String_to_char(String^ string)
{
	using namespace System::Runtime::InteropServices;
	
	return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
}