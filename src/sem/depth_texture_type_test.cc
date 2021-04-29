// Copyright 2020 The Tint Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "src/sem/depth_texture_type.h"

#include "src/sem/test_helper.h"

#include "src/sem/access_control_type.h"
#include "src/sem/external_texture_type.h"
#include "src/sem/sampled_texture_type.h"
#include "src/sem/storage_texture_type.h"

namespace tint {
namespace sem {
namespace {

using DepthTextureTest = TestHelper;

TEST_F(DepthTextureTest, Is) {
  DepthTexture d(ast::TextureDimension::kCube);
  Type* ty = &d;
  EXPECT_FALSE(ty->Is<AccessControl>());
  EXPECT_FALSE(ty->Is<Alias>());
  EXPECT_FALSE(ty->Is<ArrayType>());
  EXPECT_FALSE(ty->Is<Bool>());
  EXPECT_FALSE(ty->Is<F32>());
  EXPECT_FALSE(ty->Is<I32>());
  EXPECT_FALSE(ty->Is<Matrix>());
  EXPECT_FALSE(ty->Is<Pointer>());
  EXPECT_FALSE(ty->Is<Sampler>());
  EXPECT_FALSE(ty->Is<StructType>());
  EXPECT_TRUE(ty->Is<Texture>());
  EXPECT_FALSE(ty->Is<U32>());
  EXPECT_FALSE(ty->Is<Vector>());
}

TEST_F(DepthTextureTest, IsTexture) {
  DepthTexture d(ast::TextureDimension::kCube);
  Texture* ty = &d;
  EXPECT_TRUE(ty->Is<DepthTexture>());
  EXPECT_FALSE(ty->Is<ExternalTexture>());
  EXPECT_FALSE(ty->Is<SampledTexture>());
  EXPECT_FALSE(ty->Is<StorageTexture>());
}

TEST_F(DepthTextureTest, Dim) {
  DepthTexture d(ast::TextureDimension::kCube);
  EXPECT_EQ(d.dim(), ast::TextureDimension::kCube);
}

TEST_F(DepthTextureTest, TypeName) {
  DepthTexture d(ast::TextureDimension::kCube);
  EXPECT_EQ(d.type_name(), "__depth_texture_cube");
}

TEST_F(DepthTextureTest, FriendlyName) {
  DepthTexture d(ast::TextureDimension::kCube);
  EXPECT_EQ(d.FriendlyName(Symbols()), "texture_depth_cube");
}

}  // namespace
}  // namespace sem
}  // namespace tint