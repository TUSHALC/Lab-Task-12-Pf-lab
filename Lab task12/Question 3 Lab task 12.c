#include <stdio.h>
#include <stdlib.h>

void displayArray(float *numbers, int count) {
	int i;
    if (count == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Current numbers in the array: ");
    for (i = 0; i < count; i++) {
        printf("%.2f ", numbers[i]);
    }
    printf("\n");
}

int main() {
    int maxCapacity = 4; 
    int currentSize = 0; 
    float *numbers = (float *)malloc(maxCapacity * sizeof(float));
    
    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int userChoice; 
    do {
        printf("\nMenu:\n");
        printf("1. Add a new number\n");
        printf("2. Display all numbers\n");
        printf("3. Remove the last number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1: {
                if (currentSize >= maxCapacity) {
                    maxCapacity *= 2;
                    numbers = (float *)realloc(numbers, maxCapacity * sizeof(float));
                    if (numbers == NULL) {
                        printf("Memory reallocation failed!\n");
                        return 1; 
                    }
                }
                printf("Enter a floating-point number: ");
                scanf("%f", &numbers[currentSize]);
                currentSize++;
                break;
            }
            case 2:
                displayArray(numbers, currentSize);
                break;
            case 3: {
                if (currentSize > 0) {
                    currentSize--;
                    printf("Removed the last number. Current size: %d\n", currentSize);
                    
                    if (currentSize <= maxCapacity / 4 && maxCapacity > 4) {
                        maxCapacity /= 2;
                        numbers = (float *)realloc(numbers, maxCapacity * sizeof(float));
                        if (numbers == NULL && currentSize > 0) {
                            printf("Memory reallocation failed!\n");
                            return 1; 
                        }
                    }
                } else {
                    printf("Array is already empty.\n");
                }
                break;
            }
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (userChoice != 4);

    free(numbers);
    return 0;
}

