#include "menuawal.h"


menuawal::menuawal(float width, float height)
{

if(!font.loadFromFile("arial.ttf"))
{
//handle error

}
else
{

}
menu[0].setFont(font);
menu[0].setColor(sf::Color::Red);
menu[0].setString("Play");
menu[0].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBERS_OF_ITEMS + 1)*2));


menu[1].setFont(font);
menu[1].setColor(sf::Color::White);
menu[1].setString("Exit");
menu[1].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBERS_OF_ITEMS + 1)*3));

selectedindex=0;
}

menuawal::~menuawal()
{
}

void menuawal::draw(sf::RenderWindow &window)
{
for(int i=0;i<MAX_NUMBERS_OF_ITEMS-1;i++)
{
window.draw(menu[i]);
}
}

void menuawal::moveup()
{
if(selectedindex+1 >=0)
{
menu[selectedindex].setColor(sf::Color::White);
selectedindex--;
menu[selectedindex].setColor(sf::Color::Red);
}
}
void menuawal::movedown()
{
if(selectedindex+1 < MAX_NUMBERS_OF_ITEMS)
{
menu[selectedindex].setColor(sf::Color::White);
selectedindex++;
menu[selectedindex].setColor(sf::Color::Red);
}
}
