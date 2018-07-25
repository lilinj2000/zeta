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

#include <iomanip>
#include "src/m_datafile.h"
#include "soil/string.h"
#include "soil/json.h"
#include "soil/log.h"

namespace zeta {

void SpeedMData::writeToFile(std::ofstream* os) const {
  SOIL_FUNC_TRACE;

  soil::DateTime start_time(update_time);

  start_time += std::chrono::milliseconds(update_millisec);

  std::chrono::system_clock::duration delay = time_stamp - start_time;

  (*os) <<instru <<"\t"
        <<update_time <<"." <<std::setfill('0') <<std::setw(3)
        <<update_millisec <<"\t"
        <<start_time <<"\t"
        <<time_stamp <<"\t"
        <<delay.count() <<std::endl;
}

MDataFile::MDataFile(
    const std::string& file_name,
    const std::string& instrus_filter):
    soil::DataFile(file_name) {
  SOIL_FUNC_TRACE;

  soil::splitString(&instrus_filter_, instrus_filter);
}

MDataFile::~MDataFile() {
  SOIL_FUNC_TRACE;
}

bool MDataFile::filterData(std::shared_ptr<soil::Data> data) {
  SOIL_FUNC_TRACE;

  const MData* mdata
      = dynamic_cast<const MData*>(data.get());

  // SOIL_DEBUG_PRINT(instrus_filter_.size());

  if (instrus_filter_.empty()
      || instrus_filter_.count(
          mdata->instruID()) > 0) {
    return true;
  }

  return false;
}

// ShfeMData::ShfeMData(const std::string& md):
//     md_(md) {
//   rapidjson::Document doc;
//   doc.Parse(md_);

//   std::string key
//       = "/CThostFtdcDepthMarketDataField/InstrumentID";
//   soil::json::get_item_value(&instru_, doc, key);

//   return;
// }

};  // namespace zeta
