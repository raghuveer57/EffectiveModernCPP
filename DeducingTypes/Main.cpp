#include <iostream>
#include "../Utilities/functiondefs.h"

int main()
{
    int x = 27;         // x is int 
    const int cx = x;   // cx is const int
    const int& rx = x;  // rx is const &int
    const int *px = &x; // px is ptr to x as a const int 

    //case1: param type is reference or pointer,
    // but not universal reference
    // 1. If expr's type is ref, ignore ref part while determining T
    // 2. Then pattern match expr's type against ParamType to determine T

    // Since cx and rx are const values, T is deduced to be const int 
    // rx's ref type is ignored while deducing T
    funReference(x);  // T = int, param = int&
    funReference(cx); // T = const int , param = const int&
    funReference(rx); // T = const int , param = const int&

    // Since px is again a const value, T is deduced to be const int
    funPointer(&x); //  T = int, param = int* 
    funPointer(px); //  T = const int, param = const int*

    //case2: param type is univ reference
    // 1. If expr is lvalue, both T and ParamType are deduced to be lvalue refs
    //    Only case where T is deduced to be a reference
    //    Although ParamType is rvalue ref, its deduced type is lvalue ref
    //2. If expr is rvalue, the normal case 1 rules apply
    funUnivReference(x);    // x = lvalue, T = int&, param = int&
    funUnivReference(cx);   // cx = lvalue, T =  const int&, param = const int&
    funUnivReference(rx);   // rx = lvalue, T = const int&, param = const int&
    funUnivReference(27);   // 27 = rvalue, T = int , param = int&&

    // case3: param type is neither a ptr nor ref
    // pass by value 
    // ref, const and volatile, all are ignored
    funValue(x); // T = param = int
    funValue(cx); // T = param = int
    funValue(rx); // T = param = int

    const char* const ptr = "Fun with ptrs"; // const ptr to const obj
    funValue(ptr); // T = param = const char* 
}