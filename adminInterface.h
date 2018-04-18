#ifndef __ADMININTERFACE_HEADER_
#define __ADMININTERFACE_HEADER_

struct admin{
    char username[50];
    char name[100];
    char password[50];
    char attribut[100];
};

void adminMenu(int *num);
int getChoiceAdmin(int choice);
void loadAdmin(struct admin *users);
void addAdmin(struct admin *users);
void adminList(struct admin *users);
void adminInterface(struct admin *users,struct student *students,int position);
void DeleteAdmin(struct admin *users,int position);
void saveAdmin(struct admin *users);
int searchAdmin(struct admin *users);
void resetAdmin(struct admin *users,int position);
void editAdmin(struct admin *users,int position);
int variable();
void viewStatus(struct admin *users,struct student *students,int position,int decision);

#endif // __ADMININTERFACE_HEADER_

