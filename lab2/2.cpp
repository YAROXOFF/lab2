#include <iostream>
#include <vector>
#include <sstream>   
#include <string>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {       
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;                 
        } else if (arr[mid] < target) {
            left = mid + 1;             
        } else {
            right = mid - 1;            
        }
    }
    return -1;                         
}


int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int n;
    cout << "Введите размер массива: ";
    while (!(cin >> n)) {
        cout << "Ошибка, нужно число! Введите размер: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (n <= 0) {
        cout << "Размер должен быть положительным!" << endl;
        return 1;
    }
    cin.ignore();

    vector<int> arr;
    cout << "Введите " << n << " элементов массива (в одну строку): ";
    
    string line;
    getline(cin, line); 
    
    stringstream ss(line);
    int x;
    while (ss >> x) {
        arr.push_back(x);
    }
    if (arr.size() != n) {
        cout << "Ошибка: вы ввели " << arr.size() 
             << " чисел, а нужно " << n << "!" << endl;
        return 1;
    }

    bubbleSort(arr);

    cout << "Отсортированный массив:   ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    int target;
    cout << "Что ищем? ";
    cin >> target;

    int result = binarySearch(arr, target);

    if (result != -1) {
        cout << "Элемент " << target << " найден на индексе " << result << endl;
    } else {
        cout << "Элемент " << target << " не найден" << endl;
    }

    return 0;
}