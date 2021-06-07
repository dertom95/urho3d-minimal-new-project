/*
** Lua binding: LuaAPI
*/

//
// Copyright (c) 2008-2020 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#include <toluapp/tolua++.h>
#include <Urho3D/LuaScript/ToluaUtils.h>

#if __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
#endif

/* Exported function */
TOLUA_API int tolua_LuaAPI_open (lua_State* tolua_S);

using namespace Urho3D;
#include "../LuaAPI.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_SomeObject (lua_State* tolua_S)
{
 SomeObject* self = (SomeObject*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"SomeObject");
 tolua_usertype(tolua_S,"Node");
 tolua_usertype(tolua_S,"Vector3");
}

/* function: Add */
#ifndef TOLUA_DISABLE_tolua_LuaAPI_Add00
static int tolua_LuaAPI_Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int a = ((int)  tolua_tonumber(tolua_S,1,0));
  int b = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  int tolua_ret = (int)  Add(a,b);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: NodeTranslate */
#ifndef TOLUA_DISABLE_tolua_LuaAPI_NodeTranslate00
static int tolua_LuaAPI_NodeTranslate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Node* node = ((Node*)  tolua_tousertype(tolua_S,1,0));
  Vector3 translate = *((Vector3*)  tolua_tousertype(tolua_S,2,0));
 {
  NodeTranslate(node,translate);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NodeTranslate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SomeObject */
#ifndef TOLUA_DISABLE_tolua_LuaAPI_SomeObject_new00
static int tolua_LuaAPI_SomeObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SomeObject",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int _count = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  SomeObject* tolua_ret = (SomeObject*)  Mtolua_new((SomeObject)(_count));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SomeObject");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SomeObject */
#ifndef TOLUA_DISABLE_tolua_LuaAPI_SomeObject_new00_local
static int tolua_LuaAPI_SomeObject_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SomeObject",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int _count = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  SomeObject* tolua_ret = (SomeObject*)  Mtolua_new((SomeObject)(_count));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SomeObject");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: count of class  SomeObject */
#ifndef TOLUA_DISABLE_tolua_get_SomeObject_count
static int tolua_get_SomeObject_count(lua_State* tolua_S)
{
  SomeObject* self = (SomeObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'count'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->count);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: count of class  SomeObject */
#ifndef TOLUA_DISABLE_tolua_set_SomeObject_count
static int tolua_set_SomeObject_count(lua_State* tolua_S)
{
  SomeObject* self = (SomeObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'count'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->count = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: node of class  SomeObject */
#ifndef TOLUA_DISABLE_tolua_get_SomeObject_node_ptr
static int tolua_get_SomeObject_node_ptr(lua_State* tolua_S)
{
  SomeObject* self = (SomeObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'node'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->node,"Node");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: node of class  SomeObject */
#ifndef TOLUA_DISABLE_tolua_set_SomeObject_node_ptr
static int tolua_set_SomeObject_node_ptr(lua_State* tolua_S)
{
  SomeObject* self = (SomeObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'node'",NULL);
 if (!tolua_isusertype(tolua_S,2,"Node",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->node = ((Node*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_LuaAPI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_function(tolua_S,"Add",tolua_LuaAPI_Add00);
 tolua_function(tolua_S,"NodeTranslate",tolua_LuaAPI_NodeTranslate00);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"SomeObject","SomeObject","",tolua_collect_SomeObject);
 #else
 tolua_cclass(tolua_S,"SomeObject","SomeObject","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"SomeObject");
  tolua_function(tolua_S,"new",tolua_LuaAPI_SomeObject_new00);
  tolua_function(tolua_S,"new_local",tolua_LuaAPI_SomeObject_new00_local);
  tolua_function(tolua_S,".call",tolua_LuaAPI_SomeObject_new00_local);
  tolua_variable(tolua_S,"count",tolua_get_SomeObject_count,tolua_set_SomeObject_count);
  tolua_variable(tolua_S,"node",tolua_get_SomeObject_node_ptr,tolua_set_SomeObject_node_ptr);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_LuaAPI (lua_State* tolua_S) {
 return tolua_LuaAPI_open(tolua_S);
}
#endif

#if __clang__
#pragma clang diagnostic pop
#endif