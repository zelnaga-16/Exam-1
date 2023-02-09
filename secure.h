#pragma once
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;
class secure
{
	string dencrypt(string input);
    string encrypt(string input);
public:
	secure() = default;
	string Get_word(int& number_of_letters);
    void Add_word(string input);
};