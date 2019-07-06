
#include "../my_include.h"
#include "../my_util.h"


class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        cur = 0;
    }
    int get(int key) {
        auto iter = map.find(key);
        if (iter != map.end()) {
            int val = iter->second->second;
            pair<int,int> pr = make_pair(iter->second->first, iter->second->second);
            list_pair.erase(iter->second);
            list_pair.push_front(pr);
            map[key] = list_pair.begin();
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto iter = map.find(key);
        pair<int, int> pr = make_pair(key, value);
        if (iter != map.end()) {
            list_pair.erase(iter->second);
            list_pair.push_front(pr);
            map[key] = list_pair.begin();
            return;
        }
        if (cur == cap) {
            auto pr = list_pair.back().first;
            list_pair.erase(map[pr]);
            map.erase(pr);   
            cur--;
        }
        list_pair.push_front(pr);
        map[key] = list_pair.begin();
        cur++;
       
    }
    int cap;
    int cur;
    list<pair<int,int>> list_pair;
    unordered_map<int, list<pair<int,int>>::iterator  > map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{

	LRUCache cache(2);

	cache.put(1, 1);
	cache.put(2, 2);

	return 1;
}
