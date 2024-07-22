﻿#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<time.h>
typedef struct {
	int phanNguyen;
	int tuSo;
	int mauSo;
} HonSo;
void menu()
{
	printf("\n1.Tao mang chua hon so");
	printf("\n2.Xuat mang chua hon so");
	printf("\n3.So sanh 2 hon so");
	printf("\n4.Chuyen hon so thanh phan so");
	printf("\n5.Chuyen phan so thanh hon so");
	printf("\n6.Tong hieu tich thuong hon so");
	printf("\n7.Sap xep tang mang ");
}
HonSo taoHonSo(int phanNguyen, int tuSo, int mauSo) {
	HonSo hs;
	hs.phanNguyen = phanNguyen;
	hs.tuSo = tuSo;
	hs.mauSo = mauSo;
	return hs;
}
HonSo taoHonSoNgauNhien() {
	int phanNguyen = rand() % 10;
	int tuSo = rand() % 10;
	int mauSo = rand() % 9 + 1; 
	return taoHonSo(phanNguyen, tuSo, mauSo);
}
void xuatHonSo(HonSo hs) {
	printf("%d %d/%d\n", hs.phanNguyen, hs.tuSo, hs.mauSo);
}
int soSanhHonSo(HonSo hs1, HonSo hs2) {
	double giaTri1 = hs1.phanNguyen + (double)hs1.tuSo / hs1.mauSo;
	double giaTri2 = hs2.phanNguyen + (double)hs2.tuSo / hs2.mauSo;
	if (giaTri1 < giaTri2) return -1;
	if (giaTri1 > giaTri2) return 1;
	return 0;
}
void chuyenHonSoThanhPhanSo(HonSo hs, int* tuSo, int* mauSo) {
	*tuSo = hs.phanNguyen * hs.mauSo + hs.tuSo;
	*mauSo = hs.mauSo;
}

int main()
{
	int lc;
	srand(time(NULL));
	int n = 5;
	HonSo b[5];
	
	do {
		menu();
		printf("\nMoi ban chon ");
		scanf_s("%d", &lc);
		switch (lc)
		{
		case 1 :
		{
			
			for (int i = 0; i < n; i++) 
			{
				b[i] = taoHonSoNgauNhien();
			}
		}break;
		case 2:
		{

			printf("Danh sach hon so:\n");
			for (int i = 0; i < n; i++) {
				xuatHonSo(b[i]);
			}
		}break;
		case 3:
		{
			HonSo hs1 = taoHonSoNgauNhien();
			HonSo hs2 = taoHonSoNgauNhien();

			printf("Hon so 1: ");
			xuatHonSo(hs1);
			printf("Hon so 2: ");
			xuatHonSo(hs2);

			int ketQua = soSanhHonSo(hs1, hs2);
			if (ketQua < 0) {
				printf("Hon so 1 nho hơn hon so 2\n");
			}
			else if (ketQua > 0) {
				printf("Hon so 1 lon hon hon so 2\n");
			}
			else {
				printf("Hon so 1 bang hon so 2\n");
			}
		}break;
		case 4:
		{
			int tuSo, mauSo;
			HonSo hs = taoHonSoNgauNhien();
			printf("Hon so : ");
			xuatHonSo(hs);
			chuyenHonSoThanhPhanSo(hs, &tuSo, &mauSo);
			printf("Phan so sau khi chuyen: %d/%d\n", tuSo, mauSo);
		}break;
		case 5:
		{}break;
		case 6:
		{}break;
		case 7:
		{}break;
		}
	} while(lc<8);
	return 0;
}