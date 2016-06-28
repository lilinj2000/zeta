// Copyright (c) 2010
// All rights reserved.

#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>

#include "Config.hh"
#include "Log.hh"
#include "zebra/Service.hh"
#include "spy/Service.hh"

namespace zeta {

Options::Options():
    config_options_("zetaConfigOptions") {
  namespace po = boost::program_options;

  config_options_.add_options()
      ("zeta.instrus_filter", po::value<std::string>(&instrus_filter),
       "instrument")
      ("zeta.speed_file", po::value<std::string>(&speed_file),
       "speed file")
      ("zeta.log_cfg", po::value<std::string>(&log_cfg),
         "log config file");
  return;
}

Options::~Options() {
}

po::options_description* Options::configOptions() {
  return &config_options_;
}

Config::Config(int argc, char* argv[]) {
  zeta_options_.reset(new Options());
  zebra_options_.reset(zebra::Service::createOptions());
  spy_options_.reset(spy::Service::createOptions());

  std::unique_ptr<soil::Config> config(soil::Config::create());
  config->registerOptions(zeta_options_.get());
  config->registerOptions(zebra_options_.get());
  config->registerOptions(spy_options_.get());

  config->configFile() = "zeta.cfg";
  config->loadConfig(argc, argv);

  // init the log
  ZETA_LOG_INIT(zeta_options_->log_cfg);

  return;
}

Config::~Config() {
}

};  // namespace zeta
