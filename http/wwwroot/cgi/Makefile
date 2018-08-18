INCLUDE=-I/usr/include/mysql
LIB=-L/usr/lib64/mysql
LIB_NAME=-lmysqlclient
.PHONY:all
all:test insert_cgi delete_cgi select_cgi net_cal
test:test.c
	gcc -o $@ $^ $(INCLUDE) $(LIB) $(LIB_NAME)
insert_cgi:insert_cgi.c
	gcc -o $@ $^ $(INCLUDE) $(LIB) $(LIB_NAME)
delete_cgi:delete_cgi.c
	gcc -o $@ $^ $(INCLUDE) $(LIB) $(LIB_NAME)
select_cgi:select_cgi.c
	gcc -o $@ $^ $(INCLUDE) $(LIB) $(LIB_NAME)
net_cal:net_cal.c
	gcc -o $@ $^ 
.PHONY:clean
clean:
	rm -rf insert_cgi delete_cgi select_cgi net_cal test
