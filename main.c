#include "version1.h"

int main(int argc, char *argv[])
{
    int w;
    if(w = init()) {
        return w;
    }

    Spaceship *s = malloc(sizeof(Spaceship));
    init_spaceship(s);
    Asteroid *a;
    a = init_asteroids();

    Blast *b;
    b = init_blasts();
/*
    P *p;
    p = init_ps();
*/
    spaceship(s, a, b);


    return 0;
}
