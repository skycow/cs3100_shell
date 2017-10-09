#include <iostream>
#include <unistd.h>
#include <cstring>

int main()
{
	char** argv = new char*[3];

	argv[0] = new char[3];
	strcpy(argv[0], "ls");
	argv[1] = new char[4];
	strcpy(argv[1], "-la");
	argv[2] = NULL;

	execvp(argv[0], argv);

	std::cout << "If this shows up, I have some 'splaining to do" << std::endl;


	return 0;
}

