#include <iostream>
#include <vector>

template <typename T>
void mergeAsc(std::vector<T> &array, std::vector<T> &array1, std::vector<T> &array2)
{
	array.clear();

	int i, j, k;
	for (i = 0, j = 0, k = 0; i < array1.size() && j < array2.size(); k++) {
		if (array1.at(i) <= array2.at(j)) {
			array.push_back(array1.at(i));
			i++;
		} else if (array1.at(i) > array2.at(j)) {
			array.push_back(array2.at(j));
			j++;
		}
		k++;
	}

	while (i < array1.size()) {
		array.push_back(array1.at(i));
		i++;
	}

	while (j < array2.size()) {
		array.push_back(array2.at(j));
		j++;
	}
}

template <typename T>
void mergeSortAsc(std::vector<T> &array)
{
	if (1 < array.size()) {
		std::vector<T> array1(array.begin(), array.begin() + array.size() / 2);
		mergeSortAsc(array1);
		std::vector<T> array2(array.begin() + array.size() / 2, array.end());
		mergeSortAsc(array2);
		mergeAsc(array, array1, array2);
	}
}

template <typename T>
void mergeSortDesc(std::vector<T> &array)
{
	mergeSortAsc(array);
	std::reverse(array.begin(), array.end());
}

template <typename T>
void mergeSort(std::vector<T> &array, bool flag = true)
{
	if (flag)
		mergeSortAsc(array);
	else if (!flag)
		mergeSortDesc(array);
}

int main(int argc, char **argv)
{
	std::vector<int> vec1{4, 5 ,-6, 24, 9999, -235};
	std::vector<char> vec2{'g', 'o', 'b', 'x', 'z', 'e', 'q'};
	std::vector<double> vec3{123.524, -534,23, 8.21234, -34637.1, 636, -75845};

	mergeSort(vec1);
	for (int i = 0; i < vec1.size(); ++i) {
		std::cout << vec1[i] << "\t";
	}
	std::cout << std::endl;

	mergeSort(vec1, false);
	for (int i = 0; i < vec1.size(); ++i) {
		std::cout << vec1[i] << "\t";
	}
	std::cout << std::endl;

	mergeSort(vec2);
	for (int i = 0; i < vec2.size(); ++i) {
		std::cout << vec2[i] << "\t";
	}
	std::cout << std::endl;

	mergeSort(vec3);
	for (int i = 0; i < vec3.size(); ++i) {
		std::cout << vec3[i] << "\t";
	}
	std::cout << std::endl;

	return 0;
}