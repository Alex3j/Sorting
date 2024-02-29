#include <iostream>
#include <vector>

template <typename T>
void bubbleSort(std::vector<T>& arr, int n) {
    bool swapped = true;

    while (swapped) {
        swapped = false;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        n--;
    }
}

template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const T& element : arr) {
        std::cout << element << " ";
    }
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

    bubbleSort(arr,n);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
