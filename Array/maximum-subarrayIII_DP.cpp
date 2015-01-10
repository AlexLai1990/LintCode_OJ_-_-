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
    	// m_dp[i][j] means the largest number from 0 to j in nums having i subarray
    	vector<vector<int> > m_dp(k + 1, vector<int>(n + 1, INT_MIN));
    	fill(m_dp[0].begin(), m_dp[0].end(), 0); 
    	vector<int> pre_sum(n + 1, 0);
    	for (int i = 1; i <= n; i++) {
    		pre_sum[i] += pre_sum[i - 1] + nums[i - 1];
    	}
    	for (int i = 1; i <= k; i++) { 
    		for (int j = i; j <= n; j++) {
    			if (i == j) {
    				m_dp[i][j] = pre_sum[i];
    				continue;
    			}
    			// the nums[j] as the last subarray
    			// m_dp[i][j] = m_dp[i - 1][j - 1] + nums[j - 1];
    			// if cut in the middle
    			for (int k = i; k <= j ; k++) {
    				m_dp[i][j] = max(m_dp[i][j], m_dp[i - 1][k - 1] + pre_sum[j] - pre_sum[k - 1]);
    			}
    		}
    		// update for this row
    		for (int j = i + 1; j <= n; j++)
    			m_dp[i][j] = max(m_dp[i][j], m_dp[i][j - 1]);
    	}
    	return m_dp[k][n];
    }
};

