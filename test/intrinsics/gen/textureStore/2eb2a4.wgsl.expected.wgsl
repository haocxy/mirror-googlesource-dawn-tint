[[group(1), binding(0)]] var arg_0 : texture_storage_1d<rgba16uint, write>;

fn textureStore_2eb2a4() {
  textureStore(arg_0, 1, vec4<u32>());
}

[[stage(vertex)]]
fn vertex_main() -> [[builtin(position)]] vec4<f32> {
  textureStore_2eb2a4();
  return vec4<f32>();
}

[[stage(fragment)]]
fn fragment_main() {
  textureStore_2eb2a4();
}

[[stage(compute)]]
fn compute_main() {
  textureStore_2eb2a4();
}