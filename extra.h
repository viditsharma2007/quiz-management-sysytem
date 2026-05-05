#ifndef EXTRA_H
#define EXTRA_H

#include <iostream>
using namespace std;

// -------- TEMPLATE SCORE MANAGER --------
template <typename T>
class ScoreManager
{
public:
    static T add(T a, T b)
    {
        return a + b;
    }

    static T subtract(T a, T b)
    {
        return a - b;
    }
};

// -------- GENERIC FUNCTIONS --------
template <typename T>
T findMax(T arr[], int n)
{
    T mx = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > mx)
            mx = arr[i];
    return mx;
}

template <typename T>
T findMin(T arr[], int n)
{
    T mn = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] < mn)
            mn = arr[i];
    return mn;
}

// -------- INPUT VALIDATION --------
int getValidInteger()
{
    int x;
    while(true)
    {
        cin >> x;

        if(cin.fail())
        {
            cout << "Invalid input! Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else return x;
    }
}

#endif