#ifndef GENERIC_LINKED_LIST_H_
#define GENERIC_LINKED_LIST_H_

namespace mtm
{
    template<class T>
    struct node {
        node<T>* next;
        T data;
    };

    template<class T>
    class LinkedList
    {
    public:
        node<T>* first;
        node<T>* last;
        ~node<T>();
        LinkedList<T>() 
        {
            first = NULL;
            last = NULL;
        }
        bool sub(T data);
        void add(T data);
        T get(int index);
        void clear();
        T operator[](int index);
    };
}

#endif