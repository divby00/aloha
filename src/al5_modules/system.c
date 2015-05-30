#include <allegro5/allegro.h>
#include <stdio.h>
#include "system.h"

void aloha_al_init() {
    al_init();
}

EXPORT int lua_al_init(lua_State* ls) {
    aloha_al_init();
    return 0;
}

