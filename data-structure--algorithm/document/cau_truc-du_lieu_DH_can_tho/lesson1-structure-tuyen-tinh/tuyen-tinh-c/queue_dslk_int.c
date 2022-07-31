#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node* NodeType;

struct Node {
	ElementType element;
	NodeType	next;
};

typedef NodeType Position;

typedef struct {
	Position Front, Rear;
} Queue; 

Queue Q;

void MakeNullQueue(Queue *Q) {
	Position Header;
	Header=(NodeType)malloc(sizeof(struct Node)); 
	Header->next=NULL;
	Q->Front=Header;
	Q->Rear=Header;
}

int EmptyQueue(Queue Q) {
	return (Q.Front==Q.Rear);
} 

void EnQueue(ElementType X, Queue *Q) { 
	Q->Rear->next=(NodeType)malloc(sizeof(struct Node));
	Q->Rear=Q->Rear->next;
	Q->Rear->element=X;
	Q->Rear->next=NULL;
} 

void DeQueue(Queue *Q) {
	if (!EmptyQueue(*Q)){
		Position Tempt;
		Tempt=Q->Front;
		Q->Front=Q->Front->next;
		free(Tempt);
	}else printf("Loi : Hang rong");
 } 

ElementType RetrieveFirst(Queue Q) {
	if (!EmptyQueue(Q))
		return Q.Front->next->element;
} 

void ReadQueue(Queue *Q) {	
	int i,N;
	ElementType X;
	MakeNullQueue(Q);
	printf("So phan tu danh sach N= ");
	scanf("%d",&N);
	for(i=1;i<=N;i++) { 
		printf("Phan tu thu %d: ",i);
		scanf("%d",&X);
		EnQueue(X, Q);
	}
}


void PrintQueue(Queue Q) {
	while (!EmptyQueue(Q)) {
		printf("%d ",RetrieveFirst(Q));
		DeQueue(&Q);
	}
	printf("\n");
}


main() {
	Queue Q;
	ReadQueue(&Q);
	printf("Danh sach vua nhap: ");
	PrintQueue(Q); 
	return 0;
} 

 

  
