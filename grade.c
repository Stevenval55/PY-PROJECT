#include <stdio.h>

int main() {
    int marks;
    
    // Prompt user for input
    printf("Enter the total marks obtained: ");
    scanf("%d", &marks);
    
    // Check and display the corresponding letter grade
    if (marks >= 80 && marks <= 100) {
        printf("Grade: A\n");
    } else if (marks >= 70 && marks <= 79) {
        printf("Grade: B\n");
    } else if (marks >= 60 && marks <= 69) {
        printf("Grade: C\n");
    } else if (marks >= 50 && marks <= 59) {
        printf("Grade: D\n");
    } else if (marks >= 0 && marks <= 49) {
        printf("Grade: F\n");
    } else {
        printf("Invalid marks entered. Please enter a value between 0 and 100.\n");
    }
    
    return 0;
}