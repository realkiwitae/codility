#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <assert.h>

using namespace std;
using namespace std::chrono;

high_resolution_clock::time_point start;
#define NOW high_resolution_clock::now()
#define TIME duration_cast<duration<double>>(NOW - start).count()

void run();


int main(int argc, char** argv)
{
  start = NOW;
  std::cout << "-------" << std::endl;

  // test codility
  run();


  std::cout << "-------" << std::endl;
  std::cout << TIME << std::endl;
}


void run(){
    std::cout << "Test 1" << std::endl;
    assert ("8"=="8");

}


