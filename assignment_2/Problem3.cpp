#include <bits/stdc++.h>
using namespace std;
int luckyDraw(int arr[],int n){
	int best=1;int LIS[n]; int longest=1;
	for(int i=0;i<n;i++)LIS[i]=1;
	for(int i=0;i<n;i++){
		for(int j=i;j<i+n;j++){
			for(int k=i;k<j;k++){
				if(arr[k%n]<arr[j%n] && LIS[j%n]<LIS[k%n]+1)
					LIS[j%n]=LIS[k%n]+1;

			}
			longest=max(longest,LIS[j%n]);
		}
		best=max(best,longest);
		for(int i=0;i<n;i++)LIS[i]=1;
	}return best;

}

int main(){
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int * arr=new int[n];
		for(int j=0;j<n;j++){
			cin>>arr[j];
		}
		cout<<luckyDraw(arr,n)<<endl;
	}
	return 0;
}