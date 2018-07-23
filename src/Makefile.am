AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = zeta
zeta_SOURCES = \
	options.cc \
	m_datafile.cc \
	server.cc \
	main.cc

zeta_CPPFLAGS = -I$(top_srcdir) \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(SPY_CPPFLAGS) \
		$(RAPIDJSON_CPPFLAGS) \
		$(FMT_CPPFLAGS) \
		$(SPDLOG_CPPFLAGS) \
		$(READERWRITERQUEUE_CPPFLAGS) \
		$(ARGS_CPPFLAGS) \
		$(ZEBRA_CPPFLAGS)


zeta_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(ZEBRA_LIBADD)


zeta_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = options.h \
	m_datafile.h \
	server.h

EXTRA_DIST = env.sh zeta.json

zetadir = $(bindir)
zeta_DATA = $(EXTRA_DIST)

