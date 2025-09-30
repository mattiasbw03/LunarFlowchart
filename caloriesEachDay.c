#include <stdio.h>

#define QUEUE_SIZE 4
#define STR_SIZE 50
#define MEALS_PER_DAY 4

int queue[QUEUE_SIZE];
// `queue` is an array of `QUEUE_SIZE` integers.
// Its size is *explicit*.

char input[] = "N/A";
// `input` is an array of 4 chars (string).
// Its size is *implicit*.

const char VERSION[] = "0.2.1-2025-09-17";
// `const` makes each character read-only, so we cannot accidentally change it
// in our code.
// So, `VERSION` is an array of `_Countof("...")` read-only characters.

const int prime_numbers[] = {2, 3, 5, 7, 11, 13}; // Array size implicit

const char ROBOT_NAMES_SPACIOUS[][STR_SIZE] = {"HAL 9000", "R2-D2", "WALL-E"};
// Array of const char[STR_SIZE]
// For each string we reserve `STR_SIZE` space, which does not make sense for
// constant strings. You waste space.

const char *const ROBOT_NAMES[] = {"HAL 9000", "R2-D2", "WALL-E"};
// Array of const char * (address).
// Using pointers saves space.

double caloriesEachDayEachMeal[][MEALS_PER_DAY] = {
    {350.0, 620.5, 800.0},        // First day (breakfast, lunch, dinner)
    {300.0, 590.0, 620.3, 200.6}, // Second day (+ night snack)
    {940.2, 790.5}                // etc
};

int main() {
  for (int d = 0; d < sizeof(caloriesEachDayEachMeal) / sizeof(caloriesEachDayEachMeal[0]); d++) {
    for (int m = 0; m < MEALS_PER_DAY; m++) {
      printf("%f ", caloriesEachDayEachMeal[d][m]);
    }
    printf("\n");
  }
}