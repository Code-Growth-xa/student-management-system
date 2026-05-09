#ifndef STUDENT_H
#define STUDENT_H
//宏定义：最大学生数量、姓名长度、学号长度、学院名称长度
#define MAX_STUDENTS 100
#define NAME_LENGTH 25
#define STUDENT_ID_LENGTH 11
#define COLLEGE_NAME_LENGTH 30
//学生结构体定义:学生姓名、学号、学院、年级、班级
typedef struct Student{
    char name[NAME_LENGTH];
    char StudentID[STUDENT_ID_LENGTH];
    char StudentCollege[COLLEGE_NAME_LENGTH];
    int StudentGrade;
    int StudentClass;
}Student;
//函数声明
void studentMenu(void);
void addStudent(Student list[MAX_STUDENTS],int *count);
void deleteStudent(Student list[MAX_STUDENTS],int *count);
void modifyStudent(Student list[MAX_STUDENTS],int *count);
void searchStudent(Student list[MAX_STUDENTS],int *count);
void displayallSTUDENT(Student list[MAX_STUDENTS],int *count);
void sortStudentsByGrade(Student list[MAX_STUDENTS],int *count);
void statistics(Student list[MAX_STUDENTS],int *count);
void saveToFile(Student list[MAX_STUDENTS],int *count);
void loadFromFile(Student list[MAX_STUDENTS],int *count);
void exitProgram(void);

#endif STUDENT_H