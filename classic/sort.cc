#include <iostream>
#include <stdlib.h>
using namespace std;

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        bool exchange = false;
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                exchange = true;
                swap(arr[j], arr[j+1]);
            }
        }
        if (!exchange) {
            cout << i << endl;
            return;
        }
    }
}

void insertSort(int *arr, int n) {
    int current, preindex;
    for (int i = 1; i < n; ++i) {
        current = arr[i];
        preindex = i-1;
        while (preindex >= 0 && arr[preindex] > current) {
            arr[preindex+1] = arr[preindex];
            preindex--;
        }
        arr[preindex+1] = current;
    }
}

void selectSort(int *arr, int n) {
    for (int i = 0; i < n-1; ++i) {
        int index = i;
        for (int j = i+1; j < n; ++j) {
            if (arr[j] < arr[index]) {
                index = j;
            }
        }

        swap(arr[index], arr[i]);
    }
}

void merge(int *a, int alen, int *b, int blen, int tmp[]) {
    int len = 0;
    int i = 0, j = 0;
    while (i < alen && j < blen) {
        if (a[i] < b[j]) {
            tmp[len++] = a[i++];
        } else {
            tmp[len++] = b[j++];
        }
    }
    while (i < alen) {
        tmp[len++] = a[i++];
    }
    while (j < blen) {
        tmp[len++] = b[j++];
    }

    for (int i = 0; i < len; ++i) {
        a[i] = tmp[i];
    }
}

void mergesort(int *arr, int n, int tmp[]) {
    if (n < 2) return;
    
    int mid = n/2;

    mergesort(arr, mid, tmp);
    mergesort(arr+mid, n-mid, tmp);
    merge(arr, mid, arr+mid, n-mid, tmp);
}

void mergeSort(int *arr, int n) {
    int *tmp = (int*)malloc(sizeof(int)*n);
    mergesort(arr, n, tmp);
    free(tmp);
}

int partition(int *arr, int left, int right) {
    int pivot = left;
    int index = left+1;
    for (int i = index; i <= right; ++i) {
        if (arr[i] < arr[pivot]) {
            swap(arr[i], arr[index]);
            index++;
        }
    }
    swap(arr[pivot], arr[index-1]);
    return index-1;
}

void quickSort(int *arr, int left, int right) {
    if (left < right) {
        int index = partition(arr, left, right);
        quickSort(arr, left, index-1);
        quickSort(arr, index+1, right);
    }
}

void headpify(int *arr, int size, int i) {
    int curr = arr[i], child;
    for (child=i*2+1; child<size; child=child*2+1) {
        if (child+1 < size && arr[child] < arr[child+1]) {
            child++;
        }

        if (arr[child] > curr) {
            arr[i] = arr[child];
            i = child;
        } else {
            break;
        }
    }
    arr[i] = curr;
}

void buildMaxHeap(int *arr, int n) {
    for (int i = n/2; i >= 0; --i) {
        headpify(arr, n, i);
    }
}

void heapSort(int *arr, int n) {
    buildMaxHeap(arr, n);

    for (int i = n-1;i > 0; --i) {
        swap(arr[0], arr[i]);
        headpify(arr, i, 0);
    }
}

void print(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {3,2,4,1,5};
    //int a[] = {1,2,3,4,5};
    int len = 5;
    print(a, len);
    //bubbleSort(a, len);
    //selectSort(a, len);
    //insertSort(a, len);
    //mergeSort(a, len);
    //quickSort(a, 0, len-1);
    heapSort(a, len);

    print(a, len);
}
