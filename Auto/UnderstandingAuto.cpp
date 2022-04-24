#include "UnderstandingAuto.h"
#include <vector>
#include <unordered_map>
#include <iostream>
#include <boost/type_index.hpp>
using namespace std;

void dwimFunctions()
{
    vector v{1, 1, 2};
    auto first = v.begin();
    auto second = ++v.begin();
    // function without auto call, alternate function to dwim function
    cout << boolalpha << isEqual_withOutAuto(first, second) << endl;
    // function with auto call, alternate function to dwim function
    cout << boolalpha << isEqual_withAuto(first, second) << endl;
}

void lambdaFuntions()
{
    // C++ 11 version
    auto lessThanlambdaAuto11 = [](const unique_ptr<int> &p1, const unique_ptr<int> &p2)
    {
        return *p1 < *p2;
    };
    // C++ 14 version
    auto lessThanlambdaAuto14 = [](const auto &p1, const auto &p2)
    {
        return *p1 < *p2;
    };
    auto firstPtr = make_unique<int>(4);
    auto secondPtr = make_unique<int>(3);
    // calling 11 version, param types are not auto
    cout << lessThanlambdaAuto11(firstPtr, secondPtr) << endl;
    // calling 14 version, param types are auto
    cout << lessThanlambdaAuto14(secondPtr, firstPtr) << endl;
}

void typeShortcuts()
{
    vector<int> v{1, 2, 3};
    unsigned sz = v.size();                                              // this works, but it is not the actual type
    auto szz = v.size();                                                 // std::vector<int>::size_type
    cout << boost::typeindex::type_id_with_cvr<decltype(szz)>() << endl; // prints unsigned long for some reason

    std::unordered_map<std::string, int> m;
    m["abc"] = 1;
    m["crazy"] = 2;
    m["fsfsfsf"] = 3;

    // Type should be std::pair<const std::string,int>
    for (const std::pair<std::string, int> &p : m)
    {
        cout << "Key is :: " << p.first << "Value is :: " << p.second << endl;
    }

    for (const auto &p : m)
    {
        cout << boost::typeindex::type_id_with_cvr<decltype(p)>() << endl;
        cout << "Key is :: " << p.first << "Value is :: " << p.second << endl;
    }
}
int main()
{
    dwimFunctions();
    lambdaFuntions();
    typeShortcuts();
}