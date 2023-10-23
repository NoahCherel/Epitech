#!/bin/bash
cut -d ';' -f 3 | grep "$1" -i |  wc -l 

