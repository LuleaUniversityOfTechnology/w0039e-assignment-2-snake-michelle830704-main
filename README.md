# w0039e-assignment-2-snake-michelle830704-main
snake assignment
This Snake game is a small project built around a clear idea: control a moving snake, collect apples, and grow longer. Although the gameplay is simple, creating it required several parts to work together. I used C++ classes to organize the snake and apple, input handling to control direction, timed updates to set the movement pace, and collision checks to detect when an apple was collected.

Working on the game helped me understand how code becomes visible gameplay. A small change to movement timing can make the snake feel much faster or slower. A collision check determines whether collecting an apple works at all. By building and testing each part, I gained practice in solving problems that also appear in larger games. The project gives me a foundation for adding more features and improving my C++ game development skills.

Code Structure

The project uses several files to keep related code together. The Snake class is responsible for the snake’s behaviour, including its movement, input, and growth. Each body section is represented by a SnakePart. The Apple class represents the object the snake collects.

The main game file connects these parts. At the start of the game, it creates the snake and apple. During play, it asks the snake to handle input and move at the correct time. It also checks whether the snake and apple have collided. Keeping these responsibilities in separate classes makes the project easier to read and change. For example, I can work on how the snake moves without putting all of that code into the main game loop.

I also use constants for values such as the display size and movement timing. These values affect the whole game, so keeping them in one place makes them easier to find and adjust. If I want to change the size of the window or the speed of the snake, I can update the relevant value instead of searching through the entire project.

