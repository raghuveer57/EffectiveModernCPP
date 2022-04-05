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
