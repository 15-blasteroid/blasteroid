#include "version1.h"
int grade=0;
void draw_asteroid(Asteroid *a)
{
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, a->twist);
    al_translate_transform(&transform, a->sx, a->sy);
    al_use_transform(&transform);

    al_draw_line(-20 * a->scale, 20 * a->scale, -25 * a->scale, 5 * a->scale,a->color, 2.0f);
        al_draw_line(-25 * a->scale, 5 * a->scale, -25 * a->scale, -10 * a->scale, a->color, 2.0f);
        al_draw_line(-25 * a->scale, -10 * a->scale, -5 * a->scale, -10 * a->scale, a->color, 2.0f);
        al_draw_line(-5 * a->scale, -10 * a->scale, -10 * a->scale, -20 * a->scale, a->color, 2.0f);
        al_draw_line(-10 * a->scale, -20 * a->scale, 5 * a->scale, -20 * a->scale, a->color, 2.0f);
        al_draw_line(5 * a->scale, -20 * a->scale, 20 * a->scale, -10 * a->scale, a->color, 2.0f);
        al_draw_line(20 * a->scale, -10 * a->scale, 20 * a->scale, -5 * a->scale, a->color, 2.0f);
        al_draw_line(20 * a->scale, -5 * a->scale, 0 * a->scale, 0 * a->scale, a->color, 2.0f);
        al_draw_line(0 * a->scale, 0 * a->scale, 20 * a->scale, 10 * a->scale, a->color, 2.0f);
        al_draw_line(20 * a->scale, 10 * a->scale, 10 * a->scale, 20 * a->scale, a->color, 2.0f);
        al_draw_line(10 * a->scale, 20 * a->scale, 0 * a->scale, 15 * a->scale, a->color, 2.0f);
        al_draw_line(0 * a->scale, 15 * a->scale, -20 * a->scale, 20 * a->scale, a->color, 2.0f);

}

void init_asteroid(Asteroid *a)
{
    a->sx = SCREEN_W / 2.0;
    a->sy = SCREEN_H / 2.0;
    a->color = al_map_rgb(255, 255, 255);
    a->heading = 0;
    a->gone = 0;
    a->scale = 1;
    a->rot_velocity = 0;
    a->speed = 0;
    a->twist = 0;
    a->sx_add = 0;
    a->sy_add = 0;
    a->twist_add = 0;
    a->next = NULL;
    a->singal=0;
}

Asteroid *init_asteroids(void)
{
    Asteroid *a[20];
    a[0] = malloc(sizeof(Asteroid));
    init_asteroid(a[0]);
    a[0]->scale=0;
//    a[0]->sy=SCREEN_H*3;
    for(int i = 1; i != 20; i++) {
        a[i] = malloc(sizeof(Asteroid));
        init_asteroid(a[i]);
        if(i != 20) {
            a[i-1]->next = a[i];

            a[i-1]->sx = (rand() / (double)RAND_MAX) * SCREEN_W;
            a[i-1]->sy = (rand() / (double)RAND_MAX) * SCREEN_H;
            a[i-1]->sx_add = (rand() / (double)RAND_MAX) * 1;
            a[i-1]->sy_add = (rand() / (double)RAND_MAX) * 1;
            a[i-1]->twist_add = (rand() / (double)RAND_MAX) * 0.1;


            if(i == 1)
                a[1]->color = al_map_rgb(0, 255, 0);
            else if(!(i % 3))
                a[i-1]->color = al_map_rgb(255, 0, 0);
            else if(!(i % 7))
                a[i-1]->color = al_map_rgb(0, 255, 0);
            else if(!(i % 2))
                a[i-1]->color = al_map_rgb(0, 0, 255);
            else
                a[i-1]->color = al_map_rgb(189, 0, 200);
        }
    }

//    a[0]->sx=SCREEN_W+10;
//    a[0]->sy=SCREEN_H+10;
//    a[0]->sx_add=0;
//    a[0]->sy_add=0;


    return a[0];
}

