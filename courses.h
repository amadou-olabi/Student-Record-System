#ifndef __COURSES_HEADER_
#define __COURSES_HEADER_

void assignCourses(struct student *students,struct courses *tables,int table_point,int *selection,int position);
void coursesInterface(struct student *students,int decision,int position);
void viewCourses(struct student *students,struct courses *tables,int position,int option);
void chooseCourses(struct student *students,struct courses *tables,int position);
void editStudentCourses(struct courses *tables,struct student *students);
void deleteCourses(struct courses *tables);
void defineCourses(struct courses *tables);
void saveCourses(struct courses *tables);
void loadCourses(struct courses *tables);
int getCourseChoice(int choice);
void loadCourseMenu(int *num,char *menu);

#endif // __COURSES_HEADER_
