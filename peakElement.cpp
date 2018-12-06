#include <vector>
#include <iostream>

using namespace std;
int findPeakElement(vector<int>& nums) {        
    int l = 0;
    int h = nums.size()-1;
    while(l<h){
        int mid = l + (h-l)/2;
        if (nums[mid] > nums[mid + 1])
            h = mid;
        else
            l = mid + 1;
    }
    return nums[l];        
}  

int main(){
  vector<int> x[] = {{1,5, 8, 9, 7, 2,0},{35, 5, 8, 20}, {1,1,1,1}, {1,2,3,4,5,6,7}, {100, 90, 80, 70, 60}};
  cout << "Peak elements " << endl;
  for(vector<int> input : x)
  {
    cout << findPeakElement(input) << endl;
  }
  return 0; 
}
