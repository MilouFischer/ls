/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_str.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:29:42 by efischer          #+#    #+#             */
/*   Updated: 2019/05/14 15:35:11 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_STR_H
# define PROCESS_STR_H

char				*ft_join_free(char *s1, char *s2, int op);
char				*ft_strcapitalize(char *str);
char				*ft_strcat(char *s1, const char *s2);
void				ft_strclr(char *s);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strlowcase(char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strndup_free(char *s1, size_t n);
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strupcase(char *str);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					get_next_line(const int fd, char **line);

#endif
