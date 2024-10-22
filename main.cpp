/*
 * Name: Rachel Henninger
 * South Hills Username: rhenninger61
 */

#include <iostream>
#include "mySet.h"
using namespace std;
using namespace Set;

void testingBubbleSort(MySet<int> setCpy)
{
    cout << "Before Bubble Sort: "<< setCpy.toString() <<endl;
    setCpy.bubbleSort();
    cout << "After Bubble Sort: "<< setCpy.toString() <<endl;
}
void testingBidirectionalBubbleSort(MySet<int> setCpy)
{
    cout << "Before Bidirectional Sort: "<< setCpy.toString() <<endl;
    setCpy.bidirectionalBubbleSort();
    cout << "After Bidirectional Sort: "<< setCpy.toString() <<endl;
}
void testingInsertionSort(MySet<int> setCpy)
{
    cout << "Before Insertion Sort: "<< setCpy.toString() <<endl;
    setCpy.insertionSort();
    cout << "After Insertion Sort: "<< setCpy.toString() <<endl;
}
void testingInsertionSortVerbose(MySet<int> setCpy)
{
    cout << "Before Insertion Sort Verbose: "<< setCpy.toString() << endl;
    setCpy.insertionSortVerbose();
    cout << "After Insertion Sort Verbose: " << setCpy.toString() << endl;
}
void testingSelectionSort(MySet<int> setCpy)
{
    cout << "Before Selection Sort: "<< setCpy.toString() <<endl;
    setCpy.selectionSort();
    cout << "After Selection Sort: "<< setCpy.toString() <<endl;
}
void testingOddEven(MySet<int> setCpy)
{
    cout << "Before oddEven Sort: "<< setCpy.toString() <<endl;
    setCpy.oddEven();
    cout << "After oddEven Sort: "<< setCpy.toString() <<endl;
}

int main()
{
    // shows inserts and toString() work :)
    MySet<int> set(10);

    for(int i = 0; i < 10; i++)
    {
        int randNum = rand() % 10 + 1;
        set.insert(randNum);
    }
    cout << "Original Set: " << set.toString() << endl;

    //Inserting num to test remove
    set.insert(20);
    cout << "Inserting int 20: " << set.toString() << endl;

    // Removing the int 20 I just added
    set.remove(20);
    cout << "Removing int 20: " << set.toString() << endl;

    //Inserting num to test removeAt
    set.insert(20, 5);
    cout << "Inserting int 20 at the 5th index: " << set.toString() << endl;

    // Removing the int 20 I just added
    set.removeAt(5);
    cout << "Removing int 20 at the 5th index: " << set.toString() << endl;

    //BubbleSort -> works as intended now
    MySet<int> setCpy = MySet(set);
    testingBubbleSort(setCpy);
    setCpy.clear();

    //BidirectionalBubbleSort -> works as intended now
    MySet<int> setCpy2 = MySet(set);
    testingBidirectionalBubbleSort(setCpy2);
    setCpy2.clear();

    //InsertionSort -> works as intended now
    MySet<int> setCpy3 = MySet(set);
    testingInsertionSort(setCpy3);
    setCpy3.clear();

    //InsertionSortVerbose -> works as intended now
    MySet<int> setCpy4 = MySet(set);
    testingInsertionSortVerbose(setCpy4);
    setCpy4.clear();

    // SelectionSort -> works as intended now
    MySet<int> setCpy5 = MySet(set);
    testingSelectionSort(setCpy5);
    setCpy5.clear();

    // OddEven SOrt -> works as intended now
    MySet<int> setCpy6 = MySet(set);
    testingOddEven(setCpy6);
    setCpy6.clear();

    // Median even element test
    set.insert(20);
    cout << "Median even amount: " << set.median() << endl;

    // Median odd element test -> had to put at end due to sorting in function
    set.remove(20);
    cout << "Median odd amount: " << set.median() << endl;

    return 0;
}



