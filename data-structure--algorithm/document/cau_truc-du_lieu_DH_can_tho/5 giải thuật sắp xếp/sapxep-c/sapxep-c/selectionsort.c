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


/* selection sort */
void selection_sort(recordtype  a[], int n){           
	int i,j,lowindex;
    keytype lowkey;
	for (i=0; i<(n-1); i++) {
	    lowindex = i;
	    lowkey = a[i].key;
	    for (j = i+1; j <n; j++)
			if (a[j].key < lowkey) {
				lowkey = a[j].key;
				lowindex = j; 
			}
	    swap(&a[i],&a[lowindex]);
	}
}


/* main function */
main() {
	recordtype  a[N];
	gen(a, N);
	printf("init a\n");
	print(a, N);
	
	selection_sort(a, N);
	
	printf("sorted a\n");
	print(a, N);	
}
