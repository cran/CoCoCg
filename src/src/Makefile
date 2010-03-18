
###############################################################################
###############################################################################
###                                                                         ###
###                       Configuration Parameters                          ###
###                                                                         ###
###############################################################################
###############################################################################
#
#  COCOHOME -- main directory for CoCo;
#  COCOTMP  -- directory for CoCo-tmp-files,
#              temporary files created when CoCo invoked;
#  BINDIR   -- directory for CoCo, xlisp+coco, R+coco and S+coco shell script;
#
# Do not change these 5 parameters:
#
#  COCOLIB  -- directory for CoCo executable, parser-table, help-file,
#              default data and shared libraries/DLL/object files for
#              R, S and XLISP-STAT;
#  RCOCOLIB -- former directory of the R+CoCo interface functions;
#  SCOCOLIB -- former directory of the S+CoCo interface functions;
# RSCOCOLIB -- directory of additional test-runs and examples (and 
#              source of interface functions) for R- and S+CoCo;
#  XCOCOLIB -- directory of XLISP-STAT-CoCo interface-functions .../lsp.
#
# Often you will only have to set COCOHOME (i.e. WIN_R_ROOT) !!!
#
# For the remaining parameters, if your machine has a subdirectory in the 
# machines directory, check the values given in the README file of your
# machine's directory. [ The files of the machine's directory are OLD. ]
# If you bring CoCo up on a machine not listed in the machines directory,
# please let me (JensHenrik.Badsberg@agrsci.dk) know your changes,
# so that I can add your machine for future releases.
#
# CC        -- usually cc,        the C compiler to use.
# LD        -- usually ld,        the command to link the objects.
# R         -- usually R,         the command to start R.
# S         -- usually Splus,     the command to start Splus.
# XLISPSTAT -- usually xlispstat, the command to start XLISP-STAT.
#
# Stand-alone executable:
#
# COCOEXE -- coco, the CoCo executable.
#
#
# Shared libraries (object files), without extension:
#
# RCSHLIB --  librcoco (or wXcoco): for R.         
# SCSHLIB --  scoco    (or wScoco): for Splus.     
# XCSHLIB --  libxcoco (or wRcoco): for XLISP-STAT:
#                     [    scoco.o for XLISP-STAT version 2.1 Release 2,    
#                      libxcoco.so for XLISP-STAT 2.1 Release 3.39 or later. ]
#
#
# Shared libraries (object files), with extension:
#
# RCOCO   -- librcoco.so  (or wXcoco.dll): for R.
# SCOCO   -- scoco.o      (or wScoco.dll): for Splus.
# XCOCO   -- libxcoco.so  (or wRcoco.dll): for XLISP-STAT:
#      [     scoco.o for XLISP-STAT version 2.1 Release 2,
#        libxcoco.so for XLISP-STAT 2.1 Release 3.39 or later. ]
#
# UCFLAGS -- C compiler flags, such as -O.
#            (The ``libxcoco.so'' file did not work with the -O option
#             on a Sun4 running Solaris.)
#
# ULDFLAGS -- additional flags for linking, flags for creating ${XCOCO},
#             empty for SunOS, -G -lc -lm for Solaris.
#
# EXTRALIBS -- any additional libraries, such as -ldl on some systems.
#
# IEEE_FLAG -- empty, or -DIEEEFP if `finite' and 'isnan' are available,
#              not used for the time being.

###############################################################################
# Select compiler, linker, R, S and XLISP-STAT, and give your locations of the
# home-directories of some of these programs:

# Distribution:

  CC          = gcc

  LD          = ld

  R           = R

  R_LIB_DIR   = ${R_LIBRARY_DIR}
  R_PAC_DIR   = ${R_PACKAGE_DIR}

  WIN_R_ROOT  = C:/Programmer/R/rw1081
  CYG_R_ROOT  = /cygdrive/c/Programmer/R/rw1081

  UNIX_R_HJEM = $(shell $R RHOME)
  UNIX_R_ROOT = `$R RHOME`

  S           = Splus5
  S_ROOT      = C:/Programmer/Insightful/splus61
# S_ROOT is only used for Windows / cygwin.

  XLISPSTAT   = xlispstat
  XLISP_ROOT  = C:/Programmer/Xlispstat
# XLISP_ROOT is only used for Windows / cygwin.


###############################################################################
# Select flags for compiler and linker:

 UCFLAGS   =

 ULDFLAGS  = -G -lc -lm

 EXTRALIBS =

 IEEE_FLAG = -DIEEEFP

#### 
###############################################################################
# Select CoCo directories:

# UWIN (only tested for standalone):

# LOADPREF = 
# COCOHOME = /C/lib/mips.1.5.Beta.R2
# BINDIR   = /C/lib/mips.1.5.Beta.R2/Bin
# COCOTMP  = C:\\TEMP\\
# WINHOME  = C:\\lib\\CoCo.1.5.Beta.R2\\


