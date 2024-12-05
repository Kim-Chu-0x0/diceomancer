#ifndef Class_Card
#define Class_Card

#include "./effects/effects.h"
#include <iostream>
#include <vector>

using namespace std;

class Card
{
private:
public:
    vector <Effects> Card_Effects;
    Card();
};

Card::Card()
{
}

#endif