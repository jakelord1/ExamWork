#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "Functions.h"
using namespace std;

string GetWord() {
	ifstream in;
	string word;
	in.open("Words.txt");
	if (in.is_open()) {
		for (size_t i = 0; i < rand() % 10; i++)
		{
			getline(in, word);
			if (in.eof() || word == "") {
				in.seekg(ios::beg);
			}
		}
	}
	for (size_t i = 0; i < word.length(); i++)
	{
		word[i] -= 5;
	}
	in.close();
	return word;
}
void AddWord() {
	ofstream out;
	string word;
	out.open("Words.txt", ios::app);	

	cin >> word;
	for (size_t i = 0; i < word.length(); i++)
	{
		word[i] += 5;
	}
	out << '\n' << word;
}