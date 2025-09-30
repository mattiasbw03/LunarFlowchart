#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Enum for formene, så vi kan bruge navne i stedet for tal
typedef enum {
	ROCK,
	LIZARD,
	SCISSORS,
	PAPER,
	SPOCK,
	SHAPE_COUNT
} Shape;

// Til navne og emojis for formerne
const char *shape_names[SHAPE_COUNT] = {
	"Rock",
	"Lizard",
	"Scissors",
	"Paper",
	"Spock"
};
const char *shape_emojis[SHAPE_COUNT] = {
	"\xF0\x9F\xAA\xA8", // 🪨
	"\xF0\x9F\xA6\x8E", // 🦎
	"\xE2\x9C\x82\xEF\xB8\x8F", // ✂️
	"\xF0\x9F\x97\x92\xEF\xB8\x8F", // 🗒️
	"\xF0\x9F\x96\x96\xEF\xB8\x8F"  // 🖖
};

#define WINNING_SCORE 5

// Her viser skemaet om en form vinder over en anden form
const int win_matrix[SHAPE_COUNT][SHAPE_COUNT] = {
	// R  L  S  P  SP
	{0, 1, 1, 0, 0}, // Rock
	{0, 0, 1, 0, 1}, // Lizard
	{0, 0, 0, 1, 1}, // Scissors
	{1, 1, 0, 0, 0}, // Paper
	{1, 0, 1, 1, 0}  // Spock
};

void clear_input() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
	srand((unsigned int)time(NULL));
	char menu_choice;
	printf("Welcome to \xF0\x9F\xAA\xA8  \xE2\x9C\x82\xEF\xB8\x8F  \xF0\x9F\x97\x92\xEF\xB8\x8F  \xF0\x9F\x96\x96\xEF\xB8\x8F  \xF0\x9F\xA6\x8E !\n");
	while (1) {
		printf("(s) Single player\n(e) Exit\nSelect an item: ");
		menu_choice = getchar();
		clear_input();
		if (menu_choice == 'e') {
			printf("Bye!\n");
			return 0;
		} else if (menu_choice == 's') {
			printf("Starting game \xF0\x9F\x8E\x89\n");
			int player_score = 0, agent_score = 0;
			while (player_score < WINNING_SCORE && agent_score < WINNING_SCORE) {
				printf("\nSelect a shape:\n");
				for (int i = 0; i < SHAPE_COUNT; ++i) {
					printf("%d%s  || ", i, shape_emojis[i]);
				}
				printf(": ");
				int user_shape = -1;
				int scan_result = scanf("%d", &user_shape);
				clear_input();
				if (scan_result != 1 || user_shape < 0 || user_shape >= SHAPE_COUNT) {
					printf("\xE2\x9D\x8C Shape key %d does not exist. Try again.\n", user_shape);
					continue;
				}
				int agent_shape = rand() % SHAPE_COUNT;
				printf("Agent: %d\n", agent_shape);
				// Determinerer vinderen
				if (user_shape == agent_shape) {
					printf("Draw!\n");
				} else if (win_matrix[user_shape][agent_shape]) {
					player_score++;
				} else {
					agent_score++;
				}
				printf("\xF0\x9F\x91\xAB:🤖  %d:%d\n", player_score, agent_score);
			}
			if (player_score == WINNING_SCORE) {
				printf("You won!\n");
			} else {
				printf("\xF0\x9F\xA4\x96 Agent won!\n");
			}
			break;
		} else {
			printf("\xE2\x9D\x8C Invalid menu choice. Try again.\n");
		}
	}
	return 0;
}
