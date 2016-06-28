// Copyright (c) 2010
// All rights reserved.

#ifndef ZETA_SERVER_HH
#define ZETA_SERVER_HH

#include <memory>
#include <string>

#include "Config.hh"
#include "air/MDataFile.hh"
#include "zebra/Service.hh"

namespace zeta {

class Server : public zebra::ServiceCallback {
 public:
  Server(int argc, char *argv[]);

  ~Server();

  virtual void onReceiveMarketData(
      const ftdc::MarketDataField*,
      const struct timeval&,
      const u_char* sp,
      uint32_t len);

 protected:
  air::SpeedMData* toSpeedMData(const std::string& instru,
                                const std::string& update_time,
                                int update_millisec);

 private:
  std::unique_ptr<Config> config_;
  std::unique_ptr<air::MDataFile> speed_file_;

  std::unique_ptr<zebra::Service> zebra_service_;
};

};  // namespace zeta

#endif
