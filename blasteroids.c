#include "version1.h"

enum MYKEYS {
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE
};

bool key[5] = {false, false, false, false, false};

int k = 0;
int i=0;
int m=0;
int n=0;
Asteroid *link2=NULL;
ALLEGRO_BITMAP *bmp=NULL;
int init(void)
{
    if(!al_init()) {
        fprintf(stderr, "failed 1\n");
        return -1;
    }
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();


    if(!al_install_keyboard()) {
        fprintf(stderr, "failed 2\n");
        return -1;
    }
    bmp=al_load_bitmap("asteroid.jpg");
    if(!bmp) return -1;

    display = al_create_display(640, 480);
    if(!display) {
        fprintf(stderr, "failed 3\n");
        return -1;
    }

    font = al_load_ttf_font("/root/orange juice.ttf",72,0 );
    if (!font){
          fprintf(stderr, "Could not load 'pirulen.ttf'.\n");
          return -1;
       }

    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
        fprintf(stderr, "failed 4\n");
        al_destroy_display(display);
        return -1;
    }

    event_queue = al_create_event_queue();
    if(!event_queue) {
        fprintf(stderr, "failed 5\n");
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer(timer);

    al_clear_to_color(al_map_rgb(0,0,0));

    return 0;
}

void spaceship(Spaceship *s, Asteroid *a, Blast *b,Asteroid *aa)

{

    Spaceship *s2=malloc(sizeof(Spaceship)*4);
    init_spaceship(s2);
    bool redraw = false;
     Asteroid *link=NULL;
     //Asteroid *a3;
    //float radius = 30;

    while(1) {

        ALLEGRO_EVENT ev;
        Asteroid *a1 = a;
        Asteroid *aa1=aa;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER) {
            if(key[KEY_UP] && s->speed < SPEED_MAX)
                s->speed += 0.1;
            if(key[KEY_DOWN] && s->speed > SPEED_MIN)
                s->speed -= 0.1;
            if(key[KEY_LEFT])
                s->heading -= 0.08;
            if(key[KEY_RIGHT])
                s->heading += 0.08;
            if(key[KEY_SPACE]) {
                init_blast(b, s);
            }


            if(s->sx > SCREEN_W)
                s->sx -= SCREEN_W;
            if(s->sx < 0)
                s->sx += SCREEN_W;
            if(s->sy > SCREEN_H)
                s->sy -= SCREEN_H;
            if(s->sy < 0)
                s->sy += SCREEN_H;

            move_asteroids(a1);
            move_asteroids(aa1);
            move_spaceship(s);


            a1 = a;
            aa1=aa;
            while(a1->next) {
                judge_asteroids(a1);
                a1 = a1->next;
            }
           while(aa1->next) {
                judge_asteroids(aa1);
                aa1= aa1->next;
            }

            redraw = true;
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (ev.keyboard.keycode) {
            case ALLEGRO_KEY_UP:
                key[KEY_UP] = true;
                break;

            case ALLEGRO_KEY_DOWN:
                key[KEY_DOWN] = true;
                break;

            case ALLEGRO_KEY_LEFT:
                key[KEY_LEFT] = true;
                break;

            case ALLEGRO_KEY_RIGHT:
                key[KEY_RIGHT] = true;
                break;

            case ALLEGRO_KEY_SPACE:
                key[KEY_SPACE] = true;
                break;

            default:
                break;
            }

        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
            switch (ev.keyboard.keycode) {
            case ALLEGRO_KEY_UP:
                key[KEY_UP] = false;
                break;

            case ALLEGRO_KEY_DOWN:
                key[KEY_DOWN] = false;
                break;

            case ALLEGRO_KEY_LEFT:
                key[KEY_LEFT] = false;
                break;

            case ALLEGRO_KEY_RIGHT:
                key[KEY_RIGHT] = false;
                break;

            case ALLEGRO_KEY_SPACE:
                key[KEY_SPACE] = false;
                b = b->next;
                break;

            default:
                break;
            }

        }





        if(redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;
            ALLEGRO_TRANSFORM transform;
            al_identity_transform(&transform);
            al_rotate_transform(&transform, 0);
            al_translate_transform(&transform,0,0);
            al_use_transform(&transform);
            //al_draw_bitmap(bmp,0,0,0);
            al_flip_display();
            al_clear_to_color(al_map_rgb(50,10,70));
            s->sx += s->speed * sin(s->heading);
            s->sy -= s->speed * cos(s->heading);
            //draw_text(m);
            draw_ship(s);
            lives_of_spaceship(s2);

                    Asteroid *a2 = a;
                    Asteroid *aa2=aa;
                    while(a2->next) {
                        draw_asteroid(a2);
                        a2 = a2->next;
                    }

                    if(m){
                        a2=a;
                        asteroid_double(a2,m,aa2);
                    }


                    for(int j=0;j!=15;j++){

                        move_blast(b);
                        draw_blast(b);
                        a2 = a;
                        aa2=aa;
                       // if(j==14){

                        m=blast_hit_asteroid(b,a2,m,aa2);

                        //}



                        b = b->next;
                    }
                    al_flip_display();
        }

    }

}
