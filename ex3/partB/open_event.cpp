#include "open_event.h"


namespace mtm{

    void OpenEvent::registerParticipant(int student)
    {
        if(student<1)
            throw(InvalidStudent());
        InsertParticipant(student);
    }

    OpenEvent* OpenEvent::clone()
    {
        return new OpenEvent(*this);
    }

}