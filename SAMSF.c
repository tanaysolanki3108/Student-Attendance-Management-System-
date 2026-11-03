#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define MAX_SUB 10

typedef struct
{
    char name[50];
    char branch[20];
    int sem;
    char id[10];
    char mnumber[13];
} student;

typedef struct {
    char student_id[10];
    char subject[20];
    char status; // 'P' or 'A'
} Attendance;

student s[MAX];

void mainMenu();
void subMenu1();
void subMenu2();
void subMenu3();
void clearscreen();
int searchStudent(char a[], int n);
void displayStudent(int i);
void displaySubject(int i, char sub[][20]);
void generateStudentReport();

int main()
{
    int choice, subchoice;  // Menu variables
    int i, count = 0;       // student management variables
    char id[10], sub2;
    int choicesub, count1, n;          // attendance management variables
    char at, sub[MAX_SUB][20];

    do
    {
        mainMenu:
        mainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        system("cls");

        switch(choice)
        {
            case 1:
                do
                {   
                    subMenu1:
                    subMenu1();
                    printf("Enter your choice: ");
                    scanf("%d", &subchoice);
                    switch(subchoice)
                    {
                        case 1:
                        {
                            FILE *fp = fopen("student.dat", "ab");
                            if (fp == NULL)
                                printf("ERROR: CAN'T OPEN FILE\n");
                            else
                            {
                                for (i = 0; i < MAX; i++)
                                {   
                                    int c;
                                    while((c = getchar()) != '\n' && c != EOF);
                                    clearscreen();
                                    printf("\n\n");
                                    printf("Just hit Enter to stop adding details\n");
                                    printf("Enter student's name: ");
                                    if (fgets(s[i].name, sizeof(s[i].name), stdin) == NULL)
                                        break;
                                    s[i].name[strcspn(s[i].name, "\n")] = '\0';
                                    if (s[i].name[0] == '\0')
                                        break;

                                    printf("Enter student's branch: ");
                                    scanf("%19s", s[i].branch);
                                    printf("Enter student's current sem: ");
                                    scanf("%d", &s[i].sem);
                                    printf("Enter student's ID: ");
                                    scanf("%9s", s[i].id);
                                    while (getchar() != '\n');

                                    printf("Enter student's mobile number: ");
                                    if (fgets(s[i].mnumber, sizeof(s[i].mnumber), stdin) != NULL)
                                        s[i].mnumber[strcspn(s[i].mnumber, "\n")] = '\0';

                                    if (fwrite(&s[i], sizeof(student), 1, fp) == 1)
                                        printf("Student saved successfully.\n");
                                    else
                                        printf("ERROR: FAILED TO SAVE\n");

                                    clearscreen();
                                }
                                fclose(fp);
                            }
                            break;
                        }
                        case 2:
                        {
                            FILE *fp = fopen("student.dat", "rb");
                            if (fp == NULL)
                                printf("ERROR: FILE DOESN'T EXIST\n");
                            else    
                            {
                                count = fread(s, sizeof(student), MAX, fp);
                                fclose(fp);

                                for (i = 0; i < count; i++)
                                    displayStudent(i);
                            }
                            printf("Press 'e' to exit\n");
                            sub2:
                            scanf(" %c", &sub2);
                            if (sub2 == 'e')
                            {
                                clearscreen();
                                break;
                            }
                            else
                            {
                                printf("please press 'e'\n");
                                goto sub2;
                            }
                        }
                        case 3:
                            printf("Enter ID of student: ");
                            scanf("%9s", id);
                            i = searchStudent(id, count);

                            if (i != count)
                                displayStudent(i);
                            else
                                printf("ERROR: STUDENT DOESN'T EXIST\n");
                            printf("Press 'e' to exit\n");
                            sub3:
                            scanf(" %c", &sub2);
                            if (sub2 == 'e')
                            {
                                clearscreen();
                                break;
                            }
                            else
                            {
                                printf("please press 'e'\n");
                                goto sub3;
                            }    
                            clearscreen();
                            break;
                        case 4:
                            printf("Returning to Main Menu...\n");
                            clearscreen();
                            goto mainMenu;
                            break;
                        default:
                            printf("Invalid choice! Please try again.\n");
                            break;
                    }
                } 
                while(subchoice != 4);
                break;

            case 2:
                do
                {   
                    subMenu2:
                    subMenu2();
                    printf("Enter your choice: ");
                    scanf("%d", &subchoice);
                    system("cls");
                    switch(subchoice)
                    {
                        case 1:
                        {
                            FILE *fp1 = fopen("subject.dat", "ab");
                            if (fp1 == NULL)
                                printf("ERROR: CAN'T OPEN FILE\n");
                            else
                            {
                                printf("Enter no. of subjects you want to enroll: ");
                                scanf("%d", &n);
                                int c;
                                while((c = getchar()) != '\n' && c != EOF);
                                for (i = 0; i < n && i < MAX_SUB; i++)
                                {
                                    printf("Enter subject name: ");
                                    if (fgets(sub[i], sizeof(sub[i]), stdin) != NULL)
                                        sub[i][strcspn(sub[i], "\n")] = '\0';

                                    if (fwrite(sub[i], sizeof(sub[i]), 1, fp1) == 1)
                                        printf("Subject saved successfully.\n");
                                    else
                                        printf("ERROR: FAILED TO SAVE\n");
                                }
                                fclose(fp1);
                            }
                            break;
                        }
                        case 2:
                        {
                            count1 = 0;
                            FILE *fp1 = fopen("subject.dat", "rb");
                            if (fp1 == NULL)
                                printf("ERROR: FILE DOESN'T EXIST\n");
                            else    
                            {
                                while (count1 < MAX_SUB && fread(sub[count1], sizeof(sub[count1]), 1, fp1) == 1)
                                {
                                    count1++;
                                }
                                fclose(fp1);

                                for (i = 0; i < count1; i++)
                                    displaySubject(i, sub);
                            }

                            FILE *fp = fopen("student.dat", "rb");
                            if (fp == NULL)
                                printf("ERROR: FILE DOESN'T EXIST\n");
                            else    
                            {
                                count = fread(s, sizeof(student), MAX, fp);
                                fclose(fp);
                            }

                            if (count > 0 && count1 > 0)
                            {
                                FILE *fp2 = fopen("attendance.dat", "ab");
                                if (fp2 == NULL)
                                    printf("ERROR: CAN'T OPEN FILE\n");
                                else
                                {
                                    printf("Choose from given subjects (1 - %d): ", count1);
                                    scanf("%d", &choicesub);

                                    if (choicesub >= 1 && choicesub <= count1)
                                    {
                                        printf("\nRecording attendance for: %s\n", sub[choicesub - 1]);
                                        for (i = 0; i < count; i++)
                                        {
                                            Attendance att;
                                            strcpy(att.student_id, s[i].id);
                                            strcpy(att.subject, sub[choicesub - 1]);

                                            printf("Student ID: %s (%s) - P / A : ", s[i].id, s[i].name);
                                            scanf(" %c", &at);
                                            att.status = at;

                                            if (fwrite(&att, sizeof(Attendance), 1, fp2) == 1)
                                                printf("Attendance saved successfully.\n");
                                            else
                                                printf("ERROR: FAILED TO SAVE\n");
                                        }
                                    }
                                    else
                                    {
                                        printf("Invalid subject choice!\n");
                                    }
                                    fclose(fp2);
                                }
                            }
                            else
                            {
                                printf("No students or subjects found to record attendance.\n");
                            }
                            break;
                        }
                        case 3:
                            printf("Returning to Main Menu...\n");
                            goto mainMenu;
                            break;
                        default:
                            printf("Invalid choice! Please try again.\n");
                            break;
                    }
                } 
                while(subchoice != 3);
                break;

            case 3:
                do
                {   
                    subMenu3:
                    subMenu3(); 
                    printf("Enter your choice: ");
                    scanf("%d", &subchoice);
                    system("cls");
                    switch(subchoice)
                    {
                        case 1:
                            generateStudentReport();
                            printf("Press 'e' to exit\n");
                            sub4:
                            scanf(" %c", &sub2);
                            if (sub2 == 'e')
                            {
                                clearscreen();
                                break;
                            }
                            else
                            {
                                printf("please press 'e'\n");
                                goto sub4;
                            }
                        case 2:
                            printf("Returning to Main Menu...\n");
                            goto mainMenu;
                            break;
                        default:
                            printf("Invalid choice! Please try again.\n");
                            break;
                    }
                } 
                while(subchoice != 2);
                break;

            case 4:
                printf("Exiting program. Thank you!\n");
                break;

            default:
                printf("Invalid choice! Please enter a choice between 1 and 4.\n");
                break;
        }
    } 
    while(choice != 4);

    return 0;
}

