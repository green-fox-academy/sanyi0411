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
void selectionSortAsc(std::vector<T> &array)
{
    int minIndex;
    for (int i = 0; i < array.size() - 1; ++i) {
        minIndex = i;
        for (int j = i + 1; j < array.size(); ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (i != minIndex) {
            swap(&array[i], &array[minIndex]);
        }
    }
}

template <typename T>
void selectionSortDesc(std::vector<T> &array)
{
    int maxIndex;
    for (int i = 0; i < array.size() - 1; ++i) {
        maxIndex = i;
        for (int j = i + 1; j < array.size(); ++j) {
            if (array[j] > array[maxIndex]) {
                maxIndex = j;
            }
        }
        if (i != maxIndex) {
            swap(&array[i], &array[maxIndex]);
        }
    }
}

template <typename T>
void selectionSort(std::vector<T> &array, bool flag = true)
{
    if (flag) {
        selectionSortAsc(array);
    } else {
        selectionSortDesc(array);
    }
}

int main(int argc, char **argv)
{
    std::vector<int> vec{1,6,3,7,4,8,2};
    selectionSort(vec, false);
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << std::endl;
    }

    return 0;
}