#include <vector>
#include <limits.h>

using namespace std;

int solution(vector<int> &A) {
    int mini = INT_MAX;
    int ans = 0;

    for(int i : A){
        if(i-mini > ans)ans = i-mini;
        mini = min(i,mini);
    }

    return ans;
}