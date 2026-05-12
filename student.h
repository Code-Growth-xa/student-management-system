#ifndef STUDENT_H
#define STUDENT_H
//学生结构体定义:学生姓名、学号、学院、年级、班级
typedef struct Student{
    char StudentName[25];
    char StudentID[20];
    char StudentCollege[12];
    float StudentScore;
    char StudentClass[10];
    struct Student*next;
}Student;
//函数声明
Student *CreateNode(const char *StudentName,const char *StudentID,char *StudentCollege,float StudentScore,char *StudentClass);
void FreeNode(Student *head)
int StudentMenu(void);
void AddStudent(Student *head,const char *StudentName,const char *StudentID,const char *StudentCollege,float StudentScore,char *StudentClass);
void DeleteStudent(Student *head,const char *StudentName,const char *StudentID);
void ModifyStudent(Student *head,const char *StudentName,const char *StudentID,const char *StudentCollege,float StudentScore,char *StudentClass);
void SearchStudent(Student *head,const char *StudentID);
void DisplayAllStudents(Student *head);
void SortStudentsByScore(Student *head);
void Statistics(Student *head);
void SaveToFile(Student *head);
void LoadFromFile(Student *head);
void ExitProgram(Student *head);
#endif //STUDENT_H