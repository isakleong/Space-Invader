#include <SFML\Graphics.hpp>
using namespace sf;

class Player{
private:
	RectangleShape player;
public :
	Player(Vector2f size){
		player.setSize(size);
	}
	void pos(int x, int y){
		player.setPosition(x,y);
	}
	
	void draw(RenderWindow &window){
		Texture txt;
		txt.loadFromFile("Spaceship.png");
		player.setTexture(&txt);
		window.draw(player);
	}
};