#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

unsigned long long cephalopod_decoding(std::vector<int>& v, const std::string& op) {
    int size = v.size();
    int largest_size = 4;

    unsigned long long total = 0;

    for (int i=0; i < largest_size; i++) {

        unsigned long long col_total = 0;
        for (int &num : v) {
            if (num == 0) continue;
            int rem = num % 10;
            num /= 10;
            if (rem == 0)continue;

            col_total = (col_total * 10) + rem;
            
        }

    
       std::cout << col_total << std::endl;
        if (op == "+") {
            total += col_total;
        }
        else if (op == "*" && col_total != 0)
        {
            if (total == 0) {
                total = col_total;
              
            }else {
                total = total * col_total;
            }
            
        }
        
    
    }

    std::cout << total << std::endl;
    return total;
}


int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open input.txt\n";
        return 1;
    }

    std::vector<std::vector<std::string>> grid;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> tokens;
        std::string token;

        while (iss >> token)
            tokens.push_back(token);

        grid.push_back(std::move(tokens));
    }

    int height = grid.size();
    int width = grid[0].size();

    unsigned long long total = 0;

    for (int x = 0; x < width; x++) {
        const std::string& op = grid[height - 1][x];

        std::vector<int> v;
        v.reserve(height - 1);

        for (int y = 0; y < height - 1; y++)
            v.push_back(std::stoi(grid[y][x]));

        total += cephalopod_decoding(v, op);
    }

    std::cout << total << "\n";
    return 0;
}
