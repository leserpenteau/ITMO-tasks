#include <stdio.h>

int main(void)
{
  int i, j, w, h;
  FILE *fin, *fout;
  fin = fopen("turtle.in", "r");
  fout = fopen("turtle.out", "w");
  fscanf(fin, "%d%d\n", &h, &w);
  
  long long int a[h][w];
  
  for (i=0; i<h; i++)
  {
  	for (j=0; j<w; j++)
  		fscanf(fin, "%lld", &a[i][j]);
  	fscanf(fin,"\n");
  	printf("i=%d h=%d w=%d\n",i, h, w);
  }
	
	
	for (i=h-2; i>=0; i--)   //filling first ranges
  		a[i][0]+=a[i+1][0];
	for (j=1; j<=w; j++)
  		a[h-1][j]+=a[h-1][j-1];
  	
  for (j=1; j<=w; ++j)    //filling last elements
  {
  	for (i=h-2; i>=0; --i)
  	{
  		if (a[i+1][j]>a[i][j-1])
  			a[i][j]+=a[i+1][j];
  		else
  			a[i][j]+=a[i][j-1];
  	}
  }
	fprintf(fout, "%lld", a[0][w-1]);
	fclose(fin);
	fclose(fout);
	return 0;
}
