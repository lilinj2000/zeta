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

#include "server.h"
#include "soil/log.h"

namespace zeta {

Server::Server(const rapidjson::Document& doc) {
  SOIL_FUNC_TRACE;

  options_.reset(new Options(doc));

  if (!options_->speed_file.empty()) {
    speed_file_.reset(
        new MDataFile(
            options_->speed_file,
            options_->instrus_filter));
  }

  // if (!config_->zetaOptions()->md_file.empty()) {
  //   md_file_.reset(
  //       new MDataFile(
  //           options_->md_file,
  //           options_->instrus_filter));
  // }

  zebra_service_.reset(zebra::Service::create(doc, this));
}

Server::~Server() {
  SOIL_FUNC_TRACE;
}

void Server::onReceiveMarketData(
    const ftdc::MarketDataField* md,
    const struct timeval& ts,
    const u_char* sp,
    uint32_t len) {
  SOIL_FUNC_TRACE;

  if (speed_file_.get()) {
    speed_file_->putData(
        toSpeedMData(md->updatetime_field.InstrumentID,
                     md->updatetime_field.UpdateTime,
                     md->updatetime_field.UpdateMillisec,
                     ts));
  }

//   if (md_file_.get()) {
//     md_file_->putData(toShfeMData(md));
//   }
}

std::shared_ptr<SpeedMData> Server::toSpeedMData(
  const std::string& instru,
  const std::string& update_time,
  int update_millisec,
  const struct timeval& ts) {
  std::shared_ptr<SpeedMData> speed_data(new SpeedMData());

  speed_data->instru = instru;
  speed_data->update_time = update_time;
  speed_data->update_millisec = update_millisec;

  speed_data->time_stamp = soil::DateTime(std::chrono::system_clock::from_time_t(ts.tv_sec));
  speed_data->time_stamp += std::chrono::microseconds(ts.tv_usec);

  return speed_data;
}

// ShfeMData* Server::toShfeMData(const ftdc::MarketDataField* md) {
//   std::unique_ptr<ShfeMData> shfe_data(new ShfeMData());

//   shfe_data->TradingDay = md->base_field.TradingDay;
//   shfe_data->PreSettlementPrice = md->base_field.PreSettlementPrice;
//   shfe_data->PreClosePrice = md->base_field.PreClosePrice;
//   shfe_data->PreOpenInterest = md->base_field.PreOpenInterest;
//   shfe_data->PreDelta = md->base_field.PreDelta;

//   shfe_data->InstrumentID = md->updatetime_field.InstrumentID;
//   shfe_data->UpdateTime = md->updatetime_field.UpdateTime;
//   shfe_data->UpdateMillisec = md->updatetime_field.UpdateMillisec;
//   shfe_data->ActionDay = md->updatetime_field.ActionDay;

//   shfe_data->OpenPrice = md->static_field.OpenPrice;
//   shfe_data->HighestPrice = md->static_field.HighestPrice;
//   shfe_data->LowestPrice = md->static_field.LowestPrice;
//   shfe_data->ClosePrice = md->static_field.ClosePrice;
//   shfe_data->UpperLimitPrice = md->static_field.UpperLimitPrice;
//   shfe_data->LowerLimitPrice = md->static_field.LowerLimitPrice;
//   shfe_data->SettlementPrice = md->static_field.SettlementPrice;
//   shfe_data->CurrDelta = md->static_field.CurrDelta;

//   shfe_data->LastPrice = md->lastmatch_field.LastPrice;
//   shfe_data->Volume = md->lastmatch_field.Volume;
//   shfe_data->Turnover = md->lastmatch_field.Turnover;
//   shfe_data->OpenInterest = md->lastmatch_field.OpenInterest;

//   shfe_data->BidPrice1 = md->bestprice_field.BidPrice1;
//   shfe_data->BidVolume1 = md->bestprice_field.BidVolume1;
//   shfe_data->AskPrice1 = md->bestprice_field.AskPrice1;
//   shfe_data->AskVolume1 = md->bestprice_field.AskVolume1;

//   shfe_data->BidPrice2 = md->bid23_field.BidPrice2;
//   shfe_data->BidVolume2 = md->bid23_field.BidVolume2;
//   shfe_data->BidPrice3 = md->bid23_field.BidPrice3;
//   shfe_data->BidVolume3 = md->bid23_field.BidVolume3;

//   shfe_data->BidPrice4 = md->bid45_field.BidPrice4;
//   shfe_data->BidVolume4 = md->bid45_field.BidVolume4;
//   shfe_data->BidPrice5 = md->bid45_field.BidPrice5;
//   shfe_data->BidVolume5 = md->bid45_field.BidVolume5;


//   shfe_data->AskPrice2 = md->ask23_field.AskPrice2;
//   shfe_data->AskVolume2 = md->ask23_field.AskVolume2;
//   shfe_data->AskPrice3 = md->ask23_field.AskPrice3;
//   shfe_data->AskVolume3 = md->ask23_field.AskVolume3;

//   shfe_data->AskPrice4 = md->ask45_field.AskPrice4;
//   shfe_data->AskVolume4 = md->ask45_field.AskVolume4;
//   shfe_data->AskPrice5 = md->ask45_field.AskPrice5;
//   shfe_data->AskVolume5 = md->ask45_field.AskVolume5;

//   return shfe_data.release();
// }
}  // namespace zeta
