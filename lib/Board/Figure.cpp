// figure.cpp

#include "figure.h"

Figure::Figure(char name) {
    this->name = name; 
}

char Figure::getName() {
    return this->name;
}

Color Figure::getColor() {
    return this->color;
}