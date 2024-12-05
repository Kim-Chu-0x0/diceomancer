#ifndef Class_Area
#define Class_Area

#include "./card.h"
#include <iostream>
#include <vector>

using namespace std;

class Area
{
private:
    /* data */
public:

    //0: library
    //1: hand
    //2: graveyard
    //3: deck
    int type;
    vector <Card>* Card_pool;

    Area(int input_type);
};

Area::Area(int input_type)
{
    type=input_type;
}

#endif