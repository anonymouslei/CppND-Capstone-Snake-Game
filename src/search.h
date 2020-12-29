#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>

#include "snake.h"
#include "SDL.h"

class Search {
public:
    Search(const Snake* snake, const SDL_Point* food);
    ~Search();
    void run();

private:
    bool checkXAxis();
    bool checkYAxis();

    const SDL_Point* food_;
    const Snake* snake_;

};

#endif