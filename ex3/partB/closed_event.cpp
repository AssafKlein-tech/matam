#include "closed_event.h"


namespace mtm{

    ClosedEvent::ClosedEvent(DateWrap date, std::string name)
    {
        invited_list->clear();
        member_list->clear();
        BaseEvent:date=date;
        BaseEvent:name=name;
    }

    void ClosedEvent::addinvitee (int student){
       invited_list->add(student);
     }

    void ClosedEvent::registerParticipant(int student)
    {
        int i=0;
        int* start_copy=invited_list->first;
        while(invited_list->first!=invited_list->last)
        {
        if(student==invited_list->get(i))
        {member_list->add(student);
        return;}
        
        }
        //אם הגעתי לכאן הפעולה נכשלה
    }

    









}