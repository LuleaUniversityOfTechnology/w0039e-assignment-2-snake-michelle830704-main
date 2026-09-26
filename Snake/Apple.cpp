#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Apple.h"
#include <cstdlib>
#include "Play.h"
#include "constant.h"

Apple::Apple() {
    position.x = static_cast<float>((rand() % (DISPLAY_WIDTH / 20)) * 20);
    position.y = static_cast<float>((rand() % (DISPLAY_HEIGHT / 20)) * 20);
}

void Apple::Draw() const {
    Play::DrawCircle({ position.x, position.y }, 10, Play::Colour(255, 0, 0));
}