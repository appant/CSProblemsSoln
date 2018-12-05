#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
int findFirstOccurrence(vector<int> arr, int num){
	int lo = 0;
	int hi = arr.size() - 1;
	while(lo <= hi)
	{
		int mid = lo + (hi-lo)/2;
		if(arr[mid] == num){
		    if(mid==0)
		        return mid;		        
			else if(arr[mid-1] == num)
				hi = mid-1;
			else 
				return mid;
		}
		
		if(arr[mid] < num)
			lo = mid+1;
		else
			hi = mid-1;
	}
	return -1;
}

// main function
int main(void)
{
	vector<int> arr = { 1,2,3,3,3,4,5,5,6 };	
	cout << "First occurence of 1 is at " << findFirstOccurrence(arr, 1) << endl;
    cout << "First occurence of 3 is at " << findFirstOccurrence(arr, 3) << endl;
	return 0;
}
