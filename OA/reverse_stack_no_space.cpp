void insertToBottom(stack<int> &stack, int num);
void reverseStack(stack<int>& s) {
	if (s.empty())
		return;
	int top = s.top();
	s.pop();
	reverseStack(s);
	insertToBottom(s, top);
	return;
}

void insertToBottom(stack<int> &stack, int num) {
	if (stack.empty())
		stack.push(num);
	else {
		int top = stack.top();
		stack.pop();
		insertToBottom(stack, num);
		stack.push(top);
	}
}
 