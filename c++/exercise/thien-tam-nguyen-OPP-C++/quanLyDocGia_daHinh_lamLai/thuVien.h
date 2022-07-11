#pragma once

#include "docGiaNguoiLon.h"
#include "docGiaTreEm.h"

#include <vector>

class thuVien
{
private:
	vector<DocGia*>  ds_docGia;

public:
	void input();
	void output();
	long tongTienLamThe();

	thuVien();
	~thuVien();
};


