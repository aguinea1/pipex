<h1 align="center">
	PIPEX
</h1>
Pipex is a project that involves using some Bash commands (such as cat, grep, ls, etc.) and replicating the behavior of the pipeline "< file1 command1 | command2 > file2", with the following execution format "./pipex file1 command1 command2 file2". In other words, the goal is to redirect the input and output of commands just like a Bash pipeline would.
  
  ---
  ## › Functions I used
  | Function | Description |
  |----------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
  | `open`   |  `open(const char *pathname, int flags, mode_t mode)` – This function is used to open files and obtain a file descriptor, which can then be used to read, write, or manipulate the file. This function returns the integer of the FD, or in case of failure, it returns -1. |
  
