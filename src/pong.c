#include <stdio.h>

int render_map(int x_ball, int y_ball, int y_player_1, int y_player_2);

int main() {
    // while(1)
    // move_ball(int x_ball, int y_ball);
    render_map(1, 12, 12, 12);
    return 0;
}

int render_map(int x_ball, int y_ball, int y_player_1, int y_player_2) {
    const int HEIGHT = 25;
    const int WIDTH = 80;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // отрисовка границ верх и низ
            if ((y == 0 || y == HEIGHT - 1) && x != WIDTH - 1) printf("_");

            // отрисовка мяча
            else if (x == x_ball && y == y_ball)
                printf("*");

            // отрисовка первого игрока
            else if (x == 0 && (y == y_player_1 - 1 || y == y_player_1 || y == y_player_1 + 1))
                printf("|");

            // отрисовка второго игрока
            else if (x == WIDTH - 1 && (y == y_player_2 - 1 || y == y_player_2 || y == y_player_2 + 1))
                printf("|");

            // отрисовка пустого места
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}