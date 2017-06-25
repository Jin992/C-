#include <stdio.h> /*stdio.h - Standart input/output header*/

char* phrase = "Hello my dear friend !";


/* Funtion to find string lenght. Return the string length (int) */
int findLenght(char *string)
{
	int count = 0;

	while(1)
	{
		if(phrase[count] == '\0')
			break;
		count++;
	}

	return count;
}
/*------------->End<-------------*/

/* Function to count spaces in string. Return (int) quantity of spaces*/
int countSpaces(char *string)
{
	int spaces = 0;

	for(int j = 0; j < findLenght(string); j++)
	{
		if(string[j] == ' ')
			spaces++;
	}

	return spaces;
}
/*------------->End<-------------*/

/* Function that divides a string into words. Return (char) array of words*/
char splitString(char* string, int stringLenght)
{
	int counter = 0;
	int cycleStop = 0;
	int wordLength[countSpaces(string)];
	
	
	for(int i = 0; i < countSpaces(string); i++)
	{
		for(int j = 0; j < stringLenght; j++)
		{
			if(string[j] != ' ')
			{
				printf("%c",string[j]);
			}
			else
			{
				printf("\r\n");
			}
			
			if(string[j] == '\0')
				cycleStop = 1;
		}
		


		printf("\r\n");
		if(cycleStop == 1)
			break;
	}


	printf("String: %s\n\r", string);
	printf("String length: %i", stringLenght);


	printf("\r\n");
	
		
	return 0;
}
/*-------------------------->End<--------------------------*/


/* Main funtction*/
int main ()
{
	splitString(phrase, findLenght(phrase));
	return 0;
}








