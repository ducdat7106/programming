#include<iostream>

using namespace std;

//nhap danh sach lien ket don cac so nguyen
//tim gia tri lon nhat

//======khai bao cau truc danh sach lien ket cac so nguyen======
//khai bao cau truc 1 node
struct node
{
    int data;//du lieu chua trong 1 cai node
    struct node *pNext;//con tro dung de lien ket giua cac node voi nhau
};
typedef struct node NODE;//thay the "struct node" thanh "Node"

//khai bao cau truc cua danh sach lien ket don
struct list
{
    NODE *pHead;//node quan ly dau danh sach
    NODE *pTail;//node quan ly cuoi danh sach
};
typedef struct list LIST;

//======khoi tao cau truc danh sach lien ket cac so nguyen======
void khoiTao(LIST &l)
{
    //cho 2 node tro den NULL - vi danh sach lien ket don chua co phan tu
    l.pHead=NULL;
    l.pTail=NULL;
}

// ham khoi tao  1 node
NODE *khoiTaoNODE(int x)
{
    NODE *p = new NODE;//cap phat vung nho cho NODE p
    if(p == NULL)//neu cap phat khong thanh cong
    {
        cout<<"\nkhong du bo nho de cap phat";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;//tra ve NODE p vua khoi tao
}

//ham them node p vao dau danh sach lien ket
void themVaoDau(LIST &l, NODE *p)
{
    //danh sach dang rong
    if(l.pHead==NULL)
    {
        l.pHead=l.pTail=p;//node dau cung chinh la node cuoi va la p
    }
    else
    {
        p->pNext = l.pHead;//cho con tro cua node can them la node p lien ket den node dau - pHead 
        l.pHead = p;//cap nhat lai pHead chinh la node p
    }
}

//ham them node p vao cuoi danh sach lien ket don
void themVaoCuoi(LIST &l, NODE *p)
{
    //danh sach dang rong
    if(l.pHead==NULL)
    {
        l.pHead=l.pTail=p;//node dau cung chinh la node cuoi va la p
    }
    else
    {
        l.pTail->pNext = p;//cho con tro cua pTail lien ket voi node p
        l.pTail = p;//cap nhat lai p la node pTail
    }
}

//ham suat danh sach lien ket don
void xuatDanhSach(LIST l)
{
    for(NODE *k=l.pHead; k!=NULL; k=k->pNext)
    {
        cout<<k->data<<"  ";
    }
}

//ham tim gia tri lon nhat trong danh sach
int timMax(LIST l)
{
    //gia su node dau la node lon nhat
    int max = l.pHead->data;

    //bat dau duyet tu node thu 2 de kiem tra
    for(NODE *k = l.pHead->pNext; k!=NULL; k=k->pNext)
    {
        if(max<k->data)
        {
            max = k->data;//cap nhat gia tri cho max
        }
    }
    return max;
}

int main()
{
    LIST l;
    khoiTao(l);//khoi tao danh sach lien ket don

    int n;
    cout<<"\nnhap so luong node can them ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int x;
        cout<<"\nnhap gia tri so nguyen thu "<<i+1<<" ";
        cin>>x;
        NODE *p = khoiTaoNODE(x);//khoi tao 1 cai node so nguyen
        themVaoCuoi(l,p);//them node p vao dau danh sach lien ket don l
    }

    cout<<"\n\n\tDANH SACH LIEN KET DON";
    xuatDanhSach(l);

    cout<<"\ngia tri lon nhat " << timMax(l)<<endl;

    system("pause");
    return 0;
}