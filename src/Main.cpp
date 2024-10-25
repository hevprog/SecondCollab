#include <raylib.h>


static void start();void Draw(); void afterdraw();void beforedraw();

int main(){
    beforedraw();
    start();
    afterdraw();
}
void beforedraw(){
    //code
}
void afterdraw(){
    //code
}
void Draw(){
    //Draw here
    DrawCircle(90,90,39,RED);
}




static void start(){
    InitWindow(1200,800,"Platformer_Game");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        Draw();
        EndDrawing();
    }
    CloseWindow();
}
