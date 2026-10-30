#include <iostream>
#include <vector>
#include <cstdlib>   
#include <ctime>     

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    const int N = 1000000;   
    const int MAX_VALUE = 1000;

    vector<int> arr(N);
    srand(time(0));                    
    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % MAX_VALUE + 1;   
    }
    int k;
    cout << "Введите целевое число K: ";
    cin >> k;

    vector<int> firstIndex(MAX_VALUE + 1, -1);   

    int idx1 = -1, idx2 = -1;

    for (int i = 0; i < N; ++i) {
        int need = k - arr[i];         

        if (need >= 1 && need <= MAX_VALUE && firstIndex[need] != -1) {
            idx1 = firstIndex[need];    
            idx2 = i;                   
            break;                      
        }
        if (firstIndex[arr[i]] == -1) {
            firstIndex[arr[i]] = i;
        }
    }

    if (idx1 != -1) {
        cout << "Найдена пара: индексы " << idx1 << " и " << idx2
             << " (значения " << arr[idx1] << " и " << arr[idx2] << ")" << endl;
        cout << "Сумма = " << arr[idx1] + arr[idx2] << endl;
    } else {
        cout << "Пары с суммой " << k << " не найдено." << endl;
    }

    return 0;
}