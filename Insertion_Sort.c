#include <stdio.h>
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

void Selection_sort(int a[], int n)
{
	int i,j,num;
	for(i=1;i<n;i++)
	{
		num=a[i];
		j=i-1;
		while(j>=0 && num<a[j])
		{
		 a[j+1]=a[j];
		 j--;
		}
		a[j+1]=num;
		
	}
}


void Bubble_sort(int a[], int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)// no of pass
	{
		for(j=0;j<n-1-i;j++)//no of compare
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}

int main() {
  int data[] = {9, 5, 1, 4, 3};
  int size = sizeof(data) / sizeof(data[0]);
  Bubble_sort(data, size);
  printf("Sorted array in ascending order by Bubble Sort:\n");
  printArray(data, size);
  
  int data2[] = {8, 15, 2, 32, 73};
  int size2 = sizeof(data2) / sizeof(data2[0]);
  Selection_sort(data2, size2);
  printf("Sorted array in ascending order by Selection Sort:\n");
  printArray(data2, size2);
  
  int data3[] = {1, 23, 5, 0, 2};
  int size3 = sizeof(data3) / sizeof(data3[0]);
  insertionSort(data3, size3);
  printf("Sorted array in ascending order by Insertion Sort:\n");
  printArray(data3, size3);
}
