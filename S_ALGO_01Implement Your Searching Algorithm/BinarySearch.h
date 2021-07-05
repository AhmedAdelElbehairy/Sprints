#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
//
//#define SORTED 1
//#define NOTSORTED 0
typedef enum
{
    NOTSORTED,
    SORTED
}Sort;
Sort SortedOrNot(uint32_t* arr, uint8_t numberOfelements);
uint8_t binarySearch(uint32_t* arr, uint8_t numberOfelements, uint8_t number);

#endif // BINARYSEARCH_H
