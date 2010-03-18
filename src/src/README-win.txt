
 To avoid reading this file:


 On Windows:

 If you only want to use CoCo in R (you have probably already
 installed a recent version of R) you only have to load the
 ZIP-file with the CoCo-bundle.

 But you should also try the graphical interface in XlispStat:

 - Install XlispStat and Cygwin,

 - Place Cygwin1.dll in a catalogue in your path,

 - Uncompress the CoCo_...tar.gz file,

 - Edit only the MACRO variables WIN_R_ROOT, CYG_R_ROOT, S_ROOT and
   XLISP_ROOT in Makefile.win .../CoCoCore/src/ ;

 - Type "make -f Makefile.win windows.full" in .../CoCoCore/src/ 
   [ This will eventually terminate with an error, since coco_d_x_.c
     is missing from the distribution. Ignore this. ];

 - Start XlispStat and load Windows-load.lsp and TestGraph.lsp,
   now in $XLISP_ROOT/, into XlispStat;


 On Unix and Linux:

 - (Install R and XlispStat),

 - Unpack the .tar.gz file,

 - Make an install of CoCo-bundle for R by 'R INSTALL -d CoCo',

 For CoCo, xlisp+coco:

 - Change to the directory CoCo/CoCoCore/src,

 - If you do not use default CC (gcc), ld, R, Splus5 and xlispstat
   you will have to set the macro variable for these in Makefile,

 - Type 'make unix.full',

 - Start Xlisp+CoCo RHOME/library/CoCo/bin/xlisp+coco.

 Do for CoCoCg, xlisp+cococg:

 - Change to the directory CoCo/CoCoCg/src,

 - If you do not use default CC (gcc), ld, R, Splus5 and xlispstat
   you will have to set the macro variable for these in Makefile,

 - Type 'make unix.full',

 - Start Xlisp+CoCo RHOME/library/CoCo/bin/xlisp+cococg.


 /* -------- -------- -------- -------- -------- -------- -------- ------- */

 Section A:

 First, install the three programmes Cygwin, R and XlispStat:


 1) Get, unpack and install Cygwin: http://www.cygwin.com/

    a) I just took the default: You will need at least "cygwin1.dll" to
       run CoCo within the other programmes, and also "gcc" and "make", at 
       least the "base" and "devel" module, to compile.

    b) The directory of cygwin1.dll must be in your path.
       Set the path, or place the file in e.g. RHOME/bin !!!!.

  [ c) The following is no longer mandatory, since COCOLIB and COCOTMP,
       the locations of the lib- and tmp-directories of CoCo, are given
       to CoCo when starting CoCo within the other programmes:

       While setting the path to cygwin1.dll, you could also set the
       three environment variables COCOHOME, COCOLIB and COCOTMP, to
       appropriate, e.g. "C:/Programmes/CoCo", "C:/Programmes/CoCo/lib/coco"
       and "C:/Programmes/CoCo/TMP" .  Insert the variables in the
       AUTOEXEC.BAT file (and reboot) by, e.g.:

       Windows 2000: Indstillinger -> Kontrolpanel
                     --> System -> Avanceret -> Miljøvariable
 
       Windows 98: Programmer -> Tilbehør -> Systemværktøj
                   -> Systemoplysninger ~~> Funktioner
	 	   -> Værktøj til Systemkonfiguration
		   --> Autoexec.bat                          ]

 2) Get, unpack and install R: http://lib.stat.cmu.edu/R/CRAN/

    - Make libR.a by "make" in 'RHOME/src/gnuwin32',
      see 'RHOME/readme.packages'.


 3) Get, unpack and install XlispStat: E.g. WXLS32ZP.EXE from
    ftp.stat.unipg.it/pub/stat/xlispstat/3-52/mswin/

    a) Get the binary file;
    b) Make the directory where you want the installation,
       e.g. "C:/Programmes/XLispStat";
    c) Place WXLS32ZP.EXE in the directory;
    d) Click WXLS32ZP.EXE;
    e) Make a link to WXLS32, and move it the your desktop.


 /* - - - -  - - - -  - - - -  - - - -  - - - -  - - - -  - - - -  - - - - */

 Section B:

 4) Select R, S and XlispStat, set MACRO variables for the home directories
    of these, and select home-directory and directory for tmp-files for CoCo:

    Select R, S and XlispStat, and set environments variables WIN_R_ROOT, 
    S_ROOT and XLISP_ROOT for the home directories of the programmes in 
    .../CoCoCore/src/Makefile.win:

    -) Search for "ROOT" in .../CoCoCore/src/Makefile.win, and edit to 
       appropriate;

    I have currently set COCOHOME and COCOTMP to put these directories
    into the CoCo directory $RHOME/library/CoCo.  You can change these
    locations:

    Set the environment variables LOADPREF, COCOHOME and COCOTMP of 
    .../CoCoCore/src/Makefile.win:

    a) Search for "Cygwin" in .../CoCoCore/src/Makefile.win;
    b) Uncomment (remove the "#") of the four lines for LOADPREF, COCOHOME, 
       COCOTMP and BINDIR;
    c) Edit the values of the three environment variables
       LOADPREF, COCOHOME and COCOTMP:

       o LOADPREF is for Cygwin: If COCOHOME and COCOTMP are relative to
         root directory of Cygwin, then LOADPREF should be the location of 
         the root of Cygwin relative to the root of Windows.

 5) Type "make -f Makefile.win windows.full" in  .../CoCoCore/src/;

    This should:

 I) For CoCo,

    a) Make executable coco.exe for the stand-alone CoCo;
    b) Make the .dll file wScoco.dll for Splus;
    c) Make the .dll file wRcoco.dll R;
    d) Make the .dll file wXcoco.dll XlispStat;
    e) Create the directories $COCOHOME and $COCOHOME/lib/coco;
    f) Create the directory $COCOTMP: mkdir -p $COCOTMP;
    g) Make a copy of COCO.EXE, COCO.TAB, wScoco.dll, wRcoco.dll and 
       wXcoco.dll, etc. to $COCOHOME/lib/coco;
    


 II) For S and R:

    a) Define (insert) the four variables COCOHOME, COCOLIB, RSCOCOLIB
       and SCSHLIB / RCSHLIB into Windows-S-load.S and Windows-R-load.R
       to appropriate [ relative the location LOADPREF ] (e.g. 
       "c:/Programmer/CoCo", "c:/Programmer/CoCo/lib/coco", 
       "c:/Programmer/CoCo/R+S/R.and.S" and "wScoco.dll) and place the
       resulting files in $COCOHOME/lib/coco/ (and $COCOHOME/R+S/R.and.S); 
    b) Make a copy of the directory .../CoCoCore/src/R+S/R.and.S 
       to $COCOHOME/R+S/R.and.S (if not in place);


 III) For XlispStat:

    a) Define (insert) the four XlispStat variables *cocohome*, *cocolib*, 
       *xlisp-cocohome* and *coco-object-name* into Windows-load.lsp to 
       appropriate [ relative the location LOADPREF ]
       (e.g. "c:/Programmer/CoCo", "c:/Programmer/CoCo/lib/coco",
       "c:/Programmer/CoCo/lsp" and "wXcoco.dll"), and place the
       resulting file Windows-load.lsp in $COCOHOME/lib/coco/ 
       (and $COCOHOME/lsp + $XLISP_ROOT);
    b) Make a copy of the directory .../CoCoCore/src/lsp
       to $COCOHOME/lsp (if not in place);


 /* - - - -  - - - -  - - - -  - - - -  - - - -  - - - -  - - - -  - - - - */

 Section C:

 To use Xlisp+CoCo under Windows:

 a) Start XlispStat;
 b) Load Windows-load.lsp of $XLISP_HOME/ (or $COCOHOME/lib/coco/) into 
    XlispStat (by, e.g. "Load" from the "File" menu);
 c) Load TestGraph.lsp of $XLISP_HOME/ (or $COCOHOME/lib/coco/) into
    XlispStat;

    [ To make life easier for you, you could place the two files
      in a sub-catalogue of your XlispStat installation directory. ]

 - In sub-sequential runs of XlispStat+CoCo you have to load
   Windows-load.lsp again!


 To create a CoCo library for Splus:

 a) Start Splus;
 b) Load Windows-S-Load.S and Windows-S-make-library.S from
    $COCOHOME/R+S/R.and.S into Splus;
 c) Quit Splus (and maybe save the workspace);

 To Use Splus+CoCo:

 - Restart Splus, and

 d) type library(CoCo).


 
 To Use R+CoCo:

 a) Start R;
 b) If you have not installed the R-CoCo-package, load the ZIP-file
    with the CoCo-bundle.
 c) Quit R;

 - Restart R by clicking the workspace, and

 d) type library(CoCo).


 /* -------- -------- -------- -------- -------- -------- ------- */

 Section D:

 When it does not work:

 Installation and test in the order Splus+CoCo, R+CoCo, XlispStat+CoCo
 is recommended, since XlispStat aborts faster than R, and R faster
 than Splus.

 1) You are not able to find the file for loading interface functions:

    a) Xlisp+CoCo: Windows-load.lsp; 
    b) R:          Windows-R-load.R;
    c) S:          Windows-S-load.S.

    - See the user guides to the programmes XlispStat, R and Splus.

    - The loading-files have not been made in step I-b) to, I-d), or 
      copied to $COCOLIB/, step II-a) and III-a) above.


 2) Loading of the interface functions terminates:

    a) Xlisp+CoCo: Windows-load.lsp; 
    b) R:          Windows-R-load.R;
    c) S:          Windows-S-load.S.

    - Inappropriate values set in the loading files,
      step II-a) and III-a) above.


 3) Unable to find files used by:

    a) Xlisp+CoCo: Windows-load.lsp; 
    b) R:          Windows-R-load.R;
    c) S:          Windows-S-load.S.

    - The interface files have not been copied from ... to ... ,
      step II-b) and III-b) above.


 4) Loading of .dll file terminates,
    the .dll-files of CoCo are not found:

    a) Xlisp+CoCo: wXcoco.dll in *cocolib* of Windows-load.lsp;
    b) R:          wRcoco.dll in COCOLIB of Windows-R-load.R;
    c) S:          wScoco.dll in COCOLIB of Windows-S-load.S.

    - The .dll-files have not been copied to $COCOLIB/ ,
      step I-g) above.


 5) Loading of .dll file terminates,
    since needed libraries not found:

    a) Xlisp+CoCo: Path to cygwin1.dll
    b) R:          Path to cygwin1.dll and libR.a

    - Set the path to cygwin1.dll and make libR.a,
      step 1-b) and 1-c) above.



 6) Creating a CoCo-object terminates (and Splus, R and XlispStat
    also terminate), since environment variables COCOLIB and COCOTMP 
    are not set (or the locations given by these variables are not
    correctly transfered to CoCo):

    [ This is obsolete, since the locations of the directories are now
    given as an argument, when starting CoCo in R, S and XlispStat.
    
    a) $COCOLIB must be set, and pointing to catalogue with .dll-files 
       of CoCo and COCO.TAB !!!
       See step 1-c) above.

    b) If $COCOTMP is not set then $TMP or $TEMP must be set, and the 
       appropriate directory must exist and be possible to write in.
       See step 1-c) and 4-c) above.

    ]

    In R and Splus the function .get.lib.and.tmp(), used in
    init.coco(), must return a string with the locations of
    the two directories COCOLIB and COCOTMP, separated by the
    same character as the first and last in the string, and not in
    the paths of catalogues.  Similar in XlispStat.


 7) Creating a CoCo-object terminates (and Splus, R and XlispStat
    also terminate), since CoCo is not able to write in catalogue
    $COCOTMP (or $TMP or $TEMP).

    -) Make sure the catalogue is writable.
       See step 1-c) and 4-c) above.


 8) Creating a CoCo-object terminates (and Splus, R and XlispStat
    also terminate), since CoCo is unable to find COCO.TAB in
    $COCOLIB.

    -) Make sure that $COCOLIB/COCO.TAB is available.
       See step I-g) above.

 9) ?



 /* - - - -  - - - -  - - - -  - - - -  - - - -  - - - -  - - - -  - - - - */


