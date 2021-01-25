#ifndef SCHEDULE_H_
#define SCHEDULE_H_
#include "event_container.h"
#include <memory>
#include <list>

typedef std::shared_ptr<mtm::BaseEvent> EventPointer;
typedef std::list<std::shared_ptr<mtm::BaseEvent>> EventList;
typedef mtm::EventContainer::EventIterator EventIter;

namespace mtm{

   
    class Schedule{

        EventList event_list;

                    if (verbose)
                    }
                        event_ptr->printShort(std::cout);
                    }
                    std::cout<<std::endl;
                }
            }
        }
        void printEventDetails(const DateWrap& date,const string& name) const;
    };
}

#endif