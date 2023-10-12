#pragma once
#include "Statistic.h"
#include <iostream>
#include <string>
using namespace std;
class Word
{
	string word;
	string sword;
	Statistic gstats;
public:
	Word(string w) { 
		word = w;
		sword = word;
		for (size_t i = 0; i < word.length(); i++)
		{
			sword[i] = '_';
		}
		gstats.SetAtt(0);
		gstats.SetW(0);
	}
	bool GetLetter();
	bool WinLose();
	int GetWins() { return gstats.GetWin(); }
	int GetLoses() { return gstats.GetLose(); }
	Statistic GetStats() { return gstats; }
	void SetWins(int w) { gstats.SetW(w); }
	void SetLose(int l) { gstats.SetL(l); }
	void SetT(double t) { gstats.SetTime(t); }
};

