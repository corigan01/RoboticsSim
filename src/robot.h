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

    // This is the positions the robot nees to hope to get to
    // All positions will have a pid loop to try and get to the next one
    // This will have the goal Angle and Goal speed 
    std::vector<Vector2> AutoM;

    // This will have the ball pos
    std::vector<Vector2> BallPos {
      {10.f, 2.f},
      {14.f, 5.f},
      {18.f, 2.f}  
    };

    int workingBall = 0;

};






#endif // !ROBOT_H_
