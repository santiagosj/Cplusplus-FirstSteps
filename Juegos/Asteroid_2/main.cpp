#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>

using namespace sf;

//dimensiones del tablero
const int W = 1200;
const int H = 800;

float DEGTORAD = 0.017453f; //?

//clase para las animaciones
class Animation
{
public:
  float Frame, speed;
  Sprite sprite;
    std::vector<IntRect> frames;

    //construcltor
    Animation(){}

    Animation(Texture &t, int x, int y, int w, int h, int count, float Speed)
    {
      Frame = 0;
        speed = Speed;


    for(int i=0;i<count;i++)
        frames.push_back(IntRect(x+i*w, y, w, h) );

    sprite.setTexture(t);
    sprite.setOrigin(w/2,h/2);
       sprite.setTextureRect(frames[0]);
    }

    void update(){
      Frame+=speed;
      int n = frames.size();
      if(Frame >= n)Frame -= n;
      if(n>0) sprite.setTextureRect(frames[int(Frame)]);
    }

    bool isEnd(){
      return Frame+speed>=frames.size();
    }
};

//clase entidad para definir rasgos generales de los distintos objetos que interactuan en el juego

class Entity{
public:
  float x,y,dx, dy, R, angulo;
  bool vida;
  std::string nombre;
  Animation anim;

  //constructor
  Entity(){
    life=1;
  }

  void settings(Animation &a, int X,int Y,float Angle¨= 0,int radius=1){
    anim = a;
    x=X; y=Y;
    angle=Angle;
    R = radius;
  }


virtual void update(){};//comportamiento definido por update en Animation

void draw(RenderWindow &app){
  anim.sprite.setPosition(x,y);
  anim.sprite.setRotation(angulo + 90);
  app.draw(anim.sprite);

  CircleShape circle(R);
  circle.setFillColor(Color(255,0,0,170));
  circle.setPosition(x,y);
  circle.setOrigin(R,R);
 }

 virtual ~Entity(){};//destructor
};

class asteroide: public Entity
{
public:
  asteroide()
  {
    dx=rand()%8-4;
    dy=rand()%8-4;
    nombre="asteroide";
  }

  void update(){
    x+=dx;
    y+=dy;

    if (x>W) x=0;  if (x<0) x=W;
    if (y>H) y=0;  if (y<0) y=H;
  }
};

class bala:public Entity{
public:
  bala(){
    nombre="bala";
  }
  void update(){
    dx=cos(angulo*DEGTORAD)*6;
    dy=sin(angulo*DEGTORAD)*6;

    x+=dx;
    y+=dy;

    if (x>W || x<0 || y>H || y<0) life=0;
  }
};

class jugador: public Entity{
public:
  bool impulso;

  jugador(){
    nombre="jugador";
  }

  void update(){
    if (impulso) {
      dx+=cos(angulo*DEGTORAD)*0.2;
      dy+=sin(angulo*DEGTORAD)*0.2;
    }else{
      dx*=0.99;
      dy*=0.99;
    }

    int vel_max = 15;
    float speed = sqrt(dx*dx+dy*dy);
    if(speed > vel_max){
      dx *= vel_max/speed;
      dy *= vel_max/speed;
    }
     x+=dx;
     y+=dy;

     if (x>W) x=0; if (x<0) x=W;
     if (y>H) y=0; if (y<0) y=H;
  }
};

bool choque(Entity *a, Entity *b){
  return (b->x - a->x)*(b->x - a->x)+
         (b->y - a->y)*(b->y - a->y)<
         (a->R + b->R)*(a->R + b->R);
}

