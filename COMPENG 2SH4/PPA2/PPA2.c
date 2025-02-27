#include <stdio.h>
#include "MacUILib.h"


int exitFlag;
char input;

int speedControl = 3; //default speed of program
int speed = 100000;

#define boardHeight 10
#define boardWidth 20

struct objPos
{
    int x;
    int y;
    char symbol; // symbol of the object to be drawn on the screen
};
struct objPos playerPos;

enum direction
{
    up,
    down,
    left,
    right,
    stop
};
enum direction currDirection;



void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{
    Initialize();
    while(!exitFlag)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }
    CleanUp();
}



void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    input = 0; // NULL
    exitFlag = 0;  // not exiting

    playerPos.x = boardWidth / 2; // start in the middle of the board
    playerPos.y = boardHeight / 2;
    playerPos.symbol = '@';

    currDirection = stop; // begin stopped
}

void GetInput(void)
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
}



void RunLogic(void)
{
    if(input != 0)  // if not null character
    {
        switch (input) // the if statements make it so that the player can only change direction by 90 degrees (ex. can't go straight from up to down)
        {
            case 'w':
                if (currDirection == left || currDirection == right || currDirection == stop)
                {
                    currDirection = up;
                }
                break;
            case 's':
                if (currDirection == left || currDirection == right || currDirection == stop)
                {
                    currDirection = down;
                }
                break;
            case 'a':
                if (currDirection == up || currDirection == down || currDirection == stop)
                {
                    currDirection = left;
                }
                break;
            case 'd':
                if (currDirection == up || currDirection == down || currDirection == stop)
                {
                    currDirection = right;
                }
                break;
            case '-': // increases delay, decreases speed
                if (speedControl > 1) // make sure speedControl is within bounds
                {
                    speedControl--;
                }
                break;
            case '=': // decreases delay, increases speed
                if (speedControl < 5)
                {
                    speedControl++;
                }
                break;
            case 27: // escape key pressed
                exitFlag = 1; // exit game
                break;
            default: // do nothing for other inputs
                break;
        }
        input = 0;
    }


    // increment player by 1 unit
    switch (currDirection) // use modulo (remainder) for wraparound logic
    {
    case up:
        playerPos.y = (playerPos.y - 1 + (boardHeight-1)) % (boardHeight-1); // use boardHeight/Width - 1 so that objects wraps around boundary characters instead of going into them
        break;
    case down:
        playerPos.y = (playerPos.y + 1) % (boardHeight-1);
        break;
    case left:
        playerPos.x = (playerPos.x - 1 + (boardWidth-1)) % (boardWidth-1);
        break;
    case right:
        playerPos.x = (playerPos.x + 1) % (boardWidth-1);
        break;
    case stop:
        break;
    }
    
    // speed control
    if (speedControl == 1)
    {
        speed = 300000;
    }
    else if (speedControl == 2)
    {
        speed = 200000;
    }
    else if (speedControl == 3)
    {
        speed = 100000;
    }
    else if (speedControl == 4)
    {
        speed = 50000;
    }
    else if (speedControl == 5)
    {
        speed = 25000;
    }
}



void DrawScreen(void)
{
    MacUILib_clearScreen();

    // static
    MacUILib_printf("Josh's WASD Game\n");
    
    // dynamic
    for (int y = 0; y < boardHeight; y++)
    {
        for (int x = 0; x < boardWidth; x++)
        {
            if (x == 0 || x == boardWidth - 1 || y == 0 || y == boardHeight - 1)
            {
                MacUILib_printf("#");
            }
            else if (x == playerPos.x && y == playerPos.y)
            {
                MacUILib_printf("@");
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n"); // print new line after everything
    }

    // static again
    MacUILib_printf("Use the w,a,s,d keys to change the direction of the player.\n");
    MacUILib_printf("Use the - and + keys to change the speed of the player from 1-5.\n");
    MacUILib_printf("Current speed: %d\n", speedControl);
    MacUILib_printf("Press ESCAPE to Exit");
}



void LoopDelay(void)
{
    MacUILib_Delay(speed); //variable speed
}



void CleanUp(void)
{
    MacUILib_uninit();
}