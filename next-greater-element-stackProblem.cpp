#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1); // Initialize result with -1
    stack<int> st;          // Stack to store elements

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop smaller or equal elements
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack not empty → top is next greater
        if (!st.empty()) {
            ans[i] = st.top();
        }

        // Push current element to stack
        st.push(arr[i]);
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> result = nextGreaterElements(arr);

    cout << "\nNext Greater Elements: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
