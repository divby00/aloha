#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include "al5_modules/system.h"
#include "al5_modules/configuration.h"
#include "al5_modules/display.h"

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
    {"create_config", lua_create_config},
    {"destroy_config", lua_destroy_config},
    {"load_config_file", lua_load_config_file},
    {"load_config_file_f", lua_load_config_file_f},
    {"save_config_file", lua_save_config_file},
    {"save_config_file_f", lua_save_config_file_f},
    {"add_config_section", lua_add_config_section},
    {"remove_config_section", lua_remove_config_section},
    {"add_config_comment", lua_add_config_comment},
    {"get_config_value", lua_get_config_value},
    {"set_config_value", lua_set_config_value},
    {"remove_config_key", lua_remove_config_key},
    {"get_first_config_section", lua_get_first_config_section},
    {"get_next_config_entry", lua_get_next_config_entry},
    {"merge_config", lua_merge_config},
    {"merge_config_into", lua_merge_config_into},
    {"create_display", lua_create_display},
    {"destroy_display", lua_destroy_display},
    {"get_new_display_flags", lua_get_new_display_flags},
    {"set_new_display_flags", lua_set_new_display_flags},
    {"get_new_window_position", lua_get_new_window_position},
    {"set_new_window_position", lua_set_new_window_position},
    /* Constants from module system */
    {"RESOURCES_PATH", NULL},
    {"TEMP_PATH", NULL},
    {"USER_HOME_PATH", NULL},
    {"USER_DATA_PATH", NULL},
    {"USER_DOCUMENTS_PATH", NULL},
    {"USER_SETTINGS_PATH", NULL},
    {"EXENAME_PATH", NULL},
    /* Constants from module display */
    {"WINDOWED", NULL},
    {"FULLSCREEN", NULL},
    {"FULLSCREEN_WINDOW", NULL},
    {"RESIZABLE", NULL},
    {"OPENGL", NULL},
    {"OPENGL_3_0", NULL},
    {"OPENGL_FORWARD_COMPATIBLE", NULL},
    {"DIRECT3D_INTERNAL", NULL},
    {"PROGRAMMABLE_PIPELINE", NULL},
    {"FRAMELESS", NULL},
    {"NOFRAME", NULL},
    {"GENERATE_EXPOSE_EVENTS", NULL},
    {"GTK_TOPLEVEL_INTERNAL", NULL},
    {NULL, NULL}
};

LUAMOD_API int luaopen_aloha(lua_State* ls) {
    if (ls != NULL) {
        luaL_newlib(ls, aloha_lib);
        /* Constants from system module */
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

        /* Constants from display module */
        lua_pushnumber(ls, ALLEGRO_WINDOWED);
        lua_setfield(ls, -2, "WINDOWED");
        lua_pushnumber(ls, ALLEGRO_FULLSCREEN);
        lua_setfield(ls, -2, "FULLSCREEN");
        lua_pushnumber(ls, ALLEGRO_FULLSCREEN_WINDOW);
        lua_setfield(ls, -2, "FULLSCREEN_WINDOW");
        lua_pushnumber(ls, ALLEGRO_RESIZABLE);
        lua_setfield(ls, -2, "RESIZABLE");
        lua_pushnumber(ls, ALLEGRO_OPENGL);
        lua_setfield(ls, -2, "OPENGL");
        lua_pushnumber(ls, ALLEGRO_OPENGL_3_0);
        lua_setfield(ls, -2, "OPENGL_3_0");
        lua_pushnumber(ls, ALLEGRO_OPENGL_FORWARD_COMPATIBLE);
        lua_setfield(ls, -2, "OPENGL_FORWARD_COMPATIBLE");
        lua_pushnumber(ls, ALLEGRO_DIRECT3D_INTERNAL);
        lua_setfield(ls, -2, "DIRECT3D_INTERNAL");
        lua_pushnumber(ls, ALLEGRO_PROGRAMMABLE_PIPELINE);
        lua_setfield(ls, -2, "PROGRAMMABLE_PIPELINE");
        lua_pushnumber(ls, ALLEGRO_FRAMELESS);
        lua_setfield(ls, -2, "FRAMELESS");
        lua_pushnumber(ls, ALLEGRO_NOFRAME);
        lua_setfield(ls, -2, "NOFRAME");
        lua_pushnumber(ls, ALLEGRO_GENERATE_EXPOSE_EVENTS);
        lua_setfield(ls, -2, "GENERATE_EXPOSE_EVENTS");
        lua_pushnumber(ls, ALLEGRO_GTK_TOPLEVEL_INTERNAL);
        lua_setfield(ls, -2, "GTK_TOPLEVEL_INTERNAL");
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
