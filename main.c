#include<stdio.h>
#include"student.h"
int main(){
    int count=0;
    int choice;
    do{
        choice=studentMenu(void);
        switch(choice){
            case 1: addStudent();
            break;
            case 2:deleteStudent();
            break;
            case 3:modifyStudent();
            break;
            case 4:searchStudent();
            break;
            case 5:displayallSTUDENT();
            break;
            case 6:sortStudentsByGrade();
            break;
            case 7:statistics();
            break;
            case 8:saveToFile();
            break;
            case 9:loadFromFile();
            break;
            case 10:printf("正在退出系统......") ;
            break;
        }
    }while(choice!=10);
}