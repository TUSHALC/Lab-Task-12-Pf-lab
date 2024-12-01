#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} ResizableArray;

ResizableArray* createResizableArray() {
    ResizableArray* arr = (ResizableArray*)malloc(sizeof(ResizableArray));
    if (!arr) {
        printf("Memory allocation failed for ResizableArray.\n");
        exit(1);
    }
    arr->capacity = 2;
    arr->size = 0;
    arr->data = (int*)malloc(arr->capacity * sizeof(int));
    if (!arr->data) {
        printf("Memory allocation failed for array data.\n");
        free(arr);
        exit(1);
    }
    return arr;
}

void resizeArray(ResizableArray* arr) {
    arr->capacity *= 2;
    arr->data = (int*)realloc(arr->data, arr->capacity * sizeof(int));
    if (!arr->data) {
        printf("Memory reallocation failed.\n");
        exit(1);
    }
}

void insertAt(ResizableArray* arr, int index, int value) {
    int i;
    if (index < 0 || index > arr->size) {
        printf("Index out of bounds.\n");
        return;
    }
    if (arr->size == arr->capacity) {
        resizeArray(arr);
    }
    for (i = arr->size; i > index; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[index] = value;
    arr->size++;
}

void deleteAt(ResizableArray* arr, int index) {
    int i;
    if (index < 0 || index >= arr->size) {
        printf("Index out of bounds.\n");
        return;
    }
    for (i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

void printArray(ResizableArray* arr) {
    int i;
    if (arr->size == 0) {
        printf("Array is empty.\n");
        return;
    }
    for (i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void freeResizableArray(ResizableArray* arr) {
    free(arr->data);
    free(arr);
}

int main() {
    ResizableArray* array = createResizableArray();

    insertAt(array, 0, 100);
    insertAt(array, 1, 60);
    insertAt(array, 1, 80);

    printf("Array after insertions: ");
    printArray(array);

    deleteAt(array, 1);

    printf("Array after deletion: ");
    printArray(array);

    freeResizableArray(array);

    return 0;
}

