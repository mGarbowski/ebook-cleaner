#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <sstream>

std::string cleanNewlines(const std::string& text) {
    const std::regex pattern(R"(([a-ząęśćźłóż,])(\r?\n))");
    std::string result = std::regex_replace(text, pattern, "$1 ");
    return result;
}

std::string outputFilename(const std::string& filename) {
    size_t dotPosition = filename.find_last_of('.');
    if (dotPosition == std::string::npos) {
        return filename + "_clean";
    }

    std::string baseName = filename.substr(0, dotPosition);  // part before the '.'
    std::string extension = filename.substr(dotPosition);     // part after the '.'
    return baseName + "_clean" + extension;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::regex filenamePattern(".txt");
    std::string outFilename = outputFilename(filename);
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string fileContent = buffer.str();

    file.close();

    std::ofstream outFile(outFilename);
    outFile << cleanNewlines(fileContent);
    outFile.close();

    return 0;
}
