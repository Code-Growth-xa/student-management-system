#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
//学生管理系统功能菜单
void studentMenu(void){
    printf("西安理工大学 学生管理系统\n");
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
void searchStudent(Student list[MAX_STUDENTS],int *count){
    char id[STUDENT_ID_LENGTH];
    printf("请输入要查找的学生学号");
    scanf("%s",id);
    for(int i=0;i<*count;i++){
        if(strcmp(id,list[i].StudentID)==0){
            printf("学生姓名: %s\n",list[i].name);
            printf("学生学号: %s\n",list[i].StudentID);
            printf("学生学院: %s\n",list[i].StudentCollege);
            printf("学生年级: %d\n",list[i].StudentGrade);
            printf("学生班级: %d\n",list[i].StudentClass);
            break;}
        }
    }
//显示所有学生信息
void displayallSTUDENT(Student list[MAX_STUDENTS],int *count){
    for(int i=0;i<*count;i++){
        printf("学生姓名: %s\n",list[i].name);
        printf("学生学号: %s\n",list[i].StudentID);
        printf("学生学院: %s\n",list[i].StudentCollege);
        printf("学生年级: %d\n",list[i].StudentGrade);
        printf("学生班级: %d\n",list[i].StudentClass);
    }
}
// 按照成绩给学生排序
void sortStudentByGrade(Student list[MAX_STUDENTS],int *count){
    for(int i =0;i<*count-1;i++){
        for(int j=0;j<*count-i-1;j++){
            if(list[j].Grade<list[j+1].Grade){
                Student temp=list[j].Grade;
                list[j].Grade=list[j+1].Grade;
                list[j+1].Grade=temp;
            }
        }
    }
}
//统计信息
void statistics(Student list[MAX_STUDENTS],int *count){
    int The_highest_Grade=0;
    int The_minimum_Grade=0;
    float Average_Grade=0;
    int sum=0;
    if(*count==0){
        printf("还没有添加任何学生");
    }else{
    for(int i=0;i<*count-1;i++){
        for(int j=0;j<*count-1-i;j++){
            if(list[j].Grade<list[j+1].Grade){
                Student temp=list[j];
                list[j]=list[j+1];
                list[j+1]= temp;
            }
        }
    }
    int The_highest_Grade=list[0].Grade;
    printf("最高成绩是%d\n",The_highest_Grade);
    int The_minimum_Grade=list[*count-1].Grade;
    printf("最低成绩是%d\n",The_minimum_Grade);
    for(int i =0;i<*count;i++){
        sum +=list[i].Grade;
    }
    float Average_Grade = (float)sum/ *count;
    printf("平均成绩是：%.2f\n",Average_Grade);}
}
//保存至文件（二进制文件）
void saveToFile(Student list[MAX_STUDENTS],int *count){
    FILE *fp=fopen("Students.dat","wb");
    if(fp==NULL){
        printf("打开文件失败");
        return;
    }
    fwrite(count,sizeof(int),1,fp);
    fwrite(list,sizeof(Student),*count,fp);
    fclose(fp);
    printf("数据保存成功");
}
//从文件中读取
void loadFromFile(Student list[MAX_STUDENTS],int *count){
    FILE*fp=fopen("Students.dat","rb");
    if(fp==NULL){
        printf("文件打开失败") ;
        return;
    }
    fread(count,sizeof(int),1,fp);
    fread(list,sizeof(Student),*count,fp);
    fclose(fp);
    printf("文件读取成功");
}