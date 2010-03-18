
#ifdef R_APIX
#include "apix-R.h"
#else
  #ifdef S_APIX
  #include "apix-S.h"
  #else
    #ifdef X_APIX
    #include "apix-X.h"
    #else
    #endif /* X_APIX */
  #endif /* S_APIX */
#endif /* R_APIX */

#define SCOCO

#ifndef DCOCO
#include "coco_.c"
#else
#include "coco_d_.c"
#endif

#define Ended_CoCo 2147483647L
#define Fixed_CoCo 2147483646L
#define No_ifail            0
#define No_ifail_return   (-1)
#define CoCo_ended_ifail    1
#define Apix_Version      140


/* *************************************************************** */
Local void CoCo_Init(ifail, note_start, nargs, arg_char,
		     arg_int, arg_double, arg_char_int, LINK_INT)
long *nargs, *arg_int, *ifail, note_start, *LINK_INT;
char **arg_char;
double *arg_double;
{
  t_char_array **arg_char_ref;

  /* The following gives problems in "trace_flag_set": */

  /*
  if (!ok_int_arg(ifail, 1, 3, &nargs, &arg_int))
    return;
  if (!ok_double_arg(ifail, 2, 1, &nargs, &arg_double))
    return;
  */

  arg_char_ref = (t_char_array **)arg_char; 
  file_excluded = NULL;
  file_read = NULL;
  spec_file = NULL;
  data_file = NULL;
  if (note_start == 1l) {
    report_file = NULL;
    dump_file = NULL;
    log_file = NULL;
    diary_file = NULL;
  }
  start_coco_s(1l, note_start, ifail, &nargs,
	       *(arg_int), *(arg_int+1), *(arg_int+2),
	       *(arg_int+3), *(arg_int+4), *(arg_int+5), *(arg_int+6),
	       arg_char_ref, &arg_int, &arg_double, &arg_char_int);
  if (ifail == 0)
    read_start_up_files();
  if (*arg_double == -1) {
#ifdef MY_NA
    my_var_na_float = MY_NA_FLOAT;
    my_var_na_double = MY_NA_DOUBLE;
#else
    my_var_na_float = (float)quiet_nan();
    my_var_na_double = quiet_nan();
#endif
  } else {
    my_var_na_float = (float)*arg_double;
    my_var_na_double = *arg_double;
  }
  *LINK_INT = Fixed_CoCo;
  if (ifail == 0)
     *ifail = Apix_Version;
}

Local void CoCo_Main(ifail)
long *ifail;
{
  write_pch(stdout, "CoCo>", 5l);       /* install interrupt-handlers */
  main_coco(stdin, false);   /* re-install default interrupt-handlers */
  *ifail = 0;
}


/* *************************************************************** */
Local void CoCo_End(ifail)
long *ifail;
{
  end_coco();
  if (diary_file != NULL)
    fclose(diary_file);
  if (log_file != NULL)
    fclose(log_file);
  if (dump_file != NULL)
    fclose(dump_file);
  if (report_file != NULL)
    fclose(report_file);
  if (data_file != NULL)
    fclose(data_file);
  if (spec_file != NULL)
    fclose(spec_file);
  if (file_read != NULL)
    fclose(file_read);
  if (file_excluded != NULL)
    fclose(file_excluded);
  *ifail = 0;
}

