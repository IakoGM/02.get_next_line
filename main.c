#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		counter;
    char    *printer;

    counter = 0;
	fd = open("files/nl", O_RDONLY);
	if (fd == -1)
	{
		printf("No se ha podido abrir el archivo.\n");
		return (0);
	}
	printf("El fd es: %d\n", fd);
	while (printer != NULL)
	{
		printer = get_next_line(fd);
		counter++;
		printf("\e[36m%d : [\e[0m%s\e[36m]\e[0m\n", counter, printer);
	}
	close(fd);
	return (0);
}
