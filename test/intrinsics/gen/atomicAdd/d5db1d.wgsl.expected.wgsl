var<workgroup> arg_0 : atomic<u32>;

fn atomicAdd_d5db1d() {
  var res : u32 = atomicAdd(&(arg_0), 1u);
}

[[stage(compute)]]
fn compute_main() {
  atomicAdd_d5db1d();
}