#include "Statistic.h"

void Statistic::StatsFromFile()
{
	ifstream in;
	string stoint;
	int i;
	in.open("Stats.txt");
	getline(in, stoint);
	wins = stoi(stoint);
	getline(in, stoint);
	loses = stoi(stoint);
	getline(in, stoint);
	attempts = stoi(stoint);
	getline(in, stoint);
	games = stoi(stoint);
	getline(in, stoint);
	time = stoi(stoint);
	in.close();
}

void Statistic::StatsInFile()
{
	ofstream out;
	out.open("Stats.txt");
	out << wins << '\n' << loses << '\n' << attempts << '\n' << games << '\n' << time << '\n';
	out.close();
}

void Statistic::ShowStatistic() const
{
	system("cls");
	int hours = 0, minutes = 0, seconds = 0;
	hours = (int)time / 60 / 60;
	minutes = (int)time / 60 - hours * 60;
	seconds = (int)time - minutes * 60 - hours * 60 * 60;
	cout << "Wins: " << wins
		<< "\nLoses: " << loses
		<< "\nAttempts: " << attempts
		<< "\nGames: " << games
		<< "\nSpent time in game: " << hours  << " hours\t" << minutes << " minutes\t" << seconds << " seconds" << endl;
}

void Statistic::ShowGameStats() const
{
	cout << "\nAttempts: " << attempts << "\nTime: " << time << " seconds\n";
}

Statistic& Statistic::operator+=(Statistic game)
{
	wins += game.GetWin();
	loses += game.GetLose();
	attempts += game.GetAtt();
	games += game.GetGames();
	time += game.GetTime();
	return *this;
}
