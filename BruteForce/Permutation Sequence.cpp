class Solution {
public:
    string getPermutation(int n, int k) {
        string m_res = ""; 
        for (int i = 0; i < 10; i++) {
            m_factorials.push_back(Factorial(i));
        }
        if (k > m_factorials[n])
            return m_res;
        for (int i = 1; i <= n; i++) {
            m_res += (char)(i + '0');
        }
        getPermutationHelper(m_res, 0, --k, n);
        return m_res;
    } 
    
    void getPermutationHelper(string &m_res, int start, int curr_k, int n) {
		if (start > n - 1 || curr_k == 0)
			return;
		int swap_distance = curr_k / m_factorials[n - start - 1];
		int next_k = curr_k % m_factorials[n - start - 1];
		swap(m_res, start, swap_distance);
		getPermutationHelper(m_res, start + 1, next_k, n);
		return;
	}

	void swap(string &m_res,  int start, int dist){
		if (start + dist >= m_res.size())
			return;
		for (int i = start + dist; i>start; --i){
			char tmp = m_res[i];
			m_res[i] = m_res[i - 1];
			m_res[i - 1] = tmp;
		}
	}
	
	int Factorial(int n) {
		int res = 1;
		while (n > 0) {
			res *= n--;
		}
		return res;
	}
    
private:
    vector<int> m_factorials;
};