# (Do not end the lines with `/'.)

# Unix / Linux:

  LOADPREF    = 
  COCOHOME    = ${UNIX_R_ROOT}/library/CoCo
  COCOTMP     = ${COCOHOME}/tmp
  BINDIR      = ${COCOHOME}/bin


# Cygwin (Windows):

##LOADPREF    = C:/COMPILERS/Cygwin
##COCOHOME    = ${CYG_R_ROOT}/library/CoCo

# LOADPREF    = 
# COCOHOME    = ${WIN_R_ROOT}/library/CoCo
# COCOTMP     = ${COCOHOME}/tmp
# BINDIR      = ${COCOHOME}/bin


###############################################################################
# No need to edit:

  COCOLIB   = ${COCOHOME}/lib/mips
  COCOLIBS  = ${COCOHOME}/libs
  XCOCOLIB  = ${COCOHOME}/lsp
  SCOCOLIB  = ${COCOHOME}/R+S/S
  RCOCOLIB  = ${COCOHOME}/R+S/R
  RSCOCOLIB = ${COCOHOME}/R+S/R.and.S
  RStests   = ${COCOHOME}/R+S/tests

# Historically, COCOHOME is the home directory of CoCo, the root catalogue,
# COCOLIB is the directory of the executable, shared libraries and parser
# table, data-files, etc. of CoCo.
# RCOCOLIB, SCOCOLIB (RSCOCOLIB) and XCOCOLIB are directories with interface 
# functions to R, S and XlispStat respectively.
# Now, 2002, R wants a shared library called CoCoMips.dll/.so in ../libs.
# Pt. I make a copy of shared libraries in/to ../libs.
# LOADPREF is for Cygwin: If COCOHOME and COCOTMP are relative to the root 
# directory of Cygwin, then LOADPREF should be the location of the root of
# Cygwin relative to Windows.

#### 
###############################################################################
# Default action:

# UWIN:

# all: coco32.exe install.coco


#### - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ####

all: ./lib/mips/librcoco.so

unix.full: ./lib/mips/coco install.coco rsxdir \
	./lib/mips/scoco.o \
	./lib/mips/librcoco.so \
	install.Lisp  \
	install.R.and.S \
	./lib/mips/Xscoco.o ./lib/mips/Xlibrcoco.so \
	make.S.files make.R.files make.Lisp.files


#### - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ####

# Cygwin (Windows):

# all: wRcoco.dll

windows.full: coco.cygwin install.coco rsxdir \
	wRcoco.dll wScoco.dll wXcoco.dll \
	install.wXcoco \
	install.wScoco \
	XwRcoco.dll XwScoco.dll XwXcoco.dll \
	make.wS.files make.wR.files make.wLisp.files

cygwin.compile: ../src/coco_d_.c coco.cygwin wScoco.dll wRcoco.dll wXcoco.dll
cygwin.install: install.coco install.w.three install.wXcoco install.wScoco
cygwin: cygwin.compile cygwin.install

cygwin.Xcompile: wX-Scoco.dll wX-Rcoco.dll wX-Xcoco.dll

# all: cygwin.compile cygwin.Xcompile

#### 
###############################################################################
###############################################################################
###                                                                         ###
###                      DO NOT EDIT BELOW THIS LINE                        ###
###                                                                         ###
###############################################################################
###############################################################################

.SUFFIXES:	.c .p .o .so

# Distribution:

  CFLAGS    = ${UCFLAGS}

  LDFLAGS   = ${ULDFLAGS}

  LIBS      = ${EXTRALIBS} -lm

  SRC_RS_t  = ../src/R+S/tests
  SRC_RS    = ../src/R+S
  SRC_LSP   = ../src/lsp
#  SRC_LIB   = ../inst/lib/mips
  SRC_LIB   = ../src/lib/mips

#### - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ####

# Executable:


# UWIN:

# COCOEXE    = coco32.exe


# Unix / Linux:

  COCOEXE   = coco


# Cygwin:

# COCOEXE   = coco.exe



#### 
###############################################################################

# Shared libraries, without extension:

#

# Unix / Linux:

  RCSHLIB  = librcoco
  SCSHLIB  =    scoco
  XCSHLIB  = libxcoco

# Cygwin:

  WRCSHLIB  = wRcoco
  WSCSHLIB  = wScoco
  WXCSHLIB  = wXcoco


# Shared libraries, with extension:

# Unix / Linux:

  RCOCO = librcoco.so
  SCOCO =    scoco.o
  XCOCO = libxcoco.so

# Cygwin:

  WRCOCO =  wRcoco.dll
  WSCOCO =  wScoco.dll
  WXCOCO =  wXcoco.dll



###############################################################################

## Make source, standalone:

../src/coco_.c:
	if [ -d ../src/p ]; then \
	  (cd src ; make coco_.c) ; \
	else \
	  echo "No coco_.c!!!" ; \
	fi

