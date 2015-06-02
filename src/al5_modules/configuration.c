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
    const char* filename = NULL;
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

unsigned char aloha_save_config_file(const char* filename, ALLEGRO_CONFIG* config) {
    unsigned char result = al_save_config_file(filename, config);
    return result;
}

EXPORT int lua_save_config_file(lua_State* ls) {
    const char* filename = NULL;
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

unsigned char aloha_save_config_file_f(ALLEGRO_FILE* file, ALLEGRO_CONFIG* config) {
    unsigned char result = 0;
    result = al_save_config_file_f(file, config);
    return result;
}

EXPORT int lua_save_config_file_f(lua_State* ls) {
    ALLEGRO_FILE* file = NULL;
    ALLEGRO_CONFIG* config = NULL;
    unsigned char result = 0;

    if (lua_islightuserdata(ls, 1) && lua_islightuserdata(ls, 2)) {
        file = lua_touserdata(ls, 1);
        config = lua_touserdata(ls, 2);
        result = aloha_save_config_file_f(file, config);
    }
    lua_pushboolean(ls, result);
    return 1;
}

void aloha_add_config_section(ALLEGRO_CONFIG* config, const char* name) {
    al_add_config_section(config, name);
}

EXPORT int lua_add_config_section(lua_State* ls) {
    ALLEGRO_CONFIG* config = NULL;
    const char* name = NULL;

    if (lua_islightuserdata(ls, 1) && lua_isstring(ls, 2)) {
        config = lua_touserdata(ls, 1);
        name = lua_tostring(ls, 2);
        aloha_add_config_section(config, name);
    }
    return 0;
}

unsigned char aloha_remove_config_section(ALLEGRO_CONFIG* config, char const* section) {
    unsigned char result = 0;
    result = al_remove_config_section(config, section);
    return result;
}

EXPORT int lua_remove_config_section(lua_State* ls) {
    ALLEGRO_CONFIG* config = NULL;
    const char* section = NULL;
    unsigned char result = 0;
    if (lua_islightuserdata(ls, 1) && lua_isstring(ls, 2)) {
        config = lua_touserdata(ls, 1);
        section = lua_tostring(ls, 2);
        result = aloha_remove_config_section(config, section);
    }
    lua_pushboolean(ls, result);
    return 1;
}

void aloha_add_config_comment(ALLEGRO_CONFIG* config, const char* section, const char* comment) {
    al_add_config_comment(config, section, comment);
}

EXPORT int lua_add_config_comment(lua_State* ls) {
    ALLEGRO_CONFIG* config = NULL;
    const char* section = NULL;
    const char* comment = NULL;

    if (lua_islightuserdata(ls, 1) && lua_isstring(ls, 2) && lua_isstring(ls, 3)) {
        config = lua_touserdata(ls, 1);
        section = lua_tostring(ls, 2);
        comment = lua_tostring(ls, 3);
        aloha_add_config_comment(config, section, comment);
    }
    return 0;
}

const char* aloha_get_config_value(ALLEGRO_CONFIG* config, const char* section, const char* key) {
    const char* value = NULL;
    value = aloha_get_config_value(config, section, key);
    return value;
}

EXPORT int lua_get_config_value(lua_State* ls) {
    const char* value = NULL;
    ALLEGRO_CONFIG* config = NULL;
    const char* section = NULL;
    const char* key = NULL;

    if (lua_islightuserdata(ls, 1) && lua_isstring(ls, 2) && lua_isstring(ls, 3)) {
        config = lua_touserdata(ls, 1);
        section = lua_tostring(ls, 2);
        key = lua_tostring(ls, 3);
        value = aloha_get_config_value(config, section, key);
        lua_pushstring(ls, value);
    } else {
        lua_pushnil(ls);
    }
    return 1;
}

void aloha_set_config_value(ALLEGRO_CONFIG* config, const char* section, const char* key, const char* value) {
    al_set_config_value(config, section, key, value);
}

EXPORT int lua_set_config_value(lua_State* ls) {
    ALLEGRO_CONFIG* config = NULL;
    const char* section = NULL;
    const char* key = NULL;
    const char* value = NULL;

    if (lua_islightuserdata(ls, 1) && lua_isstring(ls, 2) && lua_isstring(ls, 3) && lua_isstring(ls, 4)) {
        config = lua_touserdata(ls, 1);
        section = lua_tostring(ls, 2);
        key = lua_tostring(ls, 3);
        value = lua_tostring(ls, 4);
        aloha_set_config_value(config, section, key, value);
    }
    return 0;
}

unsigned char aloha_remove_config_key(ALLEGRO_CONFIG* config, char const* section, char const* key) {
    unsigned char result = 0;
    result = al_remove_config_key(config, section, key);
    return result;
}

EXPORT int lua_remove_config_key(lua_State* ls) {
    ALLEGRO_CONFIG* config = NULL;
    const char* section = NULL;
    const char* key = NULL;
    unsigned char result = 0;

    if (lua_islightuserdata(ls, 1) && lua_isstring(ls, 2) && lua_isstring(ls, 3)) {
        config = lua_touserdata(ls, 1);
        section = lua_tostring(ls, 2);
        key = lua_tostring(ls, 3);
        result = aloha_remove_config_key(config, section, key);
    }
    lua_pushboolean(ls, result);
    return 1;
}

// TODO: Finish this
char const* aloha_get_first_config_section(ALLEGRO_CONFIG* config, ALLEGRO_CONFIG_SECTION **iterator) {
    return NULL;
}

// TODO: Finish this
EXPORT int lua_get_first_config_section(lua_State* ls) {
    return 0;
}

// TODO: Finish this
char const* aloha_get_next_config_entry(ALLEGRO_CONFIG_ENTRY **iterator) {
    return NULL;
}

// TODO: Finish this
EXPORT int lua_get_next_config_entry(lua_State* ls) {
    return 0;
}

ALLEGRO_CONFIG* aloha_merge_config(ALLEGRO_CONFIG* cfg1, ALLEGRO_CONFIG* cfg2) {
    ALLEGRO_CONFIG* config = NULL;
    config = al_merge_config(cfg1, cfg2);
    return config;
}

EXPORT int lua_merge_config(lua_State* ls) {
    ALLEGRO_CONFIG* config = NULL;
    ALLEGRO_CONFIG* cfg1 = NULL;
    ALLEGRO_CONFIG* cfg2 = NULL;

    if (lua_islightuserdata(ls, 1) && lua_islightuserdata(ls, 2)) {
        cfg1 = lua_touserdata(ls, 1);
        cfg2 = lua_touserdata(ls, 2);
        config = aloha_merge_config(cfg1, cfg2);
        lua_pushlightuserdata(ls, config);
    } else {
        lua_pushnil(ls);
    }
    return 1;
}

void aloha_merge_config_into(ALLEGRO_CONFIG* master, ALLEGRO_CONFIG* add) {
    al_merge_config_into(master, add);
}

EXPORT int lua_merge_config_into(lua_State* ls) {
    ALLEGRO_CONFIG* master = NULL;
    ALLEGRO_CONFIG* add = NULL;

    if (lua_islightuserdata(ls, 1) && lua_islightuserdata(ls, 2)) {
        master = lua_touserdata(ls, 1);
        add = lua_touserdata(ls, 2);
        aloha_merge_config_into(master, add);
    }
    return 0;
}
