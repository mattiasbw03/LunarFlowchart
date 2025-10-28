// sort.c
#include "sort.h"
#include <ctype.h>  // for tolower()

// Tjekker om bogstaver er i rækkefølge (case-insensitive)
bool letters_in_order(char a, char b) {
    return tolower(a) <= tolower(b);  
}

// Tjekker om tal er i stigende rækkefølge
bool numbers_ascending(char a, char b) {
    return a <= b;
}

// Bytter to elementer
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort implementering
void bubble_sort(char arr[], int n, bool (*pair_is_in_order)(char, char)) {
    bool swapping_occurred;
    do {
        swapping_occurred = false;
        for (int i = 1; i < n; i++) {
            if (!pair_is_in_order(arr[i - 1], arr[i])) {
                swap(&arr[i - 1], &arr[i]);
                swapping_occurred = true;
            }
        }
    } while (swapping_occurred);
}
