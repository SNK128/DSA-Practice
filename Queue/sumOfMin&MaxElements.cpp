// C++ program to find sum of all minimum and maximum
// elements Of Sub-array Size k.


//TC=(n^2)*k 
#include <bits/stdc++.h>
using namespace std;

//TC=(n^2)*k 
int SumOfKsubArray(int arr[], int N, int k)
{
	// To store final answer
	int sum = 0;

	// Find all subarray
	for (int i = 0; i < N; i++) {
		// To store length of subarray
		int length = 0;
		for (int j = i; j < N; j++) {
			// Increment the length
			length++;

			// When there is subarray of size k
			if (length == k) {
				// To store maximum and minimum element
				int maxi = INT_MIN;
				int mini = INT_MAX;

				for (int m = i; m <= j; m++) {
					// Find maximum and minimum element
					maxi = max(maxi, arr[m]);
					mini = min(mini, arr[m]);
				}

				// Add maximum and minimum element in sum
				sum += maxi + mini;
			}
		}
	}
	return sum;
}

//TC=(n)*k 
int solve(int arr[],int n,int k)  // { 2, 5, -1, 7, -3, -1, -2 };
{
    int sum=0;
    for(int i=0;i<n-k+1;i++)
    {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int j=i;j<i+k;j++)
        {
            maxi=max(maxi,arr[j]);
            mini=min(mini,arr[j]);
        }
        sum+=mini+maxi;
        //  cout<<mini<<" "<<maxi<<" "<<sum<<endl;
    }
    return sum;
}


//TC:O(n)
//SC:O(k)
int optimised(int arr[],int n,int k)
{
	deque<int> maxi(k);
	deque<int> mini(k);
	int sum=0;

	for(int i=0;i<k;i++)
	{
		while(!mini.empty()&&arr[mini.back()]>=arr[i])
		mini.pop_back();

		while(!maxi.empty()&&arr[maxi.back()]<=arr[i])
		maxi.pop_back();

		mini.push_back(i);
		maxi.push_back(i);
	}
	sum+=arr[mini.front()]+arr[maxi.front()];

	for(int i=k;i<n;i++)
	{
		while(!mini.empty()&&mini.front()<=i-k)
		mini.pop_front();

		while(!maxi.empty()&&maxi.front()<=i-k)
		maxi.pop_front();

		while(!mini.empty()&&arr[mini.back()]>=arr[i])
		mini.pop_back();

		while(!maxi.empty()&&arr[maxi.back()]<=arr[i])
		maxi.pop_back();

		mini.push_back(i);
		maxi.push_back(i);

		sum+=arr[mini.front()]+arr[maxi.front()];
	}


	return sum;

}

// Driver program to test above functions
int main()
{
	int arr[] = { 2, 5, -1, 7, -3, -1, -2 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	cout << SumOfKsubArray(arr, N, k)<<endl;
    cout << solve(arr, N, k)<<endl;
	cout << optimised(arr, N, k)<<endl;


    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

