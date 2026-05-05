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
// template class to manage score
