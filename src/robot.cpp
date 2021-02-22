#include "robot.h"
#include <math.h>
#include <raymath.h>


#define autoB float((((float)GetScreenWidth()/1920.0f) + ((float)GetScreenHeight() / 1080.0f)) / 2.0f) *

robot::robot() {
    //Mesh cube = GenMeshCube(1.0f, 1.0f, 1.0f);
    //robotModel = LoadModelFromMesh(torus);
}
robot::~robot() {
    // de-init
}

// Draw the robot 
void robot::draw() {
    //DrawSphere      ({Pos.x, 1, Pos.y}, 1, RED);
    DrawSphereWires({Pos.x, 1, Pos.y}, 1, 10, 10, RED);
    DrawCubeWiresV  ({Pos.x, 1, Pos.y}, {1.5, 1.5, 1.5}, GREEN);  

    for (int x = 0; x < 3; x++) {
        for (int z = 0; z < 3; z++) {
            DrawLine3D({Pos.x, 1, Pos.y}, {
                ((Val.x / cos(rotation) * 100 + 1) * cos(rotation) + Pos.x + (x / 100.f)),
                1,
                ((Val.y / sin(rotation) * 100 + 1) * sin(rotation) + Pos.y + (z / 100.f))
                }, BLUE);
        }
    }

    DrawLine3D({Pos.x, 1, Pos.y}, {Pos.x + 2, 1, Pos.y}, MAGENTA);
    DrawLine3D({Pos.x, 1, Pos.y}, {Pos.x - 2, 1, Pos.y}, MAGENTA);
    DrawLine3D({Pos.x, 1, Pos.y}, {Pos.x, 1, Pos.y + 2}, MAGENTA);
    DrawLine3D({Pos.x, 1, Pos.y}, {Pos.x, 1, Pos.y - 2}, MAGENTA);

    for (auto i : BallPos) {
            DrawSphere({i.x , 1, i.y}, 0.5, RAYWHITE);
    }

    EndMode3D();
    
    DrawRectangleRec({10, GetScreenHeight() -  (autoB 520), autoB 500, autoB 500}, GRAY);

    //DrawCircle(Pos.x - 10, Pos.y - (GetScreenHeight() -  (autoB 520)), autoB 100, RED);
    Vector2 PosS = { (Pos.x * 10 - 10) + ((autoB 500) / 2) , (Pos.y * 10) + (GetScreenHeight() -  (autoB 520)) + ((autoB 500) / 2) };
    
    for (auto i : BallPos) {
        Vector2 PosB = { (i.x * 10 - 10) + ((autoB 500) / 2) , (i.y * 10) + (GetScreenHeight() -  (autoB 520)) + ((autoB 500) / 2) };

        DrawCircleV(PosB, autoB 15, WHITE);
    }

    DrawCircleV(PosS, autoB 15, RED);
    DrawLineEx({PosS.x, PosS.y}, {
                ((Val.x / cos(rotation) * 100 + 1) * cos(rotation) + PosS.x),
                ((Val.y / sin(rotation) * 100 + 1) * sin(rotation) + PosS.y)
                }, autoB 2, GREEN);
    DrawLineEx({PosS.x, PosS.y}, {
                (100 * cos(rotation) + PosS.x),
                (100 * sin(rotation) + PosS.y)
                }, autoB 2, BLUE);


    
    
    

    //DrawModel(robotModel, {Pos.x, 1, Pos.y}, 1, WHITE);
}

void robot::update() {
    //Acl.x += Acl.x > 0.001 && Acl.x < -0.001 ? -0.001 : 0.001;
    //Acl.y += Acl.y > 0.001 && Acl.y < -0.001 ? -0.001 : 0.001;

    if (Val.x >= 0.005) {
        Val.x -= 0.001;
    }
    else if (Val.x <= 0.005) {
        Val.x += 0.001;
    }

    if (Val.y >= 0.005) {
        Val.y -= 0.01;
    }
    else if (Val.y <= 0.005) {
        Val.y += 0.01;
    }

    if (Val.x > 0.001 && Val.x < 0.06) {
        Val.x = 0;
    }
    if (Val.y > 0.001 && Val.y < 0.06) {
        Val.y = 0;
    }

    if (Val.x < -0.001 && Val.x > -0.06) {
        Val.x = 0;
    }
    if (Val.y < -0.001 && Val.y > -0.06) {
        Val.y = 0;
    }

    Val.x += Acl.x;
    Val.y += Acl.y;

    

    float rad = MaxSpeed;

    float Xp = Val.x, Xc = 0;
    float Yp = Val.y, Yc = 0;

    float Xmax = 0, Ymax = 0;

    float DPoint = sqrt( (Xp * Xp) + (Yp * Yp) );


    if (DPoint <= rad) {
        Xmax = Xp;
        Ymax = Yp;
    }
    if (DPoint > rad) {
        Xmax = ( (Xp * rad)   /   DPoint );
        Ymax = ( (Yp * rad)   /   DPoint );
    }
    

    Val.x = Xmax;
    Val.y = Ymax;
    
    Pos.x += Val.x;
    Pos.y += Val.y;

    

    

    //robotModel.transform = MatrixRotateXYZ({DEG2RAD*0, DEG2RAD*rotation, DEG2RAD*0});
}

// compatibility with WPIlib
void robot::drivetrain(float powForward, float powSide) {
    float realPowerForward = powForward * MaxSpeed;
    
    rotation += (powSide / 10);

    Acl = {cosf(rotation) * realPowerForward, sinf(rotation) * realPowerForward};
}


float robot::GetRotation() { 
    return rotation;
}

void robot::maxspeed(float speed) {
    MaxSpeed = speed;
}






