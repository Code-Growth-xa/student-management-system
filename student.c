#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
//学生管理系统功能菜单
void studentMenu(void){
    printf("学生管理系统\n");
    printf("1. 添加学生\n");
    printf("2. 删除学生\n");
    printf("3. 修改学生信息\n");
    printf("4. 查找学生\n");
    printf("5. 显示所有学生\n");
    printf("6. 按成绩排序学生\n");
    printf("7. 统计信息\n");
    printf("8. 保存到文件\n");
    printf("9. 从文件加载\n");
    printf("10. 退出\n");
}
//添加学生信息
void addStudent(Student list[MAX_STUDENTS],int *count){
    if (*count>=MAX_STUDENTS){
        printf("学生数量已达上限，无法添加更多学生。\n");
        return;
    }
    Student newStudent;
    printf ("请输入学生姓名: ");
    scanf("%s", newStudent.name);
    printf ("请输入学生学号: ");
    scanf("%s", newStudent.StudentID);
    printf ("请输入学生学院: ");
    scanf("%s", newStudent.StudentCollege);
    printf ("请输入学生年级: ");
    scanf("%d", &newStudent.StudentGrade);
    printf ("请输入学生班级: ");
    scanf("%d", &newStudent.StudentClass);
    list[*count] = newStudent;
    *count ++;
}
//删除学生信息
 void deleteStudent(Student list[MAX_STUDENTS],int *count){
    char id[STUDENT_ID_LENGTH];
    printf("请输入要删除的学生学号");
    scanf("%s",id);
    int delete=0;
    for(int i=0;i<*count;i++){
        if(strcmp(id,list[i].StudentID)==0){
            int delet=i;
            break;
        }
    }
    for(int i=delete;i<=*count;i++){
        list[i]=list[i+1];
    }
    *count--;
    printf("学生删除成功\n");
 }
 // 修改学生信息
void modifyStudent(Student list[MAX_STUDENTS],int *count){
    char id [STUDENT_ID_LENGTH];
    printf("请输入要修改的学生学号");
    scanf("%s",id);
    char newID[STUDENT_ID_LENGTH];
    printf(" 请输入新的学号\n");
    scanf("%s",newID);
    for(int i=0;i<*count;i++){
        if(strcmp(id,list[i].StudentID)==0){
            strcpy(list[i].StudentID,newID);
            break;
        }
        printf("修改学号成功\n");
}
//查找学生信息
