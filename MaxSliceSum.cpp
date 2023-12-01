#include <vector>

using namespace std;

int solution(vector<int> &A) {
    int N = A.size();
    long long ans = A[0];
    long long sum = A[0];
    for(int i = 1 ; i < N; i++){

        if(sum <0)sum=0;
        sum+=A[i];
        ans = max(sum,ans);
    }
    return ans;
}