//
// Created by Ignorant on 2025/1/11.
//

#include <iostream>
using namespace std;

void quick_sort(int *arr, int n) {
    if (n <= 1) {
        return;
    }
    int pivot = arr[0];
    int left = 0;
    int right = n - 1;
    while (left < right) {
        while (left < right && arr[right] >= pivot) {
            right--;
        }
        if (left < right) {
            arr[left] = arr[right];
            left++;
        }
        while (left < right && arr[left] < pivot) {
            left++;
        }
        if (left < right) {
            arr[right] = arr[left];
            right--;
        }
    }
    arr[left] = pivot;
    quick_sort(arr, left);
    quick_sort(arr + left + 1, n - left - 1);
}

void merge(int *arr1, const int *arr2, int m, int n) {
    int left1 = 0;
    int left2 = 0;
    auto *temp = new int[m + n];
    int length = 0;
    while (left1 < m && left2 < n) {
        while (left1 < m && left2 < n && arr1[left1] <= arr2[left2]) {
            temp[length++] = arr1[left1++];
        }
        while (left1 < m && left2 < n && arr2[left2] < arr1[left1]) {
            temp[length++] = arr2[left2++];
        }
    }
    while (left1 < m) {
        temp[length++] = arr1[left1++];
    }
    while (left2 < n) {
        temp[length++] = arr2[left2++];
    }
    for (int i = 0; i < length; i++) {
        arr1[i] = temp[i];
    }
    delete[] temp;
}

void merge_sort(int *arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr + left, arr + mid + 1, mid - left + 1, right - mid);
}

int main() {
    int n = 0;
    cin >> n;
    auto *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // 直接插入排序
//    for (int i = 1; i < n; i++) {
//        int temp = arr[i];
//        int j = i - 1;
//        for (; j >= 0 && arr[j] > temp; j--) {
//            arr[j + 1] = arr[j];
//        }
//        arr[j + 1] = temp;
//    }
    // 二分插入排序
//    for (int i = 1; i < n; i++) {
//        int left = 0;
//        int right = i;
//        int temp = arr[i];
//        while (left < right) {
//            int mid = (left + right) / 2;
//            if (arr[mid] > temp) {
//                right = mid - 1;
//            } else {
//                left = mid + 1;
//            }
//        }
//        for (int j = i; j > left; j--) {
//            arr[j] = arr[j - 1];
//        }
//        arr[left] = temp;
//    }
    // shell 排序
//    int gap = n;
//    while (gap > 1) {
//        gap /= 2;
//        for (int i = gap; i < n; i += gap) {
//            int temp = arr[i];
//            int j = i - gap;
//            for (; j >= 0 && arr[j] > temp; j -= gap) {
//                arr[j + gap] = arr[j];
//            }
//            arr[j + gap] = temp;
//        }
//    }
    // 冒泡排序
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            if (arr[j + 1] < arr[j]) {
//                int temp = arr[j + 1];
//                arr[j + 1] = arr[j];
//                arr[j] = temp;
//            }
//        }
//    }
    // 快速排序
//    quick_sort(arr, n);
    // 选择排序
//    for (int i = 0; i < n; i++) {
//        int pivot = arr[i];
//        int min_pos = i;
//        for (int j = i; j < n; j++) {
//            if (arr[j] < pivot) {
//                pivot = arr[j];
//                min_pos = j;
//            }
//        }
//        arr[min_pos] = arr[i];
//        arr[i] = pivot;
//    }
    // 归并排序
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}
