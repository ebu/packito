AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4 --install 
SUBDIRS = src
EXTRA_DIST = autogen.sh
CLEANFILES = *~
pkgconfig_DATA = packito.pc
packito.pc: packito.pc.in
	cp packito.pc.in packito.pc
