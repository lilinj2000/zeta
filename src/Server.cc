// Copyright (c) 2010
// All rights reserved.

#include "Server.hh"
#include "Log.hh"

namespace zeta {

Server::Server(int argc, char* argv[]) {
  ZETA_TRACE <<"Server::Server()";

  config_.reset(new Config(argc, argv));

  speed_file_.reset(
      new air::MDataFile(
          config_->zetaOptions()->speed_file,
          config_->zetaOptions()->instrus_filter));

  zebra_service_.reset(zebra::Service::createService(
      config_->zebraOptions(),
      config_->spyOptions(),
      this));
}

Server::~Server() {
  ZETA_TRACE <<"Server::~Server()";
}

void Server::onReceiveMarketData(
    const ftdc::MarketDataField* md,
    const struct timeval& ts,
    const u_char* sp,
    uint32_t len) {
  ZETA_TRACE <<"Server::onReceiveMarketData()";

  speed_file_->putData(
      toSpeedMData(md->updatetime_field.InstrumentID,
                   md->updatetime_field.UpdateTime,
                   md->updatetime_field.UpdateMillisec));
}

air::SpeedMData* Server::toSpeedMData(const std::string& instru,
                                          const std::string& update_time,
                                          int update_millisec) {
  std::unique_ptr<air::SpeedMData> speed_data(new air::SpeedMData());

  speed_data->instru = instru;
  speed_data->update_time = update_time;
  speed_data->update_millisec = update_millisec;

  return speed_data.release();
}

};  // namespace zeta
