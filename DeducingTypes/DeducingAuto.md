# Deducing Auto

Auto type deduction is same as template type deduction with just one exception.
The braced initializer , i.e., { 1, 2, 3} is deduced as `std::initializer_list<T>`

All the three cases which we follow for template type deduction are used here as well
- Case 1 : type specifier is a pointer or a reference, but not a universal reference
- Case 2 : type specifier is universal reference 
- Case 3 : type specifier is neither a pointer nor a reference

If the braced initializer has different data types then the type can't be deduced and the resulting code results in an error.
```
auto var = {1, 3, 5.0}; // error . can't deduce the type
```
Also if a braced initializer is passed into our usual template functions, it throws an `error: type can't be deduced`
If we were to pass a braced initializer to a function, we have to do something like this 
```
template <typename T>
void funInitializerList(std::initializer_list<T> param)
{
    ...
}
```
From C++14 onwards, the return type of a function can be auto. 
Also lamdas may use auto params.
However, it uses template type deduction instead of auto type deduction.
Meaning the below code snippets won't compile
```
auto someFunction()
{
    return {1,2,3}; //error: can't deduce type
}
```
```
vector<int> v;
auto resetV = [&v](const auto& newValue){ v = newValue;};
resetV({1,2,3});
```
### Things to remember
- auto type deduction is usually the same as template type deduction, but auto type deduction assumes that a braced initializer represents a std::initial izer_list, and template type deduction doesn’t.
- auto in a function return type or a lambda parameter implies template type deduction, not auto type deduction.( these are allowed from C++14 onwards )