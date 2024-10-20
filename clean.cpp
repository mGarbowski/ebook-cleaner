#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <sstream>

std::string cleanNewlines(const std::string &text) {
    const std::regex pattern(R"(([a-ząęśćźłóż,])(\r?\n))");
    std::string result = std::regex_replace(text, pattern, "$1 ");
    return result;
}

std::string outputFilename(const std::string &filename) {
    const size_t dotPosition = filename.find_last_of('.');
    if (dotPosition == std::string::npos) {
        return filename + "_clean";
    }

    const std::string baseName = filename.substr(0, dotPosition);
    const std::string extension = filename.substr(dotPosition);
    return baseName + "_clean" + extension;
}

std::string readFileToString(const std::ifstream &file) {
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string inputFilename = argv[1];
    std::ifstream inputFile(inputFilename);

    if (!inputFile) {
        std::cerr << "Error: Could not open file " << inputFilename << std::endl;
        return 1;
    }

    auto fileContent = readFileToString(inputFile);

    std::string outFilename = outputFilename(inputFilename);
    std::ofstream outFile(outFilename);
    outFile << cleanNewlines(fileContent);

    return 0;
}
