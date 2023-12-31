#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <assert.h>
#include <vector>
#include <string>

using namespace std;
using namespace std::chrono;

high_resolution_clock::time_point start;
#define NOW high_resolution_clock::now()
#define TIME duration_cast<duration<double>>(NOW - start).count()

void runP1();
void runP2();
void runP3();
void runP4();

void run(){
  runP1();
  runP2();
  runP3();
  runP4();
}

int main(int argc, char** argv)
{
  start = NOW;
  std::cout << "-------" << std::endl;

  // test codility
  run();


  std::cout << "-------" << std::endl;
  std::cout << TIME << std::endl;
}

int solutionP1(vector<int> &client);
int solutionP2(string &S);
int solutionP3(int n);
int solutionP4(int K,vector<vector<int>> &A);

void runP1(){
    std::cout << "Test 1" << std::endl;
    vector<int> client = {3,2,4,5,1};
    assert (solutionP1(client) == 2);
    client = {1,2,3,4,5};
    assert (solutionP1(client) == 0);
    client = {3,2,7,5,4,1,6};
    assert (solutionP1(client) == 4);
    client = {1};
    assert (solutionP1(client) == 0);
}

int solutionP1(vector<int> &client) {
    // We got a queue of clients that wanna pickup 1 package each client[k]

    int N = client.size();
    // bounded to 1e6 -> no overflow possible for worst case
    // elements are distincts

    int ans = 0;
    for(int i = 0; i < N; i++){
          ans = max(ans, client[i] - i-1);
    }


    return ans;
}

void runP2(){
    std::cout << "Test 2" << std::endl;
    string S = "ayxbx";
    assert (solutionP2(S) == 3);
    S = "xzzzy";
    assert (solutionP2(S) == 0);
    S = "toyxmy";
    assert (solutionP2(S) == 5);
    S = "apple";
    assert (solutionP2(S) == 4);
}
int solutionP2(string &S){
    int N = S.size();

    /* there are N-1 ways to split the string in 2 non empty parts
     we want to track occurence of X and Y in each parts
     lets use prefix sums to know at any given time how many are on left and right side of the cut

     Time complexity is in O(N) and space complexity is in O(N) as we stored the prefix sum for x and y
*/

    // N is bounded so no overflow possible
    vector<int> count_X(N,0);
    vector<int> count_Y(N,0);
    count_X[0] = S[0]=='x';
    count_Y[0] = S[0]=='y';
    for(int i = 1; i < N;i++){
        
        count_X[i] = count_X[i-1];
        count_Y[i] = count_Y[i-1];

        if(S[i] == 'x')count_X[i]++;
        else if(S[i]== 'y')count_Y[i]++;
    }
    if(count_X.back() < 1 && count_Y.back() < 1)return N-1;
    //  Let's check every cuts 
    
    int ans = 0;
    for(int i = 0; i < N-1; i++){
        // [..i] | [i+1...]
        if(count_X[i] == count_Y[i]){ans++;continue;}
        if(count_X.back() - count_X[i] == count_Y.back() - count_Y[i]){ans++;continue;}
    }

    return ans;
  }

void runP3(){
  std::cout << "Test 3" << std::endl;
  assert (solutionP3(1) == -1);
  assert(solutionP3(4) == -1);
  assert(solutionP3(100) == -1);
  assert(solutionP3(955) == 4);
}

int solutionP3(int n){

  /* I do find the solution poorly written as it is "hard" to grasp with this variable names ~*/

  // Decompose n in binary 
  int d[30];
  int l = 0;
  while (n > 0) {
      d[l] = n % 2;
      n /= 2;
      l++;
  }
  // l is the length of the binary representation of n (Q in the problem statement)
  for (int p = 1; p <= l/2; ++p) { // to respect P <= Q/2
      bool ok = true;
      for (int i = 0; i < l - p; ++i) {
          if (d[i] != d[i + p]) {
              ok = false;
              break;
          }
      }
      if (ok) {
          return p;
      }
  }
  return -1;
}

void runP4(){
    std::cout << "Test 4" << std::endl;

  vector< vector<int> > A = {{0,1},{0,0}};
  assert(solutionP4(1,A) == 2);
  A = {{0,0,0,0},{0,0,1,0},{1,0,0,1}};
  assert(solutionP4(2,A) == 2);
  A = {{0,0,0,1},{0,1,0,0},{0,0,1,0},{1,0,0,0},{0,0,0,0}};
  assert(solutionP4(4,A) == 8);
}

int fill(vector< vector<int> > &A,int x , int y , int K, int houses){
  int ans = 0;
  int M = A.size();
  int N = A[0].size();
  /* bfs with no obstacle means fill with manahattan distance
    we do all the computation in place to save memory adding visits as +=10
    all information is stored in first digit 0 is empty 1 is house.
  */
  for(int i = max(0,x-K); i <= min(M-1,x+K);i++){
      for(int j = max(0,y-K+abs(i-x)); j <= min(N-1,y+K-abs(i-x));j++){
          if(A[i][j]%10)continue;
          A[i][j]+=10;
          if(A[i][j]/10 == houses)ans++;
      }
  }

  return ans;
}

int solutionP4(int K, vector< vector<int> > &A) {

    /* 
    Our approach is 
    Loop over the grid and check for houses
    For each house visit identify all reachable nodes (manathan(node,house) <= K).
    The answer contains the nb of nodes that are reachable from all houses 
    
    Time Complexity
    O(M*N*H*(K**2) as we go through all the nodes and for H houses found check for nodes in reach which is in O(K*K)
    Space Complexity O(1) we did it in place
    */
    // step 1 find the houses:
    int M = A.size();
    int N = A[0].size();
    
    int houses = 0;
    int ans = 0;
    for(int i = 0; i < M;i++){
        for(int j = 0; j < N ; j++){
            if(A[i][j]!=1)continue;
            // we found a house lets check which spot are within range
            ans = fill(A,i,j,K,++houses);
        }
    }

    return ans;
}