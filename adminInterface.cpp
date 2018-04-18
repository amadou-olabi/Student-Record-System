#include"functions.h"
#include"menu.h"
#include"adminInterface.h"
#include"studentInterface.h"
#include"courses.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>

int total_admin;
int items_admin_menu;
/*_____________________________*/
char arr1[20][50],arr2[20][50];
int numchoice;                  /*This are the global variable used in the following function's.*/
/*_____________________________*/
void adminMenu(int *num)
{
    /*
        This is the Menu function. It's displayed just after the Welcome Menu!!!!!
    */
    int i;
    FILE *fp = fopen("AdminMenu","r");
    fscanf(fp,"%d\n",&numchoice);
    *num = numchoice;
    for(i=0; i<numchoice; i++)
        fgets(arr1[i],50,fp);
    for(i=0; i<numchoice; i++)
        fgets(arr2[i],50,fp);

    fclose(fp);
}

int getChoiceAdmin(int choice)
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
            printf("\n\n\t\t   -->\t%s",arr2[0]);
        }
        else printf("\n\n\t\t\t%s",arr1[0]);

        if(choice==2)
        {
            printf("\n\n\t\t   -->\t%s",arr2[1]);
        }
        else printf("\n\n\t\t\t%s",arr1[1]);

        if(choice==3)
        {
            printf("\n\n\t\t   -->\t%s",arr2[2]);
        }
        else printf("\n\n\t\t\t%s",arr1[2]);

        if(choice==4)
        {
            printf("\n\n\t\t   -->\t%s",arr2[3]);
        }
        else printf("\n\n\t\t\t%s",arr1[3]);

        if(choice==5)
        {
            printf("\n\n\t\t   -->\t%s",arr2[4]);
        }
        else printf("\n\n\t\t\t%s",arr1[4]);

        if(choice==6)
        {
            printf("\n\n\t\t   -->\t%s",arr2[5]);
        }
        else printf("\n\n\t\t\t%s",arr1[5]);
        if(choice==7)
        {
            printf("\n\n\t\t   -->\t%s",arr2[6]);
        }
        else printf("\n\n\t\t\t%s",arr1[6]);
        if(choice==8)
        {
            printf("\n\n\t\t   -->\t%s",arr2[7]);
        }
        else printf("\n\n\t\t\t%s",arr1[7]);
        if(choice==9)
        {
            printf("\n\n\t\t   -->\t%s",arr2[8]);
        }
        else printf("\n\n\t\t\t%s",arr1[8]);

        printf("\n\n\n\t[ Use UP and DOWN arrow to select an option ]");
        ch = getch();
        if(ch == 72)
            choice--;
        else if(ch == 80)
            choice++;
        if(choice<1)
            choice = 1;
        else if(choice>numchoice)
            choice = numchoice;
    }
    return choice;
}

int variable()
{
    return total_admin;
}

void loadAdmin(struct admin *users)
{
    FILE *fp;
    fp = fopen("admins","r");
    if(fp==NULL)
    {
        printf("can't open the file");
        goto end;
    }
    fread(&total_admin,sizeof(int),1,fp);
    fread(users,sizeof(struct admin),total_admin,fp);
  end:
    fclose(fp);
}

void addAdmin(struct admin *users)
{
    system("cls");
    printf("\n--ADD AN ADMINISTRATOR--\n\n");
    printf("Enter Your Name : ");
    fflush(stdin);
    gets(users[total_admin].name);
    printf("\nEnter Your Attribute in the Administration : ");
    fflush(stdin);
    gets(users[total_admin].attribut);
    printf("\nEnter any username of your choice : ");
    fflush(stdin);
    gets(users[total_admin].username);
    printf("\n\nEnter Any Password of your choice: ");
    fflush(stdin);
    gets(users[total_admin].password);
    loadBar();
    Sleep(500);
    system("cls");
    printf("\n\t System Access Pass\n\n ");
    printf("\n%-10sAccess Password\n-------------------------\n","Username");
    printf("%-10s%s\n",users[total_admin].username,users[total_admin].password);
    printf("\n\t\t Administrator added in SRS Successfully!!!!\n");
    total_admin++;
    Sleep(1000);
    printf("\n\n[ Press any key to return to menu.]");
    getch();
}

