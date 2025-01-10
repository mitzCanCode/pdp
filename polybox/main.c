/* USER: username
 LANG: C
 TASK: polybox
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// MARK: NOTES
// Note 1:
// Remember to remove the hard path to the file before submiting the problem

int main(void) {
    
    int i;
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
    
    
    
    // Opening the file "polybox.in"in read mode
    FILE* file = fopen("/Users/mitz/Developer/pdp/polybox/polybox/polybox.in", "r"); // MARK: NOTE 1
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
        
    return 0;
}
