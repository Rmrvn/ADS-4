// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int m = 0;
for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
        if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
            m++;
        }
    }
}
return m;
}
int countPairs2(int *arr, int len, int value) {
  int r = len - 1;
while (arr[r] > value) {
    r--;
}
int m = 0;
for (int i = 0; i < r; i++) {
    for (int j = r; j > i; j--) {
        if ((arr[i] + arr[j] == value) && (arr[i] >= 0 && arr[j] >= 0)) {
            m++;
        }
        else if (arr[i] + arr[j] < value) {
            break;
        }
    }
}
return m;
}
int countPairs3(int *arr, int len, int value) {
  int m = 0;
int rgh, mid, sredn, lft;
for (int i = 0; i < len; ++i) {
    rgh = len - 1;
    lft = i + 1;
    sredn = value - arr[i];
    while (lft <= rgh) {
        mid = (lft + rgh) / 2;
        if (arr[mid] == sredn) {
            m++;
            int p = mid - 1;
            while ((p > i) && (arr[p] == arr[mid])) {
                m++;
                p--;
            }
            int p2 = mid + 1;
            while ((i < p2) && (arr[p2] == arr[mid])) {
                m++;
                p2++;
            }
            break;
        }
        else if (arr[mid] > sredn) {
            rgh = mid - 1;
        }
        else {
            lft = mid + 1;
        }
    }
}
return m;
}
