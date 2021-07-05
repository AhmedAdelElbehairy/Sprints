#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include "ui_driver.h"
#include "ui_framework.h"
extern Board Our_Board;
extern Board *pointer_To_Our_Board;
void computer_turn (void)
{
    int arr_available_places[9];
    int iterator=0;
    srand(time(0));
    iterator=array_of_Available_places(arr_available_places);
    if(iterator!=0)
    {
        Update_The_Board(pointer_To_Our_Board, arr_available_places[rand()%iterator], "PC");
    }
}
void player_turn (gamemode mode,char* user)
{
    Update_The_Board(pointer_To_Our_Board, getch()-48, user);
}
gamemode modeselection(void)
{
    int selection;
    printf("enter number of your selection:\n");
    printf("1-single player\n");
    printf("2-multiplayer\n");
    selection=(getch()-48);
    if (selection==single_player || selection==multi_player)
    {
        return selection;
    }
    else
    {
        selection=0;
        printf("Wrong selection\n");
    }
    return selection;
}
void start(void)
{
    gamemode mode=modeselection();
    while(!(mode==single_player || mode==multi_player))
        mode=modeselection();
    if (mode==single_player)
    {
        Print_The_Board();
        printf("use the numpad to select the location\n");
        while(check_Win_situation()==NoWinner)
        {
            player_turn(mode,"USER1");
            computer_turn();
            Print_The_Board();
        }
    }
    else
    {
        Print_The_Board();
        printf("use the numpad to select the location\n");
        while(check_Win_situation()==NoWinner)
        {
            player_turn(mode,"USER1");//not updating the board
            Print_The_Board();
            player_turn(mode,"USER2");
            Print_The_Board();
        }
    }

}
void UnitTestingFrameWork(void)
{
    printf("start unit testing for functions of UIframeWork:\n");
    printf("1-unit testing of computer_turn() functions\n");



    reset_Tic_tac();
    printf("\npress enter to continue");
    getch();
    system("cls");
    /*********************************************************************************************/
    printf("unit testing for functions of UIframeWork:\n");
    printf("2-unit testing of player_turn() functions\n");



    reset_Tic_tac();
    printf("\npress enter to continue");
    getch();
    system("cls");
    /*********************************************************************************************/
    printf("unit testing for functions of UIframeWork:\n");
    printf("3-unit testing of play() functions\n");



    reset_Tic_tac();
    printf("\npress enter to continue");
    getch();
    system("cls");
}


