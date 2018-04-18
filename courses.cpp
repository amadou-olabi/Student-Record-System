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

int total_courses;
int num_choice_course;
char menu_tittle[50];
char t1[10][70],t2[10][70];

void viewCourses(struct student *students,struct courses *tables,int position,int option)
{
    int i,j;
    char sem[3];
    char department[10];
    char *str_dept;
    int str_sem;
    system("cls");

    if(option==1) //to view full courses to be assigned a student who will permit him to make his Choices (Full or Some)
    {
        for(j=0; j<total_courses; j++)
        {
            if(strcmp(students[position].department,tables[j].department)==0)
            {
                if(strcmp(students[position].semester,tables[j].semester)==0)
                {
                    printf("\n\nDepartment : %s         Semester : %s\n\n",tables[j].department,tables[j].semester);
                    printf("\n\t\t========= SEMESTER COURSE TABLE =========\n\n");
                    printf("\n   %s\t%s\t\t%s\n  --------------------------------------------------\n","Course Code","Credit","Course Tittle");
                    for(i=0; i<tables[j].howManyCourse; i++)
                    {
                        printf("%d. %s\t%s\t\t%s\n",i+1,tables[j].course_code[i],tables[j].credit[i],tables[j].course_name[i]);
                    }
                    break;
                }
            }
        }
    }
    else if(option==2) //to view Student Chosen Courses !!!!!
    {
        printf("\n\nDepartment : %s         Semester : %s\n\n",students[position].table.department,students[position].table.semester);
        printf("\n\t\t========= SEMESTER COURSE TABLE =========\n\n");
        printf("\n   %s\t%s\t\t%s\n  --------------------------------------------------\n","Course Code","Credit","Course Tittle");
        for(i=0; i<students[position].table.howManyCourse; i++)
        {
            printf("%d. %s\t%s\t\t%s\n",i+1,students[position].table.course_code[i],students[position].table.credit[i],students[position].table.course_name[i]);
        }
    }
    else if(option==3) //to view courses by Department,Semester
    {
        printf("\n\t\t========= SELECT A DEPARTMENT =========\n\n");
        printf("\n\t--> TVE \n\t--> EEE \n\t--> MCE \n\t--> CSEE \n\t--> CEE ");
        printf("\n\n\t\t Type The Chosen Department : ");
        fflush(stdin);
        gets(department);
        strlwr(department);
        printf("\n\n\t\t Enter a Semester (XX) : ");
        fflush(stdin);
        gets(sem);
        str_sem = atoi(sem);
        for(i=0; i<total_courses; i++)
        {
            strcpy(str_dept,tables[i].department);
            strlwr(str_dept);
            if(strcmp(department,str_dept)==0)
            {
                if(str_sem == atoi(tables[i].semester))
                {
                    system("cls");
                    printf("\n\t\t========= SEMESTER COURSE TABLE =========\n\n");
                    printf("\n\nDepartment : %s         Semester : %s\n\n",tables[i].department,tables[i].semester);
                    printf("\n   %s \t%s \t   %s\n  --------------------------------------------------\n","Course Code","Credit","Course Tittle");
                    fflush(stdin);
                    for(j=0; j<tables[i].howManyCourse; j++)
                    {
                        printf("%d. %s \t%s \t   %s\n",j+1,tables[i].course_code[j],tables[i].credit[j],tables[i].course_name[j]);
                    }
                }
            }
        }
    }
    printf("\n\n\n\t[ Press any key to return to menu.]");
    getch();
}

void assignCourses(struct student *students,struct courses *tables,int table_point,int *selection,int position)
{
    struct student tempo;
    int j;
    int choice;

    system("cls");
    printf("\n\n\t\tCourses Assignment\n");
    if(selection==NULL)
    {
        tempo.table=tables[table_point];
        students[position].table = tempo.table;
    }
    else
    {
        tempo.table.howManyCourse = students[position].table.howManyCourse;
        strcpy(tempo.table.department,tables[table_point].department);
        strcpy(tempo.table.semester,tables[table_point].semester);
        fflush(stdin);
        for(j=0; j<tempo.table.howManyCourse; j++)
        {
            choice=selection[j];
            strcpy(tempo.table.course_name[j],tables[table_point].course_name[choice-1]);
            strcpy(tempo.table.course_code[j],tables[table_point].course_code[choice-1]);
            strcpy(tempo.table.credit[j],tables[table_point].credit[choice-1]);
        }
        fflush(stdin);
        students[position].table = tempo.table;
    }
    loadBar();
    printf("\n\n\tCourses Have Been Successfully Assigned to Student %s\n\n",students[position].ID);
}

