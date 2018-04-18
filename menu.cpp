#include"menu.h"
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

void welcome()
{
    /*
    Welcome Menu Function. It displays the first preview of this project!!!
    */
    system("cls");
    printf("                       \n\n\n");
    printf("                       \n");
    printf("                            W E L C O M E       \n\n");
    printf("                             T O  T H E        \n\n");
    printf("                        STUDENT RECORD SYSTEM      \n\n");
    printf("                            * * S R S * *      \n");
    printf("\n________________________________________________________________________________");
    printf("\n       Designed By : Fopa Amadou Olabi\t    [ID : 154446]\n");
    //printf("\n                     Hassan Amadu\t    [ID : 154309]\n");
    //printf("\n                     Kum Einstein\t    [ID : 154312]\n");
    printf("________________________________________________________________________________\n");
    Sleep(1000);
    //getch();
}
void endMessage()
{
    /*
       End Message Function. It displays the last preview of this project!!!
    */
    system("cls");
    printf("                       \n\n\n");
    printf("                       \n");
    printf("________________________________________________________________________________\n");
    printf("                            T H A N K   Y O U       \n");
    printf("                             F O R  U S I N G        \n");
    printf("                          STUDENT RECORD SYSTEM      \n");
    printf("                              * * S R S * *      \n");
    printf("________________________________________________________________________________\n");
    printf("\n       Designed By : Fopa Amadou Olabi\t    [ID : 154446]\n");
    //printf("\n                     Hassan Amadu\t    [ID : 154309]\n");
    //printf("\n                     Kum Einstein\t    [ID : 154312]\n");
    printf("********************************************************************************\n\n");
    Sleep(5000);
    //getch();
}
void loadBar()
{
    /*"\r" works to overwrite the single line!!!*/
    printf("\n________________________________________________________________________________\n");
    for (int i=1; i<=1000000; i++)
    {
        printf("\r\t\t      I N   P R O C E S S   %d %c",i/10000,'%');
    }
    printf("\n________________________________________________________________________________\n");
    printf("\n");
    Sleep(100);
}
void LoginMessage()
{
    system("cls");
    printf("\n\n\t\t\t====== LogIn ======\n");
    loadBar();
    printf("\n\n\t\t\t___________________\n\t\t\t| User in Section |\n\t\t\t--------------------\n");
    Sleep(500);
}
void LogoutMessage()
{
    system("cls");
    printf("\n\n\t\t\t====== Log Out ======\n");
    loadBar();
    printf("\n\n\t\t\t___________________\n\t\t\t| Section Over |\n\t\t\t---------------\n");
    Sleep(1000);
}
/*_____________________________*/
char ar1[20][30],ar2[20][30];
int num_choice;                  /*This are the global variable used in the following function's.*/
/*_____________________________*/

void loadMenu(int *num)
{
    /*
        This is the Menu function. It's displayed just after the Welcome Menu!!!!!
    */
    int i;
    FILE *fp = fopen("menu","r");
    fscanf(fp,"%d\n",&num_choice);
    *num = num_choice;
    for(i=0; i<num_choice; i++)
        fgets(ar1[i],20,fp);
    for(i=0; i<num_choice; i++)
        fgets(ar2[i],20,fp);

    fclose(fp);
}

int getChoice(int choice)
{
    /*
        This is the function to permit us to use the arrows to make a selection!!!
    */
    char ch=10;
    while(ch!=13)
    {
        system("cls");
        printf("\n\n\n\t\t::::: Item's Selection Menu :::::\n");

        if(ch == 72)
            choice--;
        else if(ch == 80)
            choice++;
        if(choice<1)
            choice = 1;
        else if(choice>num_choice)
            choice = num_choice;

        if(choice==1)
        {
            printf("\n\n\t\t   -->\t%s",ar2[0]);
        }
        else printf("\n\n\t\t\t%s",ar1[0]);

        if(choice==2)
        {
            printf("\n\n\t\t   -->\t%s",ar2[1]);
        }
        else printf("\n\n\t\t\t%s",ar1[1]);

        if(choice==3)
        {
            printf("\n\n\t\t   -->\t%s",ar2[2]);
        }
        else printf("\n\n\t\t\t%s",ar1[2]);

        if(choice==4)
        {
            printf("\n\n\t\t   -->\t%s",ar2[3]);
        }
        else printf("\n\n\t\t\t%s",ar1[3]);

        if(choice==5)
        {
            printf("\n\n\t\t   -->\t%s",ar2[4]);
        }
        else printf("\n\n\t\t\t%s",ar1[4]);

        if(choice==6)
        {
            printf("\n\n\t\t   -->\t%s",ar2[5]);
        }
        else printf("\n\n\t\t\t%s",ar1[5]);

        printf("\n\n\t\t[ Use UP and DOWN arrow to select an option ]");
        ch = getch();
    }
    return choice;
}
