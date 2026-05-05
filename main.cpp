#include "quiz.h"
#include"extra.h"
int main()
{
    Team teams[10];
    int n, choice;

    cout << "Enter number of teams: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string name;
        cout << "Team " << i+1 << ": ";
        cin >> name;
        teams[i].setName(name);
    }
