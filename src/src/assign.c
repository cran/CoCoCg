/* page 1: clock */

#ifdef HAS_CLOCK

  long my_clock()
  {
#ifdef __CoCo_BorlandC__
    return 1000*clock()/CLK_TCK;
#else
    return clock()/1000;
#endif
  }

#else
#ifndef has_my_clock
#ifdef HAS_NOT_GETRUSAGE

/* #include <sys/types.h> */
/* #include <limits.h> */

#include <sys/times.h>

#ifndef has_sys_conf
#ifndef clk_tck
#define clk_tck 60
#endif
#endif

long my_clock()
{
  long c;
  struct tms *buffer;
  
  buffer = (struct tms *)malloc(sizeof(struct tms));
  if (times(buffer) == -1) {
    free(buffer);
    return 0;
  }
  else if (times(buffer) >= 0) {
    c = buffer->tms_utime + buffer->tms_stime;
#ifdef has_sys_conf
    c = 1000 * c / _sysconf(3); /* _sc_clk_tck */
#else
    c = 1000 * c / clk_tck;
#endif
    free(buffer);
    return c;
  }
  free(buffer);
  return 0;
}

#else

#include <sys/time.h>
#include <sys/resource.h>

long my_clock()
{
  long c;
  struct rusage *rusage;

  rusage = (struct rusage *)malloc(sizeof(struct rusage));
  if (getrusage(RUSAGE_SELF, rusage) == 0) {
    c = 1000 * rusage->ru_utime.tv_sec + rusage->ru_utime.tv_usec / 1000 +
        1000 * rusage->ru_stime.tv_sec + rusage->ru_stime.tv_usec / 1000;
    free(rusage);
    return c;
  }
  free(rusage);
  return 0;
}

#endif
#endif
#endif


/* page 2: randominit */

long random_init()
{
  /* gettimeofday or time */
#ifdef __CoCo_BorlandC__
  return my_clock()/1 + getpid();
#else
#ifdef CoCo_Cygwin
  return my_clock()/1 + getpid() /* + getppid() */ ;
#else
  return my_clock()/1 + getpid() + getppid() ;
#endif
#endif
}

Static Void monitor_note_exact(txt, w, a, b, c)
Char *txt;
long w, a, b, c;
{
}


/* page X: MY_STR... */


#ifndef CoCo_Cygwin
Static Void print_my_c(c)
Char c;
{
  Char c_str[2];

  c_str[0] = c;
  c_str[1] = '\0';
  printf(c_str);
}  /* print_my_c */
#endif /* CoCo_Cygwin */


Static Void my_strchr(s, c, i, length)
Char *s;
Char c;
long *i, length;
{
  while (s[*i - PCH_START] != '\0' &&
	 s[*i - PCH_START] != c && *i < length)
    (*i)++;
}


Static Void my_strdhr(s, c1, c2, i, length)
Char *s;
Char c1, c2;
long *i, length;
{
  while (s[*i - PCH_START] != '\0' &&
	 s[*i - PCH_START] != c1 &&
	 s[*i - PCH_START] != c2 && *i < length)
    (*i)++;
}


Static Void my_strcat(dst, src, c, i, j, length)
Char *dst, *src;
Char c;
long *i, *j, length;
{
  while (src[*j - PCH_START] != '\0' &&
	 src[*j - PCH_START] != c &&
	 *i + *j <= length) {
    dst[*i + *j - PCH_START - PCH_START] = src[*j - PCH_START];
    (*j)++;
  }
  dst[*i + *j - PCH_START - PCH_START] = '\0';
}


Static Void my_strncp(dst, src, c, i, j, n, length)
Char *dst, *src;
Char c;
long *i, *j, *n, length;
{
  long j_start;

  j_start = *j;
  while (src[*j - PCH_START] != '\0' && src[*j - PCH_START] != c &&
	 *j - j_start < *n && *j < length) {
    dst[*i - PCH_START] = src[*j - PCH_START];
    (*j)++;
    (*i)++;
  }
  dst[*i - PCH_START] = '\0';
}


Static Void my_strcct(dst, c, i, length)
Char *dst;
Char c;
long *i, length;
{
  dst[*i - PCH_START] = c;
  (*i)++;
  dst[*i - PCH_START] = '\0';
}


Static Void my_strcnt(dst, c, i, length)
Char *dst;
Char c;
long *i, length;
{
  dst[*i - PCH_START] = c;
  (*i)++;
}


Static Void my_strclr(dst, c, i, length)
Char *dst;
Char c;
long i, length;
{
  while (i <= length) {
    dst[i - PCH_START] = c;
    i++;
  }
  if (false)
    dst[i - PCH_START - 1] = '\0';
}


/* page 3: COCOLIB */

extern Char *getenv();

Static Void my_pause(c)
Char *c;
{
  int i, j, k;
  double x;

  for (j = 0; j < 8; j++) {
    for (i = j*8; i < 8*8; i++) {
      printf("-");
      x = 1.0;
      for (k = 1; k < 8*8*8*8; k++)
	x = i / k + j / x;
    }
    printf("\n");
  }
}


/* page X: GETENV_COCO... */

