#include "version1.h"

void draw_blast(Blast *b)
{
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform,b->heading);
    al_translate_transform(&transform,b->sx,b->sy);
    al_use_transform(&transform);

    al_draw_line(0, -10, 0, -20, b->color,3.0f);
}

void init_blast(Blast *b, Spaceship *s)
{
    b->sx = s->sx;
    b->sy = s->sy;
    b->color = al_map_rgb(255,255,255);
    b->gone = 0;
    b->heading = s->heading;
}

Blast *init_blasts(void)
{
    Blast *b[15];
    for(int i = 0; i != 15; i++)
        b[i] = malloc(sizeof(Blast));
    for(int i = 0; i != 14; i++) {
        b[i]->sx = 0;
        b[i]->sy = 0;
        b[i]->color = al_map_rgb(255,255,255);
        b[i]->gone = 0;
        b[i]->heading = 0;
        b[i]->next = b[i+1];
    }
    b[14]->sx = 0;
    b[14]->sy = 0;
    b[14]->color = al_map_rgb(255,255,255);
    b[14]->gone = 0;
    b[14]->heading = 0;
    b[14]->next = b[0];

    return b[0];
}

void move_blast(Blast *b)
{
    if(b->sx > 0 && b->sx < SCREEN_W && b->sy > 0 && b->sy <SCREEN_H) {
        b->sx += SPEED_MAX  * 2 * sin(b->heading);
        b->sy -= SPEED_MAX  * 2 * cos(b->heading);
    } else
        b->gone = 1;
}
