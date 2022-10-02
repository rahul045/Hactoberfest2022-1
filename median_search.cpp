#include <iostream>
#include <climits>
using namespace std;
int partition_it(int a[], int st, int ed)
{
    int k = st - 1;
    int pvt = a[ed];
    for (int i = st; i < ed; i++)
    {
        if (a[i] < pvt)
        {
            k++;
            int temp = a[i];
            a[i] = a[k];
            a[k] = temp;
        }
    }
    k++;
    int temp = a[ed];
    a[ed] = a[k];
    a[k] = pvt;
    return k;
}
int median_search(int arr[], int l, int h, int k)
{
    if (l <= h)
    {
        int index = partition_it(arr, l, h);

        if (index == k)
            return arr[index];

        else if (index > k)
            return median_search(arr, l, index - 1, k);
        else
            return median_search(arr, index + 1, h, k);
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 10;
    cout << "K-th smallest element is "
         << median_search(arr, 0, n - 1, k - 1);
    return 0;
}
