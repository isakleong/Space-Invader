#include "Projectile.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace sf;
using namespace std;
class Invader :public Projectile{
private:
	Sprite enemy1[9];
	Sprite enemy2[9];
	Sprite enemy3[9];
	int a1[9];
	int a2[9];
	int a3[9];
	int rands;
	int gil;
	int f;
	int game;
	int temp;
	Sprite Serang[9];
	int len;
public:
	Invader(){
	for(int i=0;i<9;i++){
		a1[i]=0;
		a2[i]=0;
		a3[i]=0;
	}
	game=0;
	len=0;
	}
	void setgame(int x){
		game=0;
	}
	void again(){
		for(int i=0;i<9;i++){
			a1[i]=0;
			a2[i]=0;
			a3[i]=0;
		}
	}
	void setpos(int x,int y){
		for(int i=0;i<9;i++){
		if(a1[i]==1){
		enemy1[i].setPosition(10000,10000);
		}
		if(a2[i]==1){
		enemy2[i].setPosition(10000,10000);
		}
		if(a3[i]==1){
		enemy3[i].setPosition(10000,10000);
		}
		if(a1[i]==0){
		enemy1[i].setPosition(x,y);
		}
		if(a2[i]==0){
		enemy2[i].setPosition(x,y+80);
		}
		if(a3[i]==0){
		enemy3[i].setPosition(x,y+160);
		}
		x+=(40*2);
	}
	}
	void setcek(int x){
		f=x;
	}
	void draw(RenderWindow &window){
	Texture txture1;
	Texture txture2;
	Texture txture3;
	Texture txture4;
	txture4.loadFromFile("Projectile.png");		
	for (int i=0;i<9;i++){
	Serang[i].setTexture(txture4);
	}
	txture1.loadFromFile("Alien1.png");
	for (int i=0;i<9;i++){
	enemy1[i].setTexture(txture1);
	}
	txture2.loadFromFile("Alien2.png");
	for (int i=0;i<9;i++){
	enemy2[i].setTexture(txture2);
	}
	txture3.loadFromFile("Alien3.png");
	for (int i=0;i<9;i++){
	enemy3[i].setTexture(txture3);
	}
	for(int i=0;i<9;i++){
		window.draw(Serang[i]);
		window.draw(enemy1[i]);
		window.draw(enemy2[i]);
		window.draw(enemy3[i]);
	}
	}
	int getgame(){
		return game;
	}
	int geta1(){
		return a1[len];
		len++;
		if(len>=9){
			len=0;
		}
	}
	int geta2(){
		return a2[len];
		len++;
		if(len>=9){
			len=0;
		}
	}
	int geta3(){
		return a3[len];
		len++;
		if(len>=9){
			len=0;
		}
	}
	void Checkcol(Projectile projectile){
		for (int i=0;i<9;i++){
		if (projectile.getR()<=enemy1[i].getPosition().x+32 && 
			projectile.getT()<=enemy1[i].getPosition().y &&
			projectile.getL()>=enemy1[i].getPosition().x &&
			projectile.getB()>=enemy1[i].getPosition().y-32){
				enemy1[i].setPosition(1110101,1231313);
				a1[i]=1;
				f=1;
				game++;
		}
		if (projectile.getR()<=enemy2[i].getPosition().x+44 && 
			projectile.getT()<=enemy2[i].getPosition().y &&
			projectile.getL()>=enemy2[i].getPosition().x &&
			projectile.getB()>=enemy2[i].getPosition().y-32){
				enemy2[i].setPosition(1110101,1231313);
				a2[i]=1;
				f=1;
				game++;
		}
		if (projectile.getR()<=enemy3[i].getPosition().x+48 && 
			projectile.getT()<=enemy3[i].getPosition().y &&
			projectile.getL()>=enemy3[i].getPosition().x &&
			projectile.getB()>=enemy3[i].getPosition().y-32){
				enemy3[i].setPosition(1110101,1231313);
				a3[i]=1;
				f=1;
				game++;
		}
		}
	}
	int getcek(){
		return f;
	}
};

