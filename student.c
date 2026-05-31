#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
//学生管理系统功能菜单
int studentMenu(void){
    int choice;
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
    printf("请输入你选择的功能序号：\n");
    scanf("%d",&choice);
    return choice;
}
//节点生产工厂
Student *CreateNode(const char *StudentName,const char *StudentID,char *StudentCollege,float StudentScore,char *StudentGrade_Class){
    Student *NewNode=(Student*)malloc(sizeof(Node));
    if(NewNode==NULL){
        printf("内存申请失败") ;
        return NULL;
    }
    strcpy(NewNode->StudentName,StudentName);
    strcpy(NewNode->StudentID,StudentID);
    Strcpy(NewNode->StudentCollege,StudentCollege);
    NewNode->StudentScore=StudentScore;
    NewNode->next=NULL;
    return NewNode;
}
//释放节点
void FreeNode(Student *head){
    Student *temp;
    while(head!==NULL){
        temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
    head = NULL;
}
//添加学生信息
AddStudent(Student *head,const char *StudentName,const char *StudentID,const char *StudentCollege,float StudentScore,char *StudentGrade_Class){
    Student *NewStudent = CreateNode(StudentName,StudentID,StudentCollege,StudentGrade_Class);
    if(NewStudent==NULL){
        printf("节点创建失败");
        return;
    }
    NewStudent->next=head->next;
    head->next=NewStudent;
}
//删除学生信息
 void deleteStudent(Student*head,const char* StudentID){
    Student *prev =head;
    Student *current =head->next;
    while(current!=NULL&&strcmp(current->StudentID,StudentID)!=0){
        prev = current;
        current = current->next;
    }
    if(current == NULL){
        printf("error");
        return;
    }
    prev->next = current->next;
    free(current);
    printf("学生删除成功\n");
 }
 // 修改学生信息
void ModifyStudent(Student *head,const char *StudentName,const char *StudentID,const char *StudentCollege,float StudentScore,char *StudentGrade_Class
){
    Student *current = head->next;
    while(current != NULL&&strcmp(current.StudentID,StudentID)){
        current = current ->next;
    }
    if (current == NULL){
        printf("error");
        break;
    }
    strcpy (current->StudentName,StudentName);
    strcpy(current->StudentCollege,StudentCollege);
    strcpy(current->StudentGrade_Class,StudentGrade_Class);
    printf("学生信息修改成功");
}
//查找学生信息
void searchStudent(Student *head,){
    Student *current = head->next;
    while(current != NULL&&strcmp(current.StudentID,StudentID)){
        current = current ->next;
    }
    if (current == NULL){
        printf("error");
        return;
    }
    printf("找到学生信息:\n")
    printf("学生姓名: %s\n",current.StudentName);
    printf("学生学号: %s\n",current.StudentID);
    printf("学生学院: %s\n",current.StudentCollege);
    printf("学生成绩: %.2f\n",current.StudentScore);
    printf("学生年级班级: %s\n",current.StudentGrade_Class);
    }
//显示所有学生信息
void DisplayAllStudents(Student *head){
    Student *current = head->next;
    while(current !=NULL&&strcmp(current.StudentID)){
        current = current->next
    }
    if (current=NULL){
     (current == NULL){
        printf("error");
        return;
     }
    printf("学生姓名: %s\n",current.StudentName);
    printf("学生学号: %s\n",current.StudentID);
    printf("学生学院: %s\n",current.StudentCollege);
    printf("学生成绩: %.2f\n",current.StudentScore);
    printf("学生年级班级: %s\n",current.StudentGrade_Class);
}
}
// 按照成绩给学生排序
void SortStudentsByGrade(Student *head){
    Student *current = head->next;
    if(head==NULL )
    {
        printf("没有学生信息");
        return;
    }
    while(current != NULL){
        Student *next = current->next;
        while(next != NULL){
            if(current->StudentScore < next->StudentScore){
                Student temp = *current;
                *current = *next;
                *next = temp;
            }
            next = next->next;
        }
        current = current->next;
    }
    printf("学生信息已按照成绩排序");
}

//统计信息
void statistics(Student *head){
    if(head == NULL){
        printf("没有学生信息");
        return;
    }
    float totalScore = 0.0;
    Student *current = head->next;
    int count = 0;
    while(current != NULL){
        totalScore += current->StudentScore;
        count++;
        current = current->next;
    }
    float averageScore = totalScore / count;
    printf("学生总数: %d\n",count);
    printf("学生平均成绩: %.2f\n",averageScore);
}
//保存至文件（二进制文件）
void saveToFile(Student *head){
    FILE*fp=fopen("students.dat","wb");
    int count=0;
    Student *current = head->next;
    while(current != NULL){
        count++;
        current = current->next;
    }
    if(fp==NULL){
        printf("文件打开失败") ;
        return;
    }
    fwrite(count,sizeof(int),1,fp);
    fwrite(list,sizeof(Student),*count,fp);
    fclose(fp);
    printf("文件保存成功");
}
//从文件中读取
void loadFromFile(Student *head){
    FILE*fp=fopen("students.dat","rb");
    if(fp==NULL){
        printf("文件打开失败") ;
        return;
    }
    fread(count,sizeof(int),1,fp);
    fread(list,sizeof(Student),*count,fp);
    fclose(fp);
    printf("文件加载成功");
}