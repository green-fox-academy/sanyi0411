#include <iostream>
#include <vector>

template <typename T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <typename T>
void insertionSort(std::vector<T> &array, bool ascending)
{
    for (int i = 1; i < array.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if ((array[i] < array[j] && ascending) || (array[i] > array[j] && !ascending)) {
                swap(&array[i], &array[j]);
            }
        }
    }
}

template <typename T>
void shellSort(std::vector<T> &array, int size, bool ascending)
{
    if (size >= 2) {
        int gap = size / 2;
        for (int i = 0; i + gap < array.size(); ++i) {
            if ((array[i] > array[i + gap] && ascending) || (array[i] < array[i + gap] && !ascending)) {
                swap(&array[i], &array[i + gap]);
            }
        }
        shellSort(array, gap, ascending);
    } else {
        insertionSort(array, ascending);
    }
}

template <typename T>
void shellSort(std::vector<T> &array, bool ascending = true)
{
    if (array.empty() || array.size() == 1) {
        return;
    }

    shellSort(array, array.size(), ascending);
}

int main()
{
    std::vector<int> vec{3,8,4,7,1,6,5,9,2};
    shellSort(vec);
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << std::endl;
    }
    return 0;
}