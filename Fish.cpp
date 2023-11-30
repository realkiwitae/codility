#include <stack>
#include <vector>

using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    int N = A.size();
    int ans = 0;

    stack<int> downstream;

    for(int i = 0; i < N;i++){
        if(B[i])downstream.push(A[i]);
        else{
            while(!downstream.empty() && A[i]> downstream.top())downstream.pop();
            if(downstream.empty())ans++;
        }
    }

    return ans + downstream.size();
}
