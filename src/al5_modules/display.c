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

int aloha_get_new_display_option(int option, int* importance) {
    int display_option = 0;
    display_option = al_get_new_display_option(option, importance);
    return display_option;
}

EXPORT int lua_get_new_display_option(lua_State* ls) {
    int option = 0;
    int display_option = 0;
    int* importance = NULL;

    if (lua_isnumber(ls, 1) && lua_islightuserdata(ls, 2)) {
        option = lua_tonumber(ls, 1);
        importance = lua_touserdata(ls, 2);
        display_option = aloha_get_new_display_option(option, importance);
    }
    lua_pushnumber(ls, display_option);
    return 1;
}

void aloha_set_new_display_option(int option, int value, int importance) {
    al_set_new_display_option(option, value, importance);
}

EXPORT int lua_set_new_display_option(lua_State* ls) {
    int option, value, importance = 0;

    if (lua_isnumber(ls, 1) && lua_isnumber(ls, 2) && lua_isnumber(ls, 3)) {
        option = lua_tonumber(ls, 1);
        value = lua_tonumber(ls, 2);
        importance = lua_tonumber(ls, 3);
        aloha_set_new_display_option(option, value, importance);
    }
    return 0;
}

void aloha_reset_new_display_options(void) {
    al_reset_new_display_options();
}

EXPORT int lua_reset_new_display_option(lua_State* ls) {
    aloha_reset_new_display_options();
    return 0;
}

void aloha_get_new_window_position(int* x, int* y) {
    al_get_new_window_position(x, y);
}

EXPORT int lua_get_new_window_position(lua_State* ls) {
    int a, b = 0;
    int* x = &a;
    int* y = &b;
    aloha_get_new_window_position(x, y);
    lua_pushnumber(ls, *x);
    lua_pushnumber(ls, *y);
    return 2;
}

void aloha_set_new_window_position(int x, int y) {
    al_set_new_window_position(x, y);
}

EXPORT int lua_set_new_window_position(lua_State* ls) {
    int x, y = 0;

    if (lua_isnumber(ls, 1) && lua_isnumber(ls, 2)) {
        x = lua_tonumber(ls, 1);
        y = lua_tonumber(ls, 2);
        aloha_set_new_window_position(x, y);
    }
    return 0;
}

int aloha_get_new_display_refresh_rate(void) {
    int refresh_rate = 0;
    refresh_rate = al_get_new_display_refresh_rate();
    return refresh_rate;
}

EXPORT int lua_get_new_display_refresh_rate(lua_State* ls) {
    int refresh_rate = 0;
    refresh_rate = aloha_get_new_display_refresh_rate();
    lua_pushnumber(ls, refresh_rate);
    return 1;
}

void aloha_set_new_display_refresh_rate(int refresh_rate) {
    al_set_new_display_refresh_rate(refresh_rate);
}

EXPORT int lua_set_new_display_refresh_rate(lua_State* ls) {
    int refresh_rate = 0;

    if (lua_isnumber(ls, 1)) {
        refresh_rate = lua_tonumber(ls, 1);
        aloha_set_new_display_refresh_rate(refresh_rate);
    }
    return 0;
}

ALLEGRO_EVENT_SOURCE* aloha_get_display_event_source(ALLEGRO_DISPLAY* display) {
    ALLEGRO_EVENT_SOURCE* source = NULL;
    source = al_get_display_event_source(display);
    return source;
}

EXPORT int lua_get_display_event_source(lua_State* ls) {
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_SOURCE* source = NULL;

    if (lua_islightuserdata(ls, 1)) {
        display = lua_touserdata(ls, 1);
        source = aloha_get_display_event_source(display);
    }
    return source;
}

ALLEGRO_BITMAP* aloha_get_backbuffer(ALLEGRO_DISPLAY* display) {
    ALLEGRO_BITMAP* backbuffer = NULL;
    backbuffer = al_get_backbuffer(display);
    return backbuffer;
}

