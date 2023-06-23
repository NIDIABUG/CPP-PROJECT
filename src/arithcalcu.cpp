#include <iostream>
#include <string>
#include <vector>


bool isValidExpression(const std::string& expression) {
    // iterate throughout the input and checks if it is either a number or arithmetic operator
    for (char c : expression) {
        if (!isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/' && c != ' ')
            return false;
    }
    // return true if its a valid input expression
    return true;
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    if(input.empty() || !isValidExpression(input)) {
        std::cout << "Error: Invalid expression" << std::endl;
        return 1;
    }

    std::vector<std::string> groups;
    std::string currentGroup;

    for (int i = 0; i < input.length(); i++) {
        if (isdigit(input[i])) {
            currentGroup += input[i];
        } else if (!currentGroup.empty()) {
            groups.push_back(currentGroup);
            currentGroup.clear();
        }

        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            groups.push_back(std::string(1, input[i]));
        }
    }

    if (!currentGroup.empty()) {
        groups.push_back(currentGroup);
    }

    std::cout << "Groups: ";
    for (const std::string& group : groups) {
        std::cout << group;
    }
    std::cout << std::endl;

    return 0;
}
