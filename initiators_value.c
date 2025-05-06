/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 04
** File description:
** This file contains my definition of compute power rec
** headerfile
*/
#include "includes/my_hunter.h"

void init_position(position_t *pos)
{
    pos->x = 0;
    pos->y = 0;
    pos->count = 0;
}

void init_rectangle(sfIntRect *rect)
{
    rect->left = 0;
    rect->top = 0;
    rect->width = 42;
    rect->height = 42;
}

int init_sprites(game_resources_t *game)
{
    game->spr.texture = sfTexture_createFromFile(game->current_texture, NULL);
    if (!game->spr.texture)
        return 0;
    game->spr.sprite = sfSprite_create();
    sfSprite_setTexture(game->spr.sprite, game->spr.texture, sfTrue);
    return 1;
}

void init_game_resources(game_resources_t *game)
{
    game->mode = (sfVideoMode){800, 600, 32};
    game->timer.clock = sfClock_create();
    init_position(&game->pos);
    init_rectangle(&game->rect);
    init_background(&game->back, game->mode);
    init_level_resources(game);
    init_sounds(game);
    if (!init_window(&game->spr, game->mode) || !init_sprites(game))
        exit(84);
}

void init_audio(sfMusic **music)
{
    *music = sfMusic_createFromFile("addons/music_ghost.ogg");
    if (*music) {
        sfMusic_setVolume(*music, 30);
        sfMusic_play(*music);
    }
}
