#ifndef GENERIC_LINKED_LIST_H_
#define GENERIC_LINKED_LIST_H_

namespace mtm
{

	 /**
         * @brief A generic linked list
         * @param node node in the list
         */
    template<class T>
    struct Node {
        Node<T>* next;
        T data;
        Node<T>(): next(NULL), data(){}
		~Node<T>(){delete next;}

		 /**
         * @brief Copy data to a new node.
         * @param data The event to be copied.
         */
        Node<T>* nodeCopy(T data)
        {
            Node<T>* new_node = new Node<T>;
            new_node->data = data;
            return new_node;
        }
         /**
         * @brief Copy all the generic list.
         */
        Node<T>* hardCopy();
    };
    template<class T>
    class LinkedList
    {
    public:
        Node<T>* first;

        LinkedList(): first(NULL) {}
        ~LinkedList();
        LinkedList& operator=(const LinkedList& list);
		 /**
         * @brief sub node with specific data from the list.
         * @param data The data of the node to be removed.
		 * return true if the data was found in the list and removed and false otherwise.
         */
        bool sub(T data);
		/**
         * @brief ad node with specific data to the list.
         * @param data The data of the node to be added.
         */
        void add(T data);
		/**
         * @brief Gets the node's data in the list by integer.
         * @param index The index of the node with the requiered data.
         */
        T get(int index);
		/**
         * @brief Clears the list.
         */
        void clear();
    };

    template<class T>
	Node<T>* Node<T>::hardCopy()
	{
		Node<T>* temp = this;
		if (!temp)
		{
			return NULL;
		}
		Node<T>* new_node = nodeCopy(temp->data);
		Node<T>* iteration = new_node;
		temp = temp->next;
		while(temp)
		{
			iteration->next = nodeCopy(temp->data);
			iteration = iteration->next;
			temp = temp->next;
		}
		return new_node;
	}

 	template<class T>   
	void LinkedList<T>::add(T data) 
	{
		Node<T>* insdata = new Node<T>;
		insdata->data = data;
		if(!first) 
		{
			// The list is empty
			first = insdata;
		} 
		else if (data < first->data)
		{
			insdata->next = first;
			first = insdata;
		}
		else
		{
			Node<T>* curr = first;
			while (curr->next && data > curr->next->data)
			{
				curr = curr->next;
			}
			insdata->next = curr->next;
			curr->next = insdata;
		}
	}

    template<class T>
    void LinkedList<T>::clear()
    {
        delete first;
    } 

	template<class T>
  	bool LinkedList<T>::sub(T data)
  	{
     	Node<T>* curr = first;
		Node<T>* copy;
			if(curr->data == data)
            {
				first=first->next;
				curr->next=NULL;
				delete(curr);
				return true;
            }

    	while(curr->next)
        {
          	if(curr->next->data == data)
            {

				copy=curr->next->next;
				curr->next->next=NULL;
				delete(curr->next);
				curr->next=copy;
				return true;
            }
			curr=curr->next;
        }
   		return false;
  	}

	template<class T>
	LinkedList<T>::~LinkedList<T>()
	{
		clear();
	}

	template<class T>
	LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list)
	{
		Node<T>* temp = list.first->hardCopy();
		delete first;
		first = temp;
		return *this;
	}
}
#endif