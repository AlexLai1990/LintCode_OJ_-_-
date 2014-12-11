class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        createMaxHeap(A);
        for (int i = A.size() - 1; i > 0; i--) {
            swap(A[0], A[i]);
            fixDown(A, 0, i);
        }
        return;
    }
    
    void createMaxHeap(vector<int> &A) {
        for (int i = A.size() - 1 ; i >= 0; i--) {
            fixDown(A, i, A.size());
        }    
        return;
    }
    
    void fixDown(vector<int> &A, int curr_index, int size) { 
		while (left_child(curr_index) < size) {
			int max_child_index = left_child(curr_index);
			if (right_child(curr_index) < size) {
				if (A[max_child_index] < A[right_child(curr_index)])
					max_child_index = right_child(curr_index);
			}
			if (A[curr_index] < A[max_child_index]) {
				swap(A[curr_index], A[max_child_index]);
			}
			curr_index = max_child_index;
		}
		return;
	}
    
    int get_parent(int index) {
        return ((index + 1) / 2) - 1;
    }
    
    int left_child(int index) {
        return index * 2 + 1;
    }
    
    int right_child(int index) {
        return index * 2 + 2;
    }
};
 