Local void command_implemented(ifail, LINK_INT, code, sub_code)
long *ifail, *LINK_INT, *code, *sub_code;
#ifdef R_APIX
{
  if (( -1 == *code)) /* coco.resume() */ {
    /* *ifail = 3; */
    printf("R+CoCo: Do not enter CoCo in R+CoCo under Windows.\n");
  }
  if (( -3 == *code)) /* coco.start() */ {
    /* *ifail = 3; */
    printf("R+CoCo: Do not enter CoCo in R+CoCo under Windows.\n");
  }
  /* 
   * if (( 93 == *code) && (2 <= *sub_code))
   *   printf("R+CoCo: File as datastructure not available in R+CoCo under Windows (LevelFile)\n");
   * if (( 93 == *code) && (5 == *sub_code))
   *   printf("R+CoCo: HUGE not available in R+CoCo under Windows (IntegerFile)\n");
   * if ((115 == *code) && (5 == *sub_code))
   *   printf("R+CoCo: No sorted list for large tables (RealFile)\n");
   */
  if ((  1 <= *code) && (*code <=   1))
    printf("R+CoCo: Restart not avaliable in R+CoCo under Windows\n");
  if ((  2 <= *code) && (*code <=  10))
    printf("R+CoCo: Modification of parser not to be available in R+CoCo under Windows\n");
  /* 
   : if (( 14 <= *code) && (*code <=  14))
   :   printf("R+CoCo: Export not available in R+CoCo\n");
   */
  if (( 15 <= *code) && (*code <=  15))
    printf("R+CoCo: Import not available in R+CoCo\n");
  /* 
   * if (( 23 <= *code) && (*code <=  23))
   *   printf("R+CoCo: No CoCo-commands from files in R+CoCo under Windows\n");
   */
  if (( 26 <= *code) && (*code <=  27))
    printf("R+CoCo: No redirection of standard output in R+CoCo under Windows\n");
  /*
   * if ((106 <= *code) && (*code <= 107)) {
   *   printf("R+CoCo: Q-data can not be read from standard output");
   *   printf("        / files in R+CoCo under Windows\n");
   * }
   */
}
#else
#ifdef S_APIX
{
  if (( -1 == *code)) /* coco.resume() */ {
    *ifail = 3;
    printf("S+CoCo: Do not enter CoCo in S+CoCo under windows.\n");
  }
  if (( -3 == *code)) /* coco.start() */ {
    *ifail = 3;
    printf("S+CoCo: Do not enter CoCo in S+CoCo under windows.\n");
  }
  if (( 93 == *code) && (2 <= *sub_code))
    printf("S+CoCo: File as datastructure not available in S+CoCo under windows (LevelFile)\n");
  if (( 93 == *code) && (5 == *sub_code))
    printf("S+CoCo: HUGE not available in S+CoCo under windows (IntegerFile)\n");
  if ((115 == *code) && (5 == *sub_code))
    printf("S+CoCo: No sorted list for large tables (RealFile)\n");
  if ((  1 <= *code) && (*code <=   1))
    printf("S+CoCo: Restart not avaliable in S+CoCo under windows\n");
  if ((  2 <= *code) && (*code <=  10))
    printf("S+CoCo: Modification of parser not to be available in S+CoCo under windows (ungetc / EOLN)\n");
  /* if (( 14 <= *code) && (*code <=  14))
     printf("S+CoCo: Export not available in S+CoCo under windows (ungetc / EOLN)\n"); */
  if (( 15 <= *code) && (*code <=  15))
    printf("S+CoCo: Import not available in S+CoCo under windows (ungetc / EOLN)\n");
  if (( 23 <= *code) && (*code <=  23))
    printf("S+CoCo: No CoCo-commands from files in S+CoCo under windows (ungetc / EOLN)\n");
  if (( 26 <= *code) && (*code <=  27))
    printf("S+CoCo: No redirection of standard output in S+CoCo under windows\n");
  if (( 19 <= *code) && (*code <=  22))
    printf("S+CoCo: Data can not be read from files in S+CoCo under windows (ungetc / EOLN)\n");
  if (( 88 <= *code) && (*code <=  88))
    printf("S+CoCo: Data can not be read from files in S+CoCo under windows (ungetc / EOLN)\n");
  if (( 89 <= *code) && (*code <=  91))
    printf("S+CoCo: Specification can not be read from files in S+CoCo under windows (ungetc / EOLN)\n");
  if ((103 <= *code) && (*code <= 105))
    printf("S+CoCo: Observations can not be read from files in S+CoCo under windows (ungetc / EOLN)\n");
  if ((106 <= *code) && (*code <= 107))
    printf("S+CoCo: Q-data can not be read from files in S+CoCo under windows (ungetc / EOLN)\n");
}
#else
#ifdef X_APIX
{
  if (( -1 == *code)) /* coco.resume() */ {
    *ifail = 3;
    printf("X+CoCo: Do not enter CoCo in X+CoCo under windows.\n");
  }
  if (( -3 == *code)) /* coco.start() */ {
    *ifail = 3;
    printf("X+CoCo: Do not enter CoCo in X+CoCo under windows.\n");
  }
  if (( 93 == *code) && (2 <= *sub_code))
    printf("X+CoCo: File as datastructure not available in X+CoCo under windows (LevelFile)\n");
  if (( 93 == *code) && (5 == *sub_code))
    printf("X+CoCo: HUGE not available in X+CoCo under windows (IntegerFile)\n");
  if ((115 == *code) && (5 == *sub_code))
    printf("X+CoCo: No sorted list for large tables (RealFile)\n");
  if ((  1 <= *code) && (*code <=   1))
    printf("X+CoCo: Restart not avaliable in X+CoCo under windows\n");
  if ((  2 <= *code) && (*code <=  10))
    printf("X+CoCo: Modification of parser not to be available in X+CoCo under windows (ungetc / EOLN)\n");
  /* if (( 14 <= *code) && (*code <=  14))
     printf("X+CoCo: Export not available in X+CoCo under windows (ungetc / EOLN)\n"); */
  if (( 15 <= *code) && (*code <=  15))
    printf("X+CoCo: Import not available in X+CoCo under windows (ungetc / EOLN)\n");
  if (( 23 <= *code) && (*code <=  23))
    printf("X+CoCo: No CoCo-commands from files in X+CoCo under windows (ungetc / EOLN)\n");
  if (( 26 <= *code) && (*code <=  27))
    printf("X+CoCo: No redirection of standard output in X+CoCo under windows\n");
  if (( 19 <= *code) && (*code <=  22))
    printf("X+CoCo: Data can not be read from files in X+CoCo under windows (ungetc / EOLN)\n");
  if (( 88 <= *code) && (*code <=  88))
    printf("X+CoCo: Data can not be read from files in X+CoCo under windows (ungetc / EOLN)\n");
  if (( 89 <= *code) && (*code <=  91))
    printf("X+CoCo: Specification can not be read from files in X+CoCo under windows (ungetc / EOLN)\n");
  if ((103 <= *code) && (*code <= 105))
    printf("X+CoCo: Observations can not be read from files in X+CoCo under windows (ungetc / EOLN)\n");
  if ((106 <= *code) && (*code <= 107))
    printf("X+CoCo: Q-data can not be read from files in X+CoCo under windows (ungetc / EOLN)\n");
}
#else
{
}
#endif /* X_APIX */
#endif /* S_APIX */
#endif /* R_APIX */

