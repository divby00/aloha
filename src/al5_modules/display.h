#ifndef __ALOHA_DISPLAY_H
#define __ALOHA_DISPLAY_H

#include <lua.h>
#include <allegro5/allegro.h>
#include "../aloha/defs.h"

ALLEGRO_DISPLAY* aloha_create_display(unsigned int w, unsigned int h);
EXPORT int lua_create_display(lua_State* ls);
void aloha_destroy_display(ALLEGRO_DISPLAY* display);
EXPORT int lua_destroy_display(lua_State* ls);
int aloha_get_new_display_flags(void);
EXPORT int lua_get_new_display_flags(lua_State* ls);
void aloha_set_new_display_flags(int flags);
EXPORT int lua_set_new_display_flags(lua_State* ls);

#endif
