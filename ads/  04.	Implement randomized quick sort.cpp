#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int Partition(int a[], int low, int high)
{
        int pivot, index, i;
        index = low;
        pivot = high;
        for (i = low; i < high; i++)
        {
                if (a[i] < a[pivot])
                {
                        swap(a[i], a[index]);
                        index++;
                }
        }
        swap(a[pivot], a[index]);
        return index;
}
void random_shuffle(int arr[], int n)
{
        srand(time(NULL));
        for (int i = n - 1; i > 0; i--)
        {
                int j = rand() % (i + 1);
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
        }
}
int RandomPivotPartition(int a[], int low, int high)
{
        int pvt, n, temp;
        n = rand();
        pvt = low + n % (high - low + 1);
        swap(a[high], a[pvt]);
        return Partition(a, low, high);
}
void quick_sort(int arr[], int p, int q)
{
        int pindex;
        if (p < q)
        {
                pindex = RandomPivotPartition(arr, p, q);
                quick_sort(arr, p, pindex - 1);
                quick_sort(arr, pindex + 1, q);
        }
}
int main()
{
        int n = 5;
        int arr[n];
        for (int i = 0; i < n; i++)
                arr[i] = i + 1;
        random_shuffle(arr, n);
        quick_sort(arr, 0, n - 1);
        for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
        cout << endl;
}
