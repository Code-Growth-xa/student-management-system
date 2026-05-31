#include<stdio.h>
#include"student.h"
int main(){
    int choice;
        choice=StudentMenu(void);
    Student *head=(Student*)malloc(sizeof(Student));
    head->next=NULL;
    while(choice!=10){
        switch(choice){
            case 1:
                AddStudent(head);
                break;  
            case 2:
                DeleteStudent(head);
                break;
            case 3:
                ModifyStudent(head);
                break;
            case 4: 
                SearchStudent(head);
                break;
            case 5:
                DisplayAllStudents(head);
                break;
            case 6:
                SortStudentsByGrade(head);
                break;  
            case 7:
                Statistics(head);
                break;
            case 8:
                SaveToFile(head);
                break;
            case 9:
                LoadFromFile(head); 
                break;
            default:
                printf("无效的选择，请重新输入");
                break;  
}
    }
}