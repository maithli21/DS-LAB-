void improvedselectionsort (int arr [] , int n) {
    for (int i = 0; i < n / 2; i++) {
    int minidx = i;
    int maxidx = i;
    for (int j = i; j < n - i; j++) {
       if (arr[j] < arr[minidx])
                minidx = j;
        if (arr[j] > arr[maxidx])
                maxidx = j;
        }
        std::swap(arr[i], arr[minidx]);
        if (maxidx == i)
            maxidx = minidx;
        std::swap(arr[n - i - 1], arr[maxidx]);
    }
}
