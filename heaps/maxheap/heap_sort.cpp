#include <iostream>
#include <vector>
using namespace std;

/*  INSERT INTO MAX-HEAP
    ---------------------
    • Insert element at index n.
    • Bubble it up until heap property holds.
    • Works because parent index = i/2.
*/
void insert(vector<int> &A, int n)
{
    int temp = A[n];     // element to place correctly
    int i = n;

    // bubble up while parent exists and is smaller
    while (i > 1 && temp > A[i/2])
    {
        A[i] = A[i/2];   // move parent down
        i = i / 2;       // go to parent index
    }

    A[i] = temp;         // place the element
}

/*  DELETE ROOT (HEAPSORT STEP)
    ----------------------------
    • A[1] is root (max element).
    • Move last element to root.
    • Bubble it down (heapify).
    • At each step choose the larger child.
    • Final sorted element placed at A[n].
*/
int delete_root(vector<int> &A, int n)
{
    int x = A[1];        // extract max
    A[1] = A[n];         // move last to root

    int i = 1;
    int j = 2 * i;       // left child

    // bubble down while child exists
    while (j <= n - 1)
    {
        // pick the larger child
        if (j + 1 <= n - 1 && A[j + 1] > A[j])
            j++;

        // if child is bigger, swap
        if (A[i] < A[j])
        {
            swap(A[i], A[j]);
            i = j;          // move to child
            j = 2 * i;      // update child index
        }
        else
            break;          // heap order satisfied
    }

    A[n] = x;               // place max at end (heapsort)
    return x;
}

int main()
{
    vector<int> v;

    /* DUMMY AT INDEX 0
       ----------------
       • Makes heap 1-indexed.
       • Parent/child formulas become simple.
    */
    v.push_back(0);

    cout << "enter the no of element to insert: ";
    int n;
    cin >> n;

    // read input normally (placed from index 1)
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    /* BUILD MAX-HEAP BY INSERTION
       ----------------------------
       • Insert elements one by one.
       • Complexity: O(n log n).
    */
    for (int i = 1; i <= n; i++)
        insert(v, i);

    /* PRINT MAX-HEAP */
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << endl;

    /* HEAPSORT PROCESS
       -----------------
       • Repeatedly delete root.
       • Max elements get placed at A[n], A[n-1], …
    */
    for (int i = n; i > 1; i--)
        delete_root(v, i);

    /* FINAL SORTED ARRAY */
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";

    return 0;
}
