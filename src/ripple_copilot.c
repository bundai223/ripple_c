/** Copilotで生成させてみたcode
 * 波紋のエフェクトをC言語で実装します。
 * 12x3
 * の配列をピクセルの並びにみたてて、波紋のそれぞれの座標での高さを0.0〜1.0で計算する関数を実装してください
 *
 * あとだしで・・・
 * 波紋の発生源、波紋が発生してからのいままでの経過時間も引数で指定できる関数にしてください
 */

#include <math.h>
#include <stdio.h>

#define WIDTH 12
#define HEIGHT 3
#define PI 3.14159265358979323846

// 高さを計算する関数
double calculateHeight(int x, int y, double sourceX, double sourceY,
                       double elapsedTime) {
  double centerX = WIDTH / 2.0;
  double centerY = HEIGHT / 2.0;
  double distance =
      sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY));
  double maxDistance = sqrt(centerX * centerX + centerY * centerY);
  double normalizedDistance = distance / maxDistance;

  // 波紋の速度と周期を設定
  double waveSpeed = 1.0;  // 1.0 ピクセル/秒
  double wavePeriod = 2.0; // 2.0 秒

  // 経過時間に応じて高さを計算
  double phase = 2.0 * PI * elapsedTime / wavePeriod;
  double height = 0.5 * (1.0 - cos(phase)) * exp(-normalizedDistance) *
                  sin(waveSpeed * elapsedTime);

  return height;
}

int main() {
  double sourceX = 6.0;     // 発生源のX座標
  double sourceY = 1.0;     // 発生源のY座標
  double elapsedTime = 1.0; // 経過時間（秒）

  for (int y = 0; y < HEIGHT; ++y) {
    for (int x = 0; x < WIDTH; ++x) {
      double height = calculateHeight(x, y, sourceX, sourceY, elapsedTime);
      printf("%.2f ", height);
    }
    printf("\n");
  }
  return 0;
}
