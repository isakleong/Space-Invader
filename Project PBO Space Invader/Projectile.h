#include <SFML\Graphics.hpp>
using namespace sf;
class Projectile{
private:
	Sprite projectile;
	int cek;
public :
	Projectile(){
	}
	void setpos(int x,int y){
		projectile.setPosition(x,y);
	}
	void setcek(int x){
		cek=x;
	}
  	int getcek(){
		return cek;
	}
	int getR(){
		return projectile.getPosition().x;
	}
	int getL(){
		return projectile.getPosition().x;
	}
	int getT(){
		return projectile.getPosition().y;
	}
	int getB(){
		return projectile.getPosition().y;
	}
	void draw(RenderWindow &window){
		Texture txture5;
		txture5.loadFromFile("Projectile.png");
		projectile.setTexture(txture5);
		window.draw(projectile);
	}
};