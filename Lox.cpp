#include <iostream>
#include <fstream>
#include <string>

int runFile(const std::string path);
void run(const std::string fileContent);
void runPrompt();

int main(int argc, char** argv)
{
    if (argc > 1) {
        std::cout << "Usage: loxcpp [script] ";
    }
    else if (argc == 1) 
    {
        return runFile(argv[0]);
    }
    else 
    {
        runPrompt();
    }

    return 0;
}

int runFile(const std::string path) {
    std::ifstream inputFile;
    inputFile.open(path);
    if (!inputFile.is_open()) 
    {
        std::cerr << "Error opening the file." << std::endl;
        return -1;
    }

    std::string inputFileContent;
    std::string line;
    while (std::getline(inputFile, line))
    {
        inputFileContent += line;
    }

    inputFile.close();

    run(inputFileContent);

    return 0;
}

void run(const std::string fileContent) {
    
}

void runPrompt() {
    std::string line;
    while (true) {
        std::cout << ">";
        std::getline(std::cin, line);
        if (line == "exit") {
            break;
        }

        run(line);
    }
}