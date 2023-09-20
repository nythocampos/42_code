#ifndef  _TESTLIB_H
# define _TESTLIB_H

int		asser_equals(char *fun_name, int a, int b);
int		assert_true(char *fun_name, int a);
int		assert_false(char *fun_name, int a);
int		assert_null(char *fun_name, int *ptr);
int		assert_array_equals(char *fun_name, int *array, int *array2);

# endif

