#include "mySet.h"

#include <iostream>
#include <ostream>
#include <stdexcept>

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
    if(capacity == std::string::npos)
    {
        throw std::invalid_argument("capacity must be positive");
    }
    this->capacity = capacity;
    this->count = 0;
    this->items = new T[capacity];
}

//Copy Constructor
template <typename T>
MySet<T>::MySet(const MySet& other)
    : count(other.count), capacity(other.capacity)
{
    items = new T[capacity];
    for(size_t i = 0; i < count; ++i)
    {
        items[i] = other.items[i];
    }
}

//Deconstructor
template <typename T>
MySet<T>::~MySet()
{
    delete[] items;
}

// Indexing
template <typename T>
size_t MySet<T>::operator[](const size_t index)
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
    //Prevents bug if user puts 0 as capacity
    if(capacity == 0)
    {
        capacity = 1;
    }

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
    insert(item, count);
}

template <typename T>
void MySet<T>::insert(const T& item, const size_t index)
{
    // checks if item already exists
    if(find(item) == std::string::npos)
    {
        // increases capacity if capacity is reached
        if(count + 1 >= capacity)
        {
            grow();
        }
        // move items over
        for (size_t i = count; i > index; i--)
        {
            items[i] = items[i - 1];
        }
        // add item at given index
        items[index] = item;
        //increment count
        count++;
    }
}

// removeAt() -> takes index as argument
template <typename T>
void MySet<T>::removeAt(const size_t index)
{
    if(index >= count)
    {
        throw std::out_of_range("Index is out of range");
    }
    for(size_t i = index; i < count - 1; ++i)
    {
        items[i] = items[i + 1]; // copies everything to the right over to the left one space starting from the desired removal point
    }
    if(--count < capacity/4) // shrinks capacity to take up less memory if needed
    {
        shrink();
    }
}

// remove() -> takes item as argument
template <typename T>
bool MySet<T>::remove(const T& item)
{
    const size_t index = find(item);

    if(index == std::string::npos)
    {
        return false;
    }
    removeAt(index);
    return true;
}

// clear() -> clears the set
template <typename T>
void MySet<T>::clear()
{
    delete[] items;
    items = new T[capacity]; // reallocate memory for set
    count = 0;
}

// toString()
template <typename T>
std::string MySet<T>::toString() const
{
    if(count == 0)
    {
        return "";
    }
    std::string str;

    for(size_t i = 0; i < count; ++i)
    {
        str += std::to_string(items[i]) + " ";
    }
    return str;
}

// ======= SORTING ========

// bubbleSort() -> standard
template <typename T>
void MySet<T>::bubbleSort()
{
    bool sorted = false;
    int unsortedUntilIndex = count - 1;

    while(sorted == false)
    {
        sorted = true; // prove me wrong!

        for(size_t i = 0; i < unsortedUntilIndex; i++)
        {
            if(items[i] > items[i + 1]) // check if value to left is greater than value to the right
            {
                // larger value moved to the right
                swap(i, i + 1);
                sorted = false; // I was proved wrong :(
            }
        }
        // largest value has been sorted and its no longer necessary to look at it
        --unsortedUntilIndex;
    }
}

// bidirectionalBubbleSort() -> inner loop carry the largest item to the right, inner loop will carry the smallest item to the left
template <typename T>
void MySet<T>::bidirectionalBubbleSort()
{
    bool sorted = false;
    int largeUnsortedUntilIndex = count - 1;
    int smallUnsortedUntilIndex = 0;

    while(sorted == false)
    {
        sorted = true; // prove me wrong!

        // largest -> starts at left and moves right
        for(size_t i = smallUnsortedUntilIndex; i < largeUnsortedUntilIndex; ++i)
        {
            if(items[i] > items[i + 1]) // check if value to right is greater than value to the left
            {
                // larger value moved to the right
                swap(i, i + 1);
                sorted = false; // I was proved wrong :(
            }
        }
        // largest value has been sorted and its no longer necessary to look at it
        --largeUnsortedUntilIndex;

        // smallest -> starts at right and moves left
        for(size_t i = largeUnsortedUntilIndex; i > smallUnsortedUntilIndex; --i)
        {
            if(items[i] < items[i - 1]) // checks if value to the right is smaller than value to the left
            {
                // moves smaller value to the left
                swap(i, i - 1);
                sorted = false; // I was proved wrong :(
            }
        }
        // smallest value has been sorted and it's no longer necessary to look at it
        ++smallUnsortedUntilIndex;
    }
}

