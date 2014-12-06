void main()
{
	int T[30][30];
	int i,j,m;
	for(i=0;i<30;i++)
	{
		for(j=0;j<30;j++)
		{
			T[i][j]=0;
		}
	}
	
	int x,y;
	x=0;
	y=0;
	T[0][1]=0;
	int x2, y2;
	
	


	x=6;
	y=15;
	T[x][y]=2;

	
	Couleur* Full=NULL;
	Full=Mouv(T,6,15);
	
	
	printf("\n LA SOL pour 6 15 \n");
	afficherCo(Full);	
}
