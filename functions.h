#ifndef __FUNCTIONS_HEADER_
#define __FUNCTIONS_HEADER_

struct courses
{
    char course_name[12][100];
    char course_code[12][20];
    char credit[12][3];
    char department[10];
    char semester[3];
    int howManyCourse;
};

struct student{
    char ID[6];
    char name[50];
    char birthInfos[15];
    char address[100];
    char country[50];
    char password[50];
    char father[80];
    char mother[80];
    char program[50];
    char department[5];
    char semester[3];
    char phone[20];
    char bach[5];
    char gender[5];
    struct courses table;
};

void loadData(struct student *students);
void saveData(struct student *students);
void viewStudents(struct student *students);
void addStudent(struct student *students);
void sortStudents(struct student *students);
void deleteStudents(struct student *students);
void editStudent(struct student *students,int position,int decision);
int searchStudents(struct student *students);
int authentif(struct student *students,struct admin *users,int decision);
void random_password(struct student *students,int index);
void edit_password(struct student *students,int position);
void random_id(struct student *students);
void reset_password(struct student *students);
int resetAccount(struct student *students);


#endif // __FUNCTIONS_HEADER_
