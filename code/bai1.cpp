#include<stdio.h>
#include<conio.h>
#include<time.h>
#include <stdlib.h>
void menu()
{
	printf("\n1.Tao mang ngau nhien co so phan tu lon hon hoac nho hon 15");
	printf("\n2.Tao mang toan so chan");
	printf("\n3.Tim x trong a theo  Linear Search.");
	printf("\n4.Sap xep a tang dan  Interchange Sort.");
	printf("\n5.Tim x trong a theo Binary Search");
	printf("\n6.Sap xep a tang dan theo Selection Sort");
	printf("\n7.Sap xep a tang dan theo  Quick Sort");
}
void taomangngaunhien(int* arr, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 28;
	}
}
void taomangngaunhientoanchan(int* arr, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (rand() % 101) * 2;
	}
}
int linear_search(int* arr, int n, int x) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			return i;
		}
	}
	return -1;
}
void interchange_sort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
int binary_search(int* arr, int n, int x) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] == x) {
			return mid;
		}
		else if (arr[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}
void selection_sort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}
int main()
{
	srand(time(0));
	int n = 15;
	int arr[100];
	int lc;
	do
	{
		menu();
		printf("\nMoi ban chon ");
		scanf_s("%d", &lc);
		switch (lc)
		{
		case 1:
		{
			taomangngaunhien(arr, n);
			printf("Mang ngau nhien: ");
			for (int i = 0; i < n; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");

		}break;
		case 2:
		{

			taomangngaunhientoanchan(arr, n);
			printf("Mang so chan la: ");
			for (int i = 0; i < n; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");

		}break;
		}
		case 3:
		{
			int x;
			printf("\nNhap phan tu can tim: ");
			scanf("%d", &x);
			if (linear_search(arr, n, x) == -1)
				printf("\nKhong tim thay phan tu %d trong mang ", x);
			else
				printf("\nTim thay phan tu %d trong mang ", x);

		}break;
		case 4:
		{
			interchange_sort(arr, n);
			printf("Mang sap xep theo tu tang dan  la: ");
			for (int i = 0; i < n; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");

		}break;
		case 5:
		{
			int x;
			printf("\nNhap phan tu can tim: ");
			scanf_s("%d", &x);
			int binary_result = binary_search(arr, n, x);
			printf("Tim kiem nhi phan %d trong mang da sap xep tang dan : ", x);
			if (binary_result == -1) {
				printf("Khong tim thay\n");
			}
			else {
				printf("Vi tri %d\n", binary_result);
			}
		}break;
		case 6:
		{
			selection_sort(arr, n);
			printf("Mang sap xep tang dan theo Selection Sort: ");
			for (int i = 0; i < n; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
		}break;
	} while (lc < 8);
	return 0;
}