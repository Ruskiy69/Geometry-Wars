#ifndef ENGINE_H
#define ENGINE_H

#include <cstdlib>
#include <ctime>

#include <sstream>
#include <list>

#include "SDL_Helper.h"
#include "Display.h"
#include "Events.h"
#include "Menus.h"
#include "Entity.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Level.h"
#include "Timer.h"
#include "ParticleEngine.h"

static const int PLAYER_SPEED   = 5;
static const double SHOT_ANGLE  = 10.0;
static int SHOT_COUNT           = 1;

typedef std::list<Enemy*>                   AllEnemies;
typedef std::list<Bullet*>                  AllBullets;
typedef std::vector<AllEnemies::iterator>   EnemyIterator;
typedef std::vector<AllBullets::iterator>   ShotIterator;

class Engine
{
public:
    Engine();
    ~Engine();

    void Play();

private:
    void Events();

    void AddEnemy();
    void Shoot();
    
    void CheckCollisions(std::vector<AllEnemies::iterator>& enemy_iters,
            std::vector<AllBullets::iterator>& shot_iters);
    void RemoveEnemies(std::vector<AllEnemies::iterator>& iters);
    void RemoveShots(std::vector<AllBullets::iterator>& iters);

    void ShowDebugInfo();
    void UpdateAll();

    Display*        Screen;
    Menu*           MainMenu;
    CPlayer*        Player;
    AllEnemies      Enemies;
    AllBullets      Shots;
    LevelManager*   Levels;
    ParticleEngine* Particles;
    Timer*          Fps;

    EnemyIterator   enemy_iters;
    ShotIterator    shot_iters;

    TTF_Font*       main_font;

    bool            quit;
    bool            debug;

    int             score;
};

#endif // ENGINE_H