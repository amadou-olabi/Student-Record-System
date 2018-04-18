#include"menu.h"
#include"functions.h"
#include"adminInterface.h"
#include"studentInterface.h"
#include"courses.h"
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<dos.h>
#include<ctype.h>

int num_of_menu_items;

int main()
{

    int choice = 1,alpha;
    int k = 100;
    struct student students[k];
    struct admin users[50];

    welcome();
    Sleep(5000);
    system("cls");
    printf("\n\n\n\n\n\t\t\t**** System Loading ****");
    loadBar();
    loadAdmin(users);
    loadMenu(&num_of_menu_items);
    loadData(students);


    while(choice!=num_of_menu_items)
    {
        choice = getChoice(choice);
        switch(choice)
        {
        case 1:
            system("cls");
            alpha=authentif(students,users,choice);
            if(alpha!=-1)
                adminInterface(users,students,alpha);
            break;
        case 2:
            system("cls");
            printf("\n\t\t\tStudent Interface\n\t\t\t-----------------\n\n");
            printf("\n\t\t1. Login to Student Section (For Old Student)\n\n\t\t2. Registration Section (For New Student)\n\n");
            printf("\n\t\t\tEnter Choice : ");
            fflush(stdin);
            scanf(" %d",&alpha);
            if(alpha==1)
            {
                fflush(stdin);
                alpha=authentif(students,users,choice);
                if(alpha!=-1)
                    studentInterface(students,alpha);
            }
            else if(alpha==2)
                addStudent(students);
            break;
        case 3:
            system("cls");
            printf("\n\t\t\tABOUT THIS SYSTEM\n");
            printf("\n\t\t----STILL UNDER CONSTRUCTION----\n\n");
            printf("\n\t   [Press any Button to go back to main menu.] ");
            getch();
            break;
        case 4:
            saveData(students);
            saveAdmin(users);
            endMessage();
            break;
        }
    }
    return 0;
}
