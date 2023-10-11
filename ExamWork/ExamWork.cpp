#include <iostream>
#include <ctime>
#include <string>
#include "Functions.h"
using namespace std;

int main()
{
    srand(time(NULL));
    AddWord();
    cout << GetWord();
}
