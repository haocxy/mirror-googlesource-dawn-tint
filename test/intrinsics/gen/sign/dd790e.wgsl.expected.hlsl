struct tint_symbol {
  float4 value : SV_Position;
};

void sign_dd790e() {
  float res = sign(1.0f);
}

tint_symbol vertex_main() {
  sign_dd790e();
  const tint_symbol tint_symbol_1 = {float4(0.0f, 0.0f, 0.0f, 0.0f)};
  return tint_symbol_1;
}

void fragment_main() {
  sign_dd790e();
  return;
}

[numthreads(1, 1, 1)]
void compute_main() {
  sign_dd790e();
  return;
}
