template <typename T>
class ArrayQueue
{
public:
	static const size_t CAPACITY = 30;

	ArrayQueue() {
		this->first = 0;
		this->count = 0;
		this->last = this->CAPACITY - 1;
	}

	void enqueue(const T& entry) {
		assert(this->size() < this->CAPACITY);
		this->last = this->next_index(this->last);
		this->data[last] = entry;
		this->count++;
	}

	T& dequeue() {
		assert(!this->empty());
		T& result = this->data[this->first];
		this->first = this->next_index(this->first);
		this->count--;
		return result;
	}

	bool empty() const {
		return (this->count == 0);
	}

	T front() const {
		assert(!this->empty());
		return this->data[this->first];
	}

	T rear() const {
		assert(!this->empty());
		return this->data[this->last];
	}

	size_t size() const {
		return this->count;
	}
private:
	T data[CAPACITY];
	size_t first;
	size_t last;
	size_t count;
	size_t next_index(size_t i) const {
		return (i + 1) % CAPACITY;
	}
};