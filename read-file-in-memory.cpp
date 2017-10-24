#include "read-file-in-memory.h"
#include <fstream>

template <typename T>
void read_file_in_memory(const std::string& filename, T& contents)
{
    // Adapted from: https://stackoverflow.com/a/18816228/19254

    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (!file) {
        throw std::runtime_error("Unable to open file '" + filename + "' for reading");
    }

    const std::streamsize size = file.tellg();

    file.seekg(0, std::ios::beg);

    contents.resize(size);

    if (size > 0) {
        if (!file.read(&contents[0], size)) {
            throw std::runtime_error("Unable to read file '" + filename + "'");
        }
    }
}

void read_file(const std::string& filename, std::vector<char>& contents)
{
    read_file_in_memory(filename, contents);
}

void read_file(const std::string& filename, std::string& contents)
{
    read_file_in_memory(filename, contents);
}

std::vector<char> read_file_as_char_vector(const std::string& filename)
{
    std::vector<char> contents;
    read_file(filename, contents);
    return contents;
}

std::string read_file_as_string(const std::string& filename)
{
    std::string contents;
    read_file(filename, contents);
    return contents;
}
