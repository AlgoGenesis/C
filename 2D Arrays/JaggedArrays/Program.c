#include <stdio.h>
#include <stdlib.h>

void initializeJaggedArray(int **jaggedArray, int rows, int *columnSizes) {
    for (int i = 0; i < rows; i++) {
        printf("Enter the number of columns for row %d: ", i);
        scanf("%d", &columnSizes[i]);
        jaggedArray[i] = (int *)malloc(columnSizes[i] * sizeof(int));
        printf("Enter elements for row %d: ", i);
        for (int j = 0; j < columnSizes[i]; j++) {
            scanf("%d", &jaggedArray[i][j]);
        }
    }
}

void insertElement(int **jaggedArray, int row, int *columnSizes, int element, int position) {
    columnSizes[row]++;
    jaggedArray[row] = (int *)realloc(jaggedArray[row], columnSizes[row] * sizeof(int));
    for (int i = columnSizes[row] - 1; i > position; i--) {
        jaggedArray[row][i] = jaggedArray[row][i - 1];
    }
    jaggedArray[row][position] = element;
}

void deleteElement(int **jaggedArray, int row, int *columnSizes, int position) {
    for (int i = position; i < columnSizes[row] - 1; i++) {
        jaggedArray[row][i] = jaggedArray[row][i + 1];
    }
    columnSizes[row]--;
    jaggedArray[row] = (int *)realloc(jaggedArray[row], columnSizes[row] * sizeof(int));
}

int searchElement(int **jaggedArray, int rows, int *columnSizes, int element) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columnSizes[i]; j++) {
            if (jaggedArray[i][j] == element) {
                printf("Element %d found at Row %d, Column %d\n", element, i, j);
                return 1;
            }
        }
    }
    printf("Element %d not found.\n", element);
    return 0;
}

void displayJaggedArray(int **jaggedArray, int rows, int *columnSizes) {
    printf("Jagged Array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d ", jaggedArray[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    int **jaggedArray = (int **)malloc(rows * sizeof(int *));
    int *columnSizes = (int *)malloc(rows * sizeof(int));

    initializeJaggedArray(jaggedArray, rows, columnSizes);
    displayJaggedArray(jaggedArray, rows, columnSizes);

    int row, position, element, choice;
    while (1) {
        printf("\nChoose an operation:\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter row, position, and element to insert: ");
                scanf("%d %d %d", &row, &position, &element);
                insertElement(jaggedArray, row, columnSizes, element, position);
                displayJaggedArray(jaggedArray, rows, columnSizes);
                break;
            case 2:
                printf("Enter row and position of element to delete: ");
                scanf("%d %d", &row, &position);
                deleteElement(jaggedArray, row, columnSizes, position);
                displayJaggedArray(jaggedArray, rows, columnSizes);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &element);
                searchElement(jaggedArray, rows, columnSizes, element);
                break;
            case 4:
                displayJaggedArray(jaggedArray, rows, columnSizes);
                break;
            case 5:
                printf("Exiting program.\n");
                for (int i = 0; i < rows; i++) {
                    free(jaggedArray[i]);
                }
                free(jaggedArray);
                free(columnSizes);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}