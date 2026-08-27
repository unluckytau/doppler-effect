#include <stdio.h>
#include <raylib.h>

#define WIDTH 900
#define HEIGHT 600
#define MAX_WAVES 1000
#define WAVE_SPEED 15

int current_waves = 0;

struct Car{
  float x, y;
};

struct SoundWave{
  float x, y, r;
};

struct Car car;

struct SoundWave waves[MAX_WAVES];

void draw_car(){
    DrawCircle(car.x, car.y, 20, WHITE);
}

void emit_new_waves(){
  waves[0] = (struct SoundWave){WIDTH/2, HEIGHT/2, 0};
  current_waves++;
}

void draw_waves(){
  for(int i = 0; i < current_waves; i++){
    DrawCircleLines(waves[i].x, waves[i].y, waves[i].r, WHITE);
  };
};

void propogate_waves(float dt){
  for(int i = 0; i < current_waves; i++){
    waves[i].r += WAVE_SPEED * dt;
  };
}

int main(){
  InitWindow(WIDTH, HEIGHT, "Doppler Effect");
  
  car = (struct Car){WIDTH/2, HEIGHT/2};

  SetTargetFPS(60);
  emit_new_waves();
  while(!WindowShouldClose()){
    
    float dt = GetFrameTime();
    propogate_waves(dt);
    
    if (IsKeyDown(KEY_RIGHT)) car.x += 5;
    if (IsKeyDown(KEY_LEFT)) car.x -= 5;
    if (IsKeyDown(KEY_UP)) car.y -= 5;
    if (IsKeyDown(KEY_DOWN)) car.y += 5;

    BeginDrawing();

    // white circle (vehicle).
    ClearBackground(BLACK);

    draw_car();
    draw_waves();
    EndDrawing();
  }
  return 0;
}