../src/coco_d_.c:
	if [ -d ../src/p ]; then \
	  (cd src ; make coco_d_.c) ; \
	else \
	  echo "No coco_d_.c!!!" ; \
	fi

#### 
###############################################################################

## Script for running standalone:

CoCo.bat: ./lib/mips/CoCo.bat
./lib/mips/CoCo.bat: ./lib/mips/coco32.exe ../src/coco_d_.c ../src/assign.c
	sh ./Bin/setup.shell CoCo     ./  ${COCOEXE}  ./
	chmod a+x ./bin/CoCo
	sh ./Bin/setup.shell CoCo.bat .\\ ${COCOEXE} .\\
	chmod a+x ./bin/CoCo.bat
	date

#### - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ####

## Compilation of standalone:

coco32.exe: ./lib/mips/coco32.exe
./lib/mips/coco32.exe: ../src/coco_d_.c ../src/assign.c
	if [ -f ../src/coco_d_.c ]; then \
	  ${CC} ${CFLAGS} -o ./lib/mips/${COCOEXE} ../src/coco_d_.c ${LIBS} ; \
	fi
	date

coco: ./lib/mips/coco
./lib/mips/coco: ../src/coco_d_.c ../src/assign.c
	if [ -f ../src/coco_d_.c ]; then \
	  ${CC} ${CFLAGS} -ggdb -o ./lib/mips/${COCOEXE} \
	    ../src/coco_d_.c ${LIBS} ; \
	fi
	date

coco.cygwin: ./lib/mips/coco.exe
./lib/mips/coco.exe: ../src/coco_d_.c ../src/assign.c
	if [ -f ../src/coco_d_.c ]; then \
	  ${CC} ${CFLAGS} -DCoCo_Cygwin \
	    -o ./lib/mips/${COCOEXE} ../src/coco_d_.c ${LIBS} ; \
	fi
	date

Xcoco.cygwin: ../src/coco_d_x_.c ../src/assign.c
	gcc -DANSIGCC -DMINUSLOG -DNO_INTERRUPT -DCoCo_Cygwin ${CFLAGS} \
	    -c -I/. ../src/coco_d_x_.c
	gcc ${LDFLAGS} \
	    -o X${COCOEXE} coco_d_x_.o ${LIBS}
	date

#### 
###############################################################################

## Shared libraries (one object), Unix / Linux:

scoco.o: ./lib/mips/scoco.o
./lib/mips/scoco.o: ../src/coco_d_.c ../src/assign.c ../src/apix.c
	if [ -f ../src/coco_d_.c ]; then \
	  ${CC} -D__Mkstemp__ -DNO_INTERRUPT -DDCOCO ${CFLAGS} \
	    -c -o ./lib/mips/scoco.o ../src/apix.c ${LIBS} ; \
	fi
	date

libxcoco.so: ./lib/mips/libxcoco.so
./lib/mips/libxcoco.so: ./lib/mips/scoco.o
	if [ -f ../src/coco_d_.c ]; then \
	  ${LD} ${LDFLAGS} -o ./lib/mips/libxcoco.so ./lib/mips/scoco.o ; \
	fi
	date

librcoco.so: ./lib/mips/librcoco.so
./lib/mips/librcoco.so: ./lib/mips/libxcoco.so
#	${LD} ${LDFLAGS} -o ./lib/mips/librcoco.so ./lib/mips/scoco.o
#	${R} CMD SHLIB --output=librcoco.so scoco.o
	if [ -f ../src/coco_d_.c ]; then \
	  if [ ! -h ./lib/mips/librcoco.so ]; then \
	    ln -s  ./libxcoco.so ./lib/mips/librcoco.so ; \
	    cp ./lib/mips/libxcoco.so ./CoCoCg.so ; \
	  fi ; \
	fi
	date

#### - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ####

## Shared libraries (more than one object), Unix / Linux:

../src/coco_d_x_.c:
	(cd src ; make coco_d_x_.c)

Xcoco: ../src/coco_d_x_.c ../src/assign.c
	gcc -DANSIGCC -DMINUSLOG -DNO_INTERRUPT ${CFLAGS}  \
	    -c -I/. ../src/coco_d_x_.c
	gcc ${LDFLAGS} -o X${COCOEXE} coco_d_x_.o ${LIBS}
	date

./lib/mips/Xscoco.o: ../src/coco_d_x_.c ../src/assign.c ../src/apix_x.c
	gcc -DANSIGCC -DMINUSLOG -DNO_INTERRUPT -DDCOCO ${CFLAGS} -Wall \
	    -c -o ./lib/mips/Xscoco.o ../src/apix_x.c ${LIBS}
	date

Xlibxcoco.so: ./lib/mips/Xlibxcoco.so
./lib/mips/Xlibxcoco.so: ./lib/mips/Xscoco.o
	${LD} ${LDFLAGS} -o ./lib/mips/Xlibxcoco.so ./lib/mips/Xscoco.o
	date

