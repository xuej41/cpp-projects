#include <stdio.h>
#include "MacUILib.h"
#include "myStringLib.h"   // This is your first custom C library

#include <stdlib.h>
#include <time.h>

int exitFlag; // Program Exiting Flag
int won; // win or not

char input;

int speedControl = 3; //default speed of program
int speed = 100000;

int moveCount = 0; // keeps track of how many iterations the game has goen through

#define boardHeight 10
#define boardWidth 20

struct objPos
{
    int x;
    int y;
    char symbol; // symbol of the object to be drawn on the screen
};
struct objPos playerPos;
struct objPos *itemBin;


enum direction
{
    up,
    down,
    left,
    right,
    stop
};
enum direction currDirection;

const char *goalStr = "McMaster-ECE";

char *mysteryStr;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


void GenerateItems(struct objPos list[], const int listSize, const struct objPos *playerPos, const int xRange, const int yRange, const char* str);





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

    srand(time(NULL)); // make the rand() numbers actually random

    input = 0; // NULL
    exitFlag = 0;  // not exiting

    playerPos.x = boardWidth / 2; // start in the middle of the board
    playerPos.y = boardHeight / 2;
    playerPos.symbol = '@';

    itemBin = (struct objPos*)malloc(5 * sizeof(struct objPos));

    GenerateItems(itemBin, 5, &playerPos, boardWidth - 3, boardHeight - 3, goalStr); // populate the itemBin struct with the randomly generated stuff

    currDirection = stop; // begin stopped

    mysteryStr = (char*)malloc(13 * sizeof(char)); // initializa the mysterystr
    for (int i = 0; i < 12; i++)
    {
        mysteryStr[i] = '?';
    }
    mysteryStr[12] = '\0';
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
    switch (currDirection)
    {
    case up:
        if (playerPos.y == 1)
            playerPos.y = boardHeight - 2;
        else
            playerPos.y--;
        break;
    case down:
        if (playerPos.y == boardHeight - 2)
            playerPos.y = 1;
        else
            playerPos.y++;
        break;
    case left:
        if (playerPos.x == 1)
            playerPos.x = boardWidth - 2;
        else
            playerPos.x--;
        break;
    case right:
        if (playerPos.x == boardWidth - 2)
            playerPos.x = 1;
        else
            playerPos.x++;
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

    // collision detection
    for (int i = 0; i < 5; i++) // for each item in itemBin
    {
        if (playerPos.x == itemBin[i].x && playerPos.y == itemBin[i].y) // if collision occurs
        {
            char collidedItem = itemBin[i].symbol;
            for (int j = 0; j < my_strlen(goalStr); j++) // go through all chars in goalStr, if it matches the collided char, replace it in mysteryStr
            {
                if (goalStr[j] == collidedItem)
                {
                    mysteryStr[j] = collidedItem;
                }
            }
            GenerateItems(itemBin, 5, &playerPos, boardWidth - 3, boardHeight - 3, goalStr); // generate coords between [1,18] and [1,8]
            break;
        }
    }

    if (my_strcmp(mysteryStr, goalStr) == 1) // if all characters are collected (mysteryStr = goalStr), end game
    {
        won = 1;
        exitFlag = 1;
    }
    
}



