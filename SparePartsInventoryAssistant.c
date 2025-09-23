
#include <stdio.h>
#include <string.h>

int main() {
    // Liste over reservedele i lageret
    const char *parts[] = {"hydraulic pump", "PLC module", "servo motor"};
    // Antal reservedele
    const int part_count = 3;
    // Buffer til brugerens input
    char input[100];

    // Startbesked til brugeren
    printf("Hej. Welcome to the spare parts inventory!\n");

    // Hovedloop: gentager indtil en reservedel findes
    while (1) {
        // Spørg brugeren om hvilken reservedel de har brug for
        printf("Which part do you need? ");
        // Læs brugerens input
        fgets(input, sizeof(input), stdin);

        // Fjern newline-tegn fra input
        size_t len = strlen(input);
        if (len > 0 && input[len-1] == '\n') input[len-1] = '\0';

        // Tjek for special-forespørgsler
        if (strcmp(input, "Do you actually have any parts?") == 0 ||
            strcmp(input, "Is there anything in stock at all?") == 0) {
            // Svar med antal og navne på reservedele
            printf("We have %d part(s)!\n", part_count);
            for (int i = 0; i < part_count; i++) {
                printf("%s\n", parts[i]);
            }
            continue; // Spørg igen
        }

        // Tjek om input matcher en reservedel
        int found = 0;
        for (int i = 0; i < part_count; i++) {
            if (strcmp(input, parts[i]) == 0) {
                // Bekræft at delen findes og afslut programmet
                printf("I've got %s here for you 😊. Bye!\n", parts[i]);
                found = 1;
                break;
            }
        }
        if (found) break; // Afslut loopet hvis delen findes

        // Hvis delen ikke findes, giv besked og spørg igen
        printf("I am afraid we don't have any %s in the inventory 😔\n", input);
    }
    return 0;
}