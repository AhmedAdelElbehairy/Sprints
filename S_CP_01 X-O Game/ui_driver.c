#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "ui_driver.h"
//global values
Board Our_Board ={' ',' ',' ',\
                  ' ',' ',' ',\
                  ' ',' ',' '};
Board *pointer_To_Our_Board = &Our_Board;
//functions
void Print_The_Board(void)
{
    #if Unit_Testing!=1
    system("cls");
    #endif

    Board *ptr=pointer_To_Our_Board;
    printf(" %C | %C | %C \n-----------\n %C | %C | %C \n-----------\n %C | %C | %C \n",\
           ptr->UL,ptr->UC,ptr->UR,\
           ptr->ML,ptr->MC,ptr->MR,\
           ptr->BL,ptr->BC,ptr->BR);
}
void Update_The_Board(Board *ptr, locations_of_board location, char* user)
{
    char XORO;
    if(user[0]=='PC')
    {
        XORO='O';
    }
    else if (user[4]=='1')
    {
        XORO='X';
    }
    else if (user[4]=='2')
    {
        XORO='O';
    }
    else
    {
        printf("wrong user entry to Update_The_Board function\n/n");
    }

    switch (location)
    {
        case UL:
            ptr->UL=XORO;
            break;
        case UC:
            ptr->UC=XORO;
            break;
        case UR:
            ptr->UR=XORO;
            break;
        case ML:
            ptr->ML=XORO;
            break;
        case MC:
            ptr->MC=XORO;
            break;
        case MR:
            ptr->MR=XORO;
            break;
        case BL:
            ptr->BL=XORO;
            break;
        case BC:
            ptr->BC=XORO;
            break;
        case BR:
            ptr->BR=XORO;
            break;
        default:
            printf("wrong location entry to Update_The_Board function\n");
    }
}
void check_The_Location(Board *ptr, locations_of_board location)
{
    switch (location)
    {
        case UL:
            if(ptr->UL=='X' || ptr->UL=='O')
                printf("this position is already filled\n");
            else
                printf("this position is empty\n");
            break;
        case UC:
            if(ptr->UC=='X' || ptr->UC=='O')
                printf("this position is already filled\n");
            else
                printf("this position is empty\n");
            break;
        case UR:
            if(ptr->UR=='X' || ptr->UR=='O')
                printf("this position is already filled\n");
            else
                printf("this position is empty\n");
            break;
        case ML:
            if(ptr->ML=='X' || ptr->ML=='O')
                printf("this position is already filled\n");
            else
                printf("this position is empty\n");
            break;
        case MC:
            if(ptr->MC=='X' || ptr->MC=='O')
                printf("this position is already filled\n");
            else
                printf("this position is empty\n");
            break;
        case MR:
            if(ptr->MR=='X' || ptr->MR=='O')
                printf("this position is already filled\n");
            else
                printf("this position is empty\n");
            break;
        case BL:
            if(ptr->BL=='X' || ptr->BL=='O')
                printf("this position is already filled\n");
            else
                printf("this position is empty\n");
            break;
        case BC:
            if(ptr->BC=='X' || ptr->BC=='O')
                printf("this position is already filled\n");
            else
                printf("this position is empty\n");
            break;
        case BR:
            if(ptr->BR=='X' || ptr->BR=='O')
                printf("this position is already filled\n");
            else
                printf("this position is empty\n");
            break;
        default:
            printf("this position isn't valid\n");
    }
}
winner check_Win_situation(void)
{
    Board* ptr=pointer_To_Our_Board;
    int stat= NoWinner;
    if(((ptr->UL==ptr->UC) && (ptr->UC==ptr->UR) && (ptr->UL!=' ')) ||\
       ((ptr->ML==ptr->MC) && (ptr->MC==ptr->MR) && (ptr->ML!=' ')) ||\
       ((ptr->BL==ptr->BC) && (ptr->BC==ptr->BR) && (ptr->BL!=' ')) ||\
       ((ptr->UL==ptr->ML) && (ptr->ML==ptr->BL) && (ptr->UL!=' ')) ||\
       ((ptr->UC==ptr->MC) && (ptr->MC==ptr->BC) && (ptr->UC!=' ')) ||\
       ((ptr->UR==ptr->MR) && (ptr->MR==ptr->BR) && (ptr->UR!=' ')) ||\
       ((ptr->UL==ptr->MC) && (ptr->MC==ptr->BR) && (ptr->UL!=' ')) ||\
       ((ptr->UR==ptr->MC) && (ptr->MC==ptr->BL) && (ptr->UR!=' ')))
        {
            printf("we have a winner\n");
            stat=Winner;
        }

    return stat;
}
void reset_Tic_tac(void)
{
    pointer_To_Our_Board->UL=' ';
    pointer_To_Our_Board->UC=' ';
    pointer_To_Our_Board->UR=' ';

    pointer_To_Our_Board->ML=' ';
    pointer_To_Our_Board->MC=' ';
    pointer_To_Our_Board->MR=' ';

    pointer_To_Our_Board->BL=' ';
    pointer_To_Our_Board->BC=' ';
    pointer_To_Our_Board->BR=' ';
}
int array_of_Available_places(int arr[9])
{
    int iterator=0;
    if(pointer_To_Our_Board->UL==' ' || pointer_To_Our_Board->UC==' ' || pointer_To_Our_Board->UR==' ' ||\
       pointer_To_Our_Board->ML==' ' || pointer_To_Our_Board->MC==' ' || pointer_To_Our_Board->MR==' ' ||\
       pointer_To_Our_Board->BL==' ' || pointer_To_Our_Board->BC==' ' || pointer_To_Our_Board->BR==' ')
    {
        if(pointer_To_Our_Board->UL==' ')
        {
            arr[iterator]=UL;
            iterator++;
        }
        if(pointer_To_Our_Board->UC==' ')
        {
            arr[iterator]=UC;
            iterator++;
        }
        if(pointer_To_Our_Board->UR==' ')
        {
            arr[iterator]=UR;
            iterator++;
        }
        if(pointer_To_Our_Board->ML==' ')
        {
            arr[iterator]=ML;
            iterator++;
        }
        if(pointer_To_Our_Board->MC==' ')
        {
            arr[iterator]=MC;
            iterator++;
        }
        if(pointer_To_Our_Board->MR==' ')
        {
            arr[iterator]=MR;
            iterator++;
        }
        if(pointer_To_Our_Board->BL==' ')
        {
            arr[iterator]=BL;
            iterator++;
        }
        if(pointer_To_Our_Board->BC==' ')
        {
            arr[iterator]=BC;
            iterator++;
        }
        if(pointer_To_Our_Board->BR==' ')
        {
            arr[iterator]=BR;
            iterator++;
        }
    }
    else
    {
        printf("no place is empty\n");
    }
    return iterator;
}
void UnitTestingDriver(void)
{
    printf("start unit testing for functions of UIdriver:\n");
    printf("1-unit testing of array_of_Available_places() and Update_The_Board() functions\n");
    int arr_available_places[9];
    int iterator=0;
    printf("printing board locations\n");
    printf(" %s | %s | %s \n -----------\n %s | %s | %s \n -----------\n %s | %s | %s \n",\
           "UL","UC","UR",\
           "ML","MC","MR",\
           "BL","BC","BR");
    printf("function testing start:\n");
    printf("The Board:\n");
    Print_The_Board();
    for(int i =0; i<9; i++)
    {
        srand(time(0));
        iterator=array_of_Available_places(arr_available_places);
        printf("Available places are:\n");
        for(int k =0; k<iterator; k++)
        {
            if(arr_available_places[k]==UL)
                printf("UL ");
            else if(arr_available_places[k]==UC)
                printf("UC ");
            else if(arr_available_places[k]==UR)
                printf("UR ");
            else if(arr_available_places[k]==ML)
                printf("ML ");
            else if(arr_available_places[k]==MC)
                printf("MC ");
            else if(arr_available_places[k]==MR)
                printf("MR ");
            else if(arr_available_places[k]==BL)
                printf("BL ");
            else if(arr_available_places[k]==BC)
                printf("BC ");
            else
                printf("BR ");
        }
        printf("\n");
        printf("updating the board....\n");
        printf("\nThe Board:\n");

        if(i%2==0)
        {

            if(iterator!=0)
            {
                Update_The_Board(pointer_To_Our_Board,arr_available_places[rand()%iterator],"USER1");
            }
        }
        else
        {
            if(iterator!=0)
            {
                Update_The_Board(pointer_To_Our_Board,arr_available_places[rand()%iterator],"USER2");
            }
        }
        Print_The_Board();
    }
    reset_Tic_tac();
    printf("\npress enter to continue");
    getch();
    system("cls");
    /*********************************************************************************************/
    printf("unit testing for functions of UIdriver:\n");
    printf("2-unit testing of check_The_Location() function\n");
    iterator=0;
    for(int i =0; i<4; i++)
    {
        srand(time(0));
        iterator=array_of_Available_places(arr_available_places);
        if(i%2==0)
        {

            if(iterator!=0)
            {
                Update_The_Board(pointer_To_Our_Board,arr_available_places[rand()%iterator],"USER1");
            }
        }
        else
        {
            if(iterator!=0)
            {
                Update_The_Board(pointer_To_Our_Board,arr_available_places[rand()%iterator],"USER2");
            }
        }
    }
    printf("\nThe Board:\n");
    Print_The_Board();
    printf("\nAvailable places are:\n");
    for(int k =0; k<iterator-1; k++)
    {
        if(arr_available_places[k]==UL)
            printf("UL ");
        else if(arr_available_places[k]==UC)
            printf("UC ");
        else if(arr_available_places[k]==UR)
            printf("UR ");
        else if(arr_available_places[k]==ML)
            printf("ML ");
        else if(arr_available_places[k]==MC)
            printf("MC ");
        else if(arr_available_places[k]==MR)
            printf("MR ");
        else if(arr_available_places[k]==BL)
            printf("BL ");
        else if(arr_available_places[k]==BC)
            printf("BC ");
        else
            printf("BR ");
    }
    printf("\n");
    printf("testing the function\n");
    printf("state of location BL :");
    check_The_Location(pointer_To_Our_Board,BL);
    printf("state of location BM :");
    check_The_Location(pointer_To_Our_Board,BC);
    printf("state of location BR :");
    check_The_Location(pointer_To_Our_Board,BR);
    printf("state of location ML :");
    check_The_Location(pointer_To_Our_Board,ML);
    printf("state of location MC :");
    check_The_Location(pointer_To_Our_Board,MC);
    printf("state of location MR :");
    check_The_Location(pointer_To_Our_Board,MR);
    printf("state of location UL :");
    check_The_Location(pointer_To_Our_Board,UL);
    printf("state of location UC :");
    check_The_Location(pointer_To_Our_Board,UC);
    printf("state of location UR :");
    check_The_Location(pointer_To_Our_Board,UR);
    reset_Tic_tac();
    printf("\npress enter to continue");
    getch();
    system("cls");
    /*********************************************************************************************/
    printf("unit testing for functions of UIdriver:\n");
    printf("3-unit testing of check_Win_situation() function\n");
    iterator=0;
    for(int i =0; i<9; i++)
    {
        srand(time(0));
        iterator=array_of_Available_places(arr_available_places);
        if(i%2==0)
        {

            if(iterator!=0)
            {
                Update_The_Board(pointer_To_Our_Board,arr_available_places[rand()%iterator],"USER1");
            }
        }
        else
        {
            if(iterator!=0)
            {
                Update_The_Board(pointer_To_Our_Board,arr_available_places[rand()%iterator],"USER2");
            }
        }
    }
    printf("\nThe Board:\n");
    Print_The_Board();
    printf("\n");
    printf("testing the function\n");
    if(check_Win_situation()==Winner)
    {
        printf("it is a winning situation\n");
    }
    else
    {
        printf("no winning situation\n");
    }

}







