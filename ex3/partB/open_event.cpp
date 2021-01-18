#include "open_event.h"


namespace mtm{

  void OpenEvent::registerParticipant(int student)
 {
     node<int>* curr_member=member_list->first;
      while(curr_member)
                    if(curr_member->data==student)
                        throw AlreadyRegistered();

                member_list->add(student);

 }





}