#include <stdio.h>

/* README
Denne kode viser et rumskibs kontrolsystem for dens thruster
hvor altituden bestemmer udfaldet
-Hvis altitude er > 100 skal thruster= 0 off
-Hvis altitude 0 < og <= 100 skal thruster= 1 on
-Hvis altitude <=0 skal thruster= 0 off*/

  int Control(int altitude) {
    int thruster = 0;

    if (altitude > 100) {
        thruster = 0;   // thruster off
    } else if (altitude > 0) {
        thruster = 1;   // thruster on
    } else {
        thruster = 0;   // thruster off
    }

    return thruster;
}

void Test(int altitude) {
  int thruster = Control(altitude);
  int behaviorCorrect = (altitude > 100 && thruster == 0) ||
                        (altitude <= 100 && altitude > 0 && thruster == 1) ||
                        (altitude <= 0 && thruster == 0);
  char *behaviorCorrectIcon = behaviorCorrect ? " OK " : "FAIL";
  printf("For altitude %3d, your thruster is %d |%s|\n", altitude, thruster,
         behaviorCorrectIcon);
}

int main(void) {
  Test(150);
  Test(100);
  Test(50);
  Test(0);
  Test(-1);
}