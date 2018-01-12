
#include "ClientSocket.h"

int main(int argc, char *argv[])
{	
	if (argc == 5)
	{
		// === The next few lines delete the existing data in the log file ===
		errno_t retval;
		FILE *p_stream;
		retval = fopen_s(&p_stream, argv[1], "w");
		if (0 != retval)
		{
			printf("Failed to open file.\n");
			return -1;
		}
		retval = fputs("\0", p_stream);
		retval = fclose(p_stream);
		if (0 != retval)
		{
			printf("Failed to close file.\n");
			return -1;
		}
		// ====================================================================

		MainClient(argv[1], argv[2], argv[3], argv[4]);
	}
	else
	{
		printf("Invalid arguments\n");
		return -1;
	}
	
}