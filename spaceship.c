#include "version1.h"


void init_spaceship(Spaceship *s)
{
    s->sx = SCREEN_W / 2.0;
    s->sy = SCREEN_H / 2.0;
    s->heading = INITIAL_HEADING;
    s->speed = INITIAL_SPEED;
    s->gone = 0;
    s->color = al_map_rgb(255, 255, 255);
}

void draw_ship(Spaceship* s){
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, s->heading);
    al_translate_transform(&transform, s->sx, s->sy);
    al_use_transform(&transform);

    al_draw_line(-8, 9, 0, -11, s->color,3.0f);
    al_draw_line(0, -11, 8, 9, s->color, 3.0f);
    al_draw_line(-6, 4, -1, 4, s->color, 3.0f);
    al_draw_line(6, 4, 1, 4, s->color, 3.0f);
}


