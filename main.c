#include<stdio.h>
#include<stdlib.h>
#include"student.h"
int main(){
    system("chcp 65001 >nul");
    int choice;
    Student *head=(Student*)malloc(sizeof(Student));
    head->next=NULL;
    while(choice!=10){
        choice=StudentMenu();
        switch(choice){
            case 1:{
        char StudentName[25];
        char StudentID[20];
        char StudentCollege[12];
        float StudentScore;
        char StudentGrade_Class[10];
        printf("请输入学生姓名：");
        scanf("%s",StudentName);
        printf("请输入学生学号：");
        scanf("%s",StudentID);
        printf("请输入学生学院：");
        scanf("%s",StudentCollege);
        printf("请输入学生成绩：");
        scanf("%f",&StudentScore);
        printf("请输入学生年级班级：");
        scanf("%s",StudentGrade_Class);
                AddStudent(head,StudentName,StudentID,StudentCollege,StudentScore,StudentGrade_Class);
                break;  }
            case 2:
            char StudentID[20];{
                printf("请输入要删除的学生学号：");
                scanf("%s",StudentID);
                DeleteStudent(head,StudentID);
                break;}
            case 3:{
                char StudentName[25];
                char StudentID[20];
                char StudentCollege[12];
                float StudentScore;
                char StudentGrade_Class[10];    
                printf("请输入要修改的学生学号：");
                scanf("%s",StudentID);
                printf("请输入学生姓名：");
                scanf("%s",StudentName);
                printf("请输入学生学院：");
                scanf("%s",StudentCollege);
                printf("请输入学生成绩：");
                scanf("%f",&StudentScore);
                printf("请输入学生年级班级：");
                scanf("%s",StudentGrade_Class);
                ModifyStudent(head,StudentName,StudentID,StudentCollege,StudentScore,StudentGrade_Class);
                break;}
            case 4: {
                char StudentID[20];
                printf("请输入要查找的学生学号：");
                scanf("%s",StudentID);
                SearchStudent(head,StudentID);
                break;}
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