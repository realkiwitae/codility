#include <vector>

using namespace std;


int leader(vector<int>& A, vector<int>& counts){
    int N = A.size();
    if(N<1)return -1;

    int cand = -1;
    int count = 0;
    int ans = -1;
    for(int i = 0; i < N;i++){
        
        if(!count){
            cand = A[i];
            ans = i;
        }
        count += cand == A[i]?1:-1;
    }
    
    counts = vector<int>(N,0);
    counts[0] = A[0] == cand;
    for(int i = 1; i < N ;i++){
        counts[i]= counts[i-1];
        if(A[i] == cand)counts[i]++;
    }
    return counts.back()>N/2?ans:-1;
}


int solution(vector<int> &A) {
    int N = A.size();
    vector<int> counts;
    
    // find leader and prefix count sums
    int idx = leader(A,counts);
    
    
    if(idx<0)return 0;

    int ans = 0;
    // check for equileaders
    for(int i = 0; i < N-1; i++){
        if(counts[i]>(i+1)/2. && (counts.back()-counts[i])>(N-1-i)/2.)ans++;
    }

    return ans;

}