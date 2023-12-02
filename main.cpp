#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <assert.h>

using namespace std;
using namespace std::chrono;

high_resolution_clock::time_point start;
#define NOW high_resolution_clock::now()
#define TIME duration_cast<duration<double>>(NOW - start).count()

void runP1();
void runP2(){}
void runP3(){}
void runP4(){}

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


