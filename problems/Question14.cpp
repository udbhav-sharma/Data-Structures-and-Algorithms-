/*An element in a sorted array can be in O(logn) time via binary search. But suppose I rotated the
sorted array at some pivot unknown to you beforehand. So for instance, 1 2 3 4 5 might become 3 4 5 1 2.
Now devise a way to find Peak in rotated array in O(logn) time */
 
#include <iostream>
#include <vector>

using namespace std;

std::vector<int> Input;

int FindRotationIndex(int i,int j)
{
	int m=(i+j)/2;
	
	int left=max(m-1,i);
	int right=min(m+1,j);

	if(Input[m]>=Input[left] && Input[m]>=Input[right])
		return m;
	else if(Input[m]>Input[right])
		return FindRotationIndex(i,m-1);
	else if(Input[m]>Input[left])
		return FindRotationIndex(m+1,j);
	return -1;
}

int main()
{
	int n;
	cin>>n;
	while(n!=-1)
	{
		Input.push_back(n);
		cin>>n;
	}
	cout<<"Peak is at index[0,n-1]:\t"<<FindRotationIndex(0,Input.size()-1)<<endl;
	return 0;
}