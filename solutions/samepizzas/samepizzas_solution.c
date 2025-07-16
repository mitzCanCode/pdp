/* 
    USER: mitzCanCode
    LANG: C
    TASK: samepizzas
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// MARK: START OF MERGE SORT
// I created a function for the merge sort algorithm so that i can sort arrays quicker
void merge(int arr[], int left, int mid, int right) {
    
    // These 2 variables are used for keeping track of how many elements there are toi the left and to the right
    int elementsLeft = mid - left + 1;
    int elementsRight = right - mid;
    
    // Temporary arrays used for containing the two halves of an array
    int leftArray[elementsLeft], rightArray[elementsRight];
    
    // Copy data to temporary arrays
    for (int i = 0; i < elementsLeft; i++) {
        leftArray[i] = arr[left + i];
    }
    for (int i = 0; i < elementsRight; i++) {
        rightArray[i] = arr[mid + 1 + i];
    }
    
    // Merge the temporary arrays back into the main array (arr)
    int i = 0, j = 0, k = left;
    while (i < elementsLeft && j < elementsRight) {
        if (leftArray[i] >= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    
    // Copying the remaining elements of leftArray, if any
    while (i < elementsLeft) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    
    // Copying the remaining elements of rightArray, if any
    while (j < elementsRight) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Helper function used for merging arrays
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point of the sub array
        int mid = left + (right - left) / 2;
        
        // Recursively sorting the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merging the two sorted halves
        merge(arr, left, mid, right);
    }
}

// MARK: END OF MERGE SORT

// Submit function used for submiting the most identical pizzas that can be made
void submit(int number) {
    FILE* file = fopen("samepizzas.out", "w");
    fprintf(file, "%d", number);
    fclose(file);
}

int main(void) {
    // Opening the file
    FILE* file = fopen("samepizzas.in", "r");
    // If the file can't be opened exit the program
    if (file ==NULL) {
        perror("Error opening file");
        return 1;
    }
    
    char line[1000000]; // Used for containg each line
    char sub_task;
    
    int lineNum = 0;
    // The total number of ingredient and the least number of ingredients that can be used
    int n = 0;
    int k = 0;
    
    
    // While loop used to iterate over all the lines
    while (fgets(line, sizeof(line), file)) {
        if (lineNum == 0) {
            sub_task = line[0]; // The subtask is the first character in the string at line 0
            printf("%c\n", sub_task);
        } else if (lineNum == 1){
            sscanf(line, "%d %d", &n, &k); // Fetching the n, k  variables from the second line
            if (k>n){
                submit(0);
                return 0;
            }
            printf("%d %d\n", n, k);
        }
        lineNum++;
    }
    
    
    // Closing the input file
    fclose(file);
    
    printf("\n");
    int i = 0;
    int ingredients[n];
    // Splitting the ingredient line
    char* piece = strtok(line, " ");
    // While there are available pieces printing them
    while (piece != NULL) {
        ingredients[i] = atoi(piece); // Converting the ammount of an ingredient to a string

        piece = strtok(NULL, " "); // Getting the next piece
        i++;
    }


    // Using the mergesort algorithm to sort all the elements
    mergeSort(ingredients, 0, n-1);
    for (int i = 0; i<n; i++) {
        printf("%d ", ingredients[i]);
    }
    printf("\n");
    printf("%d\n", ingredients[k-1]);
    

    
    // Submiting the least number of identical pizzas
    submit(ingredients[k-1]);
    
    return 0;
}
