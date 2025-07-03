#include <unistd.h>

#define BUFFER_SIZE 1024 //Standard buffer size (1024 bytes = 1 KB)

int get_next_line(char **line)
{
	char	buffer[BUFFER_SIZE]; //Buffer to store read characters
	char	*buff_ptr; //Track position in buffer so far
	char	*line_ptr; //Track position in existing line
	char	*temp_line; //Temporary pointer for managing memory allocation
	char	*new_line; //Pointer to the enw line
	ssize_t	bytes_read; //Store number of current bytes read. ssize_t can account for negative values (errors) returned by read(), as 0 = EOF (not an error)
	size_t	total_read; //Track the total number of bytes read so far, which helps in managing the size of the allocated memory for `line` and appending new data

	total_read = 0; //Initialize total bytes read

	*line = malloc(1 * sizeof(char)); //Ensure `line` points to valid memory allocation, 1 byte for '\0'. This makes `line` free-able, and return an empty string if no data
	if (!*line) //Check if malloc failed
		return (-1); //Return -1 to indicate error as per subject.en.txt
	*line[0] = '\0'; //Initialize `line` to an empty string

	while ((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0) //Read from fd 0 (stdin) in chunks
	{
		buff_ptr = buffer; //Point to the current position in buffer
		while (bytes_read > 0) //Iterate over each character read
		{
			if (buff_ptr == '\n') //Check for newline character
			{
				*line[total_read] = '\0'; //Null-terminate the line
				return (1); //Return 1 to indicate a line has been read
			}
			//Allocate memory for the new line
			*temp_line = malloc(total_read + 2); //+1 for '\n' +1 for '\0'
			if (!temp_line) //Check if malloc failed
			{
				free(*line); //Free previously allocated memory before exiting
				return (-1); //Return -1 to indicate error
			}
			//Copy existing characters to the new line
			line_ptr = *line; //Pointer to current position in existing line
			new_line = temp_line; //Pointer to the new line
			while (total_read > 0) //Iterate over each character in existing line
			{
				*new_line++ = *line_ptr++; //Copy character from existing line to new line
				total_read--; //Decrement total bytes read
			}
			//Finalise the new line and prepare for the next line
			*new_line++ = *buff_ptr; //Add the new character todo dont understand
		}
	}
}
