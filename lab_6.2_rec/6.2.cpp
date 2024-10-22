#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

const int SIZE = 10;

// ���������� ������� ��� ��������� ������
void COUT(int mas[], int size, int i = 0) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << mas[i] << " ";
    COUT(mas, size, i + 1);
}

// ���������� ������� ��� ���������� ������
void FillArray(int mas[], int size, int i = 0) {
    if (i == size) return; // ������� �������
    mas[i] = rand() % 100; // ���������� ���������� ������
    FillArray(mas, size, i + 1); // ����������� ������ ��� ���������� ��������
}

// ���������� ������� ��� ������ ������� ���������� ������� ��������
int FindMaxEvenIndexRecursive(int mas[], int size, int i = 0, int maxEven = -1, int maxIndex = -1) {
    if (i == size) {
        return maxIndex; // ��������� ������ ���������� ������� ��������
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

    // ���������� ������ ����������
    FillArray(a, SIZE);

    cout << "���������� �����: " << endl;
    // ��������� ������ ����������
    COUT(a, SIZE);

    // ����� ������� ���������� ������� �������� ����������
    int maxEvenIndex = FindMaxEvenIndexRecursive(a, SIZE);

    if (maxEvenIndex != -1) {
        cout << "������ ���������� ������� ��������: " << maxEvenIndex << endl;
        cout << "�������� ���������� ������� ��������: " << a[maxEvenIndex] << endl;
    }
    else {
        cout << "� ����� ���� ������ ��������." << endl;
    }

    return 0;
}
