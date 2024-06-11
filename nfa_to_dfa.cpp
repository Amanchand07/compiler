#include<stdio.h>
#include<string.h>
int main(){
	int nfa[4][2]={{0}};
	nfa[1][0]=2;
	nfa[1][1]=13;
	nfa[2][0]=2;
	nfa[2][2]=1;
	nfa[3][0]=2;
	nfa[3][1]=3;
	 
	int dfa[10][2]={{0}};
	int dstate[10]={0};
	int n=1,m,q,r,flag=0,k,j;
	dstate[1]=1;
	for(k=1;dstate[k]!=0;k++)
	{
		m=dstate[k];
		if(m>10){
			q=m/10;
			r=m%10;
		}
		else{
			q=0;
			r=m;
		}
		for(j=0;j<2;j++){
			dfa[k][j]=nfa[r][j];
			flag=0;
			for(int i=1;i<=n;i++)
			{
				if(dfa[k][j]==dstate[i]){
					falg=1;
					break;
				}
			}
			if(!flag && dfa[k][j]!=0)
			{
				int ns=dfa[k][j];
				int dup=0;
				for(int l=1;l<=n;l++)
				{
					if(dstate[l]==ns)
					{
						dup=1;
						break;
					}
				}
				if(!dup)
				{
					dstate[++n]=ns;
				}
			}
		}
	}

	 printf("state  |  a    |   b    \n");
	 for(int i=0;i<k;i++)
	 {
	 	if(dstate[i]==13) printf("%d   |  %d   |  %d  \n",13,dfa[i][0],dfa[i][1]);
	 	else{
	 		printf("%d   |  %d   |  %d  \n",dstate[i],dfa[i][0],dfa[i][1]);
		 }
	 }

return 0;
}

