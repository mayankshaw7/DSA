#include <bits/stdc++.h>
using namespace std;

int findLastOccurrenceRecursive(const vector<int> &vec, int target, int index)
{
    // Base case: if index is less than 0, target is not found
    if (index < 0)
    {
        return -1;
    }
    // Check if the current element is the target
    if (vec[index] == target)
    {
        return index; // Return the index of the last occurrence
    }
    // Recursive call to check the next element
    return findLastOccurrenceRecursive(vec, target, index - 1);
}

int main()
{
    // Test cases
    vector<int> testVector1 = {1, 2, 3, 4, 5, 3, 6};
    int target1 = 3;
    cout << "Last occurrence of " << target1 << " is at index: " << findLastOccurrenceRecursive(testVector1, target1, testVector1.size() - 1) << std::endl;

    return 0;
}
