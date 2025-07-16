/* USER: mitzCanCode
 LANG: C
 TASK: hiring */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// MARK: START OF MERGE SORT
// I created a function for the merge sort algorithm so that i can sort arrays quicker
void merge(int arr[], int parallelArr[],int left, int mid, int right) {
    
    // These 2 variables are used for keeping track of how many elements there are to the left and to the right
    int elementsLeft = mid - left + 1;
    int elementsRight = right - mid;
    
    // Temporary arrays used for containing the two halves of an array
    int leftArray[elementsLeft], rightArray[elementsRight];
    int leftParallel[elementsLeft], rightParallel[elementsRight];
    
    // Copy data to temporary arrays
    for (int i = 0; i < elementsLeft; i++) {
        leftArray[i] = arr[left + i];
        leftParallel[i] = parallelArr[left + i];
    }
    for (int i = 0; i < elementsRight; i++) {
        rightArray[i] = arr[mid + 1 + i];
        rightParallel[i] = parallelArr[mid + 1 + i];
    }
    
    // Merge the temporary arrays back into the main array (arr)
    int i = 0, j = 0, k = left;
    while (i < elementsLeft && j < elementsRight) {
        if (leftArray[i] >= rightArray[j]) {
            arr[k] = leftArray[i];
            parallelArr[k] = leftParallel[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            parallelArr[k] = rightParallel[j];
            j++;
        }
        k++;
    }
    
    // Copying the remaining elements of leftArray, if any
    while (i < elementsLeft) {
        arr[k] = leftArray[i];
        parallelArr[k] = leftParallel[i];
        i++;
        k++;
    }
    
    // Copying the remaining elements of rightArray, if any
    while (j < elementsRight) {
        arr[k] = rightArray[j];
        parallelArr[k] = rightParallel[j];
        j++;
        k++;
    }
}

// Helper function used for merging arrays
void mergeSort(int arr[], int parallelArr[], int left, int right) {
    if (left < right) {
        // Find the middle point of the sub array
        int mid = left + (right - left) / 2;
        
        // Recursively sorting the two halves
        mergeSort(arr, parallelArr, left, mid);
        mergeSort(arr, parallelArr, mid + 1, right);
        
        // Merging the two sorted halves
        merge(arr, parallelArr,left, mid, right);
    }
}

// MARK: END OF MERGE SORT

// MARK: In array helper function
bool x_is_in_array(int arr[], int size, int x) {
    int i;
    for (i=0; i<size; i++) {
        if (arr[i] == x) {
            return true;
        }
    }
    return false;
}

void submit(int performance) {
    FILE* file = fopen("hiring.out", "w");
    fprintf(file, "%d", performance);
    fclose(file);
    printf("%d", performance);
}

int main(int argc, const char * argv[]) {
    char line[2048];
    
    int total_bronze = 0;
    int total_silver = 0;
    int total_gold = 0;
    
    int total_given = 0;
    int gold_given = 0;
    int silver_given = 0;
    int bronze_given = 0;
    
    int lineNum = 0;
    int sub_task;
    int candidates = 0;
    int applicant = 0;
    int temp1;
    int temp2;
    int temp3;
    int performance = 0;
    
    FILE* file = fopen("hiring.in", "r");
    
    for (int i=0; i < 2; i++) {
        fgets(line, sizeof(line), file);
        if (lineNum == 0) {
            sscanf(line, "%d", &sub_task);
            printf("%d\n", sub_task);
        } else if (lineNum == 1){
            sscanf(line, "%d %d %d %d", &candidates, &total_bronze, &total_silver, &total_gold);
            printf("%d %d %d %d\n", candidates, total_bronze, total_silver, total_gold);
        } else {
            sscanf(line, "%d %d %d", &temp1, &temp2, &temp3);
            printf("%d %d %d\n", temp1, temp2, temp3);
        }
        lineNum++;
    }
    
    int total_all = total_gold + total_silver + total_bronze;
    int gold_n[candidates];
    int gold[candidates];
    int silver_n[candidates];
    int silver[candidates];
    int bronze_n[candidates];
    int bronze[candidates];
    int used[total_all];
    int used_count = 0;

    for (int j = 0; j<total_all; j++) {
        used[j] = -1;
    }
    
    printf("\n%d\n", candidates);
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d %d %d", &bronze[applicant], &silver[applicant], &gold[applicant]);
        printf("%d %d %d\n", bronze[applicant], silver[applicant], gold[applicant]);
        gold_n[applicant] = applicant;
        silver_n[applicant] = applicant;
        bronze_n[applicant] = applicant;
        applicant++;
    }
    
    mergeSort(gold, gold_n, 0, candidates - 1);
    for (int j = 0; j<candidates; j++){
        printf("%d:%d ", gold[j], gold_n[j]);
    }
    printf("\n");
    
    int i = 0;
    while (gold_given < total_gold && i < candidates) {
        if (x_is_in_array(used, total_all, gold_n[i])) {
            i++;
            continue;
        }
        
        // Checking if the performance of bronze for the same candidate is the same or better
        if ((bronze[gold_n[i]] >= gold[i]) && (bronze_given < total_bronze)) {
            performance += bronze[gold_n[i]];
            printf("\nJust added: %d at position %d\n (1st if g)", bronze[gold_n[i]], gold_n[i]);
            bronze_given++;
        // Checking if the performance of silver for the same candidate is the same or better
        } else if ((silver[gold_n[i]] >= gold[i]) && (silver_given < total_silver)) {
            performance += silver[gold_n[i]];
            printf("\nJust added: %d at position %d(2nd if g)\n", silver[gold_n[i]], gold_n[i]);
            silver_given++;
        } else if (gold_given < total_gold) {
            performance += gold[i];
            printf("\nJust added: %d at position %d(3rd if g)\n", gold[i], gold_n[i]);
            gold_given++;
        } else {
            break;
        }
        
        used[used_count] = gold_n[i];
        used_count++;

        printf("Used: ");
        for (int j = 0; j<used_count; j++){
            printf("%d ", used[j]);
        }
        printf("\n");
        i++;
    }
    
    mergeSort(silver, silver_n, 0, candidates - 1);
    for (int j = 0; j<candidates; j++){
        printf("%d:%d ", silver[j], silver_n[j]);
    }
    printf("\n");
    
    i = 0;
    while (silver_given < total_silver && i < candidates){
        if (x_is_in_array(used, total_all, silver_n[i])) {
            i++;
            continue;
        }
        // Checking if the performance of bronze for the same candidate is the same or better
        if ((bronze[silver_n[i]] >= silver[i]) && (bronze_given < total_bronze)){
            performance += bronze[silver_n[i]];
            printf("\nJust added: %d at position %d (1st if s)\n", bronze[silver_n[i]], silver_n[i]);
            bronze_given += 1;
        } else if (silver_given < total_silver) {
            performance += silver[i];
            printf("\nJust added: %d at position %d(2nd if s)\n", silver[i], silver_n[i]);
            silver_given++;
        } else {
            break;
        }
        used[used_count] = silver_n[i];
        used_count++;
        printf("Used: ");
        for (int j = 0; j<used_count; j++){
            printf("%d ", used[j]);
        }
        printf("\n");
        i++;
    }
    
    mergeSort(bronze, bronze_n, 0, candidates - 1);
    for (int j = 0; j<candidates; j++){
        printf("%d:%d ", bronze[j], bronze_n[j]);
    }
    printf("\n");
    
    i = 0;
    while (bronze_given < total_bronze && i < candidates) {
        if (x_is_in_array(used, total_all, bronze_n[i])) {
            i++;
            continue;
        }
        if (bronze_given < total_bronze) {
            performance += bronze[i];
            printf("\nJust added: %d at position %d(1st if b)\n", bronze[i], bronze_n[i]);
            bronze_given++;
        } else {
            break;
        }

        used[used_count] = bronze_n[i];
        used_count++;
        printf("Used: ");
        for (int j = 0; j<used_count; j++){
            printf("%d ", used[j]);
        }
        printf("\n");
        i++;
    }
    
    submit(performance);
    return 0;
}
