#ifndef MAD_NAME_H
#define MAD_NAME_H

// types

struct name_list;
struct double_array;

struct name_list /* contains list of index sorted names plus int inform. */
{
  char name[NAME_L];
  int  max,                     /* max. pointer array size */
       curr;                    /* current occupation */
  int* index;                   /* index for alphabetic access */
  int* inform;                  /* array parallel to names with integer */
  int stamp;
  char** names;                 /* element names for sort */
};

struct vector_list              /* contains named vectors */
{
  int curr, max;
  struct name_list* names;
  struct double_array** vectors;
};

// interface

char*   get_new_name(void);

struct name_list*  new_name_list(char* list_name, int length);
struct name_list*  clone_name_list(struct name_list*);
struct name_list*  delete_name_list(struct name_list*);
void               dump_name_list(struct name_list*);
void               copy_name_list(struct name_list* out, struct name_list* in);
void               grow_name_list(struct name_list*);
int                add_to_name_list(char* name, int inf, struct name_list*);
int                name_list_pos(char* p, struct name_list*);

struct vector_list* new_vector_list(int length);
struct vector_list* delete_vector_list(struct vector_list*);
void                grow_vector_list(struct vector_list*);

#endif // MAD_NAME_H

