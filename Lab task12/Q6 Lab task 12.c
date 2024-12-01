#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
    int totalNumbers;
    printf("Enter the total number of entries (1 to 100): ");
    scanf("%d", &totalNumbers);
    if (totalNumbers < 1 || totalNumbers > 100) {
        printf("Invalid number of entries. Please enter a value between 1 and 100.\n");
        return 1;
    }
    int *numArray = (int*)calloc(totalNumbers, sizeof(int));
    if (numArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (i = 0; i < totalNumbers; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &numArray[i]);
    }
    int largestValue = numArray[0];
    for (i = 1; i < totalNumbers; i++) {
        if (numArray[i] > largestValue) {
            largestValue = numArray[i];
        }
    }
    printf("The largest value is: %d\n", largestValue);
    free(numArray);
    return 0;
}

