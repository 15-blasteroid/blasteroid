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
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib,"allegro-5.0.7-mt-debug.lib")
#pragma comment(lib,"allegro_image-5.0.7-mt-debug.lib")
static int SCREEN_W = 640;
static int SCREEN_H = 480;
static float INITIAL_HEADING = 0;
static float INITIAL_SPEED = 0;
static float SPEED_MAX = 5.0;
static float SPEED_MIN = 0.2;
static float LIVES = 3;
static float FPS = 60;
static float radius=30;


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
    struct asteroid * next;
    int singal;

}Asteroid;



//blasteroids.c
int init(void);
void spaceship(Spaceship *s, Asteroid *a, Blast *b,Asteroid *aa);

//spaceship.c
void init_spaceship(Spaceship *s);
void draw_ship(Spaceship* s);
void move_spaceship(Spaceship* s);
void lives_of_spaceship(Spaceship *s2);
//asteroid.c
void draw_asteroid(Asteroid *a);
void init_asteroid(Asteroid *a);
Asteroid *init_asteroids(void);
void move_asteroids(Asteroid *a);
void judge_asteroids(Asteroid *a);
int blast_hit_asteroid(Blast *b,Asteroid *a,int num1,Asteroid *aa);
void asteroid_double(Asteroid *a,int num,Asteroid *aa);
void destroy_asteroid(Asteroid *a,Asteroid *link);
//text.c
void draw_text(int i);
char *itoa(int i,char *string);
// P *init_ps(void);
void draw_text2(void);

//blast.c
void init_blast(Blast *b, Spaceship *s);
void draw_blast(Blast *b);
Blast *init_blasts(void);
void move_blast(Blast *b);

#endif // VERSION1_H
