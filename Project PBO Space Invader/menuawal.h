#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBERS_OF_ITEMS 3
class menuawal
{
public:
menuawal(float width, float height);
~menuawal();

void draw(sf::RenderWindow &window);
void moveup();
void movedown();
int getpresseditem() {return selectedindex;}
private:
int selectedindex;
sf::Font font;
//sf::Text text("Crystallibrium", font, 50);
sf::Text menu[MAX_NUMBERS_OF_ITEMS];

};


