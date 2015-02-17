// version1 push O(1), pop O(N)
// this way, queue2 is treated as a buffer
template <typename T>
class m_stack {
public:
	void push(T elem) {
		m_q1.push(elem);
	}

	T pop() {
		if (empty())
			throw new exception("Stack is already Empty!");
		else {
			while (m_q1.size() > 1) {
				m_q2.push(m_q1.front());
				m_q1.pop();
			}
			T m_ret = m_q1.front();
			m_q1.pop();
			swap(m_q1, m_q2); 
			return m_ret;
		}
	}
	bool empty() {
		return m_q1.size() == 0;
	}

private:
	queue<T> m_q1;
	queue<T> m_q2;
};

// version2 push O(N), pop O(1)
// In this way, we keep queue1 as stack shapes, and push new in q2 and concatenate q1. 
// pop from queue1. And queue2 is only used for push the new in the front, which is different than original queue(insert from behind).
template <typename T>
class m_stack2 {
public:
	void push(T elem) {
		// make sure q2 is always empty when we do inserting
		m_q2.push(elem);
		while (!m_q1.empty()) {
			m_q2.push(m_q1.front());
			m_q1.pop();
		}
		// make q2 empty, and store the stack shape in q1
		swap(m_q1, m_q2); 
		return;
	}

	T pop() { 
		if (empty())
			throw new exception("Stack is already Empty!");
		else {
			T m_ret = m_q1.front();
			m_q1.pop();
			return m_ret;
		}
	}

	bool empty() {
		return m_q1.size() == 0;
	}

private:
	queue<T> m_q1;
	queue<T> m_q2;
};
