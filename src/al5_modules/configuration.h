#ifndef __ALOHA_CONFIGURATION_H
#define __ALOHA_CONFIGURATION_H

#include <lua.h>
#include <allegro5/allegro.h>
#include "../aloha/defs.h"

ALLEGRO_CONFIG* aloha_create_config(void);
EXPORT int lua_create_config(lua_State* ls);
void aloha_destroy_config(ALLEGRO_CONFIG* config);
EXPORT int lua_destroy_config(lua_State* ls);
ALLEGRO_CONFIG* aloha_load_config_file(const char* filename);
EXPORT int lua_load_config_file(lua_State* ls);
ALLEGRO_CONFIG *aloha_load_config_file_f(ALLEGRO_FILE* file);
EXPORT int lua_load_config_file_f(lua_State* ls);
unsigned char aloha_save_config_file(const char* filename, ALLEGRO_CONFIG* config);
EXPORT int lua_save_config_file(lua_State* ls);
unsigned char aloha_save_config_file_f(ALLEGRO_FILE* file, ALLEGRO_CONFIG* config);
EXPORT int lua_save_config_file_f(lua_State* ls);
void aloha_add_config_section(ALLEGRO_CONFIG* config, const char* name);
EXPORT int lua_add_config_section(lua_State* ls);
unsigned char aloha_remove_config_section(ALLEGRO_CONFIG* config, char const* section);
EXPORT int lua_remove_config_section(lua_State* ls);
void aloha_add_config_comment(ALLEGRO_CONFIG* config, const char* section, const char* comment);
EXPORT int lua_add_config_comment(lua_State* ls);
const char* aloha_get_config_value(ALLEGRO_CONFIG* config, const char* section, const char* key);
EXPORT int lua_get_config_value(lua_State* ls);
void aloha_set_config_value(ALLEGRO_CONFIG* config, const char* section, const char* key, const char* value);
EXPORT int lua_set_config_value(lua_State* ls);
unsigned char aloha_remove_config_key(ALLEGRO_CONFIG* config, char const* section, char const* key);
EXPORT int lua_remove_config_key(lua_State* ls);
char const* aloha_get_first_config_section(ALLEGRO_CONFIG* config, ALLEGRO_CONFIG_SECTION **iterator);
EXPORT int lua_get_first_config_section(lua_State* ls);
char const* aloha_get_next_config_entry(ALLEGRO_CONFIG_ENTRY **iterator);
EXPORT int lua_get_next_config_entry(lua_State* ls);
ALLEGRO_CONFIG* aloha_merge_config(ALLEGRO_CONFIG* cfg1, ALLEGRO_CONFIG* cfg2);
EXPORT int lua_merge_config(lua_State* ls);
void aloha_merge_config_into(ALLEGRO_CONFIG* master, ALLEGRO_CONFIG* add);
EXPORT int lua_merge_config_into(lua_State* ls);

#endif