void mainMenu()
{
    printf("================================\n");
    printf(" STUDENT ATTENDANCE MANAGEMENT  \n");
    printf("================================\n");
    printf("\n");
    printf("1. Student Management\n");
    printf("2. Attendance Management\n");
    printf("3. Reports\n");
    printf("4. Exit\n");
    printf("\n");
}

void subMenu1()
{
    printf("===== STUDENT MANAGEMENT =====\n");
    printf("\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Search Student\n");
    printf("4. Back to main menu\n");
    printf("\n");
}

void subMenu2()
{
    printf("===== ATTENDANCE MANAGEMENT =====\n");
    printf("\n");
    printf("1. Add subjects\n");
    printf("2. Record attendance\n");
    printf("3. Back to Main Menu\n");
    printf("\n");
}

void subMenu3()
{
    printf("===== REPORTS =====\n");
    printf("\n");
    printf("1. View Student Attendance Report\n");
    printf("2. Back to Main Menu\n");
    printf("\n");
}

void clearscreen()
{
    system("cls");
}

int searchStudent(char a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (strcmp(a, s[i].id) == 0)
            return i;
    return n;   // not found
}

void displayStudent(int i)
{
    printf("student %d\n", i + 1);
    printf("name : %s\n", s[i].name);
    printf("branch : %s\n", s[i].branch);
    printf("sem : %d\n", s[i].sem);
    printf("ID : %s\n", s[i].id);
    printf("mobile number : %s\n", s[i].mnumber);
}

