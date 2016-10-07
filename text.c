#include "version1.h"

void draw_text(int i)
{
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_translate_transform(&transform, 0, 10);
    al_use_transform(&transform);
    char str[10];
    int score=100*i;
    // char *text=itoa(score,str);
    //al_draw_text(font, al_map_rgb(255,255,255), 60, 0,ALLEGRO_ALIGN_CENTER,text);

      //  al_draw_text(font, al_map_rgb(255,255,255), 60, 0,ALLEGRO_ALIGN_CENTER, "you have win");




}
void draw_text2(void)
{
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_translate_transform(&transform, 100, 100);
    al_use_transform(&transform);

    al_draw_text(font, al_map_rgb(255,255,255), 60, 0,ALLEGRO_ALIGN_CENTER, "hahahaha");
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
//char *itoa(int val,char *buf,unsigned radix){
//    char *p;
//    char *firstdig;
//    char temp;
//    unsigned digval;
//    p=buf;
//    if(val<0){
//        *p++='-';
//        val=(unsigned long)(-(long)val);

//    }
//    fisrtdig=p;


//}
