#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int	msnv;
	char	ten[30];
	int	tuoi;
} ElementType;

typedef struct Node* NodeType;

struct Node {
	ElementType element;
	NodeType	next;
};

typedef NodeType Position;
typedef Position List;

void MakeNullList(List *header) {
	(*header)=(NodeType)malloc(sizeof(struct Node));
	(*header)->next= NULL;
}

int EmptyList(List L) { 
	return (L->next==NULL);
}

Position First(List L) {	
	return L; 
} 

Position EndList(List L) {
	Position p;
	p=First(L);
	while (p->next!=NULL) 
		p=p->next;
	return p;
}
 
Position Next(Position p, List L) {	
	return p->next;
}

void InsertList(ElementType x,Position p, List *L) {	
	Position t;
	t=(NodeType)malloc(sizeof(struct Node));
	t->element=x;
	t->next=p->next;
	p->next=t;
}

void DeleteList(Position p, List *L) { 
	Position temp;
	if (p->next!=NULL) {  
		temp=p->next; 
		p->next=temp->next; 
		free(temp);
	}
}

Position Find(int maso, List L) {	
	Position p;
	int Found = 0;
	p = L;
	while ((p->next != NULL) && (Found == 0))
		if (p->next->element.msnv == maso) Found = 1;
		else p = p->next;
	return p;
} 

void Delete(int maso, List *L) { 
	Position p;
	p = Find(maso, *L);
	if(p != EndList(*L))
		DeleteList(p, L);
	else
		printf("Khong thay nhan vien co ma so nay\n");
}

Position LocateSortedList(int tuoi, List L) {	
	Position p;
	p = L;
	while ((p->next != NULL) && (p->next->element.tuoi < tuoi))
		p = Next(p, L);
	return p;
} 

void InsertSortedList(ElementType x, List *L) {
	Position p = LocateSortedList(x.tuoi, *L);
	InsertList(x, p, L);
}
 
ElementType Retrieve(Position p, List L) {
	if (p->next!=NULL)
		return p->next->element;
} 

void Sort(List *L) {
	Position p, q, smallest;
	p = First(*L);
	
	while (p->next != NULL) {
		smallest = p;
		q = Next(p, *L);
		while (q->next != NULL) {
			if (q->next->element.tuoi < smallest->next->element.tuoi) 
				smallest = q;
			q = Next(q, *L);
		}
		ElementType x;
		x = p->next->element;
		p->next->element = smallest->next->element;
		smallest->next->element = x;
		p = Next(p, *L);
	}
}

void PrintList(List L) {
	Position p;
	ElementType x;
	p = First(L);
	while (p != EndList(L)) {
		x = Retrieve(p,L);
		printf("%d:%s:%d\n",x.msnv, x.ten, x.tuoi);
		p = Next(p, L);
	}
	printf("\n");
}

void ReadList(List *L) {	
	int i, n;
	MakeNullList(L);
	printf("So phan tu danh sach N= ");
	scanf("%d",&n);
	for(i=1;i<=n;i++) { 
		ElementType x;
		printf("Phan tu thu %d: \n",i);
		printf("Ma so nhan vien: "); scanf("%d",&x.msnv);
		getchar();
		printf("Ho ten nhan vien: "); gets(x.ten);
		printf("Tuoi nhan vien: "); scanf("%d",&x.tuoi);
		if(Find(x.msnv, *L) == EndList(*L))
			InsertList(x,EndList(*L),L);
		else
			printf("Ma so nhan vien da ton tai\n");
	}
}

double tuoitb(List L) {
	int sophtu = 0;
	int tongtuoi = 0;
	Position p = First(L);
	while(p != EndList(L)) {
		sophtu++;
		p = Next(p, L);
		tongtuoi = tongtuoi + p->element.tuoi;
	}
	return 1.0*tongtuoi/sophtu;
}

main() {
	List L;
	ElementType x;
	int maso;
	ReadList(&L);
	printf("Danh sach hien tai la:\n");
	PrintList(L);
	printf("Danh sach sau khi sap xep theo tuoi tang la:\n");
	Sort(&L);
	PrintList(L);
	printf("Tuoi trung binh:%5.2f\n", tuoitb(L));
	printf("Ma so nhan vien can xoa: "); scanf("%d", &maso);
	Delete(maso, &L);
	printf("Danh sach sau khi xoa la:\n");
	PrintList(L);
	printf("Phan tu can them\n");
	printf("Ma so nhan vien: "); scanf("%d",&x.msnv);
	getchar();
	printf("Ho ten nhan vien: "); gets(x.ten);
	printf("Tuoi nhan vien: "); scanf("%d",&x.tuoi);
	InsertSortedList(x, &L);
	printf("Danh sach hien tai la:\n");
	PrintList(L);
		
	return 0;
} 

 

  
