#pragma once

#include <lauxlib.h>
#include <lua.h>
#include <stdbool.h>

#include "nvim/api/private/helpers.h"
#include "nvim/cmdexpand_defs.h"  // IWYU pragma: keep
#include "nvim/ex_cmds_defs.h"  // IWYU pragma: keep
#include "nvim/func_attr.h"
#include "nvim/macros_defs.h"
#include "nvim/map_defs.h"
#include "nvim/types_defs.h"
#include "nvim/usercmd.h"  // IWYU pragma: keep

// Generated by msgpack-gen.lua
void nlua_add_api_functions(lua_State *lstate) REAL_FATTR_NONNULL_ALL;

typedef struct {
  LuaRef nil_ref;
  LuaRef empty_dict_ref;
  int ref_count;
#if __has_feature(address_sanitizer)
  PMap(int) ref_markers;
#endif
} nlua_ref_state_t;

#define NLUA_EXEC_STATIC(cstr, arg, err) nlua_exec(STATIC_CSTR_AS_STRING(cstr), arg, err)

#define NLUA_CLEAR_REF(x) \
  do { \
    /* Take the address to avoid double evaluation. #1375 */ \
    if ((x) != LUA_NOREF) { \
      api_free_luaref(x); \
      (x) = LUA_NOREF; \
    } \
  } while (0)

#ifdef INCLUDE_GENERATED_DECLARATIONS
# include "lua/executor.h.generated.h"
#endif

EXTERN nlua_ref_state_t *nlua_global_refs INIT( = NULL);
EXTERN bool nlua_disable_preload INIT( = false);
