var<workgroup> arg_1 : vec3<i32>;

fn frexp_40fc9b() {
  var res : vec3<f32> = frexp(vec3<f32>(), &(arg_1));
}

[[stage(compute)]]
fn compute_main() {
  frexp_40fc9b();
}