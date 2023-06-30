#include <stdio.h>
#include <stdlib.h>

#define True (-1)
#define False (0)

//#define URUNEN 366

//プロトタイプ宣言
int nengappi(int iYear, int iNissu, int* inen, int* ituki, int* ihi);
int IsUru(int inen);

int main(int iargc, char* psargv[])
{
	int iyear;
	int inissu;

	int inen;
	int ituki;
	int ihi;

	char *pcendptr[2];

	if (iargc != 3) {
		printf("使い方： ./gappi 年 日数\n");
		printf("    年・日数は正の整数を入力してください。\n");
	}
	
	iyear = strtol(psargv[1], &pcendptr[0], 0);
	inissu = strtol(psargv[2], &pcendptr[1], 0);

	if (*pcendptr[0] != '\0' || iyear < 0) {
		printf("年の値が不正です。（正の整数を入力してください。\n");
		printf("入力されたデータは[%s]です。", psargv[1]);
		return -1;
	}
	if (*pcendptr[1] != '\0' || inissu < 0) {
		printf("日数の値が不正です。（正の整数を入力してください。\n");
		printf("入力されたデータは[%s]です。", psargv[2]);
		return -2;
	}
printf("%d, %d\n", iyear, inissu);

	//年月日の算出
	nengappi(iyear, inissu, &inen, &ituki, &ihi);

	//結果表示
	printf("%d年1月1日から　%d 日後は\n", iyear, inissu);
	printf("%d年%d月%d日です。\n", inen, ituki, ihi);
	return 0;
}

//年月日の関数
int nengappi(int iYear, int iNissu, int* inen, int* ituki, int* ihi)
{
	//年の算出
	*inen = iYear;
	for ( ; ; ) {
		if (IsUru(*inen) == True) {
			if (iNissu > 366) {
				iNissu -= 366;
				(*inen)++;
			}
			else {
				break;
			}
		}
		else {
			if (iNissu > 365) {
				iNissu -= 365;
				(*inen)++;
			}
			else {
				break;
			}
		}
	}
	//月の算出
	*ituki = 1;
	for ( ; ; ) {
		if (*ituki == 1 || *ituki == 3 || *ituki == 5 ||
			*ituki == 7 || *ituki == 8 || *ituki == 10 || *ituki == 12) {
			if (iNissu > 31) {
				iNissu -= 31;
				(*ituki)++;
			}
			else {
				break;
			}
		}
		else if (*ituki == 4 || *ituki == 6 || *ituki == 9 || *ituki == 11) {
			if (iNissu > 30) {
				iNissu -= 30;
				(*ituki)++;
			}
			else {
				break;
			}
		}
		else {	//2月
			if (IsUru(*inen) == True) {
				if (iNissu > 29) {
					iNissu -= 29;
					(*ituki)++;
				}
				else {
					break;
				}
			}
			else {
				if (iNissu > 28) {
					iNissu -= 28;
					(*ituki)++;
				}
				else {
					break;
				}
			}
		}
	}
	*ihi = iNissu;

	return 0;
} 

//うるう年チェックの関数
int IsUru(int inen)
{
	int iKekka;

	if (inen % 4 == 0) {
		if (inen % 100 == 0) {
			if (inen % 400 == 0) {
				iKekka = True;
			}
			else {
				iKekka = False;
			}
		}
		else {
			iKekka = True;
		}
	}
	else {
		iKekka = False;
	}

	return iKekka;
}
