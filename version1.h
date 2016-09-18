#ifndef VERSION1_H
#define VERSION1_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

static int SCREEN_W = 640;
static int SCREEN_H = 480;
static float INITIAL_HEADING = 0;
static float INITIAL_SPEED = 0;
static float SPEED_MAX = 5.0;
static float SPEED_MIN = 0.2;
static float LIVES = 3;
static float FPS = 60;



ALLEGRO_DISPLAY *display;
ALLEGRO_TIMER *timer;
ALLEGRO_EVENT_QUEUE *event_queue;
ALLEGRO_FONT *font;

typedef struct {
    float sx;
    float sy;
    float heading;
    float speed;
    int gone;
    ALLEGRO_COLOR color;
}Spaceship;

typedef struct blast{
    float sx;
    float sy;
    float heading;
    int gone;
    ALLEGRO_COLOR color;
    struct blast *next;
}Blast;

typedef struct p{
    int q;
    struct p *next;
}P;

typedef struct asteroid{
    float sx;
    float sy;
    float heading;
    float twist;
    float speed;
    float rot_velocity;
    float scale;
    int gone;
    float twist_add;
    float sx_add;
    float sy_add;
    ALLEGRO_COLOR color;
    struct asteroid *next;
}Asteroid;



//blasteroids.c
int init(void);
void spaceship(Spaceship *s, Asteroid *a, Blast *b);

//spaceship.c
void init_spaceship(Spaceship *s);
void draw_ship(Spaceship* s);

//asteroid.c
void draw_asteroid(Asteroid *a);
void init_asteroid(Asteroid *a);
Asteroid *init_asteroids(void);
void move_asteroids(Asteroid *a);
void judge_asteroids(Asteroid *a);

//text.c
void draw_text(void);
// P *init_ps(void);

//blast.c
void init_blast(Blast *b, Spaceship *s);
void draw_blast(Blast *b);
Blast *init_blasts(void);
void move_blast(Blast *b);

#endif // VERSION1_H
