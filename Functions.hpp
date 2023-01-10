#pragma once
#include <iostream>
#define print(a) std::cout<<a<<'\n';

template<class T> int compare(T val1, T val2) {
	if (val1 > val2)
	{
		return -1;
	}
	if (val1 == val2)
	{
		return 0;
	}
	if (val2 > val1)
	{
		return 1;
	}
}
template<class T> void swap(T* xp, T* yp) {
	T temp = *xp;
	*xp = *yp;
	*yp = temp;
}
template<class T> void bubbleSort(T* arr, int arrLen) {
	for (int i = 0; i < arrLen - 1; i++)
		for (int j = 0; j < arrLen - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
template<class T> void printArray(T* arr, int arrLen) {
	for (int i = 0; i < arrLen; i++)
	{
		print(arr[i])
	}
}