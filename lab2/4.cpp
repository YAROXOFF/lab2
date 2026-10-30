#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>      
#include <sstream>     

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int n;
    cout << "Введите размер массива: ";
    while (!(cin >> n)) {
        cout << "Ошибка, нужно число! Введите размер: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (n < 2) {
        cout << "Нужно хотя бы 2 элемента!" << endl;
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

    int k;
    cout << "Введите целевое число K: ";
    cin >> k;

    unordered_map<int, int> seen;

    for (int i = 0; i < n; ++i) {
        int need = k - arr[i];            
        if (seen.count(need)) {             
            cout << "Найдена пара: индексы "
                 << seen[need] << " и " << i
                 << " (значения " << need << " и " << arr[i] << ")" << endl;
            break;                          
        }
        seen[arr[i]] = i;                   
    }
    return 0;
}