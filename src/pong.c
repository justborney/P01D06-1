#include <stdio.h>

#define HEIGHT 25
#define WIDTH 80

int render_map(int x_ball, int y_ball, int y_player_1, int y_player_2);
int move_ball(int x_ball, int direction);
int move_paddle(int y_player, char user_input);

int main() {
    int x_ball = 76;
    int y_ball = 12;
    int y_player_1 = 12;
    int y_player_2 = 12;
    int direction = 1;
    char user_input;
    char last_char_checker;

    while (1) {
        x_ball = move_ball(x_ball, direction);
        if (x_ball == 1 || x_ball == WIDTH - 2) direction *= -1;

        int user_input_checker = scanf("%c%c", &user_input, &last_char_checker);
        if (user_input_checker == 2 || last_char_checker != '\n') {
            if (user_input == 'a' || user_input == 'z') {
                y_player_1 = move_paddle(y_player_1, user_input);
            } 
            if (user_input == 'k' || user_input == 'm') {
                printf("HI\n");
                y_player_2 = move_paddle(y_player_2, user_input);
            }
            render_map(x_ball, y_ball, y_player_1, y_player_2);
            // printf("x_ball=%d\ndir=%d\n", x_ball, direction);
        }
    }
    return 0;
}

int render_map(int x_ball, int y_ball, int y_player_1, int y_player_2) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // отрисовка границ верх и низ
            if (y == 0 || y == HEIGHT - 1) {
                printf("_");
            }
            // отрисовка мяча
            else if (x == x_ball && y == y_ball) {
                printf("*");
            }
            // отрисовка первого игрока
            else if
                (x == 0 && (y == y_player_1 - 1 || y == y_player_1 || y == y_player_1 + 1)) { printf("|");
            }
            // отрисовка второго игрока
            else if (x == WIDTH - 1 && (y == y_player_2 - 1 || y == y_player_2 || y == y_player_2 + 1)) {
                printf("|");
            }
            // отрисовка пустого места
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

int move_ball(int x_ball, int direction) {
    if (direction > 0) {
        x_ball += 1;
    } else if (direction < 0) {
        x_ball -= 1;
    }
    return x_ball;
}

int move_paddle(int y_player, char user_input) {
    if (user_input == 'a' || user_input == 'k') {
        y_player -= 1;
    } else if (user_input == 'z' || user_input == 'm') {
        y_player += 1;
    }
    return y_player;
}