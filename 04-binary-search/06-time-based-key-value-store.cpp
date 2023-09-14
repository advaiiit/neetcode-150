#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> map;

    TimeMap() {
        map.clear();
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        return (map[key].size()) ? binarySearchTimestamp(key, timestamp, map[key]) : "";
    }
    // TC: O(NlogN)

private:
    string binarySearchTimestamp(string key, int timestamp, vector<pair<int, string>>& values) {
        int start = 0, end = values.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (values[mid].first <= timestamp) 
                start = mid + 1;
            else
                end = mid - 1;
        }

        return (start == 0) ? "" : values[start - 1].second;
    }
};