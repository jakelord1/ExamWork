#pragma once
#include <iostream>
#include <string>
#include <fstream>
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
	void StatsFromFile();
	void StatsInFile();

	void ShowStatistic() const;
	void ShowGameStats() const;

	void SetAtt(int a) { attempts = a; }
	void SetW(int a) { wins = a; }
	void SetL(int a) { loses = a; }
	void SetTime(double a) { time = a; }
	void SetGames(int a) { games = a; }
	int GetAtt() { return attempts; }
	int GetWin() { return wins; }
	int GetLose() { return loses; }
	int GetTime() { return time; }
	int GetGames() { return games; }

	Statistic& operator+=(Statistic game);
};

