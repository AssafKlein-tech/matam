CC = gcc
OBJS = event_manager.o event.o priority_queue.o date.o member.o
EXEC = prog
DEBUG=# now empty, assign -g for debug
CFLAGS = -std=c99 -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(DEBUG_FLAG) $(OBJS) -o $@
	
event_manager.o : event_manager.c event_manager.h priority_queue.h date.h event.h member.h
priority_queue.o : priority_queue.c priority_queue.h
date.o : date.c date.h 
event.o : event.c event.h date.h
member.o : member.c member.h

clean:
	rm -f $(OBJS) $(EXEC)
