#include"functions.h"
#include"menu.h"
#include"adminInterface.h"
#include"studentInterface.h"
#include"courses.h"
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<math.h>
#include<ctype.h>

int total_students;

void loadData(struct student *students)
{
    FILE *fp;
    fp = fopen("students","r");
    if(fp==NULL)
    {
        printf("can't open the file");
        goto end;
    }
    fread(&total_students,sizeof(int),1,fp);
    fread(students,sizeof(struct student),total_students,fp);
    end:
    fclose(fp);
}

void viewStudents(struct student *students)  // Only Administrator can use this function
{
    int i,j=0;
    int choice;
    system("cls");
    if(total_students)
    {
        printf("\n\t\t========= LIST OF STUDENT IN SYSTEM =========\n");
        printf("\n\n\t1. View All Students in System\n\t2. View Students By Departments\n\t3. View Students By Programs\n\n\tEnter Choice : ");
        scanf(" %d",&choice);
        if(choice==1)   // View All Students
        {
            system("cls");
            printf("\n total students = %d",total_students);
            fflush(stdin);
            printf("\n\n\t\tAvailable Students in System are:\n\n");
            printf("\n   %-10s %s \t%13s\t %s\n  --------------------------------------------------\n","Dpt.","Prog.","STUDENT ID","FULL NAME");
            for(i=0; i<total_students; i++)
            {
                printf("%d. %-10s %s \t%10s\t %s\n",i+1,students[i].department,students[i].program,students[i].ID,students[i].name);
            }
        }
        else if(choice==2)   // View by Department
        {
            system("cls");
            printf("\n\nDepartment : %s\n\n","TVE");
            printf("\n   %-10s %s %10s\n  --------------------------------------------------\n","Prog.","STUDENT ID","FULL NAME");
            j=0;
            for(i=0; i<total_students; i++)
            {
                if(strcmp(students[i].department,"TVE")==0)
                {
                    printf("%d. %-10s %s %20s \n",j+1,students[i].program,students[i].ID,students[i].name);
                    j++;
                }
            }
            fflush(stdin);
            printf("\n\nDepartment : %s\n\n","EEE");
            printf("\n   %-10s %s %10s\n  --------------------------------------------------\n","Prog.","STUDENT ID","FULL NAME");
            j=0;
            for(i=0; i<total_students; i++)
            {
                if(strcmp(students[i].department,"EEE")==0)
                {
                    printf("%d. %-10s %s %20s\n",j+1,students[i].program,students[i].ID,students[i].name);
                    j++;
                }
            }
            fflush(stdin);
            printf("\n\nDepartment : %s\n\n","MCE");
            printf("\n   %-10s %s %10s\n  --------------------------------------------------\n","Prog.","STUDENT ID","FULL NAME");
            j=0;
            for(i=0; i<total_students; i++)
            {
                if(strcmp(students[i].department,"MCE")==0)
                {
                    printf("%d. %-10s %s %20s\n",j+1,students[i].program,students[i].ID,students[i].name);
                    j++;
                }
            }
            fflush(stdin);
            printf("\n\nDepartment : %s\n\n","CSEE");
            printf("\n   %-10s %s %10s\n  --------------------------------------------------\n","Prog.","STUDENT ID","FULL NAME");
            j=0;
            for(i=0; i<total_students; i++)
            {
                if(strcmp(students[i].department,"CSEE")==0)
                {
                    printf("%d. %-10s %s %20s\n",j+1,students[i].program,students[i].ID,students[i].name);
                    j++;
                }
            }
            fflush(stdin);
            printf("\n\nDepartment : %s\n\n","CEE");
            printf("\n   %-10s %s %10s\n  --------------------------------------------------\n","Prog.","STUDENT ID","FULL NAME");
            j=0;
            for(i=0; i<total_students; i++)
            {
                if(strcmp(students[i].department,"CEE")==0)
                {
                    printf("%d. %-10s %s %20s\n",j+1,students[i].program,students[i].ID,students[i].name);
                    j++;
                }
            }
            fflush(stdin);
        }
        else if(choice==3)   // View by Program
        {
            system("cls");
            printf("\n\n\nProgram : %s\n\n","H.D");
            printf("\n   %-10s%s%10s\n   --------------------------------------------------\n","Dpt.","STUDENT ID","FULL NAME");
            j=0;
            for(i=0; i<total_students; i++)
            {
                if(strcmp(students[i].program,"H.D")==0)
                {
                    printf("%d. %-10s %s %20s\n",j+1,students[i].department,students[i].ID,students[i].name);
                    j++;
                }
            }
            printf("\n\n\nProgram : %s\n\n","B.Sc.");
            printf("\n   %-10s%s%10s\n   --------------------------------------------------\n","Dpt.","STUDENT ID","FULL NAME");
            j=0;
            for(i=0; i<total_students; i++)
            {
                if(strcmp(students[i].program,"B.Sc.")==0)
                {
                    printf("%d. %-10s %s %20s\n",j+1,students[i].department,students[i].ID,students[i].name);
                    j++;
                }
            }
            printf("\n\n\nProgram : %s\n\n","M.Sc.");
            printf("\n   %-10s%s%10s\n   --------------------------------------------------\n","Dpt.","STUDENT ID","FULL NAME");
            j=0;
            for(i=0; i<total_students; i++)
            {
                if(strcmp(students[i].program,"M.Sc.")==0)
                {
                    printf("%d. %-10s %s %20s\n",j+1,students[i].department,students[i].ID,students[i].name);
                    j++;
                }
            }
        }
        else printf("\n\n\t     WRONG CHOICE !!!!!!");
    }
    else printf("\n\n\t\tStudents list is empty\n");
    printf("\n\n[ Press any key to return to menu. ]");
    getch();
}

