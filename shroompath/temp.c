#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void generate_combinations(int n, char *current, char **result, int *index) {
    if (strlen(current) == n) {
        strcpy(result[(*index)++], current); // Store in result array
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
 
char **get_combinations(int n, int *count) {
    *count = 1 << n; // 2^n possible combinations
    char **result = (char **)malloc((*count) * sizeof(char *));
    for (int i = 0; i < *count; i++) {
        result[i] = (char *)malloc((n + 1) * sizeof(char));
    }
 
    int index = 0;
    char start[100] = ""; // Start with an empty string
    generate_combinations(n, start, result, &index);
 
    return result;
}
 
void print_results(char **result, int count, int length) {
    printf("\nAll generated combinations:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", result[i]);
        for (int j = 0; j<length; j++ ){
        	printf("%c\n", result[i][j]);
        }
    }
}
 
void free_results(char **result, int count) {
    for (int i = 0; i < count; i++) {
        free(result[i]);
    }
    free(result);
}


 
int main() {
    int n = 2; // Example: Generate combinations of length 3
    int count;
    char **combinations = get_combinations(n, &count);
 	
    print_results(combinations, count, n);
    free_results(combinations, count);
 
    return 0;
}
























#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void generate_combinations(int n, char *current, char **result, int *index) {
    if (strlen(current) == n) {
        strcpy(result[(*index)++], current); // Store in result array
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
 
char **get_combinations(int n, int *total_combos) {
    *total_combos = 1 << n; // 2^n possible combinations
    char **result = (char **)malloc((*total_combos) * sizeof(char *));
    for (int i = 0; i < *total_combos; i++) {
        result[i] = (char *)malloc((n + 1) * sizeof(char));
    }
 
    int index = 0;
    char start[100] = ""; // Start with an empty string
    generate_combinations(n, start, result, &index);
 
    return result;
}
 
void print_results(char **result, long int total_combos, long int length) {
    printf("\nAll generated combinations:\n");
    for (int i = 0; i < total_combos; i++) {
        printf("%s\n", result[i]);
        for (int j = 0; j<length; j++ ){
        	printf("%c\n", result[i][j]);
        }
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
    int s = 13;
    int x = 5;
    int y = 3;
    long int total_combos;

 	
    print_results(combinations, total_combos, combo_length);
    free_results(combinations, total_combos);
 
 
 	while (basket < s) {
        // Calculating the total number of combinations that will be created
        total_combos = total_combinations(combo_length);
        char combinations[total_combos][combo_length];
        
        // Creating a new longer set of combinations
    	char **combinations = get_combinations(combo_length, &total_combos);

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
 
 
    return 0;
}