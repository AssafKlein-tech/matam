#include "open_event.h"


namespace mtm{

    void OpenEvent::registerParticipant(int student)
    {
        InsertParticipant(student);
    }

    OpenEvent* OpenEvent::clone()
    {
        return new OpenEvent(*this);
    }

}