/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 04
** File description:
** This file contains my definition of compute power rec
** headerfile
*/
#include "includes/my_hunter.h"

void update_ghost_texture(game_resources_t *game)
{
    sfTexture_destroy(game->spr.texture);
    if (game->level <= 10)
        game->current_texture = "addons/ghost.png";
    else if (game->level <= 20)
        game->current_texture = "addons/fantasmabluelvl2.png";
    else
        game->current_texture = "addons/fantasmanegrolvl3.png";
    game->spr.texture = sfTexture_createFromFile(game->current_texture, NULL);
    sfSprite_setTexture(game->spr.sprite, game->spr.texture, sfTrue);
}

void update_ghost_level(game_resources_t *game)
{
    float i = 10;
    float j = 10;
    int new_level = 0;

    new_level = (game->pos.count / 10) + 1;
    if (new_level != game->level && new_level <= 20) {
        game->level = new_level;
        update_ghost_texture(game);
        game->speed = i + (new_level - 1) * j;
    }
}

void update_score(score_t *score, position_t pos, sfRenderWindow *window)
{
    if (!score->font)
        score->font = sfFont_createFromFile("addons/Montserrat-Black.ttf");
    if (!score->text)
        score->text = sfText_create();
    sfText_setString(score->text, my_nbr_to_str(pos.count));
    sfText_setFont(score->text, score->font);
    sfText_setCharacterSize(score->text, 50);
    sfRenderWindow_drawText(window, score->text, NULL);
}

void update_sprite_rect(sfIntRect *rect)
{
    rect->top += 42;
    if (rect->top >= 341 - 42)
        rect->top = 0;
}

void update_sprite_position(game_resources_t *game)
{
    game->timer.times = sfClock_getElapsedTime(game->timer.clock);
    game->timer.seconds = game->timer.times.microseconds / 1000000.0;
    if (game->timer.seconds > 0.15) {
        sfClock_restart(game->timer.clock);
        update_sprite_rect(&game->rect);
        sfSprite_setTextureRect(game->spr.sprite, game->rect);
        game->pos.x += game->speed;
    }
}
