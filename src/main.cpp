#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <storage/impl/BinaryTree.h>

int main() {
    std::string line;
    BinaryTree tree;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);
        if (line == "exit") break;

        std::istringstream iss(line);
        std::vector<std::string> args;
        std::string word;
        while (iss >> word) args.push_back(word);

        if (args.empty()) continue;
        const std::string& cmd = args[0];

        if (cmd == "s" && args.size() == 3) {
            std::cout << "Set: " << args[1] << " => " << args[2] << "\n";
            std::cout << tree.set(args[1], args[2]) << std::endl;
        } else if (cmd == "d" && args.size() == 2) {
            std::cout << "Delete: " << args[1] << "\n";
            std::cout << tree.del(args[1]) << std::endl;
        } else if (cmd == "g" && args.size() == 2) {
            std::cout << "Get: " << args[1] << "\n";
            std::optional<std::string> v = tree.get(args[1]);
            std::string val = v.has_value() ? v.value() : "Not found";
            std::cout << val << std::endl;
        } else {
            std::cout << "Unknown command\n";
        }
    }
}
