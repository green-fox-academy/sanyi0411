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
void insertionSort(std::vector<T> &array, bool ascending = true)
{
    for (int i = 1; i < array.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if ((array[i] < array[j] && ascending) || (array[i] > array[j] && !ascending)) {
                swap(&array[i], &array[j]);
            }
        }
    }
}

int main()
{
    std::vector<int> vec{3,8,4,7,1,6,5,9,2};
    insertionSort(vec, false);
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << std::endl;
    }
    return 0;
}