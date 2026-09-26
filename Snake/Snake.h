#ifndef SNAKE_H
#define SNAKE_H
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Point2D.h"
#include "Apple.h"
#include "SnakePart.h"
#include <vector>
#include "Play.h"

class Snake {
public:
    MyMath::Direction heading;

    SnakePart** parts; 
    int size;           
    int capacity;       

    float moveTimer = 2.5f;      
    const float moveInterval = 8.0f; 
   
    Snake();
    ~Snake();  
    void Draw() const;

    void HandleInput();
    void Move();
    void AddPart();
    bool Collide(const Apple& apple);
    bool CollideWithItself();

private:
    void Resize(); 
    void DeleteParts(); 


};

#endif
