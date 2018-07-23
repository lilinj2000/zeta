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


#ifndef SRC_M_DATAFILE_H_
#define SRC_M_DATAFILE_H_

#include <string>
#include <set>

#include "soil/data_file.h"
#include "soil/date_time.h"

namespace zeta {

class MDataFile;

typedef std::set<std::string> InstrusFilter;

class MData : public soil::Data {
 public:
  virtual const std::string& instruID() const = 0;
};

class SpeedMData : public MData {
 public:
  virtual const std::string& instruID() const {
    return instru;
  }

  virtual void writeToFile(std::ofstream* os) const;

  std::string instru;
  std::string update_time;
  int update_millisec;

  soil::DateTime time_stamp;
};

// class CffexMData : public MData {
//  public:
//   explicit CffexMData(const std::string& md);

//   virtual const std::string& instruID() const {
//     return InstrumentID;
//   }

//   virtual void writeToFile(std::ofstream* os) const {
//     (*os) <<md_ <<std::endl;
//   }

//  private:
//   std::string instru_;
//   std::string md_;
// };

// class ShfeMData : public MData {
//  public:
//   explicit ShfeMData(const std::string& md);

//   virtual const std::string& instruID() const {
//     return instru_;
//   }

//   virtual void writeToFile(std::ofstream* os) const {
//     (*os) <<md_ <<std::endl;
//   }

//  private:
//   std::string instru_;
//   std::string md_;
// };

class MDataFile : public soil::DataFile {
 public:
  MDataFile(const std::string& file_name,
            const std::string& instrus_filter = "");

  virtual ~MDataFile();

 protected:
  virtual bool filterData(const soil::Data* data);

 private:
  InstrusFilter instrus_filter_;
};

};  // namespace zeta

#endif
