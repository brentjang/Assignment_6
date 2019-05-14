#include <iostream>
#include <chrono>
#include "Sort.h"
#include "FileIO.h"

using namespace std;
using namespace std::chrono;

Sort::Sort(string n)
{
    FileIO f(n);

    sizeOfArrays = f.getTotalLines();
    quickSortArr = new double[sizeOfArrays];
    insertionSortArr = new double[sizeOfArrays];
    bubbleSortArr = new double[sizeOfArrays];
    mergeSortArr = new double[sizeOfArrays];

    for(int i = 0; i < sizeOfArrays; i++)
    {
        quickSortArr[i] = f.getLine(i);
        insertionSortArr[i] = f.getLine(i);
        bubbleSortArr[i] = f.getLine(i);
        mergeSortArr[i] = f.getLine(i);
    }
}

Sort::~Sort()
{
    delete[] quickSortArr;
    delete[] insertionSortArr;
    delete[] bubbleSortArr;
    delete[] mergeSortArr;
}

//helper for QuickSort
int Sort::partition(double* arr, int low, int high)
{
    double pivot = arr[high]; //pivot is the last element
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void Sort::quickRec(int low, int high)
{
    if (low < high)
    {
        int index = partition(quickSortArr, low, high);
        quickRec(low, index - 1);
        quickRec(index + 1, high);
    }
}

void Sort::quickSort()
{
    auto start = high_resolution_clock::now();
    quickRec(0, sizeOfArrays);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Time taken by QuickSort: "
         << duration.count() << " nanoseconds" << endl;
}

void Sort::bubbleSort()
{
    auto start = high_resolution_clock::now();
    for (int i = 0; i < sizeOfArrays; i++)
    {
        for (int j = 0; j < sizeOfArrays-i-1; j++)
        {
            if (bubbleSortArr[j] > bubbleSortArr[j+1]) //if pair is out of order
            {
                swap(&bubbleSortArr[j], &bubbleSortArr[j+1]);
            }
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Time taken by Bubble Sort: "
         << duration.count() << " nanoseconds" << endl;
}

void Sort::insertionSort()
{
    int j = 0;
    auto start = high_resolution_clock::now();
    for (int i = 1; i < sizeOfArrays; i++)
    {
        double key = insertionSortArr[i];
        j = i - 1;
        while (j >= 0 && insertionSortArr[j] > key) //slides values until correct index it found
        {
            insertionSortArr[j + 1] = insertionSortArr[j];
            j = j - 1;
        }
        insertionSortArr[j + 1] = key;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Time taken by Insertion Sort: "
         << duration.count() << " nanoseconds" << endl;
}


void Sort::merge(int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 =  right - middle;

    double tempLeft[n1], tempRight[n2]; //make temp arrays

    //fill temp arrays
    for (i = 0; i < n1; i++)
    {
        tempLeft[i] = mergeSortArr[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        tempRight[j] = mergeSortArr[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    //compares merging array values to place them in order
    while (i < n1 && j < n2)
    {
        if (tempLeft[i] <= tempRight[j]) //smaller values placed first
        {
            mergeSortArr[k] = tempLeft[i];
            i++;
        }
        else
        {
            mergeSortArr[k] = tempRight[j];
            j++;
        }
        k++;
    }
    while (i < n1) //leftover elements in tempLeft
    {
        mergeSortArr[k] = tempLeft[i];
        i++;
        k++;
    }
    while (j < n2) //leftover elements in tempRight
    {
        mergeSortArr[k] = tempRight[j];
        j++;
        k++;
    }
}

void Sort::mergeRec(int left, int right)
{
    if (left < right)
    {
        int middle = left+(right-left)/2;

        mergeRec(left, middle);
        mergeRec(middle+1, right);
        merge(left, middle, right);
    }
}

void Sort::mergeSort()
{
    auto start = high_resolution_clock::now();
    mergeRec(0, sizeOfArrays);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Time taken by Merge Sort: "
         << duration.count() << " nanoseconds" << endl;
}

//swap two elements helper function
void Sort::swap(double *xp, double *yp)
{
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int Sort::getSizeOfArrays()
{
    return sizeOfArrays;
}
//
// void Sort::printArrays()
// {
//     for(int j = 0; j < sizeOfArrays; j++)
//     {
//         cout << quickSortArr[j] << endl;
//     }
// }
