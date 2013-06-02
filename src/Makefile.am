bin_PROGRAMS =packito
packito_SOURCES = main.cpp packagerWindow.hpp packagerWindow.cpp packagerEngine.hpp packagerEngine.cpp genericFilechooserWindow.hpp genericFilechooserWindow.cpp genericFeatures.hpp genericFeatures.cpp genericAssistant.hpp genericAssistant.cpp genericAlertWindow.hpp genericAlertWindow.cpp

packito_CPPFLAGS = @GTKMM_CFLAGS@ @GDKMM_CFLAGS@
packito_LDADD = @GTKMM_LIBS@ @GDKMM_CFLAGS@
packito_CXXFLAGS = -std=c++11 -W -Wall
CLEANFILES = *~