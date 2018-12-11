## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = project3

project3_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	offre.c offre.h \
	event.c event.h \
	seancee.c seancee.h \
	consultm.c consultm.h \
	consultc.c consultc.h

project3_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

