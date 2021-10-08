
// If you have two actions 1 and 2 (we use int type for convenience)
// the machine has two states A and B (we use string type for convenience)

#include <string>
using namespace std;

class machine
{
private:
    string state;
public:
    void Interface(int action){
        switch (action)
        {
        case 1:
            if(state == 'A')
                /* code */;
            else
                /* code */;
            break;

        case 2:
            if(state == 'A')
                /* code */;
            else
                /* code */;
            break;
        
        default:
            break;
        }

    }
};

