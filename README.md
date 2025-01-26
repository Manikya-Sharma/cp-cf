# My CP codes and templates

## Template and debugging

The templates are kept in `/utils` folder

### Usage

1. Creating template

- alias the execution of `cf_template.py` as something easier to type such as

```bash
alias cpstd='python3 ~/programming/c/cp/utils/debugging/cf_template.py'
```

- In order to create a new file to part `a`, use command as

```bash
cpstd a problem_name
```

1. Debugging

- alias the execution of `cfdbg.py` as something like

```bash
alias dbgrun='python3 ~/programming/c/cp/utils/debugging/cfdbg.py'
```

- Enter the testcases in `a.in`
- run command

```bash
dbgrun a
```

- to get output in different file use

```bash
dbgrun a > out
```

- In order to compare, store expected output in file such as `exp` and compare
using some tool such as `vimdiff`

## Codes

This repository consists of most of the codes I have submitted
in various platforms like Codeforces and AtCoder

There is no guarantee that the solutions are correct, and they
are uploaded only after the contest is over. They are meant
only for future reference.
