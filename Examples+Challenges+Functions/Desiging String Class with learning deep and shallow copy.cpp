#include<iostream>
#include<string.h>
class String
{
    char* M_buffer;
    unsigned int M_size;

public:

    String(const char* string){
        M_size = strlen(string);
        M_buffer = new char[M_size + 1];
        memcpy(M_buffer,string,M_size);
        M_buffer[M_size] = 0;
    }

    ~String(){
    delete[] M_buffer;
    }

    char& operator[](unsigned int index){
        return M_buffer[index];
    }

//Writing the copy constructor for Deep Copying
String(const String& string)
    :M_size(string.M_size)
{

    //std::cout << " Copied String " << std::endl;
    M_buffer = new char[M_size + 1];
    memcpy(M_buffer,string.M_buffer,M_size+1);
}

/*
//This are the two ways how compiler copies the object #shallow copy
    String(const String& string)
        :M_buffer(string.M_buffer),M_size(string.M_size){}
//OR
    String(const String& string){
    memcpy(this,&string,sizeof(String));
    }
*/

/*
//If we don't want compiler to write the copy constructor
//we can do that deleting the copy constructor as shown below
    String(const String& string) = delete;
*/
    friend std::ostream& operator<<(std::ostream& stream,const String& s);
};
std::ostream& operator<<(std::ostream& stream, const String& s){
stream<<s.M_buffer;
return stream;
}
//here we are using Shallow Copy because we don't want the String to get
//copied every time we pass it because it is the function which only
//prints the string without modifying it.
//you can remove the reference(&) to see the no of copies and uncomment cout
//statements in copy constructor of string.
void PrintString(const String& string)
{
    std::cout << string << std::endl;
}
main()
{
    String first = "Tanay";
    String second = first;

    second[2]='m';
    PrintString(first);
    PrintString(second);

    //std::cout << first << std::endl;
    //std::cout << second << std::endl;
}
