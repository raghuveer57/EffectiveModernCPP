#include <iostream>
#include "../Utilities/functiondefs.h"

int x = 27;         // x is int
const int cx = x;   // cx is const int
const int &rx = x;  // rx is const &int
const int *px = &x; // px is ptr to x as a const int

void case1()
{
    // case1: param type is reference or pointer,
    //  but not universal reference
    //  1. If expr's type is ref, ignore ref part while determining T
    //  2. Then pattern match expr's type against ParamType to determine T

    // Since cx and rx are const values, T is deduced to be const int
    // rx's ref type is ignored while deducing T
    funReference(x);  // T = int, param = int&
    funReference(cx); // T = const int , param = const int&
    funReference(rx); // T = const int , param = const int&

    // Since px is again a const value, T is deduced to be const int
    funPointer(&x); //  T = int, param = int*
    funPointer(px); //  T = const int, param = const int*
}

void case2()
{
    // case2: param type is univ reference
    //  1. If expr is lvalue, both T and ParamType are deduced to be lvalue refs
    //     Only case where T is deduced to be a reference
    //     Although ParamType is rvalue ref, its deduced type is lvalue ref
    // 2. If expr is rvalue, the normal case 1 rules apply
    funUnivReference(x);  // x = lvalue, T = int&, param = int&
    funUnivReference(cx); // cx = lvalue, T =  const int&, param = const int&
    funUnivReference(rx); // rx = lvalue, T = const int&, param = const int&
    funUnivReference(27); // 27 = rvalue, T = int , param = int&&
}

void case3()
{
    // case3: param type is neither a ptr nor ref
    // pass by value
    // ref, const and volatile, all are ignored
    funValue(x);  // T = param = int
    funValue(cx); // T = param = int
    funValue(rx); // T = param = int

    const char *const ptr = "Fun with ptrs"; // const ptr to const obj
    funValue(ptr);                           // T = param = const char*
}

void caseArray()
{
    const char name[] = "J. P. Briggs"; // name's type is const char[13]
    const char* ptrToName = name;   // array decays to pointer
    std::cout << boost::typeindex::type_id_with_cvr<decltype(name)>() << std::endl;
    std::cout << boost::typeindex::type_id_with_cvr<decltype(ptrToName)>() << std::endl;
    std::cout << std::endl;
    funValue(name); // array decays to pointer when it is passed by value
                    // T = const char*,  param = const char*
    funPointer(name); // same as above, arrays decays to pointer 
                      // T = const char , param = const char*
    funReference(name); // T = const char[13], param = const char (&)[13]

    int arr[] = {1,2,3,4,5,6,7};
    std::cout << arraySize(arr) << std::endl; // check utilies on arraySize function

    int copyarray[arraySize(arr)]; // constexpr in arraySize declaration makes this possible
    std::cout << arraySize(copyarray) << std::endl; // size is again 7 
}

void funExample(int, double)
{

}

void caseFunctionArgs()
{
    //functions also decays into pointer when passed by value
    funValue(funExample); //T = param = void (*) ( int , double)
    funReference(funExample); // T = void (int, double),  param = void (&) (int, double)
}

int main()
{
    // case1();
    // case2();
    // case3();
    // caseArray();
    caseFunctionArgs();
}