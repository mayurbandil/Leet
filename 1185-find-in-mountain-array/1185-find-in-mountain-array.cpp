class Solution {
public:
    void findPeak(int i, int l, int &peak, MountainArray &mountainArr) {
        while (i <= l) {
            int mid = i + (l - i) / 2;
            int midVal = mountainArr.get(mid);
            int nextVal = mountainArr.get(mid + 1);
            
            if (midVal > nextVal) {
                peak = mid;
                l = mid - 1;
            } else {
                i = mid + 1;
            }
        }
    }
    
    int binarySearch(int l, int r, int target, MountainArray &mountainArr, bool reverse) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int midVal = mountainArr.get(mid);
            
            if (midVal == target) {
                return mid;
            } else if ((midVal < target) ^ reverse) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak = 0;
        findPeak(0, n - 1, peak, mountainArr);
        
        int left = binarySearch(0, peak, target, mountainArr, false);
        if (left != -1) {
            return left;
        }
        
        int right = binarySearch(peak + 1, n - 1, target, mountainArr, true);
        return right;
    }
};
