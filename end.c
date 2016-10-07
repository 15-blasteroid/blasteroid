#include "version1.h"

void gameover(int score){

    display = al_create_display(640, 480);
    if(!display) {
        fprintf(stderr, "failed 3\n");
        return -1;
    }


    al_clear_to_color(al_map_rgb(0,250,0));
    draw_text("score :",SCREEN_W/2-100,SCREEN_H/2);
    draw_text(my_itoa(score),SCREEN_W/2 + 30,SCREEN_H/2);
    al_flip_display();
    al_rest(10.0);
}
