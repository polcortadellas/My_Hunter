/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 04
** File description:
** This file contains my definition of compute power rec
** headerfile
*/
#include "includes/my_hunter.h"

void check_sprite_bounds(game_resources_t *game)
{
    if (sfSprite_getPosition(game->spr.sprite).x >= 800) {
        game->pos.x = 0;
        game->pos.y = rand() % (game->mode.height - 42);
    }
}

void render_game(game_resources_t *game, close_button_t *button)
{
    sfRenderWindow_clear(game->spr.window, sfBlack);
    sfRenderWindow_drawSprite(game->spr.window, game->back.sprite_b, NULL);
    sfSprite_setTextureRect(game->spr.sprite, game->rect);
    sfSprite_setPosition(game->spr.sprite,
        (sfVector2f){game->pos.x, game->pos.y});
    sfRenderWindow_drawSprite(game->spr.window, game->spr.sprite, NULL);
    update_score(&game->score, game->pos, game->spr.window);
    sfRenderWindow_drawSprite(game->spr.window, button->sprite, NULL);
    sfRenderWindow_display(game->spr.window);
}

void cleanup_resources(game_resources_t *game, sfMusic *music,
    close_button_t *button)
{
    if (music)
        sfMusic_destroy(music);
    cleanup_sounds(game);
    sfSprite_destroy(game->spr.sprite);
    sfTexture_destroy(game->spr.texture);
    sfSprite_destroy(game->back.sprite_b);
    sfTexture_destroy(game->back.texture_b);
    sfFont_destroy(game->score.font);
    sfText_destroy(game->score.text);
    sfSprite_destroy(button->sprite);
    sfTexture_destroy(button->texture);
    sfRenderWindow_destroy(game->spr.window);
    sfClock_destroy(game->timer.clock);
}

void game_loop(game_resources_t *game, close_button_t *button)
{
    while (sfRenderWindow_isOpen(game->spr.window)) {
        while (sfRenderWindow_pollEvent(game->spr.window, &game->event))
            analyse_events(game, button);
        update_sprite_position(game);
        check_sprite_bounds(game);
        update_ghost_level(game);
        render_game(game, button);
    }
}

void print_help(void)
{
    mini_printf("Ghost Hunter\n");
    mini_printf("Try to kill the ghosts with left mouse click ");
    mini_printf("and get the highest score.\n");
}
