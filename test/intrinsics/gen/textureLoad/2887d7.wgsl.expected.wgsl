[[group(1), binding(0)]] var arg_0 : texture_storage_1d<rgba32float, read>;

fn textureLoad_2887d7() {
  var res : vec4<f32> = textureLoad(arg_0, 1);
}

[[stage(vertex)]]
fn vertex_main() -> [[builtin(position)]] vec4<f32> {
  textureLoad_2887d7();
  return vec4<f32>();
}

[[stage(fragment)]]
fn fragment_main() {
  textureLoad_2887d7();
}

[[stage(compute)]]
fn compute_main() {
  textureLoad_2887d7();
}