Static Void getenv_cocolib(c, ok)
Char *c;
boolean *ok;
#ifndef CoCo_Cygwin
{
  Char *dir;

  *ok = true;
  dir = getenv("COCOLIB");
  if ( dir == NULL ){
#ifdef TRY_CURRENT
    fprintf(stderr,
	    " no COCOLIB environment variable, Trying ./\n");
    fprintf(stderr,
	    " Trying ./\n");
    dir = (Char *)Malloc(2 * sizeof(Char));
    strcpy(dir, "./\0");
#else
    fprintf(stderr,
	    " no COCOLIB environment variable.\n");
    *ok = false;
#endif
  } else
    if ( strlen(dir) >= FILE_NAME_LENGTH ){
      *ok = false;
      fprintf(stderr,
	      " COCOLIB environment variable too long.\n");
    } else
      if ( dir != NULL )
	strcpy(c, dir);
}
#else  /* CoCo_Cygwin */
{
  Char *dir;
  pch_long lib;
  long i, j;
  boolean library;

  *ok = true;
  library = false;
  dir = getenv("COCO_z_LIB");
  if ( dir == NULL ){
    /* fprintf(stderr, */ 
    printf(" no COCOLIB environment variable, \n");
    /* fprintf(stderr, */ 
    printf(" Trying .../library/CoCo/lib/coco in R_HOME \n");
    dir = getenv("R_HOME");
    if ( dir == NULL ){
      /* fprintf(stderr, */ 
      printf(" no R_HOME environment variable, \n");
      /* fprintf(stderr, */ 
      printf(" Trying .../library/CoCo/lib/coco in S_HOME \n");
      dir = getenv("S_HOME");
    }
    if ( dir == NULL ){
      /* fprintf(stderr, */ 
      printf(" no S_HOME environment variable, \n");
      /* fprintf(stderr, */ 
      printf(" Trying .../library/CoCo/lib/coco in SHOME \n");
      dir = getenv("SHOME");
    }
    if ( dir != NULL )
      library = true;
  }
  if ( dir == NULL ){
    /* fprintf(stderr, */ 
    printf(" no COCOLIB environment variable, Trying ./\n");
    /* strcpy(dir, "./\0"); */
    *ok = false;
  } else {
    if ( strlen(dir) >= FILE_NAME_LENGTH ){
      /* fprintf(stderr, */ 
      printf(" COCOLIB environment variable too long\n");
      *ok = false;
    }
    else {
      if ( dir != NULL )
	strcpy(c, dir);
      if ( library ){
	strcpy(lib, "/library/CoCo/lib/coco\0");
	i = PCH_START /* + strlen(c) */;
	my_strdhr(c, ' ', '\0', &i, (long)FILE_NAME_LENGTH);
	j = PCH_START;
	my_strcat(c, lib, ' ', &i, &j, (long)FILE_NAME_LENGTH);
	i = i + j - PCH_START;
	my_strcnt(c, '\0', &i, (long)FILE_NAME_LENGTH);
      }
    }
  }
}
#endif /* CoCo_Cygwin */


Static Void getenv_tmp(c, ok)
Char *c;
boolean *ok;
#ifndef CoCo_Cygwin
{
  Char *dir;

  *ok = true;
  dir = getenv("COCOTMP");
  if ( dir == NULL ){
    fprintf(stderr, 
	    " no COCOTMP environment variable,  \n");
    fprintf(stderr, 
	    " Trying TEMP. \n");
    dir = getenv("TEMP");
  }
  if ( dir == NULL ){
    fprintf(stderr, 
	    " no COCOTMP environment variable, \n");
    fprintf(stderr, 
	    " Trying HOME. \n");
    dir = getenv("HOME");
  }
  if ( dir == NULL ){
    fprintf(stderr,
	    " no COCOTMP environment variable, \n");
    fprintf(stderr,
	    " Trying ./\n");
    dir = (Char *)Malloc(2 * sizeof(Char));
    strcpy(dir, "./\0");
  } else
    if ( strlen(dir) >= FILE_NAME_LENGTH ){
      *ok = false;
      fprintf(stderr,
	      " COCOTMP environment variable too long.\n");
    } else
      if ( dir != NULL )
	strcpy(c, dir);
}
#else  /* CoCo_Cygwin */
{
  Char *dir;

  *ok = true;
#ifdef S_APIX
  /* Splus does not resolve "TEMP=/cygdrive/c/windows/TEMP"
     to "C:/WINDOWS/TEMP" as R and Xlispstat !!! */ 
  dir = getenv("COCOTMP");
#else /* S_APIX */
  dir = getenv("COCO_z_TMP");
#endif /* S_APIX */
  if ( dir == NULL ){
    /* fprintf(stderr, */ 
    printf(" no COCOTMP environment variable, \n");
    /* fprintf(stderr, */ 
    printf(" Trying TEMP. \n");
    dir = getenv("TEMP");
  }
  if ( dir == NULL ){
    /* fprintf(stderr, */ 
    printf(" no TEMP environment variable, \n");
    /* fprintf(stderr, */ 
    printf(" Trying TMP. \n");
    dir = getenv("TMP");
  }
  if ( dir == NULL ){
    /* fprintf(stderr, */ 
    printf(" no environment variables for temporary directory. \n");
    /* strcpy(dir, "./\0"); */
    *ok = false;
  } else {
    if ( strlen(dir) >= FILE_NAME_LENGTH ){
      /* fprintf(stderr, */
      printf(" COCOTMP environment variable too long\n");
      *ok = false;
    }
    else {
      strcpy(c, dir);
    }
  }
}
#endif /* CoCo_Cygwin */


/* page X: GET_COCO... */

Static Void get_cocolib(name, ok)
Char *name;
boolean *ok;
{
  pch_long dir;
  long i;

  if (link_coco_lib != NULL) {
    memcpy(dir, link_coco_lib, sizeof(pch_long));
    *ok = true;
  } else {
    getenv_cocolib(dir, ok);
    link_coco_lib = (Char *)Malloc(sizeof(pch_long));
    if (link_coco_lib == NULL)
      _OutMem();
      memcpy(link_coco_lib, dir, sizeof(pch_long));
  }
  if (!*ok /* dir == NULL */) {
    fprintf(stderr,
	    " - no COCOLIB environment variable.\n");
    *ok = false;
  } else {
    *ok = true;
    i = PCH_START;
    my_strchr(dir, ' ', &i, (long)FILE_NAME_LENGTH);
    if (dir[i - PCH_START - 1] != '\\' &&
        dir[i - PCH_START - 1] != '/' &&
	i < FILE_NAME_LENGTH)
      my_strcct(dir, '/', &i, (long)FILE_NAME_LENGTH);
    my_strclr(dir, ' ', i, (long)FILE_NAME_LENGTH);
    memcpy(name, dir, sizeof(pch_long));
  }
}

