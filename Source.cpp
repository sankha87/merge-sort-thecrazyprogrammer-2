#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void mergesort(int *array, int i, int j);
void merge(int *array, int i1, int j1, int i2, int j2);

int main()
{
	int *arr, n, i;
	printf("Enter no of elements: ");
	scanf("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	printf("enter elements : \n");
	for (int i = 0; i<n; i++)
		scanf("%d", arr + i);

	mergesort(arr, 0, n - 1);

	printf("\nSorted array is : ");
	for (int i = 0; i<n; i++)
		printf(" %d ", *(arr + i));

	_getch();
}

void mergesort(int *arr, int low, int high)
{
	int mid;

	if (low<high)
	{
		mid = (low + high) / 2;
		mergesort(arr, low, mid);				//left recursion
		mergesort(arr, mid + 1, high);		//right recursion
		merge(arr, low, mid, mid + 1, high);	//merging of two sorted sub-arrays
	}
}

void merge(int *arr, int low, int mid, int midPlus, int high)
{
	int *temp;	// array used for merging
	int arrSize = high - low + 1;
	temp = (int*)malloc(arrSize * sizeof(int));

	int i, j, k;
	i = low;		//beginning of the first list
	j = midPlus;	//beginning of the second list
	k = 0;

	while (i <= mid && j <= high)	//while elements in both lists
	{
		if ( *(arr+i) < *(arr+j) )
		{
			*(temp+k) = *(arr+i);
			k++;
			i++;
		}
		else
		{
			*(temp+k) = *(arr+j);
			k++;
			j++;
		}
	}

	while (i <= mid)	//copy remaining elements of the first list
	{
		*(temp+k) = *(arr+i);
		k++;
		i++;
	}

	while (j <= high)	//copy remaining elements of the second list
	{
		*(temp+k) = *(arr+j);
		k++;
		j++;
	}

	//Transfer elements from temp[] back to arr[]
	for (i = low, j = 0; i <= high; i++, j++)
		*(arr+i) = *(temp+j);
}