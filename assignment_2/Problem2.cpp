#include <bits/stdc++.h>
using namespace std;

long numWays(int width, int height, vector<string> &bad){
	long Grid[width+1][height+1][3];// 3 dimension for a)if (i,j) can be reached from (i,j-1) b)if (i,j) can be reached from (i-1,j) c)total no of ways to reach (i,j)
	memset(Grid,0,sizeof(Grid));
	for(int i=0;i<bad.size();i++){
		stringstream ss(bad[i]);
		int n;int j=0;int coord[4];// a, b, c and d
		while(ss>>n){
			coord[j]=n;
			j++;
		}

		if(coord[0]==coord[2])Grid[coord[0]][max(coord[1],coord[3])][1]=-1;//Grid[i][j][0]=-1 if "i,j-1,i,j" present in string[] bad
		else{
			Grid[max(coord[2],coord[0])][coord[3]][0]=-1;//Grid[i][j][1]=-1 if "i-1,j,i,j" present in string[] bad
		}
	}
	Grid[0][0][2]=1;//---
	for(int i=1;i<=width;i++)if(Grid[0][i][0]!=-1)Grid[0][i][2]=1;
	for(int i=1;i<=height;i++)if(Grid[i][0][1]!=-1)Grid[i][0][2]=1;

	for(int i=1;i<=height;i++){
		for(int j=1;j<=width;j++){
			if(Grid[i][j][0]!=-1){Grid[i][j][2]+=Grid[i][j-1][2];}
			if(Grid[i][j][1]!=-1){Grid[i][j][2]+=Grid[i-1][j][2];}
		}
	}
	return Grid[height][width][2];
}

