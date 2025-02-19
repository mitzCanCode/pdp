//
//  main.c
//  shroompath
//
//  Created by Dimitris Chatzigeorgiou on 16/2/25.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

long int total_combinations(long int num) {
    long int p = 1;
    for (int i = 0; i<num; i++) {
        p = 2 * p;
    }
    return p;
}
 
void generate_combinations(long int n, char *current, char result[][100], int *index) {
    if (strlen(current) == n) {
        printf("%s\n", current);
        strcpy(result[(*index)++], current);
        return;
    }
 
    char next[100];
    strcpy(next, current);
    strcat(next, "a");
    generate_combinations(n, next, result, index);
 
    strcpy(next, current);
    strcat(next, "b");
    generate_combinations(n, next, result, index);
}
 
int main(void) {
    long int total_combos = 2;
    long int combo_length = 1;  // Change this value as needed
    int index = 0;
    int s = 13;
    int x = 5;
    int y = 3;
    int basket = 0;
    int steps = 0;
    char basket_content = 'a';
    bool done = false;
    
    while (basket < s) {
        // Calculating the total number of combinations that will be created
        total_combos = total_combinations(combo_length);
        char combinations[total_combos][combo_length];
        
        // Creating a new longer set of combinations
        generate_combinations(combo_length, "", combinations, &index);
        for (int i= 0; i<total_combos+1; i++){
            for (int j = 0; j<combo_length; j++){
                printf("%c", &combinations[i][j]);
            }
        }
        steps = 0;
        printf("Generated new combination\n");
        // Iterating over the combinations
        long int i = 0;
        while (i<total_combos && !done) {
            printf("Currently testing combination: %s\n", combinations[i]);
            // Iterating over each character of a combination
            long int j = 0;
            
            while (j<combo_length && !done) {
                if (combinations[i][j] == 'a' || combinations[i][j] == 'b') {
                    printf("\tCurrently testing for %c\n", combinations[i][j]);
                    // Checking if the mushroom changes
                    if (basket_content != combinations[i][j]) {
                        // Changing the type of shrooms in the basket to the current one
                        basket_content = combinations[i][j];
                        printf("\t\tBasket content removed switching to %c\n", basket_content);
                        // Reseting the basket
                        basket = 0;
                    }
                    // Adding the correct mushroom weight to the basket
                    if (basket_content == 'a') {
                        basket += x;
                        printf("\t\tAdded a to basket and increased by: %d\n", x);
                        
                    } else {
                        basket += y;
                        printf("\t\tAdded b to basket and increased by: %d\n", y);
                    }
                    printf("\t\tCurrent basket size: %d\n", basket);
                    // Increasing the steps done
                    steps++;
                }
                if (basket >= s) {
                    done = true;
                    break;
                }
                j++;
            }
            printf("here\n");
            i++;
        }

        combo_length++;
        index = 0;

    }
    long int result = steps % ((long int)pow(10,9) + 7);
    printf("%ld", result);
    return 0;
}



//int main(void) {
//    char test[4][2] = {"aa", "ab", "ba", "bb"};
//    int combos = 4;
//    int length = 2;
//    for (int i = 0; i<combos; i++) {
//        for (int j = 0; j<length; j++) {
//            printf("%c", test[i][j]);
//        }
//    }
//    return 0;
//}


//        for (long int i = 0; i<total_combos; i++) {
//            printf("Currently testing combination: %s", combinations[i]);
//            // Iterating over each character of a combination
//            for (long int j = 0; j<combo_length; j++) {
//                printf("Currently testing for %c\n", combinations[i][j]);
//                // Checking if the mushroom changes
//                if (basket_content != combinations[i][j]) {
//                    // Changing the type of shrooms in the basket to the current one
//                    basket_content = combinations[i][j];
//                    printf("Basket content removed switching to %c\n", basket_content);
//                    // Reseting the basket
//                    basket = 0;
//                }
//                // Adding the correct mushroom weight to the basket
//                if (basket_content == 'a') {
//                    basket += x;
//                    printf("Added a to basket and increased by: %d\n", x);
//
//                } else {
//                    basket += y;
//                    printf("Added b to basket and increased by: %d\n", y);
//                }
//                printf("Current basket size: %d\n", basket);
//
//                // Increasing the steps done
//                steps++;
//            }
//        }
