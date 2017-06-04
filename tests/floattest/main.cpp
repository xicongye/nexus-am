#include <am.h>
#include <klib.h>
#include <fix16.h>

#define N 480

u32 colors[] = {
  0xff0000,
  0xeeb422,
  0xeeee00,
  0x76ee00,
  0x40e0d0,
  0x1e90ff,
  0x4b0082,
};

void print(Float f) {
  printf("%d.%04x\n", (u32)f.value >> 16, (u32)f.value & 0xffff);
}


void plot(Float(*f)(Float)) {
  static int col = 0;

  Float n = Float(N << 16);

  for (int i = 0; i < N; i ++) {
    Float x = Float(i << 16) / n;
    Float y = f(x) * n;
    int iy = (i16)((u32)y.value >> 16);

    if (iy >= -N && iy <= N) {
      iy = (iy + N) / 2;
      if (iy == N) iy --;
      _draw_p(i, N - iy, colors[col]);
    }
  }

  _draw_sync();
  col = (col + 1) % 7;
}

int main() {
  _ioe_init();
  // y = 2(x-1/2)
  plot( [](Float x) { return Float(2.0) * (x - Float(0.5)) ; } );
  // y = 1 / x
  plot( [](Float x) { return Float(0.1) / x; } );
  // y = 2 * x^2 - 1
  plot( [](Float x) { return Float(2.0) * x * x - Float(1.0); } );
  // y = sqrt(x)
  plot( [](Float x) { return (Float(2.0) * x.sqrt()) - 1.0; } );
  // y = sin(x * 2pi)
  plot( [](Float x) { 
    Float x1 = x * Float(3.1415 * 2);
    return x1.sin();
  } );
  // y = cos(x * 2pi)
  plot( [](Float x) { 
    Float x1 = x * Float(3.1415 * 2);
    return x1.cos();
  } );
  // y = asin(x) / (pi/2)
  plot( [](Float x) { 
    Float x1 = x;
    return x1.asin() / Float(3.1415 / 2);
  } );



  return 0;
}
