#include <iostream>
#include <list>
#include <string>

// What do you see when printing the variable text?
//
// b main
// r
// n
// n
// p text
// p/r text

int main()
{
    std::list<std::string> text = { { "this", "is", "just", "an", "example" } };

    for (auto&& word : text) {
	std::cout << word << '\n';
    }
}
