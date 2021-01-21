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
        Node<T>* first;

        LinkedList<T>() {}
        ~LinkedList<T>();

        bool sub(T data);
        void add(T data);
        T get(int index);
        void clear();
    };
}
#endif