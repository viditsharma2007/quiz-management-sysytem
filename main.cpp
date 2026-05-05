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

    NormalRound normal;
    RapidFire rapid;
    Buzzer buzzer;
    BonusRound bonus;

    do
    {
        cout << "\nMENU\n";
        cout << "1.Normal Round\n";
        cout << "2.Rapid Fire\n";
        cout << "3.Buzzer\n";
        cout << "4.Bonus Round\n";
        cout << "5.Show Score\n";
        cout << "6.Save\n";
        cout << "7.Load\n";
        cout << "8.Ranking\n";
        cout << "9.Edit Team\n";
        cout << "10.Reset Scores\n";
        cout << "11.Detailed Report\n";
        cout << "12.Exit\n";


        try
        {
            cin >> choice;

            if(cin.fail())
                throw "Invalid input!";
        }
        catch(const char* msg)
        {
            cout << msg << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

      switch(choice)
{
    case 1: normal.conductRound(teams, n); break;
    case 2: rapid.conductRound(teams, n); break;
    case 3: buzzer.conductRound(teams, n); break;
    case 4: bonus.conductRound(teams, n); break;

    case 5: showScore(teams, n); break;
    case 6: saveData(teams, n); break;
    case 7: loadData(); break;
    case 8: showRanking(teams, n); break;
    case 9: editTeam(teams, n); break;
    case 10: resetScores(teams, n); break;
    case 11: showDetailedReport(teams, n); break;

    case 12: cout << "Exiting...\n"; break;

    default: cout << "Invalid choice!\n";
}

    } while(choice != 12);

    return 0;
}