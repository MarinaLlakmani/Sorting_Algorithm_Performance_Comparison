#include <iostream>
#include <ratio>
#include "TimedSorts.h"

using namespace std;

void testAllSorts(TimedSorts& test, int type, const string& Name){
    test.scramble(type);
    cout << Name << endl;
    duration<double,TIME_UNIT> bubbleInus = test.BubbleSort();
    cout << "Using Bubble Sort: " << bubbleInus.count() << endl;

    test.scramble(type);
    duration<double,TIME_UNIT> insertionInus = test.InsertionSort();
    cout << "Using Insertion Sort: " << insertionInus.count() << endl;

    test.scramble(type);
    duration<double,TIME_UNIT> mergeInus = test.MergeSort();
    cout << "Using Merge Sort: " << mergeInus.count() << endl;

    test.scramble(type);
    duration<double,TIME_UNIT> quickInus = test.QuickSort();
    cout << "Using Quick Sort: " << quickInus.count() << endl;
    
    test.scramble(type);
    duration<double,TIME_UNIT> builtInus = test.BuiltInSort();
    cout << "Using Built in Sort: " << builtInus.count() << endl << endl;

}

int main()
{
    int arrLength = 1000;
    cout << boolalpha;
    TimedSorts runner = TimedSorts();

    runner.fillData(arrLength);
    cout << "Testing sorting time on an array with " << arrLength << " elements" << endl;
    testAllSorts(runner, -2, "Testing on a reverse array");
    testAllSorts(runner, 0, "Testing on a sorted array");
    testAllSorts(runner, 1, "Testing on the same scramble");
    testAllSorts(runner, -1, "Testing on a random array");
    return 0;


}


