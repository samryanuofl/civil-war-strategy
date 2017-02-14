#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <memory>

class State;

class StateMachine
{
    public:
        virtual void AddState(std::shared_ptr<State>) = 0;
        virtual State* GetState() = 0;
        virtual int Cycle() = 0;
    protected:
    private:
};

#endif // STATEMACHINE_H
