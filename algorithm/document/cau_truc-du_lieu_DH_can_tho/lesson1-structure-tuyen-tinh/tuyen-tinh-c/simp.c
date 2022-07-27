#include <stdio.h>

#define MaxLength 50 
#define Null -1 
typedef char	ElementType;
typedef	int		Position;   
typedef struct { 
  	ElementType Data; 
	Position Next; 
} Node; 
Node Space[MaxLength]; 
Position Available;
Position L;

/* khoi tao vung nho rong */
void Init() { 
	int i; 
	for(i=0; i<MaxLength-1; i++) 
		Space[i].Next=i+1;
	Space[MaxLength-1].Next=Null; 
	Available=0; 
}

/* di chuyen vung nho tu p sang q */
int Move(int *p, int *q) { 
	int temp; 
  	if (*p==Null) 
		return 0; //Khong co o de chuyen 
  	else { 
   		temp=*q; 
   		*q=*p; 
   		*p=Space[*q].Next; 
   		Space[*q].Next=temp; 
   		return 1; //Chuyen thanh cong 
 	} 
}

/* chen pt X vao vi tri P trong L */
void Insert_List(ElementType X, int P, int *L) { 
  	if (P==-1) {	//Xen dau danh sach 
		if (Move(&Available, L)) 
   			Space[*L].Data = X; 
   		else printf("Loi! Khong con bo nho trong"); 
    } 
    else {			//Chuyen mot o tu Available vao vi tri P 
		if (Move(&Available,&Space[P].Next)) 
   			Space[Space[P].Next].Data = X; 
   		else printf("Loi! Khong con vung nho trong"); 
    } 
} 

/* xoa pt sau P tu L */
void Delete_List(int P, int *L) { 
	if (P==-1) {	//Neu la o dau tien 
		if (!Move(L,&Available)) 
			printf("Loi trong khi xoa"); 
	} 
	else 
		if (!Move(&Space[P].Next,&Available)) 
			printf("Loi trong khi xoa"); 
}

/* doi vi tri sang chi so */
Position Pos_2_Idx(int Pos, Position L) {
	Position P = L;
	while (Pos > 1) {
		P = Space[P].Next;
		Pos--;
	}
	return P;
}

/* tim vi tri cua X trong L */
Position Locate(ElementType X, Position L) {	
	int Found = 0;
	Position P = L;
	while ((Space[P].Next != Null) && (Found == 0))
		if (Space[Space[P].Next].Data == X) Found = 1;
		else P = Space[P].Next;
	return P;
}

/* in danh sach */
void Print_List(Position L) {
	Position P = L;
	while (P != Null) {
		printf("%c\n", Space[P].Data);
		P = Space[P].Next;
	}	
}

/* nhap danh sach */
void Read_List(Position *L) {
	Position P;
	ElementType X;
	int i, nchar;
	/* khoi tao vung nho rong */
	Init();
	*L = Null;
	printf("nhap bao nhieu ky tu? "); scanf("%d",&nchar);
	for(i=0; i<nchar; i++) {
		getchar();
		printf("nhap ky tu: "); scanf("%c", &X);
		P = Null;	/* nhap vao dau danh sach */
		Insert_List(X, P, L);
	}
}

main() {
	ElementType X;
	Position P;
	printf("<<< nhap danh sach >>>\n");
	Read_List(&L);
	printf("<<< danh sach hien co >>>\n");
	Print_List(L);
	
	/* them ky tu X vao vi tri P */
	getchar();
	printf("nhap ky tu can them: "); scanf("%c", &X); 
	printf("nhap vi tri xen vao: "); scanf("%d", &P);
	/*Insert_List(X, P, &L);*/
	Insert_List(X, Pos_2_Idx(P, L), &L);
	printf("<<< danh sach hien co >>>\n");
	Print_List(L);
	
	/* xoa ky tu X */
	getchar();
	printf("nhap ky tu can xoa: "); scanf("%c", &X);
	P = Locate(X, L);
	Delete_List(P, &L);
	printf("<<< danh sach hien co >>>\n");
	Print_List(L);	
} 

