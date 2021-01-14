#ifndef GENERIC_QUEUE_H_
#define GENERIC_QUEUE_H_
#include "date_wrap.h"
#include "base_event.h"
using mtm::BaseEvent;

namespace mtm{

    class queue
{
        private:
                Type size;
                Type start;
                Type end;
                Type *data;
         public:
                 queue();
                 queue(Type n);
                 ~queue();
                 void put(Type value);
                 Type get();
                 void clear();



}
#endif