#include "version1.h"

void draw_text(void)
{
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_translate_transform(&transform, 0, 10);
    al_use_transform(&transform);

    al_draw_text(font, al_map_rgb(255,255,255), 60, 0,ALLEGRO_ALIGN_CENTER, "600!");
}

/*

P *init_ps(void){
    P *p1[15];

    for(int i = 0; i != 15; i++)
        p1[i] = malloc(sizeof(P));
    for(int i = 0; i != 14; i++) {
        p1[i]->q = i;
        p1[i]->next = p1[i+1];
    }
    p1[14]->q = 0;
    p1[14]->next = p1[0];

    return p1[0];
}
*/