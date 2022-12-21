
#include "./includes/libft.h"


int main()
{
    int fd = open("Makefile", O_RDONLY);
    printf("fd: %d\n", fd);
    char *str = get_next_line(fd);
	printf("One: %s\n", str);
	while(str)
	{
        if(ft_isalpha(str[0]))
		    printf("Two: %s\n", str);
		// printf("Two--c: |%c|\n", str[0]);
		str = get_next_line(fd);
	}
    return 0;
}