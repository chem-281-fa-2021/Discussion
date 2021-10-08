
// Close to modify
// Open to extend

#include <string>
using namespace std;

class machine
{
private:
    State * curstate;
public:
    void Interface(int action){
        switch (action)
        {
        case 1:
            curstate->func_1();
            break;
        case 2:
            curstate->func_2();
            break;
        
        default:
            break;
        }
    }
};


class State
{
public:
    State(){}
    // Some functions to deal with member variable;
    virtual double func_1() = 0;
    virtual double func_2() = 0;

protected:
    // member variable;
};

class A : public State{
    virtual double func_1(){
        /* code */;
    }
    virtual double func_2(){
        /* code */;
    }
};

class B : public State{
    virtual double func_1(){
        /* code */;
    }
    virtual double func_2(){
        /* code */;
    }
};