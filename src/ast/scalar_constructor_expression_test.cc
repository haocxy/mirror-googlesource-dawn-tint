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

#include "src/ast/scalar_constructor_expression.h"

#include "src/ast/bool_literal.h"
#include "src/ast/test_helper.h"
#include "src/ast/type/bool_type.h"

namespace tint {
namespace ast {
namespace {

using ScalarConstructorExpressionTest = TestHelper;

TEST_F(ScalarConstructorExpressionTest, Creation) {
  type::Bool bool_type;
  auto* b = create<BoolLiteral>(&bool_type, true);
  ScalarConstructorExpression c(b);
  EXPECT_EQ(c.literal(), b);
}

TEST_F(ScalarConstructorExpressionTest, Creation_WithSource) {
  type::Bool bool_type;
  auto* b = create<BoolLiteral>(&bool_type, true);
  ScalarConstructorExpression c(Source{Source::Location{20, 2}}, b);
  auto src = c.source();
  EXPECT_EQ(src.range.begin.line, 20u);
  EXPECT_EQ(src.range.begin.column, 2u);
}

TEST_F(ScalarConstructorExpressionTest, IsValid) {
  type::Bool bool_type;
  auto* b = create<BoolLiteral>(&bool_type, true);
  ScalarConstructorExpression c(b);
  EXPECT_TRUE(c.IsValid());
}

TEST_F(ScalarConstructorExpressionTest, IsValid_MissingLiteral) {
  ScalarConstructorExpression c;
  EXPECT_FALSE(c.IsValid());
}

TEST_F(ScalarConstructorExpressionTest, ToStr) {
  type::Bool bool_type;
  auto* b = create<BoolLiteral>(&bool_type, true);
  ScalarConstructorExpression c(b);
  std::ostringstream out;
  c.to_str(out, 2);
  EXPECT_EQ(out.str(), R"(  ScalarConstructor[not set]{true}
)");
}

}  // namespace
}  // namespace ast
}  // namespace tint
