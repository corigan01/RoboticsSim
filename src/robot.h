#pragma once

#ifndef ROBOT_H_
#define ROBOT_H_

#include <raylib.h>
#include <iostream>
#include <string>
#include <vector>



class robot {
    public:

    robot();
    ~robot();

    // Draw the robot 
    void draw();
    void update();


    // compatibility with WPIlib
    void drivetrain(float powForward, float powSide);
    float GetRotation();
    void maxspeed(float speed);
    

    Vector2 Pos = {0, 0};
    Vector2 Val = {0, 0};
    Vector2 Acl = {0, 0};
    
    float rotation = 0;

    float MaxSpeed = 0;

    Model robotModel;

};






#endif // !ROBOT_H_
