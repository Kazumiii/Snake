#include <allegro.h>
#include "headers.hpp"
#include <stdlib.h>


void nowa_gra(){
	//background
    FONT* myFont= load_font("czcionka.pcx", NULL, NULL);
    install_timer();
    install_int_ex(zwieksz_predkosc, BPS_TO_TIMER(20));
    int poz[286][5];
    double speed=2.5;
    int x=128,y=128,ruch=2,dlugosc_weza=6,fx,fy,pkt=0;
    bool lose=false,zjedzenie=true;
    BITMAP *bufor=create_bitmap(800,600);if(!bufor) blad();
    BITMAP *glowa=load_bmp("glowa.bmp", default_palette);if(!glowa) blad();
    BITMAP *cialo=load_bmp("cialo.bmp", default_palette);if(!cialo) blad();
    BITMAP *ogon=load_bmp("ogon.bmp", default_palette);if(!ogon) blad();
    BITMAP *skret=load_bmp("skret.bmp", default_palette);if(!skret) blad();
    BITMAP *dol=load_bmp("dol.bmp", default_palette);if(!dol) blad();
    BITMAP *food=load_bmp("jablko.bmp", default_palette);if(!food) blad();
    BITMAP *tlo=load_bmp("tlo.bmp", default_palette);if(!tlo) blad();

    for(int i=0;i>200;i++){
         poz[i][0]=800;
        poz[i][1]=800;
         poz[i][2]=2;
         poz[i][3]=0;
          poz[i][4]=0;
    }

    while(1)
    {
        if(lose==true){
        for(int i=dlugosc_weza;i>=0;i--){
        poz[i][0]=800;
        poz[i][1]=800;
        poz[i][2]=2;
        poz[i][3]=0;
        poz[i][4]=0;
        }
        break;}

while( predkosc> 0 )
{
        if( key[ KEY_LEFT ]&&ruch!=2&&ruch!=1 ){if(ruch==3)poz[1][4]=270;else poz[1][4]=0;ruch=1;poz[1][3]=1;}else{
        if( key[ KEY_RIGHT ]&&ruch!=1&&ruch!=2 ){if(ruch==3)poz[1][4]=180;else poz[1][4]=90;ruch=2;poz[1][3]=1;}else{
        if( key[ KEY_UP ]&&ruch!=4&&ruch!=3){if(ruch==1)poz[1][4]=90;else poz[1][4]=0;ruch=3;poz[1][3]=1;}else
        if( key[ KEY_DOWN ]&&ruch!=3&&ruch!=4 ){if(ruch==1)poz[1][4]=180;else poz[1][4]=270;ruch=4;poz[1][3]=1;}
        }}

        switch(ruch){
            case 1:
                x-=32; poz[0][2]=1; break;
            case 2:
                 x+=32; poz[0][2]=2; break;
            case 3:
                 y-=32; poz[0][2]=3; break;
            case 4:
                 y+=32;; poz[0][2]=4;break;
        }
        //predkosc weza
        predkosc-=speed;
        if(x<0||x>=800||y<0||y>=480) lose=true;
        poz[0][0]=x;
        poz[0][1]=y;

         if(poz[0][0]==fx&&poz[0][1]==fy){
            zjedzenie=true;
            dlugosc_weza++;
            pkt+=10;
            speed-=0.01;
        }
        if(zjedzenie==true){
            srand(time(NULL));
            bool spr=true;
            while(spr==true){
            fx=(rand()%24+1)*32;
            fy=(rand()%14+1)*32;
            for(int i=dlugosc_weza;i>=0;i--){
            if(poz[i][0]!=fx&&poz[i][1]!=fy) spr=false;
            }
            }
            zjedzenie=false;
        }
    blit( tlo, bufor, 0, 0, 0, 0, tlo->w, tlo->h );
     blit( dol, bufor, 0, 0, 0, 480, dol->w, dol->h );
    masked_blit( food, bufor, 0,0, fx,fy, food->w, food->h);

        textprintf(bufor,myFont, 25,500,makecol(0,0,0),"SCORE: %d",pkt);
    int obrot;
    for(int i=0;i<dlugosc_weza;i++){
        int obrot=0;
        if(poz[i][2]==1) obrot=270;
        if(poz[i][2]==2) obrot=90;
        if(poz[i][2]==4) obrot=180;
        if(i==0) rotate_sprite( bufor, glowa,poz[0][0], poz[0][1], kat_obrotu(obrot));else{
            if(poz[i][3]==1)rotate_sprite( bufor, skret,poz[i][0], poz[i][1], kat_obrotu(poz[i][4]));else
                rotate_sprite( bufor, cialo,poz[i][0], poz[i][1], kat_obrotu(obrot));
            }
        if(i==dlugosc_weza-1) rotate_sprite( bufor, ogon,poz[dlugosc_weza][0], poz[dlugosc_weza][1], kat_obrotu(obrot));
    }

//pozycja weza
    blit( bufor, screen, 0, 0, 0, 0, 800, 600 );
      for(int i=1;i<=dlugosc_weza;i++)
    if(poz[0][0]==poz[i][0]&&poz[0][1]==poz[i][1]) lose=true;
     for(int i=dlugosc_weza;i>=0;i--){

        poz[i][0]=poz[i-1][0];
        poz[i][1]=poz[i-1][1];
        poz[i][2]=poz[i-1][2];
        poz[i][3]=poz[i-1][3];
        poz[i][4]=poz[i-1][4];
    }

    }}
    destroy_bitmap( glowa );
    destroy_bitmap( bufor );
    destroy_bitmap( dol );
    destroy_bitmap( cialo );
    destroy_bitmap( skret );
    destroy_bitmap( ogon );
    destroy_bitmap( food );
    destroy_bitmap( tlo );
}

