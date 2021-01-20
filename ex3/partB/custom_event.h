#ifndef CUSTOM_EVENT_H
#define CUSTOM_EVENT_H
#include "base_event.h"

namespace mtm{

    template <class CanRegister>
    class CustomEvent:public BaseEvent{
    
    public:
     CustomEvent::CustomEvent(DateWrap date, std::string name, const CanRegister assignment_conditions);
     void CustomEvent::registerParticipant(int student) override;
     CustomEvent* clone() override;
     CustomEvent::~CustomEvent(){ delete(invited_list); };

    protected:
        CanRegister can_register;
    };

    template <class CanRegister>
    CustomEvent<CanRegister>::CustomEvent(DateWrap date, std::string name, const CanRegister assignment_conditions):
        BaseEvent(date,name)
    {
        can_register=assignment_conditions;
    }


    template <class CanRegister>
    void CustomEvent<CanRegister>::registerParticipant(int student) 
    {
        if(assignment_conditions(student))
        InsertParticipant(student);
    }

    template <class CanRegister>
    CustomEvent<CanRegister>* CustomEvent<CanRegister>::clone()
    {
        return new CustomEvent<CanRegister>(*this);
    }





}





#endif