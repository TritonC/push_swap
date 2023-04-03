<h1 align="center"> PUSH_SWAP </h1>

https://user-images.githubusercontent.com/105948301/229530224-801c9ecb-add8-4bf8-8ce0-cbde34ac64e4.mov

\## 📁 Access the project

**Git clone the repository, all the source code is found in the src directory**

\## 🛠️ Open and Execute

**do make rule $>make**

**./push_swap [args]**

**./push_swap 3 2 1**

## Instruction set

For the following instructions, if the instruction is not possible, the part of
it that can't be executed won't.

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

### Performance of the Algorithm

My push_swap sorts

    3 numbers with maximum 3 instructions,
    4 numbers with maximum 7 instructions,
    5 numbers with maximum 11 instructions,
    100 numbers with maximum 690 instructions => 5 points,
    500 numbers with maximum 4800 instructions => 5 points.

The library includes the functions of the following projects:
- [Libft](https://github.com/Tritonc/Libft)

```
$ make
```
The **make** rule will compile the whole library generating a static library 'libft.a' containing all the functions of the project.
```
$ make clean
```
The **clean** rule will delete all objects created to compile the library 'libft.a'.
```
$ make fclean
```
The **fclean** rule will delete all created objects and the 'libft.a' file that has been previously compiled.
```
$ make re
```
The **re** rule will remove all compiled objects and files (if any) and recompile the library.
