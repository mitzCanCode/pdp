/* USER: user239.37pdp
 LANG: C
 TASK: hiring */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// MARK: START OF MERGE SORT
// I created a function for the merge sort algorithm so that i can sort arrays quicker
void merge(int arr[], int parallelArr[],int left, int mid, int right) {
    
    // These 2 variables are used for keeping track of how many elements there are toi the left and to the right
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
//    FILE* file = fopen("hiring.out", "w");
//    fprintf(file, "%d", performance);
//    fclose(file);
    printf("%d", performance);
}

int main(int argc, const char * argv[]) {
    char line[2048];
    int noOfBronze = 0;
    int noOfSilver = 0;
    int noOfGold = 0;
    int lineNum = 0;
    int sub_task;
    int applicants = 0;
    int applicant = 0;
    int temp1;
    int temp2;
    int temp3;
    int performance = 0;
    
    
    
    FILE* file = fopen("/Users/mitz/Developer/pdp/hiring/hiring/hiring.in", "r");
    
    
    for (int i=0; i < 2; i++) {
        fgets(line, sizeof(line), file);
        if (lineNum == 0) {
            sscanf(line, "%d", &sub_task);
            printf("%d\n", sub_task);
        } else if (lineNum == 1){
            sscanf(line, "%d %d %d %d", &applicants, &noOfBronze, &noOfSilver, &noOfGold);
            printf("%d %d %d %d\n", applicants, noOfBronze, noOfSilver, noOfGold);
            
        } else {
            sscanf(line, "%d %d %d", &temp1, &temp2, &temp3);
            printf("%d %d %d\n", temp1, temp2, temp3);
        }
        lineNum++;
    }
    
    int totalApplicants = noOfGold + noOfSilver + noOfBronze;
    int applicantsArrGold[applicants];
    int goldPerformances[applicants];
    int applicantsArrSilver[applicants];
    int silverPerformances[applicants];
    int applicantsArrBronze[applicants];
    int bronzePerformances[applicants];
    int applicantsUsed[totalApplicants];
    
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d %d %d", &bronzePerformances[applicant], &silverPerformances[applicant], &goldPerformances[applicant]);
        printf("%d %d %d\n", bronzePerformances[applicant], silverPerformances[applicant], goldPerformances[applicant]);
        applicantsArrGold[applicant] = applicant;
        applicantsArrSilver[applicant] = applicant;
        applicantsArrBronze[applicant] = applicant;
        applicant++;
    }
    
    mergeSort(goldPerformances, applicantsArrGold, 0, applicants - 1);
    printf("Sorted Gold Performances: ");
    for (int i = 0; i < applicants ; i++) {
        printf("%d ", goldPerformances[i]);
    }
    printf("\n");
    
    printf("Sorted Applicants: ");
    for (int i = 0; i < applicants ; i++) {
        printf("%d ", applicantsArrGold[i]);
    }
    
    printf("\n");
    for (int i=0; i<noOfGold; i++) {
        performance += goldPerformances[i];
        applicantsUsed[i] = applicantsArrGold[i];
//        printf("%d", applicantsUsed[i]);
    }
    printf("\n");


    if (totalApplicants - noOfGold == 0) {
        submit(performance);
        return 0;
    }
    
    totalApplicants -= noOfGold;
    mergeSort(silverPerformances, applicantsArrSilver, 0, applicants - 1);
    
    int applicantCounterSilver = 0;
    int i = 0;
    while (applicantCounterSilver < noOfSilver && i<=applicants-1){
        if ( !(x_is_in_array(applicantsUsed, applicantCounterSilver + noOfGold, applicantsArrSilver[i])) && (totalApplicants - applicantCounterSilver >= 0) ) {
            performance += silverPerformances[i];
            // Adding the applicants used after the last added gold applicant
            applicantsUsed[noOfGold + applicantCounterSilver] = applicantsArrSilver[i];
            applicantCounterSilver++;
        }
        i++;
    }

    printf("\n");
    
    if (totalApplicants-applicantCounterSilver == 0 && !(applicantCounterSilver <= noOfSilver)) {
        submit(performance);
        return 0;
    }
    totalApplicants -= noOfSilver;
    
    
    mergeSort(bronzePerformances, applicantsArrBronze, 0, applicants - 1);
    
    int applicantCounterBronze = 0;
    i = 0;
    while (applicantCounterBronze < noOfBronze && i<=applicants-1){
        if ( !(x_is_in_array(applicantsUsed, noOfGold+noOfSilver + applicantCounterBronze, applicantsArrBronze[i])) && (totalApplicants - applicantCounterBronze >= 0) ) {
            performance += bronzePerformances[i];
            // Adding the applicants used after the last added gold applicant
            applicantsUsed[noOfGold + noOfSilver + applicantCounterBronze] = applicantsArrBronze[i];
            applicantCounterBronze++;
        }
        i++;
    }
    printf("\n");
//    printf("Sorted Gold Performances: ");
    for (int i = 0; i < noOfGold+noOfSilver + applicantCounterBronze ; i++) {
        printf("%d ", applicantsUsed[i]);
    }

    submit(performance);


    return 0;
}


