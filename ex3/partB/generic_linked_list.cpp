#include "generic_linked_list.h"

namespace mtm{
  
 	template<class T>   
	void LinkedList<class T>::add(T data) 
	{
		if(!first) 
		{
			// The list is empty
			first = new node<T>;
			first->data = data;
			first->next = NULL;
			last = first;
		} else 
		{
			// The list isn't empty
			if(last == first) {
				// The list has one element
				last = new node<T>;
				last->data = data;
				last->next = NULL;
				first->next = last;
			} else {
				// The list has more than one element
				node<T>* insdata = new node<T>;
				insdata->data = data;
				insdata->next = NULL;
				last->next = insdata;
				last = insdata;
			}
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

~LinkedList<T>()
	  {
		  	clear();
	  }
	
template<class T>   
void LinkedList<class T>::sort() {
	node<T>* curr1=this->first;
	node<T>* curr2=this->first->next;
	while(curr1->first)
	{
		while (curr2->first)
		{
			if(curr2->first->data < curr1->first->data)
			{
				T data_copy=new T();
				data_copy=curr2->first->data;
				curr2->first->data=curr1->first->data_copy;
				curr1->first->data=data_copy;
				delete(data_copy);
			}
			
			curr2->first=curr2->first->next;
		}
			curr1->first=curr1->first->next;
	}
	
		}
	
	}

}
