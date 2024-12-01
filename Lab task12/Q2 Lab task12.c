
#include <stdio.h>
#include <stdlib.h>
int main(){
int* p=(int*)malloc(5*sizeof(int));
int i;
if(p == NULL){
    printf("Memory allocation failed!\n");
    return 1;
    }
    printf("Enter integers:\n");
    for (i = 0; i < 5; i++) {
    scanf("%d", (p + i));
    }
    for (i = 0; i < 5; i++) {
    printf("%d ", p[i]);
    }
    printf("\n");
    for (i = 0; i < 5; i++) {
    if(p[i]%2 !=0){
    p[i]=p[i]-1;
    }
    }
    for (i = 0; i < 5; i++) {
    printf("%d ", p[i]);
    }
return 0;
}

