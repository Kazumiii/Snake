#include <allegro.h>
#include "headers.hpp"
#include <stdlib.h>


void nowa_gra(){
//create snake and foods
    FONT* myFont= load_font("czcionka.pcx", NULL, NULL);

    int poz[286][5];
    double speed=100,speed2=100;
    int x=256,y=128,ruch=2,dlugosc_weza=4,fx,fy,gx,gy,bx,by,losb,losg,pkt=0,licznik,lsd=0,beczk=0,beczklos;
    bool lose=false,start=true,grzyb=false,spraw,beczka=false;
    BITMAP *bufor=create_bitmap(800,600);if(!bufor) blad();
    clear_to_color( bufor, makecol( 0, 0, 0 ) );
    BITMAP *glowa=load_bmp("media/glowa.bmp", default_palette);if(!glowa) blad();
    BITMAP *cialo=load_bmp("media/cialo.bmp", default_palette);if(!cialo) blad();
    BITMAP *ogon=load_bmp("media/ogon.bmp", default_palette);if(!ogon) blad();
    BITMAP *skret=load_bmp("media/skret.bmp", default_palette);if(!skret) blad();
    BITMAP *dol=load_bmp("media/dol.bmp", default_palette);if(!dol) blad();
    BITMAP *food=load_bmp("media/jablko.bmp", default_palette);if(!food) blad();
    BITMAP *tlo=load_bmp("media/tlo.bmp", default_palette);if(!tlo) blad();
    BITMAP *plansza=load_bmp("media/plansza.bmp", default_palette);if(!plansza) blad();
    BITMAP *tlo2=load_bmp("media/tlo2.bmp", default_palette);if(!tlo2) blad();
    BITMAP *grzybek=load_bmp("media/grzybek.bmp", default_palette);if(!grzybek) blad();
    BITMAP *beka=load_bmp("media/beczka.bmp", default_palette);if(!beka) blad();
    SAMPLE * dzwiek = load_sample( "media/grzyb.wav" );
    SAMPLE *wakeup = load_sample( "media/lsd.wav" );
    SAMPLE *bogus =NULL;

    blit( dol, bufor, 0, 0, 0, 480, dol->w, dol->h );
 srand(time(NULL));
    fx=(rand()%24+1)*32;
    fy=(rand()%14+1)*32;
    for(int i=200;i>=2;i--){
        poz[i][0]=800;
        poz[i][1]=480;
        poz[i][2]=2;
        poz[i][2]=0;
        poz[i][2]=0;
    }
    
    //Sound
play_sample( dzwiek, 200, 127, 1000, 1 );
    while(1){
        if(lose==true){
                speed=0;stop_sample(dzwiek);stop_sample(wakeup);
                bogus = load_sample( "media/bogus.wav" );
                play_sample( bogus, 255, 127, 1000, 0 );
            textprintf(screen,myFont, 400,240,makecol(255,255,255),"Press Enter");
            textprintf(screen,myFont, 400,260,makecol(255,255,255),"to go to Menu");

        while(!key[ KEY_ENTER ]){}
        //random food
        break;}
        srand(time(NULL));
        int losunio=rand()%60;
        if (losunio==0) {grzyb=false;gx=-32;gy=-32;}
        if(losunio==19) {beczka=false;bx=-32;by=-32;}
            if(grzyb==false){
            srand(time(NULL));
            losg=rand()%15;}
        if(beczka==false){
            srand(time(NULL));
            losb=rand()%30;}
            spraw=false;
        if(losg==0&&grzyb==false){

                stop_sample(wakeup);
            while(spraw==false){
            licznik=0;

            gx=rand()%24+1;
            gy=rand()%14+1;
            gy*=32;
            gx*=32;
            for(int i=0;i<dlugosc_weza;i++){
            if(poz[i][0]!=gx&&poz[i][1]!=gy)licznik++;else break;
                }if(licznik=dlugosc_weza-1)spraw=true;}
                 if(by==gy&&bx==gx) spraw=false;
            grzyb=true;
        }

        spraw=false;
        if(losb==0&&beczka==false){
            while(spraw==false){
            licznik=0;
            bx=rand()%24+1;
            by=rand()%14+1;
            by*=32;
            bx*=32;
            for(int i=0;i<dlugosc_weza;i++){
            if(poz[i][0]!=bx&&poz[i][1]!=by)licznik++;else break;
                }if(licznik=dlugosc_weza-1)spraw=true;}
                if(by==gy&&bx==gx) spraw=false;
            beczka=true;
        }
        if(beczk>0){
            if( key[ KEY_LEFT ]&&ruch!=1&&ruch!=2 ){if(ruch==3)poz[1][4]=180;else poz[1][4]=90;ruch=2;poz[1][3]=1;}else{
            if( key[ KEY_RIGHT ]&&ruch!=2&&ruch!=1 ){if(ruch==3)poz[1][4]=270;else poz[1][4]=0;ruch=1;poz[1][3]=1;}else{
            if( key[ KEY_UP ]&&ruch!=3&&ruch!=4 ){if(ruch==1)poz[1][4]=180;else poz[1][4]=270;ruch=4;poz[1][3]=1;}else
            if( key[ KEY_DOWN ]&&ruch!=4&&ruch!=3){if(ruch==1)poz[1][4]=90;else poz[1][4]=0;ruch=3;poz[1][3]=1;}
        }}}else{
            if( key[ KEY_LEFT ]&&ruch!=2&&ruch!=1 ){if(ruch==3)poz[1][4]=270;else poz[1][4]=0;ruch=1;poz[1][3]=1;}else{
            if( key[ KEY_RIGHT ]&&ruch!=1&&ruch!=2 ){if(ruch==3)poz[1][4]=180;else poz[1][4]=90;ruch=2;poz[1][3]=1;}else{
            if( key[ KEY_UP ]&&ruch!=4&&ruch!=3){if(ruch==1)poz[1][4]=90;else poz[1][4]=0;ruch=3;poz[1][3]=1;}else
            if( key[ KEY_DOWN ]&&ruch!=3&&ruch!=4 ){if(ruch==1)poz[1][4]=180;else poz[1][4]=270;ruch=4;poz[1][3]=1;}
        }}}
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
if(x<0||x>=800||y<0||y>=480) lose=true;
        poz[0][0]=x;
        poz[0][1]=y;

        rest(speed);
        false;
        if(x==fx&&y==fy){
//Snake's grow
                    while(spraw==false){
                    licznik=0;
                    srand(time(NULL));
                    fx=rand()%24+1;
                    fy=rand()%14+1;
                    fy*=32;
                    fx*=32;
                    for(int i=0;i<dlugosc_weza;i++){
                    if(poz[i][0]!=fx&&poz[i][1]!=fy)licznik++;else break;
                }if(licznik=dlugosc_weza-1)spraw=true;}
            dlugosc_weza++;
            pkt+=10;
            speed-=0.1;
            }
        if(x==gx&&y==gy){
            speed2=speed;
        speed=50;
            grzyb=false;
            gx=-32;gy=-32;
            pkt-=20;
            dlugosc_weza++;
            speed-=0.1;
            lsd=130;
            play_sample( wakeup, 255, 127, 1000, 1 );
        }
          if(x==bx&&y==by){
            beczka=false;
            bx=-32;by=-32;
            beczk=rand()%50+10;
            play_sample( wakeup, 255, 127, 1000, 1 );
        }
           if(lsd==0) speed=speed2;
    if(lsd>0){adjust_sample( dzwiek,0,127,1000,1);
            if(lsd%4==0||lsd%4==1)
                blit( tlo, bufor, 0, 0, 0, 0, tlo->w, tlo->h ); else
                    blit( tlo2, bufor, 0, 0, 0, 0, tlo2->w, tlo2->h );

            lsd--;}else{
                clear_to_color( bufor, makecol( 0, 0, 0 ) );
                stop_sample(wakeup);
                adjust_sample( dzwiek,255,127,1000,1);}

    blit( dol, bufor, 0, 0, 0, 480, dol->w, dol->h );
    masked_blit( food, bufor, 0,0, fx,fy, food->w, food->h);
    if(grzyb==true) {masked_blit( grzybek, bufor, 0,0, gx,gy, grzybek->w, grzybek->h);}
    if(beczka==true) {masked_blit( beka, bufor, 0,0, bx,by, beka->w, beka->h);beczk--;}
    if(lsd>0){textprintf(bufor,myFont, 25,530,makecol(0,0,0),"You got fung!! -20pkt");}
    if(beczk>0)textprintf(bufor,myFont, 25,530,makecol(0,0,0),"You drunk wine. Goodluck:)");
    textprintf(bufor,myFont, 25,500,makecol(0,0,0),"SCORE: %d",pkt);
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

    blit( bufor, screen, 0, 0, 0, 0, 800, 600 );
    if(start==true){
            textprintf(screen,myFont, 400,240,makecol(255,255,255),"Press Enter");
            textprintf(screen,myFont, 420,260,makecol(255,255,255),"to start");
        while(!key[ KEY_ENTER ]){
        start=false;

    }}

    for(int i=1;i<=dlugosc_weza;i++)
        if(poz[0][0]==poz[i][0]&&poz[0][1]==poz[i][1]) lose=true;

    for(int i=dlugosc_weza;i>=1;i--){
        poz[i][0]=poz[i-1][0];
        poz[i][1]=poz[i-1][1];
        poz[i][2]=poz[i-1][2];
        poz[i][3]=poz[i-1][3];
        poz[i][4]=poz[i-1][4];}

    }
    destroy_bitmap( glowa );
    destroy_bitmap( bufor );
    destroy_bitmap( dol );
    destroy_bitmap( cialo );
    destroy_bitmap( skret );
    destroy_bitmap( ogon );
    destroy_bitmap( food );
    destroy_bitmap( tlo );
     destroy_bitmap( tlo2 );
     destroy_bitmap( beka );
    destroy_bitmap( grzybek );
    destroy_sample( dzwiek );
    destroy_sample( wakeup);
    destroy_sample( bogus);
}


