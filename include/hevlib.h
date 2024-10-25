
#ifndef hevproglibrary
#define hevproglibrary
#include <raylib.h>
#include <raymath.h>
typedef struct AutomaticParallax
{
   Texture2D texture;
   Vector2 initalPosition;
   Vector2 targetpos;
   float speed;
   Color color;
   float updateTimeFrame = 1; //set change in frame;
   const int direction_default = -1;
   void setTexture(Texture2D tex){
    texture = tex;}
   void setSpeed(float _speed){ // Set the scrolling speed
    speed = _speed;}
   void setInitialpos(Vector2 init){ // set position to place Texture2D
    initalPosition = init;}
   void setTarget(Vector2 _target){
    targetpos = _target;} // sets the tracker. *required
   void setColor(Color x){
    color = x;}
   
}AutomaticParallax;

/*
_______________FUNCTIONS_______________________________
*/
Vector2 moveCollision(Rectangle bodyA, Rectangle bodyB, Vector2 vector);
    /* The moveCollision takes in three args and returns a canceled Vector2 upon collision. The return is a Vector2 that you can use to update position.
    This function automatically checks for collision and capable of displacing.
        EXAMPLE OF USAGE:
            Vector2 velocity = playerInput() * Speed * TIME_DELTA;
            velocity = moveCollision(Player, Wall, velocity);
    */

void parallaxTargetSystem_H(AutomaticParallax &texture, Vector2 target, bool isInfinite);
    /* Parallax System that includes targeting and infinite horizontal scrolling. Require to pass AutomaticParallax data type as
     argument to work, only applicable to single texture but can be override with draw texture functions.
        EXAMPLE OF USAGE:
        parallaxTargetSystem_H(Mountains, player.position(), true); // infinite scrolling
        parallaxTargetSystem_H(Houses, player.position(), false); // finite scrolling
    */
void parallaxTargetSystem_V(AutomaticParallax &texture, Vector2 target, bool isInfinite);
    /* Similar to parallaxTargetSystem_H but for vertical scrolling, only applicable to single texture but
    can be override with draw texture functions;
        EXAMPLE OF USAGE:
        parallaxTargetSystem_V(Mountains, player.position(), true); // infinite scrolling
        parallaxTargetSystem_V(Houses, player.position(), false); // finite scrolling

    */




#endif //hevproglibrary