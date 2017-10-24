#include <string>
#include <vector>

void read_file(const std::string& filename, std::vector<char>& contents);
void read_file(const std::string& filename, std::string& contents);

// Convenience wrappers
std::vector<char> read_file_as_char_vector(const std::string& filename);
std::string read_file_as_string(const std::string& filename);
