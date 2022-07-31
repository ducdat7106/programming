#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define	N	10000

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


/* find pivot */
int find_pivot(recordtype  a[], int i, int j) {  
	keytype  firstkey;
	int k ;
	k = i+1;
	firstkey = a[i].key;
	while ((k <= j) && (a[k].key == firstkey)) 
		k++;
	if (k > j) 
		return -1;
	else
		if (a[k].key>firstkey) 
			return k; 
		else 
			return i;
}


/* partition */
int partition(recordtype  a[], int i, int j, keytype pivot) {            
	int L,R;
	L = i;
	R = j;
	while (L <= R) {
		while (a[L].key < pivot)  L++;
		while (a[R].key >= pivot) R--;
		if (L<R) 
			swap(&a[L],&a[R]);
	}
	return L;  
}


/* quick sort */
void quick_sort(recordtype  a[], int i, int j) { 
	keytype pivot;
	int pivotindex, k;
	pivotindex = find_pivot(a, i, j);
	if (pivotindex != -1) {
		pivot = a[pivotindex].key;
		k = partition(a, i, j, pivot);
		quick_sort(a, i, k-1);
		quick_sort(a, k, j);
	}
}


/* main function */
main() {
	recordtype  a[N];
	gen(a, N);
	printf("init a\n");
	print(a, N);
	
	quick_sort(a, 0, N-1);
	
	printf("sorted a\n");
	print(a, N);	
}