void adminInterface(struct admin *users,struct student *students,int position)
{
    int choice = 1,as;
    adminMenu(&items_admin_menu);
    fflush(stdin);

    while(choice!=items_admin_menu)
    {
        choice = getChoiceAdmin(choice);
        switch(choice)
        {
        case 1:
            viewStatus(users,NULL,position,1);
            break;
        case 2:
            system("cls");
            printf("\n\n\t\t1. Add New Admin\n\t\t2. Add New Student\n\n\t\tEnter Choice: ");
            scanf(" %d",&as);
            fflush(stdin);
            if(as==1)
            {
                system("cls");
                addAdmin(users);
            }
            else if(as==2)
            {
                system("cls");
                addStudent(students);
            }
            else
                printf("\n\n\t\tInvalid Choice!!!");
            break;
        case 3:
            system("cls");
            printf("\n\n\t\t1. Delete Admin\n\t\t2. Delete Student\n\n\t\tEnter Choice: ");
            scanf(" %d",&as);
            fflush(stdin);
            if(as==1)
            {
                system("cls");
                DeleteAdmin(users,position);
            }
            else if(as==2)
            {
                system("cls");
                deleteStudents(students);
            }
            else
                printf("\n\n\t\tInvalid Choice!!!");
            break;
        case 4:
            system("cls");
            printf("\n\n\t\t1. Edit Admin\n\t\t2. Edit Student\n\n\t\tEnter Choice: ");
            scanf(" %d",&as);
            fflush(stdin);
            if(as==1)
            {
                system("cls");
                editAdmin(users,position);
            }
            else if(as==2)
            {
                system("cls");
                editStudent(students,NULL,1);
            }
            else
                printf("\n\n\t\tInvalid Choice!!!");
            break;
        case 5:
            system("cls");
            coursesInterface(students,1,NULL);
            break;
        case 6:
            system("cls");
            printf("\n\n\t\t1. View List of Administrators\n\t\t2. View List of Students\n\n\t\tEnter Choice: ");
            scanf(" %d",&as);
            fflush(stdin);
            if(as==1)
            {
                system("cls");
                adminList(users);
            }
            else if(as==2)
            {
                system("cls");
                viewStudents(students);
            }
            else
                printf("\n\n\t\tInvalid Choice!!!");
            Sleep(500);
            break;
        case 7:
            system("cls");
            printf("\n\n\t\t1. Search For an Administrator\n\t\t2. Search For a Student\n\n\t\tEnter Choice: ");
            scanf(" %d",&as);
            fflush(stdin);
            if(as==1)
            {
                system("cls");
                searchAdmin(users);
            }
            else if(as==2)
            {
                system("cls");
                searchStudents(students);
            }
            else
                printf("\n\n\t\tInvalid Choice!!!");
            break;
        case 8:
            system("cls");
            printf("\n\n\t\t1. Reset Admin Account\n\t\t2. Reset Student Account\n\t\t3. Reset Student Password\n\n\t\tEnter Choice: ");
            scanf(" %d",&as);
            fflush(stdin);
            if(as==1)
            {
                system("cls");
                resetAdmin(users,position);
            }
            else if(as==2)
            {
                system("cls");
                resetAccount(students);
            }
            else if(as==3)
            {
                system("cls");
                reset_password(students);
            }
            else
                printf("\n\n\t\tInvalid Choice!!!");
            break;
        case 9:
            saveAdmin(users);
            saveData(students);
            LogoutMessage();
            break;
        }
    }
}

