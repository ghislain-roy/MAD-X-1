#ifndef MAD_CMDPAR_H
#define MAD_CMDPAR_H

// types

struct command;
struct element;
struct expression;
struct expr_list;
struct double_array;
struct char_p_array;
struct el_list;
struct var_list;

struct command_parameter        /* holds one command parameter */
{
  char name[NAME_L];
  int type;                           /* 0 logical 1 integer 2 double
                                         3 string 4 constraint */
                                      /* 11 int array 12 double array
                                         13 string array */
  int c_type;                         /* for type 4:
                                         1 min, 2 max, 3 both, 4 value */
  double double_value;                /* type 0, 1, 2, 4 */
  double c_min;                       /* type 4 */
  double c_max;                       /* type 4 */
  struct expression* expr;            /* type 1, 2, 4 */
  struct expression* min_expr;        /* type 4 */
  struct expression* max_expr;        /* type 4 */
  char* string;                       /* type 3 */
  int stamp;
  struct double_array* double_array;  /* type 11, 12 */
  struct expr_list* expr_list;        /* type 11, 12 */
  struct char_p_array* m_string;      /* type 13 */
  struct command_parameter* call_def; /* contains definitions for "bare"
                                         parameter input, e.g. option,echo */
};

struct command_parameter_list /* contains list of command parameter pointers */
{
  int stamp;
  char name[NAME_L];
  int  max,                               /* max. pointer array size */
       curr;                              /* current occupation */
  struct command_parameter** parameters;  /* command_parameter pointer list */
};

// interface

struct command_parameter*       new_command_parameter(char* name, int type);
struct command_parameter_list*  new_command_parameter_list(int length);
struct command_parameter*       clone_command_parameter(struct command_parameter*);
struct command_parameter*       delete_command_parameter(struct command_parameter*);
struct command_parameter_list*  delete_command_parameter_list(struct command_parameter_list*);
struct command_parameter*       store_comm_par_def(char* toks[], int start, int end);

void    check_table(char* string);
struct expression* command_par_expr(char* parameter, struct command*);
double  command_par_special(char* parameter, struct element*);
char*   command_par_string(char* parameter, struct command*);
double  command_par_value(char* parameter, struct command*);
int     command_par_value2(char* parameter, struct command*, double* val);
struct double_array* command_par_array(char* parameter, struct command*);
int     command_par_vector(char* parameter, struct command*, double* vector);
void    set_command_par_value(char* parameter, struct command*, double val);
void    store_comm_par_value(char* parameter, double val, struct command*);
char*   alias(char* par_string);
void    fill_par_var_list(struct el_list*, struct command_parameter*, struct var_list*);
int     decode_par(struct in_cmd* cmd, int start, int number, int pos, int log);
void    store_set(struct command*, int flag);
void    dump_command_parameter(struct command_parameter*);
void    export_comm_par(struct command_parameter*, char* string);
void    grow_command_parameter_list(struct command_parameter_list*);
void    print_command_parameter(struct command_parameter*);
int     par_present(char* par, struct command*, struct command_list*);
void    store_comm_par_vector(char* parameter, double* val, struct command*);
void    add_cmd_parameter_clone(struct command*, struct command_parameter*,char* par_name,int inf);
void    add_cmd_parameter_new(struct command*,double par_value,char* par_name,int inf);
void    comm_para(char* name, int* n_int, int* n_double, int* n_string, int* int_array, double* double_array, char* strings, int* string_lengths);
int     log_val(char* name, struct command*);

// void    set_command_par_string(char* parameter, struct command*, char* val); // not used...

// used by Fortran
double  get_value (char* name, char* par);
int     get_string(char* name, char* par, char* string);
int     get_vector(char* name, char* par, double* vector);
void    set_value (char* name, char* par, double* value);

#endif // MAD_CMDPAR_H