void addStudent(struct student *students)   // For Both Student and Administrator
{
    system("cls");
    printf("\n--ADD A STUDENT--\n\n");
    printf("\n\tEnter Student Name : ");
    fflush(stdin);
    gets(students[total_students].name);
    printf("\n\n\tEnter Date of Birth (DD/MM/YYYY) : ");
    fflush(stdin);
    gets(students[total_students].birthInfos);
    printf("\n\n\tEnter Student Gender : ");
    fflush(stdin);
    gets(students[total_students].gender);
    printf("\n\n\tEnter Student Country : ");
    gets(students[total_students].country);
    printf("\n\n\tEnter Father's Name : ");
    gets(students[total_students].father);
    printf("\n\n\tEnter Mother's Name : ");
    fflush(stdin);
    gets(students[total_students].mother);
    printf("\nEnter Student Address : ");
    fflush(stdin);
    gets(students[total_students].address);
    printf("\n\n\tEnter Student Phone Number : ");
    fflush(stdin);
    gets(students[total_students].phone);
    printf("\n\n\tEnter Student Department\nChoose from this (CSEE / EEE / MCE / CEE / TVE) : ");
    gets(students[total_students].department);
    printf("\n\n\tEnter Student Chosen Program (B.Sc. / H.D / M.Sc.) : ");
    fflush(stdin);
    gets(students[total_students].program);
    printf("\n\n\tEnter Student Bach Year (XXXX) : ");
    gets(students[total_students].bach);
    printf("\n\n\tEnter Student Actual Semester (XX) : ");
    gets(students[total_students].semester);
    fflush(stdin);
    random_password(students,total_students);
    random_id(students);
    fflush(stdin);
    loadBar();
    Sleep(500);
    system("cls");
    printf("\n\t System Access Pass\n\n ");
    printf("\n%-20sAccess Password\n  ----------------------------------\n","Student ID");
    printf("%-20s%s\n",students[total_students].ID,students[total_students].password);
    fflush(stdin);
    printf("\n\t\t Student added in SRS Successfully!!!!\n");
    printf("\n\n[ Press any key to return to menu.]");
    getch();
    total_students++;
    sortStudents(students);
}

void random_password(struct student *students,int index)    // Only Administrator can use this function
{
    int p_digit[4];
    char p_tempo[6];
    int k;
    int i;
    fflush(stdin);
    for(i=0; i<4; i++)
    {
        p_digit[i] = ( rand() % 4 ) + 1;
    }
    fflush(stdin);
    p_tempo[0] = students[index].name[0];
    p_tempo[1] = students[index].name[strlen(students[index].name) - p_digit[0]];
    fflush(stdin);
    for(k=0,i=2; k<4 && i<6 ; k++,i++)
    {
        p_tempo[i] = (p_digit[k]+48);
    }
    fflush(stdin);
    p_tempo[6]='\0';
    strcpy(students[index].password,p_tempo);
    fflush(stdin);
}

