/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define parent(idx) ((idx - 1) >> 1)
#define leftChild(idx) ((idx << 1) + 1)
#define rightChild(idx) ((idx << 1) + 2)

// Binary Heap implementation

// Max Heap
template<typename t> 
class MaxHeap {
public:
    int sz;
    vector<t> heap;

    MaxHeap() { sz = 0; } // Constructor. Assign size of heap 0

    void upHeapify(int idx) { // Balances leaf element in heap
        if(idx and heap[parent(idx)] < heap[idx]) { // Compare value with it's parent
            swap(heap[parent(idx)], heap[idx]); // Swap if parent is greater than value
            upHeapify(parent(idx)); // Recursive Heapify call for parent
        }
    }

    void downHeapify(int idx) { // Balances root in heap
        int mx = idx;

        // Find maximum index out of root and it's two children
        if (leftChild(idx) < sz and heap[leftChild(idx)] > heap[idx]) mx = leftChild(idx);
        if (rightChild(idx) < sz and heap[rightChild(idx)] > heap[mx]) mx = rightChild(idx);

        swap(heap[idx], heap[mx]);

        // Recursively call for swapped child if root is changed, else recursion ends
        if(mx != idx) downHeapify(mx); // Recursive Heapify call
    }

    void insert(t value) { // Insert function for heap
        heap.push_back(value); // Insert element in heap
        upHeapify(sz); // Balance heap
        sz++; // Increment size
    }

    void remove() { // Delete root from heap
        if (!sz) { // If heap is empty
            cout << "Empty.\n";
            return;
        }

        heap[0] = heap[sz - 1]; // Make root equal to last element in heap array
        heap.pop_back(); // Pop last element
        sz--; // Decrease size
        downHeapify(0); // Rebalance heap to update root
    }

    void remove(int idx) { // Delete element from given idx
        if (!sz) { // If heap is empty
            cout << "Empty.\n";
            return;
        } 
        else if(idx > sz) { // If index is out of bound
            cout << "Index doesn't exist in heap.\n";
            return;
        }

        heap[idx] = INF(t); // Change value of index to maximum value
        upHeapify(idx); // Balance the tree
        remove(); // Now as the root is maximum, balance the tree
    }

    void display() { // Print heap, level order traversal
        for(auto &i : heap) 
            cout << i << " ";
        cout << "\n";
    }

};

void solve() { // Driver Function
    MaxHeap<int> tr;
    int q; // No. of queries
    cin >> q;
    for (int i = 0; i < q; i++) {
        string t; // Type of query
        cin >> t;
        if (t == "Insert") {
            int val;
            cin >> val;
            tr.insert(val);
        }
        else if (t == "Delete") {
            int idx; // Index in heap to be deleted
            cin >> idx;
            tr.remove(idx);
        }
        else {
            tr.display();
        }
    }
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
