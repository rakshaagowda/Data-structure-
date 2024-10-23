#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int reg_no;
    float marks[3];
    float average_marks;
} Student;

// Function prototypes
void read_students(Student *students, int n);
void display_students(const Student *students, int n);
void calculate_average(Student *students, int n);
float calculate_best_two(float marks[]);

int main() {
    int n, choice;
    Student *students = NULL;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for students using calloc
    students = (Student *)calloc(n, sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // For loop to act as a menu-driven program
    for (;;) {
        printf("\nMenu:\n");
        printf("1. Read information of students\n");
        printf("2. Display students' information\n");
        printf("3. Calculate average of best two test marks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                read_students(students, n);
                break;
            case 2:
                display_students(students, n);
                break;
            case 3:
                calculate_average(students, n);
                break;
            case 4:
                printf("Exiting...\n");
                free(students);  // Free dynamically allocated memory before exiting
                return 0;  // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Function to read students' information
void read_students(Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details of student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Registration Number: ");
        scanf("%d", &students[i].reg_no);
        printf("Enter marks for 3 tests:\n");
        for (int j = 0; j < 3; j++) {
            printf("Test %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
        }
    }
}

// Function to display students' information
void display_students(const Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nDetails of student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Registration Number: %d\n", students[i].reg_no);
        printf("Marks: %.2f, %.2f, %.2f\n", students[i].marks[0], students[i].marks[1], students[i].marks[2]);
        printf("Average of best two marks: %.2f\n", students[i].average_marks);
    }
}

// Function to calculate the average of the best two marks for each student
void calculate_average(Student *students, int n) {
    for (int i = 0; i < n; i++) {
        students[i].average_marks = calculate_best_two(students[i].marks);
    }
    printf("Averages calculated successfully!\n");
}

// Helper function to calculate the average of the best two out of three marks
float calculate_best_two(float marks[]) {
    float min = marks[0];
    float sum = marks[0] + marks[1] + marks[2];

    // Find the minimum mark
    if (marks[1] < min) min = marks[1];
    if (marks[2] < min) min = marks[2];

    // Calculate the average of the best two marks
    return (sum - min) / 2;
}