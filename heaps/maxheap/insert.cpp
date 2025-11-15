#include <iostream>
using namespace std;

void Insert(int A[], int n)
{
    int i = n, temp;
    temp = A[i];  
    // temp stores the newly inserted element
    // i starts at the index of the newly inserted element (n)

    while(i > 1 && temp > A[i/2])
    {
        // While temp is greater than its parent, shift parent down
        A[i] = A[i/2];
        i = i/2;  
        // Move index to parent's position
    }

    A[i] = temp;  
    // Place temp in its correct position (heap property restored)
}

int Delete(int A[], int n)
{
    int i, j, x, temp, val;

    val = A[1];  
    // val = element to delete (root of max-heap)

    x = A[n];    
    // x = last element (to move to root)

    A[1] = A[n]; 
    // Move last element to root to fill the hole

    i = 1;
    j = i * 2;   
    // j = left child of i

    while(j < n - 1)  
    {
        // Loop runs while child index is within range
        // j < n-1 ensures j+1 is also valid (right child)

        if(A[j+1] > A[j])
            j = j + 1;  
        // j = index of the larger child

        if(A[i] < A[j])
        {
            // If parent is smaller than larger child → swap
            swap(A[i], A[j]);
            i = j;        
            j = i * 2;    
            // Move down the tree and continue heapifying
        }
        else 
            break;  
            // Heap property restored
    }

    return val;  
    // return deleted element
}

int main()
{
    int H[] = {0,2,5,8,9,10,7};
    // 1-based indexing (dummy 0 at index 0)

    for (int i = 2; i <= 6; i++)
    {
        // Build heap using Insert
        Insert(H, i);
    }

    for (int i = 1; i <= 6; i++)
    {
        // Print heap after insertion
        cout << H[i] << " ";
    }
    cout << endl;

    Delete(H, 6);
    // Delete max (root)

    for (int i = 1; i <= 5; i++)
    {
        // Print heap after deletion
        cout << H[i] << " ";
    }

    return 0;
}