void DeleteAdmin(struct admin *users,int position)
{
    char search_id[50];
    int found = 0,i,j;
    int choice = 10;
    system("cls");
    printf("\n\n\t\t----Delete Administration Account----\n\n");
    printf("\t\t\tNote: Only The developer's have this right!!!\n\n");
    loadBar();
    Sleep(500);
    if(strcmp(users[position].attribut,"Engineer")==0||strcmp(users[position].attribut,"Developer")==0)
    {
        system("cls");
        printf("\n\t----DELETE ADMINISTRATOR----\n");
        printf("\n\tEnter Admin Username to delete: ");
        fflush(stdin);
        gets(search_id);
        for(i=0; i<total_admin; i++)
        {
            if(!stricmp(users[i].username,search_id))
            {
                found = 1;
                j=i;
                break;
            }
        }
        if(found)
        {
            printf("\nDo you want to delete this administrator: %s?\n1. Yes\n2. No\n",users[j].username);
            while(choice!=1 && choice!=2)
            {
                scanf("%d",&choice);
            }
            if(choice==1)
            {
                for(; i<total_admin; i++)
                    users[i] = users[i+1];
                total_admin--;
                loadBar();
                printf("\n\t%s has been deleted successfully!!!!!",users[j].username);
            }
            else
                printf("\nAdministrator NOT Deleted.");
        }
        else
            printf("\nADMINISTRATOR NOT FOUND!!");
        printf("\n\n[ Press any key to return to profile.]");
        getch();
    }
    else
    {
        printf("\n\tYou Do Not Have the Required Rights to run this Option!!!\n\nPlease Contact Developer's!!!");
        Sleep(700);
    }
}

void saveAdmin(struct admin *users)
{
    FILE *fp = fopen("admins","w");
    fwrite(&total_admin,sizeof(int),1,fp);
    fwrite(users,sizeof(struct admin),total_admin,fp);
    fclose(fp);
}

void adminList(struct admin *users)
{
    int i;
    char ch;
    system("cls");
    if(total_admin)
    {
        printf("Availabale Administrators in System :\n\n");
        printf("\n   %s\t%s\t\t\t%s\n  --------------------------------------------------\n","USERNAME","NAME","ATTRIBUTE");
        for(i=0; i<total_admin; i++)
        {
            printf("%d. %s\t%s\t\t%s\n",i+1,users[i].username,users[i].name,users[i].attribut);
            if(i%10==0 && i>0)
            {
                printf("\n\n==== Press any key to continue list or Press x to return ==> ");
                ch = getch();
                if(ch=='x' || ch=='X')
                    break;
                system("cls");
                printf("\n   %s\t%s\t\t\t%s\n  --------------------------------------------------\n","USERNAME","NAME","ATTRIBUTE");
            }
        }
    }
    else printf("\nAdministrator's list is Empty!!!\n");
    printf("\n\n[ Press any key to return to menu. ]");
    getch();
}

void resetAdmin(struct admin *users,int position)
{
    int LINE;
    char ch;

    system("cls");
    printf("\n\n\t\t----Reset Administration Account----\n\n");
    printf("\t\t\tNote: Only The developer's have this right!!!\n\n");
    loadBar();
    Sleep(500);
    if(strcmp(users[position].attribut,"Developer")==0 || strcmp(users[position].attribut,"Engineer")==0)
    {
        system("cls");
        printf("\n\n\t\t\t==== Welcome Developer %s ====\n",users[position].username);
        LINE=searchAdmin(users);
        editAdmin(users,LINE);
        printf("\n  Do you want to reset the Student password\n1. Yes (Y)\n2.No (N)\nChoice: ");
        ch=getchar();

        if(ch=='Y'||ch=='y')
        {
            printf("\nEnter Your New Password: ");
            scanf(" %s",users[LINE].password);
            loadBar();
            printf("\n\n\t\t\tAdministrator Account has been reset Successfully\n");
            Sleep(700);
            system("cls");
            printf("\n\t System Access Pass is now:\n\n ");
            printf("\n%-20sPASSWORD\n----------------------------------\n","USERNAME");
            printf("%-20s%s\n",users[LINE].username,users[LINE].password);
            printf("\nName : %s",users[LINE].name);
            printf("\n\n\t\t\tDone!!!!!");
            Sleep(1000);
        }
    }
    else
    {
        printf("\n\tYou Do Not Have the Required Rights to run this Option!!!\n\nPlease Contact Developer's!!!");
        Sleep(700);
    }
}

