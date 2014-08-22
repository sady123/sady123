#include<stdio.h>
		
int state=0;  /* State 0 corresponds to the intial state when there is no input */
int parseForHello(char c)
{
 switch(state)					
	 {
	 case 0: if(c=='h')    		
	 			state=1;				/*State 1 when input goes to h */
	 			else state=0;
	 			break;
	 				 
    case 1: if(c=='h')
    			state=1;
	 			else if(c=='e')			
	 			state=2;				/*State 2 when input goes to e */
	 			else state=0;
	 			break;
	 		

	 case 2: 
	 		  if(c=='l')
	 			state=3;				/*State 3 when input goes to l */
	 			else state=0;
				break;
	 
	 case 3:
	 			if(c=='l')
	 			state=4;			  /*State 4 when input goes to l */
	 			else state=0;
	 			break;
 
 	 case 4:	 
 	 			if(c=='o')
 	 			state=5;
 	 			else state=0;		/*State 5 whhen input goes to o and sequence is completed */
 				break;
 
 }
	if(state==5)
	{state=0;
	return(1);
	}					/*End of sequence detect returns a 1 making loop break */ 
	else return(0);
}  	 
	
/* unit test for function helloFound(c) */

void test()
{
	int i,check,j;
	char a[4][100]={"abcdhello","helloabc","abchelloxyz","abcxyz"}; /*All possible string input combinations given to the function have been stored in 2D array*/
	for(i=0;i<4;i++)
	{
		puts(a[i]);
		for(j=0;a[i][j]!='\0';j++)
		{
			check= parseForHello(a[i][j]);	
			if(check==1)
			{
				printf("case %d hello found, test passed\n\n",i+1);
				break;
			}	
		}
	if(check==0) printf("\ncase %d hello not found, test passed \n",i+1);
	else printf("\ntest failed\n");
	}	

}
int main()
{
	test();	/*unit test called */
  int helloFound;
  printf("\nenter the serial data stream :\n");        
	while(1)
	{	char c = getchar();  /*Infinte loop Obtains serial input (no spaces/enter requried) from user*/ 
		helloFound= parseForHello(c);
		if(helloFound)
		{
			printf("\nhellofound"); /*loop breaks when string is detected and helloFound=1 else it keeps waiting for hellostring */
			break;
		}
	}
	return(0);
}
