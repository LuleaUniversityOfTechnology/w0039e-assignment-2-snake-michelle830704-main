#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Snake.h"
#include "Play.h" 
#include "Point2D.h"
#include <cmath> 

Snake::Snake() : heading(MyMath::Direction::North), size(2), capacity(2) {
    
    parts = new SnakePart *[capacity];


    parts[0] = new SnakePart(MyMath::Point2D(40, 40), Play::Colour(0, 100, 0));
    parts[1] = new SnakePart(MyMath::Point2D(40, 20), Play::Colour(0, 0, 200));
}

Snake::~Snake() {
   
    for (int i = 0; i < size; ++i) {
        delete parts[i];
    }
    delete[] parts;  
}

void Snake::Draw() const {
    
    for (int i = 0; i < size; ++i) {
        parts[i]->Draw();
    }
}

void Snake::HandleInput() {
    if (Play::KeyPressed(Play::KEY_UP)) {
        heading = MyMath::Direction::North;
    }
    else if (Play::KeyPressed(Play::KEY_DOWN)) {
        heading = MyMath::Direction::South;
    }
    else if (Play::KeyPressed(Play::KEY_LEFT)) {
        heading = MyMath::Direction::West;
    }
    else if (Play::KeyPressed(Play::KEY_RIGHT)) {
        heading = MyMath::Direction::East;
    }
}

void Snake::Move() {
    
    for (int i = size - 1; i > 0; --i) {
        parts[i]->position = parts[i - 1]->position;
    }

    
    switch (heading) {
    case MyMath::Direction::North:
        parts[0]->position.y += 20;
        break;
    case MyMath::Direction::South:
        parts[0]->position.y -= 20;
        break;
    case MyMath::Direction::West:
        parts[0]->position.x -= 20;
        break;
    case MyMath::Direction::East:
        parts[0]->position.x += 20;
        break;
    }
}

void Snake::AddPart() {
   
    if (size == capacity) {
        Resize();
    }

    
    MyMath::Point2D newPartPosition = parts[size - 1]->position;  
    parts[size] = new SnakePart(newPartPosition, Play::Colour(0, 100, 0)); 
    size++;  
}

void Snake::Resize() {

    capacity *= 2;

    
    SnakePart** newParts = new SnakePart * [capacity];

    
    for (int i = 0; i < size; ++i) {
        newParts[i] = parts[i];
    }

    
    delete[] parts;

    
    parts = newParts;
}

bool Snake::Collide(const Apple& apple) {
    bool collide = false;

 
    float dx = apple.position.x - parts[0]->position.x;
    float dy = apple.position.y - parts[0]->position.y;

    float distance = sqrt(dx * dx + dy * dy);  

   
    if (distance < 5.0f) {
        collide = true;
    }

    return collide;
}