Static Void get_cocotmp(name, ok)
Char *name;
boolean *ok;
{
  pch_long dir;
  long i;

  if (link_coco_tmp != NULL) {
    memcpy(dir, link_coco_tmp, sizeof(pch_long));
    *ok = true;
  } else {
    getenv_tmp(dir, ok);
    link_coco_tmp = (Char *)Malloc(sizeof(pch_long));
    if (link_coco_tmp == NULL)
      _OutMem();
    memcpy(link_coco_tmp, dir, sizeof(pch_long));
  }

  if (!*ok /* dir == NULL */) {
    fprintf(stderr,
	    " -- no COCOTMP environment variable.\n");
    *ok = false;
  } else {
    *ok = true;
    i = PCH_START;
    my_strchr(dir, ' ', &i, (long)FILE_NAME_LENGTH);
    if (dir[i - PCH_START - 1] != '\\' &&
	dir[i - PCH_START - 1] != '/' &&
	i < FILE_NAME_LENGTH)
      my_strcct(dir, '/', &i, (long)FILE_NAME_LENGTH);
    my_strclr(dir, ' ', i, (long)FILE_NAME_LENGTH);
    memcpy(name, dir, sizeof(pch_long));
  }
}


/* page X: Assign, etc ... */

Static FILE *my_freopen(filename, mode, f)
Char *filename, *mode;
FILE *f;
{
#ifdef CoCo_Cygwin
  fclose(f);
  return fopen(filename, mode);
#else  /* CoCo_Cygwin */
  return freopen(filename, mode, f);
#endif /* CoCo_Cygwin */
}


Static Void assign_read(f, name_, ok)
FILE **f;
Char *name_;
boolean *ok;
{
  pch_long name;
  long i;
  Char str1[255];

  memcpy(name, name_, sizeof(pch_long));
  i = PCH_START;
  my_strchr(name, ' ', &i, (long)FILE_NAME_LENGTH);
  my_strcnt(name, '\0', &i, (long)FILE_NAME_LENGTH);
  sprintf(str1, "%.255s", name);
  if (*f != NULL)
    *f = my_freopen(str1, "r", *f);
  else
    *f = fopen(str1, "r");
  *ok = (*f != NULL);
}


Static Void assign_binary_read(f, name_, ok)
FILE **f;
Char *name_;
boolean *ok;
{
  pch_long name;
  long i;
  Char str1[255];

  memcpy(name, name_, sizeof(pch_long));
  i = 0;
  while (name[i] != '\0' && name[i] != ' ' && i++ < FILE_NAME_LENGTH);
  name[i] = '\0';
  sprintf(str1, "%.255s", name);
  if (*f != NULL)
    *f = freopen(str1, "r", *f);
  else
    *f = fopen(str1, "r");
  *ok = (*f != NULL);
}


Static Void assign_read_cocolib(f, name, ok)
FILE **f;
Char *name;
boolean *ok;
{
  pch_long dir;
  long i, j;

  get_cocolib(dir, ok);
  if (!*ok)
    return;
  i = PCH_START;
  my_strchr(dir, ' ', &i, (long)FILE_NAME_LENGTH);
  if (dir[i - PCH_START - 1] != '\\' &&
      dir[i - PCH_START - 1] != '/' &&
      i < FILE_NAME_LENGTH)
    my_strcct(dir, '/', &i, (long)FILE_NAME_LENGTH);
  j = PCH_START;
  my_strcat(dir, name, ' ', &i, &j, (long)FILE_NAME_LENGTH);
  my_strclr(dir, ' ', i + j, (long)FILE_NAME_LENGTH);
  memcpy(name, dir, sizeof(pch_long));
  assign_read(f, name, ok);
}


Static Void assign_write(f, name_, ok)
FILE **f;
Char *name_;
boolean *ok;
{
  pch_long name;
  long i;
  Char str1[255];

  memcpy(name, name_, sizeof(pch_long));
  i = PCH_START;
  my_strchr(name, ' ', &i, (long)FILE_NAME_LENGTH);
  my_strcnt(name, '\0', &i, (long)FILE_NAME_LENGTH);
  sprintf(str1, "%.255s", name);
  if (*f != NULL)
    *f = my_freopen(str1, "w", *f);
  else
    *f = fopen(str1, "w");
  *ok = (*f != NULL);
}


Static Void assign_binary_write(f, name_, ok)
FILE **f;
Char *name_;
boolean *ok;
{
  long i;
  Char str1[255];

  i = 0;
  while (name_[i] != '\0' && name_[i] != ' ' && i++ < FILE_NAME_LENGTH);
  name_[i] = '\0';
  sprintf(str1, "%.255s", name_);
  if (*f != NULL)
    *f = freopen(str1, "w", *f);
  else
    *f = fopen(str1, "w");
  *ok = (*f != NULL);
}


Static Void flush_file(f)
FILE **f;
{
#ifdef CoCo_Cygwin
  if (*f != stdout)
#endif /* CoCo_Cygwin */
    if (*f != NULL)
      fflush(*f);
  P_ioresult = 0;
}


Static Void close_file(dummy_f)
FILE *dummy_f;
{
}


Static Void close_level_file(dummy_f)
FILE *dummy_f;
{
}


/* page 4: tmpname */

