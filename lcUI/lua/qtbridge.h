#pragma once

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "lua-intf/LuaIntf/LuaIntf.h"

#include <QObject>
#include <QMetaObject>
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QDockWidget>
#include <QString>
#include <QMenuBar>
#include <QAction>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QFileDialog>

#include "cadmdichild.h"
#include "documentcanvas.h"
#include "lcadviewer.h"
#include "ui/luascript.h"

#include "luainterface.h"
#include "luaqobject.h"

void luaOpenQtBridge(lua_State *L);

void addQtBaseBindings(lua_State *L);
void addQtWindowBindings(lua_State *L);
void addQtLayoutBindings(lua_State *L);
void addQtWidgetsBindings(lua_State *L);
void addLCBindings(lua_State *L);