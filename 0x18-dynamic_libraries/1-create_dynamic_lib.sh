#!/bin/bash
gcc -Wall -Wextra -Werror -Wpedantic *.c -fPIC -shared -o liball.so
