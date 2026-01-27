
int main(int argc, char **argv)
{
	if(argc == 2)
		run_game(argv[1]);
	else
		printf("doofus");
}

void run_game(char *map_name)
{
	parsing();
	execution();
}
