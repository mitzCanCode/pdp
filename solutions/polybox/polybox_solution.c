/*
    USER: mitzCanCode
    LANG: C
    TASK: polybox
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char* sum(const char *number1, const char *number2){
    int numOfDigits1 = (int)strlen(number1);
    int numOfDigits2 = (int)strlen(number2);
    
    int digit1, digit2;
    // The number array is 42 to contain 41 digits and the null terminator of the string
    static char number[42]; // static ensures the array size persists after function return
    int carry = 0;
    int result;
    
    int left;
    int right;
    
    
    // Strating from least significant numbers
    int d1 = numOfDigits1 - 1;
    int d2 = numOfDigits2 - 1;
    
    // counter variable used for keeping track of where digits should be placed in number[]
    int pos = 0;
    
    while (d1 >= 0 || d2 >= 0 || carry>0){
        // Assigning the int versions of the digits from the string number1 and number2
        // If any of the two have run out of digits then 0 is returned instead
        digit1 = (d1 >= 0) ? number1[d1] - '0' : 0;
        digit2 = (d2 >= 0) ? number2[d2] - '0' : 0;
        
        // Adding the 2 digits together
        result = digit1 + digit2 + carry;
        
        // Finding if there is a new carry
        carry = result / 10;
        // Assigning the sum of the digits into the number and converting the digit back to a string
        number[pos] = (result % 10)  + '0';
        
        d1--;
        d2--;
        pos++;
    }
    
    // Adding a null terminator to mark the end of a string
    number[pos] = '\0';
    
    // Reversing the number (since number[] has everything in reverse order)
    left = 0;
    right = pos - 1;
    while (left < right){
        // Swapping the variables without a temp variable cause im such a good dev
        number[right] = number[left] + number[right];
        number[left] = number[right] - number[left];
        number[right] = number[right] - number[left];
        
        right--;
        left++;
    }
    
    return number;
}



char* subtract(const char *number1, const char *number2) {
    int numOfDigits1 = (int)strlen(number1);
    int numOfDigits2 = (int)strlen(number2);
    
    int digit1, digit2;
    // The number array is 41 to contain 40 digits and the null terminator of the string
    static char number[41]; // static ensures the array size persists after function return
    int carry = 0;
    int result;
    
    int left;
    int right;
    
    
    // Strating from least significant numbers
    int d1 = numOfDigits1 - 1;
    int d2 = numOfDigits2 - 1;
    
    // counter variable used for keeping track of where digits should be placed in number[]
    int pos = 0;

    // Compare number1 and number2 lexicographically to determine which one is larger
    if (numOfDigits1 < numOfDigits2 || (numOfDigits1 == numOfDigits2 && strcmp(number1, number2) < 0)) {
        // If number2 is greater, swap number1 and number2
        const char *temp = number1;
        number1 = number2;
        number2 = temp;
        // Update the digit counts after the swap
        numOfDigits1 = (int)strlen(number1);
        numOfDigits2 = (int)strlen(number2);
    }
    
    
    while (d1 >= 0 || d2 >= 0 || carry>0){
        // Assigning the int versions of the digits from the string number1 and number2
        // If any of the two have run out of digits then 0 is returned instead
        digit1 = (d1 >= 0) ? number1[d1] - '0' : 0;
        digit2 = (d2 >= 0) ? number2[d2] - '0' : 0;
        
        if (digit1 < digit2 + carry) {
            digit1 += 10;
            result = digit1 - (digit2 + carry);
            carry = 1;
        } else {
            result = digit1 - (digit2 + carry);
            carry = 0;
        }
        
        
        // Assigning the sum of the digits into the number and converting the digit back to a string
        number[pos] = result + '0';
        
        d1--;
        d2--;
        pos++;
    }
    
    // Adding a null terminator to mark the end of a string
    number[pos] = '\0';
    
    // Reversing the number (since number[] has everything in reverse order)
    left = 0;
    right = pos - 1;
    while (left < right){
        // Swapping the variables without a temp variable cause im such a good dev
        number[right] = number[left] + number[right];
        number[left] = number[right] - number[left];
        number[right] = number[right] - number[left];
        
        right--;
        left++;
    }
    
    return number;
}



int main(void) {
    
    int i;
    int j;
    int n = 0; // Used for storing the number of pizza boxes
    int lineNum; // Used to understand what the line contains
           //                      lineNum = 0: subtask number
           //                      lineNum = 1: number of boxes
           //                      lineNum > 1: width and height
    char line[1024]; // Used for containg each line
    char sub_task; // Used for containg the subtask number
    // Parallel arrays used for containg the width and heights entered in each line
    char widths[100000][41], heights[100000][41];
    
    
    
    
    // Width and height variables (Strings to be able to contain all digits)
    char w[41], h[41];
    
    char tempPerimeter[1024];
    char perimeter[1024];
    
    // Opening the file "polybox.in"in read mode
    FILE* file = fopen("polybox.in", "r");
    if (file ==NULL) {
        perror("Error opening file");
        return 1;
    }
    
    
    
    
    lineNum = 0;
    i = 0;
    // While loop used to iterate over all the lines
    while (fgets(line, sizeof(line), file)) {
        if (lineNum == 0) {
            sub_task = line[0]; // The subtask is the first character in the string at line 0
            printf("%c\n", sub_task);
        } else if (lineNum == 1){
            n = atoi(line);
            printf("%d\n", n);
        } else {
            // sscanf is used to read input from a buffer
            if (sscanf(line, "%s %s", w, h) == 2){
                // Fill 'w' with leading zeros to make it 40 characters long
                int w_len = (int)strlen(w);
                if (w_len < 40) {
                    // Shift the existing digits of 'w' to the right
                    for (int j = 39; j >= 40 - w_len; j--) {
                        w[j] = w[j - (40 - w_len)];
                    }
                    // Fill the leading part of the string with zeros
                    for (int j = 0; j < 40 - w_len; j++) {
                        w[j] = '0';
                    }
                }
                
                // Fill 'h' with leading zeros to make it 40 characters long
                int h_len = (int)strlen(h);
                if (h_len < 40) {
                    // Shift the existing digits of 'h' to the right
                    for (int j = 39; j >= 40 - h_len; j--) {
                        h[j] = h[j - (40 - h_len)];
                    }
                    // Fill the leading part of the string with zeros
                    for (int j = 0; j < 40 - h_len; j++) {
                        h[j] = '0';
                    }
                }
                
                
                
                strcpy(widths[i], w);
                strcpy(heights[i], h);
                i++;
            } else {
                printf("There was an issue extracting the width and height");
            }
        }
        lineNum++;
    }
    
    for (i=0; i<n; i++) {
        printf("width: %s, height: %s\n", widths[i], heights[i]);
    }

    
    // Adding all the heights together
    for (i=0; i<n; i++) {
        for (j=0; j<2; j++) {
            strcpy(tempPerimeter, sum(tempPerimeter, heights[i]));
        }
    }
    printf("Sum of all heights: %s\n", tempPerimeter);

    // Adding the top and bottom widths
    strcpy(tempPerimeter, sum(tempPerimeter, widths[0]));
    strcpy(tempPerimeter, sum(tempPerimeter, widths[n-1]));
    
    printf("Sum of all heights and first and last box widths: %s\n", tempPerimeter);

    
    //Adding all the height differences
    for (i=1; i<n; i++) {
        strcpy(tempPerimeter, sum(tempPerimeter, subtract(widths[i-1], widths[i])));
    }
    printf("%s\n", tempPerimeter);
    
    
    bool foundNone0 = false; // Flag used for keeping track if only zeroes have been found
    j = 0;
    // Cleaning up the input and printing it
    for (i=0; i<strlen(tempPerimeter); i++) {
        if (tempPerimeter[i] != '0'){
            foundNone0 = true;
        }
        if (foundNone0) {
            perimeter[j] = tempPerimeter[i];
            j++;
        }
    }
    
    perimeter[j] = '\n';     // Adding a new line char as requested by the exercise
    
    printf("%s\n", perimeter);
    
    // Creating a file variable
    FILE* outputFile;
    outputFile = fopen("polybox.out", "w");
    fputs(perimeter, outputFile);
    fclose(outputFile);
    
    return 0;
}
