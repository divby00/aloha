#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include "al5_modules/system.h"

static const luaL_Reg aloha_lib[] = {
    {"init", lua_init},
    {"uninstall_system", lua_uninstall_system},
    {"get_allegro_version", lua_get_allegro_version},
    {"is_system_installed", lua_is_system_installed},
    {"get_standard_path", lua_get_standard_path},
    {"set_exe_name", lua_set_exe_name},
    {"set_app_name", lua_set_app_name},
    {"set_org_name", lua_set_org_name},
    {"get_app_name", lua_get_app_name},
    {"get_org_name", lua_get_org_name},
    {"get_system_config", lua_get_system_config},
    {"RESOURCES_PATH", NULL},
    {"TEMP_PATH", NULL},
    {"USER_HOME_PATH", NULL},
    {"USER_DATA_PATH", NULL},
    {"USER_DOCUMENTS_PATH", NULL},
    {"USER_SETTINGS_PATH", NULL},
    {"EXENAME_PATH", NULL},
    {NULL, NULL}
};

LUAMOD_API int luaopen_aloha(lua_State* ls) {
    if (ls != NULL) {
        luaL_newlib(ls, aloha_lib);
        lua_pushnumber(ls, ALLEGRO_RESOURCES_PATH);
        lua_setfield(ls, -2, "RESOURCES_PATH");
        lua_pushnumber(ls, ALLEGRO_TEMP_PATH);
        lua_setfield(ls, -2, "TEMP_PATH");
        lua_pushnumber(ls, ALLEGRO_USER_HOME_PATH);
        lua_setfield(ls, -2, "USER_HOME_PATH");
        lua_pushnumber(ls, ALLEGRO_USER_DATA_PATH);
        lua_setfield(ls, -2, "USER_DATA_PATH");
        lua_pushnumber(ls, ALLEGRO_USER_DOCUMENTS_PATH);
        lua_setfield(ls, -2, "USER_DOCUMENTS_PATH");
        lua_pushnumber(ls, ALLEGRO_USER_SETTINGS_PATH);
        lua_setfield(ls, -2, "USER_SETTINGS_PATH");
        lua_pushnumber(ls, ALLEGRO_EXENAME_PATH);
        lua_setfield(ls, -2, "EXENAME_PATH");
    } else {
        fprintf(stdout, "Invalid Lua handler");
        return 0;
    }
    return 1;
}

int main(void) {
    int status = 0;
    lua_State* ls = NULL;
    ls=luaL_newstate();
    luaL_openlibs(ls);
    status = luaL_dofile(ls, "lua/example01.lua");
    if (status) {
        fprintf(stdout, "\nError");
    }
    lua_close(ls);
    return 0;
}
