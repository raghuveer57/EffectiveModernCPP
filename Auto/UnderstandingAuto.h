#pragma once 
#include<iterator>

// function to compare the values pointed by two iterators 
// full type version 
// the type of the value pointed by iterator is 
// typename std::iterator_traits<It>::value_type firstVal
template<typename It>
bool isEqual_withOutAuto(It first, It second)
{
    typename std::iterator_traits<It>::value_type firstVal = *first;
    typename std::iterator_traits<It>::value_type secondVal = *second;
    return firstVal == secondVal;
}
// function to compare the values pointed by two iterators 
// auto version 
template<typename It>
bool isEqual_withAuto(It first, It second)
{
    auto firstVal = *first;
    auto secondVal = *second;
    return firstVal == secondVal;
}