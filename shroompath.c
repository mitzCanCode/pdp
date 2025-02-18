#include <stdio.h>
#include <string.h>
#include <stdbool.h>

long int total_combinations(long int num) {
    long int p = 1;
    for (int i = 0; i<num; i++) {
        p = 2 * p;
    }
    return p;
}
 
char generate_combinations(int n, char *current, char result[][100], int *index) {
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
 
int main() {
    long int total_combos = 2;
    long int combo_length = 1;  // Change this value as needed
    int index = 0;
    int s = 10;
    int x = 2;
    int y = 5;
    int basket = 0;
    int steps = 0;
    char basket_content = 'a'

    while (basket < s) {
        // Calculating the total number of combinations that will be created
        total_combos = total_combinations(combo_length);
        char combinations[total_combos][combo_length];
        // Creating a new longer set of combinations
        generate_combinations(combo_length, "", combinations, &index);
        // Iterating over the combinations
        for (long int i = 0; i<total_combos; i++;) {
            // Iterating over each character of a combination
            for (long int j = 0; j<combo_length; j++;) {
                // Checking if the mushroom changes
                if !(basket_content == combinations[i][j]) { 
                    // Changing the type of shrooms in the basket to the current one
                    basket_content = combinations[i][j];
                    // Reseting the basket
                    basket = 0;
                } 
                // Adding the correct mushroom weight to the basket
                basket += (basket_content == 'a') ? x : y;
                // Increasing the steps done
                steps++;
            }
        }
        combo_length++; 
        index = 0;   
    }
    return 0;
}

