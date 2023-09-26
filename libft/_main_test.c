/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:57:54 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/14 11:57:55 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "_testlib.h"
#include <stdio.h>
#include <ctype.h>
//alias run_test="echo Building tests... | gcc *.c -o _tests | echo Running tests... | ./_tests"

int	test_ft_strncomp(void)
{
	const char	a[20]= "\x12\xff\x65\x12\xbd\xde\xad";
	const char	b[20]= "\x12\x02";
	int			num = 6;
	int			result1;
	int			result2;

	result1 = strncmp(a, b, num);
	result2 = ft_strncmp(a, b, num);
	printf("test_ft_strrchr \n");
	printf("Real function result: %d \n", result1);
	printf("Fake function result: %d \n", result2);
	return (0);
}

// int	test_ft_strrchr(void)
// {
// 	const char	a[20]= "hello world";
// 	char		to_find = 'o';
// 	char		*result1;
// 	char		*result2;

// 	result1 = strrchr(a, to_find);
// 	result2 = ft_strrchr(a, to_find);
// 	printf("test_ft_strrchr \n");
// 	printf("Real function result: %s \n", result1);
// 	printf("Fake function result: %s \n", result2);
// 	return (0);
// }

// int	test_ft_strchr(void)
// {
// 	const char	a[20]= "hello world";
// 	char		to_find = 'o';
// 	char		*result1;
// 	char		*result2;

// 	result1 = strchr(a, to_find);
// 	result2 = ft_strchr(a, to_find);
// 	printf("test_ft_strchr \n");
// 	printf("Real function result: %s \n", result1);
// 	printf("Fake function result: %s \n", result2);
// 	return (0);
// }

// int	test_ft_memmove(void)
// {

// 	char		b[20];
// 	char		b2[20];
// 	int			num = 5;

// 	memmove((void *)b + 3, (const void *)a, num);
// 	ft_memmove((void *)b2 + 3, (const void *)a, num);
// 	printf("Real function result: %s \n", b);
// 	printf("Fake function result: %s \n", b2);
// 	return (0);
// }

// int	test_ft_memcpy(void)
// {
// 	const char	a[20]= "hello world";
// 	char		b[20];
// 	char		b2[20];
// 	int			num = 5;

// 	memcpy((void *)b + 3, (void *)a, num);
// 	ft_memcpy((void *)b2 + 3, (void *)a, num);
// 	printf("Real function result: %s \n", b);
// 	printf("Fake function result: %s \n", b2);
// 	return (0);
// }

// int	test_ft_bzero(void)
// {
// 	int	a[10]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// 	int	a2[10]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// 	int	num = 20;
// 	int loop;

// 	bzero(a, num);
// 	ft_bzero(a2, num);
// 	/*
// 	assert_array_equals(
// 		(char *)__func__,
// 		a,
// 		a2
// 		);
// 	*/
// 	for(loop = 0; loop < 10; loop++)
//     	printf("a: %d, a2: %d \n", a[loop], a2[loop]);
// 	return (0);
// }

// //memset
// int	test_ft_memset(void)
// {
// 	char	str[20] = "hello world";
// 	char	str2[20] = "hello world";
// 	int		character;
// 	int		num;

// 	strcpy(str,"hello world");
// 	strcpy(str2,"hello world");
// 	character = '^';
// 	num = 2;
// 	assert_array_equals(
// 		(char *)__func__,
// 		(int *)memset(str, character, num),
// 		(int *)ft_memset(str2, character, num)
// 		);
// 	printf("print result: %s \n\n", str);

// 	strcpy(str,"hello world");
// 	strcpy(str2,"hello world");
// 	character = '%';
// 	num = 5;
// 	assert_array_equals(
// 		(char *)__func__,
// 		(int *)memset(str, character, num),
// 		(int *)ft_memset(str2, character, num)
// 		);
// 	printf("print result: %s \n\n", str);

// 	strcpy(str,"hello world");
// 	strcpy(str2,"hello world");
// 	character = '%';
// 	num = 7;
// 	assert_array_equals(
// 		(char *)__func__,
// 		(int *)memset(str, character, num),
// 		(int *)ft_memset(str2, character, num)
// 		);
// 	printf("print result: %s \n\n", str);
// 	printf("\n\n\n");
// 	return (0);
// }

// //strlen
// int	test_ft_strlen(void)
// {
// 	char	text[10] = "perro";
// 	char	*pointer;
// 	int		result;

// 	pointer = &text[0];
// 	result = strlen(pointer);
// 	result = ft_strlen(pointer);

// 	printf("ft_strlen: ");
// 	//asser_equals(__func__, result, result);
// 	printf("%d", result);
// 	printf("\n\n\n");
// 	return (0);
// }

// //isprint
// int	test_ft_isprint(void)
// {
// 	int	test_value;

// 	test_value = 0;
// 	printf("input used: 			%d \n", test_value);
// 	printf("Real function result: 	%d \n", isprint(test_value));
// 	printf("Fake function result: 	%d \n", ft_isprint(test_value));
// 	printf("\n\n\n");
// 	return (0);
// }


// //isdigit
// int	test_ft_isascii(void)
// {
// 	int	test_value;

// 	test_value = 'a';
// 	printf("value: 	%d \n", test_value);
// 	printf("Real: 	%d \n", isascii(test_value));
// 	printf("Fake: 	%d \n", ft_isascii(test_value));
// 	printf("\n\n\n");
// 	return (0);
// }

// // isalnum
// int	test_ft_isalnum(void)
// {
// 	int	test_value;

// 	test_value = 0;
// 	printf("value: %d \n", test_value);
// 	printf("Real: %d \n", isdigit(test_value));
// 	printf("Fake: %d \n", ft_isdigit(test_value));
// 	printf("\n\n\n");
// 	return (0);
// }

// //is_digit
// int	test_ft_isdigit(void)
// {
// 	int	test_value;

// 	test_value = 57;
// 	printf("value: %d \n", test_value);
// 	printf("Real: %d \n", isdigit(test_value));
// 	printf("Fake: %d \n", ft_isdigit(test_value));
// 	printf("\n\n\n");
// 	return (0);
// }

// //isalpha
// int	test_isalpha(void)
// {
// 	int	test_value;

// 	test_value = 'z';
// 	printf("value: %d \n", test_value);
// 	printf("Real: %d \n", isalpha(test_value));
// 	printf("Fake: %d \n", ft_isalpha(test_value));
// 	printf("\n\n\n");
// 	return (0);
// }

/*int	main(void)
{
	test_ft_strncomp();
	printf("\n\n");
	//test_ft_strchr();
	//printf("\n\n");
	return (0);
}*/
