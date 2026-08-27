#include <raylib.h>
#include <string.h>

Color EMBERBG = { 28, 27, 25, 255 };
Color EMBER = { 224, 128, 96, 255 };

// constants.
#define WIDTH 900
#define HEIGHT 600
#define MAX_WAVES 50
#define WAVE_SPEED 50
#define OBJ_SPEED 0.6f
#define WAVE_FREQ 4

int current_waves = 0;

// structs.
struct Obj{
  float x, y;
};
struct SoundWave{
  float x, y, r;
};
struct Obj obj;
struct SoundWave waves[MAX_WAVES];

// protos.
void draw_obj();
void wave_emission();
void draw_waves();
void wave_propagation(float dt);

int main(){
  InitWindow(WIDTH, HEIGHT, "Doppler Sim");
  
  obj = (struct Obj){WIDTH/2, HEIGHT/2};

  SetTargetFPS(60);
  float interval = 0;
  wave_emission();
  while(!WindowShouldClose()){
    
    float dt = GetFrameTime();
    
    interval += dt;
    if(interval > 1.0f / WAVE_FREQ){
      wave_emission();
      interval = 0.0f;
    };
    wave_propagation(dt);
    
    if (IsKeyDown(KEY_RIGHT)) obj.x += OBJ_SPEED;
    if (IsKeyDown(KEY_LEFT)) obj.x -= OBJ_SPEED;
    if (IsKeyDown(KEY_UP)) obj.y -= OBJ_SPEED;
    if (IsKeyDown(KEY_DOWN)) obj.y += OBJ_SPEED;

    BeginDrawing();

    ClearBackground(EMBERBG);

    draw_obj();
    draw_waves();
    EndDrawing();
  }
  return 0;
}

void draw_obj(){
    DrawCircle(obj.x, obj.y, 20, EMBER);
}

void wave_emission(){
  struct SoundWave copy[MAX_WAVES];
  memset(copy, 0, MAX_WAVES * sizeof(struct SoundWave)); 

  for(int i = 0; i < current_waves; i++){
    copy[i] = waves[i];
  }

  for(int i = 0; i < current_waves; i++){
    if (i < MAX_WAVES - 1){
      waves[i + 1] = copy[i];
    }
  }

  waves[0] = (struct SoundWave){obj.x, obj.y, 0};
  if(current_waves < MAX_WAVES){
    current_waves++;
  }
}

void draw_waves(){
  for(int i = 0; i < current_waves; i++){
    DrawCircleLines(waves[i].x, waves[i].y, waves[i].r, EMBER);
  };
};

void wave_propagation(float dt){
  for(int i = 0; i < current_waves; i++){
    waves[i].r += WAVE_SPEED * dt;
  };
}
