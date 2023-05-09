/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:18:51 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 11:46:47 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_substrcounter(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
		if (*s++ != c && (*s == '\0' || *s == c))
			count++;
	return (count);
}

static int	ft_substrlen(char const *s, char c, int pos)
{
	int	len;

	len = 0;
	while (s[pos] != c && s[pos])
	{
		len++;
		pos++;
	}
	return (len);
}

static void	ft_free(char **strings, int k)
{
	while (k-- > 0)
		free(strings[k]);
	free(strings);
}

static char	**ft_fill(char const *s, int subsn, char c, char **strings)
{
	int	sc;
	int	skipc;
	int	pos;

	sc = 0;
	skipc = 0;
	while (sc < subsn)
	{
		while (s[skipc] == c)
			skipc++;
		pos = ft_substrlen(s, c, skipc);
		strings[sc] = ft_substr(s, skipc, pos);
		if (strings[sc] == NULL)
		{
			ft_free (strings, sc);
			return (NULL);
		}
		skipc += pos;
		sc++;
	}
	strings[sc] = 0;
	return (strings);
}

/*split string, with specified character as delimiter, into an array of strings
-Allocates (with malloc(3)) and returns an array of strings obtained by
splitting ’s’ using the character ’c’ as a delimiter. The array must be
ended by a NULL pointer.*/
char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		subsn;

	subsn = ft_substrcounter(s, c);
	strings = (char **)malloc((subsn + 1) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	strings = ft_fill(s, subsn, c, strings);
	return (strings);
}
