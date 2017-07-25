#!/bin/bash
echo -n “Enter user-name: ”
read uname
pent=`grep $uname passwd1.txt`
echo "userid:" `echo $uname`
echo "uid:  " `echo $pent | cut -f 3 -d :`
echo "gid:  " `echo $pent | cut -f 4 -d :`
echo "home directory: " `echo $pent | cut -f 6 -d :`
echo "shell: " `echo $pent | cut -f 7 -d :`
