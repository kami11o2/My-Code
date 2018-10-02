void TaoBanCo (char bc[][100],int N)
{
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			bc[i][j] = '-';
}

void InBanCo (char bc[][100],int N)
{
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
			cout<<bc[i][j]<<" ";
		cout<<endl;
	}
}

bool XepDuocHau (char bc[][100], int N, int x, int y)
{
	for (int i=1;i<y;i++)
		if (bc[x-1][i-1]=='H')
			return 0;
	for (int i=x+1, j=y-1;i<=N,j>=1;i++,j--)
		if (bc[i-1][j-1]=='H')
			return 0;
	for (int i=x-1, j=y-1;i>=1,j>=1;i--,j--)
		if (bc[i-1][j-1]=='H')
			return 0;
	return 1;
}

void XepHau(int c,char bc[][100],int N)
{
	if (c>N)
	{
		cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
		InBanCo(bc,N);
	}
	else
	{
		for (int j=1;j<=N;j++)
		{
			if (XepDuocHau(bc,N,j,c))
			{
				bc[j-1][c-1] = 'H';
				XepHau(c+1,bc,N);
				bc[j-1][c-1] = '-';
			}
		}
	}
}