void random_id(struct student *students)    // Only Administrator can use this function
{
    char id_tempo[8];
    char id_rank[2];
    fflush(stdin);
    itoa(total_students,id_rank,10);
    id_tempo[0]=students[total_students].bach[2];
    id_tempo[1]=students[total_students].bach[3];
    fflush(stdin);
    if(strcmp(students[total_students].department,"TVE")==0)
        id_tempo[2]='1';
    else if(strcmp(students[total_students].department,"EEE")==0)
        id_tempo[2]='2';
    else if(strcmp(students[total_students].department,"MCE")==0)
        id_tempo[2]='3';
    else if(strcmp(students[total_students].department,"CSEE")==0)
        id_tempo[2]='4';
    else if(strcmp(students[total_students].department,"CEE")==0)
        id_tempo[2]='5';
    fflush(stdin);
    switch(students[total_students].program[0])
    {
    case 'B':
        id_tempo[3]='4';
        break;
    case 'H':
        id_tempo[3]='3';
        break;
    case 'M':
        id_tempo[3]='6';
        break;
    }
    fflush(stdin);
    id_tempo[4]='\0';
    strcat(id_tempo,id_rank);
    fflush(stdin);
    strcpy(students[total_students].ID,id_tempo);
    fflush(stdin);
}

void sortStudents(struct student *students)
{

    struct student tempo;
    int i,j;
    for(i=0; i<total_students; i++)
    {
        for(j=0; j<total_students; j++)
        {
            if(strcmp(students[j].ID,students[j+1].ID)<0)
            {
                tempo=students[j];
                students[j]=students[j+1];
                students[j+1]=tempo;
            }
        }
    }
}

void deleteStudents(struct student *students)   // Only Administrator can use this function
{
    char search_id[50];
    int found = 0, i;
    int choice = 10;
    system("cls");
    printf("\n\t----DELETE STUDENT----\n");
    printf("\n\tEnter Student ID : ");
    fflush(stdin);
    gets(search_id);
    for(i=0; i<total_students; i++)
    {
        if(!stricmp(students[i].ID,search_id))
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        printf("\nDo you want to delete this student of ID: %s?\n1. Yes\n2. No\n",students[i].ID);
        while(choice!=1 && choice!=2)
        {
            scanf("%d",&choice);
        }
        if(choice==1)
        {
            for(; i<total_students-1; i++)
                students[i] = students[i+1];
            total_students--;
            loadBar();
            printf("\n\tStudent has been deleted successfully!!!!!");
        }
        else
            printf("\nStudent NOT Deleted.");
    }
    else
        printf("\nSTUDENT NOT FOUND!!");
    printf("\n\n[ Press any key to return to menu.]");
    getch();
}

void saveData(struct student *students)
{
    FILE *fp = fopen("students","w");
    fwrite(&total_students,sizeof(int),1,fp);
    fwrite(students,sizeof(struct student),total_students,fp);
    fclose(fp);
}

