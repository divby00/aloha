#include "display.h"
#include <stdio.h>

ALLEGRO_DISPLAY* aloha_create_display(unsigned int w, unsigned int h) {
    ALLEGRO_DISPLAY* display = NULL;
    display = al_create_display(w, h);
    return display;
}

EXPORT int lua_create_display(lua_State* ls) {
    ALLEGRO_DISPLAY* display = NULL;
    unsigned int w = 0;
    unsigned int h = 0;

    if (lua_isnumber(ls, 1) && lua_isnumber(ls, 2)) {
        w = lua_tonumber(ls, 1);
        h = lua_tonumber(ls, 2);
        display = aloha_create_display(w, h);
    }

    if (display != NULL) {
        lua_pushlightuserdata(ls, display);
    } else {
        lua_pushnil(ls);
    }
    return 1;
}

void aloha_destroy_display(ALLEGRO_DISPLAY* display) {
    al_destroy_display(display);
}

EXPORT int lua_destroy_display(lua_State* ls) {
    ALLEGRO_DISPLAY* display = NULL;

    if (lua_islightuserdata(ls, 1)) {
        display = lua_touserdata(ls, 1);
        aloha_destroy_display(display);
    }
    return 0;
}

int aloha_get_new_display_flags(void) {
    int flags = 0;
    flags = al_get_new_display_flags();
    return flags;
}

EXPORT int lua_get_new_display_flags(lua_State* ls) {
    int flags = aloha_get_new_display_flags();
    lua_pushnumber(ls, flags);
    return 1;
}

void aloha_set_new_display_flags(int flags) {
    al_set_new_display_flags(flags);
}

EXPORT int lua_set_new_display_flags(lua_State* ls) {
    int flags = 0;
    if (lua_isnumber(ls, 1)) {
        flags = lua_tonumber(ls, 1);
        aloha_set_new_display_flags(flags);
    }
    return 0;
}
