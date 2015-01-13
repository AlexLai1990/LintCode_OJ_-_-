#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxKSubArrays(vector<int> nums, int k) {
        int n = nums.size();
    	if (n <= 1 || k > nums.size())
    		return 0;
    	// m_dp[i][j] means the largest number when using nums[0..j] with i subarrays
    	vector<vector<int> > m_dp(k + 1, vector<int>(n + 1, INT_MIN));
    	fill(m_dp[0].begin(), m_dp[0].end(), 0); 
    	vector<int> pre_sum(n + 1, 0);
		// pre-store a pre-sum array for get sum from nums[i] to num[j] later.
    	for (int i = 1; i <= n; i++) {
    		pre_sum[i] += pre_sum[i - 1] + nums[i - 1];
		}
    	for (int i = 1; i <= k; i++) { 
    		for (int j = i; j <= n; j++) {
    			if (i == j) {
    				m_dp[i][j] = pre_sum[i];
    				continue;
    			}
				// get fake largest, define current largest is using num[j] as the last number in the ith subarray
    			// try to find a cut from i to j
    			for (int k = i; k <= j ; k++) {
    				m_dp[i][j] = max(m_dp[i][j], m_dp[i - 1][k - 1] + pre_sum[j] - pre_sum[k - 1]);
    			}
    		}
    		// update the real largest number in current row
    		for (int j = i + 1; j <= n; j++) {
    			m_dp[i][j] = max(m_dp[i][j], m_dp[i][j - 1]);
			}
    	}
    	return m_dp[k][n];
    }
};

