#ifndef Class_Command
#define Class_Command

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

vector<int*>* /* universal vars*/modify_vars;

class command_line
{
private:
    //0:operator
    //1:command
    int type;
    int subtype;

    vector <int>* var_execution;

    command_line* next_line;
    command_line* sub_commands;


public:

    command_line(int input_type,int input_subtype,vector <int>* var_execution);
    void execute(vector<int*>* &arguments);
    int command_read_build(){
        ;
    }

};

command_line::command_line(int input_type,int input_subtype,vector <int>* input_var_execution)
{
    type=input_type;
    subtype=input_subtype;
    var_execution=input_var_execution;
}

void command_line::execute(/*local vars*/vector<int*>* &arguments)
{
    vector < vector <int*> * > operation_vars={modify_vars,arguments};
    //0:operator
    if (type==0)
    {
        switch (subtype)
        {

        //if (condition) then
        case 0:
            bool pass = 0;
            switch (var_execution->at(1)){
                //(A>B)
                case 0:
                    break;
                //(A<B)
                case 1:
                    break;
                //(A=B)
                case 2:
                    break;
                //(A check d n )
                //(A+d n >= d n max)
                case 3:
                    if ((*operation_vars.at(var_execution->at(2))->at(var_execution->at(3)) + rand()%var_execution->at(4)) >= var_execution->at(4)){
                        pass = 1;
                    }
                    break;
                //(condition)
                case 4:
                    if (*operation_vars.at(var_execution->at(2))->at(var_execution->at(3))){
                        pass = 1;
                    }
                    break;
                default:
                    break;
            }
            //not
            if (var_execution->at(0)==1){
                if (pass){
                    pass = 0;
                }
                else{
                    pass = 1;
                }
            }
            if (pass){
                if (sub_commands!=nullptr){
                    sub_commands->execute(arguments);
                }
            }
            
            break;
        
        //until (condition)
        case 1:
            while (true){            
                bool pass = 0;
                switch (var_execution->at(1)){
                    //(A>B)
                    case 0:
                        break;
                    //(A<B)
                    case 1:
                        break;
                    //(A=B)
                    case 2:
                        break;
                    //(A check d n )
                    //(A+d n >= d n max)
                    case 3:
                        if ((*operation_vars.at(var_execution->at(2))->at(var_execution->at(3)) + rand()%var_execution->at(4)) >= var_execution->at(4)){
                            pass = 1;
                        }
                        break;
                    //(condition)
                    case 4:
                        if (*operation_vars.at(var_execution->at(2))->at(var_execution->at(3))){
                            pass = 1;
                        }
                        break;
                    default:
                        break;
                }
                //not
                if (var_execution->at(0)==1){
                    if (pass){
                        pass = 0;
                    }
                    else{
                        pass = 1;
                    }
                }
                if (pass){
                    if (sub_commands!=nullptr){
                        sub_commands->execute(arguments);
                    }
                }
                else{
                    break;
                }
            
            }
            break;
        
        default:
            break;
        }
    }
    else if (type==1){
        switch (subtype)
        {
        //(A increase by B)
        case 0:
            break;
        //(A reduce by B)
        case 1:
            break;
        
        default:
            break;
        }
    }
    
    if (next_line!=nullptr){
        next_line->execute(arguments);
    }
}

#endif