#include <iostream>

using namespace std;

class Sort
{
public:
    Sort() {};
    Sort(string n);
    ~Sort();
    void quickRec(int low, int high);
    int partition(double* arr, int low, int high);
    void quickSort();
    void insertionSort();
    void bubbleSort();
    void merge(int left, int middle, int right);
    void mergeRec(int left, int right);
    void mergeSort();
    void swap(double* xp, double* yp);
    int getSizeOfArrays();
    //void printArrays();

private:
    double* quickSortArr;
    double* insertionSortArr;
    double* bubbleSortArr;
    double* mergeSortArr;
    int sizeOfArrays;
};
