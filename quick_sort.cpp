#include <iostream>
#include <vector>
#include <random>

template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
int randomPartition(std::vector<T>& arr, int low, int high) {
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<int> dis(low, high);
    int randomIndex = dis(gen);
    std::swap(arr[randomIndex], arr[high]);
    return partition(arr, low, high);
}

template <typename T>
void quickSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const T& element : arr)
        std::cout << element << " ";
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array:";
    std::cin >> n;

    std::vector<double> arr(n);

    std::cout << "Enter the elements of the array:";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array:";
    printArray(arr);

    return 0;
}