#include "generic_linked_list.h"

namespace mtm{
  
 	template<class T>   
	void LinkedList<class T>::add(T data) 
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
	T get(int index) {
		if(index == 0) {
			// Get the first element
			return this->first->data;
		} else {
			// Get the index'th element
			node<T>* curr = this->first;
			for(int i = 0; i < index; ++i) 
			{
				curr = curr->next;
			}
			return curr->data;
		}
  	}

  template<class T>
  void LinkedList<class T>::clear()
    {
        node<T>* curr=this->first;
        while(this->first)
        {
			curr=curr->next;
          	delete(this->first);
          	this->first=curr;
        }
    } 


	template<class T>
  	bool LinkedList<class T>::sub(T data)
  	{
     	node<T>* first_copy=this->first;
     	node<T>* copy;
    	while(this->first)
        {
          if(this->first->data==data)
            {
            copy=this->first;
            this->first=this->first->next;
            delete(copy);
            }
            this->first=first_copy;
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
