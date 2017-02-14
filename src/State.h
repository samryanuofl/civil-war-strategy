#ifndef STATE_H
#define STATE_H

class StateMachine;

class State
{
    public:
        virtual void Start() = 0;
        virtual void Cycle(StateMachine *state_machine)= 0;
        virtual void Exit() = 0;
    protected:
    private:
};

#endif // STATE_H
