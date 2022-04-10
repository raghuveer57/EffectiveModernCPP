#include <iostream>
#include <vector>
#include "../Utilities/functiondefs.h"
using namespace std;
using boost::typeindex::type_id_with_cvr;

class Widget
{
};

const int i = 0;                // decltype(i) is const int
vector<int> intVector{1, 2, 3}; // decltype(intVector) is vector<int>
                                // decltype(intVector[0]) is int&
vector<bool> boolVector{true, false, true};
// decltype(boolVector[0] is a new vector reference

bool f(const Widget &w) { return false; } // decltype(f) is bool(const Widget&)

struct Point
{
    int x, y; // decltype(Point::x) is int , decltype(Point::y) is int
};

void obviousSnippets()
{
    cout << type_id_with_cvr<decltype(i)>().pretty_name() << endl;
    cout << type_id_with_cvr<decltype(f)>().pretty_name() << endl;
    cout << type_id_with_cvr<decltype(Point::x)>().pretty_name() << endl;
    cout << type_id_with_cvr<decltype(Point::y)>().pretty_name() << endl;
    cout << type_id_with_cvr<decltype(intVector)>().pretty_name() << endl;
    cout << type_id_with_cvr<decltype(intVector[0])>().pretty_name() << endl;
}

void specialCases()
{
    cout << type_id_with_cvr<decltype((i))>().pretty_name() << endl; // decltype peculiar behavior
    // [] for bool vector returns a new object and it depends on the container
    cout << type_id_with_cvr<decltype(boolVector[0])>().pretty_name() << endl;
    // change the value of the 3rd element
    authAndAcess(intVector,2) = 11;
    cout << intVector[2] << endl;
    // read the rvalue vector
    cout << authAndAcess(vector{1,2,3}, 1) << endl;
}

int main()
{
    //obviousSnippets();
    specialCases();
}