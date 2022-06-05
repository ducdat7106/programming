#include "docGiaNguoiLon.h"

void docGiaNguoiLon::input()
{
	DocGia::input();
	cout << "\nVao so chung minh thu: ";
	fflush(stdin);
	getline(cin, chungMinhThu);
}

void docGiaNguoiLon::output()
{
	DocGia::output();
	cout << "\nSo CMND: " << chungMinhThu << endl;
}
int docGiaNguoiLon::tienLamThe()
{
	return soThangCoHieuLuc * 10000;
}

docGiaNguoiLon::docGiaNguoiLon()
{
	chungMinhThu = "";
}

docGiaNguoiLon::~docGiaNguoiLon()
{
	chungMinhThu = "";
}