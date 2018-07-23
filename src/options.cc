// Copyright 2017 The Zeta Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// -----------------------------------------------------------------------------
// File: [file_name]
// -----------------------------------------------------------------------------
//
// [file_descrition]
//
// Example:
//
//   ... ...
//
//

#include "src/options.h"

namespace zeta {

using soil::json::get_item_value;

Options::Options(const rapidjson::Document& doc) {
  
  get_item_value(&instrus_filter, doc, "/zeta/instrus_filter");
  get_item_value(&speed_file, doc, "/zeta/speed_file");
  get_item_value(&md_file, doc, "/zeta/md_file", false);
  
  return;
}

Options::~Options() {
}

};  // namespace zeta
