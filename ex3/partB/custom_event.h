#ifndef CUSTOM_EVENT_H
#define CUSTOM_EVENT_H
#include "base_event.h"

namespace mtm{

    template <class CanRegister>
    class CustomEvent:public BaseEvent{
    
    public:
        CustomEvent(DateWrap date, std::string name, const CanRegister assignment_conditions);
        void registerParticipant(int student) override;
        CustomEvent& operator=(const CustomEvent& event);
        CustomEvent* clone() const override;
        ~CustomEvent(){}

    private:
        CanRegister can_register;
    };

    template <class CanRegister>
    CustomEvent<CanRegister>::CustomEvent(DateWrap date, std::string name, const CanRegister assignment_conditions):
        BaseEvent(date,name)
    {
        can_register = assignment_conditions;
    }


    template <class CanRegister>
    void CustomEvent<CanRegister>::registerParticipant(int student) 
    {
        if (student <= 0)
        {
            throw InvalidStudent();
        }
        if(can_register(student))
        {
            InsertParticipant(student);
        }
        else 
        {
            throw RegistrationBlocked();
        }
    }

    template <class CanRegister>
    CustomEvent<CanRegister>& CustomEvent<CanRegister>::operator=(const CustomEvent<CanRegister>& event)
    {
        assign(event);
        can_register = event.can_register;
        return *this;
    }

    template <class CanRegister>
    CustomEvent<CanRegister>* CustomEvent<CanRegister>::clone() const
    {
        return new CustomEvent<CanRegister>(*this);
    }
}

#endif