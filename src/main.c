#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include "al5_modules/system.h"

static const luaL_Reg aloha_lib[] = {
    {"al_init", lua_al_init},
    {NULL, NULL}
};

LUAMOD_API int luaopen_aloha(lua_State* ls) {
    if (ls != NULL) {
        luaL_newlib(ls, aloha_lib);
        return 1;
    } else {
        fprintf(stdout, "Invalid Lua handler");
        return 0;
    }
}

int main(int argc, char **argv) {
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
