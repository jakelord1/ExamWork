#pragma once
#include <iostream>
#include <string>
using namespace std;
class Statistic
{
	int wins;
	int loses;
	double time;
	int attempts;
	int games;
public:
	Statistic() { wins = 0; loses = 0; time = 0, attempts = 0; games = 1; }
	void ShowStatistic() const;
	void SetAtt(int a) { attempts = a; }
	void SetW(int a) { wins = a; }
	void SetL(int a) { loses = a; }
	void SetTime(double a) { time = a; }
	int GetAtt() { return attempts; }
	int GetWin() { return wins; }
	int GetLose() { return loses; }
};

