<h1 align="center">Welcome to PSU_strace_2018 👋</h1>
<p>
</p>

> strace traces a program in real time and displays all of the system calls, it executes in their order of appearance.
The aim of this project was to Develop an alternative to strace that implementing the following options: 
  - -p: force a specific PID instead of executing a command 
  - -s: display the detailled arguments (see below)
  
  By default, my strace must only display the arguments and return values in hexadecimal form. If the system call has a void return value, display a question mark. With -s option, the program must be as close as possible to the strace command on our unix system, and therefore display the following:
   - integers in decimal form,
   - pointers on a character string in the form of a character string
   - detailed structures (value for each field).

## Install

```sh
$> git clone https://github.com/hadi-ilies/PSU_strace_2018.git
$> cd PSU_strace_2018
$> make
```
## Usage

```sh
USAGE
    ./strace [-s] [-p <pid>|<command>]
OPTIONS
    -s <command> 
       Display the detailled arguments. This option allow to display integers in decimal form, pointers on a character string in the form of a character string
    -p <pid> 
       Force a specific PID instead of executing a command
    -h, --help
       Display the program usage
```

 ## Run strace with simple command
```sh
$> ./strace ls
```
 
## Author

👤 **hadi Bereksi**

* Website: https://hadibereksi.fr/
* Github: [@hadi-ilies](https://github.com/hadi-ilies)
* LinkedIn: [@hadibereksi](https://linkedin.com/in/hadibereksi)

## Show your support

Give a ⭐️ if this project helped you!

***
_This README was generated with ❤️ by [readme-md-generator](https://github.com/kefranabg/readme-md-generator)_