void chooseCourses(struct student *students,struct courses *tables,int position)
{
    int i,j;
    int selection[12];
    viewCourses(students,tables,position,1);
    fflush(stdin);
    printf("\n\tEnter The Total Number Of Courses Of Your Choice:  ");
    scanf(" %d",&j);
    if(j>0 && j<=12)
    {
        students[position].table.howManyCourse = j;
        fflush(stdin);
        for(j=0; j<total_courses; j++)
        {
            if(strcmp(students[position].department,tables[j].department)==0)
            {
                if(strcmp(students[position].semester,tables[j].semester)==0)
                {
                    if(students[position].table.howManyCourse==tables[j].howManyCourse)
                    {
                        assignCourses(students,tables,j,NULL,position);
                        break;
                    }
                    else
                    {
                        printf("\n\tSelect from the List Above according to Lines Number of Courses  \n");
                        fflush(stdin);
                        printf("\n\t\tEnter Your Selections (X X X X X . . .) :  ");
                        for(i=0; i<students[position].table.howManyCourse; i++)
                            scanf(" %d",&selection[i]);
                        fflush(stdin);
                        assignCourses(students,tables,j,selection,position);
                        break;
                    }
                }
            }
        }
    }
    else
    {
        printf("\n\n\tNOTE : Too Much or Too Less Total Number of Courses !!!!!!!\n\n");
        printf("\n\t\tAvailable Interval 4 ==> 12\n");
        printf("\n\n[ Press any key to return to menu.]");
        getch();
    }
    printf("\n\n[ Press any key to return to menu.]");
    getch();
}

void coursesInterface(struct student *students,int decision,int position)
{
    int num_items;
    int choice=1;
    struct courses tables[60];
    char student[]="Course Menu For Student";
    char admin[]="Course Menu For Admin";


    loadCourses(tables);
    if(decision==1) // For Administrator
    {
        loadCourseMenu(&num_items,admin);
        while(choice!=num_items)
        {
            choice = getCourseChoice(choice);
            switch(choice)
            {
            case 1:
                defineCourses(tables);
                break;
            case 2:
                deleteCourses(tables);
                break;
            case 3:
                viewCourses(students,tables,position,3);
                break;
            case 4:
                editStudentCourses(tables,students);
                break;
            case 5:
                saveCourses(tables);
                saveData(students);
                break;
            }
        }
    }
    else if(decision==2) //For Student
    {
        loadCourseMenu(&num_items,student);
        while(choice!=num_items)
        {
            choice = getCourseChoice(choice);
            switch(choice)
            {
            case 1:
                chooseCourses(students,tables,position);
                break;
            case 2:
                viewCourses(students,NULL,position,2);
                break;
            case 3:
                system("cls");  // Function Undone Yet !!!!! Still Under Construction
                printf("\n\t\t\t\tDefine Course Option\n");
                printf("\n\t\t\t----STILL UNDER CONSTRUCTION----\n\n");
                printf("\n\t\t\t[Press any Button to go back to profile.] ");
                getch();
                break;
            case 4:
                saveData(students);
                break;
            }
        }
    }
}

void editStudentCourses(struct courses *tables,struct student *students)
{
    int line = searchStudents(students);
    chooseCourses(students,tables,line);
    system("cls");
    printf("\n\n\t The Courses of Student %s has been Edited !!!! \n\n\n",students[line].ID);
    printf("\t\t\tDone Successfully !!!!\n");
    printf("\n\n[ Press any key to return to menu.] ");
    getch();
}