void editStudent(struct student *students,int position,int decision)    // For Both Student and Administrator
{
    int line;
    int i=0;
    struct student tempo;

    system("cls");
    printf("\n\n\t----EDIT STUDENT----\n\n");
    Sleep(500);
    line=searchStudents(students);
    system("cls");
    printf("\n\t\tInsert the New Information's--->>\n");
    switch(decision)
    {
    case 1:                     // As Administrator
a:
        system("cls");
        printf("\n=====Edit As Administrator====");
        printf("\n\tStudent: %s\n",students[line].name);
        fflush(stdin);
        printf("\n\tEnter Student Name : ");
        gets(tempo.name);
        printf("\n\n\tEnter Date of Birth (DD/MM/YYYY) : ");
        fflush(stdin);
        gets(tempo.birthInfos);
        printf("\n\n\tEnter Student Gender : ");
        fflush(stdin);
        gets(tempo.gender);
        printf("\n\n\tEnter Student Country : ");
        gets(tempo.country);
        printf("\n\n\tEnter Father's Name : ");
        gets(tempo.father);
        printf("\n\n\tEnter Mother's Name : ");
        fflush(stdin);
        gets(tempo.mother);
        printf("\n\n\tEnter Student Address : ");
        gets(tempo.address);
        printf("\n\n\tEnter Student Phone Number : ");
        fflush(stdin);
        gets(tempo.phone);
        printf("\n\n\tEnter Student Department\nChoose from this (CSEE / EEE / MCE / CEE / TVE) : ");
        gets(tempo.department);
        printf("\n\n\tEnter Student Chosen Program (B.Sc. / H.D / M.Sc.) : ");
        fflush(stdin);
        gets(tempo.program);
        printf("\n\n\tEnter Student Actual Semester (XX) : ");
        gets(tempo.semester);
        fflush(stdin);
        printf("\n\n\t\tAre you okay with this modification?\n\t1. Yes and Save\n\t2. No and Exit\n\t3. No and Restart Edit\n\n\tEnter choice: ");
        scanf(" %d",&i);
        if(i==1)
        {
            strcpy(students[line].name,tempo.name);
            strcpy(students[line].birthInfos,tempo.birthInfos);
            strcpy(students[line].gender,tempo.gender);
            strcpy(students[line].country,tempo.country);
            strcpy(students[line].father,tempo.father);
            strcpy(students[line].mother,tempo.mother);
            strcpy(students[line].address,tempo.address);
            strcpy(students[line].phone,tempo.phone);
            strcpy(students[line].department,tempo.department);
            strcpy(students[line].program,tempo.program);
            strcpy(students[line].semester,tempo.semester);
            printf("\nDone!!!!!");
            goto b;
        }
        else if(i==2) goto endF;
        else goto a;
b:
        printf("\n\n\t[ Press Any Button to Return to Profile. ] ");
        fflush(stdin);
        getch();
        break;

    case 2:             // As Student
aa:
        system("cls");
        printf("\n\t========== Edit As ==========");
        printf("\n\tStudent: %s\n",students[position].ID);
        fflush(stdin);
        printf("\n\tEnter New Student Name : ");
        gets(tempo.name);
        printf("\n\n\tEnter Date of Birth (DD/MM/YYYY) : ");
        fflush(stdin);
        gets(tempo.birthInfos);
        printf("\n\n\tEnter Student Gender : ");
        fflush(stdin);
        gets(tempo.gender);
        printf("\n\n\tEnter Student Country : ");
        gets(tempo.country);
        printf("\n\n\tEnter Father's Name : ");
        gets(tempo.father);
        printf("\n\n\tEnter Mother's Name : ");
        fflush(stdin);
        gets(tempo.mother);
        printf("\n\n\tEnter Student Address : ");
        gets(tempo.address);
        printf("\n\n\tEnter Student Phone Number : ");
        fflush(stdin);
        gets(tempo.phone);
        printf("\n\n\tEnter Student Actual Semester (XX) : ");
        gets(tempo.semester);
        fflush(stdin);
        printf("\n\n\t\tAre you okay with this modification?\n\t1. Yes and Save\n\t2. No and Exit\n\t3. No and Restart Edit\n\n\tEnter choice: ");
        scanf(" %d",&i);
        if(i==1)
        {
            strcpy(students[position].name,tempo.name);
            strcpy(students[position].birthInfos,tempo.birthInfos);
            strcpy(students[position].gender,tempo.gender);
            strcpy(students[position].country,tempo.country);
            strcpy(students[position].father,tempo.father);
            strcpy(students[position].mother,tempo.mother);
            strcpy(students[position].address,tempo.address);
            strcpy(students[position].phone,tempo.phone);
            strcpy(students[position].semester,tempo.semester);
            printf("\nDone!!!!!");
            goto bb;
        }
        else if(i==2)
        {
            printf("\n\n\t\t Modifications Abort !!!!!!\n\n");
            goto endF;
        }
        else
        {
            printf("\n\n\t\tWRONG CHOICE !!!!!\n");
            Sleep(700);
            goto aa;
        }
bb:
        printf("\n\n\t[ Press Any Button to Return to Profile. ] ");
        fflush(stdin);
        getch();
        break;
    }
    printf("\n\nStudent modified successfully!!!!!");
endF:
    printf("\n\n[ Press any key to return to menu.]");
    getch();
}

