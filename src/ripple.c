#include <math.h>
#include <stdio.h>

#define X_CENTER 100   // x pixel position of center
#define Y_CENTER 100   // y pixel position of center
#define RADIUS 70      // approximate radius of circular wave train, in pixels
#define WAVELENGTH 10  // wavelength of ripples, in pixels
#define TRAINWIDTH 3.4 // approximate width of wave train, in wavelengths
#define SUPERPHASE 1.5 // phase vel. / group vel. (irrelevant for stills)

// returns a number from -1.0 to 1.0
double depth(int x, int y) {
  double dx = x - X_CENTER; // or int, if the center coords are ints
  double dy = y - Y_CENTER;
  double r = (sqrt(dx * dx + dy * dy) - RADIUS) / WAVELENGTH;
  double k = r - (1 - SUPERPHASE) * RADIUS / WAVELENGTH;
  double a = 1 / (1.0 + (r / TRAINWIDTH) * (r / TRAINWIDTH));
  return a * sin(k * 2 * M_PI);
}

static double field[12][3];

int main(void) {
  printf("%d\n", 10);
  return 0;
}
