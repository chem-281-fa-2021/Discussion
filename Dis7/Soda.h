#if !defined SODA_H
#define SODA_H
#include <string>

// Template 
// Even the following existed class miss some functions and variables you need for homework
namespace Soda
{
    enum Action {insert, press, reload, quit};
    class State;

    class AbstractContext
    {
    public:
        virtual void setState(State *newState)=0; // change state object
    };


    class State
    {
    public:
        State(){}
        void setContext(AbstractContext * ac);
        void SetTransitionTable(State **transitonTable);
        virtual double handle(Action *eventData) = 0;

    protected:
        AbstractContext *context;
        State **transitionTable;
    };

    class AbstractStateFactory
    {
    public:
        AbstractStateFactory(int num): num_states(num){}
        const int num_states;
    };
  
}
#endif // SODA_H