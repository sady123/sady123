#include<stdio.h>

int state=0;  /* State 0 corresponds when either there is no input or any input other than state h */
int parseForHello(char c)
{
 switch(state)					
	 {
	 case 0: if(c=='h')    		
	 			state=1;				/*State 1 when input goes to h */
	 			else state=0;
	 			break;
	 				 
    case 1: 
	 			if(c=='e')			
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
	return(1);					/*End of sequence detect returns a 1 making loop break */ 
	else return(0);
}  	 
	

int main()
{
	int helloFound;        
	while(1)
	{	char c = getchar();  /*Infinte loop Obtains serial input (no spaces/enter requried) from user*/ 
		helloFound= parseForHello(c);
		if(helloFound)
		{
			printf("\nhellofound"); /*loop breaks when string is detected and helloFound=1 */
			break;
		}
	}
}		