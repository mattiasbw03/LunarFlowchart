#include <stdio.h>

const double motor_capacity = 5.6;

int main(void) {
    printf("hvor mange motorer du?");
    int num_motor;
    scanf("%d", &num_motor);
    printf("Hvor mange kg vejer pakkerne?");
    int kg;
    scanf("%d", &kg);
    if (kg >= num_motor * motor_capacity)
    {
        printf("Bæltet kan ikke køre");
    }
    else
    {
        printf("Bæltet kan godt køre");
    }
    return 0;    

}