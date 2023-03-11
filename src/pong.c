#include <stdio.h>

int create_map(int x_ball, int y_ball);

int main() {
    create_map(10, 10);
    return 0;
}

int create_map(int x_ball, int y_ball) {
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            // отрисовка границ верх и низ
            if ((y == 0 || y == 24) && x != 79) 
                printf("_");
            else if ((y == 0 || y == 24) && x == 79) 
                printf("_\n");
                
            // отрисовка мяча
            if (x == x_ball && y == y_ball)
                printf("*");
            // отрисовка пустого места
            else if ((y != 0 && y != 79) && x == 79)
                printf(" \n");                
            else
                printf(" ");
        }
    }
    return 0;
}