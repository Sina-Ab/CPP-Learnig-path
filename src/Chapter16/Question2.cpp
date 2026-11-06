#include <iostream>
#include <vector>
#include <string>

template <typename T>
bool isValueInArray(const std::vector<T>& array, const T& value){
    for(const auto& valueinarray: array){
        if(valueinarray == value){return true;}
    }
    return false;
}

int main(){
    std::vector<std::string> names{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::vector<int> numbers{1,6,4,8,12};
    std::string name{};
    int number{};
    while (true) {
        std::cout << "Enter a name and number: " << "\n";
        std::cin >> name >> number;
        if(isValueInArray<std::string>(names, name)){std::cout << name << " was found." << "\n";}
        else{std::cout << name << " was not found." << "\n";}
        if(isValueInArray<int>(numbers, number)){std::cout << number << " was found." << "\n";}
        else{std::cout << number << " was not found." << "\n";}
    }
    return 0;
}
