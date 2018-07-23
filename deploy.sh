#! /bin/sh

node=`uname -n`
home_app=~/app/${node}

home_zeta=${home_app}/zeta

./configure --prefix=${home_zeta}

if test -d ${home_zeta}; then
    rm -rf ${home_zeta}
fi

make install

make distclean
