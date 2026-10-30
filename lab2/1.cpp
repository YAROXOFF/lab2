#include <iostream>
#include <vector>
#include <string>  
#include <sstream>   
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
        cout << "Размер массива должен быть положительным!" << endl;
        return 1;
    }

    cin.ignore();

    vector<int> arr; 
    cout << "Введите " << n << " элементов массива (через пробел): ";
    
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

    cout << "Отсортированный массив: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl; 

    return 0;
}