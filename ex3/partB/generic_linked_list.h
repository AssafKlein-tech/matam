#ifndef GENERIC_LINKED_LIST_H_
#define GENERIC_LINKED_LIST_H_

namespace mtm
{
    template<class T>
    struct Node {
        Node<T>* next;
        T data;
        ~Node<T>();
    };
    template<class T>
    class LinkedList
    {
    public:
        node<T>* first;

        LinkedList<T>() 
        {
            first = NULL;
        }

        ~LinkedList<T>();
        
        bool sub(T data);
        void add(T data);
        T get(int index);
        void clear();
       LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> linked_list);
    };
}
#endif