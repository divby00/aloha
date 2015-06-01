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
unsigned char aloha_save_config_file(const char* filename, const ALLEGRO_CONFIG* config);
EXPORT int lua_save_config_file(lua_State* ls);
unsigned char aloha_save_config_file_f(const char* filename, const ALLEGRO_CONFIG* config);
EXPORT int lua_save_config_file_f(lua_State* ls);

#endif