void DrawScreen(void)
{
    MacUILib_clearScreen();

    // static
    MacUILib_printf("Josh's Scavenger Hunt Game\n");
    
    // dynamic
    for (int y = 0; y < boardHeight; y++)
    {
        for (int x = 0; x < boardWidth; x++)
        {
            if (x == 0 || x == boardWidth - 1 || y == 0 || y == boardHeight - 1) // board borders
            {
                MacUILib_printf("#");
            }
            else if (x == playerPos.x && y == playerPos.y) // player position
            {
                MacUILib_printf("%c", playerPos.symbol);
            }
            else if (x == itemBin[0].x && y == itemBin[0].y) // item bin 0
            {
                MacUILib_printf("%c", itemBin[0].symbol);
            }
            else if (x == itemBin[1].x && y == itemBin[1].y) // item bin 1
            {
                MacUILib_printf("%c", itemBin[1].symbol);
            }
            else if (x == itemBin[2].x && y == itemBin[2].y) // item bin 2
            {
                MacUILib_printf("%c", itemBin[2].symbol);
            }
            else if (x == itemBin[3].x && y == itemBin[3].y) // item bin 3
            {
                MacUILib_printf("%c", itemBin[3].symbol);
            }
            else if (x == itemBin[4].x && y == itemBin[4].y) // item bin 4
            {
                MacUILib_printf("%c", itemBin[4].symbol);
            }
            else //empty space
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n"); // print new line after everything
    }

    if (currDirection != stop) //only increment move count if player has begun
    {
        moveCount++;
    }

    // static again
    MacUILib_printf("Use the - and + keys to change the speed of the player from 1-5.\n");
    MacUILib_printf("Current speed: %d\n", speedControl);

    MacUILib_printf("Mystery String: %s\n", mysteryStr);
    MacUILib_printf("Move Count: %d\n", moveCount);

    MacUILib_printf("Press ESCAPE to Exit\n");
}



void LoopDelay(void)
{
    MacUILib_Delay(speed); // variable speed
}



void CleanUp(void)
{
    if (won)
    {
        MacUILib_printf("==========ENDGAME MESSAGE==========\n");
        MacUILib_printf("Congratulations, You Won the Game!\n");
        MacUILib_printf("Your move count: %d", moveCount);
    }
    
    free(itemBin);
    free(mysteryStr);

    MacUILib_uninit();
}



void GenerateItems(struct objPos list[], const int listSize, const struct objPos *playerPos, const int xRange, const int yRange, const char* str)
{
    // coordinate generation
    for (int i = 0; i < listSize; i++)
    {
        int x, y;
        // Repeat until we get a valid, non-overlapping position
        do
        {
            x = rand() % xRange + 1; // random int with range [1, 18]
            y = rand() % yRange + 1; // random int with range [1, 8]
        } while (x == playerPos->x && y == playerPos->y);

        // assign random coordinates and random symbol from the goal string for each item
        list[i].x = x;
        list[i].y = y;
    }

    //character generation
    int randomIndices[listSize]; // listsize = 5, this is an array that stores the random numbers

    // character generation for first 2 chars
    int goalStrLen = my_strlen(goalStr); //12 characters total

    int usedIndices[goalStrLen]; // set the entire array as 0s
    for (int i = 0; i < goalStrLen; i++)
    {
        usedIndices[i] = 0;
    }

    for (int i = 0; i < 2; i++)
    {
        int randIndex;
        int valid = 0;

        // loop that finds an unused index and using that index number to get the unique char
        while (!valid)
        {
            randIndex = rand() % goalStrLen;  // get a random index in goalstr

            // check if the character at this index has already been used
            if (usedIndices[randIndex] == 0)
            {
                usedIndices[randIndex] = 1; // mark the index to be used

                randomIndices[i] = goalStr[randIndex]; // assign the character from goalstr at the respective index to the list of 5 things
                list[i].symbol = randomIndices[i];  // assign the character from goalstr at the respective index to the item
                valid = 1;
            }
        }
    }

    // character generation for remaining 3 chars
    int randomStrLen = 94; // range of random chars (33 to 126)
    int usedIndices2[randomStrLen]; // set the entire 126 character array as 0s
    for (int i = 0; i < randomStrLen; i++)
    {
        usedIndices2[i] = 0;
    }

    for (int i = 2; i < 5; i++)
    {
        int randIndex;
        int valid = 0;

        // loop that finds an unused index and using that index number to get the unique char (index can be from 0 - 126)
        while (!valid)
        {
            do
            {
                randIndex = (rand() % 94) + 33;  // get a random number between 33 and 126
            } while (randIndex == 32 || randIndex == 35 || randIndex == 64); // make sure the thing isnt space or # or @

            // check if the character at this index has already been used
            if (usedIndices2[randIndex - 33] == 0)
            {
                usedIndices2[randIndex - 33] = 1;

                randomIndices[i] = (char)randIndex; // assign the 3,4,5th elements of randomindices as the char equivalent of the random number 33 - 126
                list[i].symbol = randomIndices[i];  // assign the random number index as the ascii char equivalent thing
                valid = 1;
            }
        }
    }
}