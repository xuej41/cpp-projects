#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class GameMechs
{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;

        int boardSizeX;
        int boardSizeY;

        objPos food;
        void chk_esc();
    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        GameMechs(const GameMechs & rhs);
        ~GameMechs(); // is this one needed at all? Why or why not?
        GameMechs & operator=(const GameMechs & rhs);
        bool getExitFlagStatus() const;
        void setExitTrue();
        bool getLoseFlagStatus() const;
        void setLoseFlag();

        char getInput() const;
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX() const;
        int getBoardSizeY() const;

        int getScore() const;
        void incrementScore();

        // More methods should be added here
        void generateFood(const objPosArrayList * arr);
        objPos getFoodPos() const;
};

#endif