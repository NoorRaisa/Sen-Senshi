#include "iGraphics.h"
#include "bitmap_loader.h"
#include "variables.h"
#include "menu.h"
#include "score.h"

/*
 function iDraw() is called again and again by the system.

 */
void resetGame();
struct renderBackground{
	int x, y;
}background[15];
renderBackground background_level2[15];
renderBackground background_level3;

struct Obstacle{
	int x, y;
	bool obstacle_visible;
};
Obstacle obstacle[obstacleNumber];
Obstacle obstacle2[obstacleNumber2];

struct enemyMonster{
	int x, y, mons_index;
	bool monster_visible;
};
enemyMonster monster_lvl1[monsterNumber];
enemyMonster monster_lvl2[monsterNumber2];
struct specialpower{
	int x, y;
	bool power_visible;

};
specialpower p[power];
void gamePause()
{
	iShowBMP(300, 160, "Image\\pause.bmp");
}
void menuBar(){
	iShowImage(0, 0, screenWidth, screenHeight, iLoadImage("Image\\menu.png"));
	for (int i = 0; i < 5; i++)
	{
		iShowBMP2(menu_buttons[i].x, menu_buttons[i].y, menubuttons[i], 255);
	}
}
void showLifebar()
{
	if (lifebar_visible)
	{
		iShowBMP2(0, 540, lifebar[life_index], 0);
	}
}
void showbosslifebar()
{
	if (bossvisible){
		iShowBMP2(880, 520, bosslifebar[boss_index], 0);
	}
}
void obstacleRender()
{
	for (int i = 0; i < obstacleNumber; i++){
		if (obstacle[i].obstacle_visible){
			iShowBMP2(obstacle[i].x, obstacle[i].y, obs,0);
			///iShowBMP(obstacle[i].x, obstacle[i].y, box);
			///iShowImage(obstacle[i].x, obstacle[i].y, 100, 100, iLoadImage("Image\\obs.png"));
		}
	}
}
void obstacleRender2()
{
	for (int i = 0; i < obstacleNumber2; i++){
		if (obstacle2[i].obstacle_visible){
			iShowBMP2(obstacle2[i].x, obstacle2[i].y, obs, 0);
			///iShowBMP(obstacle[i].x, obstacle[i].y, box);
			///iShowImage(obstacle[i].x, obstacle[i].y, 100, 100, iLoadImage("Image\\obs.png"));
		}
	}
}
void backgroundrender_level1()
{
	for (int i = 0; i < 15; i++)
	{
		iShowBMP(background[i].x, background[i].y, backgroundImage[i]);
	}
}
void backgroundrender_level2()
{
	for (int i = 0; i < 15; i++)
		iShowBMP(background_level2[i].x, background_level2[i].y, bg_lvl2[i]);
}
void backgroundrender_level3()
{
	iShowBMP(background_level3.x, background_level3.y, background_lvl3);
}
void level1_end()
{
	if (levelup){
		iShowBMP2(900, 50, levelUp, 0);
	}
	if (averyX >= 940){
		levelup = false;
		level++;
		lifebar_visible = true;
		life_index = 0;
		///averyVisible = false;
		averyVisible2 = true;
		level2characters = true;
		averyX = 0;
		averyY = 110;
	}
}
void level2_end()
{
	if (car){
		iShowBMP2(900, 80, carimg, 0);
	}
	if (averyX1 >= 890){
		car = false;
		level++;
		lifebar_visible = true;
		life_index = 0;
		///averyVisible = false;
		averyVisible3 = true;
		level3characters = true;
		bossvisible = true;
		bossfiring = true;
		
	}
}
void level3_end()
{
	if (chestv){
		iShowBMP2(900, 80, chest, 0);
	}
	if (averyX2 >= 890){
		chestv = false;
		life_index = 0;
		completegame = true;
		highScore();
		//pause = true;
		gameState = -2;
		level = 1;
		///pause = true;
	}
}
void bossMovement()
{
	if (bossvisible&&bossfiring){
		iShowBMP2(bossX, bossY, boss, 0);
		iShowBMP2(bossfireX, bossfireY, fire[fire_index], 0);
	}
}
void avery_Movement()
{
	if (averyVisible){
		if (jump){
			if (jumpUp){
				iShowBMP2(averyX, averyY + averyJump, avery_jump[0], 0);
			}
			else{
				iShowBMP2(averyX, averyY + averyJump, avery_jump[1], 0);
			}
		}
		if (standfront)
		{
			runForward = runBackward = false;
			iShowBMP2(averyX, averyY, avery_stand[stand_index], 0);
		}
		if (standrev)
		{
			runForward = runBackward = false;
			iShowBMP2(averyX, averyY, stand_rev[stand_index], 0);
		}
		if (firing&&front)
		{
			iShowBMP2(fireX, fireY, star[star_index], 0);
		}
		if (firing&&back)
		{
			iShowBMP2(fireX, fireY, star[star_index], 0);
		}
		if (runForward)
		{
			iShowBMP2(averyX, averyY, avery_run[runIndex], 0);
			stand_count++;
			if (stand_count >= 20)
			{
				stand_count = 0;
				running = false;
				stand = true;
				standfront = true;
			}
		}
		if (runBackward)
		{
			iShowBMP2(averyX, averyY, run_rev[runIndex], 0);
			stand_count++;
			if (stand_count >= 20)
			{
				stand_count = 0;
				running = false;
				stand = true;
				standrev = true;
			}
		}
	}
	
}
void avery_Movement_lvl2()
{
	if (averyVisible2){
		if (jump){
			if (jumpUp){
				iShowBMP2(averyX1, averyY1 + averyJump, avery_jump[0], 0);
			}
			else{
				iShowBMP2(averyX1, averyY1 + averyJump, avery_jump[1], 0);
			}
		}
		if (standfront)
		{
			runForward = runBackward = false;
			iShowBMP2(averyX1, averyY1, avery_stand[stand_index], 0);
		}
		if (standrev)
		{
			runForward = runBackward = false;
			iShowBMP2(averyX1, averyY1, stand_rev[stand_index], 0);
		}
		if (firing&&front)
		{
			iShowBMP2(fireX, fireY, star3[star_index], 0);
		}
		if (firing&&back)
		{
			iShowBMP2(fireX, fireY, star3[star_index], 0);
		}
		if (runForward)
		{
			iShowBMP2(averyX1, averyY1, avery_run[runIndex], 0);
			stand_count++;
			if (stand_count >= 20)
			{
				stand_count = 0;
				running = false;
				stand = true;
				standfront = true;
			}
		}
		if (runBackward)
		{
			iShowBMP2(averyX1, averyY1, run_rev[runIndex], 0);
			stand_count++;
			if (stand_count >= 20)
			{
				stand_count = 0;
				running = false;
				stand = true;
				standrev = true;
			}
		}
	}
}
void avery_Movement_lvl3()
{
	if (averyVisible3){
		if (jump){
			if (jumpUp){
				iShowBMP2(averyX2, averyY2 + averyJump, avery_jump[0], 0);
			}
			else{
				iShowBMP2(averyX2, averyY2 + averyJump, avery_jump[1], 0);
			}
		}
		if (standfront)
		{
			runForward = runBackward = false;
			iShowBMP2(averyX2, averyY2, avery_stand[stand_index], 0);
		}
		if (standrev)
		{
			runForward = runBackward = false;
			iShowBMP2(averyX2, averyY2, stand_rev[stand_index], 0);
		}
		if (firing&&front)
		{
			iShowBMP2(fireX, fireY, star2[star_index], 0);
		}
		if (firing&&back)
		{
			iShowBMP2(fireX, fireY, star2[star_index], 0);
		}
		if (runForward)
		{
			iShowBMP2(averyX2, averyY2, avery_run[runIndex], 0);
			stand_count++;
			if (stand_count >= 20)
			{
				stand_count = 0;
				running = false;
				stand = true;
				standfront = true;
			}
		}
		if (runBackward)
		{
			iShowBMP2(averyX2, averyY2, run_rev[runIndex], 0);
			stand_count++;
			if (stand_count >= 20)
			{
				stand_count = 0;
				running = false;
				stand = true;
				standrev = true;
			}
		}
	}
}
void monsterMovement(){
	for (int i = 0; i < monsterNumber; i++){
		if (monster_lvl1[i].monster_visible){
				iShowBMP2(monster_lvl1[i].x, monster_lvl1[i].y, monster_run_level1[monster_lvl1[i].mons_index], 0);
		}
	}
}
void monsterMovement_lvl2(){
	for (int i = 0; i < monsterNumber2; i++){
		if (monster_lvl2[i].monster_visible){
			iShowBMP2(monster_lvl2[i].x, monster_lvl2[i].y, monster_run_level2[monster_lvl2[i].mons_index], 0);
		}
	}
}
void collisionCheck()
{
	if (!pause){
		if (level == 1 && level1characters){
			for (int i = 0; i < monsterNumber; i++){
				if (monster_lvl1[i].monster_visible&&averyVisible){
					if ((averyX >= monster_lvl1[i].x && averyX <= monster_lvl1[i].x + 100) && (averyY+20>= monster_lvl1[i].y && averyY<= monster_lvl1[i].y + 120)){
						life_index++;
						if (life_index >= 5){
							life_index = 5;
							lifebar_visible = false;
							monster_lvl1[i].monster_visible = false;
							averyVisible = false;
							///level1characters = false;
							gameOver = true;
							gameState = -2;
							pause = true;
							highScore();
						}
					}
				}
			}
		}
		if (level == 2 && level2characters){
			for (int i = 0; i < monsterNumber2; i++){
				if (monster_lvl2[i].monster_visible&&averyVisible2){
					if ((averyX1+30  >= monster_lvl2[i].x && averyX1 <= monster_lvl2[i].x + 100) && (averyY1+20>= monster_lvl2[i].y && averyY1 <= monster_lvl2[i].y + 120)){
						life_index++;
						if (life_index >= 5){
							life_index = 5;
							lifebar_visible = false;
							monster_lvl2[i].monster_visible = false;
							averyVisible2 = false;
							gameOver = true;
							gameState = -2;
							pause = true;
							highScore();
						}
					}
				}
			}
			for (int i = 0; i < obstacleNumber; i++){
				if (obstacle[i].obstacle_visible&&averyVisible2){
					if ((averyX1+30>=obstacle[i].x && averyX1<=obstacle[i].x+74)&&(averyY1+20>=obstacle[i].y && averyY1+averyJump<=obstacle[i].y+88)){
						life_index++;
						if (life_index >= 5){
							life_index = 5;
							lifebar_visible = false;
							obstacle[i].obstacle_visible = false;
							averyVisible2 = false;
							gameOver = true;
							gameState = -2;
							pause = true;
							highScore();
						}
					}
				}
			}
		}
		/*if (level == 3 && bossvisible){
			for (int i = 0; i < obstacleNumber2; i++){
				if (obstacle2[i].obstacle_visible&&averyVisible3&&bossvisible){
					if ((averyX2 >= obstacle2[i].x && averyX2 <= obstacle2[i].x + 74) && (averyY2+20>= obstacle2[i].y && averyY2 + averyJump <= obstacle2[i].y + 88)){
						life_index++;
						if (life_index >= 5 && count2 < 3){
							life_index = 0;
							count2++;
						}
						else if (life_index >= 5 && count2 == 3){
							life_index = 5;
							obstacle2[i].obstacle_visible = false;
							lifebar_visible = false;
							averyVisible3 = false;
							bossfiring = false;
							bossvisible = false;
							gameOver = true;
							gameState = -2;
							pause = true;
							highScore();
						}
					}
				}
			}
		}*/
	}
}
void bosscollisioncheck()
{
	if (!pause){
		if (level == 3 && level3characters){
			if (bossfiring){
				if ((averyX2 <= bossfireX+27  && averyX2 + 77 >= bossfireX)&&(averyY2+averyJump<=bossfireY+19)){					
				life_index++;
				if (life_index >= 5 && count2 < 3){
						life_index = 0;
						count2++;
					}
					else if (life_index >= 5 && count2 == 3){
						life_index = 5;
						lifebar_visible = false;
						averyVisible3 = false;
						bossfiring = false;
						bossvisible = false;
						gameOver = true;
						gameState = -2;
						pause = true;
						highScore();
					}
				}
			}
		}
	}
}
void starAndMonsterCollisionCheck()
{
	if (!pause){
		if (firing){
			if (level == 1){
				for (int i = 0; i < monsterNumber; i++){
					if (monster_lvl1[i].monster_visible){
						if ((fireX+40>= monster_lvl1[i].x && fireX <= monster_lvl1[i].x + 100) && (fireY <= monster_lvl1[i].y + 120 && fireY+35 >= monster_lvl1[i].y)){
							monster_lvl1[i].monster_visible = false;
							firing = false;
							fireX = averyX + 10000000000000000000;
							enemyKilled++;
							killScore += 5;
						}
					}
				}
			}
			else if (level == 2){
				for (int i = 0; i < monsterNumber2; i++){
					if (monster_lvl2[i].monster_visible){
						if ((fireX+40>= monster_lvl2[i].x && fireX <= monster_lvl2[i].x + 100) && (fireY <= monster_lvl2[i].y + 120 && fireY+35 >= monster_lvl2[i].y)){
							monster_lvl2[i].monster_visible = false;
							firing = false;
							fireX = averyX1 + 10000000000000000000;
							enemyKilled++;
							killScore += 5;
						}
					}
				}
			}
			else if (level == 3){
				if (bossvisible){
					if ((fireX  >= bossX&&fireX <= bossX + 120) && (fireY <= bossY + 124 && fireY  >= bossY)){
						boss_index++;
						firing = false;
						fireX = averyX2 + 10000000000000000000;
						///enemyKilled++;
						killScore += 5; 
						if (boss_index >= 7 && count1 < 5){
							boss_index = 0;
							count1++;
						}
						else if (boss_index >= 7 && count1 == 5){
							boss_index = 7;
							bossvisible = false;
							bossfiring = false;
						}
					}
				}
			}
		}
	}
}
void iDraw()
{
	iClear();
	if (gameState == -1)
		menuBar();
	else if (gameState == 0 && level == 1){
		if (level1characters){
			///pause = false;
			backgroundrender_level1();
			scoreCounter();
			avery_Movement();
			monsterMovement();
			showLifebar();
			if (pause) gamePause();
			iShowImage(530, 530, 156, 69, iLoadImage("Image\\Level 1.png"));
		}
		else{
			backgroundrender_level1();
			avery_Movement();
			level1_end();
			if (pause) gamePause();
			///iShowImage(530, 530, 156, 69, iLoadImage("Image\\Level 1.png"));
		}
	}
	else if (gameState == 0 && level == 2){
		if (level2characters){
			///pause = false;
			backgroundrender_level2();
			avery_Movement_lvl2();
			scoreCounter();
			showLifebar();
			monsterMovement_lvl2();
			obstacleRender();
			if (pause) gamePause();
			iShowImage(530, 530, 156, 69, iLoadImage("Image\\Level 2.png"));
		}
		else{
			backgroundrender_level2();
			avery_Movement_lvl2();
			level2_end();
			if (pause) gamePause();
		}
	}
	else if (gameState == 0 && level == 3){
		if (bossvisible){
			backgroundrender_level3();
			avery_Movement_lvl3();
			obstacleRender2();
			bossMovement();
			scoreCounter();
			showLifebar();
			showbosslifebar();
			if (pause) gamePause();
			iShowImage(530, 530, 153, 68, iLoadImage("Image\\Level 3.png"));
		}
		else{
			backgroundrender_level3();
			avery_Movement_lvl3();
			level3_end();
			if (pause) gamePause();
		}
	}
	else if (gameState == 1)
		iShowImage(0, 0, screenWidth, screenHeight, iLoadImage("Image\\ins.png"));
	else if (gameState == 2)
	{
		iShowImage(0, 0, screenWidth, screenHeight, iLoadImage("Image\\score.png"));
		showscore();
	}
	else if (gameState == 3)
		iShowImage(0, 0, screenWidth, screenHeight, iLoadImage("Image\\credit.png"));
	else if (gameState == 4)
		exit(0);
	else if (gameOver==true){
		iShowImage(0, 0, screenWidth, screenHeight, iLoadImage("Image\\gameover.png"));
		resetGame();
		///gameOver = false;
	}
	else if (completegame == true){
		iShowImage(0, 0, screenWidth, screenHeight, iLoadImage("Image\\CONGO.png"));
		resetGame();
	}
}

