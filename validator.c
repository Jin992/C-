#include <stdio.h> /*stdio.h - Standart input/output header*/
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define AC_RED     "\x1b[31m"
#define AC_GREEN   "\x1b[32m"
#define AC_YELLOW  "\x1b[33m"
#define AC_BLUE    "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN    "\x1b[36m"
#define AC_RESET   "\x1b[0m"

#define APP_VERSION "0.1.0"

/*Functions prototypes*/
void versionCommand(void);
void helpCommand(void);

const char * const allowedFlags[] = {"--version","--help"};
void (*commandsStore[])(void) = {versionCommand, helpCommand};
const int const allowedFlagsLength = sizeof allowedFlags / sizeof allowedFlags[0];



void validateFlags(const char * const flags[], const int const length, const char * const allowedFlagsValues[], const int const allowedFlagsArrayLength)
{
	int incorrectFlagIndex = -1;

	for(int i = 1; i < length; i++)
	{
		for(int j = 0; j < allowedFlagsArrayLength; j++)
		{
			if(strcmp(flags[i], allowedFlagsValues[j]) == 0)
			{
				incorrectFlagIndex = -1;
				break;
			}
			else 
				incorrectFlagIndex = i;
		}
		if(incorrectFlagIndex > -1)
		{
			printf(AC_RED "[-] Error: %s %s Incorrect flag was given!", AC_RESET, flags[incorrectFlagIndex]);
			exit(EXIT_FAILURE);
		}
	}
	return;
}


void invokeCommands(const char * const commands[], const unsigned int count, const char * const allowedFlagsValues[], const int const allowedFlagsArrayLength)
{
	for(int i = 1; i < count; i++){
		for(int j = 0; j < allowedFlagsArrayLength; j++)
		{
			if(strcmp(commands[i], allowedFlagsValues[j]) == 0)
			{
				commandsStore[j]();
			}
		}
	}
}

void versionCommand(void)
{
	printf("App version %s", APP_VERSION);
}

void helpCommand(void)
{
	printf("Help commaind invoked.");
}


int main (const int const argc, const char * const argv[])
{
	if(argc > 1) validateFlags(argv,argc,allowedFlags,allowedFlagsLength);
	else printf(AC_GREEN "Congratulations!\r\n" AC_RESET);

	invokeCommands(argv,argc,allowedFlags,allowedFlagsLength);
	
	return EXIT_SUCCESS;
}