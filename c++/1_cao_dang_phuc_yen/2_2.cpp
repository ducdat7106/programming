#include<iostream>
#include<string.h>

using namespace std;

#define MaxLength 100

class May;
class MayTinh;

class NhaSanXuat
{
    private:
        char Ten_NSX[30];
        char Dia_Chi[30];

        friend class May;
        friend class MayTinh;

        friend void In(MayTinh *mt, int value);
};

class May
{
    public:
        char Nhan_Hieu[30];
        NhaSanXuat NSX;
        int Gia_Thanh;

        void input();
        void output();
};

class MayTinh:public May
{
    private:
        int Toc_Do, DungLuongRam, DungLuongHHD;
    public:
        void input();
        void output();

        friend void In(MayTinh *mt, int value);
        friend void giaTB(MayTinh mt[], int n);
};


void May::input()
{
    cout<<"Nhap nhan hieu: ";
    fflush(stdin);
    fgets(Nhan_Hieu, 30, stdin);

    cout<<"Nhap nha san xuat:\n";

    cout<<"Nhap ten nsx: ";
    fflush(stdin);
    fgets(NSX.Ten_NSX, 30, stdin);

    cout << "Nhap dia chi: ";
    fflush(stdin);
    fgets(NSX.Dia_Chi, 30, stdin);

    cout<<"Nhap gia thanh: ";
    cin>>Gia_Thanh;
}

void May::output()
{
    cout<<"Nhan hieu: "<<Nhan_Hieu;
    
    cout<<"Ten nha san xuat: "<<NSX.Ten_NSX;

    cout<<"Dia chi: "<<NSX.Dia_Chi;

    cout<<"Gia thanh: "<<Gia_Thanh<<endl;
}

void MayTinh::input()
{
    May::input();

    cout<<"Nhap toc do: ";
    cin>>Toc_Do;

    cout << "Nhap dung luong Ram: ";
    cin >> DungLuongRam;

    cout<<"Nhap dung luong HHD: ";
    cin>>DungLuongHHD;
}

void MayTinh::output()
{
    May::output();

    cout<<"Toc do: "<<Toc_Do<<endl;
    cout<<"Dung luong Ram: "<<DungLuongRam<<endl;
    cout<<"Dung luong HHD: "<<DungLuongHHD<<endl;
}

void In(MayTinh *mt, int value)
{
    for(int i=0; i<value; i++)
    {
        // if (strcmp(mt[i].NSX.Ten_NSX, "Intel\n") == 0)
        if (strcmp(mt[i].NSX.Ten_NSX, "A\n") == 0)
            mt[i].output();
    }
}


void swap(MayTinh *a1, MayTinh *a2)
{
    MayTinh temp = *a1;
    *a1=*a2;
    *a2=temp;
}


void sort(MayTinh *mt, int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(mt[i].Gia_Thanh < mt[j].Gia_Thanh)
                swap(mt[i], mt[j]);
}

void giaTB(MayTinh mt[], int n)
{
    float sum=0;

    for(int i=0; i<n; i++)
        sum += mt[i].Gia_Thanh;
    
    sum /= n;

    cout<<"\nGia trung binh moi chieu may tinh: "<<sum<<endl;
}

int main()
{
    system("cls");

    MayTinh arr[MaxLength];
    int n, i;

    cout<<"n = ";
    cin>>n;

    cout<<"\n=====Nhap:\n";
    for(i=0; i<n; i++)
    {
        cout << "May " << i + 1 << endl;
        arr[i].input();
        cout<<endl;
    }

    /*
    cout<<"\n=====Xuat:\n";
    for (i = 0; i < n; i++)
    {
        cout<<"May "<<i+1<<endl;
        arr[i].output();
        cout << endl;
    }
    */

   /*
   cout<<"\nMay cua nha san xuat A:\n";
   In(arr, n);
    */

   /*
   sort(arr, n);
   cout<<"\n=====Sap xep giam dan theo gia:\n";
    for(i=0; i<n; i++)
        arr[i].output();
    */

    giaTB(arr, n);

    system("pause");
}