Static Void get_tmp_name(ok, name, tmp_count)
     boolean *ok;
     Char *name;
     long *tmp_count;
{
  pch_long dir;
  long i, j;
  Char c;

  get_cocotmp(dir, ok);
  if (!*ok)
    return;
    i = PCH_START;
    my_strchr(dir, ' ', &i, (long)FILE_NAME_LENGTH);
    if (dir[i - PCH_START - 1] != '\\' && dir[i - PCH_START - 1] != '/' &&
	i < FILE_NAME_LENGTH)
      my_strcct(dir, '/', &i, (long)FILE_NAME_LENGTH);
    j = PCH_START;
    my_strcat(dir, name, ' ', &i, &j, (long)FILE_NAME_LENGTH);
    my_strclr(dir, ' ', i + j, (long)FILE_NAME_LENGTH);
    memcpy(name, dir, sizeof(pch_long));
    (*tmp_count)++;
    i = PCH_START;
    my_strdhr(name, ' ', 'Y', &i, (long)FILE_NAME_LENGTH);
    c = (Char)(labs(*tmp_count) / 100 + '0');
    my_strcnt(name, c, &i, (long)FILE_NAME_LENGTH);
    c = (Char)(labs(*tmp_count) % 100 / 10 + '0');
    my_strcnt(name, c, &i, (long)FILE_NAME_LENGTH);
    c = (Char)(labs(*tmp_count) % 10 + '0');
    my_strcnt(name, c, &i, (long)FILE_NAME_LENGTH);
    my_strchr(name, ' ', &i, (long)FILE_NAME_LENGTH);
    my_strcnt(name, '\0', &i, (long)FILE_NAME_LENGTH);
#ifdef __Mkstemp__
    mkstemp(name);
#else  /* __Mkstemp__ */
    mktemp(name);
    strcpy(dir, ".tmp\0");
    i = PCH_START /* + strlen(name) */;
    my_strdhr(name, ' ', '\0', &i, (long)FILE_NAME_LENGTH);
    j = PCH_START;
    my_strcat(name, dir, ' ', &i, &j, (long)FILE_NAME_LENGTH);
    i = i + j - PCH_START;
    my_strcnt(name, '\0', &i, (long)FILE_NAME_LENGTH);
#endif /* __Mkstemp__ */

}


/* page 5: textfiles */

Static Void assign_tmp_write(f, name, tmp_count, ok)
FILE **f;
Char *name;
long *tmp_count;
boolean *ok;
{
  Char str1[255];

  get_tmp_name(ok, name, tmp_count);
  if (*ok) {
    sprintf(str1, "%.255s", name);
#ifndef __Mkstemp__
#endif /* __Mkstemp__ */
    if (*f != NULL)
      *f = my_freopen(str1, "w", *f);
    else
      *f = fopen(str1, "w");
    if (*f == NULL)
      *ok = false;
    /* _EscIO(FileNotFound); */
  }
}


Static Void unlink_tmp_file(f, name, file_set)
FILE **f;
Char *name;
boolean file_set;
{
  Char str1[255];

  if (*f != NULL)
    fflush(*f);
  if (!file_set) {
    sprintf(str1, "%.255s", name);
#ifdef __CoCo_DJGPP__
    fclose(*f);
#endif
#ifdef __CoCo_BorlandC__
    fclose(*f);
#endif
    unlink(str1);
  }
}


/* page 6: cellfiles */

Static Void assign_tmp_cell_write(f, name, tmp_count)
FILE **f;
Char *name;
long *tmp_count;
{
  boolean ok;
  Char str1[255];

  get_tmp_name(&ok, name, tmp_count);
  sprintf(str1, "%.255s", name);
  if (*f != NULL)
    *f = my_freopen(str1, "wb", *f);
  else
    *f = fopen(str1, "w+b");  /* "wb" */
  if (*f == NULL)
    _EscIO(FileNotFound);
}


Static Void unlink_cell_file(f, name)
FILE **f;
Char *name;
{
  Char str1[255];

  if (*f != NULL)
    fflush(*f);
  P_ioresult = 0;
  if (*f != NULL)
    fclose(*f);
  *f = NULL;
  sprintf(str1, "%.255s", name);
  unlink(str1);
}


Static Void reassign_tmp_cell_write(f, name)
FILE **f;
Char *name;
{
  Char str1[255];

/* unlink_cell_file(*f, name); %%% */

  if (*f != NULL)
    fflush(*f);
  P_ioresult = 0;
  if (*f != NULL)
    fclose(*f);
  *f = NULL;
  sprintf(str1, "%.255s", name);
  unlink(str1);
  if (*f != NULL)
    *f = my_freopen(str1, "wb", *f);
  else
    *f = fopen(str1, "w+b");
  if (*f == NULL)
    _EscIO(FileNotFound);
}


/* page 7: levelfiles */

Static Void assign_tmp_level_write(f, name, tmp_count)
FILE **f;
Char *name;
long *tmp_count;
{
  boolean ok;
  Char str1[255];

  get_tmp_name(&ok, name, tmp_count);
  sprintf(str1, "%.255s", name);
  if (*f != NULL)
    *f = my_freopen(str1, "wb", *f);
  else
    *f = fopen(str1, "w+");  /* "wb" */
  unlink(str1);
  if (*f == NULL)
    _EscIO(FileNotFound);
}

Static Void reassign_tmp_level_file_write(f, name)
FILE **f;
Char *name;
{
  Char str1[256];

  if (*f != NULL)
    fflush(*f);
  P_ioresult = 0;
  if (*f != NULL)
    fclose(*f);
  *f = NULL;
  sprintf(str1, "%.255s", name);
  if (*f != NULL)
    *f = my_freopen(str1, "wb", *f);
  else
    *f = fopen(str1, "w+b");
  unlink(str1);
  if (*f == NULL)
    _EscIO(FileNotFound);
}


/* page 8: integerfiles */

Static Void assign_integer_file_write(f, name, tmp_count)
FILE **f;
Char *name;
long *tmp_count;
{
  boolean ok;
  Char str1[256];

  get_tmp_name(&ok, name, tmp_count);
  sprintf(str1, "%.255s", name);
  if (*f != NULL)
    *f = my_freopen(str1, "wb", *f);
  else
    *f = fopen(str1, "w+b");
  if (*f == NULL)
    _EscIO(FileNotFound);
}


