#include "mySet.h"

#include <stdexcept>
#include <bits/ranges_algo.h>
using namespace Set;

// Getters
template<typename T>
size_t MySet<T>::getCount() const {return count;}; // getter for count
template<typename T>
size_t MySet<T>::getCapacity() const {return capacity;}; // getter for capacity

// Default Constructor -> capacity for 4 elements
template<typename T>
MySet<T>::MySet(): MySet(DEFAULT_CAPACITY)
{}

// Capacity Constructor
template <typename T>
MySet<T>::MySet(const size_t capacity)
{
    this->capacity = capacity;
    this->count = 0;
    this->items = new T[capacity];
}

//Deconstructor
template <typename T>
MySet<T>::~MySet()
{
    delete[] items;
}

// Indexing
template <typename T>
size_t& MySet<T>::operator[](const size_t index)
{
    if(index >= count)
    {
        throw std::out_of_range("Index is out of range");
    }
    return items[index];
}

// increase capacity when it is reached
template <typename T>
void MySet<T>::grow()
{
    // Allocate memory for a new array
    T* newItems = new T[capacity * 2];

    // adds all items to new array
    for(size_t i = 0; i < count; i++)
    {
        newItems[i] = items[i];
    }
    //deletes items in original list
    delete[] items;

    // increases the original capacity
    capacity *= 2;

    // reassigns items back to original list
    items = newItems;
}

// shrink capacity when it is reached
template <typename T>
void MySet<T>::shrink()
{
    // Allocate memory for a new array
    T* newItems = new T[capacity / 2];

    // adds all items to new array
    for(size_t i = 0; i < count; i++)
    {
        newItems[i] = items[i];
    }
    //deletes items in original list
    delete[] items;

    // decreases the original capacity
    capacity /= 2;

    // reassigns items back to original list
    items = newItems;
}

// find() -> item as argument, returns index
template <typename T>
size_t MySet<T>::find(const T& item) const
{
    for(size_t i = 0; i < count; ++i)
    {
        if(item == items[i])
        {
            return i;
        }
    }
    return std::string::npos; //std::string::npos returns -1, for checking if an item is not in an array (same type as index)
}

// insert() -> no dupes allowed, only argument is the item itself
template <typename T>
void MySet<T>::insert(const T& item)
{
    // won't add the item if it already exists
    if(find(item) == std::string::npos)
    {
        return;
    }
    // increases capacity if capacity is reached
    if(count + 1 >= capacity)
    {
        grow();
    }

    // inserts at the correct location -> ask nick if this is okay?
    int left = 0;
    int right = count - 1;
    int insertIndex = count;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(item == items[mid])
        {
            insertIndex = mid;
            break;
        }
        if(items[mid] < item)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            insertIndex = mid;
        }
    }
    for(size_t i = count; i > insertIndex; --i)
    {
        items[i] = items[i - 1];
    }
    items[insertIndex] = item;
    ++count;
}

// remove() -> takes item as argument
template <typename T>
bool MySet<T>::remove(const T& item)
{
    
}

// removeAt() -> takes index as argument
void removeAt(const size_t index);

// clear() -> clears the set
void clear();

// toString()
std::string toString() const;

// ======= SORTING ========

// bubbleSort() -> standard
void bubbleSort();

// bidirectionalBubbleSort() -> inner loop carry largest item to the right, inner loop will carry smallest item to the left
void bidirectionalBubbleSort();

// insertionSort() -> standard
void insertionSort();

// insertionSortVerbose() -> counts the number of copies and comparisons it makes during a sort and displays the totals
void insertionSortVerbose();

// selectionSort() -> standard
void selectionSort();

//oddEven() -> google what this is supposed to look like
void oddEven();

// ======== ADDITIONAL METHODS ===========
// swap()
void swap(size_t index);

// median() -> returns the median value of a set
void median();
