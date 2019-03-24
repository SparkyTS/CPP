#include<iostream>

struct Vector3
{
     int z,x,y;

    //returning the address of first element for type punning
     int* getPosition(){
     return &z;
     }
};

void PrintVector3(const Vector3& vector) const {
    std::cout << "Value of X is " << vector.x << std::endl;
    std::cout << "Value of Y is " << vector.y << std::endl;
    std::cout << "Value of Z is " << vector.z << std::endl;
    }

main()
{
    Vector3 vector = {1,2,3};

    std::cout << "Vector3 After Initialization : \n";
    PrintVector3(vector);

    int offsetx = (int)&((Vector3*)nullptr)->x;
    int offsety = (int)&((Vector3*)nullptr)->y;
    int offsetz = (int)&((Vector3*)nullptr)->z;
    std::cout << "\n\nOffset Values of Variables : \n\n";
    std::cout << "Off Set of x : " << offsetx << std::endl;
    std::cout << "Off Set of y : " << offsety << std::endl;
    std::cout << "Off set of z : " << offsetz << std::endl;


    //Treating Structure as Array and Changing values by using offsets(Also Called "Type Punning")
     int* position  =  vector.getPosition();
    //we can divide offset by three for getting the index of each variable
     position[offsetx/4] = 5;
     position[offsety/4] = 6;
     position[offsetz/4] = 7;
     std::cout << "\nAfter Changing data of structure by Using type Punning and Offsets\n\n";
     PrintVector3(vector);
}
