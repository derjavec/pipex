### Pipex Project Overview 🚀

Welcome to the Pipex project, where we explore the intricacies of command execution in Unix-like environments. Let's delve into the core concepts and functionality:

#### How It Works:

1. **Forking Processes**: In Unix, `fork()` creates a duplicate of the current process, resulting in two identical processes, known as the parent and child. The child process inherits the memory and resources of the parent, allowing it to execute commands independently.

2. **Stream Redirection with `dup2()`**: When executing commands, it's crucial to manage input and output streams efficiently. `dup2()` duplicates file descriptors, enabling us to redirect standard input and output streams to files or other processes.

3. **Synchronization with `waitpid()`**: In a multi-process environment, synchronization is key. `waitpid()` allows the parent process to wait for the child processes to complete their execution before proceeding. This ensures orderly execution and prevents race conditions.

4. **Parent and Child Processes**: In Pipex, the main process spawns child processes to execute individual commands. These child processes handle command execution independently, while the parent process coordinates and waits for their completion.

#### Brief Code Description:

The Pipex code orchestrates the execution of multiple commands in a Unix environment. It begins by forking processes to handle each command, setting up communication channels using pipes, and redirecting input and output streams as needed. Each child process executes its designated command, and the parent process waits for their completion using `waitpid()`. This ensures orderly execution and synchronization between processes.

#### Specific Code Implementation:

The provided code consists of functions that manage the execution flow of the Pipex project. `cmd_exc()` is responsible for handling input and output redirection, while `pipex()` coordinates the execution of multiple commands using forked processes and pipes. These functions leverage Unix system calls such as `fork()`, `dup2()`, and `waitpid()` to achieve efficient command execution and synchronization.

---

This project offers a deeper understanding of fundamental Unix concepts such as process management, stream redirection, and synchronization. Through Pipex, we gain insights into the inner workings of command execution in Unix-like systems, equipping us with valuable skills for system programming and software development.
