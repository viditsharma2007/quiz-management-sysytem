#ifndef QUIZ_H
#define QUIZ_H

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "extra.h"
using namespace std;

// -------- QUESTION STRUCT --------
struct Question
{
    string question;
    string options[4];
    int correct;
};

// -------- TEAM CLASS --------
class Team
{
public:
    string name;
    int score;

    Team()
    {
        score = 0;
    }

    void setName(string n)
    {
        name = n;
    }

    void addScore(int s)
    {
        score += s;
    }

    void display()
    {
        cout << name << " : " << score << " points" << endl;
    }
};

// -------- ABSTRACT BASE CLASS --------
class Quiz
{
public:
    virtual void conductRound(Team teams[], int n) = 0;
};

// updated code

// -------- NORMAL ROUND --------
class NormalRound : public Quiz
{
public:
    void conductRound(Team teams[], int n)
    {
        Question qBank[3] = {
            {"Capital of India?", {"Delhi","Mumbai","Kolkata","Chennai"}, 1},
            {"2+2?", {"3","4","5","6"}, 2},
            {"5*5?", {"10","20","25","30"}, 3}
        };

        int ans;

        for(int i = 0; i < n; i++)
        {
            cout << "\nTurn: " << teams[i].name << endl;

            for(int q = 0; q < 3; q++)
            {
                cout << qBank[q].question << endl;

                for(int j = 0; j < 4; j++)
                    cout << j+1 << ". " << qBank[q].options[j] << endl;

                ans = getValidInteger();

                if(ans == qBank[q].correct)
                    teams[i].addScore(10);
                else
                    teams[i].addScore(-5);
            }
        }
    }
};
// -------- RAPID FIRE --------
class RapidFire : public Quiz
{
public:
    void conductRound(Team teams[], int n)
    {
        int ans;

        for(int i = 0; i < n; i++)
        {
            cout << "\nRapid Fire: " << teams[i].name << endl;

            for(int j = 1; j <= 3; j++)
            {
                cout << "Capital of India?\n";
                cout << "1.Delhi 2.Mumbai 3.Kolkata 4.Chennai\n";

                ans = getValidInteger();

                if(ans == 1)
                    teams[i].addScore(5);
                else
                    teams[i].addScore(-2);
            }
        }
    }
};

// -------- BUZZER --------
class Buzzer : public Quiz
{
public:
    void conductRound(Team teams[], int n)
    {
        int teamChoice, ans;

        for(int i = 0; i < 2; i++)
        {
            cout << "Team (1-" << n << "): ";
            teamChoice = getValidInteger();

            if(teamChoice < 1 || teamChoice > n)
            {
                cout << "Invalid team\n";
                continue;
            }

            cout << "5*5?\n1.20 2.25 3.30 4.35\n";
            ans = getValidInteger();

            if(ans == 2)
                teams[teamChoice-1].addScore(20);
            else
                teams[teamChoice-1].addScore(-10);
        }
    }
};

// -------- BONUS ROUND --------
class BonusRound : public Quiz
{
public:
    void conductRound(Team teams[], int n)
    {
        int ans;

        for(int i = 0; i < n; i++)
        {
            cout << "\nBonus Round: " << teams[i].name << endl;

            cout << "10 + 5 = ?\n1.12 2.15 3.20 4.25\n";
            ans = getValidInteger();

            if(ans == 2)
                teams[i].score = ScoreManager<int>::add(teams[i].score, 15);
            else
                teams[i].score = ScoreManager<int>::subtract(teams[i].score, 5);
        }
    }
};

// -------- LIGHTNING ROUND --------
class LightningRound : public Quiz
{
public:
    void conductRound(Team teams[], int n)
    {
        int ans;

        for(int i = 0; i < n; i++)
        {
            cout << "\nLightning Round: " << teams[i].name << endl;

            cout << "1+1?\n1.1 2.2 3.3 4.4\n";
            ans = getValidInteger();

            if(ans == 2)
                teams[i].addScore(5);
            else
                teams[i].addScore(-2);
        }
    }
};

// -------- FUNCTIONS --------
void showScore(Team teams[], int n)
{
    for(int i = 0; i < n; i++)
        teams[i].display();
}

void showRanking(Team teams[], int n)
{
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(teams[j].score > teams[i].score)
                swap(teams[i], teams[j]);

    cout << "\n--- RANKING ---\n";
    for(int i = 0; i < n; i++)
    {
        cout << i+1 << ". ";
        teams[i].display();
    }
}