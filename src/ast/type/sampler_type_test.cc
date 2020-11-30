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

#include "src/ast/type/sampler_type.h"

#include "src/ast/test_helper.h"
#include "src/ast/type/access_control_type.h"

namespace tint {
namespace ast {
namespace type {
namespace {

using SamplerTypeTest = TestHelper;

TEST_F(SamplerTypeTest, Creation) {
  SamplerType s{SamplerKind::kSampler};
  EXPECT_EQ(s.kind(), SamplerKind::kSampler);
}

TEST_F(SamplerTypeTest, Creation_ComparisonSampler) {
  SamplerType s{SamplerKind::kComparisonSampler};
  EXPECT_EQ(s.kind(), SamplerKind::kComparisonSampler);
  EXPECT_TRUE(s.IsComparison());
}

TEST_F(SamplerTypeTest, Is) {
  SamplerType s{SamplerKind::kSampler};
  Type* ty = &s;
  EXPECT_FALSE(ty->Is<AccessControlType>());
  EXPECT_FALSE(ty->IsAlias());
  EXPECT_FALSE(ty->IsArray());
  EXPECT_FALSE(ty->IsBool());
  EXPECT_FALSE(ty->IsF32());
  EXPECT_FALSE(ty->IsI32());
  EXPECT_FALSE(ty->IsMatrix());
  EXPECT_FALSE(ty->IsPointer());
  EXPECT_TRUE(ty->IsSampler());
  EXPECT_FALSE(ty->IsStruct());
  EXPECT_FALSE(ty->IsTexture());
  EXPECT_FALSE(ty->IsU32());
  EXPECT_FALSE(ty->IsVector());
}

TEST_F(SamplerTypeTest, TypeName_Sampler) {
  SamplerType s{SamplerKind::kSampler};
  EXPECT_EQ(s.type_name(), "__sampler_sampler");
}

TEST_F(SamplerTypeTest, TypeName_Comparison) {
  SamplerType s{SamplerKind::kComparisonSampler};
  EXPECT_EQ(s.type_name(), "__sampler_comparison");
}

TEST_F(SamplerTypeTest, MinBufferBindingSize) {
  SamplerType s{SamplerKind::kSampler};
  EXPECT_EQ(0u, s.MinBufferBindingSize(MemoryLayout::kUniformBuffer));
}

}  // namespace
}  // namespace type
}  // namespace ast
}  // namespace tint
