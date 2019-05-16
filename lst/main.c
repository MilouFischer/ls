#include "libft.h"

static void	ft_printlist(t_list *lst)
{
	while (lst != NULL)
	{
		ft_putendl("YO");
		ft_putendl(lst->content);
		lst = lst->next;
	}
}

int		main(void)
{
	char	*tab[3] = { "toto", "tata", "titi" };
	t_list	*lst;
	t_list	*tmp;
	size_t	i;

	i = 0;
	lst = NULL;
	tmp = lst;
	while (i < 3)
	{
		ft_lstadd(&lst, ft_lstnew(tab[i], ft_strlen(tab[i])));
		ft_putendl(lst->content);
		lst = lst->next;
		i++;
	}
	ft_lstprint(tmp);
	return (0);
}