Static Void unlink_integer_file(f, name)
FILE **f;
Char *name;
{
  Char str1[255];

  if (*f != NULL)
    fflush(*f);
  P_ioresult = 0;
  if (*f != NULL)
    fclose(*f);
  *f = NULL;
  sprintf(str1, "%.255s", name);
  unlink(str1);
}


Static Void reassign_integer_file_write(f, name)
FILE **f;
Char *name;
{
  Char str1[256];

  if (*f != NULL)
    fflush(*f);
  P_ioresult = 0;
  if (*f != NULL)
    fclose(*f);
  *f = NULL;
  sprintf(str1, "%.255s", name);
  if (*f != NULL)
    *f = my_freopen(str1, "wb", *f);
  else
    *f = fopen(str1, "w+b");
  if (*f == NULL)
    _EscIO(FileNotFound);
}


/* page 9: realfiles */

Static Void assign_tmp_real_write(f, name, tmp_count)
FILE **f;
Char *name;
long *tmp_count;
{
  boolean ok;
  Char str1[255];

  get_tmp_name(&ok, name, tmp_count);
  sprintf(str1, "%.255s", name);
  if (*f != NULL)
    *f = my_freopen(str1, "wb", *f);
  else
    *f = fopen(str1, "w+");  /* "wb" */
  unlink(str1);
  if (*f == NULL)
    _EscIO(FileNotFound);
}


Static Void assign_real_file_write(f, name, tmp_count)
FILE **f;
Char *name;
long *tmp_count;
{
  boolean ok;
  Char str1[256];

  get_tmp_name(&ok, name, tmp_count);
  sprintf(str1, "%.255s", name);
  if (*f != NULL)
    *f = my_freopen(str1, "wb", *f);
  else
    *f = fopen(str1, "w+b");
  if (*f == NULL)
    _EscIO(FileNotFound);
}


Static Void unlink_real_file(f, name)
FILE **f;
Char *name;
{
  Char str1[255];

  if (*f != NULL)
    fflush(*f);
  P_ioresult = 0;
  if (*f != NULL)
    fclose(*f);
  *f = NULL;
  sprintf(str1, "%.255s", name);
  unlink(str1);
}


Static Void reassign_real_file_write(f, name)
FILE **f;
Char *name;
{
  Char str1[256];

  if (*f != NULL)
    fflush(*f);
  P_ioresult = 0;
  if (*f != NULL)
    fclose(*f);
  *f = NULL;
  sprintf(str1, "%.255s", name);
  if (*f != NULL)
    *f = my_freopen(str1, "wb", *f);
  else
    *f = fopen(str1, "w+b");
  if (*f == NULL)
    _EscIO(FileNotFound);
}


/* page 10: interrupts */

#ifdef __CoCo_BorlandC__
#ifdef __cplusplus
typedef void (*fptr)(int);
#else
typedef void (*fptr)();
#endif
#endif

#ifndef NO_INTERRUPT
#ifdef __CoCo_BorlandC__
void inter_1(int *i)
#else
Static long inter_1(i)
long i;
#endif
{
  interrupt_1 = true;
  if (my_clock()/1 - last_interrupt_time_1 < DELTA_INTERRUPT)
    interrupt_2 = true;
  interrupt_count++;
  printf("interrupt (1):  %2ld%2d%10ld\n",
	 interrupt_count, i, my_clock()/1 - last_interrupt_time_1);
#ifndef MINUSLOG
  fprintf(log_file, "# interrupt (1):  %2ld%2d%10ld\n",
	  interrupt_count, i, my_clock()/1 - last_interrupt_time_1);
#endif
  last_interrupt_time_1 = my_clock()/1;
  return 0;
}


#ifdef __CoCo_BorlandC__
void inter_2(int *i)
#else
Static long inter_2(i)
long i;
#endif
{
  interrupt_1 = true;
  interrupt_2 = true;
  if (my_clock()/1 - last_interrupt_time_2 < DELTA_INTERRUPT)
    interrupt_3 = true;
  interrupt_count++;
  printf("interrupt (2):  %2ld%2d%10ld\n",
	 interrupt_count, i, my_clock()/1 - last_interrupt_time_2);
#ifndef MINUSLOG
  fprintf(log_file, "# interrupt (2):  %2ld%2d%10ld\n",
	  interrupt_count, i, my_clock()/1 - last_interrupt_time_2);
#endif
  last_interrupt_time_2 = my_clock()/1;
  return 0;
}
#endif

#include <signal.h>

Static Void set_interrupt()
{
  interrupt_count = 0;
  interrupt_1 = false;
  interrupt_2 = false;
  interrupt_3 = false;
  last_interrupt_time_1 = my_clock()/1;
  last_interrupt_time_2 = my_clock()/1;
#ifndef NO_INTERRUPT
#ifdef __CoCo_BorlandC__
  signal(SIGINT,   (fptr)inter_1);
  signal(SIGBREAK, (fptr)inter_2);
  signal(SIGTERM,  (fptr)inter_2);
#else
  signal(SIGINT,  inter_1);
  signal(SIGQUIT, inter_2);
#endif
#endif
}



Static Void set_interrupt_on_off(code)
long code;
{
  _PROCEDURE temp;

#ifndef NO_INTERRUPT
  switch (code) {

    case 1:
      signal(SIGINT, SIG_DFL);
      break;

    case 3:
#ifdef __CoCo_BorlandC__
      signal(SIGINT, (fptr)inter_1);
#else
      signal(SIGINT, inter_1);
#endif
      break;

    case 11:
#ifdef __CoCo_BorlandC__
      signal(SIGBREAK, SIG_DFL);
      signal(SIGTERM,  SIG_DFL);
#else
      signal(SIGQUIT,  SIG_DFL);
#endif
      break;

    case 13:
#ifdef __CoCo_BorlandC__
      signal(SIGBREAK, (fptr)inter_2);
      signal(SIGTERM,  (fptr)inter_2);
#else
      signal(SIGQUIT,  inter_2);
#endif
      break;
  }
#endif
}


