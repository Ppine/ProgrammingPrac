#include <stdio.h>
#define GRAVITY 9.8
#define SPEED_OF_SOUND 343
#define MAX_LEVEL 10
#define MY_PI 3.14

int main() {
    printf("Gravity: %.1f m/s^2\n", GRAVITY);
    printf("Speed of sound: %d m/s\n", SPEED_OF_SOUND);
    printf("Max level in the game: %d\n", MAX_LEVEL);
    printf("3 PI: %lf\n", 3*MY_PI);
    return 0;
}