int searchStudents(struct student *students)    // Only Administrator can use this function
{
    int position;
    char ch[50];
    char *test;
    int i;
    char *ret;

    system("cls");
    printf("\n----SEARCH STUDENT----\n");
    printf("\n\n\t1. Search By ID\n\t2. Search By Name\n\n\t Enter choice: ");
    scanf(" %d",&i);
    fflush(stdin);
    if(i==1)
    {
        printf("\nEnter Student ID : ");
        gets(ch);
        fflush(stdin);
        for(i=0; i<total_students; i++)
        {
            ret = strstr(students[i].ID, ch);
            if(ret)
            {
                printf("\nStudent Found!!!\n");
                printf("\n%-10s%sNAME\n----------------------------------\n","Student ID","Department");
                printf("%-10s%s%10s",students[i].ID,students[i].department,students[i].name);
                fflush(stdin);
                position=i;
                return position;
            }
            else if(i==total_students-1)
            {
                printf("\nStudent NOT Found!!!\n");
            }
        }
    }
    else if(i==2)
    {
        printf("\nEnter a Student Substring Name : ");
        gets(ch);
        fflush(stdin);
        strlwr(ch);
        fflush(stdin);
        printf("\nThis are the Students Name's Matching with Substring %s\n",ch);
        for(i=0; i<total_students; i++)
        {
            strcpy(test,students[i].name);
            strlwr(test);
            ret = strstr(test,ch);
            if(ret)
            {
                printf("\n%-10s%sNAME\n----------------------------------\n","Student ID","Department");
                printf("%-10s%s%10s",students[i].ID,students[i].department,students[i].name);
                fflush(stdin);
                printf("\n\n[ Press any key to continue.]");
                getch();
                position = i;
                return position;
            }
            else if(i==total_students-1)
            {
                printf("\n-----------------------------------------------\n\t\tNOT STUDENTS MATCHES WITH THE GIVEN SUBSTRING!!!\n");
                printf("-----------------------------------------------\n");
            }
        }
    }
    else
    {
        printf("\n\n\t WRONG CHOICE!!!!!!\n");
        return -1;
    }
}

void edit_password(struct student *students,int position) // This function is only for students used !!!
{
    //printf("\n\n\t----EDIT PASSWORD----\n\n");
    //Sleep(500);
    //int position = searchStudents(students);
    char tempo[50];
    char tempo_cc[50];
    loadBar();
s:
    system("cls");
    fflush(stdin);
    printf("\n\n\t\t\t----EDIT PASSWORD----\n\n");
    printf("\n\tStudent : %s --> ID : %s\n",students[position].name,students[position].ID);
    printf("\n\n\tEnter New Password (Password Length [6 to 50])\n\n-->");
    gets(tempo);
    fflush(stdin);
    if(strlen(tempo)>=51)
    {
        printf("\nToo Much Long Password.\nNote: Password max-length = '50'\n");
        Sleep(600);
        goto s;
    }
    else if(strlen(tempo)<5)
    {
        printf("\nToo Short Password.\nNote: Password min-length = '6'\n");
        Sleep(600);
        goto s;
    }
    fflush(stdin);
    printf("\n\tConfirm New Password : ");
    gets(tempo_cc);
    if(strcmp(tempo,tempo_cc)==0)
        strcpy(students[position].password,tempo);
    system("cls");
    printf("\n\t New System Access Pass\n\n ");
    printf("\n%-20s Access Password\n----------------------------------\n","Student ID");
    printf("%-20s %s\n",students[position].ID,students[position].password);
    printf("\nName : %s",students[position].name);
    printf("\n\n\t\t\tDone!!!!!");
    Sleep(1000);
    printf("\n\n[ Press any key to return to menu.]");
    getch();
    fflush(stdin);
}

int resetAccount(struct student *students) // Only for Administrator
{
    int LINE;
    char ch;
    LINE=searchStudents(students);
    system("cls");
    printf("\n\n\t----Reset Student Account----\n\n");
    Sleep(1000);
    editStudent(students,LINE,1);
kl:
    printf("\n  Do you want to reset the Student password\n1. Yes (Y)\n2. No (N)\nChoice: ");
    ch=getchar();
    if(ch=='N'||ch=='n')
    {
        goto zz;
    }
    else if(ch=='Y'||ch=='y')
    {
        random_password(students,LINE);
        system("cls");
        loadBar();
        printf("\n\nDone!!!!!");
        printf("\n\t System Access Pass\n\n ");
        printf("\n%-20sAccess Password\n  ----------------------------------\n","Student ID");
        printf("%-20s%s\n",students[LINE].ID,students[LINE].password);
        printf("\nName : %s",students[LINE].name);
        printf("\n\n\t\t\tDone!!!!!");
        Sleep(1000);
        return 0; //If this value returns then the account with the password have been reset!!!
    }
    else
    {
        printf("\nInvalid Choice!!!\n");
        Sleep(500);
        system("cls");
        goto kl;
    }
zz:
    printf("Escape\n");
    Sleep(500);
    system("cls");
    loadBar();
    printf("\n\nDone!!!!!");
    printf("\n\t System Access Pass\n\n ");
    printf("\n%-20sAccess Password\n  ----------------------------------\n","Student ID");
    printf("%-20s%s\n",students[LINE].ID,students[LINE].password);
    printf("\nName : %s",students[LINE].name);
    printf("\n\n\t\t\tDone!!!!!");
    printf("\n\n\t\t[Press Any Button to return.] ");
    getch();
    return 1; //If this value returns then the account only without the password have been reset!!!

}

