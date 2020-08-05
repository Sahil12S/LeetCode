class Solution {
    bool isBadVersion(int version)
    {
        int first_bad_version = 3;
        return version < first_bad_version;
    }
public:
    int firstBadVersion(int n) {
        int first = n;
        int left = 1;
        int right = n;
        while (left < right)
        {
            int mid = left + (right - left ) / 2;
            if (!isBadVersion(mid))
            {
                left = mid + 1;
            }
            else if (mid < first)
            {
                first = mid;
                right = mid;
            }
        }
        return first;
    }
};