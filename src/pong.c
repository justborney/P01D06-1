#include <stdio.h>

int render_map(int x_ball, int y_ball, int y_player_1, int y_player_2);

int main() {
    render_map(1, 12, 12, 12);
    return 0;
}

int render_map(int x_ball, int y_ball, int y_player_1, int y_player_2) {
    const int HEIGHT = 24;
    const int WIDTH = 79;

    for (int y = 0; y < (HEIGHT + 1); y++) {
        for (int x = 0; x < (WIDTH + 1); x++) {
            // отрисовка границ верх и низ
            if ((y == 0 || y == HEIGHT) && x != WIDTH) 
                printf("_");
            else if ((y == 0 || (y == HEIGHT && y != y_player_2)) && x == WIDTH) 
                printf("_\n");

            // отрисовка мяча
            else if (x == x_ball && y == y_ball)
                printf("*");

            // отрисовка первого игрока
            else if (x == 0 && (y == y_player_1 - 1 || y == y_player_1 || y == y_player_1 + 1))
                printf("|");
            
             // отрисовка второго игрока
            else if (x == WIDTH && (y == y_player_2 - 1 || y == y_player_2 || y == y_player_2 + 1))
                printf("|\n");

            // отрисовка пустого места
            else if ((y != 0 && y != WIDTH) && x == WIDTH)
                printf(" \n");                
            else
                printf(" ");
        }
    }
    return 0;
}