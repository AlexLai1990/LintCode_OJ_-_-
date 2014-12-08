int hashCode(string key, int HASH_SIZE) {
	// write your code here 
	
	HASH_SIZE = (unsigned long long) HASH_SIZE;
	if (HASH_SIZE == 0)
		return -1;
	if (key.length() == 0)
		return 0;
	int len = key.length();
	vector<unsigned long long> m_dict(1025, 1);
	m_dict[1] = 33 % HASH_SIZE;
	for (int i = 2; i < 11; i++) {
		m_dict[i] = m_dict[i - 1] * m_dict[i - 1]  % HASH_SIZE;
	}
	unsigned long long m_res = 0;
	int shift = 0;
	int digit = 1;
	for (int i = 0; i < len; i++) {
		long long N = len - i - 1;
		unsigned long long temp_mul = key[i];
		while (shift < 10) { 
			if (digit << shift & N) {
				temp_mul *= m_dict[shift + 1];
	    	if (temp_mul > HASH_SIZE)
	    	    temp_mul %= HASH_SIZE; 
			}
			shift++;
		}
		m_res += temp_mul;
	    if (m_res > HASH_SIZE)
	        m_res %= HASH_SIZE;
		shift = 0;
	}
	return m_res;
}