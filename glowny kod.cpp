#include <allegro.h>
#include "headers.hpp"



int main()
{
	init();
	while(!key[KEY_ESC] ){
    if(menu()==false) break;
    nowa_gra();
}
	deinit();
	return 0;
}
END_OF_MAIN()


