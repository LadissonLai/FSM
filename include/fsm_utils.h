#pragma once
#include <iostream>
#include <typeinfo>
#include <cxxabi.h>
#include <string>

// 辅助函数，用于去除名字修饰
static std::string demangle(const char *mangled_name)
{
    int status = 0;
    char *demangled = abi::__cxa_demangle(mangled_name, nullptr, nullptr, &status);
    std::string result(demangled ? demangled : mangled_name);
    free(demangled);
    return result;
}

template <typename T>
std::string get_type_name()
{
    return demangle(typeid(T).name()); // 返回类的名字
}