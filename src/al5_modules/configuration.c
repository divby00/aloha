#include "configuration.h"
#include <stdio.h>

ALLEGRO_CONFIG* aloha_create_config(void) {
    ALLEGRO_CONFIG* config = al_create_config();
    return config;
}

EXPORT int lua_create_config(lua_State* ls) {
    ALLEGRO_CONFIG* config = aloha_create_config();
    lua_pushlightuserdata(ls, config);
    return 1;
}

void aloha_destroy_config(ALLEGRO_CONFIG* config) {
    al_destroy_config(config);
}

EXPORT int lua_destroy_config(lua_State* ls) {
    ALLEGRO_CONFIG* config = NULL;
    fprintf(stdout, "\nEn destroy...");
    if (lua_isuserdata(ls, 1)) {
        config = lua_touserdata(ls, 1);
        fprintf(stdout, "\nConfig");
        aloha_destroy_config(config);
    }
    return 0;
}

ALLEGRO_CONFIG* aloha_load_config_file(const char* filename) {
    ALLEGRO_CONFIG* config = al_load_config_file(filename);
    return config;
}

EXPORT int lua_load_config_file(lua_State* ls) {
    char* filename = NULL;
    ALLEGRO_CONFIG* config = NULL;

    if (lua_isstring(ls, 1)) {
        filename = lua_tostring(ls, 1);
        config = aloha_load_config_file(filename);
        lua_pushlightuserdata(ls, config);
    } else {
        lua_pushnil(ls);
    }
    return 1;
}

ALLEGRO_CONFIG *aloha_load_config_file_f(ALLEGRO_FILE* file) {
    ALLEGRO_CONFIG* config = al_load_config_file_f(file);
    return config;
}

EXPORT int lua_load_config_file_f(lua_State* ls) {
    ALLEGRO_CONFIG* config = NULL;
    ALLEGRO_FILE* file = NULL;

    if (lua_isuserdata(ls, 1)) {
        file = lua_touserdata(ls, 1);
        config = aloha_load_config_file_f(file);
        lua_pushlightuserdata(ls, config);
    } else {
        lua_pushnil(ls);
    }
    return 1;
}

unsigned char aloha_save_config_file(const char* filename, const ALLEGRO_CONFIG* config) {
    unsigned char result = al_save_config_file(filename, config);
    return result;
}

EXPORT int lua_save_config_file(lua_State* ls) {
    char* filename = NULL;
    ALLEGRO_CONFIG* config = NULL;
    unsigned char result = 0;

    if (lua_isstring(ls, 1) && lua_islightuserdata(ls, 2)) {
        filename = lua_tostring(ls, 1);
        config = lua_touserdata(ls, 2);
        result = aloha_save_config_file(filename, config);
    }
    lua_pushboolean(ls, result);
    return 1;
}