./lib/mips/Xlibrcoco.so: ./lib/mips/Xlibxcoco.so
#	${LD} ${LDFLAGS} -o ./lib/mips/Xlibrcoco.so ./lib/mips/Xscoco.o
#	${R} CMD SHLIB --output=Xlibrcoco.so Xscoco.o
#	ln -s  ./Xlibxcoco.so ./lib/mips/Xlibrcoco.so
	    cp ./lib/mips/Xlibxcoco.so ./CoCoCg.so ; \
	date


#### 
###############################################################################

# After 'make libR.a' in '${WIN_R_ROOT}/src/gnuwin32',
# see '${WIN_R_ROOT}/readme.packages'.

## R

RCFLAGS1 = -DDCOCO -DCoCo_Cygwin -DR_APIX 
RCFLAGS = ${RCFLAGS1} -O2 -I${WIN_R_ROOT}/src/include/

wRcoco.o: ./lib/mips/wRcoco.o
./lib/mips/wRcoco.o: ../src/coco_d_.c ../src/assign.c ../src/apix.c ../src/apix-R.h
	date
	if [ -f ../src/coco_d_.c ]; then \
	  ${CC} ${CFLAGS} ${RCFLAGS} -pedantic \
	    -c -o ./lib/mips/wRcoco.o ../src/apix.c ${LIBS} ; \
	fi
	date

RDLLEXTRALIBS = ${CYG_R_ROOT}/src/gnuwin32/libR.a
RDLLFLAGS = --mno-cygwin --export-all-symbols --output-def dllwrap.def
## -mwin32

wRcoco.dll: ./lib/mips/wRcoco.dll
./lib/mips/wRcoco.dll: ./lib/mips/wRcoco.o
	if [ -f ../src/coco_d_.c ]; then \
	  dllwrap ${RDLLFLAGS} --def libcoco.def \
	    -o ./lib/mips/wRcoco.dll ./lib/mips/wRcoco.o ${RDLLEXTRALIBS} ; \
	  cp ./lib/mips/wRcoco.dll ./CoCoCg.dll ; \
	fi
	date

#### - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ####

## R, Multiple objects

RXCFLAGS1 = -DDCOCO -DCoCo_Cygwin -DR_APIX 
RXCFLAGS = ${RXCFLAGS1} -O2 -I${WIN_R_ROOT}/src/include/

XwRcoco.o: ./lib/mips/XwRcoco.o
./lib/mips/XwRcoco.o: ../src/coco_d_.c ../src/assign.c ../src/apix_x.c ../src/apix-R.h
	date
	if [ -f ../src/coco_d_x_.c ]; then \
	  ${CC} ${CFLAGS} ${RXCFLAGS} -pedantic \
	    -c -o ./lib/mips/XwRcoco.o ../src/apix_x.c ${LIBS} ; \
	fi
	date

RXDLLEXTRALIBS = ${CYG_R_ROOT}/src/gnuwin32/libR.a
RXDLLFLAGS = --mno-cygwin --export-all-symbols --output-def dllwrap.def
## -mwin32

XwRcoco.dll: ./lib/mips/XwRcoco.dll
./lib/mips/XwRcoco.dll: ./lib/mips/XwRcoco.o
	if [ -f ../src/coco_d_x_.c ]; then \
	  dllwrap ${RXDLLFLAGS} --def libcoco.def \
	    -o ./lib/mips/XwRcoco.dll ./lib/mips/XwRcoco.o ${RXDLLEXTRALIBS} ; \
	  cp ./lib/mips/XwRcoco.dll ./CoCoCg.dll ; \
	fi
	date

#### 
###############################################################################

## Splus

SCFLAGS1 = -DDCOCO -DCoCo_Cygwin -DS_APIX -I${S_ROOT}/include/
## SCFLAGS1 = -O2 ${SCFLAGS1}
SCFLAGS = ${SCFLAGS1} -I/usr/include/mingw/ 

wScoco.o: ./lib/mips/wScoco.o
./lib/mips/wScoco.o: ../src/coco_d_.c ../src/assign.c ../src/apix.c ../src/apix-S.h
	date
	if [ -f ../src/coco_d_.c ]; then \
	  ${CC} ${CFLAGS} ${SCFLAGS} -pedantic \
	    -c -o ./lib/mips/wScoco.o ../src/apix.c ${LIBS} ; \
	fi
	date

SDLLEXTRALIBS = ${S_ROOT}/cmd/sqpe.dll
SDLLFLAGS = --mno-cygwin --export-all-symbols --output-def dllwrap.def

wScoco.dll: ./lib/mips/wScoco.dll
./lib/mips/wScoco.dll: ./lib/mips/wScoco.o
	if [ -f ../src/coco_d_.c ]; then \
	  dllwrap ${SDLLFLAGS} --def libcoco.def \
	    -o ./lib/mips/wScoco.dll ./lib/mips/wScoco.o ${SDLLEXTRALIBS} ; \
	fi
	date

#### - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ####

## Splus, Multiple objects

SXCFLAGS1 = -DDCOCO -DCoCo_Cygwin -DS_APIX -I${S_ROOT}/include/
## SXCFLAGS1 = -O2 ${SXCFLAGS1}
SXCFLAGS = ${SXCFLAGS1} -I/usr/include/mingw/ 

XwScoco.o: ./lib/mips/XwScoco.o
./lib/mips/XwScoco.o: ../src/coco_d_.c ../src/assign.c ../src/apix_x.c ../src/apix-S.h
	date
	if [ -f ../src/coco_d_x_.c ]; then \
	  ${CC} ${CFLAGS} ${SXCFLAGS} -pedantic \
	    -c -o ./lib/mips/XwScoco.o ../src/apix_x.c ${LIBS} ; \
	fi
	date

SXDLLEXTRALIBS = ${S_ROOT}/cmd/sqpe.dll
SXDLLFLAGS = --mno-cygwin --export-all-symbols --output-def dllwrap.def

XwScoco.dll: ./lib/mips/XwScoco.dll
./lib/mips/XwScoco.dll: ./lib/mips/XwScoco.o
	if [ -f ../src/coco_d_x_.c ]; then \
	  dllwrap ${SXDLLFLAGS} --def libcoco.def \
	    -o ./lib/mips/XwScoco.dll ./lib/mips/XwScoco.o ${SXDLLEXTRALIBS} ; \
	fi
	date

#### 
###############################################################################

## XlispStat:

## TestGraph.lsp on this succeeded!!!
## - But no printing (no at all from CoCo) !!!

XCFLAGS1 = -DDCOCO -DCoCo_Cygwin -DX_APIX 
XCFLAGS = ${XCFLAGS1}

wXcoco.o: ./lib/mips/wXcoco.o
./lib/mips/wXcoco.o: ../src/coco_d_.c ../src/assign.c ../src/apix.c ../src/apix-X.h
	date
	if [ -f ../src/coco_d_.c ]; then \
	  ${CC} ${CFLAGS} ${XCFLAGS} -pedantic \
	    -c -o ./lib/mips/wXcoco.o ../src/apix.c ${LIBS} ; \
	fi
	date

XDLLEXTRALIBS =
XDLLFLAGS = --export-all-symbols --output-def dllwrap.def

wXcoco.dll: ./lib/mips/wXcoco.dll
./lib/mips/wXcoco.dll: ./lib/mips/wXcoco.o
	if [ -f ../src/coco_d_.c ]; then \
	  dllwrap ${XDLLFLAGS} \
	    -o ./lib/mips/wXcoco.dll ./lib/mips/wXcoco.o ${XDLLEXTRALIBS} ; \
	fi
	date

#### - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ####

## XlispStat, Multiple objects

## TestGraph.lsp on this succeeded!!!
## - But no printing (no at all from CoCo).

XXCFLAGS1 = -DDCOCO -DCoCo_Cygwin -DX_APIX 
XXCFLAGS = ${XXCFLAGS1}

XwXcoco.o: ./lib/mips/XwXcoco.o
./lib/mips/XwXcoco.o: ../src/coco_d_.c ../src/assign.c ../src/apix_x.c ../src/apix-X.h
	date
	if [ -f ../src/coco_d_x_.c ]; then \
	  ${CC} ${CFLAGS} ${XXCFLAGS} -pedantic \
	    -c -o ./lib/mips/XwXcoco.o ../src/apix_x.c ${LIBS} ; \
	fi
	date

XXDLLEXTRALIBS =
XXDLLFLAGS = --export-all-symbols --output-def dllwrap.def

XwXcoco.dll: ./lib/mips/XwXcoco.dll
./lib/mips/XwXcoco.dll: ./lib/mips/XwXcoco.o
	if [ -f ../src/coco_d_x_.c ]; then \
	  dllwrap ${XXDLLFLAGS}  \
	    -o ./lib/mips/XwXcoco.dll ./lib/mips/XwXcoco.o ${XXDLLEXTRALIBS} ; \
	fi
	date

#### 
###############################################################################

## XLispStat-R:
## No Printing!!!

XRCFLAGS1 = -DDCOCO -DCoCo_Cygwin -DX_APIX -DR_APIX 
XRCFLAGS = ${XRCFLAGS1} -O2 -I${WIN_R_ROOT}/src/include/

wX-Rcoco.o: ./lib/mips/wX-Rcoco.o
./lib/mips/wX-Rcoco.o: ../src/coco_d_.c ../src/assign.c ../src/apix.c ../src/apix-X.h ../src/apix-R.h
	date
	if [ -f ../src/coco_d_.c ]; then \
	  ${CC} ${CFLAGS} ${XRCFLAGS} -pedantic \
	    -c -o ./lib/mips/wX-Rcoco.o ../src/apix.c ${LIBS} ; \
	fi
	date

