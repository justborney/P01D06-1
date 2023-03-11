// I WANT TO PLAY WITH YOU
//         YOUR FRIEND, AI
#include <stdio.h>

int main() {
    int MAX_X = 80;
    int MAX_Y = 25;

    for(int y = 0; y < MAX_Y; y++) {
       for(int x = 0; x < MAX_X; x++) {
          if (y == 0 || y == MAX_Y - 1) {
              printf("-");
          } else {
              printf("m");
          }
       }
       printf("\n");
    }
     
    return 0;
}