/* page 11: resize */

Static boolean resize_n(n, size, max_cell_number)
long **n;
long size;
long *max_cell_number;
{
  long *new_n;
  FILE *temp;
/*new_n  = (long *) realloc(*n, (size+1) * sizeof(long));                  */
  new_n  = (long *) realloc(*n, (size_t) sizeof(long) * (size+1));   
  if (new_n == NULL) {
#ifndef MINUSLOG
    fprintf(log_file, 
	    " # Please ignore: Resize of N from %ld to %ld failed.\n",
           *max_cell_number , size);
    temp = log_file;
    flush_file(&temp);
#endif
    return 0;
  } else {
#ifndef MINUSLOG
    fprintf(log_file, 
	    " # Please ignore: Resize of N from %ld to %ld succeded.\n",
	    *max_cell_number , size);
    temp = log_file;
    flush_file(&temp);
#endif
    *n = new_n;
    *max_cell_number = size;
    return 1;
  }
}
 
Static boolean resize_p(p, size, max_cell_number)
float **p;
long size;
long *max_cell_number;
{
  float *new_p;
  FILE *temp;
/*new_p  = (float *) realloc(*p, (size+1) * sizeof(float));                */
/*new_p  = (float *) realloc(*p, (unsigned *)(sizeof(float) * (size+1)));  */
  new_p  = (float *) realloc(*p, (size_t)(sizeof(float) * (size+1)));   
  if (new_p == NULL) {
#ifndef MINUSLOG
    fprintf(log_file, 
	    " # Please ignore: Resize of P from %ld to %ld failed.\n",
           *max_cell_number , size);
    temp = log_file;
    flush_file(&temp);
#endif
    return 0;
  } else {
#ifndef MINUSLOG
    fprintf(log_file, 
	    " # Please ignore: Resize of P from %ld to %ld succeded.\n",
           *max_cell_number , size);
    temp = log_file;
    flush_file(&temp);
#endif
    *p = new_p;
    *max_cell_number = size;
    return 1;
  }
}

Static boolean resize_q(q, size, max_cell_number)
long **q; /* uchar **q; */
long size;
long *max_cell_number;
{
  long *new_q;  /* uchar *new_q; */
  FILE *temp;
/*new_q  = (uchar *) realloc(*q, (size+1) * sizeof(uchar));                */
  new_q  = (long *) realloc(*q, (size_t)sizeof(long) * (size+1));   
  if (new_q == NULL) {
#ifndef MINUSLOG
    fprintf(log_file, 
	    " # Please ignore: Resize of Q from %ld to %ld failed.\n",
           *max_cell_number , size);
    temp = log_file;
    flush_file(&temp);
#endif
    return 0;
  } else {
#ifndef MINUSLOG
    fprintf(log_file, 
	    " # Please ignore: Resize of Q from %ld to %ld succeded.\n",
           *max_cell_number , size);
    temp = log_file;
    flush_file(&temp);
#endif
    *q = new_q;
    *max_cell_number = size;
    return 1;
  }
}

Static boolean malloc_n(n, INIT_MAX_CELL_NUMBER, max_cell_number)
long **n;
long INIT_MAX_CELL_NUMBER;
t_long_integer *max_cell_number;
{
  long *new_n;
  new_n = (long  *)malloc((*max_cell_number+1) * sizeof(long));
  if (new_n == NULL) {
       *max_cell_number = INIT_MAX_CELL_NUMBER;
       new_n = (long  *)malloc((*max_cell_number+1) * sizeof(long));
       printf(" Warning: Unable to allocate N-array, allocated: %7d\n",
              max_cell_number);
  }
   *n = new_n;
   return (INIT_MAX_CELL_NUMBER <= *max_cell_number);
}

Static boolean malloc_p(p, INIT_MAX_P_CELL_NUMBER, max_p_cell_number)
float **p;
long INIT_MAX_P_CELL_NUMBER;
t_long_integer *max_p_cell_number;
{
  float *new_p;
  new_p = (float *)malloc((*max_p_cell_number+1) * sizeof(float));
  if (new_p == NULL) {
       *max_p_cell_number = INIT_MAX_P_CELL_NUMBER;
       new_p = (float *)malloc((*max_p_cell_number+1) * sizeof(float));
       printf(" Warning: Unable to allocate P-array, allocated: %7d\n",
              max_p_cell_number);
  }
  *p = new_p;
  return (INIT_MAX_P_CELL_NUMBER <= *max_p_cell_number);
}

Static boolean malloc_q(q_array, INIT_MAX_Q_CELL_NUMBER, max_q_cell_number)
long **q_array;
long INIT_MAX_Q_CELL_NUMBER;
t_long_integer *max_q_cell_number;
{
  long *new_q;  /* uchar *new_q; */
  new_q = (long  *)malloc((*max_q_cell_number+1) * sizeof(long));
  if (new_q == NULL) {
       *max_q_cell_number = INIT_MAX_Q_CELL_NUMBER;
       new_q = (long *)malloc((*max_q_cell_number+1) * sizeof(long));
       printf(" Warning: Unable to allocate Q-array, allocated: %7d\n",
              max_q_cell_number);
  }
  *q_array = new_q;
  return (INIT_MAX_Q_CELL_NUMBER <= *max_q_cell_number);
}

Static Void malloc_ss_array(size, ss_list)
t_long_integer size;
t_ss_list **ss_list;
{
  t_ss_list *p;

#ifdef DEBUG_RESIZE
  printf(" # Please ignore: mallocSSarray: %ld / %ld = %10.2f.\n",
	 sizeof(t_ss_array), size, (float)(sizeof(t_ss_array) / size));
#endif
  p = (t_ss_list *)Malloc(sizeof(t_ss_list));
  if (p == NULL)
    _OutMem();
  p->ss = (t_ss_r *)Malloc(sizeof(t_ss_r));
  if (p->ss == NULL)
    _OutMem();
  p->ss->z = (double *)Malloc(sizeof(t_ss_array));
  if (p->ss->z == NULL)
    _OutMem();
  p->fssa = SS_START - FIRST_INDEX;
  p->top = 0;
  p->pointer = *ss_list;
  *ss_list = p;
}  /* malloc_ss_array */


