#pragma once
#include <iostream>

using namespace System;

std::string& Convert_String_to_string(String^ s, std::string& os);
String^ Convert_string_to_String(std::string& os, String^ s);
std::string& Convert_String_to_string(String^ s);
String^ Convert_string_to_String(std::string& os);
String^ Convert_char_to_String(char* ch);
char* Convert_String_to_char(String^ string);
