#include "DocGia.h"

void DocGia::input()
{
	cout << "\nVao ho ten:";
	cin.ignore();
	getline(cin, hoTen);

	cout << "\nVao thoi gian lam the: ";
	cin.ignore();
	getline(cin, ngayLamThe);

	cout << "\nVao so thang co hieu luc: ";
	cin >> soThangCoHieuLuc;
}

void DocGia::output()
{
	cout << "\nHo Ten: " << hoTen << endl;
	cout << "\nNgay lam the: " << ngayLamThe << endl;
	cout << "\nHieu luc: " << soThangCoHieuLuc << endl;
}

DocGia::DocGia()
{
	soThangCoHieuLuc = 0;
	test = 0;
}

DocGia::~DocGia()
{
	soThangCoHieuLuc = 0;
	test = 0;
}

