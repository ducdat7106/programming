#include "thuVien.h"

thuVien::thuVien()
{

}

thuVien::~thuVien()
{

}


void thuVien::input()
{
	int choose;
	while (1)
	{
		system("cls");
		cout << "\n\t\t=====Thu vien Y=====\n";
		cout << "\n\t\t0. thoat";
		cout << "\n\t\t1. tre em\n";
		cout << "\n\t\t2. nguoi lon\n";
		cout << "\n\t\t3. sap xep theo so thang co hieu luc tang dan\n";
		cout << "\n\t\t=====END=====";

		cout << "\n\nNhap lua chon cua ban: ";
		cin >> choose;

		DocGia* x;

		if (choose == 0)
		{
			system("cls");
			break;
		}
		else if (choose < 0 || choose >3)
		{
			cout << "\nNhap sai. Moi nhap lai.";
			system("pause");
		}
		else if (choose == 1)
		{
			x = new docGiaTreEm;
			cout << "\nNhap thong tin doc gia: \n";
			x->input();
			x->setTest(true);
			ds_docGia.push_back(x);

		}
		else if (choose == 2)
		{
			x = new docGiaNguoiLon;
			cout << "\nNhap thong tin doc gia: \n";
			x->input();
			x->setTest(false);
			ds_docGia.push_back(x);
		}
		else if (choose == 3)
		{

		}

	}
}

void thuVien::output()
{
	cout << "\n=====DANH SACH DOC GIA=====\n";
	for (int i = 0; i < ds_docGia.size(); i++)
	{
		if (ds_docGia[i]->getTest() == false)
		{
			cout << "\nThong tin doc gia nguoi lon thu " << i + 1;
			ds_docGia[i]->output();
		}
		else
		{
			cout << "\nThong tin doc gia tre em thu " << i + 1;
			ds_docGia[i]->output();
		}
	}
}

long thuVien::tongTienLamThe()
{
	long sum = 0;

	for (int i = 0; i < ds_docGia.size(); i++)
	{
		sum += ds_docGia[i]->tienLamThe();
	}

	return sum;
}