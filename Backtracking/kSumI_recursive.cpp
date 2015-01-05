class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */ 
    
    int kSum(vector<int> num, int k, int target) {
        // wirte your code here
        vector<vector<int> > m_res = KSum(num, k, target, 0);
        return m_res.size();
    }
            
    vector<vector<int> > KSum(vector<int> &num, int K, int target, int start) { 
        vector< vector<int> > vecResults; 
        if (K == 2) { // base case 
            vector<int> tuple(2, 0);
            int i = start, j = num.size() - 1;
            while (i < j) {
                if (i > start && num[i] == num[i - 1]) {
                    ++i;
                    continue;
                } 
                int sum = num[i] + num[j];
                if (sum == target) {
                    tuple[0] = num[i++];
                    tuple[1] = num[j--];
                    vecResults.push_back(tuple);
                }
                else if (sum > target) {
                    --j;
                }
                else {
                    ++i;
                }
            }
            return vecResults;
        }
        
        // K > 2
        for (int i = start; i < num.size(); ++i) {
            if (i > start && num[i] == num[i - 1]) 
                continue; 
            vector< vector<int> > K1Sum = KSum(num, K - 1, target - num[i], i + 1); 
            for (auto it = K1Sum.begin(); it != K1Sum.end(); ++it) { 
                vector<int> tuple; 
                tuple.push_back(num[i]); 
                tuple.insert(tuple.end(), it->begin(), it->end()); 
                vecResults.push_back(tuple); 
            } 
        } 
        return vecResults; 
    }
};
