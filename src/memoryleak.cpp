#include <iostream>

int main() {
    while(true) {
        std::string* memoryLeak101 = new std::string("");
    }
}