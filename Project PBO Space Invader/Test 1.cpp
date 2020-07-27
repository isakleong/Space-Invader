#include <iostream>
#include <SFML\Audio.hpp>
#include "Player.h"
#include "Invader.h"
#include "Eattack.h"
#include <Windows.h>
#include "life.h"
#include <SFML\Graphics.hpp>
#include "menuawal.h"
using namespace sf;
using namespace std;
void main(){
RenderWindow window(VideoMode(1080, 720),"Alien Menembak Di Luar Angkasa", Style::Close | Style::Titlebar);
bool playy;
bool games=false;
int x1=540,y1=620;
int x2,y2;
int x3,y3;
int a1[9];
int a2[9];
int a3[9];
bool tekan=false;
bool tekan1=false;
bool fire1=false;
bool fire=false;;
int x=80,y=80;
int dx=0,dy=0;
int q=5;
bool gerak;
int w=0;
int attack=2;
int kk=y;
int xlf=0,ylf=0;

Player player(Vector2f(80,80));
Invader enemy;
life lf(Vector2f(40,40));
Projectile projectile;
Eattack bullet;

//sound fx
menuawal menu(window.getSize().x, window.getSize().y);

Music music;
if (!music.openFromFile("musik.ogg"))
{
}

SoundBuffer buffers;
if(!buffers.loadFromFile("invaderkilled.ogg"))
{
}
Sound SFX(buffers);
SFX.setVolume(50);



while (window.isOpen()){
	if(GetAsyncKeyState(VK_RSHIFT)!=0){
	music.play();
	}
	
	//Sound
sf::Event event;
while(window.pollEvent(event))
{
switch(event.type)
{
case sf::Event::KeyReleased:
switch (event.key.code)
{
case sf::Keyboard::Up:
menu.moveup();
break;

case sf::Keyboard::Down:
menu.movedown();
break;

case sf::Keyboard::Return:
switch (menu.getpresseditem())
{
case 0:{
playy=true;
games=true;
break;
}
case 1:
playy = false;
window.close();
break;
}
break;
}
break;
case Event::Closed:
window.close();
break;
}
}

system("cls");

if(games==true)
{
	//New Game untuk mengembalikan semuanya seperti semula
	if(enemy.getgame()>=27){
		x=80;
		y=80;
		q=5;
		dx=0;
		dy=0;
		w=0;
		enemy.setpos(x,y);
		enemy.again();
		enemy.setgame(0);
		xlf=0;
		ylf=0;
		bullet.settot();
	}
	Event evnt;	

	//set position
	enemy.setpos(x,y);
	player.pos(x1,y1);
	x+=dx;
	

	//Enemy Move
	if(y<=80)
		{
			if (w==0){
			gerak=false;
			q+=2;
			}
			w=1;
		}
	else if(y+160>=540)
		{
			if(w==1){
			gerak=true;
			q+=2;
			}
			w=0;
	}
	if(q>=20)q=20;  //q=kecepatan
	if (gerak==false){
		if(x<= 80){
			dx = q;
			y+=20;
		}
		else if(x>= 960-(40*16)){
			dx = -q;
			y+=20;
		}
	}
	else if(gerak==true)
	{

		if(x<= 80){
			dx = q;
			y-=20;
		}
		else if(x>= 960-(40*16)){
			dx = -q;
			y-=20;
		}
	}

	//Player Move
	if(GetAsyncKeyState(VK_LEFT)!=0){
		if (x1 >=80){
			x1-=20;
			player.pos(x1,y1);
		}
	}

	if(GetAsyncKeyState(VK_RIGHT)!=0){
		if (x1<=940){
			x1+=20;
			player.pos(x1,y1);
		}
	}

	//Projectile Shoot Action
	if (tekan==false){
		x2=x1+38;
		y2=y1;
	if(GetAsyncKeyState(VK_SPACE)!=0){
		tekan=true;
		fire=true;
		SFX.play();
		}
	}
	
	if (y2<0){
		fire=false;
		y2=620;
		tekan=false;
		projectile.setpos(10000,10000);
	}
	if (fire==true){
			projectile.setpos(x2,y2);
			y2-=30;
			enemy.Checkcol(projectile);
			if(enemy.getcek()==1){
				projectile.setpos(10000,10000);
				fire=false;
				tekan=false;
			}
	}

	//Enemy Coll
	enemy.setcek(0);
	kk+=10; //kecepatan peluru enemy

	//Enemy Attack
	x3=x;
	y3=y;

	for(int i=0;i<9;i++){
		a1[i]=enemy.geta1();
	}
	for(int i=0;i<9;i++){
		a2[i]=enemy.geta2();
	}
	for(int i=0;i<9;i++){
 		a3[i]=enemy.geta3();
	}

	for(int i=0;i<9;i++){
		int aa;
		aa=a1[i];
		bullet.seta1(aa);
	}
	for(int i=0;i<9;i++){
		int aa;
		aa=a2[i];
		bullet.seta2(aa);
	}
	for(int i=0;i<9;i++){
		int aa;
		aa=a3[i];
		bullet.seta3(aa);
	}
	bullet.setpos(x3,y3);
	bullet.col(x1,y1);

	//Player Life
	if(bullet.gettot()==0){
		lf.setpos1(xlf,ylf);
		lf.setpos2(xlf,ylf);
		lf.setpos3(xlf,ylf);
	}
	else if(bullet.gettot()==1){
		xlf=1000;ylf=1000;
		lf.setpos1(xlf,ylf);
	}
	else if(bullet.gettot()==2){
		xlf=1000;ylf=1000;
		lf.setpos2(xlf,ylf);
	}
	else if(bullet.gettot()>=3){
		games=false;
		playy=false;
		//window.close();
		xlf=1000;ylf=1000;
		lf.setpos3(xlf,ylf);
	}
	window.clear();
	
		player.draw(window);
		enemy.draw(window);
		if(tekan==true)
		{
			projectile.draw(window);
		}
		bullet.draw(window);
		lf.draw(window);
}
if(playy==true)
	{
	}
	else
	{
		window.clear();
		menu.draw(window);
	}
	window.display();
}
}

