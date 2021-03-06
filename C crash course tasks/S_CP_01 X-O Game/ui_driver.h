#ifndef UI_DRIVER_H
#define UI_DRIVER_H

typedef enum gamemode {
        single_player=1,
        multi_player
    }gamemode;
typedef struct{
    char UL;
    char UC;
    char UR;
    char ML;
    char MC;
    char MR;
    char BL;
    char BC;
    char BR;
}Board;
typedef enum
{
    BL = 1,
    BC,
    BR,
    ML,
    MC,
    MR,
    UL,
    UC,
    UR
}locations_of_board;
typedef enum
{
    NoWinner,
    Winner
}winner;

void Print_The_Board(void);
void Update_The_Board(Board *ptr, locations_of_board location, char* user);
int check_The_Location(Board *ptr, locations_of_board location);
winner check_Win_situation(void);
void reset_Tic_tac(void);
int array_of_Available_places(int* arr);
gamemode modeselection(void);
void UnitTestingDriver(void);
#endif // UI_DRIVER_H
