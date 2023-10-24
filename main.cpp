#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

using namespace std;

int* copyarray(int array[], unsigned length);

int* reversedarray(int size);
int* sortedarray(int size);
int* randomarray(int size);
int* nearlysortedarray(int size);

bool ismember(int* arr, int size, int comp);

const int numarr = 20;

int main()
{
    short currentMethod = 0;

    int** reversedarrays = new int* [numarr];
    int** sortedarrays = new int* [numarr];
    int** nearlysortedarrays = new int* [numarr];
    int** randomarrays = new int* [numarr];

    for (int i = 0; i < numarr; i++) {
        reversedarrays[i] = reversedarray((i+1)*M);
    }
    for (int i = 0; i < numarr; i++) {
        sortedarrays[i] = sortedarray((i + 1) * M);
    }
    for (int i = 0; i < numarr; i++) {
        nearlysortedarrays[i] = nearlysortedarray((i + 1) * M);
    }
    for (int i = 0; i < numarr; i++) {
        randomarrays[i] = randomarray((i + 1) * M);
    }

    cout.precision(0);

    clock_t start;
    double time;

    double timeCD;

    for (int numOfOperation = 1; numOfOperation < 10; numOfOperation++) {
        switch (numOfOperation) {
            case 1:
                cout << "Selection Sort" << endl;
                break;
            case 2:
                cout << "\n\nInsertion Sort" << endl;
                break;
            case 3:
                cout << "\n\nBubble Sort" << endl;
                break;
            case 4:
                cout << "\n\nMerge Sort" << endl;
                break;
            case 5:
                cout << "\n\nQuick Sort" << endl;
                break;
            case 6:
                cout << "\n\nShell Sort" << endl;
                break;
            case 7:
                cout << "\n\nHeap Sort" << endl;
                break;
            case 8:
                cout << "\n\nTim Sort" << endl;
                break;
            case 9:
                cout << "\n\nIntro Sort" << endl;
                break;
            default:
                cout << "Error" << endl;
        }

        for (int numOfArray = 1; numOfArray < 5; numOfArray++) {

            switch (numOfArray) {
                case 1:
                    cout << "\nReverse array\n" << endl;
                    break;
                case 2:
                    cout << "\nSorted Array\n" << endl;
                    break;
                case 3:
                    cout << "\nNearly Sorted Array\n" << endl;
                    break;
                case 4:
                    cout << "\nRandom Array\n" << endl;
                    break;
                default:
                    cout << "Error" << endl;
            }

            for (int j = 0; j < numarr; j++) {

                switch(numOfArray) {
                    case 1:
                        start = clock();
                        for (int i = 0; i < 100; i++) {
                            int *new_array = copyarray(reversedarrays[j], (j + 1) * M);
                            delete[] new_array;
                        }
                        timeCD = double(clock() - start);
                        break;
                    case 2:
                        start = clock();
                        for (int i = 0; i < 100; i++) {
                            int *new_array = copyarray(sortedarrays[j], (j + 1) * M);
                            delete[] new_array;
                        }
                        timeCD = double(clock() - start);
                        break;
                    case 3:
                        start = clock();
                        for (int i = 0; i < 100; i++) {
                            int *new_array = copyarray(nearlysortedarrays[j], (j + 1) * M);
                            delete[] new_array;
                        }
                        timeCD = double(clock() - start);
                        break;
                    case 4:
                        start = clock();
                        for (int i = 0; i < 100; i++) {
                            int *new_array = copyarray(randomarrays[j], (j + 1) * M);
                            delete[] new_array;
                        }
                        timeCD = double(clock() - start);
                        break;
                    default:
                        cout << "Error" << endl;
                }

                switch (numOfOperation) {
                    case 1:
                        switch(numOfArray) {
                            case 1:
                                start = clock();
                                for (int i = 0; i < 100; i++) {
                                    int* new_array = copyarray(reversedarrays[j], (j+1) * M);
                                    SelectionSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 100);
                                break;
                            case 2:
                                start = clock();
                                for (int i = 0; i < 100; i++) {
                                    int* new_array = copyarray(sortedarrays[j], (j+1) * M);
                                    SelectionSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 100);
                                break;
                            case 3:
                                start = clock();
                                for (int i = 0; i < 100; i++) {
                                    int* new_array = copyarray(nearlysortedarrays[j], (j+1) * M);
                                    SelectionSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 100);
                                break;
                            case 4:
                                start = clock();
                                for (int i = 0; i < 100; i++) {
                                    int* new_array = copyarray(randomarrays[j], (j+1) * M);
                                    SelectionSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 100);
                                break;
                            default:
                                cout << "Error" << endl;
                        }
                        break;
                    case 2:
                        switch(numOfArray) {
                            case 1:
                                start = clock();
                                for (int i = 0; i < 100; i++) {
                                    int* new_array = copyarray(reversedarrays[j], (j + 1) * M);
                                    InsertionSort(new_array, 0, (j + 1)* M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 100);
                                break;
                            case 2:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(sortedarrays[j], (j + 1) * M);
                                    InsertionSort(new_array, 0, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            case 3:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(nearlysortedarrays[j], (j + 1) * M);
                                    InsertionSort(new_array, 0, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            case 4:
                                start = clock();
                                for (int i = 0; i < 100; i++) {
                                    int* new_array = copyarray(randomarrays[j], (j + 1) * M);
                                    InsertionSort(new_array, 0, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 100);
                                break;
                            default:
                                cout << "Error" << endl;
                        }
                        break;
                    case 3:
                        switch(numOfArray) {
                            case 1:
                                start = clock();
                                for (int i = 0; i < 100; i++) {
                                    int* new_array = copyarray(reversedarrays[j], (j + 1) * M);
                                    BubbleSort(new_array, (j + 1)* M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 100);
                                break;
                            case 2:
                                start = clock();
                                for (int i = 0; i < 100; i++) {
                                    int* new_array = copyarray(sortedarrays[j], (j + 1) * M);
                                    BubbleSort(new_array, (j + 1)* M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 100);
                                break;
                            case 3:
                                start = clock();
                                for (int i = 0; i < 100; i++) {
                                    int* new_array = copyarray(nearlysortedarrays[j], (j + 1) * M);
                                    BubbleSort(new_array, (j + 1)* M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 100);
                                break;
                            case 4:
                                start = clock();
                                for (int i = 0; i < 100; i++) {
                                    int* new_array = copyarray(randomarrays[j], (j + 1) * M);
                                    BubbleSort(new_array, (j + 1)* M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 100);
                                break;
                            default:
                                cout << "Error" << endl;
                        }
                        break;
                    case 4:
                        switch(numOfArray) {
                            case 1:
                                start = clock();
                                for (int i = 0; i < 100; i++) {
                                    int* new_array = copyarray(reversedarrays[j], (j + 1) * M);
                                    MergeSort(new_array, 0, (j + 1) * M - 1);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 100);
                                break;
                            case 2:
                                start = clock();
                                for (int i = 0; i < 100; i++) {
                                    int* new_array = copyarray(sortedarrays[j], (j + 1) * M);
                                    MergeSort(new_array, 0, (j + 1) * M - 1);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 100);
                                break;
                            case 3:
                                start = clock();
                                for (int i = 0; i < 100; i++) {
                                    int* new_array = copyarray(nearlysortedarrays[j], (j + 1) * M);
                                    MergeSort(new_array, 0, (j + 1) * M - 1);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 100);
                                break;
                            case 4:
                                start = clock();
                                for (int i = 0; i < 100; i++) {
                                    int* new_array = copyarray(randomarrays[j], (j + 1) * M);
                                    MergeSort(new_array, 0, (j + 1) * M - 1);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 100);
                                break;
                            default:
                                cout << "Error" << endl;
                        }
                        break;
                    case 5:
                        switch(numOfArray) {
                            case 1:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(reversedarrays[j], (j + 1) * M);
                                    QuickSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            case 2:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(sortedarrays[j], (j + 1) * M);
                                    QuickSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            case 3:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(nearlysortedarrays[j], (j + 1) * M);
                                    QuickSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            case 4:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(randomarrays[j], (j + 1) * M);
                                    QuickSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            default:
                                cout << "Error" << endl;
                        }
                        break;
                    case 6:
                        switch(numOfArray) {
                            case 1:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(reversedarrays[j], (j + 1) * M);
                                    ShellSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            case 2:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(sortedarrays[j], (j + 1) * M);
                                    ShellSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            case 3:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(nearlysortedarrays[j], (j + 1) * M);
                                    ShellSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            case 4:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(randomarrays[j], (j + 1) * M);
                                    ShellSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            default:
                                cout << "Error" << endl;
                        }
                        break;
                    case 7:
                        switch(numOfArray) {
                            case 1:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(reversedarrays[j], (j + 1) * M);
                                    HeapSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            case 2:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(sortedarrays[j], (j + 1) * M);
                                    HeapSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            case 3:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(nearlysortedarrays[j], (j + 1) * M);
                                    HeapSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);start = clock();
                                break;
                            case 4:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(randomarrays[j], (j + 1) * M);
                                    HeapSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            default:
                                cout << "Error" << endl;
                        }
                        break;
                    case 8:
                        switch(numOfArray) {
                            case 1:
                                start = clock();
                                for (int i = 0; i < 100; i++) {
                                    int* new_array = copyarray(reversedarrays[j], (j + 1) * M);
                                    TimSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 100);
                                break;
                            case 2:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(sortedarrays[j], (j + 1) * M);
                                    TimSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            case 3:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(nearlysortedarrays[j], (j + 1) * M);
                                    TimSort(new_array, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            case 4:
                                start = clock();
                                for (int i = 0; i < 100; i++) {
                                    int* new_array = copyarray(reversedarrays[j], (j + 1) * M);
                                    IntroSort(new_array, 0, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 100);
                                break;
                            default:
                                cout << "Error" << endl;
                        }
                        break;
                    case 9:
                        switch(numOfArray) {
                            case 1:
                                start = clock();
                                for (int i = 0; i < 100; i++) {
                                    int* new_array = copyarray(reversedarrays[j], (j + 1) * M);
                                    IntroSort(new_array, 0, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 100);
                                break;
                            case 2:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(sortedarrays[j], (j + 1) * M);
                                    IntroSort(new_array, 0, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            case 3:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(nearlysortedarrays[j], (j + 1) * M);
                                    IntroSort(new_array, 0, (j + 1) * M - 1);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            case 4:
                                start = clock();
                                for (int i = 0; i < 1000; i++) {
                                    int* new_array = copyarray(randomarrays[j], (j + 1) * M);
                                    IntroSort(new_array, 0, (j + 1) * M);
                                    delete[] new_array;
                                }
                                time = double((clock() - start - timeCD) / 1000);
                                break;
                            default:
                                cout << "Error" << endl;
                        }
                        break;
                    default:
                        cout << "Error" << endl;
                }
                cout << (j + 1) * M << " " << fixed << time << endl;
            }
        }
    }


    for (int i = 0; i < numarr; ++i) {
        if (reversedarrays[i] != NULL) {
            delete reversedarrays[i];
            reversedarrays[i] = NULL;
        }
    }

    for (int i = 0; i < numarr; ++i) {
        if (sortedarrays[i] != NULL) {
            delete sortedarrays[i];
            sortedarrays[i] = NULL;
        }
    }
    for (int i = 0; i < numarr; ++i) {
        if (nearlysortedarrays[i] != NULL) {
            delete nearlysortedarrays[i];
            nearlysortedarrays[i] = NULL;
        }
    }
    for (int i = 0; i < numarr; ++i) {
        if (randomarrays[i] != NULL) {
            delete randomarrays[i];
            randomarrays[i] = NULL;
        }
    }
}

int* copyarray(int array[], unsigned length) {
    int* newArr = new int[length];
    for (unsigned i = 0; i < length; i++) {
        *(newArr + i) = array[i];
    }
    return newArr;
}

int* reversedarray(int size)
{
    int* pointer = new int[size];
    for (int i = size - 1; i >= 0; i--) {
        pointer[size - i - 1] = i;
    }
    return pointer;
}

int* sortedarray(int size)
{
    int* pointer = new int[size];
    for (int i = 0; i < size; i++) {
        pointer[i] = i;
    }
    return pointer;
}

int* randomarray(int size)
{
    int* pointer = new int[size];
    int i = 0;
    while (i < size) {
        int b = rand() % size;
        if (ismember(pointer, i, b)) { continue; }
        else {
            pointer[i] = b;
            ++i;
        }
    }
    return pointer;
}

int* nearlysortedarray(int size)
{
    int* pointer = sortedarray(size);
    int temp = pointer[0];
    pointer[0] = pointer[size - 1];
    pointer[size - 1] = temp;
    return pointer;
}

bool ismember(int* arr, int size, int comp) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == comp) {
            return true;
        }
    }
    return false;
}