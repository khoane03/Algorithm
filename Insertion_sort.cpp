#include <iostream>
using namespace std;
void sort(int arr[], int n)
{
    int pos, i, x;
    for (i = 1; i < 7; i++)
    {
        x = arr[i];
        pos = i - 1;
        while ((pos >= 0) && (arr[pos] > x))
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = x;
    }
}

int main()
{
    int arr[6] = {9, 2, 5, 7, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, n);
    cout<<"mang da sap xep : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

}