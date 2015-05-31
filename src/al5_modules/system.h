#ifndef __ALOHA_SYSTEM_H
#define __ALOHA_SYSTEM_H

#include <lua.h>
#include <allegro5/allegro.h>
#include "../aloha/defs.h"

void aloha_init();
EXPORT int lua_init(lua_State* ls);
void aloha_uninstall_system();
EXPORT int lua_uninstall_system(lua_State* ls);
u_int32_t aloha_get_allegro_version(void);
EXPORT int lua_get_allegro_version(lua_State* ls);
unsigned char aloha_is_system_installed(void);
EXPORT int lua_is_system_installed(lua_State* ls);
ALLEGRO_PATH* aloha_get_standard_path(int id);
EXPORT int lua_get_standard_path(lua_State* ls);
void aloha_set_exe_name(const char* name);
EXPORT int lua_set_exe_name(lua_State* ls);
void aloha_set_app_name(const char* name);
EXPORT int lua_set_app_name(lua_State* ls);
void aloha_set_org_name(const char* name);
EXPORT int lua_set_org_name(lua_State* ls);
const char* aloha_get_app_name(void);
EXPORT int lua_get_app_name(lua_State* ls);
const char* aloha_get_org_name(void);
EXPORT int lua_get_org_name(lua_State* ls);
ALLEGRO_CONFIG* aloha_get_system_config(void);
EXPORT int lua_get_system_config(lua_State* ls);

#endif
