/*
	We need to dispacther the assignments in sequence.
	dp[i][j] means mininum time finishing i assignments with j people
	dp[i][j] = min{max(dp[k][j - 1], sum(k, i), j <= k < i} the new worker need get some work at least, 
	because they doing work at the same time, get the max time each round

	Need a pre_process sum[][] to get the sum(k, i);
*/
int getMinTimeInWorkers(vector<int> assignments, int num_people) {
	int n = assignments.size();
	vector<vector<int> > dp(n + 1, vector<int>(num_people + 1, INT_MAX));
	vector<vector<int> > sum(n, vector<int>(n, 0));
	// initialize sum array
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			for (int k = i; k <= j; ++k){
				sum[i][j] += assignments[k];
			}
		}
	}

	// initilize time by one worker
	for (int i = 1; i < n; i++) {
		dp[i][1] = sum[0][i - 1];
	}

	// assign works, because it depends on diffrent number of workers 
	// set the j = number of workers, the outer loop
	for (int j = 2; j <= num_people; j++) {
		for (int i = j; i <= n; i++) { 
			// assign the work for jth worker.
			for (int k = j; k < i; k++) {
				int current_time = max(dp[k][j - 1], sum[k][i - 1]);
				dp[i][j] = min(dp[i][j], current_time);
			}
		}
	} 
	return dp[n][num_people];
}


int main(int argc, char * argv[]){
	int arr_a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> nums(arr_a, arr_a + sizeof(arr_a) / sizeof(int));
	int min_time = getMinTimeInWorkers(nums, 5);
}