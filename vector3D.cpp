//
// Created by leonroussel on 2/14/22.
//

#include <iostream>
#include <cmath>

#ifndef DEMO_VECTOR3D_H
#define DEMO_VECTOR3D_H

/*
 * 3-dimensional vector implementation with some operators (+, -, *, ...)
 */
class vector3D {
private :
    double coord [3];
public :
    vector3D(double x, double y, double z){
        this->coord[0] = x;
        this->coord[1] = y;
        this->coord[2] = z;
    }

    vector3D(){
        vector3D(0., 0., 0.);
    }

    double getX(){
        return this->coord[0];
    }

    double getY(){
        return this->coord[1];
    }

    double getZ(){
        return this->coord[2];
    }

    double norm(){
        return sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2));
    }

    vector3D operator+(vector3D u){
        return vector3D(this->getX() + u.getX(), this->getY() + u .getY(), this->getZ() + u.getZ());
    }

    vector3D operator-(vector3D u){
        return vector3D(this->getX() - u.getX(), this->getY() - u .getY(), this->getZ() - u.getZ());
    }

    vector3D operator-(){
        return vector3D(- this->getX(), - this->getY(), - this->getZ());
    }

    vector3D operator*(double lambda){
        return vector3D(this->getX() * lambda, this->getY() * lambda, this->getZ() * lambda);
    }

    friend std::ostream& operator<<(std::ostream &s, const vector3D vec);
};

/* To print the vectors : */
std::ostream& operator<<(std::ostream &o, const vector3D vec) {
    return o << vec.coord[0] << " " << vec.coord[1] <<  " " << vec.coord[2];
}

#endif //DEMO_VECTOR3D_H