#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    // Display our little program header ONLY when no parameters were given to keep the output clean.
    // First off we check if the user has properly called the program with the arguments it requires:
    if (argc < 2) {
        // If no argument is passed, display a usage example to the user:
        std::cerr << "File-splitter v0.2 by svdk" << endl << "Usage: " << argv[0] << " <FILENAME.EXT>" << std::endl;
        // Exit if the condition has been met
        return 1;
    }
// The is the main part of the program, taking argv[1] as filename to work with:
std::fstream file(argv[1]);
std::string line;
// Perform for every line:
while(std::getline(file, line))
{
    std::stringstream   linestream(line);
    std::string         data;
    int                 val1;
    int                 val2;
    /* If the input file has tab delimited data, use getline() by changing the third parameter.
       If the input file is "white space" separated data then the operator ">>" can be used (reads a " " separated word into a string).
       */
    std::getline(linestream, data, '\t');  // read up-to the first tab (discard tab).
    // Print the data that has been split
    cout << data <<endl;
    // Read the integers using the operator >>
    linestream >> val1 >> val2;
}
}