void change()
{
	if (!pause){
		if (level == 1){
			if (jump){
				if (jumpUp){
					averyJump += 5;
					if (averyJump >= jumpLimit){
						jumpUp = false;
					}
				}
				else{
					averyJump -= 5;
					if (averyJump < 0){
						jump = false;
						averyJump = 0;
						stand = standfront = true;
						//running = runForward = true;
					}
				}
			}
			if (level1characters){
				for (int i = 0; i < monsterNumber; i++)
				{
					if (monster_lvl1[i].monster_visible){
							monster_lvl1[i].x -= 10;
							monster_lvl1[i].mons_index++;
							if (monster_lvl1[i].x <= 0) monster_lvl1[i].x = screenWidth + rand() % 1500 ;
							if (monster_lvl1[i].mons_index >= 2)  monster_lvl1[i].mons_index = 0;
					}
					if (monster_lvl1[i].monster_visible == false){
						monster_lvl1[i].x = screenWidth + rand() % 1500;
						monster_lvl1[i].y = 110;
						monster_lvl1[i].monster_visible = true;
					}
				}
			}
		}
		else if (level == 2){
			if (jump){
				if (jumpUp){
					averyJump += 5;
					if (averyJump >= jumpLimit)
						jumpUp = false;
				}
				else{
					averyJump -= 5;
					if (averyJump < 0){
						jump = false;
						averyJump = 0;
						stand = standfront = true;
					}
				}
			}
			if (level2characters){
				for (int i = 0; i < obstacleNumber; i++)
				{
					obstacle[i].x -=10;
					if (obstacle[i].x < 0) obstacle[i].x = screenWidth + rand() % 7500;
					if (obstacle[i].obstacle_visible == false){
						obstacle[i].obstacle_visible = true;
						obstacle[i].x = screenWidth + rand() % 7500;
					}
				}
				for (int i = 0; i < monsterNumber2; i++)
				{
					if (monster_lvl2[i].monster_visible){
						monster_lvl2[i].x -= 10;
						monster_lvl2[i].mons_index++;
						if (monster_lvl2[i].x <= 0) monster_lvl2[i].x = screenWidth + rand() % 8000+rand()%5;
						if (monster_lvl2[i].mons_index >= 2)  monster_lvl2[i].mons_index = 0;
					}
					if (monster_lvl2[i].monster_visible == false){
						monster_lvl2[i].x = screenWidth + rand() % 10000+rand()%5;
						monster_lvl2[i].y = 110;
						monster_lvl2[i].monster_visible = true;
					}
				}
			}
		}
		else if (level == 3){
			if (jump){
				if (jumpUp){
					averyJump += 5;
					if (averyJump >= jumpLimit)
						jumpUp = false;
				}
				else{
					averyJump -= 5;
					if (averyJump < 0){
						jump = false;
						averyJump = 0;
						stand = standfront = true;
					}
				}
			}
		}
	}
}
void changeBackground()
{
	if (!pause){
		if (level == 1)
		{
			if (running){
				if (front){
					for (int i = 0; i < 15; i++)
					{
						background[i].x -= backgroundspeed;
						if (background[i].x < 0)
							background[i].x = screenWidth - 80;
					}
				}
				else if (back){
					for (int i = 0; i < 15; i++)
					{
						background[i].x += backgroundspeed;
						if (background[i].x >= screenWidth)
							background[i].x = 0;
					}
				}
			}
			
		}
		if (level == 2)
		{
			if (running){
				if (front){
					for (int i = 0; i < 15; i++)
					{
						background_level2[i].x -= backgroundspeed;
						if (background_level2[i].x < 0)
							background_level2[i].x = screenWidth - 80;
					}
				}
				else if (back){
					for (int i = 0; i < 15; i++)
					{
						background_level2[i].x += backgroundspeed;
						if (background_level2[i].x >= screenWidth)
							background_level2[i].x = 0;
					}
				}
			}

		}
	}
}
void bossFiring()
{
	if (!pause){
		if (bossfiring && bossvisible){
			for (int i = 0; i < 200; i++){
				bossfireX--;
				if (bossfireX <=10){
					bossfireX = 1065;
				}
				fire_index++;
				if (fire_index >= 2) fire_index = 0;
			}
			
		}
	}
}
void fire_star()
{
	if (!pause){
		if (firing&&front){
			for (int i = 0; i < 152; i++){
				fireX++;
				if (fireX>screenWidth){
					firing = false;
					if (level == 1)
						fireX = averyX + 10000000000000000000;
					else if (level == 2)
						fireX = averyX1 + 10000000000000000000;
					else if (level == 3)
						fireX = averyX2 + 10000000000000000000;
				}
			}
		}
		else if (firing &&back)
		{
			for (int i = 0; i < 152; i++){
				fireX--;
				if (fireX < 0){
					firing = false;
					if (level == 1)
						fireX = averyX + 10000000000000000000;
					else if (level == 2)
						fireX = averyX1 + 10000000000000000000;
					else if (level == 3)
						fireX = averyX2 + 10000000000000000000;
				}
			}
		}
	}
}
void level_end_logic()
{
	if (level == 1){
		if (enemyKilled ==35){
			enemyKilled = 0;
			level1characters = false;
			levelup = true;
		}
	}
	else if (level == 2){
		if (enemyKilled == 40){
			enemyKilled = 0;
			level2characters = false;
			car = true;
		}
	}
	else if (level == 3 && bossvisible == false&&averyVisible3==true)
		chestv = true;
}
///structure variable set(start)
void setMenu(){
	int sum = 0;
	for (int i = 4; i >= 0; i--)
	{
		menu_buttons[i].x = 70;
		menu_buttons[i].y = sum;
		sum += 100;
	}
}
void setMonster_level1()
{
	for (int i = 0; i < monsterNumber; i++)
	{
		monster_lvl1[i].x = screenWidth + rand() % 100000+rand()%1000;
		monster_lvl1[i].y = 110;
		monster_lvl1[i].mons_index =rand()%4;
		monster_lvl1[i].monster_visible = true;
	}
}
void setMonster_level2()
{
	for (int i = 0; i < monsterNumber2; i++)
	{
		monster_lvl2[i].x = screenWidth + rand() % 12000;
		monster_lvl2[i].y = 90;
		monster_lvl2[i].mons_index = rand()%4;
		monster_lvl2[i].monster_visible = true;
	}
}
void setObstacle(){
	for (int i = 0; i < obstacleNumber; i++){
		obstacle[i].x = screenWidth + rand() % 30000;
		obstacle[i].y = 90;
		obstacle[i].obstacle_visible = true;
	}
}
/*void setObstacle2(){
	for (int i = 0; i < obstacleNumber2; i++){
		obstacle2[i].x = screenWidth + rand() % 40000;
		obstacle2[i].y = 80;
		obstacle2[i].obstacle_visible = true;
	}
}*/
void setBackground_level1(){
	int sum = 0;
	for (int i = 0; i < 15; i++)
	{
		background[i].x = sum;
		background[i].y = 0;
		sum += 80;
	}
}
void setBackground_level2()
{
	int sum = 0;
	for (int i = 0; i < 15; i++)
	{
		background_level2[i].x = sum;
		background_level2[i].y = 0;
		sum += 80;
	}
}
void setBackground_level3()
{
	int sum = 0;
		background_level3.x = sum;
		background_level3.y = 0;
		sum += 150;
}
void set_power(){
	for(int i = 0; i < power; i++)
	{
		p[i].x = 500 + rand() % 12000;
		p[i].y = 200;
		p[i].power_visible = true;
	}
}
void resetGame(){
	setBackground_level1();
	setMonster_level1();
	setBackground_level2();
	setMonster_level2();
	setObstacle();
	///setObstacle2();
	setBackground_level3();
	level1characters = true;
	level2characters = false;
	level3characters = false;
	averyVisible = true;
	averyVisible2 = false;
	jump = false;
	life_index = 0;
	level = 1;
	lifebar_visible = true;
	averyX = 0;
	averyY = 110;
	averyX1 = 0;
	averyY1 = 90;
	averyX2 = 30;
	averyY2 = 80;
	enemyKilled = 0;
	killScore = 0;
	///if (pause == true) pause = false;
	standfront = true;
	standrev = false;
	bossfiring = false;
	bossvisible = false;
	//completegame = false;
	boss_index = 0;
	bossfireX = 1065;
    bossfireY = 106;
	pause = true;
}
void iPassiveMouse(int x, int y)
{
	;
}


