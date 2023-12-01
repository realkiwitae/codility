#include <limits.h>
#include <vector>

using namespace std;

int solution(vector<int> &A) {

    int N = A.size();

    long long ans = INT_MIN;
    long long mini = INT_MAX;
    long long sum = 0; 
    for(int i = 1 ; i < N-1; i++){
        if(sum-mini < 0){
            sum = 0;
            mini = INT_MAX;
        }
        mini = min(mini,(long long)A[i]);
        sum += A[i];
        ans = max(ans,sum-mini);
    }

    mini = INT_MAX;
    sum = 0;
    for(int i = N-2 ; i > 1; i--){
        if(sum-mini < 0){
            sum = 0;
            mini = INT_MAX;
        }
        mini = min(mini,(long long)A[i]);
        sum += A[i];
        ans = max(ans,sum-mini);
    }

    return ans;
}