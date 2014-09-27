// luatinkerEx.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};

#include "lua_tinker.h"

#pragma comment(lib, "liblua.lib")

int cpp_func(int arg1, int arg2)
{
	return arg1 + arg2;
}

int main()
{
	// Lua �� �ʱ�ȭ �Ѵ�.
	lua_State* L = luaL_newstate();

	// Lua �⺻ �Լ����� �ε��Ѵ�.- print() ���
	luaopen_base(L);

	// LuaTinker �� �̿��ؼ� �Լ��� ����Ѵ�.
	lua_tinker::def(L, "cpp_func", cpp_func);

	// sample1.lua ������ �ε�/�����Ѵ�.
	lua_tinker::dofile(L, "sample1.lua");

	// sample1.lua �� �Լ��� ȣ���Ѵ�.
	int result = lua_tinker::call<int>(L, "lua_func", 3, 4);

	// lua_func(3,4) �� ����� ���
	printf("lua_func(3,4) = %d\n", result);

	// ���α׷� ����
	lua_close(L);

	return 0;
}