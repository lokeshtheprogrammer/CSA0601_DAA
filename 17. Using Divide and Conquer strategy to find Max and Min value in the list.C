#include <stdio.h>

void find_max_min(int arr[], int low, int high, int *max, int *min) {
    if (low == high) {
        *max = arr[low];
        *min = arr[low];
    } else if (low + 1 == high) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
    } else {
        int mid = (low + high) / 2;
        int max1, min1, max2, min2;
        find_max_min(arr, low, mid, &max1, &min1);
        find_max_min(arr, mid + 1, high, &max2, &min2);
        *max = (max1 > max2) ? max1 : max2;
        *min = (min1 < min2) ? min1 : min2;
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max, min;
    find_max_min(arr, 0, n - 1, &max, &min);
    printf("Max value: %d\n", max);
    printf("Min value: %d\n", min);
    return 0;
}
