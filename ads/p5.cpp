
#include <iostream>
using namespace std;
void countsort(int arr[], int n)
{
        int max1 = arr[0];
        for (int i = 0; i < n; i++)
        {
                max1 = max(max1, arr[i]);
        }
        int countarray[10] = {0};
        for (int i = 0; i < n; i++)
        {
                countarray[arr[i]]++;
        }
        for (int i = 1; i <= max1; i++)
        {
                countarray[i] = countarray[i - 1] + countarray[i];
        }
        int out[n];
        for (int i = n - 1; i >= 0; i--)
        {
                countarray[arr[i]]--;
                out[countarray[arr[i]]] = arr[i];
        }
        for (int i = 0; i < n; i++)
        {
                arr[i] = out[i];
        }
}
int main()
{
        int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
        int len = sizeof(arr) / sizeof(arr[0]);

        cout << "unsorted array : ";
        for (int i = 0; i <len ; i++)
        {
                cout << arr[i] << " ";
        }
        cout << endl;
        countsort(arr, 9);
        cout << "sorted array : ";
        for (int i = 0; i <len; i++)
        {
                cout << arr[i] << " ";
        }
}
