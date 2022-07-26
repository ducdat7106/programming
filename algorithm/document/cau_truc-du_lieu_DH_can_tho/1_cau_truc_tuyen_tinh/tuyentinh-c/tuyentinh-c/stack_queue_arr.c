#include <stdio.h>
#include <stdlib.h>

#define MaxLength 50
typedef int ElementType;
typedef struct {
	ElementType Elements[MaxLength];
	int Top_idx; 
} Stack;

typedef struct {
	ElementType Elements[MaxLength]; 
	int Front, Rear; 
} Queue;

/* cac ham co ban cua ngan xep */
void MakeNull_Stack(Stack *S)	{
	S->Top_idx=MaxLength;
}

int Empty_Stack(Stack S)	{ 
	return S.Top_idx==MaxLength; 
}

int Full_Stack(Stack S) {	
	return S.Top_idx==0;
}

ElementType Top(Stack S) {
	if (!Empty_Stack(S))
		return S.Elements[S.Top_idx];
	else printf("Loi! Ngan xep rong");
}

void Pop(Stack *S) {
	if (!Empty_Stack(*S))
		S->Top_idx=S->Top_idx+1;
	else printf("Loi! Ngan xep rong!");
}

void Push(ElementType X, Stack *S) {
	if (Full_Stack(*S))
		printf("Loi! Ngan xep day!");
	else{
		S->Top_idx=S->Top_idx-1;
		S->Elements[S->Top_idx]=X;
	}
}

/* cac ham co ban cua hang doi */	
void MakeNull_Queue(Queue *Q) {
	Q->Front=-1;
	Q->Rear=-1;
}

int Empty_Queue(Queue Q) {
	return Q.Front==-1;
}

int Full_Queue(Queue Q) {
	return (Q.Rear-Q.Front+1) % MaxLength==0;
}

ElementType Front(Queue Q) {
	if (!Empty_Queue(Q)) 
		return Q.Elements[Q.Front];
}

void DeQueue(Queue *Q){
    if (!Empty_Queue(*Q)){
		if (Q->Front==Q->Rear) 
	        MakeNull_Queue(Q);
	    else Q->Front=(Q->Front+1) % MaxLength;
    }
    else printf("Loi: Hang rong!");
}

void EnQueue(ElementType X, Queue *Q) {
	if (!Full_Queue(*Q)){
		if (Empty_Queue(*Q)) 
            Q->Front=0;
		Q->Rear=(Q->Rear+1) % MaxLength;
		Q->Elements[Q->Rear]=X;
	}
    else printf("Loi: Hang day!");
} 

/* 
nhap n so nguyen dua vao stack
lay tung ptu tu dinh ngan xep bo vo hang doi
in toan bo cac ptu trong hang doi
*/
void demo() {
	Stack S;
	Queue Q;
	int n, i;
	ElementType X;
	/* nhap n so nguyen dua vao stack */
	MakeNull_Stack(&S);
	printf("co bao nhieu so nguyen ?"); scanf("%d", &n);
	for(i=0; i<n; i++) {
		printf("nhap so thu %d: ", i+1); scanf("%d", &X);
		Push(X, &S);
	}
	
	/* lay tung ptu tu dinh ngan xep bo vo hang doi */
	MakeNull_Queue(&Q);
	while(!Empty_Stack(S)) {
		EnQueue(Top(S), &Q);
		Pop(&S);
	}
	
	/* in toan bo cac ptu trong hang doi */
	printf("danh sach so nguyen theo thu tu nguoc\n");
	while(!Empty_Queue(Q)) {
		printf("%d\n", Front(Q));
		DeQueue(&Q);
	}
}

main() {
	demo();
}
