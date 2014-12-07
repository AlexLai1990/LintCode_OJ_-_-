int median(vector<int> &nums) {
    // write your code here
    return findkth(nums, 0, nums.size() - 1, (nums.size() + 1) / 2);
}

int findkth(vector<int> &nums, int left, int right, int k) {
    int pivot = left + (right - left) / 2;
	int pivot_value = nums[pivot];
	swap(nums[left], nums[pivot]);

	int i = left + 1, j = right;
	int temp;
	while (i <= j) {
		while (i <= nums.size() - 1 && nums[i] < pivot_value) {
			i++;
		}
		while (j >= 0 && nums[j] > pivot_value) {
			j--;
		}
		if (i <= j) {
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			i++;
			j--;
		}
	}
	swap(nums[left], nums[j]);
	if (j - left == k - 1)
		return nums[j];
	else if (j - left < k - 1) {
		return findkth(nums, j + 1, right, k - (j - left + 1));
	}
	else {
		return findkth(nums, left, j - 1, k);
	}
}