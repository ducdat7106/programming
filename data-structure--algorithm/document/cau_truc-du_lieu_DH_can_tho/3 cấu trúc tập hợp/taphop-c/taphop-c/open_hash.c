#include <stdio.h>
#include <stdlib.h>

#define B 20

typedef int ElementType;
typedef struct Node* NodeType;
struct Node {
	ElementType Data;
	NodeType	Next;
};

typedef NodeType Position;
typedef Position Dictionary[B];

void MakeNullSet(Dictionary *D) {
	int i;
	for(i=0; i<B; i++)
		(*D)[i]=NULL;
}

int H(ElementType X) {
	return X%B;
}

int Member(ElementType X, Dictionary D) {
	Position P;
	int Found=0;
	P=D[H(X)]; //Tim o muc H(X)
	//Duyet tren ds thu H(X)
	while((P!=NULL) && (!Found))
			if (P->Data==X) Found=1;
			else P=P->Next;
	return Found;
}

void InsertSet(ElementType X, Dictionary *D){
	if (!Member(X,*D)){
		NodeType temp;
		temp =(NodeType)malloc(sizeof(struct Node));
		temp->Data = X;
		temp-> Next = (*D)[H(X)];
		(*D)[H(X)] = temp;
	}
}

void DeleteSet(ElementType X, Dictionary *D) {
	Position P, Q;
	if((*D)[H(X)]!=NULL) {
		if ((*D)[H(X)]->Data==X) {
			Q=(*D)[H(X)];
			(*D)[H(X)]=(*D)[H(X)]->Next;
			free(Q);
		} else {
		    int Found = 0;
			P=(*D)[H(X)];
		    while ((P->Next!=NULL) && (!Found))
				if (P->Next->Data==X) Found=1; 
				else P=P->Next;
			if(Found) {
				Q=P->Next; 
				P->Next=Q->Next;
				free(Q);
			}
		}
	}
} 
 
void PrintSet(Dictionary D) {
	int i;
	for(i=0; i<B; i++) {
		Position P = D[i];
		printf("[__%d__]=> ",i);
		while (P != NULL) {
			printf("[%d]=> ",P->Data);
			P = P->Next;
		}
		printf("[]\n");
	}	
}


void ReadSet(Dictionary *D) {	
	int i,N;
	ElementType X;
	MakeNullSet(D);
	printf("So phan tu tap hop N= ");
	scanf("%d",&N);
	for(i=1;i<=N;i++) { 
		printf("Phan tu thu %d: ",i);
		scanf("%d",&X);
		InsertSet(X,D);
	}
}


main() {
	Dictionary D;
	ElementType X;
	
	ReadSet(&D);
	printf("Tap hop vua nhap: \n");
	PrintSet(D);
	
	printf("Phan tu can them vao: ");scanf("%d",&X);
	InsertSet(X, &D);
	printf("Tap hop sau khi them phan tu la: \n");
	PrintSet(D);
	
	printf("Phan tu can xoa: ");scanf("%d",&X);
	DeleteSet(X,&D);
	printf("Tap hop sau khi xoa %d la: \n",X);
	PrintSet(D);

	printf("Phan tu can tim: ");scanf("%d",&X);
	if (Member(X,D))
		printf("%d co trong tap hop\n",X);
	else	
		printf("%d khong co trong tap hop\n",X);

	
	return 0;
} 

 

  
