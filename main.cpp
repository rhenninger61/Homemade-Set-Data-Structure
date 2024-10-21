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
void testingInsertionSort(MySet<int> setCpy)
{
    cout << "Before Insertion Sort: "<< setCpy.toString() <<endl;
    setCpy.insertionSort();
    cout << "After Insertion Sort: "<< setCpy.toString() <<endl;
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

    MySet<int> setCpy = set;
    // ASK NICK -> gets error Signal: SIGSEGV (Segmentation fault) during second iteration in the swap step?
    //testingBubbleSort(setCpy);

    MySet<int> setCpy2 = set;
    // ASK NICK -> it is only kind of sorting and seems a little random on where it's putting the values?
    //testingInsertionSort(setCpy);

    MySet<int> setCpy3 = set;
    // ASK NICK -> is there a problem with my swap?
    //testingSelectionSort(setCpy);

    MySet<int> setCpy4 = set;
    testingOddEven(setCpy);
    return 0;
}



