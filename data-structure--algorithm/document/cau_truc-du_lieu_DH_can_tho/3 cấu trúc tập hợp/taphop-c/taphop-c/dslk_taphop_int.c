#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node* NodeType;

struct Node {
	ElementType Data;
	NodeType	Next;
};

typedef NodeType Position;
typedef Position SET;

void MakeNull(SET *A) {
		(*A)=(NodeType)malloc(sizeof(struct Node));
		(*A)->Next= NULL;
} 

int EmptySet(SET A) { 
	return (A->Next==NULL);
}

 
ElementType Retrieve(Position P, SET A) {
	if (P->Next!=NULL)
		return P->Next->Data;
} 

Position First(SET A) {	
	return A; 
} 

Position End(SET A) {
	Position P;
	P=First(A);
	while (P->Next!=NULL) 
		P=P->Next;
	return P;
}
 
Position Next(Position P, SET A) {	
	return P->Next;
}

int Member(ElementType X, SET A) {
		Position P;
		int Found = 0;
		P = First(A);
		while ((P != End(A)) && (Found == 0))
			if (Retrieve(P, A) == X) Found = 1;
			else P = Next(P, A);
		return Found;
}
	
void Insert(ElementType X, SET *A)  {
		Position T;
		T=(NodeType)malloc(sizeof(struct Node));
		T->Data=X;
		T->Next=(*A)->Next;
		(*A)->Next=T;
}


void Print(SET A) {
	Position P;
	P = First(A);
	while (P != End(A)) {
		printf("%d ",Retrieve(P,A));
		P = Next(P, A);
	}
	printf("\n");
}

void Union(SET A, SET B, SET *C) {
    Position p;
  	MakeNull(C);
  	p=First(A);
  	while (p!=End(A)) { 
		Insert(Retrieve(p, A), C);
		p=Next(p,A);
    }
  	p=First(B);
 	while (p!=End(B)) {
  		if (!Member(Retrieve(p, B), *C))
         	     Insert(Retrieve(p, B), C);
	 	p=Next(p,B);
	}
} 

void Intersection(SET A, SET B, SET *C) {
	Position p;
	MakeNull(C);
	p=First(A);
	while (p!=End(A)) {
	    if (Member(Retrieve(p,A),B))  
	        Insert(Retrieve(p,A), C);
	    p=Next(p,A);
	}
}

void Difference(SET A, SET B, SET *C) {
	Position p;
	MakeNull(C);
	p=First(A);
	while (p!=End(A)) {
	    if (!Member(Retrieve(p,A),B))  
	        Insert(Retrieve(p,A), C);
	    p=Next(p,A);
	}
}

void Read(SET *A) {	
	int i,N;
	ElementType X;
	MakeNull(A);
	printf("So phan tu tap hop N= ");
	scanf("%d",&N);
	for(i=1;i<=N;i++) { 
		printf("Phan tu thu %d: ",i);
		scanf("%d",&X);
		if(!Member(X,*A))
			Insert(X,A);
	}
}

void Delete(ElementType X, SET *A) {
	Position T, P=*A;
	int  found=0;
	while ((P->Next!=NULL)&& (found==0))
		if  (P->Next->Data!=X) P=P->Next;
		else found=1;

	if (found==1) {  
		T=P->Next;
		P->Next=T->Next;
		free(T);
	}
}
	
main() {
	SET A, B, C;
	Read(&A);
	Read(&B);
	printf(" tap A \n"); Print(A);
	printf(" tap B \n"); Print(B);
	Union(A, B, &C);
	printf(" tap A union B \n"); Print(C);
	Intersection(A, B, &C);
	printf(" tap A intersect B \n"); Print(C);
	Difference(A, B, &C);
	printf(" tap A Diff B \n"); Print(C);	
	return 0;
} 

 

  
