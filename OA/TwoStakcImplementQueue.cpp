template <typename T>
class m_queue {
public:
	void push(T one) {
		m_inbox.push(one);
		size++;
		return;
	}

	T pop() { 
		if (m_outbox.empty()) {
			while (!m_inbox.empty()) {
				m_outbox.push(m_inbox.top());
				m_inbox.pop();
			}
		} 
		if (m_outbox.size() == 0) {
			throw new exception("Queue is already empty!");
		} 
		T m_ret = m_outbox.top();
		m_outbox.pop();
		size--;
		return m_ret;
	}

	bool empty() {
		return size == 0;
	}

private:
	stack<T> m_inbox;
	stack<T> m_outbox;
	int size = 0;
};

template <typename T>
class m_queue2 {
public:
	void add(T elem) {
		if (m_stack.empty()) {
			m_stack.push(elem);
		}
		else {
			T m_top = m_stack.top();
			m_stack.pop();
			add(elem);
			m_stack.push(m_top);
		}
	}

	T pop() {
		if (m_stack.empty())
			throw new exception("Queue is already empty!");
		else {
			T m_ret = m_stack.top();
			m_stack.pop();
			return m_ret;
		}
	}

	bool empty() {
		return m_stack.size() == 0;
	}

private:
	stack<T> m_stack; 
};