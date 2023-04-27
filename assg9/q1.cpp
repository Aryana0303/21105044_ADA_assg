#include<iostream>
using namespace std;
// maximise sum of profits and sum of weights should be less than the capacity

int knapsack(int * weights, int * profits, int n, int maxWeight) {
  
  int ** dp = new int * [n + 1];  //(n+1) rows 

  
  for (int i = 0; i < n + 1; i++) {

   
    dp[i] = new int[maxWeight + 1]; //(maxWeight+1) columns
  }

  
  
  for (int i = 0; i < n + 1; i++) {
    
    for (int j = 0; j < maxWeight + 1; j++) {
      
      if (i == 0 || j == 0) // rows and columns are filled with 0
     
        dp[i][j] = 0;  

      
      else if (weights[i - 1] > j) {  //If weights[i - 1] > j, then we cannot include item i in the knapsack, since it is too heavy to fit.
      // In this case, we simply copy the value from the previous row i-1 at the same capacity j, i.e., dp[i][j] = dp[i - 1][j].


       
        dp[i][j] = dp[i - 1][j];
      } 
       else {

     
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + profits[i - 1]);

      }

    }

  
  }
  return dp[n][maxWeight];

}


int main() {

  
  int n;
  
  cin >> n;
  
  int * weights = new int[n];
  
  int * profits = new int[n];

  
  for (int i = 0; i < n; i++) {
    
    cin >> weights[i];
  }

  
  for (int i = 0; i < n; i++) {
    
    cin >> profits[i];
  }

  
  int maxWeight;
  
  cin >> maxWeight;

  
  cout << knapsack(weights, profits, n, maxWeight);


}