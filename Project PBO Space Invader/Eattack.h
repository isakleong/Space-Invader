#include <SFML\Graphics.hpp>
#include<Windows.h>
#include<time.h>
using namespace sf;
class Eattack{
private:
	Sprite bullet1;
	Sprite bullet2;
	Sprite bullet3;
	int x1,y1;
	int x2,y2;
	int x3,y3;
	int a1[9],a2[9],a3[9];
	bool cek;
	int len;
	int jum;
	int aa1,aa2,aa3;
	int tot;
public :
	Eattack(){
		tot=0;
		cek=false;
		len=0;
		jum=0;
		aa1=0;
		aa2=4;
		aa3=8;
	}
	void seta1(int x){
		a1[len]=x;
		len++;
		if(len>=9){
			len=0;
		}
	}
	void seta2(int x){
		a2[len]=x;
		len++;
		if(len>=9){
			len=0;
		}
	}
	void seta3(int x){
		a3[len]=x;
		len++;
		if(len>=9){
			len=0;
		}
	}
	void setpos(int x,int y){
		srand(time(NULL));
			if(cek==false){
			aa1=rand()%8;
			aa2=rand()%8;
			aa3=rand()%8;
		
			for(int i=0;i<9;i++){
				/*if(a1[i]==0){*/
					if(aa1==i){		
					bullet1.setPosition(x,y);
					x1=x;y1=y;
					}
				
				/*if(a2[i]==0){*/
					if(aa2==i){
					bullet2.setPosition(x,y+80);
					x2=x;y2=y+80;
					}
				
				/*if(a3[i]==0){*/
					if(aa3==i){	
					bullet3.setPosition(x,y+160);
					x3=x;y3=y+160;
					}
				
				x+=80;
			}
			}
	}
	void col(int x,int y){
		cek=true;
		int h=0;
		if(y1>=720){
			bullet1.setPosition(1000,1000);
			h++;
		}
		if(x1>=x&&x1<=x+80&&y1>=620){
			bullet1.setPosition(1000,1000);
			cek=false;
			tot+=1;
		}
		if(y2>=720){
			bullet2.setPosition(1000,1000);
			h++;
		}
		if(x2>=x&&x2<=x+80&&y2>=620){
			bullet2.setPosition(1000,1000);
			cek=false;
			tot+=1;
		}

		if(y3>=720){
			bullet3.setPosition(1000,1000);
			h++;
		}
		if(x3>=x&&x3<=x+80&&y3>=620){
			bullet3.setPosition(1000,1000);
			cek=false;
			tot+=1;
		}
		int jj=0;
		for(int i=0;i<9;i++){
			if(a1[i]==1){
				jj++;
				if (jj==9){
				jum++;
				}
			}
		}
		
		jj=0;
		for(int i=0;i<9;i++){
			if(a2[i]==1){
				jj++;
				if (jj==9){
					jum++;
				}
			}
		}
		
		jj=0;
		for(int i=0;i<9;i++){
			if(a3[i]==1){
				jj++;
				if (jj==9){
					jum++;
				}
			}
		}
		

		if(h+jum==3){
			cek=false;
		}
		jum=0;
		y1+=10;
		y2+=10;
		y3+=10;
		bullet1.setPosition(x1,y1);
		bullet2.setPosition(x2,y2);
		bullet3.setPosition(x3,y3);
	}
	int gettot(){
		return tot;
	}
	void settot(){
		tot=0;
	}
	void draw(RenderWindow &window){
		Texture txture4;
		txture4.loadFromFile("Projectile.png");		
			bullet1.setTexture(txture4);
			bullet2.setTexture(txture4);
			bullet3.setTexture(txture4);
			for(int i=0;i<9;i++)
			{
				if(a1[i]==0)
				window.draw(bullet1);
				if(a2[i]==0)
				window.draw(bullet2);
				if(a3[i]==0)
				window.draw(bullet3);
			}
			
		
	}
	
	

};