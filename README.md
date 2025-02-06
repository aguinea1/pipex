<h1 align="center">
	PIPEX
</h1>
Pipex is a project that involves using some Bash commands (such as cat, grep, ls, etc.) and replicating the behavior of the pipeline "< file1 command1 | command2 > file2", with the following execution format "./pipex file1 command1 command2 file2". In other words, the goal is to redirect the input and output of commands just like a Bash pipeline would.
  
  ---
## › Functions I used

| Function | Description |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `OPEN`   | `open(const char *pathname, int flags, mode_t mode)` – This function is used to open files and obtain a file descriptor, which can then be used to read, write, or manipulate the file. This function returns the integer of the FD, or in case of failure, it returns -1. |
|          | The flags I used are: |
|          |   - > `O_RDONLY` is used to open the file in read-only mode. |
|          |   - > `O_WRONLY` is used to open the file in write-only mode. |
|          |   - > `O_TRUNC` is used to truncate the file to zero length if it already exists. |
|          |   - > `O_APPEND` is used to append data to the end of the file without modifying its existing content. |
|          |   - >`O_CREAT` is used to create a file if it doesn't exist when opening. | 
| `DUP2`   | `dup2(int oldfd, int newfd)` – This function duplicates a file descriptor. It copies the file descriptor `oldfd` to the file descriptor `newfd`. If `newfd` is already open, it is closed before being reused. The function returns the new file descriptor (`newfd`) or -1 in case of an error. To be clear: It is used to redirect the standard input or output from one file descriptor to another, meaning it changes the destination of the output from one file descriptor (FD) to another.|
