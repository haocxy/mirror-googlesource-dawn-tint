struct tint_symbol {
  float4 value : SV_Position;
};

void pow_4a46c9() {
  float3 res = pow(float3(0.0f, 0.0f, 0.0f), float3(0.0f, 0.0f, 0.0f));
}

tint_symbol vertex_main() {
  pow_4a46c9();
  const tint_symbol tint_symbol_1 = {float4(0.0f, 0.0f, 0.0f, 0.0f)};
  return tint_symbol_1;
}

void fragment_main() {
  pow_4a46c9();
  return;
}

[numthreads(1, 1, 1)]
void compute_main() {
  pow_4a46c9();
  return;
}
