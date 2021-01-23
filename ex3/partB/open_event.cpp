#include "open_event.h"


namespace mtm{

    void OpenEvent::registerParticipant(int student)
    {
        if(!isValidStudent(student))
        {
            throw(InvalidStudent());
        }
        InsertParticipant(student);
    }

    OpenEvent* OpenEvent::clone() const
    {
        return new OpenEvent(*this);
    }

    OpenEvent& OpenEvent::operator=(const OpenEvent& event)
    {
        assign(event);
        return *this;
    }
}