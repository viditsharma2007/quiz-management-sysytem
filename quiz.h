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
