#include <stdio.h>
#include <stdlib.h>

#define B 20
#define Deleted -999999
#define Empty 999999 
typedef int ElementType;
typedef int Position;
typedef ElementType Dictionary[B];

void MakeNullSet(Dictionary D) {
	int i;
	for(i=0; i<B; i++)
		D[i]=Empty;
}

int H(ElementType X) {
	return X%B;
}

int Member(ElementType X, Dictionary D) {
	Position P = H(X); // ham bam
	int i=0, Found = 0;
	while ((i < B) && (D[P]!=Empty) && (!Found))
	    if (D[P] == X) Found = 1;
	    else {P=(P+1)%B; i++;}
		
	return Found;
} 

int FullSet(Dictionary D) {
	int i=0;
	int full=1;
	while ((i<B) && (full == 1))
		if((D[i] == Deleted) || (D[i] == Empty))
			full = 0;
		else
			i++;
			
	return full;		
}

void InsertSet(ElementType X, Dictionary D) {
	Position P;
	if (FullSet(D))
		printf("\nBang bam day\n");
	else if (!Member(X,D)){
		P = H(X); 
		int i = 0; 
		while((i<B)&& (D[P]!=Empty)&&(D[P]!=Deleted)) 
		{i++; P=(P+1)%B;}
		D[P]=X;
	} else
		printf("\nPhan tu da ton tai");
}

void DeleteSet(ElementType X, Dictionary D) {
	int i=0;
	Position P = H(X);
    while ((i<B) && (D[P]!=X) && (D[P]!=Empty)) 
    {i++; P=(P+1)%B;}
    if (D[P]==X)
        D[P]=Deleted;
}
 
void PrintSet(Dictionary D) {
	int i;
	for(i=0; i<B; i++)
		if((D[i] != Deleted) && (D[i] != Empty))
			printf("%d ",D[i]);
}

void ReadSet(Dictionary *D) {	
	int i,N;
	ElementType X;
	MakeNullSet(*D);
	printf("So phan tu tap hop N= ");
	scanf("%d",&N);
	for(i=1;i<=N;i++) { 
		printf("Phan tu thu %d: ",i);
		scanf("%d",&X);
		InsertSet(X,*D);
	}
}


main() {
	Dictionary D;
	ElementType X;
	
	ReadSet(&D);
	printf("Tap hop vua nhap: \n");
	PrintSet(D);
	
	printf("\nPhan tu can them vao: ");scanf("%d",&X);
	InsertSet(X, D);
	printf("Tap hop sau khi them phan tu la: \n");
	PrintSet(D);
	
	printf("\nPhan tu can xoa: ");scanf("%d",&X);
	DeleteSet(X,D);
	printf("Tap hop sau khi xoa %d la: \n",X);
	PrintSet(D);

	printf("\nPhan tu can tim: ");scanf("%d",&X);
	if (Member(X,D))
		printf("%d co trong tap hop\n",X);
	else	
		printf("%d khong co trong tap hop\n",X);

	
	return 0;
} 

 

  
