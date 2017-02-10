#ifndef STATEINTRO_H
#define STATEINTRO_H

#include "State.h"

class StateIntro: public State
{
    public:
        StateIntro();
        void Start();
        void Cycle(StateMachine& state_machine);
        void Exit();
    protected:
    private:
};

#endif // STATEINTRO_H