Static boolean resize_ss(ss, increment, current, max_cell_number)
double **ss; /* uchar **ss; */
long increment, current;
long *max_cell_number;
{
  long size;
  double *new_ss;  /* uchar *new_ss; */
  FILE *temp;
  size = increment + current;
#ifdef DEBUG_RESIZE
  printf(" # Please ignore: Resize of SS from %ld to %ld = %ld + %ld.\n",
	 *max_cell_number, size, increment, current);
#endif
  new_ss  = (double *) realloc(*ss, (size_t)sizeof(double) * (size+1));   
  if (new_ss == NULL) {
#ifndef MINUSLOG
    fprintf(log_file, 
	    " # Please ignore: Resize of SS from %ld to %ld failed.\n",
           *max_cell_number , size);
    temp = log_file;
    flush_file(&temp);
#endif
    return 0;
  } else {
#ifndef MINUSLOG
    fprintf(log_file, 
	    " # Please ignore: Resize of SS from %ld to %ld succeded.\n",
           *max_cell_number , size);
    temp = log_file;
    flush_file(&temp);
#endif
    *ss = new_ss;
    *max_cell_number = size;
    return 1;
  }
}

Static Void malloc_s_array(size, s_list)
t_long_integer size;
t_s_list **s_list;
{
  t_s_list *p;

#ifdef DEBUG_RESIZE
  printf(" # Please ignore: mallocSarray:  %ld / %ld = %10.2f.\n",
	 sizeof(t_s_array), size, (float)(sizeof(t_s_array) / size));
#endif
  p = (t_s_list *)Malloc(sizeof(t_s_list));
  if (p == NULL)
    _OutMem();
  p->s = (t_s_r *)Malloc(sizeof(t_s_r));
  if (p->s == NULL)
    _OutMem();
  p->s->z = (double *)Malloc(sizeof(t_s_array));
  if (p->s->z == NULL)
    _OutMem();
  p->fsa = S_START - FIRST_INDEX;
  p->top = 0;
  p->pointer = *s_list;
  *s_list = p;
}  /* malloc_s_array */


Static boolean resize_s(s, increment, current, max_cell_number)
double **s; /* uchar **s; */
long increment, current;
long *max_cell_number;
{
  long size;
  double *new_s, *tmp_s;  /* uchar *new_s; */
  FILE *temp;
  size = increment + current;
#ifdef DEBUG_RESIZE
  printf(" # Please ignore: Resize of S from %ld to %ld = %ld + %ld.\n",
	 *max_cell_number, size, increment, current);
#endif
  tmp_s  = (double *) malloc((size_t)sizeof(double) * (size+1));   
  new_s  = (double *) realloc(*s, (size_t)sizeof(double) * (size+1));   
  if (new_s == NULL) {
#ifndef MINUSLOG
    fprintf(log_file, 
	    " # Please ignore: Resize of S from %ld to %ld failed.\n",
           *max_cell_number , size);
    temp = log_file;
    flush_file(&temp);
#endif
    return 0;
  } else {
#ifndef MINUSLOG
    fprintf(log_file, 
	    " # Please ignore: Resize of S from %ld to %ld succeded.\n",
           *max_cell_number , size);
    temp = log_file;
    flush_file(&temp);
#endif
    *s = new_s;
    *max_cell_number = size;
    return 1;
  }
}

Static Void malloc_r_array(size, r_list)
t_long_integer size;
t_r_list **r_list;
{
  t_r_list *p;

#ifdef DEBUG_RESIZE
  printf(" # Please ignore: mallocRarray:  %ld / %ld = %10.2f.\n",
	 sizeof(t_r_array), size, (float)(sizeof(t_r_array) / size));
#endif
  p = (t_r_list *)Malloc(sizeof(t_r_list));
  if (p == NULL)
    _OutMem();
  p->r = (t_r_r *)Malloc(sizeof(t_r_r));
  if (p->r == NULL)
    _OutMem();
  p->r->z = (double *)Malloc(sizeof(t_r_array));
  if (p->r->z == NULL)
    _OutMem();
  p->fra = R_START - FIRST_INDEX;
  p->top = 0;
  p->pointer = *r_list;
  *r_list = p;
}  /* malloc_r_array */


Static boolean resize_r(r, increment, current, max_cell_number)
double **r; /* uchar **r; */
long increment, current;
long *max_cell_number;
{
  long size;
  double *new_r;  /* uchar *new_r; */
  FILE *temp;
  size = increment + current;
#ifdef DEBUG_RESIZE
  printf(" # Please ignore: Resize of R from %ld to %ld = %ld + %ld.\n",
	 *max_cell_number, size, increment, current);
#endif
  new_r  = (double *) realloc(*r, (size_t)sizeof(double) * (size+1));   
  if (new_r == NULL) {
#ifndef MINUSLOG
    fprintf(log_file, 
	    " # Please ignore: Resize of R from %ld to %ld failed.\n",
           *max_cell_number , size);
    temp = log_file;
    flush_file(&temp);
#endif
    return 0;
  } else {
#ifndef MINUSLOG
    fprintf(log_file, 
	    " # Please ignore: Resize of R from %ld to %ld succeded.\n",
           *max_cell_number , size);
    temp = log_file;
    flush_file(&temp);
#endif
    *r = new_r;
    *max_cell_number = size;
    return 1;
  }
}

