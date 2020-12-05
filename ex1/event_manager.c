#include "event_manager.h"
#include "date.h"
#include "priority_queue.h"

typedef struct event{
        char* event_name;
        int event_id;
         struct event *next_event;
    };

typedef struct member {
        char* member_name;
        int member_id;
        struct member *next_member;
    };

typedef struct EventManager_t* EventManager{
    PriorityQueue event_manager;
     event* events;
     member* members;
     Date* dates;  
};

EventManager createEventManager(Date date){
    pqCreate()





}

void destroyEventManager(EventManager em);

EventManagerResult emAddEventByDate(EventManager em, char* event_name, Date date, int event_id);

EventManagerResult emAddEventByDiff(EventManager em, char* event_name, int days, int event_id);

EventManagerResult emRemoveEvent(EventManager em, int event_id);

EventManagerResult emChangeEventDate(EventManager em, int event_id, Date new_date);

EventManagerResult emAddMember(EventManager em, char* member_name, int member_id);

EventManagerResult emAddMemberToEvent(EventManager em, int member_id, int event_id);

EventManagerResult emRemoveMemberFromEvent (EventManager em, int member_id, int event_id);

EventManagerResult emTick(EventManager em, int days);

int emGetEventsAmount(EventManager em);

char* emGetNextEvent(EventManager em);

void emPrintAllEvents(EventManager em, const char* file_name);

void emPrintAllResponsibleMembers(EventManager em, const char* file_name);
#endif //EVENT_MANAGER_H
