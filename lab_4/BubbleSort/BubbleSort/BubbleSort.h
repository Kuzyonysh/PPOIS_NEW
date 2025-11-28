#ifndef SORT_H
#define SORT_H

#include <vector>
#include <algorithm> 

template <typename T, typename Compare>
void bubbleSort(std::vector<T>& arr, Compare comp) {
    for (size_t i = 0; i < arr.size(); i++) {
        bool swapped = false;
        for (size_t j = 0; j < arr.size() - i - 1; j++) {
            if (comp(arr[j + 1], arr[j])) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

template <typename T, typename Compare>
void bubbleSort(T arr[], size_t size, Compare comp) {
    for (size_t i = 0; i < size; i++) {
        bool swapped = false;
        for (size_t j = 0; j < size - i - 1; j++) {
            if (comp(arr[j + 1], arr[j])) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

#endif 