# After 'make libR.a' in '${WIN_R_ROOT}/src/gnuwin32',
# see '${WIN_R_ROOT}/readme.packages'.

XRDLLEXTRALIBS = ${CYG_R_ROOT}/src/gnuwin32/libR.a
XRDLLFLAGS = --mno-cygwin --export-all-symbols --output-def dllwrap.def
## -mwin32

wX-Rcoco.dll: ./lib/mips/wX-Rcoco.dll
./lib/mips/wX-Rcoco.dll: ./lib/mips/wX-Rcoco.o
	date
	if [ -f ../src/coco_d_.c ]; then \
	  dllwrap ${XRDLLFLAGS} --def libcoco.def \
	    -o ./lib/mips/wX-Rcoco.dll  ./lib/mips/wX-Rcoco.o ${XRDLLEXTRALIBS} ; \
	fi
	date

#### 
#### - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ####

## XLispStat-Splus
## Not working!!!

## ; loading C:\Statistics\Xlispstat\jhb\TestGraph.lsp
## Error: error code 1157 loading library
##               C:/COMPILERS/Cygwin/home/jhb/CoCo/source.2002.okt.18/lib/mips/wX-Scoco
## Happened in: #<Subr-SHARED-LIBRARY::SHLIB-OPEN: #750d40>

XSCFLAGS1 = -DDCOCO -DCoCo_Cygwin -DX_APIX -DS_APIX -I${S_ROOT}/include/
## XSCFLAGS1 = -O2 ${XSCFLAGS1}
XSCFLAGS = ${XSCFLAGS1} -I/usr/include/mingw/ 

wX-Scoco.o: ./lib/mips/wX-Scoco.o
./lib/mips/wX-Scoco.o: ../src/coco_d_.c ../src/assign.c ../src/apix.c ../src/apix-X.h ../src/apix-S.h
	date
	if [ -f ../src/coco_d_.c ]; then \
	  ${CC} ${CFLAGS} ${XSCFLAGS} -pedantic \
	    -c -o ./lib/mips/wX-Scoco.o ../src/apix.c ${LIBS} ; \
	fi
	date

XSDLLEXTRALIBS = ${S_ROOT}/cmd/sqpe.dll
XSDLLFLAGS = --mno-cygwin --export-all-symbols --output-def dllwrap.def

wX-Scoco.dll: ./lib/mips/wX-Scoco.dll
./lib/mips/wX-Scoco.dll: ./lib/mips/wX-Scoco.o
	if [ -f ../src/coco_d_.c ]; then \
	  dllwrap ${XSDLLFLAGS} --def libcoco.def \
		-o ./lib/mips/wX-Scoco.dll ./lib/mips/wX-Scoco.o ${XSDLLEXTRALIBS} ; \
	fi
	date

#### 
###############################################################################

## Installation:

install.coco: ./lib/mips/${COCOEXE} ${COCOFILES} ./Bin/setup.shell dirs
#	-mkdir ${COCOHOME}/Examples
#	-mkdir ${COCOHOME}/DataSets
#	-mkdir ${COCOHOME}/TestRuns

	sh ./Bin/setup.shell CoCo     ${COCOHOME} ${COCOEXE} ${COCOTMP}
	chmod a+x ./bin/CoCo
	cp -p ./bin/CoCo     ${BINDIR}

	sh ./Bin/setup.shell CoCo.bat ${WINHOME} ${COCOEXE} ${COCOTMP}
	chmod a+x ./bin/CoCo.bat
	cp -p ./bin/CoCo.bat ${BINDIR}

	cp -p ./lib/mips/${COCOEXE} ${SRC_LIB}/COCO.TAB \
	 ${SRC_LIB}/COCO.DAT ${SRC_LIB}/COCO.HLP ${COCOLIB}
	touch     ${COCOHOME}/Logs/CoCo.log
	chmod 666 ${COCOHOME}/Logs/CoCo.log
	date

install: install.coco


#### - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ####

install.R.and.S: ${COCOFILES} ./lib/mips/${RCOCO} ./lib/mips/${SCOCO} \
	 ./Bin/setup.shell dirs copy.r.s.files
	make make.R.files
	make make.S.files
	date

install.Lisp: ${COCOFILES} ./lib/mips/${XCOCO} \
	 ./Bin/setup.shell loadcoco dirs copy.lisp.files
#	cp -p ${SRC_LSP}/Examples/TestGraph.lsp ${XLISP_ROOT}
#	cp -p ./lib/mips/Unix-load.lsp          ${XLISP_ROOT}/Unix-load.lsp
	make make.Lisp.files
	date

