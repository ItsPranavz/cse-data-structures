// Sorting and searching algorithms

#include <bits/stdc++.h>
using namespace std;

// Linear search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

// Binary search
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

// Bubble sort
void bubbleSort(int arr[], int n) 
{
    for(int j=0;j<n-1;j++){
    for(int i=0; i<n-1-j;i++){
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
    }
 }

// Insertion sort
void insertionSort(int arr[], int n)
{
    for(int i=1;i<n;i++){
        int current=arr[i];
        int j;
        for( j=i-1;j>=0;j--){
            if(current<arr[j]){
                arr[j+1]=arr[j];
            } else {
                break;
            }
        }
            arr[j+1]=current;  
    }
}

//  Merge function
void merge(vector<int> &a,int l,int r){
    int mid = (l+r)/2;
    int *temp = new int[r-l+1];
    int i=l;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            temp[k]=a[i];
            i++;
            k++;
        }
        else{
            temp[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=r){
        temp[k]=a[j];
        j++;
        k++;
    }
    int o=0;
    while(o<k){
        a[l+o]=temp[o];
        o++;
    }
}

// Mergesort function
void mergeSort(vector<int>& arr, int l, int r) {
    if(l>=r) return;
    else{
        int mid= (l+r) /2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1,  r);
        merge(arr,l,r);
    }
}

// Partition function
int partitionArray(int input[], int start, int end) {
	int c=0;
	for(int i=start;i<=end;i++){
		if(input[i]<input[start]) c++;
	}
	int temp= input[start];
	input[start]=input[start+c];
	input[start+c]=temp;
	int pi= start+c;
	int i=start;
	int j=end;
	while(i< pi && j>pi){
		if(input[i]< input[pi]) i++;
		else if(input[j]>= input[pi]) j--;
		else{
			int t=input[i];
			input[i]=input[j];
			input[j]=t;
			i++;
			j--;
		}
	}
	return pi;
}

// Quicksort
void quickSort(int input[], int start, int end) {
	if(start>=end) return;
        else {
                int pi = partitionArray(input, start, end);
                quickSort(input, start, pi);
                quickSort(input, pi + 1, end);
        }
}
 
// Function for Selection sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n - 1; i++) {
 
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}
