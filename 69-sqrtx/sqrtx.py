class Solution:
    def mySqrt(self, x: int) -> int:
        low = 1
        high = x
        ans = 0
        while low<=high:
            mid = low + (high-low)//2
            print(low,high,mid)
            if mid*mid==x:
                return mid
            elif mid*mid>x:
                high = mid-1
            else:
                ans = mid
                low = mid+1
        return ans














        