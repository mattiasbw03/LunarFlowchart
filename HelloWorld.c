#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand((unsigned int)time(NULL));

    // Generate and print 5 random numbers in [0, 4]
    for (int i = 0; i < 5; i++) {
        int num = rand() % 5; // Gives a number from 0 to 4
        printf("%d\n", num);
    }
    return 0;
}