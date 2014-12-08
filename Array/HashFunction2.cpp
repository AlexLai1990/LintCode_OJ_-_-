int hashCode(string key, int HASH_SIZE) {
	// write your code here 
	long res = 0;
    for (int i = 0; i < key.size(); i++){
        res = 33 * res + key[i];
        res = res % HASH_SIZE;
    }
    return (int)res; 
}