int authentif(struct student *students,struct admin *users,int decision)    // For Both Student and Administrator
{
    char ch[50];
    char a[50]="",c;
    int i=0;
    int j=0;
    int trial=0;
    int total_admin=variable();
    system("cls");
    printf("\n\n\t\t\tWelcome to the Login Interface\n\t\t\t------------------------------\n\n");
    if(decision==1) //admin
    {
tt:
        printf("                         NUMBER OF TRIAL : %d/3\n\n\n",trial+1);
        printf("                        ENTER YOUR USERNAME :  ");
        fflush(stdin);
        gets(ch);
        fflush(stdin);

        printf("                       \n\n");
        printf("                        ENTER YOUR PASSWORD :  ");
        fflush(stdin);
        while((c=getch())!='\r')
        {
            if(c==8)
            {
                if(i)
                {
                    printf("%c",c);
                    printf(" ");
                    printf("%c",c);
                    i--;
                }
            }
            else
            {
                printf("*");
                a[i]=c;
                i++;
            }

        }
        fflush(stdin);
        a[i]='\0';
        while(1)
        {
            if(strcmp(ch,users[j].username)==0)
            {
                if(strcmp(a,users[j].password)==0)
                {
                    LoginMessage();
                    Sleep(500);
                    return j;
                }
                else
                {
                    printf("\n\n\n\n\n                            WRONG PASSWORD !!!!!!    ");
                    Sleep(500);
                    system("cls");
                    break;
                }

            }
            else if(j==total_admin)
            {
                system("cls");
                printf("\n\n\n\n\n                         WRONG USERNAME OR PASSWORD !!!!!!    ");
                Sleep(500);
                system("cls");
                break;
            }
            j++;
        }
        trial++;
        if(trial==3)
        {
            system("cls");
            printf("\n\n\t\t\t WRONG USER!!!");
            Sleep(1000);
            return -1;
        }
        i = 0 ;
        goto tt;
    }
    else if(decision==2) //student
    {
aaa:
        printf("                          NUMBER OF TRIAL : %d/3\n\n\n",trial+1);
        printf("                        ENTER YOUR STUDENT ID :  ");
        fflush(stdin);
        gets(ch);
        fflush(stdin);
        trial++;
        printf("                       \n\n");
        printf("                        ENTER YOUR PASSWORD :  ");
        fflush(stdin);
        while((c=getch())!='\r')
        {
            if(c==8)
            {
                if(i)
                {
                    printf("%c",c);
                    printf(" ");
                    printf("%c",c);
                    i--;
                }
            }
            else
            {
                printf("*");
                a[i]=c;
                i++;
            }
        }
        a[i]='\0';
        while(1)
        {
            if(strcmp(ch,students[j].ID)==0)
            {
                if(strcmp(a,students[j].password)==0)
                {
                    LoginMessage();
                    Sleep(1000);
                    fflush(stdin);
                    return j;
                }
                else
                {
                    printf("\n\n\n\n\n                            WRONG PASSWORD !!!!!!    ");
                    Sleep(700);
                    system("cls");
                    fflush(stdin);
                    break;
                }

            }
            else if(j==total_students-1)
            {
                printf("\n\n\n\n\n                            WRONG ID OR PASSWORD !!!!!!    ");
                Sleep(700);
                system("cls");
                fflush(stdin);
                break;
            }
            j++;
        }
        if(trial==3)
        {
            system("cls");
            printf("\n\n\t\t\t WRONG STUDENT USER!!!");
            Sleep(1000);
            fflush(stdin);
            return -1;
        }
        i = 0 ;
        goto aaa;
    }
    return -1;
}

void reset_password(struct student *students)   // Only for Administrator
{
    int LINE = searchStudents(students);
    random_password(students,LINE);
    loadBar();
    printf("\n\n\t\t\tPassword Reset Successfully!!!!!\n");
    Sleep(700);
    system("cls");
    printf("\n\t System Access Pass\n\n ");
    printf("\n%-20sAccess Password\n----------------------------------\n","Student ID");
    printf("%-20s%s\n",students[LINE].ID,students[LINE].password);
    printf("\n\n\tName : %s",students[LINE].name);
    printf("\n\n\t\t\tDone!!!!!");
    printf("\n\n\t\t[Press Any Button to return.] ");
    getch();
}

