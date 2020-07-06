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

#include <memory>

#include "gtest/gtest.h"
#include "src/ast/assignment_statement.h"
#include "src/ast/float_literal.h"
#include "src/ast/identifier_expression.h"
#include "src/ast/kill_statement.h"
#include "src/ast/loop_statement.h"
#include "src/ast/return_statement.h"
#include "src/ast/type/f32_type.h"
#include "src/ast/variable.h"
#include "src/ast/variable_decl_statement.h"
#include "src/writer/msl/generator_impl.h"

namespace tint {
namespace writer {
namespace msl {
namespace {

using MslGeneratorImplTest = testing::Test;

TEST_F(MslGeneratorImplTest, Emit_Loop) {
  ast::StatementList body;
  body.push_back(std::make_unique<ast::KillStatement>());

  ast::LoopStatement l(std::move(body), {});

  GeneratorImpl g;
  g.increment_indent();

  ASSERT_TRUE(g.EmitStatement(&l)) << g.error();
  EXPECT_EQ(g.result(), R"(  for(;;) {
    discard_fragment();
  }
)");
}

TEST_F(MslGeneratorImplTest, Emit_LoopWithContinuing) {
  ast::StatementList body;
  body.push_back(std::make_unique<ast::KillStatement>());

  ast::StatementList continuing;
  continuing.push_back(std::make_unique<ast::ReturnStatement>());

  ast::LoopStatement l(std::move(body), std::move(continuing));

  GeneratorImpl g;
  g.increment_indent();

  ASSERT_TRUE(g.EmitStatement(&l)) << g.error();
  EXPECT_EQ(g.result(), R"(  {
    bool tint_msl_is_first_1 = true;
    for(;;) {
      if (!tint_msl_is_first_1) {
        return;
      }
      tint_msl_is_first_1 = false;

      discard_fragment();
    }
  }
)");
}

TEST_F(MslGeneratorImplTest, Emit_LoopNestedWithContinuing) {
  ast::type::F32Type f32;

  ast::StatementList body;
  body.push_back(std::make_unique<ast::KillStatement>());

  ast::StatementList continuing;
  continuing.push_back(std::make_unique<ast::ReturnStatement>());

  auto inner = std::make_unique<ast::LoopStatement>(std::move(body),
                                                    std::move(continuing));

  body.push_back(std::move(inner));

  auto lhs = std::make_unique<ast::IdentifierExpression>("lhs");
  auto rhs = std::make_unique<ast::IdentifierExpression>("rhs");
  continuing.push_back(std::make_unique<ast::AssignmentStatement>(
      std::move(lhs), std::move(rhs)));

  ast::LoopStatement outer(std::move(body), std::move(continuing));

  GeneratorImpl g;
  g.increment_indent();

  ASSERT_TRUE(g.EmitStatement(&outer)) << g.error();
  EXPECT_EQ(g.result(), R"(  {
    bool tint_msl_is_first_1 = true;
    for(;;) {
      if (!tint_msl_is_first_1) {
        lhs = rhs;
      }
      tint_msl_is_first_1 = false;

      {
        bool tint_msl_is_first_2 = true;
        for(;;) {
          if (!tint_msl_is_first_2) {
            return;
          }
          tint_msl_is_first_2 = false;

          discard_fragment();
        }
      }
    }
  }
)");
}

// TODO(dsinclair): Make this work when we have variable declarations.
TEST_F(MslGeneratorImplTest, DISABLED_Emit_LoopWithVarUsedInContinuing) {
  ast::type::F32Type f32;

  auto var = std::make_unique<ast::Variable>(
      "lhs", ast::StorageClass::kFunction, &f32);
  var->set_constructor(std::make_unique<ast::ScalarConstructorExpression>(
      std::make_unique<ast::FloatLiteral>(&f32, 2.4)));

  ast::StatementList body;
  body.push_back(std::make_unique<ast::VariableDeclStatement>(std::move(var)));
  body.push_back(std::make_unique<ast::VariableDeclStatement>(
      std::make_unique<ast::Variable>("other", ast::StorageClass::kFunction,
                                      &f32)));

  ast::StatementList continuing;
  auto lhs = std::make_unique<ast::IdentifierExpression>("lhs");
  auto rhs = std::make_unique<ast::IdentifierExpression>("rhs");
  continuing.push_back(std::make_unique<ast::AssignmentStatement>(
      std::move(lhs), std::move(rhs)));

  ast::LoopStatement outer(std::move(body), std::move(continuing));

  GeneratorImpl g;
  g.increment_indent();

  ASSERT_TRUE(g.EmitStatement(&outer)) << g.error();
  EXPECT_EQ(g.result(), R"(  {
    float lhs;
    bool tint_msl_is_first_1 = true;
    for(;;) {
      if (!tint_msl_is_first_1) {
        lhs = rhs;
      }
      tint_msl_is_first_1 = false;

      lhs = 2.4;
      float other;
    }
  }
)");
}
}  // namespace
}  // namespace msl
}  // namespace writer
}  // namespace tint