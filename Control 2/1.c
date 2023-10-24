
#include <stdio.h>

int main() {
  int si = 0, num = 0;
  while (si == 0) {
    printf("ingrese su numero\n");
    scanf("%i", &num);
    if (num >= 0 && num < 10) {
      break;
      ;
    }
  }
}
