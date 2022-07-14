#include <stdio.h>
#include <stdlib.h>

#define MaxLength 50
typedef int ElementType;
typedef struct {
	ElementType Elements[MaxLength];
	int Top_idx;
} Stack;


void MakeNullStack(Stack *S) { 
	S->Top_idx=MaxLength;
}

int EmptyStack(Stack S) { 
	return S.Top_idx==MaxLength; 
}

int FullStack(Stack S) {	
	return S.Top_idx==0;
}


void Push(ElementType X, Stack *S) { 
	if (FullStack(*S))
		printf("Loi! Ngan xep day!");
	else {
		S->Top_idx=S->Top_idx-1;
		S->Elements[S->Top_idx]=X;
	}
}	

void Pop(Stack *S) {
	if (!EmptyStack(*S))
		S->Top_idx=S->Top_idx+1;
	else printf("Loi! Ngan xep rong!");
}

ElementType Top(Stack S) {
	if (!EmptyStack(S))
		return S.Elements[S.Top_idx];
	else printf("Loi! Ngan xep rong");
} 
   
void ConvEngine(Stack *S) {	
	int i, N;
	MakeNullStack(S);
	printf("So thap phan can doi N= ");
	scanf("%d",&N);
	while (N!=0) {
		Push(N%2, S);
		N = N/2;
	}
}

void PrintStack(Stack S) {
	while (!EmptyStack(S)) {
		printf("%d ",Top(S));
		Pop(&S);
	}
	printf("\n");
}


main() {
	Stack S;
	ConvEngine(&S);
	printf("So nhi phan tuong ung: ");
	PrintStack(S); 
	return 0;
} 

 

  
