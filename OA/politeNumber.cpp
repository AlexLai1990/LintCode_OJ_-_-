int politeNumber(int n) {
	int end = (n + 1) / 2;
	int count = 0, sum = 0;
	int i = 1, start = 1;;
	while (i <= end + 1) {
		if (sum < n) {
			sum += i++;
		}
		else if (sum > n) {
			sum -= start;
			start++;
		}
		else {
			count++;
			sum -= start;
			start++;
		}
	}
	return count;
}