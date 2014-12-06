vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) { 
    // write your code here
    vector<int> m_ret;
    m_ret.reserve(A.size() + B.size());
    if (A.size() < 1 && B.size() < 1)
        return m_ret;
    else if (A.size() < 1)
        return B;
    else if (B.size() < 1)
        return A;
        
    int index_a = 0, index_b = 0;
    while (index_a < A.size() && index_b < B.size()) {
        if (A[index_a] <  B[index_b]) {
            m_ret.push_back(A[index_a]);
            index_a++;
        }
        else {
            m_ret.push_back(B[index_b]);
            index_b++;
        }
    }
    if (index_a == A.size())
        while (index_b < B.size()) 
            m_ret.push_back(B[index_b++]);
    if (index_b == B.size())
        while (index_a < A.size())
            m_ret.push_back(A[index_a++]);
    
    return m_ret;
}