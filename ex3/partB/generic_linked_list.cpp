#include "generic_linked_list.h"

namespace mtm{
  
 	template<class T>   
	void LinkedList<T>::add(T data) 
	{
		node<T>* insdata = new node<T>;
		insdata->data = data;
		if(!first) 
		{
			// The list is empty
			first = insdata
			first->next = NULL;
		} else if (data < first->data)
			{
				insdata->next = first;
				first = insdata
			}
		else
		{
			node<T>* curr = first;
			while (data < curr->next)
			{
				curr = curr->next;
			}
			insdata->next = curr->next;
			curr->next = insdata;
		}
	}

  	template<class T>
	T LinkedList<T>::get(int index) 
	{
		if(index == 0) 
		{
			// Get the first element
			return first->data;
		} else 
		{
			// Get the index'th element
			node<T>* curr = first;
			for(int i = 0; i < index; ++i) 
			{
				curr = curr->next;
			}
			return curr->data;
		}
  	}

  template<class T>
  void LinkedList<T>::clear()
    {
        node<T>* curr = first;
        while(first)
        {
			curr = curr->next;
          	delete(first);
          	first = curr;
        }
    } 


	template<class T>
  	bool LinkedList<T>::sub(T data)
  	{
     	node<T>* first_copy = first;
     	node<T>* copy;
    	while(first)
        {
          	if(first->data == data)
            {
				copy = first;
				first = first->next;
				delete(copy);
            }
            first = first_copy;
            return true;
        }
   		return false;
  	}

	template<class T>
	LinkedList<T>::~LinkedList<T>()
	{
		clear();
	}
}
