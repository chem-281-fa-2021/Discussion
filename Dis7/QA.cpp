#include <iostream>
#include <map>


//1. You may need to convert input to action
enum Action {insert, press, reload, quit};
std::map<std::string, Action> operation_map { {"p", press}, {"q", insert}, {"e", quit}, {"reload", reload}, };

//2. state /should have the ability/ to change the machine to another state/
// 2.1 ability --> Use whose function?
    //machine's function
    // state should have a pointer to the machine (abstract machine)

// 2.2  State --> where is the another state stored?
// machine has a pinter to the list of all the states allthestates: state->machine->changestate(state->machine->allthestates[i])
    // constructor
    // Another class StateFactory (AbstractStateFactory)
// state has a pointer to all the states allthestates: state->machine->changestate(state->allthestates[i])
    // Another class StateFactory (AbstractStateFactory)

//3. We have a counter! Equals to another kind of state!!!