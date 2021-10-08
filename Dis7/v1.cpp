
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
        /*convert input string to action*/
        curstate->handle(action);
    }
};


class State
{
public:
    State(){}
    // Some functions to deal with member variable;
    virtual double handle(int action) = 0;

protected:
    // member variable;
};

class A : public State{
    virtual double handle(int action){
        switch (action)
        {
        case 1:
            /* code */;
            break;

        case 2:
            /* code */;
            break;
        
        default:
            break;
        }
    }
};

class B : public State{
    virtual double handle(int action){
        switch (action)
        {
        case 1:
            /* code */;
            break;

        case 2:
            /* code */;
            break;
        
        default:
            break;
        }
    }
};