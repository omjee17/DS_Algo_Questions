bool findPair(int arr[], int size, int n) {

    map<int, int>m;
    for (int i = 0; i < size; i++)
    {
        m[arr[i]]++;
    }

    for (int i = 0; i < size; i++)
    {
        if (m[abs(n - arr[i])] >= 1)
        {
            return true;
        }
    }
    return false;


}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cinn >> arr[i];
    }
    int value;
    cin >> value;
    cout << findPair(arr, n, value) << endl;

    delete[] arr;
}