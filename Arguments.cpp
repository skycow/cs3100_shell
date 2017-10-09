#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    std::cout << "There are " << argc << " parameters." << std::endl;

    for (int param = 0; param < argc; param++)
    {
        std::cout << "Param " << (param + 1) << ": " << argv[param] << std::endl;
    }

    for (int param = 0; param < argc; param++)
    {
        std::string value = argv[param];

        if (value == "one")
        {
            std::cout << "one is a parameter" << std::endl;
        }
        if (value == "two")
        {
            std::cout << "two is a parameter" << std::endl;
        }
    }

    return 0;
}
