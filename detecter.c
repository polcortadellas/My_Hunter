/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 04
** File description:
** This file contains my definition of compute power rec
** headerfile
*/
#include "includes/my_hunter.h"
void cleanup_sounds(game_resources_t *game)
{
    sfSound_destroy(game->sound.death_sound);
    sfSoundBuffer_destroy(game->sound.death_buffer);
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

void clicker_killer(sfEvent event, sfSprite* sprite, position_t *pos,
    game_resources_t *game)
{
    sfFloatRect posi = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&posi, event.mouseButton.x,
        event.mouseButton.y)) {
        pos->y = rand() % (game->mode.height - 42);
        pos->x = 0;
        pos->count += 1;
        sfSound_play(game->sound.death_sound);
    }
}

void check_close_button(close_button_t *button, sfEvent event,
    sfRenderWindow *window)
{
    sfFloatRect bounds;
    sfVector2i mouse;

    if (event.type == sfEvtMouseButtonPressed) {
        bounds = sfSprite_getGlobalBounds(button->sprite);
        mouse = sfMouse_getPositionRenderWindow(window);
        if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
            sfRenderWindow_close(window);
        }
    }
}

void analyse_events(game_resources_t *game, close_button_t *button)
{
    if (game->event.type == sfEvtMouseButtonPressed)
        clicker_killer(game->event, game->spr.sprite, &game->pos, game);
    if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyEscape)
        close_window(game->spr.window);
    if (game->event.type == sfEvtClosed)
        close_window(game->spr.window);
    check_close_button(button, game->event, game->spr.window);
}
