CC= gcc
object = main.o menu.o service.o List.o 
a.out : $(object)
	$(CC) $(object) -o a.out
main.o : main.c 
	$(CC) -c main.c 
menu.o : menu.c 
	$(CC) -c menu.c 
service.o : service.c 
	$(CC) -c service.c 
List.o : List.c 
	$(CC) -c List.c  
.PHONY:
clean:
	rm -rf $(object) a.out
	
