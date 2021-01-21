#include "open_event.h"


namespace mtm{

    void OpenEvent::registerParticipant(int student)
    {
        if(student<1)
            throw(InvalidStudent());
        InsertParticipant(student);
    }

    OpenEvent* OpenEvent::clone() const
    {
        return new OpenEvent(*this);
    }

}