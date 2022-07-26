#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define	N	100000

typedef  int keytype;
typedef  float othertype;
typedef  struct {
	keytype key;
	othertype others;
} recordtype;
	  

/* generate n random number */
void gen(recordtype  a[], int n) {
	int i;

	srand(time(0));
	for(i=0; i<n; i++)
		a[i].key = rand();
}


/* swap(x,y) */
void swap(recordtype *x, recordtype *y) {
      recordtype temp;
      temp = *x;
      *x = *y;
      *y = temp;
}


/* print array */
void print(recordtype  a[], int n) {
	int i;
	for(i=0; i<n; i++)
		printf("%d ", a[i].key);
	printf("\n");	
}


/* insertion sort */
void insertion_sort(recordtype  a[], int n) {
	int i,j;
	for (i = 1; i<= n-1; i++) {
		j = i;
		while ((j>0) && (a[j].key < a[j-1].key)) {
			swap(&a[j], &a[j-1]);
			j= j-1;
	    }
	}
}


/* main function */
main() {
	recordtype  a[N];
	gen(a, N);
	printf("init a\n");
	print(a, N);
	

	insertion_sort(a, N);

	
	printf("sorted a\n");
	print(a, N);	
}
