#include <stdio.h>

#define HEIGHT 25
#define WIDTH 80

int render_map(int x_ball, int y_ball, int y_player_1, int y_player_2);
int move_ball(int x_ball, int direction);
int move_paddle(int y_player, char user_input);
// int is_ball_on_paddle(int x_ball, int y_ball, int y_player);

int main() {
    int x_ball = 6;
    int y_ball = 12;
    int y_player_1 = 12;
    int y_player_2 = 12;
    int direction = -1;
    char user_input;
    // char last_char_checker;
    printf("Press space button to start. Press q to exit.\n");
    while (user_input != 'q') {
        user_input = getchar();

        // if (is_ball_on_paddle(x_ball, y_ball, y_player_1) == 1) {
        //     direction *= -1;
        // } else if (is_ball_on_paddle(x_ball, y_ball, y_player_2) == 1) {
        //     direction *= -1;
        // }

        if (user_input != '\n' && (user_input == 'a' || user_input == 'z' || 
                                   user_input == 'k' || user_input == 'm' || 
                                   user_input == ' ')) {
            if ((x_ball == 1) &&
                (y_player_1 == y_ball || y_player_1 - 1 == y_ball || y_player_1 + 1 == y_ball)) {
                direction *= -1;
            }
            if ((x_ball == WIDTH - 2) &&
                (y_player_2 == y_ball || y_player_2 - 1 == y_ball || y_player_2 + 1 == y_ball)) {
                direction *= -1;
            }
            x_ball = move_ball(x_ball, direction);
            if (user_input == 'a' || user_input == 'z') {
                y_player_1 = move_paddle(y_player_1, user_input);
            }
            if (user_input == 'k' || user_input == 'm') {
                y_player_2 = move_paddle(y_player_2, user_input);
            }
            printf("direction = %d x_ball = %d\n", direction, x_ball);

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
            // отрисовка первого игрока, ракетка на линии 0
            else if (x == 0 && (y == y_player_1 - 1 || y == y_player_1 || y == y_player_1 + 1)) {
                printf("|");
            }
            // отрисовка второго игрока, ракетка на линии 24
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
        x_ball += 1;  // направо
    } else if (direction < 0) {
        x_ball -= 1;  // налево
    }
    return x_ball;
}

int move_paddle(int y_player, char user_input) {
    if ((user_input == 'a' || user_input == 'k') && y_player > 2) {
        y_player -= 1;
    } else if ((user_input == 'z' || user_input == 'm') && y_player < 22) {
        y_player += 1;
    }
    return y_player;
}

// int is_ball_on_paddle(int x_ball, int y_ball, int y_player) {
//     int result;
//     if ((x_ball == 1 || x_ball == WIDTH -2) && (y_player == y_ball || y_player - 1 == y_ball || y_player +
//     1 == y_ball)) {
//         result = 1;
//         printf("on paddle!\n");
//     } else {
//         result = 0;
//     }
//     return result;
// }