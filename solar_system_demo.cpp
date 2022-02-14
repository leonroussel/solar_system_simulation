//
// Created by leonroussel on 2/10/22.
//

#include <iostream>
#include <deque>
#include <random>
#include <fstream>

#include "particle.cpp"
#include "vector3D.cpp"

/*
 * Update the forces with interaction forces of all particles
 */
void calculate_forces(vector3D *forces[], Particle particleList[], int n_particles){
    for(int i = 0; i < n_particles; i++){
        vector3D F_i = vector3D(0, 0, 0);
        for(int j = 0; j < n_particles; j++){
            if(j != i){
                vector3D r_i_j = particleList[i].getPosition() - particleList[j].getPosition();
                vector3D F_i_j = - r_i_j * ((particleList[i].getMass() * particleList[j].getMass()) / pow(r_i_j.norm(), 3));
                F_i = F_i + F_i_j;
            }
        }
        (*forces)[i] = F_i;
    }
}

/*
 * Simulate the solar system evolution with 4 elements (Sun, Earth, Jupiter, Halley)
 * The extracted data only focus on Sun, Earth & Jupiter as long as Halley is far and do not have a big effect on the simulation
 */
int main(){
    /* INITIALISATION */
    int n = 4;

    auto particleList = new Particle[n];
    double *pos = new double[3];
    double *spe = new double[3];
    double mass;

    // Sun :
    pos[0] = 0;
    pos[1] = 0;
    pos[2] = 0;
    spe[0] = 0;
    spe[1] = 0;
    spe[2] = 0;
    mass = 1.;
    particleList[0] = Particle(pos, spe, mass, 0);

    // Earth :
    pos[0] = 0;
    pos[1] = 1;
    pos[2] = 0;
    spe[0] = -1;
    spe[1] = 0;
    spe[2] = 0;
    mass = 3.0e-6;
    particleList[1] = Particle(pos, spe, mass, 1);

    // Jupiter :
    pos[0] = 0;
    pos[1] = 5.36;
    pos[2] = 0;
    spe[0] = -0.425;
    spe[1] = 0;
    spe[2] = 0;
    mass = 9.55e-4;
    particleList[2] = Particle(pos, spe, mass, 2);

    // Haley :
    pos[0] = 34.75;
    pos[1] = 0;
    pos[2] = 0;
    spe[0] = 0;
    spe[1] = 0.0296;
    spe[2] = 0;
    mass = 1.e-14;
    particleList[3] = Particle(pos, spe, mass, 3);

    delete [] pos;
    delete [] spe;

    /* SIMULATION : */
    /* Open output file : */
    std::ofstream myfile;
    // !!! You should modify the path in the 'open' function !!!
    myfile.open ("./../data.txt", std::ios::out | std::ios::trunc);

    /* Initialization : */
    auto forces_old = new vector3D[n];

    for(int i = 0; i < n; i++){
        forces_old[i] = particleList[i].getForce();
    }

    auto forces = new vector3D[n];

    calculate_forces(&forces, particleList, n);

    /* Algorithm of Stromer-Verlet :
     * It calculates the position, speed & forces at each step of times dt
     */
    double dt = 0.015;
    double t = 0;
    double t_end = 400;
    while(t < t_end){
        t = t + dt;

        /* Update position */
        for(int i = 0; i < n; i++){
            vector3D incr = (particleList[i].getSpeed() + forces[i] * (dt / (2. * particleList[i].getMass()))) * dt;
            particleList[i].setPosition(particleList[i].getPosition() + incr);

            forces_old[i] = forces[i];
        }

        /* Print the positions */
        /* for(int i = 0; i < n; i++){
            std::cout << particleList[i].getPosition() << " | ";
        }
        std::cout << "\n";*/

        /* Recalculate the forces */
        calculate_forces(&forces, particleList, n);

        /* Print the positions */
        /* for(int i = 0; i < n; i++){
            std::cout << forces[i] << " & ";
        }
        std::cout << "\n"; */

        /* Update speed */
        for(int i = 0; i < n; i++){
            vector3D incr = (forces[i] + forces_old[i]) * (dt / (2 * particleList[i].getMass()));
            particleList[i].setSpeed(particleList[i].getSpeed() + incr);
        }

        /* Redirect X & Y positions to output file */
        for(int i = 0; i < 3; i++){
            myfile << particleList[i].getPosition().getX() << " " << particleList[i].getPosition().getY() << " ";
        }
        myfile << "\n";
    }

    myfile.close();

    /* Delete */
    delete [] forces;
    delete [] forces_old;
    delete [] particleList;
}




