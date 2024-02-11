/*
name: Muhammad Sabeeh
ID: 23k-0002
purpose: The objective is to recursively identify a subset of elements from an array in such a way that the sum of these elements equals a specified target value.
*/
#include<iostream>

using namespace std;

// Function to check if there exists a subset with a given sum
bool hasSubsetSum(int arr[], int size, int targetSum) {
    // Base cases
    if (targetSum == 0) {
        return true;  // Subset with sum 0 always exists (empty subset)
    }
    
    if (size == 0) {
        return false;  // No numbers left to check
    }

    // If the last element is greater than the target sum, it won't be included in the subset as at least two numbers are needed
    if (arr[size - 1] > targetSum) {
        // Recursive case: excluding the last element
        return hasSubsetSum(arr, size - 1, targetSum);
    }

    // Recursive case: check if either including the last element or excluding it gives the target sum
    return hasSubsetSum(arr, size - 1, targetSum) || hasSubsetSum(arr, size - 1, targetSum - arr[size - 1]);
}

int main() {
    int n, target, i;
    cout << "Enter the size of the integer array:" << endl;
    cin >> n;
    int numeric[n];
    
    cout << "Enter the target sum:" << endl;
    cin >> target;
    
    for(i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ":" << endl;
        cin >> numeric[i];
    }
    
    if (hasSubsetSum(numeric, n, target)) {
        cout << "Subset with sum " << target << " exists." << endl;
    } else {
        cout << "Subset with sum " << target << " does NOT exist." << endl;
    }
    
    return 0;
}
