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

#include "src/ast/builder.h"

namespace tint {
namespace ast {

Builder::Builder() = default;

Builder::Builder(Context* ctx) : ctx_(ctx) {}

Builder::~Builder() = default;

std::unique_ptr<ast::Variable> Builder::make_var(const std::string& name,
                                                 ast::StorageClass storage,
                                                 ast::type::Type* type) {
  auto var = std::make_unique<ast::Variable>(name, storage, type);
  return var;
}

}  // namespace ast
}  // namespace tint