void move_asteroids(Asteroid *a)
{
    Asteroid *a1 = a;
    while(a1) {
        a1->twist += a1->twist_add;
        a1->sx += a1->sx_add;
        a1->sy += a1->sy_add;
        a1 = a1->next;
    }

}

void judge_asteroids(Asteroid *a)
{

        if(a->sx > SCREEN_W)
            a->sx -= SCREEN_W;
        if(a->sx < 0)
            a->sx += SCREEN_W;
        if(a->sy > SCREEN_H)
            a->sy -= SCREEN_H;
        if(a->sy < 0)
            a->sy += SCREEN_H;


}
int blast_hit_asteroid(Blast *b,Asteroid *a,int num1,Asteroid *aa){
    Asteroid *link=NULL;
    Asteroid *link1=NULL;
    Asteroid *aa1=aa;
    int j=0;
    int nnn = 0;

    draw_text2(my_itoa(grade));
    while(a->next) {
        if((pow(fabs(b->sx - a->sx), 2) + pow(fabs(b->sy - a->sy), 2))<pow(radius, 2)&&a->scale==1) {
            nnn = 1;

            if(nnn == 1) {
                grade = grade + 100;
                draw_text2(my_itoa(grade));
            }

            nnn = 0;
//            draw_text2(my_itoa(grade));
            a->scale=0.5;
            num1++;

        }else if((pow(fabs(b->sx - a->sx), 2) + pow(fabs(b->sy - a->sy), 2))<            pow(radius, 2)&&a->scale==0.5) {
            //            if(j==0){
            //                free(a);
            //            }
            //            j++;
            destroy_asteroid(a,link);
        }
        link=a;
        a=a->next;
    }
//    if(!a->next){
//        if((pow(fabs(b->sx - a->sx), 2) + pow(fabs(b->sy - a->sy), 2))<pow(radius, 2)&&a->scale==0.5) {
//            free(a);
//        }
//    }
    while(aa1->next){
        if((pow(fabs(b->sx - a->sx), 2) + pow(fabs(b->sy - a->sy),2)) <pow(radius, 2)&&a->scale==0.5){
            destroy_asteroid(a,link1);
        }
        num1--;
        link1=aa1;
        aa1=aa1->next;
    }
    return num1;

}

void asteroid_double(Asteroid *a,int num,Asteroid *aa){
    while(a->next){
       int i=0;
            if(a->scale==0.5&&i!=num){
                aa->color=a->color;
                aa->scale=0.5;
                draw_asteroid(aa);
                aa=aa->next;
            }

          a=a->next;
   }
}
void destroy_asteroid(Asteroid *a,Asteroid *link){
    Asteroid *link1=a;
    link->next=a->next;
    free(link1);

}

Asteroid *init_asteroids2(void)
{
    Asteroid *a[20];
    a[0] = malloc(sizeof(Asteroid));
    init_asteroid(a[0]);
    for(int i = 1; i != 20; i++) {
        a[i] = malloc(sizeof(Asteroid));
        init_asteroid(a[i]);
        if(i != 20) {
            a[i-1]->next = a[i];

            a[i-1]->sx = (rand() / (double)RAND_MAX) * SCREEN_W;
            a[i-1]->sy = (rand() / (double)RAND_MAX) * SCREEN_H;
            a[i-1]->sx_add = (rand() / (double)RAND_MAX) * 1;
            a[i-1]->sy_add = (rand() / (double)RAND_MAX) * 1;
            a[i-1]->twist_add = (rand() / (double)RAND_MAX) * 0.1;


            if(i == 1)
                a[1]->color = al_map_rgb(0, 255, 0);
            else if(!(i % 3))
                a[i-1]->color = al_map_rgb(255, 0, 0);
            else if(!(i % 7))
                a[i-1]->color = al_map_rgb(0, 255, 0);
            else if(!(i % 2))
                a[i-1]->color = al_map_rgb(0, 0, 255);
            else
                a[i-1]->color = al_map_rgb(189, 0, 200);
        }
    }


    return a[0];
}

