[[group(1), binding(0)]] var arg_0 : texture_storage_3d<rgba32sint, read>;

fn textureDimensions_8799ee() {
  var res : vec3<i32> = textureDimensions(arg_0);
}

[[stage(vertex)]]
fn vertex_main() -> [[builtin(position)]] vec4<f32> {
  textureDimensions_8799ee();
  return vec4<f32>();
}

[[stage(fragment)]]
fn fragment_main() {
  textureDimensions_8799ee();
}

[[stage(compute)]]
fn compute_main() {
  textureDimensions_8799ee();
}