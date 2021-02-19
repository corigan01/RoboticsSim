#include <iostream>
#include <raylib.h>
#include <string>
#include <vector>
#include <raymath.h>
#include <math.h>
#include "robot.h"
#include "Display.h"


int main() { 
    

    Display dis(800, 600, "Robot auto");


    while(!WindowShouldClose()) {
        dis.update();
        dis.draw();
    }

}