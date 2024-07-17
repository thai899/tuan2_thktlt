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
	} while (lc < 8);
	return 0;
}