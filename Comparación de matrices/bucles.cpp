#include <chrono>
#include <iostream>

const int MAX = 100;

using namespace std;

int main() {

  double A[MAX][MAX], x[MAX], y[MAX];
  int count = 0;
  for (int i = 0; i < MAX; i++) {
    x[i] = 1;
    y[i] = 0;
    for (int j = 0; j < MAX; j++) {
      A[i][j] = count;
      count++;
    }
  }

  auto start = std::chrono::system_clock::now();

  // First pair of loops ∗/
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      y[i] += A[i][j] * x[j];
      //cout << A[i][j] << " ";
    }
    //cout << endl;
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<float, std::milli> duration = end - start;
  std::cout << duration.count() << "s" << endl;

  // Assign y = 0
  cout << endl;

  start = std::chrono::system_clock::now();
  // Second pair of loops ∗/
  for (int j = 0; j < MAX; j++) {
    for (int i = 0; i < MAX; i++) {
      y[i] += A[i][j] * x[j];
      //cout << A[i][j] << " ";
    }
    //cout << endl;
  }
  end = std::chrono::system_clock::now();
  duration = end - start;
  std::cout << duration.count() << "s" << endl;
}
