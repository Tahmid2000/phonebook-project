 /*
 * linkedList.h
 *
 * Implementation of a double linked list.
 *
 * We have the ability to get the first and last entries and navigate
 * through the entries in the linked list.
 *
 * There are actually three classes here:
 *
 * listNode<DataType>
 *
 * listNodeIterator<DataType>
 
 * and
 *
 * linkedList<DataType>
 *
 * The listNodeIterator is the iterator for the new linked list class. 
 * 
 */
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

//include "memoryLeak.h"
#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <iterator>

// forward declaration of the template class linkedList since it is a friend class
template<class DataType>
class linkedList;
// forward declaration of iterator
template<class DataType>
class linkedListIterator;

// listNode class
template<class DataType>
class listNode
{
	// make DoubleLinkedList<DataType> a friend class
	friend class linkedList<DataType>;
	friend class linkedListIterator<DataType>;
	private:
		// contains the actual data
		DataType dataType;
		// pointer to the next item in the list or nullptr 
		// if at the end
		listNode<DataType>* pNext;
		// pointer to the previous item in the list or nullptr 
		// if at the start
		listNode<DataType>* pPrevious;
	public:
		// default constructor
        listNode();
		// constructor with data
        listNode(const DataType &newItem);
    
    listNode(const listNode& other);
    
	protected:
		// get the next node
		listNode* next() const
		{
			return pNext;
		}

		// get the previous node
		listNode* previous() const
		{
			return pPrevious;
		}

		// return the data stored in the node as a const
		const DataType& data() const
		{
			return dataType;
		}
		// return the data stored in the node
		DataType& data()
		{
			return dataType;
		}
		// update the next node
		void next(listNode *nextNode)
		{
			pNext = nextNode;
		}
		// update the previous node
		void previous(listNode *previousNode)
		{
			pPrevious = previousNode;
		}
    
    bool operator==(const listNode<DataType> &rhs) const {return data() == rhs->data();}
    bool operator!=(const listNode<DataType> &rhs) const {return data() != rhs->data();}
    bool operator<(const listNode<DataType> &rhs) const {return data() < rhs->data();}
    bool operator<=(const listNode<DataType> &rhs) const {return data() <= rhs->data();}
    bool operator>(const listNode<DataType> &rhs) const {return data() > rhs->data();}
    bool operator>=(const listNode<DataType> &rhs) const {return data() >= rhs->data();}
};

// the linkedListIterator is the iterator for class linkedList.
//
// most of this code has been provided for you. 
// the exceptions are the operator--() operator--(int) member fuctions and
// and the operator== and operator!= member functions. 
template<class DataType>
class linkedListIterator
{
	typedef DataType 								value_type;
	typedef DataType& 								reference;
	typedef const DataType& 						const_reference;
	typedef DataType* 								pointer;
	typedef const DataType* 						const_pointer;
	typedef std::bidirectional_iterator_tag	iterator_category;
	typedef std::ptrdiff_t 							difference_type;
	typedef std::size_t								size_type;
	typedef linkedListIterator						iterator;
	typedef const linkedListIterator	  			const_iterator;

	friend class linkedList<DataType>;
	private:
		listNode<DataType> *current;
	public:
		linkedListIterator(listNode<DataType> *current)
			: current(current)
		{
		}

		virtual ~linkedListIterator()
		{
		}

		reference operator*()
		{
		   assert(current != nullptr);
			return current->data();
		}

		const_reference operator*() const
		{
		   assert(current != nullptr);
			return current->data();
		}

		pointer operator->()
		{
		   assert(current != nullptr);
			return &(current->data());
		}

		const_pointer operator->() const
		{
		   assert(current != nullptr);
			return &(current->data());
		}

		iterator operator++()
		{
            if (current != nullptr)
			{
				current = current->next();
			}
			return *this;
		}

		iterator operator++(int)
		{
			iterator it = *this;
			if (current != nullptr)
			{
				current = current->next();
			}
			return it;
		}

        iterator operator--()
        {
            if(current->previous() != nullptr)
            {
                current = current->previous();
            }
            return *this;
        }
        iterator operator--(int)
        {
            iterator it = *this;
            if(current->previous() !=nullptr)
            {
                current = current->previous();
            }
            return it;
        }
        DataType& data()
        {
            return current->dataType;
        }
    
        bool operator==(const_iterator &other) const
        {
            return (current == other.current);
        }
        bool operator!=(const_iterator &other) const
        {
            return (current != other.current);
        }
    
