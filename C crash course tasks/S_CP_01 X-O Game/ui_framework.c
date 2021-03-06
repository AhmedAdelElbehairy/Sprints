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
    if(empty==0 && (pressed_value==1 ||pressed_value==2||\
                    pressed_value==3||pressed_value==4||pressed_value==5||\
                    pressed_value==9||pressed_value==7||pressed_value==6||pressed_value==8))
        Update_The_Board(pointer_To_Our_Board, pressed_value, user);
    else
        pressed_value=-1;
    return pressed_value;
}
void start(void)
{
    reset_Tic_tac();
    gamemode mode=modeselection();
    int playerselection=0;
    int flag=0;
    while(!(mode==single_player || mode==multi_player))
	{
		sleep(1);
		system("cls");
        mode=modeselection();
	}
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
            playerselection=player_turn(mode,"USER1");
            if(playerselection==-1)
                continue;
            Print_The_Board();
            if(!(pointer_To_Our_Board->UL==' ' || pointer_To_Our_Board->UC==' ' || pointer_To_Our_Board->UR==' ' ||\
                pointer_To_Our_Board->ML==' ' || pointer_To_Our_Board->MC==' ' || pointer_To_Our_Board->MR==' ' ||\
                pointer_To_Our_Board->BL==' ' || pointer_To_Our_Board->BC==' ' || pointer_To_Our_Board->BR==' '))
                    break;
            computer_turn();
            Print_The_Board();

        }
        if(check_Win_situation()==Winner)
        {
            printf("we have a winner\n");
            sleep(1);
        }
        else if(!(pointer_To_Our_Board->UL==' ' || pointer_To_Our_Board->UC==' ' || pointer_To_Our_Board->UR==' ' ||\
                pointer_To_Our_Board->ML==' ' || pointer_To_Our_Board->MC==' ' || pointer_To_Our_Board->MR==' ' ||\
                pointer_To_Our_Board->BL==' ' || pointer_To_Our_Board->BC==' ' || pointer_To_Our_Board->BR==' ')&&(check_Win_situation()==NoWinner))
        {
            printf("there is no winners\n");
            sleep(1);
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
            if(!(check_Win_situation()==NoWinner)||!(pointer_To_Our_Board->UL==' ' || pointer_To_Our_Board->UC==' ' || pointer_To_Our_Board->UR==' ' ||\
                pointer_To_Our_Board->ML==' ' || pointer_To_Our_Board->MC==' ' || pointer_To_Our_Board->MR==' ' ||\
                pointer_To_Our_Board->BL==' ' || pointer_To_Our_Board->BC==' ' || pointer_To_Our_Board->BR==' '))
                break;
            while(player_turn(mode,"USER1")==-1&&(pointer_To_Our_Board->UL==' ' || pointer_To_Our_Board->UC==' ' || pointer_To_Our_Board->UR==' ' ||\
                pointer_To_Our_Board->ML==' ' || pointer_To_Our_Board->MC==' ' || pointer_To_Our_Board->MR==' ' ||\
                pointer_To_Our_Board->BL==' ' || pointer_To_Our_Board->BC==' ' || pointer_To_Our_Board->BR==' ')&&(check_Win_situation()==NoWinner));
            Print_The_Board();
            if(!(check_Win_situation()==NoWinner)||!(pointer_To_Our_Board->UL==' ' || pointer_To_Our_Board->UC==' ' || pointer_To_Our_Board->UR==' ' ||\
                pointer_To_Our_Board->ML==' ' || pointer_To_Our_Board->MC==' ' || pointer_To_Our_Board->MR==' ' ||\
                pointer_To_Our_Board->BL==' ' || pointer_To_Our_Board->BC==' ' || pointer_To_Our_Board->BR==' '))
                break;

        }
        if(!(pointer_To_Our_Board->UL==' ' || pointer_To_Our_Board->UC==' ' || pointer_To_Our_Board->UR==' ' ||\
                pointer_To_Our_Board->ML==' ' || pointer_To_Our_Board->MC==' ' || pointer_To_Our_Board->MR==' ' ||\
                pointer_To_Our_Board->BL==' ' || pointer_To_Our_Board->BC==' ' || pointer_To_Our_Board->BR==' ')&&(check_Win_situation()==NoWinner))
                {
                    printf("there is no winners\n");
                    sleep(1);
                }
                else
                {
                    printf("we have a winner\n");
                    sleep(1);
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
    printf("3-unit testing of start() functions\n");
    printf("this function is tested by playing\n");
    printf("function testing start:\n");
    start();
    reset_Tic_tac();
    printf("\npress enter to continue");
    getch();
    system("cls");
}


