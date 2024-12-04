#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PASS_MARK 40
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int roll_number;
    int marks;
} Student;

Student* students = NULL;
int student_count = 0;

// Function prototypes
void greetUser();
void addStudent();
void displayStudents();
void modifyStudent();
void saveToFile();
void loadFromFile();
void searchStudent();
void calculateAverage();
void sortStudents();
int isAlphabetic(const char* str);
int isNumeric(const char* str);

int main() {
    greetUser();
    loadFromFile(); // Load existing records

    int choice;
    do {
        printf("\n1. Add Student\n2. Display Students\n3. Modify Student\n4. Search Student\n");
        printf("5. Save to File\n6. Load from File\n7. Calculate Average\n8. Sort by Marks\n9. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: modifyStudent(); break;
            case 4: searchStudent(); break;
            case 5: saveToFile(); break;
            case 6: loadFromFile(); break;
            case 7: calculateAverage(); break;
            case 8: sortStudents(); break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 9);

    // Free allocated memory
    free(students);
    return 0;
}

void greetUser() {
    char name[MAX_NAME_LENGTH];
    printf("Welcome! Please enter your name: ");
    scanf("%s", name);

    // Validate name to only allow alphabetic characters
    while (!isAlphabetic(name)) {
        printf("Invalid input. Please enter alphabetic characters only: ");
        scanf("%s", name);
    }

    printf("Hello, %s!\n", name);
}

// Function to check if a string contains only alphabetic characters
int isAlphabetic(const char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string contains only numeric characters
int isNumeric(const char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to add a new student
void addStudent() {
    students = realloc(students, (student_count + 1) * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Get and validate student name
    printf("Enter student name: ");
    scanf("%s", students[student_count].name);
    while (!isAlphabetic(students[student_count].name)) {
        printf("Invalid name. Please enter alphabetic characters only: ");
        scanf("%s", students[student_count].name);
    }

    // Get and validate roll number
    char roll_number_str[10];
    printf("Enter roll number: ");
    scanf("%s", roll_number_str);
    while (!isNumeric(roll_number_str)) {
        printf("Invalid roll number. Please enter numeric characters only: ");
        scanf("%s", roll_number_str);
    }
    students[student_count].roll_number = atoi(roll_number_str);

    // Get and validate marks
    char marks_str[10];
    printf("Enter marks: ");
    scanf("%s", marks_str);
    while (!isNumeric(marks_str)) {
        printf("Invalid marks. Please enter numeric characters only: ");
        scanf("%s", marks_str);
    }
    students[student_count].marks = atoi(marks_str);

    printf("Student %s %s.\n", students[student_count].marks >= PASS_MARK ? "Passed" : "Failed");
    student_count++;
}

// Function to display students
void displayStudents() {
    for (int i = 0; i < student_count; i++) {
        printf("Name: %s, Roll No: %d, Marks: %d\n", students[i].name, students[i].roll_number, students[i].marks);
    }
}

// Modify student, search by roll number
void modifyStudent() {
    int roll_no, found = -1;
    printf("Enter roll number to modify: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_number == roll_no) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        char marks_str[10];
        printf("Enter new marks: ");
        scanf("%s", marks_str);
        while (!isNumeric(marks_str)) {
            printf("Invalid marks. Please enter numeric characters only: ");
            scanf("%s", marks_str);
        }
        students[found].marks = atoi(marks_str);
        printf("Marks updated.\n");
    } else {
        printf("Student not found.\n");
    }
}

// Save to file
void saveToFile() {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < student_count; i++) {
        fprintf(file, "%s %d %d\n", students[i].name, students[i].roll_number, students[i].marks);
    }

    fclose(file);
    printf("Data saved.\n");
}

// Load from file
void loadFromFile() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("No data file found.\n");
        return;
    }

    Student temp;
    while (fscanf(file, "%s %d %d", temp.name, &temp.roll_number, &temp.marks) != EOF) {
        students = realloc(students, (student_count + 1) * sizeof(Student));
        if (students == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        students[student_count++] = temp;
    }

    fclose(file);
    printf("Data loaded.\n");
}

// Search for a student by roll number
void searchStudent() {
    int roll_no;
    printf("Enter roll number to search: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_number == roll_no) {
            printf("Found: %s, Marks: %d\n", students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student not found.\n");
}

// Calculate average marks
void calculateAverage() {
    if (student_count == 0) {
        printf("No students.\n");
        return;
    }
    int total_marks = 0;
    for (int i = 0; i < student_count; i++) {
        total_marks += students[i].marks;
    }
    printf("Average marks: %.2f\n", total_marks / (float)student_count);
}

// Sort by marks
void sortStudents() {
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = i + 1; j < student_count; j++) {
            if (students[i].marks > students[j].marks) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Students sorted by marks.\n");
}
