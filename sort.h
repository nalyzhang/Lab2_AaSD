#pragma once

const int RUN = 32;
const int M = 50;

void swap(int* a, int* b);
void merge(int* A, int low, int mid, int high);
unsigned partition(int* A, unsigned start, unsigned end);
void heapify(int* A, int N, int i);
int minn(int a, int b);


void SelectionSort(int* A, unsigned N);
void InsertionSort(int* A, unsigned begin, unsigned end);
void BubbleSort(int* A, unsigned N);
void MergeSort(int* A, unsigned left, unsigned right);
void QuickSort(int* A, unsigned size);
void ShellSort(int* A, unsigned N);
void ShellSortExponencial(int* arr, int len);
void ShellSortDivision(int* arr, int len);
void ShellSortSubstact(int* arr, int len);
void HeapSort(int* A, unsigned end);
void TimSort(int* A, unsigned N);
void IntroSort(int *data, unsigned begin, unsigned count);