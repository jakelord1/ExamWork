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
    system("color 05");
    cout << "To move in menu just enter number...\n";
    system("pause");
    system("cls");
    while (true) {
        cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n" <<
                "|            HANGMAN           |\n" <<
                "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n" <<
                "| Menu:                        |\n" <<
                "| 1 - Start Game               |\n" <<
                "| 2 - Add New Word             |\n" <<
                "| 3 - Show Statistic           |\n" <<
                "| 4 - Settings                 |\n" <<
                "| 5 - Rules                    |\n" <<
                "| 6 - Authors                  |\n" <<
                "| 0 - Exit Game                |\n" <<
                "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
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
            cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
            cout << "| -> Enter color: ";
            string color = "color ";
            int f = 0, s = 0;
            cin >> f;
            color.push_back(f + '0');
            cin >> s;
            color.push_back(s + '0');
            cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
            system(color.c_str());
            break;
        }
        case '5': {
            system("cls");
            cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
            cout << "| -> Players are given a word that they must guess using the letters of the alphabet \n| and the opportunity to make a limited number of mistakes(6).\n| You need to enter ONLY lowercase letters in enter field.\n";
            cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
            system("pause");
            break;
        }
        case '6': {
            system("cls");
            cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
            cout << "| -> Made by Victor Pronchatov(JAKELORD1)\n";
            cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
            system("pause");
            break;
        }
        case '0': {
            system("cls");
            statisic.StatsInFile();
            cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
            cout << "| -> Stats saved! Goodbye!\n";
            cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+";
            exit(0);
            break;
        }
        default: {
            break;
        }
        }
        system("cls");
    }
}
