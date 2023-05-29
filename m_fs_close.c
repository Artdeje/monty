#include "monty.h"

/**
 * m_fs_close - closes file stream
 * @status: exit status
 * @arg: pointer to arguments
 *
 * Return: nothing
 */

void m_fs_close(int status, void *arg)
{
	FILE *fs;

	(void)status;

	fs = (FILE *) arg;

	fclose(fs);
}
