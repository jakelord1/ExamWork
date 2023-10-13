#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>
#include "Functions.h"
using namespace std;

int main()
{
    srand(time(NULL));
    Statistic statisic;
    statisic.StatsFromFile();
    while (true) {
        cout << "Menu\n";
        switch (_getch()) {
        case '1': 
        {
            statisic += Game();
            system("pause");
            break;
        }
        case '2': {
            AddWord();
            break;
        }
        case '3': {
            statisic.ShowStatistic();
            system("pause");
            break;
        }
        case '4': {
            system("cls");
            cout << "Enter color: ";
            string color = "color ";
            int f = 0, s = 0;
            cin >> f;
            color.push_back(f+'0');
            cin >> s;
            color.push_back(s+'0');
            system(color.c_str());
            break;
        }
        case '5': {
            system("cls");
            cout << "Players are given a word that they must guess using the letters of the alphabet \nand the opportunity to make a limited number of mistakes(6).\nYou need to enter ONLY lowercase letters in enter field.\n\n";
            system("pause");
            break;
        }
        case '6': {
            system("cls");
            cout << "Made by Victor Pronchatov(JAKELORD1)\n\n";
            system("pause");
            break;
        }
        case '0': {
            statisic.StatsInFile();
            cout << "Stats saved! Goodbye!\n";
            exit(0);
            break;
        }
        }
        system("cls");
    }
}
