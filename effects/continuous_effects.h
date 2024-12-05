#ifndef Class_Effects
#define Class_Effects

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../command/command.h"

using namespace std;

vector <Effects*>* effect_templates;

class Effects
{
private:
public:
    bool hidden;
    vector <command_line>* arguments;
    string name_en,name_ch;
    int trigger_condition,trigger_counter;

    //0: Apply effects
    //1: Access areas
    //2: Change card texts
    int type_main;

    int type_sub;

    Effects();

};

Effects::Effects()
{
    arguments = new vector <command_line>;
    type_main=-1;
    type_sub=-1;
    trigger_condition=-1;
    name_en=name_ch="Null";
}

void Read_continuous_effects(){
    delete effect_templates;
    effect_templates = new vector <Effects*>;
    ifstream continuous_effect("continuous_effects_name");
    string stache1,stache2,stache3,stache4,stache5;
    while (continuous_effect>>stache1)
    {
        Effects* new_template_memeber = new Effects;
        continuous_effect>>new_template_memeber->name_en;
        continuous_effect>>new_template_memeber->name_ch;
        //when (condition)
        continuous_effect>>stache1;
        continuous_effect>>stache1;
        if (stache1=="upkeep"){
            new_template_memeber->trigger_condition=0;
        }
        else if (stache1=="endstep"){
            new_template_memeber->trigger_condition=0;
        }
    }
    
}

#endif