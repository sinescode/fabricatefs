#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <cstdlib>

namespace fs = std::filesystem;

// Version information
const std::string VERSION = "1.0.0";

// Helper functions
void printHelp() {
    std::cout << "fabrifs - Fast and Brilliant File System creator utility v" << VERSION << std::endl;
    std::cout << "Usage: fabrifs [options] path" << std::endl;
    std::cout << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -h, --help     Show this help message and exit" << std::endl;
    std::cout << "  -v, --version  Show version information and exit" << std::endl;
    std::cout << std::endl;
    std::cout << "Examples:" << std::endl;
    std::cout << "  fabrifs new            Create a file named 'new'" << std::endl;
    std::cout << "  fabrifs new/           Create a directory named 'new'" << std::endl;
    std::cout << "  fabrifs new/file       Create a file named 'file' in directory 'new'" << std::endl;
    std::cout << "  fabrifs new/dir/       Create nested directories 'new/dir'" << std::endl;
    std::cout << "  fabrifs a/b/c/d.txt    Create nested directories and a file" << std::endl;
}

void printVersion() {
    std::cout << "fabrifs version " << VERSION << std::endl;
}

// Create a file
bool createFile(const fs::path& path) {
    try {
        // Create parent directories if they don't exist
        if (path.has_parent_path() && !fs::exists(path.parent_path())) {
            fs::create_directories(path.parent_path());
            std::cout << "Created directory: " << path.parent_path() << std::endl;
        }

        // Create the file
        std::ofstream file(path);
        if (!file) {
            std::cerr << "Error: Failed to create file: " << path << std::endl;
            return false;
        }
        file.close();
        
        std::cout << "Created file: " << path << std::endl;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
}

// Create a directory
bool createDirectory(const fs::path& path) {
    try {
        if (fs::exists(path)) {
            std::cout << "Directory already exists: " << path << std::endl;
            return true;
        }
        
        fs::create_directories(path);
        std::cout << "Created directory: " << path << std::endl;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
}

// Process the path and determine whether to create a file or directory
bool processPath(const std::string& pathStr) {
    fs::path path(pathStr);
    
    // Check if the path ends with '/' - indication for directory
    if (pathStr.empty()) {
        std::cerr << "Error: Empty path" << std::endl;
        return false;
    }
    
    if (pathStr.back() == '/') {
        return createDirectory(path);
    } else {
        return createFile(path);
    }
}

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv + 1, argv + argc);
    
    // If no arguments provided, show help
    if (args.empty()) {
        printHelp();
        return 0;
    }
    
    // Process options
    for (const auto& arg : args) {
        if (arg == "-h" || arg == "--help") {
            printHelp();
            return 0;
        } else if (arg == "-v" || arg == "--version") {
            printVersion();
            return 0;
        }
    }
    
    // Process the last argument as the path
    return processPath(args.back()) ? 0 : 1;
}