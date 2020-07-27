#include <SFML\Graphics.hpp>
using namespace sf;
class life{
private :
	RectangleShape hr1;
	RectangleShape hr2;
	RectangleShape hr3;
public:
	life(Vector2f size){
		hr1.setSize(size);
		hr2.setSize(size);
		hr3.setSize(size);
	}
	void setpos2(int x,int y){
		hr2.setPosition(x+40,y);
	}
	void setpos1(int x,int y){
		hr1.setPosition(x+80,y);
	}
	void setpos3(int x,int y){
		hr3.setPosition(x,y);
	}
	void draw(RenderWindow &window){
		Texture h;
		h.loadFromFile("heart.png");
		hr1.setTexture(&h);
		hr2.setTexture(&h);
		hr3.setTexture(&h);
		window.draw(hr1);
		window.draw(hr2);
		window.draw(hr3);
	}
};