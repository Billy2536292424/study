ROOT=$(shell pwd)
.PHONY:all
all:httpd cgi
httpd:httpd.c
	gcc -o $@ $^ -lpthread
cgi:
	cd $(ROOT)/wwwroot/cgi;make clean;make;cd -
.PHONY:output
output:
	mkdir -p output/wwwroot/cgi
	cp httpd output
	cp start.sh output
	cp -rf lib output
	cp -f wwwroot/*.html output/wwwroot
	cp -rf wwwroot/imag output/wwwroot
	cp -f wwwroot/cgi/insert_cgi output/wwwroot/cgi
	cp -f wwwroot/cgi/delete_cgi output/wwwroot/cgi
	cp -f wwwroot/cgi/select_cgi output/wwwroot/cgi
.PHONY:clean
clean:
	rm -f httpd
	cd $(ROOT)/wwwroot/cgi;make clean;cd -
	rm -rf output
