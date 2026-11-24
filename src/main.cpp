#include <iostream>
#include <ostream>
#include <string>
#include <string_view>

class MyString{
    private:
        std::string m_str{};
    public:
        MyString(std::string_view str = {}):m_str{str}{}

        friend std::ostream& operator<<(std::ostream& out,const MyString& str){
            out << str.m_str;
            return out;
        }

        MyString& operator()(int start,int length){
            std::string_view sv{m_str};
            MyString out_str{sv.substr(start,length)};
            return out_str;
        }
};



int main(){
    MyString s { "Hello, world!" };
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters
    std::cout << "HI";
    return 0;
}
