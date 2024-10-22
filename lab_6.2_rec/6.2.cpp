#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

const int SIZE = 10;

// Рекурсивна функція для виведення масиву
void COUT(int mas[], int size, int i = 0) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << mas[i] << " ";
    COUT(mas, size, i + 1);
}

// Рекурсивна функція для заповнення масиву
void FillArray(int mas[], int size, int i = 0) {
    if (i == size) return; // Базовий випадок
    mas[i] = rand() % 100; // Заповнення випадковим числом
    FillArray(mas, size, i + 1); // Рекурсивний виклик для наступного елемента
}

// Рекурсивна функція для пошуку індексу найбільшого парного елемента
int FindMaxEvenIndexRecursive(int mas[], int size, int i = 0, int maxEven = -1, int maxIndex = -1) {
    if (i == size) {
        return maxIndex; // Повертаємо індекс найбільшого парного елемента
    }

    if (mas[i] % 2 == 0 && mas[i] > maxEven) {
        maxEven = mas[i];
        maxIndex = i;
    }

    return FindMaxEvenIndexRecursive(mas, size, i + 1, maxEven, maxIndex);
}

int main() {
    srand((unsigned)time(0));
    setlocale(LC_CTYPE, "ukr");

    int a[SIZE];

    // Заповнення масиву рекурсивно
    FillArray(a, SIZE);

    cout << "Початковий масив: " << endl;
    // Виведення масиву рекурсивно
    COUT(a, SIZE);

    // Пошук індексу найбільшого парного елемента рекурсивно
    int maxEvenIndex = FindMaxEvenIndexRecursive(a, SIZE);

    if (maxEvenIndex != -1) {
        cout << "Індекс найбільшого парного елемента: " << maxEvenIndex << endl;
        cout << "Значення найбільшого парного елемента: " << a[maxEvenIndex] << endl;
    }
    else {
        cout << "У масиві немає парних елементів." << endl;
    }

    return 0;
}
