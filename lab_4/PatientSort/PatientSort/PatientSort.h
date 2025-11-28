#ifndef SORT_H
#define SORT_H

#include<vector>

template <typename T, typename Compare>
void patienceSort(std::vector<T>& arr, Compare comp) {
    std::vector<std::vector<T>> piles;
    if (arr.empty()) return;

    for (const T& elem : arr) {
        bool placed = false;

        for (auto& pile : piles) {
            if (!comp(pile.back(), elem)) {
                pile.push_back(elem);
                placed = true;
                break;
            }
        }

        if (!placed) {
            piles.push_back({ elem });
        }
    }

    std::vector<T> result;
    result.reserve(arr.size());

    while (!piles.empty()) {

        T minElem = piles[0].back();
        size_t minPile = 0;

        for (size_t i = 1; i < piles.size(); i++) {
            if (comp(piles[i].back(), minElem)) {
                minElem = piles[i].back();
                minPile = i;
            }
        }

        result.push_back(minElem);
        piles[minPile].pop_back();

        if (piles[minPile].empty()) {
            piles.erase(piles.begin() + minPile);
        }
    }
    arr = result;
}

template <typename T, typename Compare>
void patienceSort(T arr[], size_t size, Compare comp) {
    if (size == 0) return;

    std::vector<T> vec(arr, arr + size);
    std::vector<std::vector<T>> piles;

    for (const T& elem : vec) {
        bool placed = false;

        for (auto& pile : piles) {
            if (!comp(pile.back(), elem)) { 
                pile.push_back(elem);
                placed = true;
                break;
            }
        }

        if (!placed) {
            piles.push_back({ elem });
        }
    }
    std::vector<T> result;
    result.reserve(size);

    while (!piles.empty()) {

        T minElem = piles[0].back();
        size_t minPile = 0;

        for (size_t i = 1; i < piles.size(); i++) {
            if (comp(piles[i].back(), minElem)) {
                minElem = piles[i].back();
                minPile = i;
            }
        }

        result.push_back(minElem);
        piles[minPile].pop_back();

        if (piles[minPile].empty()) {
            piles.erase(piles.begin() + minPile);
        }
    }

    for (size_t i = 0; i < size; i++) {
        arr[i] = result[i];
    }
}
#endif 