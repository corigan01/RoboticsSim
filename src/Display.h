#pragma once

#ifndef Display_H_
#define Display_H_

#include <raylib.h>
#include <iostream>
#include <string>
#include <vector>
#include "robot.h"

class Display {
    public:

    Display(int sizeX, int sizeY, std::string Displayname);
    ~Display();

    void draw();
    void update();

    // init var

    Camera camera = { 0 };

    Vector2 mouse = GetMousePosition();
    Vector2 NMouse = mouse;
    Vector2 MouseDelta =  {NMouse.x - mouse.x, NMouse.y - mouse.y}; 
    Vector3 WorldPos = {0, 0, 0};

    robot robo;

    


};



#endif