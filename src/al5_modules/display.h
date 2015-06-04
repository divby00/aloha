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
int aloha_get_new_display_option(int option, int* importance);
EXPORT int lua_get_new_display_option(lua_State* ls);
void aloha_set_new_display_option(int option, int value, int importance);
EXPORT int lua_set_new_display_option(lua_State* ls);
void aloha_reset_new_display_options(void);
EXPORT int lua_reset_new_display_option(lua_State* ls);
void aloha_get_new_window_position(int* x, int* y);
EXPORT int lua_get_new_window_position(lua_State* ls);
void aloha_set_new_window_position(int x, int y);
EXPORT int lua_set_new_window_position(lua_State* ls);
int aloha_get_new_display_refresh_rate(void);
EXPORT int lua_get_new_display_refresh_rate(lua_State* ls);
void aloha_set_new_display_refresh_rate(int refresh_rate);
EXPORT int lua_set_new_display_refresh_rate(lua_State* ls);
void aloha_flip_display(void);
EXPORT int lua_flip_display(lua_State* ls);
ALLEGRO_EVENT_SOURCE* aloha_get_display_event_source(ALLEGRO_DISPLAY* display);
EXPORT int lua_get_display_event_source(lua_State* ls);
ALLEGRO_BITMAP* aloha_get_backbuffer(ALLEGRO_DISPLAY* display);
EXPORT int lua_get_backbuffer(lua_State* ls);
void aloha_update_display_region(int x, int y, int width, int height);
EXPORT int lua_update_display_region(lua_State* ls);
unsigned char aloha_wait_for_vsync(void);
EXPORT int lua_wait_for_sync(lua_State* ls);
int aloha_get_display_width(ALLEGRO_DISPLAY* display);
EXPORT int lua_get_display_width(lua_State* ls);
int aloha_get_display_height(ALLEGRO_DISPLAY* display);
EXPORT int lua_get_display_height(lua_State* ls);
unsigned char aloha_resize_display(ALLEGRO_DISPLAY* display, int width, int height);
EXPORT int lua_resize_display(lua_State* ls);
unsigned char aloha_acknowledge_resize(ALLEGRO_DISPLAY* display);
EXPORT int lua_acknowledge_resize(lua_State* ls);

#endif

















