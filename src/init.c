int	init_data(t_data *data, char **argv, int argc)
{
	//TODO: init data with the data input , check for
	//valid data entry.
	return (0);
}

int	alloc(t_data *data)
{
	//TODO: allocate t_data on mem
}

int	init_forks(data)
{
	//init forks.
}

void	init_philos(t_data *data)
{
	//init philos.
}
int init(t_data *data, char **argv, int argc)
{
	if (init_data(data, argv, argc))
		return (1);
	if (alloc(data))
		return (1);
	if (init_forks(data))
		return (1);
	init_philos(data);
	return (0);
}