void Mips(ifail, LINK_INT, code, sub_code, n_arg, arg_char,
	  arg_int, arg_double, arg_char_int)
long *ifail, *LINK_INT, *code, *sub_code, *n_arg;
char **arg_char;
long *arg_int; /* Note, not int!!! */
double *arg_double;
long *arg_char_int; /* Note, not int!!! */
{
  long num_obj;
  t_char_array **arg_char_ref;

  arg_char_ref = (t_char_array **)arg_char;
  if (sub_code == NULL)
    num_obj = 0;
  else
    num_obj = *sub_code;

  command_implemented(ifail, LINK_INT, code, sub_code);
  if (*ifail == 0) {
    if (*code < -1) {
      if (num_obj == 0 /* NULL */)
        CoCo_Init(ifail, 1l, n_arg, arg_char,
		  arg_int, arg_double, arg_char_int, LINK_INT);
      else
        CoCo_Init(ifail, 0l, n_arg, arg_char,
		  arg_int, arg_double, arg_char_int, LINK_INT);
      if (*code == -3)
	CoCo_Main(ifail); /* ifail changed from Apix_Version to 0 !!! */
    } else {
      if (*LINK_INT == Ended_CoCo) {
	*ifail = CoCo_ended_ifail;
	return;
      }
      *ifail = 0;
      if (*code < 1) {
	if (*code == 0)
	  CoCo_End(ifail);
	else 
	  CoCo_Main(ifail);
      } else {
	external_main_case(stdin, ifail, code, sub_code, &n_arg, arg_char_ref,
			   &arg_int, &arg_double, &arg_char_int);
      }
    }
  }
}

/* *************************************************************** */