/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		menu(mx, my);
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here

	}
}


/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
	if (key == '\b')
	{
		if (gameState == 3 || gameState == 2 || gameState == 1||gameState==0)gameState = -1;
		else if (gameOver){
			gameOver = false;
			gameState = -1;
			///pause = false;
		}
		else if (completegame == true){
			completegame = false;
			gameState = -1;
		}
	}
	else if (key == 'x' || key == 'X'){
		exit(0);
	}
	else if (key == 'm' || key == 'M')
	{
		if (musicOn)
		{
			musicOn = false;
			PlaySound(0, 0, 0);
		}
		else{
			musicOn = true;
			PlaySound("music\\bgm2.wav", NULL, SND_LOOP | SND_ASYNC);

		}
		
	}
	else if (key == 'p' || key == 'P')
	{
		if (!pause)
		{
			pause = true;
		}
		else{
			pause = false;
		}
	}
	else if (key == 'd' || key == 'D')
	{
		if (!pause)
		{
			running = true;
			runForward = true;
			runBackward = false;
			if (jump) runBackward = runForward = false;
			if (level == 1)
			{
				averyX += 5;
				if (averyX >= screenWidth)
					averyX = -5;
			}
			else if (level == 2)
			{
				averyX1 += 5;
				if (averyX1 >= screenWidth)
					averyX1 = -5;
			}
			else if (level == 3)
			{
				averyX2 += 5;
				if (averyX2 >= screenWidth)
					averyX2 = -5;
			}
			runIndex++;
			if (runIndex >= 5)
				runIndex = 0;
			stand =standrev=standfront= false;
			front = true; back = false;
		}
	}
	else if (key == 'a' || key == 'A')
	{
		if (!pause)
		{
			running = true;
			runForward = false;
			runBackward = true;
			if (jump) runBackward = runForward = false;
			if (level == 1)
			{
				averyX -= 5;
				if (averyX <= 0)
					averyX = 0;
			}
			else if (level == 2)
			{
				averyX1 -= 5;
				if (averyX1 <= 0)
					averyX1 = 0;
			}
			else if (level == 3)
			{
				averyX2 -= 5;
				if (averyX2 <= 30)
					averyX2 = 30;
			}
			runIndex++;
			if (runIndex >= 5)
				runIndex = 0;
			stand  =standrev=standfront= false;
			front = false; back = true;
		}
	}
	else if (key == ' ')
	{
		if (!pause){
			if (!jump){
				jumpUp = jump = true;
				runBackward = runForward = stand = standrev = standfront = false;
			}
		}
	
	}
	else if (key == 'l' || key == 'L')
	{
		if (!pause)
		{
			if (!firing)
			{
				firing = true;
				if (level == 1)
				{
					fireX = averyX+40;
					if (jump)
						fireY = averyY + averyJump + 25;
					else
						fireY = averyY+25;
				}
				else if (level == 2)
				{
					fireX = averyX1 + 40;
					if (jump)
						fireY = averyY1 + averyJump + 25;
					else
						fireY = averyY1 + 25;
				}
				else if (level == 3)
				{
					fireX = averyX2 + 40;
					if (jump)
						fireY = averyY2 + averyJump + 25;
					else
						fireY = averyY2 + 25;
				}
				star_index++;
				if (star_index >= 2) star_index = 0;
			}
		}
	}
}

/*
 function iSpecialKeyboard() is called whenver user hits special keys like-
 function keys, home, end, pg up, pg down, arraows etc. you have to use
 appropriate constants to detect them. A list is:
 GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
 GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
 GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
 GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
 */
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		
	}
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.
	setMenu();
	resetGame();
	if (musicOn)
	{
		PlaySound("music\\bgm2.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	t1 = iSetTimer(450, changeBackground);
	iSetTimer(50, change);
	iSetTimer(120, fire_star);
	iSetTimer(950, collisionCheck);
	iSetTimer(150, bosscollisioncheck);
	iSetTimer(50, starAndMonsterCollisionCheck);
	iSetTimer(2, level_end_logic);
	iSetTimer(160, bossFiring);
	iInitialize(screenWidth,screenHeight, projectName);
	iStart(); // it will start drawing
	return 0;
}