 //   bool operator==(const linkedListIterator<DataType> &rhs) const {return data() == rhs->data();}
 //   bool operator!=(const linkedListIterator<DataType> &rhs) const {return data() != rhs->data();}
    bool operator<(const linkedListIterator<DataType> &rhs) const {return current < rhs.current;}
    bool operator<=(const linkedListIterator<DataType> &rhs) const {return current <= rhs.current;}
    bool operator>(const linkedListIterator<DataType> &rhs) const {return current > rhs.current;}
    bool operator>=(const linkedListIterator<DataType> &rhs) const {return current >= rhs.current;}

};
		
// linkedList class
template<class DataType>
class linkedList
{
	public:
 		typedef DataType 								value_type;
 		typedef DataType& 								reference;
 		typedef const DataType& 						const_reference;
 		typedef DataType* 								pointer;
 		typedef const DataType* 						const_pointer;
 		typedef std::bidirectional_iterator_tag	        iterator_category;
 		typedef std::ptrdiff_t 							difference_type;
 		typedef std::size_t								size_type;
		typedef linkedListIterator<DataType>		    iterator;
		typedef const linkedListIterator<DataType>      const_iterator;

	private:
		// your instance data goes here. Things like the pointers to the first and last nodes 
		//  as well as the count of nodes
        listNode<DataType> *firstNode;
        listNode<DataType> *lastNode;
    int count;
	public:
		// default constructor
        linkedList();
		// copy constructor
        linkedList(const linkedList &other);
		// assignment operator
		linkedList& operator=(const linkedList &other);
		// destructor
        
        virtual ~linkedList();
    
        // return the number of nodes in the list
        std::size_t size() const{
            return count;
        }
		// return true if the list is empty
        bool empty() const{
            return count == 0;
        }
        //clears the list
        void clear();
    
        void copy(const linkedList &other);
		// display the contents of the list to std::cout
		void print() const
		{
            print(std::cout);
		}
		// display the contents of the list to the ostream&
        void print(std::ostream &out) const;
		// iterators
		iterator begin()
		{
			return iterator(firstNode);
		}

		const_iterator begin() const
		{
			return iterator(firstNode);
		}

		iterator end()
		{
			return iterator(nullptr);
		}

		const_iterator end() const
		{
			return iterator(nullptr);
		}

		// dump the contends in debug format to passed in 
		// ostream - usage to cout would be:
		//   list.debug(std::cout);
		void debug(std::ostream &out) const;
	public:
		// add an item to the front of the list
		virtual void push_front(const DataType &newItem);
		// add an item to the back of the list
		virtual void push_back(const DataType &newItem);
		// remove an item from the front of the list
		virtual void pop_front();
		// remove an item from the back of the list
		virtual void pop_back();
		// insert newItem before the node specified by the iterator
		virtual void insert_before (iterator iter, const DataType &newItem);
		// insert newItem after the node specified by the iterator
		virtual void insert_after (iterator iter, const DataType &newItem);
		// find the node and return the iterator for that element.
		// Return end() if not found
		virtual iterator find(const DataType &existingItem);
		// remove the node equal to currentItem
		virtual bool erase(const DataType &currentItem);
		// remove the node by address existingNode
		virtual iterator erase(iterator iter);
    
        virtual void insertSorted(const DataType &newItem);
		// return the iterator for the last node
		virtual iterator back()
		{
			return linkedListIterator<DataType>(lastNode);
		}
		virtual const_iterator back() const
		{
			return linkedListIterator<DataType>(lastNode);
		}
    
    
    
    //Remove
   
    DataType firstf()
    {
        if(firstNode!=nullptr)
            return firstNode->data();
        return;
    }
    
   
    DataType lastf()
    {
        if(lastNode !=nullptr)
            return lastNode->data();
        return;
    }

	protected:
	private:
	   // any helper functions you need should either be protected or private
};

// the constructors for the listNode class are included here
// default constructor
template <class DataType>
listNode<DataType>::listNode()
	: dataType(), pNext(nullptr), pPrevious(nullptr)
{
}

// constructor with data
template <class DataType>
listNode<DataType>::listNode(const DataType &newItem)
	: dataType(newItem), pNext(nullptr), pPrevious(nullptr)
{
}

template <class DataType>
listNode<DataType>::listNode(const listNode& other)
    : dataType(other.dataType), pNext(other.pNext), pPrevious(other.pPrevious)
{
}

