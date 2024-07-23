#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
void menu()
{
    printf("\n1.Nhap mang");
    printf("\n2.Tong phan tu so dau la le");
    printf("\n3.Dem so lan xuat hien");
    printf("\n4.Sap xep chan tang le giam");
    printf("\n5.Tim day con dai nhat");
    printf("\n6.So nho thu hai trong mang");
    printf("\n7.Tim x ");

}
void generateRandomArray(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 28;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}


void listPrimes(int n) {
    bool found = false;
    printf("So nguyen to nho hon %d: ", n);
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            found = true;
        }
    }
    if (!found) {
        printf("Khong co so nguyen to nho hon %d.", n);
    }
    printf("\n");
}
int sumOddFirstDigit(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int firstDigit = arr[i];
        while (firstDigit >= 10) {
            firstDigit /= 10;
        }
        if (firstDigit % 2 != 0) {
            sum += arr[i];
        }
    }
    return sum;
}
void countOccurrences(int arr[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            count++;
    }
    printf("%d xuat hien %d lan", x, count);

}

int main()
{
    int lc;
    int  arr[50];
    int n = 10;
    generateRandomArray(arr, n);
    do
    {
        menu();
        printf("\nMoi ban chon ");
        scanf_s("%d", &lc);
        printArray(arr, n);
        switch (lc)
        {
        case 1:
        {
            int a;
            printf("\nNhap so bat ki ");
            scanf_s("%d", &a);
            listPrimes(a);
        }break;
        case 2:
        {
            int sum = sumOddFirstDigit(arr, n);
            printf("Tong phan tu so dau la chan : %d\n", sum);
        }break;
        case 3:
        {
            int a;
            printf("\nNhap so bat ki ");
            scanf_s("%d", &a);
            countOccurrences(arr, n, a);
        }break;
        }

    } while (lc);
    return 0;

}