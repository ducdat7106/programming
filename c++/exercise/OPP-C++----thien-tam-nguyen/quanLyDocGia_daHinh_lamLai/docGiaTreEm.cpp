#include "docGiaTreEm.h"

void docGiaTreEm::input()
{
	DocGia::input();
	cout << "\nVao ten nguoi dai dien: ";
	cin.ignore();
	getline(cin, hoTenNguoiDaiDien);
}

void docGiaTreEm::output()
{
	DocGia::output();
	cout << "Ten nguoi dai dien: " << hoTenNguoiDaiDien<<endl;
}

int docGiaTreEm::tienLamThe()
{
	return soThangCoHieuLuc * 5000;
}
docGiaTreEm::docGiaTreEm()
{
	hoTenNguoiDaiDien = "";
}

docGiaTreEm::~docGiaTreEm()
{
	hoTenNguoiDaiDien = "";
}