void displaySubject(int i, char sub[][20])
{
    printf("%d. subject : %s\n", i + 1, sub[i]);
}

void generateStudentReport()
{
    char search_id[10];
    printf("Enter Student ID for report: ");
    scanf("%9s", search_id);

    // 1. Read student list to verify student existence
    FILE *fp_stud = fopen("student.dat", "rb");
    if (fp_stud == NULL)
    {
        printf("ERROR: Student database does not exist.\n");
        return;
    }

    student temp_stud;
    int found = 0;
    while (fread(&temp_stud, sizeof(student), 1, fp_stud) == 1)
    {
        if (strcmp(temp_stud.id, search_id) == 0)
        {
            found = 1;
            break;
        }
    }
    fclose(fp_stud);

    if (!found)
    {
        printf("ERROR: Student with ID '%s' not found.\n", search_id);
        return;
    }

    // 2. Read all available subjects
    char subjects[MAX_SUB][20];
    int sub_count = 0;
    FILE *fp_sub = fopen("subject.dat", "rb");
    if (fp_sub != NULL)
    {
        while (sub_count < MAX_SUB && fread(subjects[sub_count], sizeof(subjects[sub_count]), 1, fp_sub) == 1)
        {
            sub_count++;
        }
        fclose(fp_sub);
    }

    if (sub_count == 0)
    {
        printf("No enrolled subjects found in database.\n");
        return;
    }

    // Display Student Profile Summary
    printf("\n========================================\n");
    printf("        STUDENT ATTENDANCE REPORT       \n");
    printf("========================================\n");
    printf(" Name          : %s\n", temp_stud.name);
    printf(" ID            : %s\n", temp_stud.id);
    printf(" Branch        : %s\n", temp_stud.branch);
    printf(" Semester      : %d\n", temp_stud.sem);
    printf(" Mobile Number : %s\n", temp_stud.mnumber);
    printf("----------------------------------------\n");
    printf("%-20s | %-6s | %-6s | %-8s\n", "Subject", "Total", "Attnd", "Percentage");
    printf("----------------------------------------\n");

    int overall_total = 0;
    int overall_present = 0;

    // 3. Calculate Subject-wise Attendance statistics
    for (int k = 0; k < sub_count; k++)
    {
        FILE *fp_att = fopen("attendance.dat", "rb");
        int total_sessions = 0;
        int present_count = 0;

        if (fp_att != NULL)
        {
            Attendance att_rec;
            while (fread(&att_rec, sizeof(Attendance), 1, fp_att) == 1)
            {
                if (strcmp(att_rec.student_id, search_id) == 0 && strcmp(att_rec.subject, subjects[k]) == 0)
                {
                    total_sessions++;
                    if (att_rec.status == 'P' || att_rec.status == 'p')
                    {
                        present_count++;
                    }
                }
            }
            fclose(fp_att);
        }

        float percentage = (total_sessions > 0) ? ((float)present_count / total_sessions) * 100.0f : 0.0f;
        printf("%-20s | %-6d | %-6d | %-7.2f%%\n", subjects[k], total_sessions, present_count, percentage);

        overall_total += total_sessions;
        overall_present += present_count;
    }

    float overall_percentage = (overall_total > 0) ? ((float)overall_present / overall_total) * 100.0f : 0.0f;
    printf("----------------------------------------\n");
    printf("%-20s | %-6d | %-6d | %-7.2f%%\n", "OVERALL SUMMARY", overall_total, overall_present, overall_percentage);
    printf("========================================\n\n");
}
    