#include <search.h>

// Search constructor
Search::Search(const Snake* snake, const SDL_Point* food)
{
    food_ = food;
    snake_ = snake;
    std::cout << "Auto search mode is activated!\n";
}

// Search destructor
Search::~Search()
{
    std::cout << "Auto search mode is closed!\n";
}

void Search::run()
{
    int currHeadX = static_cast<int>(snake_->head_x);
    int currHeadY = static_cast<int>(snake_->head_y);


    // Check weather that the location is now on the food
    if (checkXAxis() && checkYAxis())
        return;

    SDL_Event eatFoodEvent;

    eatFoodEvent.type = SDL_KEYDOWN;

    if (checkXAxis())
    {
        if(currHeadY > food_->y)
        {
            eatFoodEvent.key.keysym.sym = SDLK_UP;
        }
        else 
        {
            eatFoodEvent.key.keysym.sym = SDLK_DOWN;
        }
    }
    if (checkYAxis())
    {
        if(currHeadX > food_->x)
        {
            eatFoodEvent.key.keysym.sym = SDLK_LEFT;
        }
        else 
        {
            eatFoodEvent.key.keysym.sym = SDLK_RIGHT;
        }
    }

    SDL_PushEvent(&eatFoodEvent);
}

bool Search::checkXAxis()
{
    return food_->x == static_cast<int>(snake_->head_x);
}

bool Search::checkYAxis()
{
    return food_->y == static_cast<int>(snake_->head_y);
}