#include<iostream>

using namespace std;

struct SinhVien
{
    char Ten[50];
    char MaSo[50];
    float DTB;
    SinhVien *pNext;
};

struct List
{
    SinhVien *pHead, *pTail;
};

