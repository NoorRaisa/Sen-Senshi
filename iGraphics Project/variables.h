#ifndef VARIABLES_INCLUDED
#define VARIABLES_INCLUDED
#define screenWidth 1200
#define screenHeight 600
#define projectName "Sen Senshi"
#define backgroundspeed 80
#define backgroundspeed2 150
#define jumpLimit 110
#define obstacleNumber 15
#define obstacleNumber2 10
#define monsterNumber 25
#define monsterNumber2 20
#define power 15
int gameState = -1;
int highscore = 0;
int level = 1;
int t1, t2;
int averyX = 0;
int averyY = 110;
int averyX1 = 0;
int averyY1 = 90;
int averyX2 = 30;
int averyY2 = 80;
int averyJump = 0;
int runIndex = 0;
int stand_count = 0;
int stand_index = 0;
int life_index = 0;
int fireX = 0;
int fireY = 0;
int c = 0;
int enemyKilled = 0;
int killScore = 0;
bool level1characters = true;
bool musicOn = true;
bool pause = true;
bool front = false, back = false;
bool jump = false, jumpUp = false, jumpDown = false;
bool stand = true, standfront = true, standrev = false, running = false, runForward = false, runBackward = false;
bool lifebar_visible = true;
bool firing = false;
bool level2characters = false;
bool level3characters = false;
bool gameOver = false;
bool averyVisible=true;
bool averyVisible2 = false;
bool averyVisible3 = false;
bool levelup = false;
bool car = false;
bool bossfiring = false;
bool bossvisible = false;
int bossX = 1090;
int bossY = 80;
int boss_index = 0;
int bossfireX = 1065;
int bossfireY = 106;
int fire_index = 0;
int count1 = 0;
int count2 = 1;
bool completegame = false;
bool chestv = false;
char backgroundImage[15][40] = { "Image\\Background\\bg01.bmp", "Image\\Background\\bg02.bmp", "Image\\Background\\bg03.bmp",
"Image\\Background\\bg04.bmp", "Image\\Background\\bg05.bmp", "Image\\Background\\bg06.bmp", "Image\\Background\\bg07.bmp",
"Image\\Background\\bg08.bmp", "Image\\Background\\bg09.bmp", "Image\\Background\\bg10.bmp", "Image\\Background\\bg11.bmp",
"Image\\Background\\bg12.bmp", "Image\\Background\\bg13.bmp", "Image\\Background\\bg14.bmp", "Image\\Background\\bg15.bmp" };
char bg_lvl2[15][40] = { "Image\\level2\\bg1.bmp", "Image\\level2\\bg2.bmp", "Image\\level2\\bg3.bmp", "Image\\level2\\bg4.bmp",
"Image\\level2\\bg5.bmp", "Image\\level2\\bg6.bmp", "Image\\level2\\bg7.bmp", "Image\\level2\\bg8.bmp", "Image\\level2\\bg9.bmp",
"Image\\level2\\bg10.bmp", "Image\\level2\\bg11.bmp", "Image\\level2\\bg12.bmp", "Image\\level2\\bg13.bmp", "Image\\level2\\bg14.bmp",
"Image\\level2\\bg15.bmp" };
char background_lvl3[] = { "Image\\background3.bmp" };
char avery_run[6][40] = { "Image\\Avery\\run1.bmp", "Image\\Avery\\run2.bmp", "Image\\Avery\\run3.bmp",
"Image\\Avery\\run4.bmp", "Image\\Avery\\run5.bmp", "Image\\Avery\\run6.bmp" };
char run_rev[6][40] = { "Image\\Avery\\runrev1.bmp", "Image\\Avery\\runrev2.bmp", "Image\\Avery\\runrev3.bmp",
"Image\\Avery\\runrev4.bmp", "Image\\Avery\\runrev5.bmp", "Image\\Avery\\runrev6.bmp" };
char avery_stand[3][40] = { "Image\\Avery\\stand1.bmp", "Image\\Avery\\stand2.bmp", "Image\\Avery\\stand3.bmp" };
char stand_rev[3][40] = { "Image\\Avery\\standrev1.bmp", "Image\\Avery\\standrev2.bmp", "Image\\Avery\\standrev3.bmp" };
char avery_jump[2][40] = { "Image\\Avery\\jump1.bmp", "Image\\Avery\\jump3.bmp" };
char menubuttons[5][50] = { "Image\\Menu\\PLAY.bmp", "Image\\Menu\\ABOUT.bmp", "Image\\Menu\\HIGHSCORE.bmp",
"Image\\Menu\\CREDITS.bmp", "Image\\Menu\\EXIT.bmp" };
char lifebar[6][40] = { "Image\\Lifebar\\life01.bmp", "Image\\Lifebar\\life02.bmp", "Image\\Lifebar\\life03.bmp",
"Image\\Lifebar\\life04.bmp", "Image\\Lifebar\\life05.bmp", "Image\\Lifebar\\life06.bmp" };
char star[3][40] = { "Image\\shuriken2.bmp", "Image\\shuriken2.bmp", "Image\\shuriken2.bmp" };
char star2[3][40] = { "Image\\shuriken.bmp","Image\\shuriken.bmp" ,"Image\\shuriken.bmp"  };
char star3[3][40] = { "Image\\shuriken3.bmp","Image\\shuriken3.bmp","Image\\shuriken3.bmp" };
int star_index = 0;
char monster_run_level1[3][40] = { "Image\\monster1_run\\monster1.bmp", "Image\\monster1_run\\monster2.bmp",
"Image\\monster1_run\\monster3.bmp" };
char monster_attack_level1[2][40] = { "Image\\monster1_attack\\monster4.bmp", "Image\\monster1_attack\\monster5.bmp" };
char monster_run_level2[3][40] = { "Image\\monster_lvl2\\run1.bmp", "Image\\monster_lvl2\\run2.bmp", "Image\\monster_lvl2\\run3.bmp", };
char obs[] = { "Image\\obstacle2.bmp" };
char chest[] = { "Image\\chest.bmp" };
char levelUp[] = { "Image\\plane.bmp" };
char carimg[] = { "Image\\car.bmp" };
char box[] = { "Image\\box.bmp" };
char bosslifebar[8][40] = { "Image\\Lifebar\\bosslifebar01.bmp", "Image\\Lifebar\\bosslifebar02.bmp",
"Image\\Lifebar\\bosslifebar03.bmp", "Image\\Lifebar\\bosslifebar04.bmp", "Image\\Lifebar\\bosslifebar05.bmp",
"Image\\Lifebar\\bosslifebar06.bmp", "Image\\Lifebar\\bosslifebar07.bmp", "Image\\Lifebar\\bosslifebar08.bmp" };
char boss[] = { "Image\\boss2.bmp" };
char fire[3][40] = { "Image\\fire.bmp", "Image\\fire.bmp", "Image\\fire.bmp" };
#endif