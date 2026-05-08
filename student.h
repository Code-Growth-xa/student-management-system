#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100
#define NAME_LENGTH 25
#define STUDENT_ID_LENGTH 11
#define COLLEGE_NAME_LENGTH 30

typedef struct Student{
    char name[NAME_LENGTH];
    char StudentID[STUDENT_ID_LENGTH];
    char StudentCollege[COLLEGE_NAME_LENGTH];
    int StudentGrade;
    int StudentClass;
}Student;

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