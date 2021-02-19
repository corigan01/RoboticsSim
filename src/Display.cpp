#include "Display.h"
#define autoB float((((float)GetScreenWidth()/1920.0f) + ((float)GetScreenHeight() / 1080.0f)) / 2.0f) *

Display::Display(int sizeX, int sizeY, std::string Displayname) {
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);


    InitWindow(sizeX, sizeY, Displayname.c_str());


    camera.position = (Vector3){ 4.0f, 2.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
    camera.up = (Vector3){ 0.0f, 2.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.type = CAMERA_PERSPECTIVE;
    SetCameraMode(camera, CAMERA_FIRST_PERSON);

    SetTargetFPS(60);

    robo.maxspeed(.07);

}

Display::~Display(){
    CloseWindow();
    exit(0);
}

void Display::draw(){
    BeginDrawing();
        ClearBackground(BLACK);


        BeginMode3D(camera);

        DrawGrid(1000, 0.1f);

        robo.draw();


        EndMode3D();


        DrawText(std::string("X: " + std::to_string(camera.position.x) +  " Y: " + std::to_string(camera.position.y) + " Z: " + std::to_string(camera.position.z) + 
        "\nRotation: " + std::to_string(((int)(robo.GetRotation() * RAD2DEG * 10)) / 10.f) + "\n" + 
        "robo acc: " + std::to_string(robo.Acl.x) + " , " + std::to_string(robo.Acl.y) + "\n" +
        "robo val: " + std::to_string(robo.Val.x) + " , " + std::to_string(robo.Val.y) + "\n" +
        "robo pos: " + std::to_string(robo.Pos.x) + " , " + std::to_string(robo.Pos.y) + "\n" 
        ).c_str(), 0, 0, 35, RED);

        Vector2 PosS = { (camera.position.x * 10 - 10) + ((autoB 500) / 2) , (camera.position.z * 10) + (GetScreenHeight() -  (autoB 520)) + ((autoB 500) / 2) };
         DrawCircleV(PosS, autoB 10, BLUE);


        EndDrawing();

        NMouse = mouse;
}

void Display::update(){
    mouse = GetMousePosition();
    MouseDelta =  {NMouse.x - mouse.x, NMouse.y - mouse.y}; 
    
    UpdateCamera(&camera);


    Vector2 PosAdd = {0, 0};

    if (IsKeyDown(KEY_I)) {
        PosAdd.x = 1;
    }
    if (IsKeyDown(KEY_J)) {
        PosAdd.y = -1;
    }
    if (IsKeyDown(KEY_K)) {
        PosAdd.x = -1;
    }
    if (IsKeyDown(KEY_L)) {
        PosAdd.y = 1;
    }

    robo.drivetrain(PosAdd.x, PosAdd.y);


    
    robo.update();

    
}