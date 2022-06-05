#include<iostream>
#include <string>
#include<fstream>//doc ghi file

using namespace std;

//khai bao cấu trúc lớp ngày tháng năm sinh
class NamSinh {
private:
	int ngay, thang, nam;
public:
	NamSinh() {
		ngay = thang = nam = 0;
	}

	~NamSinh() {
		ngay = thang = nam = 0;
	}

	int getter_ngay() {
		return ngay;
	}

	void setter_ngay(int ng) {
		ngay=ng;
	}

	int getter_thang() {
		return thang;
	}

	void setter_thang(int th) {
		thang = th;
	}

	int getter_nam() {
		return nam;
	}

	void setter_nam(int na) {
		nam = na;
	}
};

//khai bao lop cha : NhanVien
class NhanVien 
{
protected:
	string maNhanVien;
	string tenNhanVien;
	NamSinh namsinh;
	string diaChi;
	float luongCoBan;
	float heSoLuong;
public:
	NhanVien()
	{
		luongCoBan = heSoLuong = 0.0f;
	}
	virtual void Doc_File(ifstream&);
	virtual void XuatThongTin();
};

void NhanVien::Doc_File(ifstream& fileIn) 
{
	getline(fileIn, maNhanVien, ',');

	fileIn.seekg(1, 1);//dịch con trỏ chỉ vị trí của file tại vị trí hiện tại sang phải 1 byte
	getline(fileIn, tenNhanVien, ',');

	int ngay;
	fileIn >> ngay;
	namsinh.setter_ngay(ngay);

	fileIn.seekg(1, 1);//dịch con trỏ chỉ vị trí của file tại vị trí hiện tại sang phải 1 byte
	int thang;
	fileIn >> thang;
	namsinh.setter_thang(thang);

	fileIn.seekg(1, 1);//dịch con trỏ chỉ vị trí của file tại vị trí hiện tại sang phải 1 byte
	int nam;
	fileIn >> nam;
	namsinh.setter_nam(nam);

	fileIn.seekg(2, 1);//dịch con trỏ chỉ vị trí của file tại vị trí hiện tại sang phải 2 byte
	getline(fileIn, diaChi, ',');

	fileIn >> heSoLuong;

	fileIn.seekg(1, 1);//dịch con trỏ chỉ vị trí của file tại vị trí hiện tại sang phải 1 byte
	fileIn >> luongCoBan;

	fileIn.seekg(1, 1);//dịch con trỏ chỉ vị trí của file tại vị trí hiện tại sang phải 1 byte
}

void NhanVien::XuatThongTin()
{
	cout << "\nMa nhan vien: " << maNhanVien;
	cout << "\nHo ten nhan vien:" << tenNhanVien;
	cout << "\nNgay thang nam sinh: " << namsinh.getter_ngay() << "/" << namsinh.getter_thang() << "/" << namsinh.getter_nam() << endl;
	cout << "\nDia chi: " << diaChi;
	cout << "\nHe so luong: " << heSoLuong;
	cout << "\nLuong co ban: " << (size_t)luongCoBan;
}


//khai baos lopws con nhanVienlap trinh kees thua lopws cha
class NhanVienLapTrinh : public NhanVien 
{
private:
	float tienLamNgoaiGio;

public:
	NhanVienLapTrinh()
	{
		tienLamNgoaiGio = 0.0f;
	}
	void Doc_File(ifstream&);
	void XuatThongTin();

};

void NhanVienLapTrinh::Doc_File(ifstream& fileIn)
{
	NhanVien::Doc_File(fileIn);

	fileIn >> tienLamNgoaiGio;
}

void NhanVienLapTrinh::XuatThongTin()
{
	NhanVien::XuatThongTin();
	cout << "\nTien lam ngoai gio: " << (size_t)tienLamNgoaiGio;
}
class NhanVienThietKe : public NhanVien {
private:
	float tienThuong;

public:
	NhanVienThietKe()
	{
		tienThuong = 0.0f;
	}
	void Doc_File(ifstream&);
	void XuatThongTin();
};

void NhanVienThietKe::Doc_File(ifstream& fileIn)
{
	NhanVien::Doc_File(fileIn);

	fileIn >> tienThuong;
}

void NhanVienThietKe::XuatThongTin()
{
	NhanVien::XuatThongTin();
	cout << "\nTien thuong: " << (size_t)tienThuong;
}



void Menu(NhanVien *ds[], int& n)
{
	ifstream filein;
	filein.open("NhanVien.txt", ios_base::in);

	while (true) 
	{
		system("cls");
		cout << "\n\n\t\t=====Menu=====";
		cout << "\n1. Doc thong tin nhan vien tu file";
		cout << "\n2. Xuat danh sach sinh vien";
		cout << "\n0. Ket thuc"; 
		cout << "\n\n\t\t======END======";

		int luaChon;
		cout << "\nNhap lua chon: ";
		cin >> luaChon;

		if (luaChon == 0)
		{
			system("cls");
			break;
		}
		else if (luaChon < 0 || luaChon>2)
		{
			cout << "\nNhap sai! Moi nhap lai!\n";
			system("pause");
		}
		else if(luaChon == 1)
		{
			filein >> n;
			cout <<"\nSo luong nhan vien nhap vao tu file n = "<< n << endl;

			NhanVien* x = NULL;

			for (int i = 0; i < n; i++)
			{
				char c;
				filein >> c;
				filein.seekg(-1, 1);//dịch sang trái 1 byte để về đầu dòng

				if (c == 'P')
				{
					x = new NhanVienLapTrinh();
					x->Doc_File(filein);
				}
				else if (c == 'D')
				{
					x = new NhanVienThietKe();
					x->Doc_File(filein);
				}
				ds[i] = x;
			}
			system("pause");
		}
		else if (luaChon == 2)
		{
			for (int i=0; i<n; i++)
			{
				cout << "\n\n\t\tNHAN VIEN THONG TIN THU " << i + 1 << endl;
				ds[i]->XuatThongTin();
			}
			system("pause");
		}
	}

	filein.close();
}


int main()
{
	NhanVien* ds[100]; //khai bao mang 1 chieu luu tru 2 loai nhan vien
	int n = 0;//số lượng nhân viên hiện có trong mảng này

	Menu(ds, n);

	system("pause");
	return 0;
}