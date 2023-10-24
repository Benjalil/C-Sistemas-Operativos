#include <stdio.h>
#include <string.h>

int main() {
  int contv = 0, contc = 0;
  char P[100];
  printf("Escriba su texto ");
  fgets(P, sizeof(P), stdin);

  int n = strlen(P);
  for (int i = 0; i < n; i++) {
    if (P[i] == 'a' || P[i] == 'A' || P[i] == 'e' || P[i] == 'E' ||
        P[i] == 'i' || P[i] == 'I' || P[i] == 'o' || P[i] == 'O' ||
        P[i] == 'u' || P[i] == 'U') {

      contv++;
    } else if (P[i] == 'Q' || P[i] == 'q' || P[i] == 'w' || P[i] == 'W' ||
               P[i] == 'r' || P[i] == 'R' || P[i] == 't' || P[i] == 'T' ||
               P[i] == 'y' || P[i] == 'Y' || P[i] == 'p' || P[i] == 'P' ||
               P[i] == 's' || P[i] == 'S' || P[i] == 'd' || P[i] == 'D' ||
               P[i] == 'f' || P[i] == 'F' || P[i] == 'g' || P[i] == 'G' ||
               P[i] == 'h' || P[i] == 'H' || P[i] == 'j' || P[i] == 'J' ||
               P[i] == 'k' || P[i] == 'K' || P[i] == 'l' || P[i] == 'L' ||
               P[i] == 'z' || P[i] == 'Z' || P[i] == 'x' || P[i] == 'X' ||
               P[i] == 'c' || P[i] == 'C' || P[i] == 'v' || P[i] == 'V' ||
               P[i] == 'b' || P[i] == 'B' || P[i] == 'n' || P[i] == 'N' ||
               P[i] == 'm' || P[i] == 'M') {
      contc++;
    }
  }
  printf("Su texto tiene %i vocales \n", contv);
  printf("Su texto tiene %i consonantes \n", contc);
}