EXPORT int lua_get_backbuffer(lua_State* ls) {
    ALLEGRO_BITMAP* backbuffer = NULL;
    ALLEGRO_DISPLAY* display = NULL;

    if (lua_islightuserdata(ls, 1)) {
        display = lua_touserdata(ls, 1);
        backbuffer = aloha_get_backbuffer(display);
        lua_pushlightuserdata(ls, backbuffer);
    } else {
        lua_pushnil(ls);
    }
    return 1;
}

void aloha_flip_display(void) {
    al_flip_display();
}

EXPORT int lua_flip_display(lua_State* ls) {
    ls = ls;
    aloha_flip_display();
    return 0;
}

void aloha_update_display_region(int x, int y, int width, int height) {
    al_update_display_region(x, y, width, height);
}

EXPORT int lua_update_display_region(lua_State* ls) {
    int x, y, width, height = 0;

    if (lua_isnumber(ls, 1) && lua_isnumber(ls, 2) && lua_isnumber(ls, 3) && lua_isnumber(ls, 4)) {
        x = lua_tonumber(ls, 1);
        y = lua_tonumber(ls, 2);
        width = lua_tonumber(ls, 3);
        height = lua_tonumber(ls, 4);
        aloha_update_display_region(x, y, width, height);
    }
    return 0;
}

unsigned char aloha_wait_for_vsync(void) {
    unsigned char wait = 0;
    wait = al_wait_for_vsync();
    return wait;
}

EXPORT int lua_wait_for_sync(lua_State* ls) {
    unsigned char wait = 0;
    wait = aloha_wait_for_vsync();
    lua_pushnumber(ls, wait);
    return 1;
}

int aloha_get_display_width(ALLEGRO_DISPLAY* display) {
    int width = al_get_display_width(display);
    return width;
}

EXPORT int lua_get_display_width(lua_State* ls) {
    int width = 0;
    ALLEGRO_DISPLAY* display = NULL;

    if (lua_islightuserdata(ls, 1)) {
        display = lua_touserdata(ls, 1);
        width = aloha_get_display_width(display);
    }
    lua_pushnumber(ls, width);
    return 1;
}

int aloha_get_display_height(ALLEGRO_DISPLAY* display) {
    int height = al_get_display_height(display);
    return height;
}

EXPORT int lua_get_display_height(lua_State* ls) {
    int height = 0;
    ALLEGRO_DISPLAY* display = NULL;

    if (lua_islightuserdata(ls, 1)) {
        display = lua_touserdata(ls, 1);
        height = aloha_get_display_height(display);
    }
    lua_pushnumber(ls, height);
    return 1;
}

unsigned char aloha_resize_display(ALLEGRO_DISPLAY *display, int width, int height) {
    unsigned char result = 0;
    result = al_resize_display(display, width, height);
    return result;
}

EXPORT int lua_resize_display(lua_State* ls) {
    ALLEGRO_DISPLAY* display = NULL;
    unsigned char result = 0;
    int width, height = 0;

    if (lua_islightuserdata(ls, 1) && lua_isnumber(ls, 2) && lua_isnumber(ls, 3)) {
        display = lua_touserdata(ls, 1);
        width = lua_tonumber(ls, 2);
        height = lua_tonumber(ls, 3);
        result = aloha_resize_display(display, width, height);
    }
    lua_pushnumber(ls, result);
    return 1;
}

unsigned char aloha_acknowledge_resize(ALLEGRO_DISPLAY* display) {
    unsigned char result = 0;
    result = al_acknowledge_resize(display);
    return result;
}

EXPORT int lua_acknowledge_resize(lua_State* ls) {
    ALLEGRO_DISPLAY* display = NULL;
    unsigned char result = 0;

    if (lua_islightuserdata(ls, 1)) {
        display = lua_touserdata(ls, 1);
        result = aloha_acknowledge_resize(display);
    }
    lua_pushnumber(ls, result);
    return 1;
}

void aloha_get_window_position(ALLEGRO_DISPLAY* display, int* x, int* y) {
    al_get_window_position(display, x, y);
}

EXPORT int lua_get_window_position(lua_State* ls) {
    int x, y = 0;
    ALLEGRO_DISPLAY* display = NULL;

    if (lua_islightuserdata(ls, 1)) {
        display = lua_touserdata(ls, 1);
        aloha_get_window_position(display, &x, &y);
    }
    lua_pushnumber(ls, x);
    lua_pushnumber(ls, y);
    return 2;
}

