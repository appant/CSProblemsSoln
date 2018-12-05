#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

/*
O(lgN) solution to finding a number of occurence of a number in a sorted array. 
*/

int numberOfOccurrence(vector<int> arr, int num){
	int lo = 0;
	int hi = arr.size() - 1;
	int numOfOccurence = 0;
	while(lo <= hi)
	{
		int mid = lo + (hi-lo)/2;
		if(arr[mid] == num){
		    numOfOccurence = 1;
		    int temp = mid+1;
		    while(temp<arr.size())
		    {
		        if(arr[temp++]!=num)
		            break;
		        numOfOccurence++;
		    }
		    temp = mid-1;
		    while(temp<arr.size())
		    {
		        if(arr[temp--]!=num)
		            break;
		        numOfOccurence++;   
		    }
		    break;
		}
		
		if(arr[mid] < num)
			lo = mid+1;
		else
			hi = mid-1;
	}
	return numOfOccurence;
}

int main(void)
{
	vector<int> arr = { 1,2,3,3,3,4,5,5,6 };	
	cout << "# of occurence of 5 is at " << numberOfOccurrence(arr, 5) << endl;
    cout << "# of occurence of 3 is at " << numberOfOccurrence(arr, 3) << endl;
	return 0;
}
