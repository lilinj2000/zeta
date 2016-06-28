AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = zeta
zeta_SOURCES = \
	Config.cc \
	Server.cc \
	Main.cc

zeta_CPPFLAGS =  \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(SPY_CPPFLAGS) \
		$(ZEBRA_CPPFLAGS) \
		$(AIR_CPPFLAGS)


zeta_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(AIR_LIBADD) \
	$(ZEBRA_LIBADD)


zeta_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = Config.hh \
	Log.hh \
	Server.hh

EXTRA_DIST = env.sh zeta.cfg log.cfg

zetadir = $(bindir)
zeta_DATA = $(EXTRA_DIST)

