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


#ifndef SRC_SERVER_H_
#define SRC_SERVER_H_

#include <memory>
#include <string>

#include "src/options.h"
#include "src/m_datafile.h"
#include "zebra/service.h"
#include "soil/json.h"

namespace zeta {

class Server : public zebra::ServiceCallback {
 public:
  explicit Server(const rapidjson::Document& doc);

  ~Server();

  virtual void onReceiveMarketData(
      const ftdc::MarketDataField*,
      const struct timeval&,
      const u_char* sp,
      uint32_t len);

 protected:
  std::shared_ptr<SpeedMData> toSpeedMData(
    const std::string& instru,
    const std::string& update_time,
    int update_millisec);

  // ShfeMData* toShfeMData(const ftdc::MarketDataField* md);

 private:
  std::unique_ptr<Options> options_;
  std::unique_ptr<MDataFile> speed_file_;
  // std::unique_ptr<MDataFile> md_file_;

  std::unique_ptr<zebra::Service> zebra_service_;
};

};  // namespace zeta

#endif