void deleteCourses(struct courses *tables)  // This function can delete an entire semester course's and a specific course in a semester!!!
{
    int choice;
    int i,j;
    int found=0;
    char search_dpt[10];
    char search_ss[5];
    char crs_cod[10];

    system("cls");
    printf("\n\t----DELETE COURSES----\n");
    printf("\n\nDo you want to Delete : \n1. Entire Courses of a Semester\n2. A Specific Course in a Semester \n");
    printf("Enter Choice: ");
    scanf(" %d",&choice);
    if(choice==1)
    {
        system("cls");
        printf("\n\tEnter the Department : ");
        fflush(stdin);
        gets(search_dpt);
        printf("\n\tEnter the Semester : ");
        fflush(stdin);
        gets(search_ss);
        for(i=0; i<total_courses; i++)
        {
            if(!stricmp(tables[i].department,search_dpt))
                if(!stricmp(tables[i].semester,search_ss))
                {
                    found = 1;
                    j = i;
                    break;
                }
        }
        if(found)
        {
            printf("\nDo you want to Delete Courses of Semester %s?\n1. Yes\n2. No\n  ",tables[j].semester);
            fflush(stdin);
            while(choice!=1 && choice!=2)
            {
                scanf(" %d",&choice);
            }
            if(choice==1)
            {
                for(; i<total_courses-1; i++)
                    tables[i] = tables[i+1];
                total_courses--;
                loadBar();
                printf("\n\tSemester %s courses of %s Department has been deleted successfully!!!!!",tables[j].semester,tables[j].department);
            }
            else
                printf("\nCourses WAS NOT Deleted!!!!!!");
        }
        else
            printf("\nDEPARTMENT OR SEMESTER WAS NOT FOUND!!!!");
        printf("\n\n[ Press any key to return to profile.]");
        getch();
    }
    else if(choice==2)
    {
        printf("\n\tEnter the Department : ");
        fflush(stdin);
        gets(search_dpt);
        printf("\n\tEnter the Semester : ");
        fflush(stdin);
        gets(search_ss);
        for(i=0; i<total_courses; i++)
        {
            if(!stricmp(tables[i].department,search_dpt))
                if(!stricmp(tables[i].semester,search_ss))
                {
                    found = 1;
                    j = i;
                    break;
                }
        }
        if(found)
        {
            printf("   %-10s %s\n   -----------------------------------\n","Course Code","Course Name");
            for(int k=0; k<tables[j].howManyCourse; k++)
                printf("%d. %-10s %s\n",k+1,tables[j].course_code[k],tables[j].course_name[k]);
            printf("\n\nEnter the line number of the selected course to be deleted :  ");
            fflush(stdin);
            scanf(" %d",&choice);
            strcpy(crs_cod,tables[j].course_code[choice-1]);
            for(; choice<=tables[j].howManyCourse; choice++)
            {
                strcpy(tables[j].course_code[choice-1],tables[j].course_code[choice]);
                strcpy(tables[j].course_name[choice-1],tables[j].course_name[choice]);
                strcpy(tables[j].credit[choice-1],tables[j].credit[choice]);
            }
            strcpy(tables[j].course_code[tables[j].howManyCourse],"");
            strcpy(tables[j].course_name[tables[j].howManyCourse],"");
            strcpy(tables[j].credit[tables[j].howManyCourse],"");

            tables[j].howManyCourse--;

            loadBar();
            fflush(stdin);
            printf("\n\tCourse %s has been deleted successfully from Semester %s of %s Department!!!!!",crs_cod,tables[j].semester,tables[j].department);
        }
        else
            printf("\nCOURSE WAS NOT FOUND!!!!!!");
    }
    else printf("\nWRONG CHOICE!!!!");
    printf("\n\n[ Press any key to return to profile.]");
    getch();
}

