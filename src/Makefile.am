bin_PROGRAMS =packito
packito_SOURCES = main.cpp packagerWindow.hpp packagerEngine.hpp genericFilechooserWindow.hpp genericFeatures.hpp genericAssistant.hpp genericAlertWindow.hpp packagerWindow.cpp packagerEngine.cpp genericFilechooserWindow.cpp genericFeatures.cpp genericAssistant.cpp genericAlertWindow.cpp

packito_CPPFLAGS = @GTKMM30_CFLAGS@ @GDKMM30_CFLAGS@
packito_LDADD = @GTKMM30_LIBS@ @GDKMM30_LIBS@
packito_CXXFLAGS = -std=c++11 -W -pthread
CLEANFILES = *~