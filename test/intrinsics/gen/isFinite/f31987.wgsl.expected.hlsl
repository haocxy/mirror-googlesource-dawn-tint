struct tint_symbol {
  float4 value : SV_Position;
};

void isFinite_f31987() {
  vector<bool, 4> res = isfinite(float4(0.0f, 0.0f, 0.0f, 0.0f));
}

tint_symbol vertex_main() {
  isFinite_f31987();
  const tint_symbol tint_symbol_1 = {float4(0.0f, 0.0f, 0.0f, 0.0f)};
  return tint_symbol_1;
}

void fragment_main() {
  isFinite_f31987();
  return;
}

[numthreads(1, 1, 1)]
void compute_main() {
  isFinite_f31987();
  return;
}
