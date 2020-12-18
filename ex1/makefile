CC = gcc
OBJS1 = event_manager.o event.o priority_queue.o date.o member.o tests/event_manager_example_tests.o
EXEC1 = event_manager
OBJS2 = priority_queue.o pq_example_tests.o
EXEC2 = priority_queue
CFLAGS = -std=c99 -Wall -pedantic-errors -Werror -DNDEBUG

$(EXEC1) : $(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o $@

$(EXEC2) : $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o $@
	
event_manager.o : event_manager.c event_manager.h priority_queue.h date.h event.h member.h
tests/event_manager_tests.o : tests/event_manager_tests.c event_manager.h tests/test_utilities.h
tests/priority_queue_tests.o : tests/priority_queue_tests.c priority_queue.h tests/test_utilities.h
priority_queue.o : priority_queue.c priority_queue.h
date.o : date.c date.h 
event.o : event.c event.h date.h
member.o : member.c member.h

clean:
	rm -f $(OBJS1) $(EXEC1)
	rm -f $(OBJS2) $(EXEC2)
