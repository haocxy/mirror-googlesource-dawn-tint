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

#include "src/sem/vector_type.h"

#include "src/program_builder.h"

TINT_INSTANTIATE_TYPEINFO(tint::sem::Vector);

namespace tint {
namespace sem {

Vector::Vector(Type const* subtype, uint32_t width)
    : subtype_(subtype), width_(width) {
  TINT_ASSERT(Semantic, width_ > 1);
  TINT_ASSERT(Semantic, width_ < 5);
}

Vector::Vector(Vector&&) = default;

Vector::~Vector() = default;

std::string Vector::type_name() const {
  return "__vec_" + std::to_string(width_) + subtype_->type_name();
}

std::string Vector::FriendlyName(const SymbolTable& symbols) const {
  std::ostringstream out;
  out << "vec" << width_ << "<" << subtype_->FriendlyName(symbols) << ">";
  return out.str();
}

bool Vector::IsConstructible() const {
  return true;
}

uint32_t Vector::Size() const {
  return SizeOf(width_);
}

uint32_t Vector::Align() const {
  return AlignOf(width_);
}

uint32_t Vector::SizeOf(uint32_t width) {
  switch (width) {
    case 2:
      return 8;
    case 3:
      return 12;
    case 4:
      return 16;
  }
  return 0;  // Unreachable
}

uint32_t Vector::AlignOf(uint32_t width) {
  switch (width) {
    case 2:
      return 8;
    case 3:
      return 16;
    case 4:
      return 16;
  }
  return 0;  // Unreachable
}

}  // namespace sem
}  // namespace tint
