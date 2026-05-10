#include<stdio.h>
#include"student.h"
int main(){
    Student list[MAX_STUDENTS];
    int count=0;
    int choice;
    do{
        choice=studentMenu;
        switch(choice){
            case 1: addStudent(list,&count);
            break;
            case 2:deleteStudent(list,&count);
            break;
            case 3:modifyStudent(list,&count);
            break;
            case 4:searchStudent(list,&count);
            break;
            case 5:displayallSTUDENT(list,&count);
            break;
            case 6:sortStudentsByGrade(list,&count);
            break;
            case 7:statistics(list,&count);
            break;
            case 8:saveToFile(list,&count);
            break;
            case 9:loadFromFile(list,&count);
            break;
            case 10:printf("正在退出系统......") ;
            break;
        }
    }while(choice!=10);
}