void defineCourses(struct courses *tables)  // This function can define new courses for a semester in a department!!!!
{
    int num_courses;
    system("cls");
    printf("\n--DEFINE COURSES--\n\n");
    fflush(stdin);
    printf("\n\tEnter Department (CSEE / EEE / MCE / CEE / TVE) : ");
    gets(tables[total_courses].department);
    fflush(stdin);
    printf("\n\tDefine Semester (XX) : ");
    gets(tables[total_courses].semester);
    for(int j=0; j<total_courses; j++)      // Checking if Department & Semester already exist !!!
    {
        if(!stricmp(tables[total_courses].department,tables[j].department))
            if(!stricmp(tables[total_courses].semester,tables[j].semester))
            {
                printf("\n\n\tCourses for %s Semester of %s Department have been already defined!!!!",tables[j].semester,tables[j].department);
                goto end;
            }
    }
    fflush(stdin);
    printf("\n\tEnter The Number Of Courses to be Defined :  ");
    scanf(" %d",&num_courses);
    if(num_courses<=12 && num_courses>0)
    {
        // Defining New Courses for a Semester
        tables[total_courses].howManyCourse = num_courses;
        for(int i=0; i<num_courses; i++)
        {
            system("cls");
            printf("\n\t====== Course %d ======",i+1);
            fflush(stdin);
            printf("\n\tEnter Course Full Name: ");
            gets(tables[total_courses].course_name[i]);
            fflush(stdin);
            printf("\n\tEnter Course Code: ");
            gets(tables[total_courses].course_code[i]);
            fflush(stdin);
            printf("\n\tEnter Course Credit (XX): ");
            gets(tables[total_courses].credit[i]);
        }
        printf("\n\t\t Courses Have Been Defined in SRS Successfully!!!!\n");
        total_courses++;
        printf("\n\n[ Press any key to return to menu. ] ");
        getch();
    }
    else
    {
        printf("\n\tThe input number of Course is too much or too less.");
        printf("\n\tInterval of Number of Courses is [1-->12]");
    end:
        printf("\n\n\n\t[ Press any key to return to menu. ] ");
        getch();
    }
}

void saveCourses(struct courses *tables)    // This function save the various tables of courses defined by the administrator!!!
{
    FILE *fp = fopen("courses","w");
    fwrite(&total_courses,sizeof(int),1,fp);
    fwrite(tables,sizeof(struct courses),total_courses,fp);
    fclose(fp);
}

void loadCourses(struct courses *tables)
{
    FILE *fp;
    fp = fopen("courses","r");
    if(fp==NULL)
    {
        printf("can't open the file");
        getch();
        goto End;
    }
    fread(&total_courses,sizeof(int),1,fp);
    fread(tables,sizeof(struct courses),total_courses,fp);
    End:
    fclose(fp);
}

void loadCourseMenu(int *num,char *menu)
{
    /*
        This is the Menu function for Course Interface !!!!!
    */
    int i=0;

    strcpy(menu_tittle,menu);
    FILE *fp = fopen(menu,"r");
    fscanf(fp,"%d\n",&num_choice_course);
    *num = num_choice_course;

    for(i=0; i<num_choice_course; i++)
        fgets(t1[i],50,fp);
    for(i=0; i<num_choice_course; i++)
        fgets(t2[i],50,fp);

    while(i!=10)
    {
        strcpy(t1[i],"");
        strcpy(t2[i],"");
        i++;

    }

    fclose(fp);
}

int getCourseChoice(int choice)
{
    /*
        This is the function to permit us to use the arrows to make a selection!!!
    */
    char ch=10;
    while(ch!=13)
    {
        system("cls");
        printf("\n\n\n\t\t::::: %s :::::\n",menu_tittle);
        if(choice==1)
        {
            printf("\n\n\t\t   -->\t%s",t2[0]);
        }
        else printf("\n\n\t\t\t%s",t1[0]);

        if(choice==2)
        {
            printf("\n\n\t\t   -->\t%s",t2[1]);
        }
        else printf("\n\n\t\t\t%s",t1[1]);

        if(choice==3)
        {
            printf("\n\n\t\t   -->\t%s",t2[2]);
        }
        else printf("\n\n\t\t\t%s",t1[2]);

        if(choice==4)
        {
            printf("\n\n\t\t   -->\t%s",t2[3]);
        }
        else printf("\n\n\t\t\t%s",t1[3]);

        if(choice==5)
        {
            printf("\n\n\t\t   -->\t%s",t2[4]);
        }
        else printf("\n\n\t\t\t%s",t1[4]);

        if(choice==6)
        {
            printf("\n\n\t\t   -->\t%s",t2[5]);
        }
        else printf("\n\n\t\t\t%s",t1[5]);

        printf("\n\n\t      [ Use UP and DOWN arrow to select an option ]");
        ch = getch();
        if(ch == 72)
            choice--;
        else if(ch == 80)
            choice++;
        if(choice<1)
            choice = 1;
        else if(choice>num_choice_course)
            choice = num_choice_course;
    }
    return choice;
}

