struct buf0 {
  float2 resolution;
};

static float4 gl_FragCoord = float4(0.0f, 0.0f, 0.0f, 0.0f);
cbuffer cbuffer_x_6 : register(b0, space0) {
  uint4 x_6[1];
};
static float4 x_GLF_color = float4(0.0f, 0.0f, 0.0f, 0.0f);

void main_1() {
  int x_195[256] = (int[256])0;
  int x_196[256] = (int[256])0;
  int x_197[256] = (int[256])0;
  float2 x_208 = float2(0.0f, 0.0f);
  int2 x_214 = int2(0, 0);
  float4 x_249 = float4(0.0f, 0.0f, 0.0f, 0.0f);
  float4 x_251 = float4(0.0f, 0.0f, 0.0f, 0.0f);
  int2 x_218_phi = int2(0, 0);
  float4 x_251_phi = float4(0.0f, 0.0f, 0.0f, 0.0f);
  bool x_252_phi = false;
  float4 x_254_phi = float4(0.0f, 0.0f, 0.0f, 0.0f);
  const float4 x_198 = gl_FragCoord;
  const float2 x_201 = asfloat(x_6[0].xy);
  const float2 x_202 = (float2(x_198.x, x_198.y) / x_201);
  const int x_204 = -(82);
  x_208 = float2(0.0f, float4(x_201, 15.0f, 15.0f).z);
  const int x_209 = (120 - 0);
  x_214 = int2(int((x_202.x * 256.0f)), int((x_202.y * 256.0f)));
  switch(0u) {
    default: {
      x_218_phi = x_214;
      while (true) {
        bool x_235 = false;
        bool x_236_phi = false;
        const int2 x_218 = x_218_phi;
        const int x_221 = x_218.y;
        x_251_phi = float4(0.0f, 0.0f, 0.0f, 0.0f);
        x_252_phi = false;
        if ((x_221 != 256)) {
        } else {
          break;
        }
        const int x_225 = x_218.x;
        const int tint_symbol_5[256] = {115, 133, 150, 164, 176, 184, 190, 192, 191, 187, 181, 172, 163, 153, 143, 134, 126, 120, 116, 114, 114, 117, 121, 127, 134, 141, 148, 154, 159, 162, 163, 161, 157, 151, 143, 134, 124, 113, 103, 94, 87, 82, 79, 80, 84, 91, 101, 114, 130, 146, 164, 182, 199, 215, 229, 240, 249, 254, 256, 254, 250, 243, 233, 223, 212, 200, 190, 180, 172, 166, 163, 161, 162, 164, 169, 174, 179, 185, 190, 193, 195, 195, 192, 188, 180, 171, 161, 149, 137, 125, 114, 105, 97, 93, 91, 93, 98, 106, 117, 130, 145, 161, 177, 193, 208, 221, 231, 239, 243, 244, 242, 236, 228, 218, 207, 194, 181, 169, 158, 148, 141, 135, 132, 131, 132, 135, 138, 143, 147, 151, 154, 155, 155, 152, 146, 139, 129, 118, 106, 93, 80, 68, 58, 49, 43, 40, 41, 44, 51, 61, 73, 87, 103, 119, 134, 149, 162, 173, 181, 186, 188, 186, 181, 174, 164, 153, 141, 128, 116, 104, 94, 86, 81, 77, 76, 77, 80, 84, 89, 94, 98, 102, 104, 104, 102, 98, 92, 83, 73, 62, 50, 38, 26, 16, 8, 2, 0, 0, 4, 11, 21, 33, 48, 64, 81, 98, 114, 129, 141, 151, 158, 161, 161, 158, 152, 144, 134, 123, 112, 100, 90, 81, 73, 68, 65, 65, 67, 70, 75, 81, 87, 92, 97, 101, 103, 102, 100, 95, 88, 79, 69, 58, 47, 36, 26, 18, 13, 11, 11, 15, 22, 32, 45, 60, 77, 94};
        x_195 = tint_symbol_5;
        const int x_227 = x_195[x_221];
        const bool x_229 = (x_225 < (x_227 + 15));
        x_236_phi = x_229;
        if (x_229) {
          const int tint_symbol_6[256] = {115, 133, 150, 164, 176, 184, 190, 192, 191, 187, 181, 172, 163, 153, 143, 134, 126, 120, 116, 114, 114, 117, 121, 127, 134, 141, 148, 154, 159, 162, 163, 161, 157, 151, 143, 134, 124, 113, 103, 94, 87, 82, 79, 80, 84, 91, 101, 114, 130, 146, 164, 182, 199, 215, 229, 240, 249, 254, 256, 254, 250, 243, 233, 223, 212, 200, 190, 180, 172, 166, 163, 161, 162, 164, 169, 174, 179, 185, 190, 193, 195, 195, 192, 188, 180, 171, 161, 149, 137, 125, 114, 105, 97, 93, 91, 93, 98, 106, 117, 130, 145, 161, 177, 193, 208, 221, 231, 239, 243, 244, 242, 236, 228, 218, 207, 194, 181, 169, 158, 148, 141, 135, 132, 131, 132, 135, 138, 143, 147, 151, 154, 155, 155, 152, 146, 139, 129, 118, 106, 93, 80, 68, 58, 49, 43, 40, 41, 44, 51, 61, 73, 87, 103, 119, 134, 149, 162, 173, 181, 186, 188, 186, 181, 174, 164, 153, 141, 128, 116, 104, 94, 86, 81, 77, 76, 77, 80, 84, 89, 94, 98, 102, 104, 104, 102, 98, 92, 83, 73, 62, 50, 38, 26, 16, 8, 2, 0, 0, 4, 11, 21, 33, 48, 64, 81, 98, 114, 129, 141, 151, 158, 161, 161, 158, 152, 144, 134, 123, 112, 100, 90, 81, 73, 68, 65, 65, 67, 70, 75, 81, 87, 92, 97, 101, 103, 102, 100, 95, 88, 79, 69, 58, 47, 36, 26, 18, 13, 11, 11, 15, 22, 32, 45, 60, 77, 94};
          x_196 = tint_symbol_6;
          const int x_233 = x_196[x_221];
          x_235 = (x_225 > (x_233 - 15));
          x_236_phi = x_235;
        }
        if (x_236_phi) {
          const int tint_symbol_7[256] = {115, 133, 150, 164, 176, 184, 190, 192, 191, 187, 181, 172, 163, 153, 143, 134, 126, 120, 116, 114, 114, 117, 121, 127, 134, 141, 148, 154, 159, 162, 163, 161, 157, 151, 143, 134, 124, 113, 103, 94, 87, 82, 79, 80, 84, 91, 101, 114, 130, 146, 164, 182, 199, 215, 229, 240, 249, 254, 256, 254, 250, 243, 233, 223, 212, 200, 190, 180, 172, 166, 163, 161, 162, 164, 169, 174, 179, 185, 190, 193, 195, 195, 192, 188, 180, 171, 161, 149, 137, 125, 114, 105, 97, 93, 91, 93, 98, 106, 117, 130, 145, 161, 177, 193, 208, 221, 231, 239, 243, 244, 242, 236, 228, 218, 207, 194, 181, 169, 158, 148, 141, 135, 132, 131, 132, 135, 138, 143, 147, 151, 154, 155, 155, 152, 146, 139, 129, 118, 106, 93, 80, 68, 58, 49, 43, 40, 41, 44, 51, 61, 73, 87, 103, 119, 134, 149, 162, 173, 181, 186, 188, 186, 181, 174, 164, 153, 141, 128, 116, 104, 94, 86, 81, 77, 76, 77, 80, 84, 89, 94, 98, 102, 104, 104, 102, 98, 92, 83, 73, 62, 50, 38, 26, 16, 8, 2, 0, 0, 4, 11, 21, 33, 48, 64, 81, 98, 114, 129, 141, 151, 158, 161, 161, 158, 152, 144, 134, 123, 112, 100, 90, 81, 73, 68, 65, 65, 67, 70, 75, 81, 87, 92, 97, 101, 103, 102, 100, 95, 88, 79, 69, 58, 47, 36, 26, 18, 13, 11, 11, 15, 22, 32, 45, 60, 77, 94};
          x_197 = tint_symbol_7;
          const int x_240 = x_197[x_221];
          const int x_244 = (91 + 244);
          const buf0 tint_symbol_8 = {x_208};
          const float x_248 = ((tint_symbol_8.resolution.y - abs(float((x_225 - x_240)))) * 0.06666667f);
          x_249 = float4(x_248, x_248, x_248, 1.0f);
          x_251_phi = x_249;
          x_252_phi = true;
          break;
        }
        int2 x_219_1 = x_218;
        x_219_1.y = (x_221 + 1);
        const int2 x_219 = x_219_1;
        {
          x_218_phi = x_219;
        }
      }
      x_251 = x_251_phi;
      const bool x_252 = x_252_phi;
      x_254_phi = x_251;
      if (x_252) {
        break;
      }
      x_254_phi = float4(0.0f, 0.0f, 0.0f, 1.0f);
      break;
    }
  }
  x_GLF_color = x_254_phi;
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
  const tint_symbol_2 tint_symbol_9 = {tint_symbol_3.x_GLF_color_1};
  return tint_symbol_9;
}