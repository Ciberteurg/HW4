//Реализовать контейнер с 10 000 случайными (не псевдослучайными) величинами.
//Реализовать 2 вида сортировок. Сравнить, какая быстрее.
//Программа должна выводить время и название наиболее быстрой сортировки.

#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

void bubbleSort(std::vector<int>& arr);
void insertionSort(std::vector<int>& arr);

int main() {

    srand(std::time(0));
	
    for (int t = 10000; t < 30000; t += 1000) {

        std::vector<int> random_array;

        for (int _i = 0; _i < t; ++_i) {
            random_array.push_back(std::rand() % 500);
        }

        std::vector<int> array_for_insert = random_array;
        std::vector<int> array_for_bubble = random_array;

        auto start_insert_sort = std::chrono::high_resolution_clock::now();
        insertionSort(array_for_insert);
        auto end_insert_sort = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> time_insert_sort = end_insert_sort - start_insert_sort;
        std::cout << "Insertion sort time: " << time_insert_sort.count() << " seconds. Number of numbers: " << t << std::endl;


        auto start_bubble_sort = std::chrono::high_resolution_clock::now();
        bubbleSort(array_for_bubble);
        auto end_bubble_sort = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> time_bubble_sort = end_bubble_sort - start_bubble_sort;
        std::cout << "Bubble sort time: " << time_bubble_sort.count() << " seconds. Number of numbers: " << t << std::endl << std::endl;

    }
    
    return 0;

}

void bubbleSort(std::vector<int>& arr) {

    auto n = arr.size();

    for (int _i = 0; _i < n - 1; ++_i) {

        for (int _j = 0; _j < n - _i - 1; ++_j) {

            if (arr[_j] > arr[_j + 1])
                std::swap(arr[_j], arr[_j + 1]);

        }

    }

}

void insertionSort(std::vector<int>& arr) {

    auto n = arr.size();

    for (int _i = 1; _i < n; ++_i) {

        int key = arr[_i];
        int _j = _i - 1;

        while (_j >= 0 && arr[_j] > key) {

            arr[_j + 1] = arr[_j];
            _j = _j - 1;

        }

        arr[_j + 1] = key;

    }

}