void editAdmin(struct admin *users,int position)
{
    int line;
    //int i=0;
    struct admin tempo;

    system("cls");
    printf("\n\n\t\t\t----EDIT ADMIN----\n\n");
    Sleep(500);
    if(strcmp(users[position].attribut,"Developer")==0 || strcmp(users[position].attribut,"Engineer")==0)
    {
        line=searchAdmin(users);
        system("cls");
        printf("\n\t\tInsert the New Information's--->>\n");
        printf("\n          ===== Edit As %s ====\n",users[position].attribut);
        printf("\n  \tAdministrator: '%s' have the required rights to run this option and may start modifications.\n\n",users[position].username);
        printf("\nEnter New Name: ");
        gets(tempo.name);
        printf("\nEnter New Attribute in the Administrator: ");
        gets(tempo.attribut);
        printf("\nEnter New Username: ");
        gets(tempo.username);
        printf("\nEnter Administrator New Password: ");
        gets(tempo.password);
        users[line]=tempo;
        loadBar();
        Sleep(500);
        system("cls");
        printf("\n\t System Access Pass\n\n ");
        printf("\n%-10s     Access Password\n-------------------------\n","Username");
        printf("%-10s       %s\n",users[line].username,users[line].password);
        printf("\n\t\t The Developer have modified user datas in SRS Successfully!!!!\n");
        printf("\n\n[ Press any key to return to menu.]");
        getch();
    }
    else
    {
        printf("\n  \tAdministrator: '%s' cannot run this option.\n\n",users[position].username);
        printf("  \tNote: Only The developer's have this right!!!\n\n");
        printf("\n\tYou Do Not Have the Required Rights to run this Option!!!\n\n\tPlease Contact Developer!!!");
        printf("\n\n\n\n\t\t[ Press any key to return to menu.]");
        getch();
    }
}

int searchAdmin(struct admin *users)
{
    int position;
    char ch[]="";
    fflush(stdin);
    printf("\nEnter Username : ");
    gets(ch);
    for(int i=0; i<total_admin; i++)
    {
        if(strcmp(ch,users[i].username)==0)
        {
            printf("\nAdministrator Found!!!\n");
            printf("\n%-10sNAME\n----------------------------------\n","USERNAME");
            printf("%-10s%s",users[i].username,users[i].name);
            position = i;
            break;
        }
    }
    // else if(i==total_admin) printf("\nAdministrator NOT Found!!!\n");
    printf("\n\n[ Press any key to continue.]");
    getch();
    return position;
}

void viewStatus(struct admin *users,struct student *students,int position,int decision)
{
    int i;
    system("cls");
    if(decision==1)     // FOR ADMINISTRATOR
    {
        printf("\n\n\t\t::::::: On Section Administrator Infos ::::::: \n\n");
        printf("\n%s        %s         %s           %s\n----------------------------------------------------------\n","USERNAME","Password","NAME","ATTRIBUTE");
        printf("%s        %s         %s           %s\n",users[position].username,users[position].password,users[position].name,users[position].attribut);
        printf("\n\n[ Press any key to return. ]");
        fflush(stdin);
        getch();
    }
    else if(decision==2)    // FOR STUDENT
    {
        printf("On Section Student Infos: \n\n");
        printf("%s: %s\n%s: %s\n%s: %s\n%s: %s\n","Student ID",students[position].ID,"NAME",students[position].name,"Born on the",students[position].birthInfos,"Gender",students[position].gender);
        printf("%s: %s\n%s: %s\n%s: %s\n%s: %s\n","Father Name",students[position].father,"Mother Name",students[position].mother,"Address",students[position].address,"Phone",students[position].phone);
        printf("%s: %s\n%s: %s\n%s: %s\n%s: %s\n\n","Department",students[position].department,"Program",students[position].program,"Bach Year",students[position].bach,"Semester",students[position].semester);
        printf("Do you want to see your password?\n1. Yes\n2. No\n");
        printf("Enter Choice: ");
        scanf(" %d",&i);
        if(i==1) printf("\n\n\t\tPassword: %s\n",students[position].password);
        else if(i==2)
        {
            int len,lm;
            lm=strlen(students[position].password);
             printf("\n\n\t\tPassword: \n");
            for(len=0; len<lm; len++)
                printf("*");
        }
        printf("\n\n\n[ Press any key to return. ]");
        fflush(stdin);
        getch();
    }
}
