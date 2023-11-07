#include "sort.h"
#include <cmath>

//функции сортировок
void SelectionSort(int* a, unsigned size)
{
    unsigned minIndex = 0;
    for (unsigned i = 0; i < size - 1; i++) {
        for (unsigned j = i + 1; j < size; j++) {
            if (*(a + j) < *(a + minIndex)) {
                minIndex = j;
            }
        }
        int* pa = &(*(a + i));
        int* pb = &(*(a + minIndex));
        swap(pa, pb);
    }
}

void InsertionSort(int* arr, unsigned begin, unsigned end)
{
    int i, key, j;
    for (i = 1; i < end; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void BubbleSort(int* a, unsigned size)
{
    for (unsigned i = 0; i < size - 1; i++) {
        for (unsigned j = 0; j < size - 1 - i; j++) {
            if (a[j] > a[j+1])
            {
                int* pa = &a[j];
                int* pb = &a[j+1];
                swap(pa, pb);
            }
        }
    }
}

void MergeSort(int* a, unsigned low, unsigned high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    MergeSort(a, low, mid);
    MergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

void QuickSort(int* a, unsigned size)
{
    int i = 0;
    int j = size - 1;
    int mid = a[size / 2];

    do {
        while (a[i] < mid) {
            i++;
        }
        while (a[j] > mid) {
            j--;
        }
        if (i <= j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        QuickSort(a, j + 1);
    }
    if (i < size) {
        QuickSort(&(a[i]), size - i);
    }
}

void ShellSort(int* a, unsigned size)
{
    for (unsigned gap = size / 2; gap > 0; gap /= 2)
    {
        for (unsigned i = gap; i < size; i += 1)
        {
            int temp = a[i];

            unsigned j = 0;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];

            a[j] = temp;
        }
    }
}

void HeapSort(int* a, unsigned end)
{
    for (int i = end / 2 - 1; i >= 0; i--)
        heapify(a, end, i);

    for (int i = end - 1; i >= 0; i--) {
        int* pa = &a[0];
        int* pb = &a[i];
        swap(pa, pb);
        heapify(a, i, 0);
    }
}

void TimSort(int* a, unsigned sizeup)
{
    for (int i = 0; i < sizeup; i += RUN)
        InsertionSort(a, i, minn((i + RUN - 1), (sizeup - 1)));

    for (int size = RUN; size < sizeup; size *= 2) {
        for (unsigned left = 0; left < sizeup; left += 2 * size) {

            int mid = left + size - 1;
            int right = minn((left + 2 * size - 1), (sizeup - 1));

            if (mid < right) {
                merge(a, left, mid, right);
            }
        }
    }
}

void IntroSort(int* data, unsigned begin, unsigned count) {
    int partitionSize = partition(data, 0, count - 1);

    if (partitionSize < 16)
    {
        InsertionSort(data, 0, count);
    }
    else if (partitionSize > (2 * log(count)))
    {
        HeapSort(data, count);
    }
    else
    {
        QuickSort(data, count - 1);
    }
}


//дополнительные функции
int minn(int a, int b) {
    if (a > b) return b;
    else return a;
}

void swap(int* a, int* b) {
    int temp_a = *a;
    *a = *b;
    *b = temp_a;
}

void merge(int* a, int low, int mid, int high) {
    int const subArrayOne = mid - low + 1;
    int const subArrayTwo = high - mid;
    auto* leftArray = new int[subArrayOne];
    auto* rightArray = new int[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++) leftArray[i] = a[low + i];
    for (auto j = 0; j < subArrayTwo; j++) rightArray[j] = a[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = low;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            a[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            a[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        a[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        a[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

unsigned partition(int* a, unsigned left, unsigned right)
{
    int pivot = a[right];
    int temp;
    int i = left;

    for (int j = left; j < right; ++j)
    {
        if (a[j] <= pivot)
        {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            i++;
        }
    }

    a[right] = a[i];
    a[i] = pivot;

    return i;
}

void heapify(int* a, int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && a[l] > a[largest])
        largest = l;

    if (r < size && a[r] > a[largest])
        largest = r;

    int* pa;
    int* pb;

    if (largest != i) {
        pa = &(*(a + i)); pb = &(*(a + largest));
        swap(pa, pb);

        heapify(a, size, largest);
    }
}

void ShellSortDivision(int* arr, int len)
{
    for (int step = len / 2; step != 1; step /= 2)
    {
        for (int i = step; i < len; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= step && arr[j - step] > temp; j -= step)
            {
                arr[j] = arr[j - step];
            }
            arr[j] = temp;
        }
    }
}
void ShellSortExponencial(int* arr, int len)
{
    int k = 1;
    for (int step = 1; step <=len; step = pow(2,k++)-1)
    {
        for (int i = step; i < len; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= step && arr[j - step] > temp; j -= step)
            {
                arr[j] = arr[j - step];
            }
            arr[j] = temp;
        }
    }
}
void ShellSortSubstact(int* arr, int len)
{
    for (int step = len / 2; step != 1; step--)
    {
        for (int i = step; i < len; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= step && arr[j - step] > temp; j -= step)
            {
                arr[j] = arr[j - step];
            }
            arr[j] = temp;
        }
    }
}