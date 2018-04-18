#include"functions.h"
#include"menu.h"
#include"adminInterface.h"
#include"studentInterface.h"
#include"courses.h"
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>

int item_student_menu;

void studentInterface(struct student *students,int position)
{
    int choice = 1;

    studentMenu(&item_student_menu);

    while(choice!=item_student_menu)
    {
        choice = getChoiceStudent(choice);
        switch(choice)
        {
        case 1:
            viewStatus(NULL,students,position,2);
            break;
        case 2:
            editStudent(students,position,2);
            break;
        case 3:
            system("cls");  // Function Undone Yet !!!!! Still Under Construction
            coursesInterface(students,2,position);
            break;
        case 4:
            edit_password(students,position);
            break;
        case 5:
            saveData(students);
            LogoutMessage();
            break;
        }
    }
}

/*_____________________________*/
char a1[20][30],a2[20][30];
int numeric_choice;                  /*This are the global variable used in the following function's.*/
/*_____________________________*/
void studentMenu(int *num)
{
    /*
        This is the Menu function. It's displayed just after the Welcome Menu!!!!!
    */
    int i;
    FILE *fp = fopen("StudentMenu","r");
    fscanf(fp,"%d\n",&numeric_choice);
    *num = numeric_choice;
    for(i=0; i<numeric_choice; i++)
        fgets(a1[i],50,fp);
    for(i=0; i<numeric_choice; i++)
        fgets(a2[i],50,fp);

    fclose(fp);
}

int getChoiceStudent(int choice)
{
    /*
        This is the function to permit us to use the arrows to make a selection!!!
    */
    char ch=10;
    while(ch!=13)
    {
        system("cls");
        printf("\n\n\t\t::::: Item's Selection Menu :::::\n");
        if(choice==1)
        {
            printf("\n\n\t\t   -->\t%s",a2[0]);
        }
        else printf("\n\n\t\t\t%s",a1[0]);

        if(choice==2)
        {
            printf("\n\n\t\t   -->\t%s",a2[1]);
        }
        else printf("\n\n\t\t\t%s",a1[1]);

        if(choice==3)
        {
            printf("\n\n\t\t   -->\t%s",a2[2]);
        }
        else printf("\n\n\t\t\t%s",a1[2]);

        if(choice==4)
        {
            printf("\n\n\t\t   -->\t%s",a2[3]);
        }
        else printf("\n\n\t\t\t%s",a1[3]);

        if(choice==5)
        {
            printf("\n\n\t\t   -->\t%s",a2[4]);
        }
        else printf("\n\n\t\t\t%s",a1[4]);

        if(choice==6)
        {
            printf("\n\n\t\t   -->\t%s",a2[5]);
        }
        else printf("\n\n\t\t\t%s",a1[5]);
        if(choice==7)
        {
            printf("\n\n\t\t   -->\t%s",a2[6]);
        }
        else printf("\n\n\t\t\t%s",a1[6]);
        if(choice==8)
        {
            printf("\n\n\t\t   -->\t%s",a2[7]);
        }
        else printf("\n\n\t\t\t%s",a1[7]);
        if(choice==9)
        {
            printf("\n\n\t\t   -->\t%s",a2[8]);
        }
        else printf("\n\n\t\t\t%s",a1[8]);

        printf("\n\n\n\t[ Use UP and DOWN arrow to select an option ]");
        ch = getch();
        if(ch == 72)
            choice--;
        else if(ch == 80)
            choice++;
        if(choice<1)
            choice = 1;
        else if(choice>numeric_choice)
            choice = numeric_choice;
    }
    return choice;
}

