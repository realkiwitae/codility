// you can use includes, for example:
#include <algorithm>
#include <unordered_set>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;

int solution(vector<int> &A) {
    typedef long long ll;
    vector<pair<ll,int>> arcs;
    int N = A.size();
    for(int i= 0; i < N;i++){
        arcs.push_back({(ll)i-A[i],i});
        arcs.push_back({(ll)i+A[i],i});
    }

    sort(arcs.begin(),arcs.end(),[](const pair<ll,int>&a,const pair<ll,int>&b){
        if(a.first < b.first)return true;
        else if(a.first == b.first && b.second<a.second)return true;
        return false;
    });

    long long ans = 0;

    unordered_set<int> discs;
    /*for(int i = 0; i < 2*N;i++) cout << "("<<arcs[i].first << " , "<< arcs[i].second << " )" << endl;*/
    for(int i = 0; i < 2*N;i++){
        auto it = discs.find(arcs[i].second);
        if( it != discs.end()){
            // update count
            discs.erase(it);
            if(ans + discs.size() > 10000000)return -1;
            ans += discs.size();
            continue;
        }
        discs.insert(arcs[i].second);
    }

    return ans;

}