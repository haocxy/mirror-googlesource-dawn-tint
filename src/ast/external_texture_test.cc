// Copyright 2021 The Tint Authors.
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

#include "src/ast/external_texture.h"

#include "src/ast/access_control.h"
#include "src/ast/alias.h"
#include "src/ast/array.h"
#include "src/ast/bool.h"
#include "src/ast/depth_texture.h"
#include "src/ast/f32.h"
#include "src/ast/i32.h"
#include "src/ast/matrix.h"
#include "src/ast/pointer.h"
#include "src/ast/sampler.h"
#include "src/ast/storage_texture.h"
#include "src/ast/struct.h"
#include "src/ast/test_helper.h"
#include "src/ast/texture.h"
#include "src/ast/u32.h"
#include "src/ast/vector.h"

namespace tint {
namespace ast {
namespace {

using AstExternalTextureTest = TestHelper;

TEST_F(AstExternalTextureTest, Is) {
  Type* ty = create<ExternalTexture>();
  EXPECT_FALSE(ty->Is<AccessControl>());
  EXPECT_FALSE(ty->Is<Alias>());
  EXPECT_FALSE(ty->Is<Array>());
  EXPECT_FALSE(ty->Is<Bool>());
  EXPECT_FALSE(ty->Is<F32>());
  EXPECT_FALSE(ty->Is<I32>());
  EXPECT_FALSE(ty->Is<Matrix>());
  EXPECT_FALSE(ty->Is<Pointer>());
  EXPECT_FALSE(ty->Is<Sampler>());
  EXPECT_FALSE(ty->Is<Struct>());
  EXPECT_TRUE(ty->Is<Texture>());
  EXPECT_FALSE(ty->Is<U32>());
  EXPECT_FALSE(ty->Is<Vector>());
}

TEST_F(AstExternalTextureTest, IsTexture) {
  Texture* ty = create<ExternalTexture>();
  EXPECT_FALSE(ty->Is<DepthTexture>());
  EXPECT_TRUE(ty->Is<ExternalTexture>());
  EXPECT_FALSE(ty->Is<MultisampledTexture>());
  EXPECT_FALSE(ty->Is<SampledTexture>());
  EXPECT_FALSE(ty->Is<StorageTexture>());
}

TEST_F(AstExternalTextureTest, Dim) {
  auto* ty = create<ExternalTexture>();
  EXPECT_EQ(ty->dim(), ast::TextureDimension::k2d);
}

TEST_F(AstExternalTextureTest, TypeName) {
  auto* ty = create<ExternalTexture>();
  EXPECT_EQ(ty->type_name(), "__external_texture");
}

TEST_F(AstExternalTextureTest, FriendlyName) {
  auto* ty = create<ExternalTexture>();
  EXPECT_EQ(ty->FriendlyName(Symbols()), "texture_external");
}

}  // namespace
}  // namespace ast
}  // namespace tint