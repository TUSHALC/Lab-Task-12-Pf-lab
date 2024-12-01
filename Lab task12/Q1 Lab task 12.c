#include <stdio.h>
#include <stdlib.h>

int main() {
    int numStudents;
    int student,grade;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    int** grades = (int**)malloc(numStudents * sizeof(int*));
    int* gradeCounts = (int*)malloc(numStudents * sizeof(int));

    if (grades == NULL || gradeCounts == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (student = 0; student < numStudents; student++) {
        printf("Enter the number of grades for Student %d: ", student + 1);
        scanf("%d", &gradeCounts[student]);

        grades[student] = (int*)malloc(gradeCounts[student] * sizeof(int));
        if (grades[student] == NULL) {
            printf("Memory allocation for grades of Student %d failed.\n", student + 1);
            return 1;
        }
    
        printf("Enter grades for Student %d:\n", student + 1);
        for (grade = 0; grade < gradeCounts[student]; grade++) {
            printf("Grade %d: ", grade + 1);
            scanf("%d", &grades[student][grade]);
        }
    }

    printf("\nEntered Grades:\n");
    for (student = 0; student < numStudents; student++) {
        printf("Student %d Grades: ", student + 1);
        for (grade = 0; grade < gradeCounts[student]; grade++) {
            printf("%d ", grades[student][grade]);
        }
        printf("\n");
    }

    for (student = 0; student < numStudents; student++) {
        free(grades[student]);
    }
    free(grades);
    free(gradeCounts);
    return 0;
}

