class LRUCache {
	private:
		unordered_map<int, pair<int, list<int>::iterator>> cache; // key, (value, iter);
		list<int> used;
		int capacity;

	public:
		LRUCache(int capacity) {
			this->capacity = capacity;
		}

		int get(int key) {
			auto find_iter = cache.find(key);
			if (find_iter == cache.end()) return -1;

			used.erase(find_iter->second.second);
			used.push_back(key);
			cache[key] = make_pair(find_iter->second.first, --used.end());
			return find_iter->second.first;
		}

		void put(int key, int value) {
			auto find_iter = cache.find(key);
			if (find_iter == cache.end()) {
				if (used.size() == capacity) {
					int del_key = used_front();
					cache.erase(del_key);
					used.pop_front();
				}
				used.push_back(key);
				cache[key] = make_pair(value, --used.end());
			} else {
				used.erase(find_iter->second.second);
				used.push_back(key);
				cache[key] = make_pair(value, --used.end());
			}
		}
};