Static Void malloc_t_array(size, t_list)
t_long_integer size;
t_t_list **t_list;
{
  t_t_list *p;

#ifdef DEBUG_RESIZE
  printf(" # Please ignore: mallocTarray:  %ld / %ld = %10.2f.\n",
	 sizeof(t_t_array), size, (float)(sizeof(t_t_array) / size));
#endif
  p = (t_t_list *)Malloc(sizeof(t_t_list));
  if (p == NULL)
    _OutMem();
  p->t = (t_t_r *)Malloc(sizeof(t_t_r));
  if (p->t == NULL)
    _OutMem();
  p->t->z = (double *)Malloc(sizeof(t_t_array));
  if (p->t->z == NULL)
    _OutMem();
  p->fta = T_START - FIRST_INDEX;
  p->top = 0;
  p->pointer = *t_list;
  *t_list = p;
}  /* malloc_t_array */


Static boolean resize_t(t, increment, current, max_cell_number)
double **t; /* uchar **t; */
long increment, current;
long *max_cell_number;
{
  long size;
  double *new_t;  /* uchar *new_t; */
  FILE *temp;
  size = increment + current;
#ifdef DEBUG_RESIZE
  printf(" # Please ignore: Resize of T from %ld to %ld = %ld + %ld.\n",
	 *max_cell_number, size, increment, current);
#endif
  new_t  = (double *) realloc(*t, (size_t)sizeof(double) * (size+1));   
  if (new_t == NULL) {
#ifndef MINUSLOG
    fprintf(log_file, 
	    " # Please ignore: Resize of T from %ld to %ld failed.\n",
           *max_cell_number , size);
    temp = log_file;
    flush_file(&temp);
#endif
    return 0;
  } else {
#ifndef MINUSLOG
    fprintf(log_file, 
	    " # Please ignore: Resize of T from %ld to %ld succeded.\n",
           *max_cell_number , size);
    temp = log_file;
    flush_file(&temp);
#endif
    *t = new_t;
    *max_cell_number = size;
    return 1;
  }
}


/* page 12: rewrite */

/*

Static Void rewrite_file(f)
FILE **f;
{
  if (*f != NULL)
    rewind(*f);
  else
    *f = tmpfile();
  if (*f == NULL)
    _EscIO(FileNotFound);
}


Static Void rewrite_cell_file(f)
FILE **f;
{
  if (*f != NULL)
    rewind(*f);
  else
    *f = tmpfile();
  if (*f == NULL)
    _EscIO(FileNotFound);
}


Static Void rewrite_level_file(f)
FILE **f;
{
  if (*f != NULL)
    rewind(*f);
  else
    *f = tmpfile();
  if (*f == NULL)
    _EscIO(FileNotFound);
}


Static Void rewrite_integer_file(f)
FILE **f;
{
  if (*f != NULL)
    rewind(*f);
  else
    *f = tmpfile();
  if (*f == NULL)
    _EscIO(FileNotFound);
}


Static Void rewrite_real_file(f)
FILE **f;
{
  if (*f != NULL)
    rewind(*f);
  else
    *f = tmpfile();
  if (*f == NULL)
    _EscIO(FileNotFound);
}

*/


/* page 13: getarg */

Static long retarg(argc, argvp, j)
int *argc;
Char **argvp[];    /* 'argvp' is a pointer to the pointer 'argv'  */
long j;            /* to the array of pointers to strings         */
{
  long i;

  switch (strlen(**argvp)) {
  case 2:
    i = j;
    break;
  case 1:
    ++*argvp;
    --*argc;
    i = atol(**argvp);
    break;
  default:
    i = atol(**argvp + 1);
    ++**argvp;
    break;
  }
  while (isdigit((++**argvp)[1]));
  return i;
}

Static int getarg(argc, argv, narg, parg, qarg, sarg, ssarg, rarg, targ, exit_a)
long *narg, *parg, *qarg, *sarg, *ssarg, *rarg, *targ;
int *exit_a;
int *argc;
Char *argv[];
{
  int i, c, found;

  printf("Number of Arguments %d\n", *argc);
  for (i = 0; i < *argc; i++)
    printf("%s%s", (argv)[i], (i < *argc - 1) ? " " : "");
  printf("\n");

  *exit_a = 0;

  found = 0;

  while (--*argc > 0) {
    ++argv;
    if (*argv[0] == '-')
      c = *++argv[0];
    else
      c = *argv[0];
    do {
      switch (c) {
      case 'C': /* 'c': Maximal lenght of case list */
	printf("Illigal option %c for Unix: Maximal lenght of case list\n", c);
	found = -1;
	break;
      case 'e': /* 'e': Terminate immediate after start up */
	*exit_a = 1;
	break;
      case 'N': /* N-array size */
	*narg = retarg(argc, &argv, *narg);
	break;
      case 'o': /* 'o':  Overlay buffer size */
	printf("Illigal option %c for Unix: Overlay buffer size\n", c);
	found = -1;
	break;
      case 'P': /* P-array size */
	*parg = retarg(argc, &argv, *parg);
	break;
      case 'Q': /* Q-array size */
	*qarg = retarg(argc, &argv, *qarg);
	break;
      case 'S': /* S-array size */
	*sarg = retarg(argc, &argv, *sarg);
	break;
      case 's': /* sS-array size */
	*ssarg = retarg(argc, &argv, *sarg);
	break;
      case 'R': /* R-array size */
	*rarg = retarg(argc, &argv, *rarg);
	break;
      case 'T': /* T-array size */
	*targ = retarg(argc, &argv, *targ);
	break;
      case 'r': /* 'r': Retry buffer size */
	printf("Illigal option %c for Unix: Retry buffer size\n", c);
	found = -1;
	break;
      case 't': /* 't':  Trace overlays */
	printf("Illigal option %c for Unix: Trace overlays\n", c);
	found = -1;
	break;
      default:
	printf("Illigal option %c\n", c);
	found = -1;
	break;
      }
    } while (c = *++argv[0]);
  }
  return found;
}