// insertionSort() -> standard
template <typename T>
void MySet<T>::insertionSort()
{
    for(size_t i = 1; i < count; i++)
    {
        size_t j = i - 1;
        T temp = items[i]; // references current lowest number so it doesn't get lost

        //looks at element to the left and sees if there is anything greater than it
        // if not true, either the end of the array has been reached or a value has been found that is less than that value
        for(; j !=std::string::npos && items[j] > temp; --j)
        {
            // perform a shift to the right
            items[j + 1] = items[j];
        }

        // inserts the value to the right of the next lowest number in the array
        items[j + 1] = temp;
    }
}

// ASK NICK -> I'm not 100% sure I put the counters in the right spots
// insertionSortVerbose() -> counts the number of copies and comparisons it makes during a sort and displays the totals
template <typename T>
void MySet<T>::insertionSortVerbose()
{
    size_t numberOfCopies = 0;
    size_t numberOfComparisons = 0;

    for(size_t i = 1; i < count; ++i)
    {
        size_t j = i - 1;
        T temp = items[i]; // references current lowest number so it doesn't get lost

        //looks at element to the left and sees if there is anything greater than it
        // if not true, either the end of the array has been reached or a value has been found that is less than that value
        for(; j !=std::string::npos && items[j] > temp; --j)
        {
            // perform a shift to the right
            items[j + 1] = items[j];
            numberOfComparisons++;
        }

        // inserts the value to the right of the next lowest number in the array
        items[j + 1] = temp;
        numberOfCopies++;
    }

    std::cout << "Number of Copies: " << numberOfCopies << std::endl;
    std::cout << "Number of Comparisons: " << numberOfComparisons << std::endl;
}

// selectionSort() -> standard
template <typename T>
void MySet<T>::selectionSort()
{
    // going left to right through the array
    for(size_t i = 0; i < count; ++i)
    {
        size_t minIndex = i; // min value always starts at the beginning of the array

        for(size_t j = i + 1; j < count; ++j)
        {
            if(items[j] < items[minIndex])// updates to the next smallest amount
            {
                minIndex = j;
            }
        }
        if(minIndex != i) // performs a swap if items[j] is smaller than items[i]
        {
            swap(i, minIndex);
        }
    }
}

//oddEven()
template <typename T>
void MySet<T>::oddEven()
{
    bool sorted = false;

    while(sorted == false)
    {
        sorted = true;

        //odd index sort
        for(size_t i = 1; i < count - 1; i+=2)
        {
            if(items[i] > items[i + 1]) // checks if value to the right is greater
            {
                // larger value moved to the right
                swap(i, i + 1);
                sorted = false; // I was proven wrong :(
            }
        }
        // even index sort
        for(size_t i = 0; i < count - 1; i+=2) // checks if value to the right is greater
        {
            if(items[i] > items[i + 1]) // checks if value to the right is greater
            {
                // larger value moved to the right
                swap(i, i + 1);
                sorted = false; // I was proven wrong :(
            }
        }
    }
}

// ======== ADDITIONAL METHODS ===========
// swap()
template <typename T>
void MySet<T>::swap(size_t indexOne, size_t indexTwo)
{
    T temp = items[indexOne]; // saves indexOne to temp variable
    items[indexOne] = items[indexTwo]; // assigns value of indexOne to the value at indexTwo
    items[indexTwo] = temp; //reassigns the value of indexTwo to the value that was saved for indexOne
}

// median()
template <typename T>
double MySet<T>::median()
{
    // sort array first
    bubbleSort(); // best case is constant time

    // find mid-point and return it
    if(count % 2 == 0)
    {
        return static_cast<double>(items[count / 2 - 1] + items[count / 2]) / 2;
    }
    else
    {
        return items[count / 2];
    }
}
