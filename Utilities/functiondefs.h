#pragma once
#include <boost/type_index.hpp>

// case 3 : param type is neither a pointer nor a reference
template <typename T>
void funValue(T param)
{
    using boost::typeindex::type_id_with_cvr;
    using std::cout;
    using std::endl;
    // show T
    cout << "T = " << type_id_with_cvr<T>().pretty_name() << endl;
    // show param's type
    cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << endl
         << endl;
}

// case1: param type is a ref or ptr, but not a univ ref
template <typename T>
void funConstReference(const T &param)
{
    using boost::typeindex::type_id_with_cvr;
    using std::cout;
    using std::endl;
    // show T
    cout << "T = " << type_id_with_cvr<T>().pretty_name() << endl;
    // show param's type
    cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << endl
         << endl;
}

// case1: param type is a ref or ptr, but not a univ ref
template <typename T>
void funReference(T &param)
{
    using boost::typeindex::type_id_with_cvr;
    using std::cout;
    using std::endl;
    // show T
    cout << "T = " << type_id_with_cvr<T>().pretty_name() << endl;
    // show param's type
    cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << endl
         << endl;
}

// case1: param type is a ref or ptr, but not a univ ref
template <typename T>
void funPointer(T *param)
{
    using boost::typeindex::type_id_with_cvr;
    using std::cout;
    using std::endl;
    // show T
    cout << "T = " << type_id_with_cvr<T>().pretty_name() << endl;
    // show param's type
    cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << endl
         << endl;
}

// case2: param type is a univ ref
template <typename T>
void funUnivReference(T&& param)
{
    using boost::typeindex::type_id_with_cvr;
    using std::cout;
    using std::endl;
    // show T
    cout << "T = " << type_id_with_cvr<T>().pretty_name() << endl;
    // show param's type
    cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << endl
         << endl;
}

// correct way to deduce templates for braced initializers
template <typename T>
void funInitializerList(std::initializer_list<T> param)
{
    using boost::typeindex::type_id_with_cvr;
    using std::cout;
    using std::endl;
    // show T
    cout << "T = " << type_id_with_cvr<T>().pretty_name() << endl;
    // show param's type
    cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << endl
         << endl;
}

// function to return the size of array as compile type constant
// constexpr - make the result available at compile time 
// noexcept - help compilers generate better code
//  we are also not specifying the array param since we are
// only interested in the size of array
template <typename T, size_t N>
constexpr size_t arraySize(T (&)[N]) noexcept
{
    return N;
} 

/* Function to authenticate the user before returning
   use declType(auto) as return type,
   pass universal ref as parameter to handle edge cases,
   use std::forward<T>(param) to work with universal refs
*/
template <typename Container, typename Index>
decltype(auto) authAndAcess(Container &&c, Index i)
{
    //perform authentication
    return std::forward<Container>(c)[i];
}