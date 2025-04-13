<h1 align="center">
	PIPEX
</h1>

<p align="center">
	<img src="https://img.shields.io/badge/Language-C-blue?style=flat-square"/>
	<img src="https://img.shields.io/badge/UNIX%20Pipes-Shell%20Simulation-yellow?style=flat-square"/>
	<img src="https://img.shields.io/badge/Process%20Execution-Fork%20%7C%20Execve-orange?style=flat-square"/>
</p>

**Pipex** is a project from 42 that aims to replicate the shell's piping behavior. It simulates how Unix shells process commands using pipes (`|`), by executing a series of commands connected via standard input and output redirection. The goal is to deepen understanding of file descriptors, inter-process communication, and command execution in C using system calls like `pipe`, `fork`, `execve`, and `dup2`.

## › Features
- 🔗 Pipe simulation using `pipe()` and `dup2()`
- 👨‍👩‍👧‍👦 Parent-child process management with `fork()`
- 🧠 Command parsing and environment path resolution
- 🧪 Handles invalid files, missing commands, and permission errors
- 🛠 Bonus: support for multiple pipes (multi-command pipelines)

## › Example

	./pipex file1 "grep hello" "wc -l" file2

That simulates this feature in bash:

	< file1 grep hello | wc -l > file2

## 🎁 Bonus

### → Here Doc

Your program must handle shell-like *here doc* syntax. It reads from the input until a delimiter is found, feeding that as input to a command sequence.

Example:

	./pipex here_doc LIMITER cmd1 cmd2 outfile

Which simulates:

	cat << LIMITER | cmd1 | cmd2 >> outfile

### → Unlimited Commands

In the bonus version, `pipex` should be able to handle an arbitrary number of commands, chaining them just like a real shell:

	./pipex infile cmd1 cmd2 cmd3 cmd4 ... cmdN outfile

All commands will be piped sequentially as:

	< infile cmd1 | cmd2 | cmd3 | ... | cmdN > outfile

## 📫 Contact

Feel free to reach out or explore more of my work:

[<img src="https://img.shields.io/badge/LinkedIn-0077B5?style=flat-square&logo=linkedin&logoColor=white"/>](https://www.linkedin.com/in/aitor-guinea-961635348/)  
[<img src="https://img.shields.io/badge/GitHub-aguinea1-black?style=flat-square&logo=github"/>](https://github.com/aguinea1)  
[<img src="https://img.shields.io/badge/Email-guineaitor36@gmail.com-red?style=flat-square&logo=gmail&logoColor=white"/>](mailto:guineaitor36@gmail.com)

---

⭐

