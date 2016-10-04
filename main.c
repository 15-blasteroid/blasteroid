#include "version1.h"

int main(void)
{
    int w;
    if((w=init())) {
        return w;
    }

    Spaceship *s = malloc(sizeof(Spaceship));
    init_spaceship(s);
    Asteroid *a,*aa;
    a = init_asteroids();
    aa =init_asteroids();

    Blast *b;
    b = init_blasts();

//    draw_asteroid(a);

//    al_draw_line(50, 50, 50, 0, al_map_rgb(255,100,255), 2.0f);
//    al_draw_circle(0, 0, 25, a->color, 2.0f);
//    al_flip_display();
//    al_rest(5.0);



    spaceship(s, a, b,aa);


    return 0;
}
