/*
Algorithm:          First Bad Version (LeetCode Problem #278)

Task:               You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of 
                    your product fails the quality check. Since each version is developed based on the previous version, all the versions 
                    after a bad version are also bad. Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one,
                    which causes all the following ones to be bad. You are given an API bool isBadVersion(version) which returns whether 
                    version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Solution:           Use binary search to find the first bad version in range 1 to n.
                    First, determine the earliest version (early_ver), the latest version (late_ver), and the middle version (mid_ver)
                    between 1 and n. Then use the values to iteratively perform a binary search.
                        • If the middle version is bad and the version preceding it is not bad, return the middle version is the first bad 
                          version.
                        • If the middle version is bad and the version preceding it is bad, set the middle version as the latest version
                          and continue the loop.
                        • If the middle version is not bad and the version preceding it is not bad, set the middle version as the earliest
                          version and continue the loop.

Time complexity:    O(log(N))
                        N = number of versions

Space complexity:   O(1)

Auxiliary space:    O(1)

Resources:          https://leetcode.com/problems/first-bad-version/solutions/
*/

#include <iostream>
using std::cout;
using std:: endl;

int firstBadVer = 0;

// The API isBadVersion is defined for you.
bool isBadVersion(int version)
{
    if (version >= firstBadVer)
        return true;
    return false;
}

int firstBadVersion(int n) 
{
    int early_ver = 1;
    int late_ver = n;

    while (early_ver <= late_ver)
    {
        int mid_ver = early_ver + (late_ver - early_ver) / 2;

        // If the current version is bad and the version preceding it is good, then the current version is the first bad version.
        if (isBadVersion(mid_ver) && !isBadVersion(mid_ver - 1))
            return mid_ver;
        else if (isBadVersion(mid_ver))
            late_ver = mid_ver - 1;
        else if (!isBadVersion(mid_ver))
            early_ver = mid_ver + 1;
    }

    return 0;
}

int main()
{
    // Test case 1.
    firstBadVer = 4;
    int badVer = firstBadVersion(5);
    (badVer != 0) ? cout << "The first bad version is " << badVer << endl : cout << "There are no bad versions.\n";

    // Test case 2.
    firstBadVer = 1;
    badVer = firstBadVersion(1);
    (badVer != 0) ? cout << "The first bad version is " << badVer << endl : cout << "There are no bad versions.\n";
    
    return 0;
}