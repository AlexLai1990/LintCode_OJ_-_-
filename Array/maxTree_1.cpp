TreeNode* maxTree(vector<int> A) {
    // write your code here
    if (A.size() < 1)
        return NULL;
    return maxTreeHelper(A, 0, A.size() - 1);
}

TreeNode *maxTreeHelper(vector<int> &A, int left, int right) {
    if (left < 0 || right >= A.size() || left > right)
        return NULL;
    if (left == right) {
        TreeNode * m_new_node = new TreeNode(A[left]);
        return m_new_node;
    }
    int cur_max_pos = findMaxPos(A, left, right);
    TreeNode *m_root = new TreeNode(A[cur_max_pos]);
    m_root->left = maxTreeHelper(A, left, cur_max_pos - 1);
    m_root->right = maxTreeHelper(A, cur_max_pos + 1, right);
    return m_root;
}

// find the max value's position in current range
int findMaxPos(vector<int> &A, int left, int right) {
    int m_ret_pos = left;
    int cur_max = A[left];
    while (left <= right) {
        if (A[left] > cur_max) {
            m_ret_pos = left;
            cur_max = A[left];
        }
        left++;
    }
    return m_ret_pos;
}