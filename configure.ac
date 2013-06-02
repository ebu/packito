AC_PREREQ(2.60)
AC_INIT(packito, 1.0, dossantos@ebu.ch)
AC_CONFIG_AUX_DIR(config)

AM_INIT_AUTOMAKE([1.9.6 -W -Wall no-define foreign])

AC_PROG_CXX
AC_LANG_CPLUSPLUS
AC_PROG_MAKE_SET
AC_PROG_INSTALL
AC_PROG_LIBTOOL

PKG_CHECK_MODULES(GTKMM, [gtkmm-3.0 >= 3.0.0])
PKG_CHECK_MODULES(GDKMM, [gdkmm-3.0 >= 3.0.0])
AC_HEADER_STDC
AC_CHECK_HEADERS([ctime cstring cstdio cstdlib])
AC_OUTPUT(Makefile src/Makefile)