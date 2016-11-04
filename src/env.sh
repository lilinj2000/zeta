home_3rd=~/3rd
home_libs=~/libs

boost_lib=$home_3rd/boost/lib
pcap_lib=$home_3rd/pcap/lib
air_lib=$home_libs/air/lib
soil_lib=$home_libs/soil/lib
zebra_lib=$home_libs/zebra/lib
spy_lib=$home_libs/spy/lib
json_lib=$home_libs/json/lib

export LD_LIBRARY_PATH=$boost_lib:$pcap_lib:$air_lib:$soil_lib:$zebra_lib:$spy_lib:$json_lib


