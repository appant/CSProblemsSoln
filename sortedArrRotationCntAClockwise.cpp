#include <stdio.h>

// Function to find the number of times the array is rotated
int findRotationCount(int arr[], int n)
{
	// search space is arr[low..high]
	int low = 0, high = n - 1;

	// iterate till search space contains at-least one element
	while (low <= high)
	{
		// if the search space is already sorted, we have
		// found the minimum element (at index low)
		if (arr[low] <= arr[high])
			return (n-low)%n; //if the pivot element is the last element, there has been no rotation, so return n-low modulus n. 

		int mid = (low + high) / 2;

		// find next and previous element of the mid element		
		int next = (mid + 1) % n;
		int prev = (mid - 1 + n) % n;

		// if mid element is less than both its next and previous
		// neighbor, then it is the minimum element of the array

		if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
			return n-mid; //for anticlockwise rotation count. 

		// if arr[mid..high] is sorted and mid is not the minimum element,
		// then pivot element cannot be present in arr[mid..high] and
		// we can discard arr[mid..high] and search in the left half

		else if (arr[mid] <= arr[high])
			high = mid - 1;

		// if arr[low..mid] is sorted then pivot element cannot be present in
		// it and we can discard arr[low..mid] and search in the right half

		else if (arr[mid] >= arr[low])
			low = mid + 1;
	}

	// invalid input
	return -1;
}

// main function
int main(void)
{
	int arr[] = { 1,2,3,4,5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int count = findRotationCount(arr, n);
	printf("The array is rotated %d times", count);

	return 0;
}
