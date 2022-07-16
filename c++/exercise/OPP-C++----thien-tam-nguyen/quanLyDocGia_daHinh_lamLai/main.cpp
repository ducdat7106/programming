#include "main.h"

int main()
{
	thuVien* x = new thuVien;

	x->input();
	x->output();
	cout << "\nTong tien lam the: " << x->tongTienLamThe() << endl;

	delete x;
	x = NULL;

	system("pause");
	return 0;
}