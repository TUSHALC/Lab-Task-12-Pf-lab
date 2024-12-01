#include <stdio.h>
#include <stdlib.h>

int main() {
	int t,i;
    int testCases;
    printf("Enter the number of test cases: ");
    scanf("%d", &testCases);

    for (t = 0; t < testCases; t++) {
        int numElements; 
        printf("Enter the number of elements for test case %d: ", t + 1);
        scanf("%d", &numElements);

        int *elements = (int *)malloc(numElements * sizeof(int));
        if (elements == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter the elements: ");
        for (i = 0; i < numElements; i++) {
            scanf("%d", &elements[i]);
        }

        int *frequency = (int *)calloc(numElements, sizeof(int));
        if (frequency == NULL) {
            printf("Memory allocation failed!\n");
            free(elements);
            return 1;
        }
         int j;
        for (i = 0; i < numElements; i++) {
            for (j = 0; j < numElements; j++) {
                if (elements[i] == elements[j]) {
                    frequency[i]++;
                }
            }
        }

        int maxFrequency = 0;
        int mostFrequentElement = elements[0];
        for (i = 0; i < numElements; i++) {
            if (frequency[i] > maxFrequency) {
                maxFrequency = frequency[i];
                mostFrequentElement = elements[i];
            } else if (frequency[i] == maxFrequency && elements[i] < mostFrequentElement) {
                mostFrequentElement = elements[i];
            }
        }

        printf("Most frequent element for test case %d: %d\n", t + 1, mostFrequentElement);

        free(elements);
        free(frequency);
    }

    return 0;
}

