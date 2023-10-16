#include<iostream>
#include<vector>
#include <iomanip>
#include<numeric>
    

int FindTargetSumWaysRec(std::vector<int> &arr, int T, int total, int i, int sum, std::vector<std::vector<int>> &dp){
    // If all integers are processed
    if (i == arr.size()){
        // If target is reached
        if (sum == T)
            return 1;
        // If target is not reached
        return 0;
    }
 
    // If we have solved it earlier, then return the result from memory
    if (dp[i][sum + total] != -1)
        return dp[i][sum + total];
    
    // Calculate both sub-problems and save the results in the memory
    dp[i][sum + total] = FindTargetSumWaysRec(arr, T, total, i + 1, sum - arr[i], dp) + 
                         FindTargetSumWaysRec(arr, T, total, i + 1, sum + arr[i], dp);

    return dp[i][sum + total];
}

int FindTargetSumWays(std::vector<int> &arr, int T){
    int total = accumulate(arr.begin(), arr.end(), 0);

    // If the target can't be generated using the given numbers
    if (total < abs(T))
        return 0;
        
    // Initialize a lookup table
    std::vector<std::vector<int>> dp(arr.size(), std::vector<int> (2*total+1, -1));
    return FindTargetSumWaysRec(arr, T, total, 0, 0, dp);
}


// Driver code
int main(){
    std::vector<std::vector<int>> arrs = {{1}, {3, 3, 3, 3}, {2, 3, 4, 6, 8, 12}, {2, 2, 2, 4, 4, 4, 8, 8, 8}};
    std::vector<int> targets= {1, 6, 15, 18};

    // Let's uncomment this and check the effect of dynamic programming using memoization
    
    // arrs.push_back({2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3,
    //                 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3});
    // targets.push_back(42);

    for (int i=0; i<arrs.size(); ++i){
        std::string a =  "[" + std::to_string(arrs[i][0]);
        for (int j=1; j<arrs[i].size(); ++j)
            a = a + ", " + std::to_string(arrs[i][j]);
        a += "]";
        std::cout << i + 1 << ".\t Input array: " << a << std::endl;
        std::cout << "\t Target: " << targets[i] << std::endl;
        std::cout << "\t Number of ways in which we can find the target sum: " << FindTargetSumWays(arrs[i], targets[i]) << std::endl;
        std::cout << std::string(100, '-') << std::endl;
    }
    return 0;    
}
