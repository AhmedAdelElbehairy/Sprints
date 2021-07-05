#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include "config.h"
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
int player_turn (gamemode mode,char* user)
{
    int empty;
    int pressed_value=getch()-48;
    empty=check_The_Location(pointer_To_Our_Board,pressed_value);
    if(empty==0)
        Update_The_Board(pointer_To_Our_Board, pressed_value, user);
    else
        pressed_value=-1;
    return pressed_value;
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
    int flag=0;
    while(!(mode==single_player || mode==multi_player))
        mode=modeselection();
    if (mode==single_player)
    {
        if(!(pointer_To_Our_Board->UL==' ' || pointer_To_Our_Board->UC==' ' || pointer_To_Our_Board->UR==' ' ||\
             pointer_To_Our_Board->ML==' ' || pointer_To_Our_Board->MC==' ' || pointer_To_Our_Board->MR==' ' ||\
             pointer_To_Our_Board->BL==' ' || pointer_To_Our_Board->BC==' ' || pointer_To_Our_Board->BR==' '))
                {
                    Print_The_Board();
                    return;
                }

        Print_The_Board();
        printf("use the numpad to select the location\n");
        while(check_Win_situation()==NoWinner)
        {
            player_turn(mode,"USER1");
            computer_turn();
            Print_The_Board();
        }
    }
    else//multiplayer mode
    {
        Print_The_Board();

        printf("use the numpad to select the location\n");

        while((check_Win_situation()==NoWinner))
        {
            if(!(pointer_To_Our_Board->UL==' ' || pointer_To_Our_Board->UC==' ' || pointer_To_Our_Board->UR==' ' ||\
                pointer_To_Our_Board->ML==' ' || pointer_To_Our_Board->MC==' ' || pointer_To_Our_Board->MR==' ' ||\
                pointer_To_Our_Board->BL==' ' || pointer_To_Our_Board->BC==' ' || pointer_To_Our_Board->BR==' '))
                    break;
            while(player_turn(mode,"USER2")==-1&&(pointer_To_Our_Board->UL==' ' || pointer_To_Our_Board->UC==' ' || pointer_To_Our_Board->UR==' ' ||\
                pointer_To_Our_Board->ML==' ' || pointer_To_Our_Board->MC==' ' || pointer_To_Our_Board->MR==' ' ||\
                pointer_To_Our_Board->BL==' ' || pointer_To_Our_Board->BC==' ' || pointer_To_Our_Board->BR==' ')&&(check_Win_situation()==NoWinner));
            Print_The_Board();
            while(player_turn(mode,"USER1")==-1&&(pointer_To_Our_Board->UL==' ' || pointer_To_Our_Board->UC==' ' || pointer_To_Our_Board->UR==' ' ||\
                pointer_To_Our_Board->ML==' ' || pointer_To_Our_Board->MC==' ' || pointer_To_Our_Board->MR==' ' ||\
                pointer_To_Our_Board->BL==' ' || pointer_To_Our_Board->BC==' ' || pointer_To_Our_Board->BR==' ')&&(check_Win_situation()==NoWinner));
            Print_The_Board();

        }
//        Print_The_Board();
    }
    }
void UnitTestingFrameWork(void)
{
    printf("start unit testing for functions of UIframeWork:\n");
    printf("1-unit testing of computer_turn() functions\n");
    printf("function testing start:\n");
    printf("computer will play nine consecutive times to fill the board\n");
    for(int i=1;i<=9;i++)
    {
        printf("this is the turn number %d",i);
        computer_turn();
        printf("\n");
        Print_The_Board();
    }
    reset_Tic_tac();
    printf("\npress enter to continue");
    getch();
    system("cls");
    /*********************************************************************************************/
    printf("unit testing for functions of UIframeWork:\n");
    printf("2-unit testing of player_turn() functions\n");
    printf("function testing start:\n");
    printf("this testing will simulate playing with another opponent use numpad to play with yourself:\n");
    printf("Inputs are:\n");
    printf("gamemode: Multiplayer Mode:\n");
    printf("users: USER1 and USER2\n");
    char* user;
    for(int i=1;i<=9;i++)
    {
        Print_The_Board();
        printf("this is the turn number %d\n",i);
        if(i%2==0)
        {
            user="USER2";
            player_turn(multi_player,user);
            printf("\n");

        }
        else
        {
            user="USER1";
            player_turn(multi_player,user);
            printf("\n");

        }
    }
    Print_The_Board();
    reset_Tic_tac();
    printf("\npress enter to continue");
    getch();
    system("cls");
    /*********************************************************************************************/
    printf("unit testing for functions of UIframeWork:\n");
    printf("3-unit testing of play() functions\n");
    printf("this function is tested by playing\n");
    printf("function testing start:\n");
    start();
    reset_Tic_tac();
    printf("\npress enter to continue");
    getch();
    system("cls");
}


