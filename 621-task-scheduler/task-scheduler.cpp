class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char& ch : tasks) {
            freq[ch - 'A']++;
        }
        
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;
            int cycle = n + 1;
            int task_count = 0; 

            // 1. Process up to 'cycle' number of tasks
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    int current_freq = pq.top();
                    pq.pop();
                    task_count++; 
                    current_freq--;
                    if (current_freq > 0) {
                        temp.push_back(current_freq);
                    }
                }
            }

            // 2. Safely push remaining tasks back into the heap
            // Range-based for loop avoids any vector index/pointer arithmetic errors
            for (int remaining_freq : temp) {
                pq.push(remaining_freq);
            }
            
            // 3. Calculate time based on whether more tasks are left
            if (pq.empty()) {
                time += task_count; 
            } else {
                time += cycle;
            }
        }
        return time;
    }
};
