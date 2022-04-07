#include <iostream>
#include "../Utilities/functiondefs.h"
using namespace std;

void sameAsTemplate()
{
    // Auto type is same as template type deduction
    // except for intializer list
    auto x = 27; // x is int
    cout << boost::typeindex::type_id_with_cvr<decltype(x)>() << endl;
    const auto cx = x; // cx is const int
    cout << boost::typeindex::type_id_with_cvr<decltype(cx)>() << endl;
    const auto &rx = x; // rx is const& int
    cout << boost::typeindex::type_id_with_cvr<decltype(rx)>() << endl;
    auto &&uref1 = x; // uref1 is int&
    cout << boost::typeindex::type_id_with_cvr<decltype(uref1)>() << endl;
    auto &&uref2 = cx; // uref is const& int
    cout << boost::typeindex::type_id_with_cvr<decltype(uref2)>() << endl;
    auto &&uref3 = 27; // uref3 is int&&
    cout << boost::typeindex::type_id_with_cvr<decltype(uref3)>() << endl;
    const char name[] = "Test Name";
    auto arr1 = name; // pass by value, array decays to pointer, arr1 is const char*
    cout << boost::typeindex::type_id_with_cvr<decltype(arr1)>() << endl;
    auto &arr2 = name; // arr2 is const char (&) [10]
    cout << boost::typeindex::type_id_with_cvr<decltype(arr2)>() << endl;
}

void templateVsAuto()
{
    auto x1 = 27; // x1 is int
    auto x2(27);  // x2 is int
    auto x3 = { 27 };  //x3 is std::intializer_list<int>
    auto x4{ 27 };  //x4 is again int
    
    //auto val = {1 ,3, 5.0}; //error: conflicting types for initializer list
    // You have two types of deductions happening in the above case
    // One is deducing it to be a std::intializer_list<T>,
    // And the other one is deducing T

    cout << boost::typeindex::type_id_with_cvr<decltype(x1)>() << endl;
    cout << boost::typeindex::type_id_with_cvr<decltype(x2)>() << endl;
    cout << boost::typeindex::type_id_with_cvr<decltype(x3)>() << endl;
    cout << boost::typeindex::type_id_with_cvr<decltype(x4)>() << endl;
    cout << endl;

    // funValue({1, 2, 3}); // error: can't deduce type 
    funInitializerList({1,2,3}); // T is int, and param is std::initializer_list<int>
}

int main() 
{
    templateVsAuto();
    // sameAsTemplate();
    return 0;
}