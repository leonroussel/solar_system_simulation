//
// Created by leonroussel on 2/14/22.
//

#include <iostream>

#include "vector3D.cpp"

/*
 * Easy tests for class 'vector3D'
 */
int main(){
    vector3D vec = vector3D(1, 1, 1);
    std::cout << "Initial vector : " << vec << "\n";
    std::cout << "Opposite result : " << - vec << "\n";
    std::cout << "Norm : " << vec.norm() << "\n";

    vector3D add = vector3D(2, 3, 5.6788);
    std::cout << "Vector to add : " << add << "\n";

    vector3D sum = vec + add;
    std::cout << "Addition result : " << sum << "\n";

    double a = 2;
    std::cout << "Multiplication by scalar result : " << sum * a << "\n";

    std::cout << "Sub result : " << sum - vec << "\n";
}



