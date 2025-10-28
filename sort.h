#ifndef SORT_H
#define SORT_H

#include <stdbool.h>

bool letters_in_order(char a, char b);
bool numbers_ascending(char a, char b);

void swap(char *a, char *b);

void bubble_sort(char arr[], int n, bool (*pair_is_in_order)(char, char));

#endif
