cbuffer cbuffer_x_7 : register(b0, space0) {
  uint4 x_7[1];
};
cbuffer cbuffer_x_10 : register(b1, space0) {
  uint4 x_10[4];
};
static float4 gl_FragCoord = float4(0.0f, 0.0f, 0.0f, 0.0f);
static float4 x_GLF_color = float4(0.0f, 0.0f, 0.0f, 0.0f);

void main_1() {
  float4 data[2] = (float4[2])0;
  int b = 0;
  int y = 0;
  int i = 0;
  const uint scalar_offset = ((16u * uint(0))) / 4;
  const float x_42 = asfloat(x_7[scalar_offset / 4][scalar_offset % 4]);
  const uint scalar_offset_1 = ((16u * uint(0))) / 4;
  const float x_45 = asfloat(x_7[scalar_offset_1 / 4][scalar_offset_1 % 4]);
  const float4 tint_symbol_6[2] = {float4(x_42, x_42, x_42, x_42), float4(x_45, x_45, x_45, x_45)};
  data = tint_symbol_6;
  const int x_49 = asint(x_10[1].x);
  b = x_49;
  const float x_51 = gl_FragCoord.y;
  const int x_54 = asint(x_10[1].x);
  const float x_56 = gl_FragCoord.y;
  const int x_60 = asint(x_10[1].x);
  y = clamp(int(x_51), (x_54 | int(x_56)), x_60);
  const int x_63 = asint(x_10[1].x);
  i = x_63;
  while (true) {
    bool x_82 = false;
    bool x_83_phi = false;
    const int x_68 = i;
    const uint scalar_offset_2 = ((16u * uint(0))) / 4;
    const int x_70 = asint(x_10[scalar_offset_2 / 4][scalar_offset_2 % 4]);
    if ((x_68 < x_70)) {
    } else {
      break;
    }
    const int x_73 = b;
    const uint scalar_offset_3 = ((16u * uint(0))) / 4;
    const int x_75 = asint(x_10[scalar_offset_3 / 4][scalar_offset_3 % 4]);
    const bool x_76 = (x_73 > x_75);
    x_83_phi = x_76;
    if (x_76) {
      const int x_79 = y;
      const int x_81 = asint(x_10[1].x);
      x_82 = (x_79 > x_81);
      x_83_phi = x_82;
    }
    if (x_83_phi) {
      break;
    }
    b = (b + 1);
    {
      i = (i + 1);
    }
  }
  const int x_90 = b;
  const uint scalar_offset_4 = ((16u * uint(0))) / 4;
  const int x_92 = asint(x_10[scalar_offset_4 / 4][scalar_offset_4 % 4]);
  if ((x_90 == x_92)) {
    const int x_97 = asint(x_10[2].x);
    const int x_99 = asint(x_10[1].x);
    const int x_101 = asint(x_10[3].x);
    const int x_104 = asint(x_10[1].x);
    const int x_107 = asint(x_10[2].x);
    const int x_110 = asint(x_10[2].x);
    const int x_113 = asint(x_10[1].x);
    data[clamp(x_97, x_99, x_101)] = float4(float(x_104), float(x_107), float(x_110), float(x_113));
  }
  const int x_118 = asint(x_10[1].x);
  const float4 x_120 = data[x_118];
  x_GLF_color = float4(x_120.x, x_120.y, x_120.z, x_120.w);
  return;
}

struct main_out {
  float4 x_GLF_color_1;
};
struct tint_symbol_1 {
  float4 gl_FragCoord_param : SV_Position;
};
struct tint_symbol_2 {
  float4 x_GLF_color_1 : SV_Target0;
};

tint_symbol_2 main(tint_symbol_1 tint_symbol) {
  const float4 gl_FragCoord_param = tint_symbol.gl_FragCoord_param;
  gl_FragCoord = gl_FragCoord_param;
  main_1();
  const main_out tint_symbol_3 = {x_GLF_color};
  const tint_symbol_2 tint_symbol_7 = {tint_symbol_3.x_GLF_color_1};
  return tint_symbol_7;
}