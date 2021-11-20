/* Finite state machine, in this case, a turnslide*/

#include <stdio.h>
#include <string.h>

enum state{closed, open}; //states of the machine

/* display the state of the machine*/
void disp_machine(int State)
{
	printf("The machine is: ");
	if(State)
		printf("open\n");
	else
		printf("closed\n");
}

/* Get options from the user and return the # of
 * option that the input matches, return 0 if not*/
#define OPTIONS 12
int get_options()
{
	char opts[OPTIONS][10] ={
		"Push", "push", "p", "P",
		"Coin", "coin", "c", "C",
		"Exit", "exit", "e", "E"};
	char input[10];
	fgets(input, 9, stdin);
	sscanf(input, " %s", input); //get rid of whitespaces
	for(int i; i<OPTIONS; i++){
		if(!strcmp(input, opts[i]))
			return (i++);
		}
	
	return (0);
}
int main()
{
	int mach = closed;
	for(;;) 
	{
		disp_machine(mach);
		printf("Push, Coin, Exit: \n");
		printf(":> ");

		int opt;
		opt = get_options();
		switch(opt)
		{
			//This jank is to make the program
			//more user-frindly
			case 1:
			case 2:
			case 3:
			case 4:
				mach = closed;
				break;
	
			case 5:
			case 6:
			case 7:
			case 8:
				mach = open;
				puts("Now you can pass :)");
				break;
	
			case 9:
			case 10:
			case 11:
			case 12:
				return (0);
				
			default:
				puts("I don't recognize that option.");
				break;
		}
	}
}

