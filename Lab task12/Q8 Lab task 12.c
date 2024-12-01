#include <stdio.h>
#include <stdlib.h>

void gatherAmounts(int numItems, double *amounts) {
	int i;
    for (i = 0; i < numItems; i++) {
        double amount;
        printf("Enter the amount for item %d: ", i + 1);
        scanf("%lf", &amount);
        while (amount < 0) {
            printf("Error: Amount cannot be negative. Please enter a valid amount for item %d: ", i + 1);
            scanf("%lf", &amount);
        }
        amounts[i] = amount;
    }
}
double calculateRevenue(int numItems, double *amounts) {
	int i;
    double totalRevenue = 0.0;
    for (i = 0; i < numItems; i++) {
        totalRevenue += amounts[i];
    }
    return totalRevenue;
}
int main() {
    int numItems;
    printf("Enter the total number of items: ");
    scanf("%d", &numItems);
    while (numItems <= 0) {
        printf("Error: Number of items must be positive. Please enter again: ");
        scanf("%d", &numItems);
    }

    double *amounts = (double *)malloc(numItems * sizeof(double));
    gatherAmounts(numItems, amounts);
    double totalRevenue = calculateRevenue(numItems, amounts);
    printf("Total revenue generated: %.2f\n", totalRevenue);
    free(amounts);
    return 0;
}

