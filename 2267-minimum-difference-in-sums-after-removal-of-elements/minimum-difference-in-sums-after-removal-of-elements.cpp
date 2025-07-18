class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m=nums.size();
        int n=m/3;
        // 1)prefic: keep n smallest so fat -----------------
        vector<long long> leftMin(m,0);
        priority_queue<int> maxHeap;
        long long sum=0;
        for(int i=0;i<m;i++){
            maxHeap.push(nums[i]);
            sum+=nums[i];

                 if ((int)maxHeap.size() > n) { // remove largest → keep n smallest
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            
            if (i >= n - 1)
                leftMin[i] = sum;          
        }

         /* ---------- 2) suffix: keep n largest so far ---------- */
        vector<long long> rightMax(m, 0);  
        priority_queue<int, vector<int>, greater<int>> minHeap;  
        sum = 0;
        
        for (int i = m - 1; i >= 0; --i) {
            minHeap.push(nums[i]);
            sum += nums[i];
            
            if ((int)minHeap.size() > n) { 
                sum -= minHeap.top();
                minHeap.pop();
            }
            
            if (i <= 2 * n)
                rightMax[i] = sum;         
        }

         long long answer = LLONG_MAX;
        for (int border = n - 1; border <= 2 * n - 1; ++border) {
            long long diff = leftMin[border] - rightMax[border + 1];
            answer = min(answer, diff);
        }
        return answer;
    }
};