// note the code for the debug() function is included
// display a debug version of the list
template<class DataType>
void linkedList<DataType>::debug(std::ostream &out) const
{
	const unsigned int ADDRWIDTH = 10;
	out << "START DEBUG" << std::endl;
	out << "first  =" << std::setw(ADDRWIDTH) << firstNode;
	out << ", last=" << std::setw(ADDRWIDTH) << lastNode;
	out << ", # nodes=" << size() << std::endl;
	unsigned int count = 1;

	for (auto current=firstNode; current!= nullptr; current=current->next())
	{
		out << "node " << std::setw(2) << count;
		out << "=" << std::setw(ADDRWIDTH) << current;
		out << ", next=" << std::setw(ADDRWIDTH)
			<< current->next();
		out << ", previous=" << std::setw(ADDRWIDTH)
			<< current->previous();
		out << ", value=" << current->data() << std::endl;
		count++;
	}
	out << "END DEBUG" << std::endl;
}

// I have included a few function headers and bodies here where the syntax is odd
// Your implementation of non-inlined member funcctions needs to go there. 
// default constructor
template<class DataType>
linkedList<DataType>::linkedList()
    : firstNode(nullptr), lastNode(nullptr), count(0)
{
}
//copy constructor
//FIXME
template<class DataType>
linkedList<DataType>::linkedList(const linkedList& other)
{
    copy(other);
}

template <class DataType>
linkedList<DataType>::~linkedList()
{
}

//might cause errors
template <class DataType>
void linkedList<DataType>::clear()
{
    while(!empty())
        pop_back();
}

template <class DataType>
void linkedList<DataType>:: copy(const linkedList &other)
{
    if(other.empty() == true)
    {
        firstNode = lastNode = nullptr;
        count = 0;
    }
    else
    {
        listNode<DataType> *current = other.firstNode;
        count = 0;
        firstNode = lastNode = nullptr;
        while(current != nullptr)
        {
              listNode<DataType>* newNode = new listNode<DataType>(current->data());
              newNode->previous(nullptr);
              newNode->next(nullptr);
    
              if(count == 0)
                firstNode = lastNode = newNode;
              else
              {
                  
                    lastNode->next(newNode);
                    newNode->previous(lastNode);
                    lastNode = lastNode->next();
              }
              count++;
              current = current->next();
        }
    }
}
    
