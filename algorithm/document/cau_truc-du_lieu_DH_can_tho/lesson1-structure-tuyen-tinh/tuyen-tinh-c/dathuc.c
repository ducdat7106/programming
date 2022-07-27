#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float	coef;
	int		expo;
} ElementType;

typedef struct Node* NodeType;

struct Node {
	ElementType element;
	NodeType	next;
};

typedef NodeType Position;
typedef Position PolyType;

void MakeNull(PolyType *poly) {
	(*poly)=(NodeType)malloc(sizeof(struct Node));
	(*poly)->next= NULL;
}

void AddLast(ElementType x, PolyType *poly) {
	PolyType last, newp;
	int	see;
	
	last = *poly;
	see = 0;
	while ((last->next != NULL) && (see==0)) 
		if (last->next->element.expo == x.expo)
			see = 1;
		else	
			last = last->next;
	if (see == 0) {
		newp=(NodeType)malloc(sizeof(struct Node));
		newp->element = x;
		newp->next = NULL;
		last->next = newp;
	} else
        printf("<!> dung do so mu\n");
}

void Sort(PolyType *poly) {
	Position p, q, smallest;
	p = *poly;
	
	while (p->next != NULL) {
		smallest = p;
		q = p->next;
		while (q->next != NULL) {
			if (q->next->element.expo < smallest->next->element.expo) 
				smallest = q;
			q = q->next;
		}
		ElementType x;
		x = p->next->element;
		p->next->element = smallest->next->element;
		smallest->next->element = x;
		p = p->next;
	}
}

PolyType gradient(PolyType poly) {
	PolyType grad;
	Position p;
	MakeNull(&grad);	
	p = poly;
    while (p->next != NULL) {
		if (p->next->element.expo != 0) {
			ElementType x;
			x.coef = p->next->element.coef*p->next->element.expo;
			x.expo = p->next->element.expo - 1;
			AddLast(x , &grad);
		}
		p = p->next;
	}
	return grad;
}

PolyType Add(PolyType poly1, PolyType poly2) {
	PolyType result;
	Position p1, p2;
	MakeNull(&result);	
	Sort(&poly1);
	Sort(&poly2);
	p1 = poly1;
	p2 = poly2;
	while ((p1->next != NULL) &&  (p2->next != NULL)) {
		if (p1->next->element.expo < p2->next->element.expo) {
			AddLast(p1->next->element, &result);
			p1 = p1->next;
		}	
		else
		if (p1->next->element.expo > p2->next->element.expo) {
			AddLast(p2->next->element, &result);
			p2 = p2->next;
		}	
		else
		{
				ElementType x;
				x.coef = p1->next->element.coef + p2->next->element.coef;
				x.expo = p1->next->element.expo;
				if (x.coef != 0) 
					AddLast(x, &result);
				p1 = p1->next;
				p2 = p2->next;
		}
	}
	
	while(p1->next != NULL) {
		AddLast(p1->next->element, &result);
		p1 = p1->next;
	}

	while(p2->next != NULL) {
		AddLast(p2->next->element, &result);
		p2 = p2->next;
	}
	
	return result;
}

void ReadPoly(PolyType *poly) {
	int i, n;
	ElementType x;
	MakeNull(poly);	
	printf("Hay cho biet so phan tu cua da thuc:"); scanf("%d", &n);
	for(i=0; i<n; i++) {
		printf("nhap vao he so thu %d ", i+1);
		scanf("%f", &x.coef);
		printf("nhap vao so mu thu %d ", i+1);
		scanf("%d", &x.expo);
		AddLast(x, poly);
	}
}

void PrintPoly(PolyType poly) {
	PolyType p;
	p = poly;
	printf("da thuc\n");
    while (p->next != NULL) {
		if (p->next->element.coef > 0)
			printf("+");
		printf("%5.2f X^%d",p->next->element.coef, p->next->element.expo);	
		p = p->next;
	}
}

main() {
	PolyType poly;
	ReadPoly(&poly);
	Sort(&poly);
	PrintPoly(poly);
	printf("\nDao ham bac nhat cua da thuc la:\n");
	PrintPoly(gradient(poly));
	PolyType poly2;
	printf("\n Nhap them da thuc thu 2 \n");
	ReadPoly(&poly2);
	Sort(&poly2);
	PrintPoly(poly2);
	printf("\nDa thuc 1 cong da thuc 2 la:\n");
	PrintPoly(Add(poly, poly2));
	
	return 0;
}

