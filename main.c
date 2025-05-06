/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** task 05 day 5 find square root
*/
#include "includes/my_hunter.h"

int main(int argc, char **argv)
{
    sfMusic *music = NULL;
    game_resources_t game = {0};
    close_button_t button = {0};

    if (argc == 2 && argv[1][1] == 'h') {
        print_help();
        return 0;
    }
    init_audio(&music);
    init_game_resources(&game);
    init_close_button(&button, game.mode);
    game_loop(&game, &button);
    cleanup_resources(&game, music, &button);
    return 0;
}
