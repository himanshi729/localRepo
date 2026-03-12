#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int l, int r) {
    int pivot = A[r];
    int i = l;

    for(int j = l; j < r; j++) {
        if(A[j] <= pivot) {
            swap(&A[i], &A[j]);
            i++;
        }
    }

    swap(&A[i], &A[r]);
    return i;
}
int smallest(int A[], int l, int r, int i) {
    if(l <= r) {
        int p = partition(A, l, r);
        int k = p - l + 1;
        if(k == i)
            return A[p];
        else if(i < k)
            return smallest(A, l, p - 1, i);
        else
            return smallest(A, p + 1, r, i - k);
    }
    return -1;
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter the elements:\n");
    for(int j = 0; j < n; j++) {
        scanf("%d", &A[j]);
    }

    printf("Enter i : ");
    scanf("%d", &i);

    if(i > 0 && i <= n)
        printf("%d-th smallest element = %d\n", i, smallest(A, 0, n-1, i));
    else
        printf("Invalid value of i\n");

    return 0;
}