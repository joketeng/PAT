// 1029. Median (25)
// Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.

// Given two increasing sequences of integers, you are asked to find their median.

// Input

// Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (<=1000000) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.

// Output

// For each test case you should output the median of the two given sequences in a line.

// Sample Input
// 4 11 12 13 14
// 5 9 10 15 16 17
// Sample Output
// 13

#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int m, n, p = 0, q = 0;
    scanf("%d", &m);
    vector<long int> v1(m), v2(n);
    int cnt = ((m + n) - 1) / 2;
    for(int i = 0; i < m; i++)
        scanf("%ld", &v1[i]);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%ld", &v2[i]);
    while(cnt) {
        while(p < m && q < n && v1[p] < v2[q] && cnt) {
            p++;
            cnt--;
        }
        while(p < m && q < n && v1[p] >= v2[q] && cnt) {
            q++;
            cnt--;
        }
        while(p < m && q >= n && cnt) {
            p++;
            cnt--;
        }
        while(p >= m && q < n && cnt) {
            q++;
            cnt--;
        }
    }
    long int ans;
    if(p < m && q < n)
        ans = v1[p] < v2[q] ? v1[p] : v2[q];
    else
        ans = p < m ? v1[p] : v2[q];
    printf("%ld", ans);
    return 0;
}