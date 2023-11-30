#include <stack>
#include <vector>

using namespace std;

int solution(vector<int> &H) {
    
    int ans = 0;

    stack<int> blocks;

    for(int i : H){
        while(!blocks.empty() && blocks.top() > i)blocks.pop();
        if(!blocks.empty() && blocks.top() == i)continue;
        ans++;
        blocks.push(i);
    }

    return ans;    
}