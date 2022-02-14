//
// Created by leonroussel on 2/14/22.
//

// C Program to illustrate
// OpenGL animation for revolution

// Source for OpenGL features : https://www.geeksforgeeks.org/opengl-program-simple-animation-revolution-c/

#include<GL/glut.h>
#include<math.h>
#include <fstream>
#include <iostream>

/* Global declaration */
int x, y;
float i, j;

/* Initialization function */
void myInit (void)
{
    // Reset background color with black (since all three argument is 0.0)
    glClearColor(1.0, 1.0, 1.0, 1.0);

    // Set picture color to green (in RGB model)
    // as only argument corresponding to G (Green) is 1.0 and rest are 0.0
    glColor3f(0.0, 0.0, 0.7);

    // Set width of point to one unit
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set window size in X- and Y- direction
    gluOrtho2D(-256, 256, -256, 256);
}

// Function to display animation
void display (void)
{
    std::ifstream data_file;
    data_file.open("./../data.txt");
    // Outer loop to make figure moving
    // loop variable j iterated up to 10000,
    // indicating that figure will be in motion for large amount of time
    // around 10000/6.29 = 1590 time it will revolve
    // j is incremented by small value to make motion smoother
    for (j = 0; j < 100; j += 0.01)
    {
        /*if (data_file.is_open())
        {
            while ( getline (data_file,line) )
            {
                cout << line << '\n';
            }
            myfile.close();
        }*/

        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);

        int scale_size = 40;

        // Sun
        double pos_x, pos_y;
        data_file >> pos_x >> pos_y;
        for (i = 0; i < 6.29; i += 0.0005)
        {
            int size = 8;
            x = size * cos(i) + pos_x * scale_size;
            y = size * sin(i) + pos_y * scale_size;
            glVertex2i(x, y);
        }

        // Earth
        data_file >> pos_x >> pos_y;
        for (i = 0; i < 6.29; i += 0.0005)
        {
            int size = 2;
            x = size * cos(i) + pos_x * scale_size;
            y = size * sin(i) + pos_y * scale_size;
            glVertex2i(x, y);
        }

        // Jupiter
        data_file >> pos_x >> pos_y;
        for (i = 0; i < 6.29; i += 0.0005)
        {
            int size = 4;
            x = size * cos(i) + pos_x * scale_size;
            y = size * sin(i) + pos_y * scale_size;
            glVertex2i(x, y);
        }

        glEnd();
        glFlush();
    }
}

// Driver Program
int main (int argc, char** argv)
{
    glutInit(&argc, argv);

    // Display mode which is of RGB (Red Green Blue) type
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Declares window size
    glutInitWindowSize(512, 512);

    // Declares window position which is (0, 0)
    // means lower left corner will indicate position (0, 0)
    glutInitWindowPosition(0, 0);

    // Name to window
    glutCreateWindow("Solar System");

    // Call to myInit()
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}