install.three: ${COCOFILES} \
	 ./lib/mips/${RCOCO} ./lib/mips/${SCOCO} ./lib/mips/${XCOCO} \
	 ./Bin/setup.shell loadcoco dirs copy.lisp.files copy.r.s.files
	make make.S.files
	make make.R.files
	make make.Lisp.files
	date


#### 
###############################################################################

## Compile / load R, S and lisp-files:


make.S.files: ./lib/mips/${SCOCO} # ./lib/mips/X${SCOCO}
	if [ -f ./lib/mips/X${SCOCO} ]; then \
	  cp -p ./lib/mips/X${SCOCO} ${COCOLIB} ; \
	else \
	  cp -p ./lib/mips/${SCOCO} ${COCOLIB} ; \
	fi
	echo "Please ignore error if you do not have Splus:" ;
#	(cd ${SCOCOLIB} ; make -i )
	date

make.R.files: ./lib/mips/${RCOCO} # ./lib/mips/X${RCOCO}

## Use XlispStat shared library: Replace {RCOCO} by {XCOCO}

#	if [ -f ./lib/mips/X${RCOCO} ]; then \
#	  cp -p ./lib/mips/X${RCOCO} ${COCOLIB} ; \
#	else \
#	  cp -p ./lib/mips/${RCOCO} ${COCOLIB} ; \
#	fi

## Since segmentation fault at multiple objects:

	cp -p ./lib/mips/${XCOCO} ${COCOLIB}/${RCOCO}
	echo "Please ignore error if you do not have R:" ;
#	(cd ${RCOCOLIB} ; make -i )
	date

make.Lisp.files: ./lib/mips/${XCOCO} # ./lib/mips/X${XCOCO}
	if [ -f ./lib/mips/X${XCOCO} ]; then \
	  cp -p ./lib/mips/X${XCOCO} ${COCOLIB} ; \
	else \
	  cp -p ./lib/mips/${XCOCO} ${COCOLIB} ; \
	fi
	echo "Please ignore error if you do not have XlispStat:" ;
	(cd ${XCOCOLIB} ; make -i )
	date

#### 
###############################################################################
# Cygwin (Windows):

#### - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ####

install.wScoco: ${COCOFILES} ./lib/mips/${WRCOCO} ./lib/mips/${WSCOCO} \
	 ./Bin/setup.shell dirs copy.r.s.files
	make -f Makefile.win make.wR.files
	make -f Makefile.win make.wS.files
	date

install.wXcoco: ${COCOFILES} ./lib/mips/${WXCOCO} \
	 ./Bin/setup.shell loadcoco dirs copy.lisp.files
#	cp -p ${SRC_LSP}/Examples/TestGraph.lsp ${XLISP_ROOT}
#	cp -p ./lib/mips/Windows-load.lsp       ${XLISP_ROOT}/Windows-load.lsp
	make -f Makefile.win make.wLisp.files
	date

install.w.three: ${COCOFILES} \
	 ./lib/mips/${WRCOCO} ./lib/mips/${WSCOCO} ./lib/mips/${WXCOCO} \
	 ./Bin/setup.shell loadcoco dirs copy.lisp.files copy.r.s.files
	make -f Makefile.win make.wS.files
	make -f Makefile.win make.wR.files
	make -f Makefile.win make.wLisp.files
	date

###############################################################################

## Compile / load R, S and lisp-files:

make.wS.files: ./lib/mips/${WSCOCO} # ./lib/mips/X${WSCOCO}
	if [ -f ./lib/mips/X${WSCOCO} ]; then \
	  cp -p ./lib/mips/X${WSCOCO} ${COCOLIB} ; \
	else \
	  cp -p ./lib/mips/${WSCOCO} ${COCOLIB} ; \
	fi
	echo "Please ignore error if you do not have Splus:" ;
#	(cd ${WSCOCOLIB} ; make -i )
	date

make.wR.files: ./lib/mips/${WRCOCO} # ./lib/mips/X${WRCOCO}

	if [ -f ./lib/mips/X${WRCOCO} ]; then \
	  cp -p ./lib/mips/X${WRCOCO} ${COCOLIB} ; \
	else \
	  cp -p ./lib/mips/${WRCOCO} ${COCOLIB} ; \
	fi
	echo "Please ignore error if you do not have R:" ;
#	(cd ${WRCOCOLIB} ; make -i )
	date

make.wLisp.files: ./lib/mips/${WXCOCO} # ./lib/mips/X${WXCOCO}
	if [ -f ./lib/mips/X${WXCOCO} ]; then \
	  cp -p ./lib/mips/X${WXCOCO} ${COCOLIB} ; \
	else \
	  cp -p ./lib/mips/${WXCOCO} ${COCOLIB} ; \
	fi
	echo "Please ignore error if you do not have XlispStat:" ;
#	(cd ${WXCOCOLIB} ; make -i )
	date


#### 
###############################################################################

## Directories:

dirs:
	-mkdir -p ${COCOHOME}
	-mkdir -p ${COCOHOME}/Logs
	-mkdir -p ${BINDIR}
	-mkdir -p ${COCOLIB}
	-mkdir -p ${COCOTMP}
	date

rbin: ${COCOFILES} ./Bin/setup.shell
	echo R_LIB_DIR:
	echo ${R_LIB_DIR}
	echo R_PAC_DIR:
	echo ${R_PAC_DIR}
	echo UNIX_R_HJEM:
	echo ${UNIX_R_HJEM}
	echo UNIX_R_ROOT:
	echo ${UNIX_R_ROOT}
	sh ./Bin/setup.shell    Unix-R-load.R ${COCOHOME} \
		${COCOLIB} ${RSCOCOLIB}  ${RCSHLIB} ${LOADPREF}
	sh ./Bin/setup.shell Windows-R-load.R ${COCOHOME} \
		${COCOLIB} ${RSCOCOLIB} ${WRCSHLIB} ${LOADPREF}
	sh ./Bin/setup.shell R+coco ${COCOHOME} ${RCOCOLIB} ${R} ${COCOTMP}
#	chmod a+x ./bin/R+coco
#	cp -p ./bin/R+coco ${BINDIR}
#	chmod a+x ./bin/R+Mips
#	cp -p ./bin/R+Mips ${BINDIR}
	date

sbin: ${COCOFILES} ./Bin/setup.shell
	sh ./Bin/setup.shell    Unix-S-load.S ${COCOHOME} \
		${COCOLIB} ${RSCOCOLIB}  ${SCSHLIB} ${LOADPREF}
	sh ./Bin/setup.shell Windows-S-load.S ${COCOHOME} \
		${COCOLIB} ${RSCOCOLIB} ${WSCSHLIB} ${LOADPREF}
	sh ./Bin/setup.shell S+coco ${COCOHOME} ${SCOCOLIB} ${S} ${COCOTMP}
#	chmod a+x ./bin/S+coco
#	cp -p ./bin/S+coco ${BINDIR}
#	chmod a+x ./bin/S+Mips
#	cp -p ./bin/S+Mips ${BINDIR}
	date

loadcoco: ./Bin/setup.shell
	sh ./Bin/setup.shell    Unix-load.lsp ${COCOHOME} \
		${COCOLIB} ${XCOCOLIB}  ${XCSHLIB} ${LOADPREF}
	sh ./Bin/setup.shell Windows-load.lsp ${COCOHOME} \
		${COCOLIB} ${XCOCOLIB} ${WXCSHLIB} ${LOADPREF}
	date

xbin: ${COCOFILES} ./Bin/setup.shell loadcoco
	sh ./Bin/setup.shell xlisp+coco ${COCOHOME} ${XCOCOLIB} \
	 ${XLISPSTAT} ${COCOTMP}
#	chmod a+x ./bin/xlisp+coco
#	cp -p ./bin/xlisp+coco ${BINDIR}
	date

rsxdir: ${COCOFILES} ./Bin/setup.shell dirs rbin sbin xbin

#### 
#### - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ####

copy.r.s.files: ${COCOFILES} ./Bin/setup.shell dirs rbin sbin xbin
	-mkdir -p ${COCOHOME}/R+S
	-mkdir -p ${RCOCOLIB}
	-mkdir -p ${SCOCOLIB}
	-mkdir -p ${RSCOCOLIB}
	-mkdir -p ${RCOCOLIB}/bin
	-mkdir -p ${SCOCOLIB}/bin

	touch     ${COCOHOME}/Logs/R+Mips.log
	chmod 666 ${COCOHOME}/Logs/R+Mips.log
	touch     ${COCOHOME}/Logs/S+Mips.log
	chmod 666 ${COCOHOME}/Logs/S+Mips.log

	date

#### 
copy.lisp.files: ./Bin/setup.shell dirs xbin
	touch ${COCOHOME}/Logs/Xlisp+Mips.log
	chmod 666 ${COCOHOME}/Logs/Xlisp+Mips.log
	date


###############################################################################
# Cleanup:

clean:
	rm -f core *.so lib/mips/*.so lib/mips/*.o lib/mips/*.dll \
		../src/*p2c.p ../src/*p2c.c ../src/*p2c.log ../src/*.orig
	date

cleanall: clean
	rm -f ${COCOEXE} ${SCOCO} ${XCOCO} a.*
	date


#### 
###############################################################################
# Dependencies:

COCOFILES = ${SRC_LIB}/COCO.TAB ${SRC_LIB}/COCO.DAT ${SRC_LIB}/COCO.HLP


###############################################################################

Makefile.win: Makefile
	cp Makefile Makefile.win
	patch Makefile.win Makefile.patch

Makefile.patch: Makefile
	diff -C4 Makefile Makefile.win > Makefile.patch


###############################################################################
# Distribution:

### 56789012345678901234567890123456789012345678901234567890123456789012345678
