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
//    Asteroid *a_before = malloc(sizeof(Asteroid));
//    init_asteroid(a_before);
    a = init_asteroids();
//    a_before->next = a;
    aa =init_asteroids2();

    Blast *b;
    b = init_blasts();

//    draw_asteroid(a);

//    al_draw_line(50, 50, 50, 0, al_map_rgb(255,100,255), 2.0f);
//    al_draw_circle(0, 0, 25, a->color, 2.0f);
//    al_flip_display();
//    al_rest(5.0);



    int score = spaceship(s, a, b,aa);
    printf("%d",score);

    gameover(score);




    return 0;
}
