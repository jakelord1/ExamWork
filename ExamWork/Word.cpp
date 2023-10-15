#include "Word.h"
using namespace std;

bool Word::GetLetter()
{
	cout << word << "\n";
	
	char s = ' ';
	int changes = 0;
	do {
		cout << "|	-> " << sword << " <-\n";
		cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
		cout << "|       V Enter letter V       |\n";
		cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n -> ";
		cin >> s;
		cout << "\n+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
		if (sword.find(s) != word.npos) {
			system("cls");
			cout << "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n";
			cout << "-> You already entered this letter. Try again!\n";
		}
		else {
			break;
		}
	} while (s >= 97 && s <= 122 && word.find(s) != word.npos);

	gstats.SetAtt(gstats.GetAtt()+1);

	for (size_t i = 0; i < word.length(); i++)
	{
		if (s == word[i]) {
			sword[i] = s;
			changes++;
		}
	}
	sword == word ? gstats.SetW(1) : gstats.SetW(0);
	if (changes == 0 && sword != word)
		return false;
	else
		return true;
}
