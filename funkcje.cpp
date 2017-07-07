#include <allegro.h>
#include "headers.hpp"
#include <stdlib.h>


void init()
{
	//reaction on buttons
	allegro_init();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
	clear_to_color( screen, makecol( 255, 255, 255 ) );
	install_keyboard();
	install_mouse();
    text_mode(-1);
    show_mouse(screen);
    install_sound( DIGI_AUTODETECT, MIDI_AUTODETECT, "" );
set_volume( 255, 255 );
}

void deinit(){
	clear_keybuf();
	allegro_exit();
}

bool menu(){
	//loading map
FONT* myFont= load_font("czcionka.pcx", NULL, NULL);
BITMAP *menu=load_bmp("media/menu.bmp", default_palette);if(!menu) blad();
blit( menu, screen, 0, 0, 0, 0, menu->w, menu->h );
 while(1)
   {
    if(mouse_x>330 && mouse_x<450 && mouse_y>140 && mouse_y<170)
    textprintf(screen,myFont, 330,140,makecol(32,43,255),"New Game");
    else
    textprintf(screen,myFont, 330,140,makecol(0,0,0),"New Game");

    if(mouse_x>352 && mouse_x<415 && mouse_y>290 && mouse_y<320)
    textprintf(screen,myFont, 352,290,makecol(32,43,255),"QUIT");
    else
    textprintf(screen,myFont, 352,290,makecol(0,0,0),"QUIT");

    if(mouse_b & 1 && mouse_x>330 && mouse_x<450 && mouse_y>140 && mouse_y<170)
    return true;
    if(mouse_b & 1 && mouse_x>352 && mouse_x<415 && mouse_y>290 && mouse_y<320)
    return false;
    rest(10);
    }
}


void blad(){
    set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
    allegro_message( "ERROR! I can't create buffor'!" );
    allegro_exit();
}

int kat_obrotu(int kat){
    return itofix((kat*256)/360);
}

