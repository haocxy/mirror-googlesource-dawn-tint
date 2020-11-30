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

#include "src/ast/type/texture_type.h"

#include <cassert>

#include "src/ast/type/multisampled_texture_type.h"
#include "src/ast/type/sampled_texture_type.h"

namespace tint {
namespace ast {
namespace type {

std::ostream& operator<<(std::ostream& out, TextureDimension dim) {
  switch (dim) {
    case TextureDimension::kNone:
      out << "None";
      break;
    case TextureDimension::k1d:
      out << "1d";
      break;
    case TextureDimension::k1dArray:
      out << "1d_array";
      break;
    case TextureDimension::k2d:
      out << "2d";
      break;
    case TextureDimension::k2dArray:
      out << "2d_array";
      break;
    case TextureDimension::k3d:
      out << "3d";
      break;
    case TextureDimension::kCube:
      out << "cube";
      break;
    case TextureDimension::kCubeArray:
      out << "cube_array";
      break;
  }
  return out;
}

Texture::Texture(TextureDimension dim) : dim_(dim) {}

Texture::Texture(Texture&&) = default;

Texture::~Texture() = default;

}  // namespace type
}  // namespace ast
}  // namespace tint