template<class DataType>
linkedList<DataType>& linkedList<DataType>::operator=(const linkedList &other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

template<class DataType>
void linkedList<DataType>::print(std::ostream &out) const
{
    for (auto *current=firstNode; current!=nullptr; current=current->next())
    {
        out << current->data() << std::endl;
    }
}

/*
template<class DataType>
std::ostream& operator<<(std::ostream &out, const DataType &rhs)
{
    for (auto *current= firstNode; current!=nullptr; current=current->next())
    {
        out << current->data() << std::endl;
    }
    return out;
} */

// add an item to the front of the list
template<class DataType>
void linkedList<DataType>::push_front(const DataType &newItem)
{
    listNode<DataType> *newNode = new listNode<DataType>(newItem);
    if(empty())
        firstNode = lastNode = newNode;
    else
    {
        newNode->next(firstNode);
        firstNode->previous(newNode);
        firstNode = newNode;
    }
    count++;
}
// add an item to the back of the list
template<class DataType>
void linkedList<DataType>::push_back(const DataType &newItem)
{
    listNode<DataType> *newNode = new listNode<DataType>(newItem);
    if(empty())
        firstNode = lastNode = newNode;
    else
    {
        newNode->previous(lastNode);
        lastNode->next(newNode);
        lastNode = newNode;
    }
    count++;
}
// remove an item from the front of the list
template<class DataType>
void linkedList<DataType>::pop_front()
{
    if(empty())
        return;
    else
    {
        auto tempnext = firstNode->next();
        if(tempnext != nullptr && tempnext->next() != nullptr)
            tempnext->previous(nullptr); 
        delete firstNode;
        firstNode = tempnext;
        //delete tempnext;
        count--;
        if(empty())
            firstNode = lastNode = nullptr; 
    }
}
// remove an item from the back of the list
template<class DataType>
void linkedList<DataType>::pop_back()
{
    if(empty())
        return;
    else
    {
        listNode<DataType> *tempprev = lastNode->previous();
        if(tempprev != nullptr)
            tempprev->next(nullptr);
        lastNode->previous(nullptr);
        delete lastNode;
        lastNode = tempprev;
        count--;
        if(empty())
            firstNode = lastNode = nullptr;
    }
   
}
// insert newItem before the node specified by the iterator
template<class DataType>
void linkedList<DataType>::insert_before(iterator iter, const DataType &newItem)
{
    listNode<DataType> *newNode = nullptr;
    if(empty())
    {
        firstNode = lastNode = newNode;
        count++;
    }
    else if(iter == end() || iter == begin())
        push_front(newItem);
    else if(iter.current->previous() == nullptr)
    {
        newNode = new listNode<DataType>(newItem);
        newNode->next(iter.current);
        iter.current->previous(newNode);
        firstNode = newNode;
    }
    else
    {
        auto *iterNode = iter.current;
        newNode = new listNode<DataType>(newItem);
        newNode->next(iterNode);
        newNode->previous(iterNode->previous());
        iterNode->previous()->next(newNode);
        iterNode->previous(newNode);
        if(iterNode == firstNode)
            firstNode = newNode;
        count++;
        }
}
// insert newItem after the node specified by the iterator
template<class DataType>
void linkedList<DataType>::insert_after(iterator iter, const DataType &newItem)
{
    listNode<DataType> *newNode = nullptr;
    if(empty())
    {
        newNode = new listNode<DataType>(newItem);
        firstNode = lastNode = newNode;
        count++;
    }
    else if(iter == end())
        push_back(newItem);
    else if(iter.current->next() == nullptr)
    {
        newNode = new listNode<DataType>(newItem);
        iter.current->next(newNode);
        newNode->previous(iter.current);
        lastNode = newNode;
        count++;
    }
    else
    {
        auto *iterNode = iter.current;
        newNode = new listNode<DataType>(newItem);//i have to set the next of this node to the next of iter
        newNode->next(iterNode->next());
        newNode->previous(iterNode);
        iterNode->next()->previous(newNode);
        iterNode->next(newNode);
        if(iterNode == lastNode)
            lastNode = newNode;
        count++;
    }
}

template<class DataType>
typename linkedList<DataType>::iterator linkedList<DataType>::find(const DataType &existingItem)
{
    linkedListIterator<DataType> current = begin();
    bool done = false;

    while (!done && current != end())
    {
        if (*current == existingItem)
            done = true;
        else
            current++;
    }
    if(done == true)
        return current;
    return nullptr;
}

// remove the node equal to currentItem
template<class DataType>
bool linkedList<DataType>::erase(const DataType &currentItem)
{
    auto foundIter = find(currentItem);
    if(foundIter == end())
        return false;
    if(foundIter == begin())
    {
        pop_front();
        return true;
    }
    listNode<DataType> *temphead = firstNode;
    listNode<DataType> *tempnext = nullptr;
    while(temphead->next() != nullptr)
    {
        if(temphead->next()->data() == currentItem)
        {
            tempnext = temphead->next();
            break;
        }
        else
        {
            temphead = temphead->next();
        }
    }
    if(tempnext->next() == nullptr)
    {
        temphead->next(nullptr);
        lastNode = temphead;
        count--;
        return true;
    }
    temphead->next(tempnext->next());
    tempnext->next()->previous(temphead);
    delete tempnext;
    count--;
    return true;
}

// remove the node by iterator
template<class DataType>
typename linkedList<DataType>::iterator  linkedList<DataType>::erase(linkedList<DataType>::iterator iter)
{
    auto result = end();
    if(iter == end())
        return result;
    DataType currentItem = iter.current->data();
    auto foundIter = find(currentItem);
    listNode<DataType> *temphead = firstNode;
    listNode<DataType> *tempnext = nullptr;
    while(temphead != nullptr)
    {
        if(temphead->data() == currentItem)
        {
            if(temphead->next() != nullptr)
            {
                tempnext = temphead->next();
                break;
            }
            else
                return result;
        }
        else
        {
            temphead = temphead->next();
        }
    }
    auto otherFoundIter = find(tempnext->data());
    erase(currentItem);
    if(empty())
        return end();
    return otherFoundIter;
}

template<class DataType>
void linkedList<DataType>::insertSorted(const DataType &newItem)
{
    if(find(newItem) != end())
        return;
    else if(empty())
        push_back(newItem);
    else if(newItem < firstNode->data())
        push_front(newItem);
    else
    {
        listNode<DataType> *temp = firstNode;
        while(temp->next() != nullptr && temp->next()->data() < newItem)
            temp = temp->next();
        linkedListIterator<DataType> iter = find(temp->data());
        insert_after(iter, newItem);
    }
}

// all of your member function need to be before the #endif
#endif /* DOUBLELINKEDLIST_H_ */
