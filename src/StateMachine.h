#ifndef STATEMACHINE_H
#define STATEMACHINE_H


class State;

class StateMachine
{
    public:
        virtual void ChangeState(State& state) = 0;
        virtual State* GetState() = 0;
        virtual void Cycle() = 0;
    protected:
    private:
};

#endif // STATEMACHINE_H
