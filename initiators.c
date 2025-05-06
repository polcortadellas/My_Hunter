/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 04
** File description:
** This file contains my definition of compute power rec
** headerfile
*/
#include "includes/my_hunter.h"

void init_close_button(close_button_t *button, sfVideoMode mode)
{
    button->texture = sfTexture_createFromFile("addons/closegood.png", NULL);
    button->sprite = sfSprite_create();
    button->position = (sfVector2f){mode.width - 40, 10};
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setPosition(button->sprite, button->position);
}

void init_level_resources(game_resources_t *game)
{
    float i = 10;

    game->level = 1;
    game->speed = i;
    game->current_texture = "addons/ghost.png";
}

void init_sounds(game_resources_t *game)
{
    game->sound.death_buffer = sfSoundBuffer_createFromFile
        ("addons/yoshiwo.mp3");
    game->sound.death_sound = sfSound_create();
    sfSound_setBuffer(game->sound.death_sound, game->sound.death_buffer);
    sfSound_setVolume(game->sound.death_sound, 50);
}

void init_background(sprite_background_t *back, sfVideoMode mode)
{
    sfVector2u tex_size;
    float scale_x = 0;
    float scale_y = 0;

    back->texture_b = sfTexture_createFromFile
        ("addons/hauntedhouse.jpg", NULL);
    back->sprite_b = sfSprite_create();
    sfSprite_setTexture(back->sprite_b, back->texture_b, sfTrue);
    tex_size = sfTexture_getSize(back->texture_b);
    scale_x = (float)mode.width / tex_size.x;
    scale_y = (float)mode.height / tex_size.y;
    sfSprite_setScale(back->sprite_b, (sfVector2f){scale_x, scale_y});
}

int init_window(sprite_t *spr, sfVideoMode mode)
{
    spr->window = sfRenderWindow_create(mode, "Ghost Hunter",
        sfResize | sfClose, NULL);
    if (spr->window != NULL) {
        sfRenderWindow_setFramerateLimit(spr->window, 60);
        return 1;
    }
    return 0;
}
