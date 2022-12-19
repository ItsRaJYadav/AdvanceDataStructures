#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int s, int e)
{
        //     divide the array
        int mid = s + (e - s) / 2;
        int len1 = mid - s + 1;
        int len2 = e - mid;
        int *first = new int[len1];
        int *second = new int[len2];
        int mainArrIndex = s;
        for (int i = 0; i < len1; i++)
        {
                first[i] = arr[mainArrIndex++];
        }
        mainArrIndex = mid + 1;
        for (int i = 0; i < len2; i++)
        {
                second[i] = arr[mainArrIndex++];
        }
        //     merge the array
        int index1 = 0;
        int index2 = 0;
        mainArrIndex = s;
        while (index1 < len1 && index2 < len2)
        {
                if (first[index1] < second[index2])
                {
                        arr[mainArrIndex++] = first[index1++];
                }
                else
                {
                        arr[mainArrIndex++] = second[index2++];
                }
        }
        while (index1 < len1)
        {
                arr[mainArrIndex++] = first[index1++];
        }
        while (index2 < len2)
        {
                arr[mainArrIndex++] = second[index2++];
        }
        delete[] first;
        delete[] second;
}
void solve(vector<int> &arr, int s, int e)
{
        if (s >= e)
        {
                return;
        }
        int mid = s + (e - s) / 2;
        //     sort left side
        solve(arr, s, mid);
        //     sort right side
        solve(arr, mid + 1, e);
        merge(arr, s, e);
}

void mergeSort(vector<int> &arr, int n)
{
        int s = 0;
        int e = n - 1;
        solve(arr, s, e);
}

int main()
{
        vector<int> arr = {1, 2, 3, 6, 5, 736, 88, 99};
        cout<<"unsorted array : ";
        for (int i = 0; i < arr.size(); i++)
        {
                cout << arr[i]<<" ";
        }
        cout<<endl;
        mergeSort(arr, 8);
        cout << "sorted array : ";

        for (int i = 0; i < arr.size(); i++)
        {
                cout << arr[i]<<" ";
        }
}
