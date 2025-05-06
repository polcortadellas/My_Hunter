/*
** EPITECH PROJECT, 2024
** C Pool Day 03 - Task 04
** File description:
** This file contains my definition of compute power rec
** headerfile
*/

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stddef.h>

typedef struct position_s {
    int x;
    int y;
    int count;
} position_t;

typedef struct score_s {
    sfText* text;
    sfFont* font;
} score_t;

typedef struct sprite_s {
    sfRenderWindow* window;
    sfTexture* texture;
    sfSprite* sprite;
} sprite_t;

typedef struct sprite_background_s {
    sfTexture* texture_b;
    sfSprite* sprite_b;
} sprite_background_t;

typedef struct timer_of_game_s {
    sfClock *clock;
    sfTime times;
    float seconds;
} time_game_t;

typedef struct sound_resources_s {
    sfMusic *background_music;
    sfSound *death_sound;
    sfSoundBuffer *death_buffer;
} sound_resources_t;

typedef struct close_button_s {
    sfTexture* texture;
    sfSprite* sprite;
    sfVector2f position;
} close_button_t;


typedef struct game_resources_s {
    sprite_t spr;
    sfEvent event;
    sfIntRect rect;
    time_game_t timer;
    score_t score;
    position_t pos;
    sfVideoMode mode;
    sprite_background_t back;
    int level;
    float speed;
    char *current_texture;
    sound_resources_t sound;
} game_resources_t;

int my_nbr_to_str_edge_cases(char *str, int *nb);
char *my_nbr_to_str(int nb);
char *my_revstr(char *str);
int mini_printf(const char *format, ...);
void print_help(void);
void game_loop(game_resources_t *game, close_button_t *button);
void cleanup_resources(game_resources_t *game, sfMusic *music,
    close_button_t *button);
void render_game(game_resources_t *game, close_button_t *button);
void init_audio(sfMusic **music);
void init_game_resources(game_resources_t *game);
int init_sprites(game_resources_t *game);
int init_window(sprite_t *spr, sfVideoMode mode);
void init_background(sprite_background_t *back, sfVideoMode mode);
void init_rectangle(sfIntRect *rect);
void init_position(position_t *pos);
void check_sprite_bounds(game_resources_t *game);
void update_sprite_position(game_resources_t *game);
void update_sprite_rect(sfIntRect *rect);
void update_score(score_t *score, position_t pos, sfRenderWindow *window);
void analyse_events(game_resources_t *game, close_button_t *button);
void check_close_button(close_button_t *button, sfEvent event,
    sfRenderWindow *window);
void clicker_killer(sfEvent event, sfSprite* sprite, position_t *pos,
    game_resources_t *game);
void close_window(sfRenderWindow *window);
void update_ghost_level(game_resources_t *game);
void update_ghost_texture(game_resources_t *game);
void init_sounds(game_resources_t *game);
void init_level_resources(game_resources_t *game);
void init_close_button(close_button_t *button, sfVideoMode mode);
void cleanup_sounds(game_resources_t *game);

#endif
