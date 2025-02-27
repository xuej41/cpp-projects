#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        Pos* pos = 0;
        char symbol = 0;

        objPos();
        objPos(int xPos, int yPos, char sym);
        ~objPos();
        objPos(const objPos & x);
        objPos & operator=(const objPos & rhs);

        // Respect the rule of six / minimum four
        // [TODO] Implement the missing special member functions to meet the minimum four rule

        void setObjPos(objPos o);
        void setObjPos(int xPos, int yPos, char sym);

        objPos getObjPos() const;
        char getSymbol() const;
        char getSymbolIfPosEqual(const objPos* refPos) const;

        bool isPosEqual(const objPos* refPos) const;
};

#endif