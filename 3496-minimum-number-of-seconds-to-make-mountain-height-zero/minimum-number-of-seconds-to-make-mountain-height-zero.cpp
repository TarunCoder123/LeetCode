class Solution {
public:

    bool solve(long long time, int mountainHeight, vector<int>& workerTimes){

        for(int t : workerTimes){

            long long limit = time / t;

            long long start = 0, end = 100000;
            long long ans = 0;

            while(start <= end){

                long long mid = start + (end-start)/2;

                if(mid*(mid+1)/2 <= limit){
                    ans = mid;
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }

            mountainHeight -= ans;

            if(mountainHeight <= 0)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long start = 0, end = 1e18;
        long long ans = end;

        while(start <= end){

            long long mid = start + (end-start)/2;

            if(solve(mid, mountainHeight, workerTimes)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return ans;
    }
};