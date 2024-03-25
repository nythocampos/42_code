/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_vars.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:58:04 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/25 14:21:18 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define COLOR_A	0x00000000
#define COLOR_B	0x33FFC4
#define WIDTH	1200
#define HEIGHT	700 
#define MAPS_PATH ""

#if defined(__APPLE__) || (__MACH__)
# define M_FORWARD 13
# define M_BACKWARD 1
# define M_LEFT 0
# define M_RIGHT 2
# define M_UP 14
# define M_DOWN 12

# define R_POS_X 34
# define R_NEG_X 40
# define R_NEG_Y 38
# define R_POS_Y 37
# define R_NEG_Z 32
# define R_POS_Z 31

# define S_PLUS 24
# define S_LESS 27
#elif defined(__linux__)
# define M_FORWARD 119
# define M_BACKWARD 115
# define M_LEFT 97
# define M_RIGHT 100
# define M_UP 101
# define M_DOWN 113

# define R_POS_X 105
# define R_NEG_X 107
# define R_NEG_Y 106
# define R_POS_Y 108
# define R_NEG_Z 117
# define R_POS_Z 111

# define S_PLUS 43
# define S_LESS 45
#endif
