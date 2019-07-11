#include <iostream>
#include <vector>

template <typename T>
void bubbleSort(std::vector<T> &array, bool ascending = true)
{
    bool swapped;
    for (int i = 0; i < array.size() - 1; ++i) {
        swapped = false;
        for (int j = 0; j < array.size() - 1 - i; ++j) {
            if ((array[j] > array[j + 1] && ascending) || (array[j] < array[j + 1] && !ascending)) {
                std::swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int main()
{
    std::vector<int> vec{3,8,4,7,1,6,5,9,2};
    bubbleSort(vec);
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << std::endl;
    }
    return 0;
}