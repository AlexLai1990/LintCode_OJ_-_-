/* reference
http://www.ninechapter.com/problem/2/
https://github.com/Linzertorte/SRM/blob/master/169Div1/FairWorkload.java#L22
http://community.topcoder.com/stat?c=problem_statement&pm=1901&rd=4650
*/

// One way to distribute assignment evenly. Binary search + DP
int getNumberWorders(const vector<int> &inputs, int limit, vector<vector<int> > &m_res, int &per_max);

vector<vector<int> > evenlyWorkAssign(vector<int> inputs, int numberofworkers) {
	vector<vector<int> > m_res(numberofworkers, vector<int> ());
	int curr_load;
	// assume that each person cannot do twice max load in the inputs.
	int load_start = 0, load_end = 2 * *max_element(inputs.begin(), inputs.end());
	int per_max = INT_MAX;
	while (load_start + 1 < load_end) {
		curr_load = load_start + (load_end - load_start) / 2;
		if (getNumberWorders(inputs, curr_load, m_res, per_max) <= numberofworkers)
			load_end = curr_load;
		else
			load_start = curr_load;
	}
	return m_res;
}

int getNumberWorders(const vector<int> &inputs, int limit, vector<vector<int> > &m_res, int &per_max) {
	int sum = 0;
	int max_sum = INT_MIN;
	int count = 1;
	vector<int> works;
	vector<vector<int> > testworks;
	for (int i = 0; i < inputs.size(); i++) {
		if (inputs[i] > limit)
			return INT_MAX;
		sum += inputs[i];
		works.push_back(inputs[i]);
		if (sum >= limit) {
			count++;
			if (sum > limit) {
				sum -= inputs[i];
				if (max_sum < sum)
					max_sum = sum;
				sum = inputs[i];
				works.pop_back();
			}
			else {
				sum = 0;
				max_sum = limit;
			}
			testworks.push_back(works);
			works.clear();
			if (sum > 0)
				works.push_back(sum);
		}
	}
	if (sum > 0) {
		count++; 
		testworks.push_back(works);
	}
	if (testworks.size() <= m_res.size() && max_sum < per_max)
		per_max = max_sum;
		m_res = testworks;
	return count;
}

int main(int argc, char * argv[]){
	int arr_a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> nums(arr_a, arr_a + sizeof(arr_a) / sizeof(int));
	vector<vector<int> > m_evenlyWorkAssign = evenlyWorkAssign(nums, 5);
	return 1;
}
