class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
     unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    
    // Custom comparator for min-heap (sort by frequency ascending, then by value descending)
    auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) return a.second < b.second; // Same freq → higher val first
        return a.first > b.first; // Lower freq comes first
    };
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
    
    for (auto& [num, count] : freq) {
        minHeap.push({count, num});
    }
    
    vector<int> result;
    while (!minHeap.empty()) {
        auto [count, num] = minHeap.top();
        minHeap.pop();
        for (int i = 0; i < count; i++) {
            result.push_back(num);
        }
    }
    
    return result;
    }
};