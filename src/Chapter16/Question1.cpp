#include <iostream>
#include <vector>
#include <string>
#include <string_view>


bool search_function(const std::vector<std::string>& names, std::string_view name){
    for(std::string_view nameinarray: names){
        if(nameinarray == name){return true;}
    }
    return false;
}

int main(){
    std::vector<std::string> names{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::string name{};
    while (true) {
        std::cout << "Enter a name: " << "\n";
        std::cin >> name;
        if(search_function(names, name)){std::cout << name << " was found." << "\n";}
        else{std::cout << name << " was not found." << "\n";}
    }
    return 0;
}
