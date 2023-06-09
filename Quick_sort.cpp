#include <iostream>
using namespace std;

void Quick_sort(int a[], int left, int right)
{
    int i = left, j = right;
    int mid = a[left + (right - left) / 2]; 
    do
    {
        while (a[i] < mid)
            i++;
        while (a[j] > mid)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j)
        Quick_sort(a, left, j);
    if (i < right)
        Quick_sort(a, i, right);
}

int main()
{
    int a[] = {9, 2, 5, 7, 0, 1};
    int n = sizeof(a) / sizeof(a[0]);
    Quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
