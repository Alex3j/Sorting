#include <iostream>
#include <vector>

template <typename T>
void selectionSort(std::vector<T>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
            std::swap(arr[i], arr[min]);
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
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    selectionSort(arr, n);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}