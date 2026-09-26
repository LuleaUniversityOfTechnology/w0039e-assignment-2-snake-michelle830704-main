#define PLAY_IMPLEMENTATION
#include "Play.h"
#include "Snake.h"
#include "Apple.h"
#include "constant.h"
#include <cstdlib>
#include <ctime>

Snake* snake;
Apple* apple;
int myFrameCount = 0;

const int MOVE_FRAME_RATE = 25;

void MainGameEntry(PLAY_IGNORE_COMMAND_LINE) {
    Play::CreateManager(DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE);
    Play::CentreAllSpriteOrigins();

    srand(static_cast<unsigned int>(time(0)));

    snake = new Snake();
    apple = new Apple();
}

bool StepFrame(float elapsedTime) {
    snake->HandleInput();

    if (myFrameCount % MOVE_FRAME_RATE == 6) {
        snake->Move();

        if (snake->Collide(*apple)) {
            snake->AddPart();
            delete apple;
            apple = new Apple();
        }
    }

    myFrameCount++;

    snake->Draw();
    apple->Draw();

    return Play::KeyDown(Play::KEY_ESCAPE);
}

bool MainGameUpdate(float elapsedTime) {
    Play::ClearDrawingBuffer(Play::cBlack);
    StepFrame(elapsedTime);
    Play::PresentDrawingBuffer();

    return Play::KeyDown(Play::KEY_ESCAPE);
}

int MainGameExit() {
    delete snake;
    delete apple;

    Play::DestroyManager();
    return PLAY_OK;
}