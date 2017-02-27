int longestZigZag(int[] sequence){
	int n=sizeof(sequence)/sizeof(sequence[0]);
	int ZZag[n][2];
	int longest=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<1;j++)
			ZZag[i][j]=1;

	for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (sequence[j] < sequence[i] && ZZag[i][0] < ZZag[j][1] + 1)
                ZZag[i][0] = ZZag[j][1] + 1;
 
            if( sequence[j] > sequence[i] && ZZag[i][1] < ZZag[j][0] + 1)
                ZZag[i][1] = ZZag[j][0] + 1;
        }
 
        if (longest < max(ZZag[i][0], ZZag[i][1]))
            longest = max(ZZag[i][0], ZZag[i][1]);
    }
 
    return longest;
}