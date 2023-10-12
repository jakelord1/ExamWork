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

Statistic Game() {
	Word game_word(GetWord());
	int fails = 0;
	time_t time1 = time(NULL);
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
	if (game_word.GetWins()) {
		system("cls");
		Picture(fails);
		cout << endl << game_word.Wordw() << "\nYou won!";
	}
		
	time_t time2 = time(NULL);
	game_word.SetT(difftime(time2, time1));
	return game_word.GetStats();
}


void Picture(int f) {
	switch (f) {
	case 0: {
		cout << "                     \n" <<
			"    Y----------Y     \n" <<
			"    |          |     \n" <<
			"    |          |     \n" <<
			"    |                \n" <<
			"    |                \n" <<
			"    |                \n" <<
			"    |                \n" <<
			"    |                \n" <<
			"    |                \n";
		break;
	}
	case 1: {
		cout << "                     \n" <<
			"    Y----------Y     \n" <<
			"    |          |     \n" <<
			"    |          |     \n" <<
			"    |          0     \n" <<
			"    |                \n" <<
			"    |                \n" <<
			"    |                \n" <<
			"    |                \n" <<
			"    |                \n";
		break;
	}
	case 2: {
		cout << "                     \n" <<
			"    Y----------Y     \n" <<
			"    |          |     \n" <<
			"    |          |     \n" <<
			"    |          0     \n" <<
			"    |          I     \n" <<
			"    |          I     \n" <<
			"    |          I     \n" <<
			"    |                \n" <<
			"    |                 \n";
		break;
	}
	case 3: {
		cout << "                     \n" <<
			"    Y----------Y     \n" <<
			"    |          |     \n" <<
			"    |          |     \n" <<
			"    |          0     \n" <<
			"    |         /I     \n" <<
			"    |        / I     \n" <<
			"    |          I     \n" <<
			"    |                \n" <<
			"    |                \n";
		break;
	}
	case 4: {
		cout << "                     \n" <<
			"    Y----------Y     \n" <<
			"    |          |     \n" <<
			"    |          |     \n" <<
			"    |          0     \n" <<
			"    |         /I\\   \n" <<
			"    |        / I \\  \n" <<
			"    |          I     \n" <<
			"    |                \n" <<
			"    |                \n";
		break;
	}
	case 5: {
		cout << "                     \n" <<
			"    Y----------Y     \n" <<
			"    |          |     \n" <<
			"    |          |     \n" <<
			"    |          0     \n" <<
			"    |         /I\\   \n" <<
			"    |        / I \\  \n" <<
			"    |          I     \n" <<
			"    |         /      \n" <<
			"    |        /        \n";
		break;
	}
	case 6: {
		cout << "                     \n" <<
			"    Y----------Y     \n" <<
			"    |          |     \n" <<
			"    |          |     \n" <<
			"    |          0     \n" <<
			"    |         /I\\   \n" <<
			"    |        / I \\  \n" <<
			"    |          I     \n" <<
			"    |         / \\   \n" <<
			"    |        /   \\  \n\n" <<
			"           You lose! \n";
		break;
	}
		
	}
}