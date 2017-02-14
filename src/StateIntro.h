#ifndef STATEINTRO_H
#define STATEINTRO_H

#include "State.h"
#include "Renderer.h"

class StateIntro: public State
{
    public:
        StateIntro(Renderer &renderer);
        void Start();
        void Cycle(StateMachine *state_machine);
        void Exit();
    protected:
    private:
        Renderer &renderer_;
};

#endif // STATEINTRO_H