void aloha_set_window_position(ALLEGRO_DISPLAY* display, int x, int y) {
    al_set_window_position(display, x, y);
}

EXPORT int lua_set_window_position(lua_State* ls) {
    ALLEGRO_DISPLAY* display = NULL;
    int x, y = 0;
    if (lua_islightuserdata(ls, 1) && lua_isnumber(ls, 2) && lua_isnumber(ls, 3)) {
        display = lua_touserdata(ls, 1);
        x = lua_tonumber(ls, 2);
        y = lua_tonumber(ls, 3);
        aloha_set_window_position(display, x, y);
    }
    return 0;
}

unsigned char aloha_get_window_constraints(ALLEGRO_DISPLAY* display, int* min_w, int* min_h, int* max_w, int* max_h) {
    unsigned char result = 0;
    result = al_get_window_constraints(display, min_w, min_h, max_w, max_h);
    return result;
}

EXPORT int lua_get_window_constraints(lua_State* ls) {
    ALLEGRO_DISPLAY* display = NULL;
    int min_w, min_h, max_w, max_h = 0;

    if (lua_islightuserdata(ls, 1)) {
        display = lua_touserdata(ls, 1);
        aloha_get_window_constraints(display, &min_w, &min_h, &max_w, &max_h);
    }
    lua_pushnumber(ls, min_w);
    lua_pushnumber(ls, min_h);
    lua_pushnumber(ls, max_w);
    lua_pushnumber(ls, max_h);
    return 4;
}

unsigned char aloha_set_window_constraints(ALLEGRO_DISPLAY* display, int min_w, int min_h, int max_w, int max_h) {
    unsigned char result = 0;
    result = al_set_window_constraints(display, min_w, min_h, max_w, max_h);
    return result;
}

EXPORT int lua_set_window_constraints(lua_State* ls) {
    ALLEGRO_DISPLAY* display = NULL;
    int min_w, min_h, max_w, max_h = 0;
    unsigned char result = 0;

    if (lua_islightuserdata(ls, 1) && lua_isnumber(ls, 2) && lua_isnumber(ls, 3) && lua_isnumber(ls, 4) && lua_isnumber(ls, 5)) {
        display = lua_touserdata(ls, 1);
        min_w = lua_tonumber(ls, 2);
        min_h = lua_tonumber(ls, 3);
        max_w = lua_tonumber(ls, 4);
        max_h = lua_tonumber(ls, 5);
        result = aloha_set_window_constraints(display, min_w, min_h, max_w, max_h);
    }
    lua_pushnumber(ls, result);
    return 1;
}

int aloha_get_display_flags(ALLEGRO_DISPLAY* display) {
    int flags = 0;
    flags = al_get_display_flags(display);
    return flags;
}

EXPORT int lua_get_display_flags(lua_State* ls) {
    int flags = 0;
    ALLEGRO_DISPLAY* display = NULL;

    if (lua_islightuserdata(ls, 1)) {
        display = lua_touserdata(ls, 1);
        flags = aloha_get_display_flags(display);
    }
    lua_pushnumber(ls, flags);
    return 1;
}

unsigned char aloha_set_display_flag(ALLEGRO_DISPLAY* display, int flag, unsigned char onoff) {
    unsigned char result = 0;
    result = al_set_display_flag(display, flag, onoff);
    return result;

}

EXPORT int lua_set_display_flag(lua_State* ls) {
    ALLEGRO_DISPLAY* display = NULL;
    int flag = 0;
    unsigned char onoff = 0;
    unsigned char result = 0;

    if (lua_islightuserdata(ls, 1) && lua_isnumber(ls, 2) && lua_isnumber(ls, 3)) {
        display = lua_touserdata(ls, 1);
        flag = lua_tonumber(ls, 2);
        onoff = lua_tonumber(ls, 3);
        result = aloha_set_display_flag(display, flag, onoff);
    }
    lua_pushnumber(ls, result);
    return 1;
}
