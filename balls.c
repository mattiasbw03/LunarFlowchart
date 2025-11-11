#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define WIDTH 400
#define HEIGHT 400
#define TITLE "Balls and their admirers"
#define BALL_COUNT 100
#define FPS 60
#define VEL_MAX 5
#define RADIUS_MAX 20
#define RADIUS_MIN 5

Color COLORS[] = {
    LIGHTGRAY, GRAY,   DARKGRAY, YELLOW,     GOLD,      ORANGE,  PINK,
    RED,       MAROON, GREEN,    LIME,       DARKGREEN, SKYBLUE, BLUE,
    DARKBLUE,  PURPLE, VIOLET,   DARKPURPLE, BEIGE,     BROWN,   DARKBROWN,
};

// Definition of Ball
// Ball stores state and other properties
// YOUR CODE HERE
// >>> ADDED: definition af Ball-strukturen
typedef struct Ball {
    int posx;
    int posy;
    int velx;
    int vely;
    int radius;
    Color color;
    struct Ball *follows;   // pointer til den bold, den følger
} Ball;
// <<< ADDED

Ball balls[BALL_COUNT];

// Initializes a ball with random values
Ball *init_ball_random(Ball *p) {
  // Randomly initialize state and properties
  // YOUR CODE HERE
  // >>> ADDED: tilfældig position, fart, radius og farve
  p->posx = GetRandomValue(0, WIDTH - 1);
  p->posy = GetRandomValue(0, HEIGHT - 1);

  p->velx = GetRandomValue(-VEL_MAX, VEL_MAX);
  p->vely = GetRandomValue(-VEL_MAX, VEL_MAX);

  p->radius = GetRandomValue(RADIUS_MIN, RADIUS_MAX);

  int colorIndex = GetRandomValue(0, (int)(sizeof(COLORS) / sizeof(COLORS[0])) - 1);
  p->color = COLORS[colorIndex];
  // <<< ADDED

  // Find a leading ball other than the initialized ball itself.
  Ball *leader; // Represents the leading ball that this ball will follow
  // YOUR CODE HERE
  // >>> ADDED: vælg en tilfældig anden bold at følge
  do {
    int leaderIndex = GetRandomValue(0, BALL_COUNT - 1);
    leader = &balls[leaderIndex];
  } while (leader == p);   // må ikke følge sig selv
  p->follows = leader;
  // <<< ADDED

  return p;
}

// Initialize all `balls`
void init_balls_random() {
  // YOUR CODE HERE
  // >>> ADDED: initialisér alle bolde
  for (size_t i = 0; i < BALL_COUNT; ++i) {
    init_ball_random(&balls[i]);
  }
  // <<< ADDED
}

Ball *draw_ball(Ball *p) {
  DrawCircle(p->posx, p->posy, p->radius, p->color);
  return p;
}

// Updates the positions of balls according to their velocities
Ball *update_pos(Ball *p) {
  p->posx = (WIDTH + p->posx + p->velx) %
            WIDTH; // `WIDTH +` because C uses truncated division

  p->posy = (HEIGHT + p->posy + p->vely) % HEIGHT;
  return p;
}

// Updates the velocity of a ball so that it follows the leading ball
Ball *update_vel_for_following(Ball *p) {
  int errx = p->follows->posx - p->posx;
  int erry = p->follows->posy - p->posy;
  p->velx = errx > 0 ? 1 : -1;
  p->vely = erry > 0 ? 1 : -1;
  return p;
}

// Update all elements
void update_elements() {
  // for (size_t i = 0; i < _Countof balls; ++i) {
  // >>> CHANGED: brug BALL_COUNT i stedet for den ødelagte _Countof-syntaks
  for (size_t i = 0; i < BALL_COUNT; ++i) {
    draw_ball(update_pos(update_vel_for_following(&balls[i])));
  }
}

int main() {
  InitWindow(WIDTH, HEIGHT, TITLE);
  SetTargetFPS(FPS);

  init_balls_random();

  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    BeginDrawing();
    // >>> CHANGED: ClearBackground før vi tegner, ellers ser man ikke boldene
    ClearBackground(RAYWHITE);
    update_elements();
    // <<< CHANGED
    EndDrawing();
  }
}