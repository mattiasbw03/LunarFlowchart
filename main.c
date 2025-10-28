// main.c
#include <stdio.h>
#include "sort.h"

int main() {
    char letter_arr[] = {'z', 's', 's', 'a'};
    char number_arr[] = {4, -1, 2, 9};
    int n_letters = sizeof(letter_arr) / sizeof(letter_arr[0]);
    int n_numbers = sizeof(number_arr) / sizeof(number_arr[0]);

    // Sortér bogstaver
    bubble_sort(letter_arr, n_letters, letters_in_order);
    printf("Sorted letters: ");
    for (int i = 0; i < n_letters; i++)
        printf("%c ", letter_arr[i]);
    printf("\n");

    // Sortér tal
    bubble_sort(number_arr, n_numbers, numbers_ascending);
    printf("Sorted numbers: ");
    for (int i = 0; i < n_numbers; i++)
        printf("%d ", number_arr[i]);
    printf("\n");

    return 0;
}
