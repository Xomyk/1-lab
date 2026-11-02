#include <iostream>
#include <string>

using namespace std;

// ==========================================
// Шаблонная функция swap (Вариант 4)
// Обменивает значения двух переменных любого типа T
// ==========================================
template <typename T>
void mySwap(T& a, T& b) {
    T temp = a; // Временная переменная типа T
    a = b;
    b = temp;
}

// ==========================================
// Фрагменты кода для анализа сложности
// ==========================================

// Пример А: O(n) - линейный проход
int exampleA(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) { // n итераций
        sum += arr[i];            // O(1) внутри
    }
    return sum;
}

// Пример B: O(n²) - два вложенных цикла
int exampleB(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {     // n итераций
        for (int j = 0; j < n; j++) { // n итераций для каждой i
            if (arr[i] == arr[j]) count++;
        }
    }
    return count;
}

// Пример C: O(log n) - логарифмическая (удвоение шага)
int exampleC(int n) {
    int count = 0;
    for (int i = 1; i < n; i *= 2) { // i удваивается: log2(n) итераций
        count++;
    }
    return count;
}

// Пример D: O(n log n) - комбинация циклов
int exampleD(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {     // n итераций
        for (int j = n; j > 0; j /= 2) { // log2(n) итераций
            count++;
        }
    }
    return count;
}

// Пример E: O(√n) - корневая сложность
int exampleE(int n) {
    int count = 0;
    for (int i = 0; i * i < n; i++) { // i до √n
        count++;
    }
    return count;
}

// ==========================================
// Главная функция
// ==========================================
int main() {
    setlocale(LC_ALL, "ru");

    cout << "===========================================" << endl;
    cout << "1. Демонстрация работы шаблонной функции swap" << endl;
    cout << "===========================================" << endl;

    // Демонстрация с типом int
    int x = 5, y = 10;
    cout << "До swap (int): x = " << x << ", y = " << y << endl;
    mySwap(x, y);
    cout << "После swap (int): x = " << x << ", y = " << y << endl << endl;

    // Демонстрация с типом double
    double d1 = 3.14, d2 = 2.71;
    cout << "До swap (double): d1 = " << d1 << ", d2 = " << d2 << endl;
    mySwap(d1, d2);
    cout << "После swap (double): d1 = " << d1 << ", d2 = " << d2 << endl << endl;

    // Демонстрация с типом string
    string s1 = "Hello", s2 = "World";
    cout << "До swap (string): s1 = " << s1 << ", s2 = " << s2 << endl;
    mySwap(s1, s2);
    cout << "После swap (string): s1 = " << s1 << ", s2 = " << s2 << endl << endl;

    // Демонстрация с типом char
    char c1 = 'A', c2 = 'B';
    cout << "До swap (char): c1 = " << c1 << ", c2 = " << c2 << endl;
    mySwap(c1, c2);
    cout << "После swap (char): c1 = " << c1 << ", c2 = " << c2 << endl << endl;

    cout << "===========================================" << endl;
    cout << "2. Анализ сложности фрагментов кода" << endl;
    cout << "===========================================" << endl;
    
    // Вызываем функции, чтобы компилятор не выдал предупреждение о неиспользуемых функциях
    int testArr[] = {1, 2, 3, 4, 5};
    exampleA(testArr, 5);
    exampleB(testArr, 5);
    exampleC(100);
    exampleD(10);
    exampleE(100);

    cout << "Пример A: O(n)      - один цикл, зависящий от n (линейный проход)." << endl;
    cout << "Пример B: O(n^2)    - два вложенных цикла, каждый выполняется n раз." << endl;
    cout << "Пример C: O(log n)  - шаг цикла умножается на 2 (i *= 2), итераций log(n)." << endl;
    cout << "Пример D: O(n log n)- внешний цикл n раз, внутренний цикл log(n) раз (j /= 2)." << endl;
    cout << "Пример E: O(sqrt(n))- условие i * i < n, цикл выполняется корень из n раз." << endl;

    return 0;
}