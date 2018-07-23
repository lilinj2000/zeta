node=`uname -n`

home_3rd=~/3rd/${node}
home_libs=~/libs/${node}

boost_lib=$home_3rd/boost/lib
pcap_lib=$home_3rd/pcap/lib
fmt_lib=$home_3rd/fmt/lib
soil_lib=$home_libs/soil/lib
zebra_lib=$home_libs/zebra/lib
spy_lib=$home_libs/spy/lib

export LD_LIBRARY_PATH=$boost_lib:$pcap_lib:$fmt_lib:$soil_lib:$zebra_lib:$spy_lib


