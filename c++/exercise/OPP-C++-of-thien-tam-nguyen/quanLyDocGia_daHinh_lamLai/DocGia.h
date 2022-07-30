#pragma once
#include <iostream>
#include <string>
using namespace std;

class DocGia 
{
protected:
	string hoTen;
	string ngayLamThe;	//dd/mm/yyyy
	int soThangCoHieuLuc;
	bool test; //fasle:child; true:adult
public:
	DocGia();
	~DocGia();

	virtual void input();
	virtual void output();
	virtual int tienLamThe()=0;


	bool getTest()
	{
		return test;
	}

	void setTest(bool Test)
	{
		test = Test;
	}
};
