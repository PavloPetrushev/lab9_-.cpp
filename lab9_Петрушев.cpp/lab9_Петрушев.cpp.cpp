// lab9_Петрушев.cpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
using namespace std;

bool isPrime(int num) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;

    int sqrt_num = sqrt(num);
    for (int i = 3; i <= sqrt_num; i += 2) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    const int rows = 3, cols = 4; // Розміри двовимірного масиву
    int arr[rows][cols] = { {1, 2, 3, 0}, {4, 5, 6, 7}, {0, 8, 9, 10} };

    int evenCount = 0; // Кількість парних елементів у рядках з нульовими елементами
    int minArray[cols]; // Одновимірний масив для зберігання мінімальних елементів стовпців

    // Знаходимо кількість парних елементів у рядках з нульовими елементами
    for (int i = 0; i < rows; i++) {
        bool hasZero = false;
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == 0)
                hasZero = true;
            if (hasZero && arr[i][j] % 2 == 0)
                evenCount++;
        }
    }

    // Перевіряємо, чи є отримана кількість парних елементів простим числом
    if (isPrime(evenCount))
        cout << "Kількість парних елементів у рядках з нульовими елементами є простим числом." << endl;
    else
        cout << "Kількість парних елементів у рядках з нульовими елементами не є простим числом." << endl;

    // Знаходимо мінімальні елементи стовпців
    for (int j = 0; j < cols; j++) {
        minArray[j] = arr[0][j]; // Початкове значення мінімального елемента стовпця
        for (int i = 1; i < rows; i++) {
            if (arr[i][j] < minArray[j])
                minArray[j] = arr[i][j];
        }
    }

    cout << "Мінімальні елементи стовпців: ";
    for (int i = 0; i < cols; i++)
        cout << minArray[i] << " ";
    cout << endl;

    return 0;
}
