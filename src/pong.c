#include <stdio.h>

#define HEIGHT 25
#define WIDTH 80

int render_map(int x_ball, int y_ball, int y_player_1, int y_player_2);
int x_move_ball(int x_ball, int direction);
int y_move_ball(int y_ball, int direction);
int move_paddle(int y_player, char user_input);
int is_ball_at_paddle_1(int x_ball, int y_ball, int y_player);
int is_ball_at_paddle_2(int x_ball, int y_ball, int y_player_2);
int is_border(int y_ball);
int loss_check(int x_ball);

int main() {
    int x_ball = 77;
    int y_ball = 11;
    int y_player_1 = 12;
    int y_player_2 = 12;
    int x_direction = 1;
    int y_direction = 1;
    int score_player_1 = 0;
    int score_player_2 = 0;

    printf("Press space button to start. Press q to exit.\n");
    while (1) {
        char user_input;
        user_input = getchar();
        if (user_input != '\n' && (user_input == 'a' || user_input == 'z' || user_input == 'k' ||
                                   user_input == 'm' || user_input == ' ' || user_input == 'q')) {
            if (is_ball_at_paddle_1(x_ball, y_ball, y_player_1) == 1) {
                x_direction *= -1;
            } else if (is_ball_at_paddle_2(x_ball, y_ball, y_player_2) == 1) {
                x_direction *= -1;
            }
            if (is_border(y_ball)) {
                y_direction *= -1;
            }
            x_ball = x_move_ball(x_ball, x_direction);
            y_ball = y_move_ball(y_ball, y_direction);
            if (loss_check(x_ball)) {
                if (x_ball > 79) {
                    score_player_1++;
                    x_ball = 78;
                    y_ball = 12;
                    x_direction = 1;
                } else if (x_ball < 0) {
                    score_player_2++;
                    x_ball = 1;
                    y_ball = 12;
                    x_direction = -1;
                    y_direction = -1;
                }
            }
            if (score_player_1 > 1 || score_player_2 > 1 || user_input == 'q') {
                printf("%c", user_input);
                break;
            }
            if (user_input == 'a' || user_input == 'z') {
                y_player_1 = move_paddle(y_player_1, user_input);
            }
            if (user_input == 'k' || user_input == 'm') {
                y_player_2 = move_paddle(y_player_2, user_input);
            }
            printf("X_direction = %d Y_direction = %d x_ball = %d y_ball = %d\n", x_direction, y_direction,
                   x_ball, y_ball);
            render_map(x_ball, y_ball, y_player_1, y_player_2);
            printf("First player %d  ---  Second player %d\n", score_player_1, score_player_2);
            printf("Last user input: %c\n", user_input);
        }
    }
    return 0;
}

int render_map(int x_ball, int y_ball, int y_player_1, int y_player_2) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // отрисовка границ верх и низ
            if (y == 0 || y == HEIGHT - 1) {
                printf("=");
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

int x_move_ball(int x_ball, int direction) {
    if (direction > 0) {
        x_ball += 1;  // направо
    } else if (direction < 0) {
        x_ball -= 1;  // налево
    }
    return x_ball;
}

int y_move_ball(int y_ball, int direction) {
    if (direction > 0) {
        y_ball += 1;  // направо
    } else if (direction < 0) {
        y_ball -= 1;  // налево
    }
    return y_ball;
}

int move_paddle(int y_player, char user_input) {
    if ((user_input == 'a' || user_input == 'k') && y_player > 2) {
        y_player -= 1;
    } else if ((user_input == 'z' || user_input == 'm') && y_player < 22) {
        y_player += 1;
    }
    return y_player;
}

int is_ball_at_paddle_1(int x_ball, int y_ball, int y_player_1) {
    int result = 0;
    if (x_ball == 1 && (y_player_1 == y_ball || y_player_1 + 1 == y_ball || y_player_1 - 1 == y_ball)) {
        result = 1;
    }
    return result;
}

int is_ball_at_paddle_2(int x_ball, int y_ball, int y_player_2) {
    int result = 0;
    if ((x_ball == WIDTH - 2) &&
        (y_player_2 == y_ball || y_player_2 + 1 == y_ball || y_player_2 - 1 == y_ball)) {
        result = 1;
    }
    return result;
}

int is_border(int y_ball) {
    int result = 0;
    if (y_ball == 1 || y_ball == HEIGHT - 2) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

int loss_check(int x_ball) {
    int result = 0;
    if (x_ball == -1 || x_ball == 80) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}