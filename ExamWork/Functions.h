#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "Statistic.h"
#include "Word.h"
using namespace std;

string GetWord();
void AddWord();
Statistic Game();
void Picture(int f);

string GetWord() {
	ifstream in;
	string word;
	in.open("Words.txt");
	if (in.is_open()) {
		for (size_t i = 0; i < rand() % 200; i++)
		{
			getline(in, word);
			if (in.eof() || word.length() < 2) {
				in.seekg(ios::beg);
				getline(in, word);
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
	system("cls");
	ofstream out;
	string word;
	out.open("Words.txt", ios::app);	
	cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
	cout << "| Adding new word\n| -> Enter word: ";
	cin >> word;
	cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
	for (size_t i = 0; i < word.length(); i++)
	{
		word[i] += 5;
	}
	ifstream in;
	string f;
	bool b = 0;
	in.open("Words.txt");
	if (in.is_open()) {
		while (!in.eof())
		{
			getline(in,f);
			if (word == f) {
				b = true;
				break;
			}
		}
	}
	if (!b) {
		cout << "| -> Word added!\n";
		cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
		out << '\n' << word;
		system("pause");
	}
	else {
		cout << "| -> This word is already in list!\n";
		cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
		system("pause");
	}
	in.close();
	out.close();
}

Statistic Game() {
	Word game_word(GetWord());
	time_t time1 = time(NULL);
	int fails = 0;
	while (game_word.GetLoses() != 1 && game_word.GetWins() != 1) {
		system("cls");
		Picture(fails);
		if (!game_word.GetLetter()) {
			fails++;
			if (fails >= 6) {
				system("cls");
				Picture(fails);
				game_word.SetLose(1);
			}
		}
	}
	cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
	if (game_word.GetWins()) {
		system("cls");
		Picture(fails);
		cout << "|  " << game_word.Wordw() << "\n| -> You won!";
	}
	if (game_word.GetLoses()) {
		system("cls");
		Picture(fails);
		cout << "|  " << game_word.Wordw() << "\n| -> You lose!";
	}
	cout << "\n+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";

	time_t time2 = time(NULL);
	game_word.SetT(difftime(time2, time1));
	game_word.Stats();
	cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
	return game_word.GetStats();
}


void Picture(int f) {
	switch (f) {
	case 0: {
		cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n" <<
				"|                              |\n" <<
				"|   Y----------Y               |\n" <<
				"|   |          |               |\n" <<
				"|   |          |               |\n" <<
				"|   |                          |\n" <<
				"|   |                          |\n" <<
				"|   |                          |\n" <<
				"|   |                          |\n" <<
				"|   |                          |\n" <<
				"|   |                          |\n" <<
				"|                              |\n" <<
				"+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
		break;
	}
	case 1: {
		cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n" <<
			"|                              |\n" <<
			"|   Y----------Y               |\n" <<
			"|   |          |               |\n" <<
			"|   |          |               |\n" <<
			"|   |          0               |\n" <<
			"|   |                          |\n" <<
			"|   |                          |\n" <<
			"|   |                          |\n" <<
			"|   |                          |\n" <<
			"|   |                          |\n" <<
			"|                              |\n" <<
			"+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
		break;
	}
	case 2: {
		cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n" <<
			"|                              |\n" <<
			"|   Y----------Y               |\n" <<
			"|   |          |               |\n" <<
			"|   |          |               |\n" <<
			"|   |          0               |\n" <<
			"|   |          I               |\n" <<
			"|   |          I               |\n" <<
			"|   |          I               |\n" <<
			"|   |                          |\n" <<
			"|   |                          |\n" <<
			"|                              |\n" <<
			"+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
		break;
	}
	case 3: {
		cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n" <<
			"|                              |\n" <<
			"|   Y----------Y               |\n" <<
			"|   |          |               |\n" <<
			"|   |          |               |\n" <<
			"|   |          0               |\n" <<
			"|   |         /I               |\n" <<
			"|   |        / I               |\n" <<
			"|   |          I               |\n" <<
			"|   |                          |\n" <<
			"|   |                          |\n" <<
			"|                              |\n" <<
			"+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
		break;
	}
	case 4: {
		cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n" <<
			"|                              |\n" <<
			"|   Y----------Y               |\n" <<
			"|   |          |               |\n" <<
			"|   |          |               |\n" <<
			"|   |          0               |\n" <<
			"|   |         /I\\              |\n" <<
			"|   |        / I \\             |\n" <<
			"|   |          I               |\n" <<
			"|   |                          |\n" <<
			"|   |                          |\n" <<
			"|                              |\n" <<
			"+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
		break;
	}
	case 5: {
		cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n" <<
			"|                              |\n" <<
			"|   Y----------Y               |\n" <<
			"|   |          |               |\n" <<
			"|   |          |               |\n" <<
			"|   |          0               |\n" <<
			"|   |         /I\\              |\n" <<
			"|   |        / I \\             |\n" <<
			"|   |          I               |\n" <<
			"|   |         /                |\n" <<
			"|   |        /                 |\n" <<
			"|                              |\n" <<
			"+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
		break;
	}
	case 6: {
		cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n" <<
			"|                              |\n" <<
			"|   Y----------Y               |\n" <<
			"|   |          |               |\n" <<
			"|   |          |               |\n" <<
			"|   |          0               |\n" <<
			"|   |         /I\\              |\n" <<
			"|   |        / I \\             |\n" <<
			"|   |          I               |\n" <<
			"|   |         / \\              |\n" <<
			"|   |        /   \\             |\n" <<
			"|                              |\n" <<
			"+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
		break;
	}
		
	}
}

