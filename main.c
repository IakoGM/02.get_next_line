#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		counter;
    char    *printer;

    counter = 0;
	printer = "";
	fd = open("files/41_no_nl", O_RDONLY);
	if (fd == -1)
	{
		printf("No se ha podido abrir el archivo.\n");
		return (0);
	}
	printf("El fd es: %d\n", fd);
	while (printer != NULL)
	{
		printer = get_next_line(fd);
		if (printer == NULL)
			break ;
		counter++;
		printf("%d : %s\n", counter, printer);
	}
	close(fd);
	return (0);
}
