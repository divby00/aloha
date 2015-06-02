#include <allegro5/allegro.h>
#include <stdio.h>
#include "system.h"

void aloha_init() {
    al_init();
}

EXPORT int lua_init(lua_State* ls) {
    aloha_init();
    ls = ls;
    return 0;
}

void aloha_uninstall_system() {
    al_uninstall_system();
}

EXPORT int lua_uninstall_system(lua_State* ls) {
    aloha_uninstall_system();
    ls = ls;
    return 0;
}

u_int32_t aloha_get_allegro_version(void) {
    u_int32_t version = al_get_allegro_version();
    return version;
}

EXPORT int lua_get_allegro_version(lua_State* ls) {
    u_int32_t version = aloha_get_allegro_version();
    int major = version >> 24;
    int minor = (version >> 16) & 255;
    int revision = (version >> 8) & 255;
    int release = version & 255;
    lua_pushnumber(ls, major);
    lua_pushnumber(ls, minor);
    lua_pushnumber(ls, revision);
    lua_pushnumber(ls, release);
    return 4;
}

unsigned char aloha_is_system_installed(void) {
    unsigned char is_installed = al_is_system_installed();
    return is_installed;
}

EXPORT int lua_is_system_installed(lua_State* ls) {
    unsigned char is_installed = aloha_is_system_installed();
    lua_pushboolean(ls, is_installed);
    return 1;
}

ALLEGRO_PATH* aloha_get_standard_path(int id) {
    ALLEGRO_PATH* path = NULL;
    path = al_get_standard_path(id);
    return path;
}

EXPORT int lua_get_standard_path(lua_State* ls) {
    ALLEGRO_PATH* path = NULL;
    int id = -1;
    if (lua_isnumber(ls, 1)) {
        id = lua_tonumber(ls, 1);
    }
    path = aloha_get_standard_path(id);
    lua_pushlightuserdata(ls, path);
    return 1;
}

void aloha_set_exe_name(const char* name) {
    al_set_exe_name(name);
}

EXPORT int lua_set_exe_name(lua_State* ls) {
    const char* name = NULL;
    if (lua_isstring(ls, 1)) {
        name = lua_tostring(ls, 1);
        aloha_set_exe_name(name);
    }
    return 0;
}

void aloha_set_app_name(const char* name) {
    al_set_app_name(name);
}

EXPORT int lua_set_app_name(lua_State* ls) {
    const char* name = NULL;
    if (lua_isstring(ls, 1)) {
        name = lua_tostring(ls, 1);
        aloha_set_app_name(name);
    }
    return 0;
}

void aloha_set_org_name(const char* name) {
    al_set_org_name(name);
}

EXPORT int lua_set_org_name(lua_State* ls) {
    const char* name = NULL;
    if (lua_isstring(ls, 1)) {
        name = lua_tostring(ls, 1);
        aloha_set_org_name(name);
    }
    return 0;
}

const char* aloha_get_app_name(void) {
    const char* name = al_get_app_name();
    return name;
}

EXPORT int lua_get_app_name(lua_State* ls) {
    const char* name = NULL;
    name = aloha_get_app_name();
    lua_pushstring(ls, name);
    return 1;
}

const char* aloha_get_org_name(void) {
    const char* name = al_get_org_name();
    return name;
}

EXPORT int lua_get_org_name(lua_State* ls) {
    const char* name = NULL;
    name = aloha_get_org_name();
    lua_pushstring(ls, name);
    return 1;
}

ALLEGRO_CONFIG* aloha_get_system_config(void) {
    ALLEGRO_CONFIG* config = al_get_system_config();
    return config;
}

EXPORT int lua_get_system_config(lua_State* ls) {
    ALLEGRO_CONFIG* config = aloha_get_system_config();
    lua_pushlightuserdata(ls, config);
    return 1;
}
