#include <vector>

using namespace std;

int solution(vector<int> &A) {
    int N = A.size();
    
    if(N<1)return -1;

    int cand = -1;
    int count = 0;
    int ans = -1;
    for(int i = 0; i < N ;i++){
        
        if(!count){
            cand = A[i];
            ans = i;
        }
        count += cand == A[i]?1:-1;
    }
    
    count = 0;
    for(int i :A){
        if(i == cand && ++count>N/2.)return ans;
    }
    return -1;
}