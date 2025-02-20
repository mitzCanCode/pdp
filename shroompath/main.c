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
#include <stdlib.h>

void generate_combinations(long int combo_length, char *current, char **result, int *index) {
    if (strlen(current) == combo_length) {
        strcpy(result[(*index)++], current); // Store in result array
        return;
    }
 
    char next[100];
 
    strcpy(next, current);
    strcat(next, "a");
    generate_combinations(combo_length, next, result, index);
 
    strcpy(next, current);
    strcat(next, "b");
    generate_combinations(combo_length, next, result, index);
}
 
char **get_combinations(long int combo_length, long int *total_combos) {
    *total_combos = 1 << combo_length; // 2^n possible combinations
    char **result = (char **)malloc((*total_combos) * sizeof(char *));
    for (int i = 0; i < *total_combos; i++) {
        result[i] = (char *)malloc((combo_length + 1) * sizeof(char));
    }
 
    int index = 0;
    char start[100] = ""; // Start with an empty string
    generate_combinations(combo_length, start, result, &index);
 
    return result;
}
 
void print_results(char **result, long int total_combos, long int combo_length) {
    for (int i = 0; i < total_combos; i++) {
        printf("%s\n", result[i]);
    }
}
 
void free_results(char **result, int total_combos) {
    for (int i = 0; i < total_combos; i++) {
        free(result[i]);
    }
    free(result);
}


 
int main() {
    long int combo_length = 1;  
    int s = 10;
    int x = 2;
    int y = 5;
    long int total_combos;
    long int steps;
    bool done = false;
    char basket_content = 'a';
	long int basket;
 	

 
 
 	while (basket < s) {
        // Creating a new longer set of combinations
    	char **combinations = get_combinations(combo_length, &total_combos);

        // steps = 0;
        printf("Generated new combinations:\n");
        print_results(combinations, total_combos, combo_length);

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
		free_results(combinations, total_combos);
        combo_length++;
    }
 	
    long int result = steps % ((long int)pow(10,9) + 7);
    printf("%ld", result);

 
    return 0;
}
