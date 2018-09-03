#!/bin/sh
echo "Enter name:"
read name
if test -f $name
then echo "It is a file"
elif test -d $name
then echo "It is a directory"
else
echo "Error. Does not exist."
fi
