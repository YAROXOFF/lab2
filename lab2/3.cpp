#include <iostream>
#include <climits>
using namespace std;

const int N = 10;

bool isLocalMin(int matrix[N][N], int r, int c) {
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) continue;  

            int nr = r + dr;                    
            int nc = c + dc;                   
           
            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (matrix[nr][nc] <= matrix[r][c]) return false;
        }
    }
    return true;  
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int matrix[N][N] = {
        { 5, 4, 3, 9, 8, 7, 6, 5, 4, 3 },
        { 6, 1, 2, 8, 9, 6, 7, 4, 5, 2 },
        { 7, 8, 9, 7, 6, 5, 4, 3, 2, 1 },
        { 4, 3, 2, 1, 5, 6, 7, 8, 9, 4 },
        { 9, 8, 7, 6, 0, 1, 2, 3, 4, 5 },
        { 2, 3, 4, 5, 6, 7, 8, 9, 1, 6 },
        { 1, 9, 8, 7, 6, 5, 4, 3, 2, 7 },
        { 3, 2, 1, 0, 9, 8, 7, 6, 5, 8 },
        { 6, 7, 8, 9, 1, 2, 3, 4, 5, 9 },
        { 5, 4, 3, 2, 1, 0, 9, 8, 7, 6 }
    };

    cout << "Матрица:" << endl;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cout << matrix[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Локальные минимумы (строка, столбец, значение):" << endl;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (isLocalMin(matrix, r, c)) {
                cout << "(" << r << ", " << c << ") = " << matrix[r][c] << endl;
            }
        }
    }

    return 0;
}