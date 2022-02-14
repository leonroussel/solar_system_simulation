//
// Created by leonroussel on 2/10/22.
//

#include <iostream>
#include "vector3D.cpp"

/*
 * Represent a particle, here a planet !
 */
class Particle{
    vector3D position;
    vector3D speed;
    vector3D force;
    double mass;
    int id;

public :
    Particle(double *pos, double *spe, double mass, int id){
        this -> position = vector3D(pos[0], pos[1], pos[2]);
        this -> speed = vector3D(spe[0], spe[1], spe[2]);
        this -> force = vector3D(0, 0, 0);
        this -> mass = mass;
        this -> id = id;
    }

    Particle(){
        this -> position = vector3D(0, 0, 0);
        this -> speed = vector3D(0, 0, 0);
        this -> force = vector3D(0, 0, 0);
        this -> mass = 0;
        this -> id = 0;
    }

    vector3D getPosition(){
        return this -> position;
    }

    void setPosition(vector3D vec){
        this -> position = vec;
    }

    vector3D getForce(){
        return this -> force;
    }

    vector3D getSpeed(){
        return this -> speed;
    }

    void setSpeed(vector3D vec){
        this -> speed = vec;
    }

    double getMass(){
        return this -> mass;
    }

    double distance(Particle otherParticle){
        return (this -> getPosition() - otherParticle.getPosition()).norm();
    }

    friend std::ostream& operator<<(std::ostream &s, Particle particle);
};

std::ostream& operator<<(std::ostream &o, Particle particle) {
    return o << "[" << "(" << particle.position.getX() << ", " << particle.position.getY() <<  ", " << particle.position.getZ() << "), " << "(" << particle.speed.getX() << ", " << particle.speed.getY() <<  ", " << particle.speed.getZ() << "), " << particle.id << "]\n";
}