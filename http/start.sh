#!/bin/bash
root=$(pwd)
bin=httpd

if [ -z $LD_LIBRARY_PATH ]; then
	export LD_LIBRARY_PATH=/usr/lib64/mysql
fi

./$bin 8888

