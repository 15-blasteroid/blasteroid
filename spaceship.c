#include "version1.h"


void init_spaceship(Spaceship *s)
{
    s->sx = SCREEN_W / 2.0;
    s->sy = SCREEN_H / 2.0;
    s->heading = INITIAL_HEADING;
    s->speed = INITIAL_SPEED;
    s->gone = 5;
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

void move_spaceship(Spaceship *s)
{
    s->sx += s->speed * sin(s->heading);
    s->sy -= s->speed * cos(s->heading);
}

void lives_of_spaceship(Spaceship *s2,Spaceship *s){
    int l=1;
            s2->sx=50.0;
            s2->sy=20.0;
            while(l<(s->gone+1)){
                s2->sx=50*l;
                draw_ship(s2);
                l++;
            }

}
void asteroid_hit_the_spaceship(Spaceship *s,Asteroid *a,Asteroid *aa){
    int tmp = 0;
    while(a->next){
        if((pow(fabs(s->sx - a->sx), 2) + pow(fabs(s->sy - a->sy), 2))<pow(radius, 2)) {
            a = a->next;
            tmp = tmp + 1;
            printf("%d ", tmp);
        }
        a=a->next;
    }

//    while(aa->next){
//        if((pow(fabs(s->sx - aa->sx), 2) + pow(fabs(s->sy - aa->sy), 2))<pow(radius, 2)) {
//            tmp = 1;
//            if(tmp == 1) {
//                s->gone--;
//            }
//        }
//        aa=aa->next;
//    }

    if(tmp != 1) {
        s->gone = s->gone-tmp;
    }


}
