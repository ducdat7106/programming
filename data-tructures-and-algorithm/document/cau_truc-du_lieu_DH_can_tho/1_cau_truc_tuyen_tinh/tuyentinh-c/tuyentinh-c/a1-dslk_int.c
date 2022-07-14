#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node* NodeType;

struct Node {
	ElementType element;
	NodeType	next;
};

typedef NodeType Position;
typedef Position List;

void MakeNullList(List *Header) {
	(*Header)=(NodeType)malloc(sizeof(struct Node));
	(*Header)->next= NULL;
}

int EmptyList(List L) { 
	return (L->next==NULL);
}

 void InsertList(ElementType X,Position P, List *L) {	
	Position T;
	T=(NodeType)malloc(sizeof(struct Node));
	T->element=X;
	T->next=P->next;
	P->next=T;
}

 void InsertList1(ElementType X, int P1, List *L) {	
	Position P;
	P = *L;
	while((P->next != NULL) && (P1 > 1)) {
		P = P->next;
		P1--;
	}
	InsertList(X, P, L);
 }

void DeleteList(Position P, List *L) { 
	Position Temp;
	if (P->next!=NULL) {  
		Temp=P->next; 
		P->next=Temp->next; 
		free(Temp);
	}
}

Position Locate(ElementType X, List L) {	
	Position P;
	int Found = 0;
	P = L;
	while ((P->next != NULL) && (Found == 0))
		if (P->next->element == X) Found = 1;
		else P = P->next;
	return P;
} 
 
ElementType Retrieve(Position P, List L) {
	if (P->next!=NULL)
		return P->next->element;
} 

Position First(List L) {	
	return L; 
} 

Position EndList(List L) {
	Position P;
	P=First(L);
	while (P->next!=NULL) 
		P=P->next;
	return P;
}
 
Position Next(Position P, List L) {	
	return P->next;
}

void PrintList(List L) {
	Position P;
	P = First(L);
	while (P != EndList(L)) {
		printf("%d ",Retrieve(P,L));
		P = Next(P, L);
	}
	printf("\n");
}

void PrintRevList(List L) {

    if(L->next != NULL) {
		Position P = L->next;
		if(P->next == NULL)
			printf("%d ",P->element);
		else {
			PrintRevList(L->next);
			printf("%d ",P->element);			
		}	
	}
}

void ReadList(List *L) {	
	int i,N;
	ElementType X;
	MakeNullList(L);
	printf("So phan tu danh sach N= ");
	scanf("%d",&N);
	for(i=1;i<=N;i++) { 
		printf("Phan tu thu %d: ",i);
		scanf("%d",&X);
		InsertList(X,EndList(*L),L);
	}
}

int count(List L) {
	int sophtu = 0;
	Position P = First(L);
	while(P != EndList(L)) {
		sophtu++;
		P = Next(P, L);
	}
	return sophtu;
}

main() {
	List L;
	ElementType X;
	Position P;
	ReadList(&L);
	printf("Danh sach vua nhap: ");
	PrintList(L);
	
	printf("Danh sach nghich dao: ");
	PrintRevList(L);
	printf("\n");

	
	printf("Phan tu can them vao cuoi danh sach: ");scanf("%d",&X);
	InsertList(X,EndList(L),&L);
	printf("Dsach sau khi them phan tu la: ");
	PrintList(L);
	
	int P1;
	printf("Phan tu can them vao danh sach: ");scanf("%d",&X);
	printf("Vi tri can them: ");scanf("%d",&P1);
	InsertList1(X,P1,&L);
	printf("Dsach sau khi them phan tu la: ");
	PrintList(L);

	printf("Noi dung phan tu can xoa: ");
	scanf("%d",&X);
	P=Locate(X,L);
	DeleteList(P,&L);
	printf("Danh sach sau khi xoa %d la: ",X);
	PrintList(L);
	printf("So phan tu trong danh sach: %d\n", count(L));
	return 0;
} 

 

  