int main() {
  srand(time(0));

  RenderWindow app(VideoMode(W, H), "Asteroids!");
  app.setFramerateLimit(60);

  Texture t1,t2,t3,t4,t5,t6,t7;
  t1.loadFromFile("images/spaceship.png");
  t2.loadFromFile("images/background.jpg");
  t3.loadFromFile("images/explosions/type_C.png");
  t4.loadFromFile("images/rock.png");
  t5.loadFromFile("images/fire_blue.png");
  t6.loadFromFile("images/rock_small.png");
  t7.loadFromFile("images/explosions/type_B.png");

  t1.setSmooth(true);
  t2.setSmooth(true);

  Sprite background(t2);

  Animation sExplosion(t3, 0,0,256,256, 48, 0.5);
  Animation sRock(t4, 0,0,64,64, 16, 0.2);
  Animation sRock_small(t6, 0,0,64,64, 16, 0.2);
  Animation sBullet(t5, 0,0,32,64, 16, 0.8);
  Animation sPlayer(t1, 40,0,40,40, 1, 0);
  Animation sPlayer_go(t1, 40,40,40,40, 1, 0);
  Animation sExplosion_ship(t7, 0,0,192,192, 64, 0.5);

  std::list<Entity*> entities;

  for (int i = 0; i < 15; i++) {
    asteroide *a = new asteroide();
    a->settings(sRock, rand()%W, rand()%H, rand()%360, 25);
    entities.push_back(a);
  }

  jugador *j = new jugador();
  j->settings(sPlayer, 200,200,0,20);
  entities.push_back(j);

  //rutina principal del juego

   while(app.isOpen()){
     Event event;
     while(app.pollEvent(event)){
       if(event.type == Event::Closed)
          app.close();

          //escucha el evento de teclado dispara con la barra espaciadora

       if(event.type == Event::KeyPressed)
        if(event.key.code == Keyboard::Space){
          bala *b = new bala();
          b->settings(sBullet,j->x,j->y,j->angulo,10);
          entities.push_back(b);
        }
     }
         //movimiento con las flechas

      if (Keyboard::isKeyPressed(Keyboard::Right)) j->angulo+=3;
      if (Keyboard::isKeyPressed(Keyboard::Left))j->angulo+=3;
      if (Keyboard::isKeyPressed(Keyboard::Up))j->impulso+=true;
      else j->impulso=false;

      //detecta colisiones entre bala y asteroide

      for(auto a:entities)
        for(auto b:entities){
          if (a->nombre="asteroide" && b->nombre=="bala")
            if (choque(a,b)){
               a->vida=false;
               b->vida=false;

               Entity *e = new Entity();
               e->settings(sExplosion,a->x,a->y);
               e->nombre="explosion";
               entities.push_back(e);

               for(int i=0;i<2;i++)
               {
                 if(a->R==15) continue;
                 Entity *e = new asteroide();
                 e->settings(sRock_small,a->x,a->y,rand()%360,15);
                 entities.push_back(e);
               }
            }
                 //colision entre la nave y el asteroide

              if(a->nombre=="jugador" && b->nombre=="asteroide")
                if(choque(a,b))
                {
                  b->vida=false;

                  Entity *e = new Entity();
                  e->settings(sExplosion_ship,a->x,a->y);
                  e->nombre="explosion";
                  entities.push_back(e);

                  j->settings(sPlayer,W/2,H/2,0,20);
                  j->dx=0;j->dy=0;
                }

        }

        if(j->impulso) j->anim = sPlayer_go;
        else   j->anim = sPlayer;

        for(auto e:entities)
         if(e->nombre="explosion")
          if(e->anim.isEnd()) e->vida=0;

        if(rand()%150==0)
        {
          asteroide *a = new asteroide();
          a->settings(sRock, 0,rand()%H, rand()%360, 25);
          entities.push_back(a);
        }

        for(auto i = entities.begin();i != entities.end();)
        {
          Entity *e = *i;

          e->update();
          e->anim.update();

          if(e->vida==false){
            i = entities.erase(i);
            delete e;
          }else i++;
        }

        app.draw(background);

        for(auto i:entities)
         i->draw(app);

        app.display();
    }

  return 0;
}
