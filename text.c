#include "version1.h"

void draw_text(char *s, int x, int y)
{
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_translate_transform(&transform, x, y);
    al_use_transform(&transform);

    al_draw_text(font, al_map_rgb(255,255,255), 60, 0,ALLEGRO_ALIGN_CENTER, s);
}

void draw_text2(char *s)
{
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_translate_transform(&transform, 0, 10);
    al_use_transform(&transform);

    al_draw_text(font, al_map_rgb(255,255,255), 60, 0,ALLEGRO_ALIGN_CENTER, s);
}

char *reverse(char *s)
{
    char temp;
    char *p = s;    //p指向s的头部
    char *q = s;    //q指向s的尾部
    while(*q)
        ++q;
    q--;

    //交换移动指针，直到p和q交叉
    while(q > p)
    {
        temp = *p;
        *p++ = *q;
        *q-- = temp;
    }
    return s;
}

/*
 * 功能：整数转换为字符串
 * char s[] 的作用是存储整数的每一位
 */
char *my_itoa(int n)
{
    int i = 0,isNegative = 0;
    static char s[100];      //必须为static变量，或者是全局变量
    if((isNegative = n) < 0) //如果是负数，先转为正数
    {
        n = -n;
    }
    do      //从各位开始变为字符，直到最高位，最后应该反转
    {
        s[i++] = n%10 + '0';
        n = n/10;
    }while(n > 0);

    if(isNegative < 0)   //如果是负数，补上负号
    {
        s[i++] = '-';
    }
    s[i] = '\0';    //最后加上字符串结束符
    return reverse(s);
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
