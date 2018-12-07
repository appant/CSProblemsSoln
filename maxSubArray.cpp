#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

/*O(n) solution to finding the sub-array with maximum sum.
Given an array of integers, find maximum sum subarray among all subarrays possible.

For example,

Input: {2, -4, 1, 9, -6, 7, -3}

Output= Maximum sum is 11 which belongs to the sub array {1, 9, -6, 7}; 

*/

int maximumSumSubarray(vector<int> input){
	int maxSum = INT_MIN;
	int currSum = 0;
	for(int i : input){
		currSum = max(currSum+i, i);
		maxSum = max(maxSum, currSum);			
	}
	return maxSum;
}

int main()
{
  vector<int> input = {-8, -4, -1, -2, -6, -7, -3};
  cout << maximumSumSubarray(input) << endl;
}
