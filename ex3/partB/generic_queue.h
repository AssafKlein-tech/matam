#ifndef GENERIC_QUEUE_H_
#define GENERIC_QUEUE_H_

namespace mtm{

        template<class Type>
        class queue
        {
                private:
                        Type size;
                        Type start;
                        Type end;
                        Type *data;
                public:
                        queue();
                        int size();
                        queue(Type n);
                        ~queue();
                        void put(Type value);
                        Type get();
                        void clear();



        };
};
#endif