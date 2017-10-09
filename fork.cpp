#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int testValue = 8;

	std::cout << "The original value is: " << testValue << std::endl;

	if (fork())
	{
		wait(NULL);
		testValue = 6;
	}
	else
	{
		testValue = 10;
	}

	std::cout << "The current value is: " << testValue << std::endl;
	testValue *= 2;
	std::cout << "The current value is: " << testValue << std::endl;


	return 0;
}
