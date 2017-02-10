#ifndef GAMESTATE_H
#define GAMESTATE_H


class GameState
{
    public:
        GameState();
        virtual void Enter() = 0;
        virtual void Update() = 0;
        virtual void Quit() = 0;
        virtual ~GameState();
    protected:
    private:
};

#endif // GAMESTATE_H
