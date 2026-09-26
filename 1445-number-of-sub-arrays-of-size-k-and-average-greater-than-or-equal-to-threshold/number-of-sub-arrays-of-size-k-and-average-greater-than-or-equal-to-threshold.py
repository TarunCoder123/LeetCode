class Solution:
    def numOfSubarrays(self, arr: list[int], k: int, threshold: int) -> int:
        low=0
        high=0
        sum=0
        count=0
        while high<len(arr):
            if high-low+1<k:
                sum+=arr[high]
                high+=1
            else:
                sum+=arr[high]
                if sum/k >= threshold:
                    count+=1
                # print(sum)
                sum-=arr[low]
                low+=1
                high+=1
        return count
    
        
