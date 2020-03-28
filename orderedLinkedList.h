/*
 * orderedLinkedList.h
 *
 * Store the DataType values in sorted order. This ordering
 * is determined by the comparison operators of the DataType
 * class.
 *
 */

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_

#include <cstddef>

#include "linkedList.h"

template<class DataType>
class orderedLinkedList
{
	public:
		typedef linkedList<DataType>              unorderedLinkedList;
		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef std::ptrdiff_t 					      difference_type;
		typedef std::size_t						      size_type;
		typedef typename unorderedLinkedList::iterator  iterator;
		typedef const iterator	  	               const_iterator;
	private:
		// we are making use of the DoubleLinkedList class
		//unorderedLinkedList list;
    linkedList<DataType> list;
	public:
		// default constructor
		orderedLinkedList();
		// copy constructor
		orderedLinkedList(const orderedLinkedList &other);
		// assignment operator
		orderedLinkedList& operator=(const orderedLinkedList &other);
		// destructor
		virtual ~orderedLinkedList();
		// iterators
		iterator begin()
		{
			return list.begin();
		}
		
		iterator end()
		{
			return list.end();
		}

		const_iterator begin() const
		{
			return list.begin();
		}

		const_iterator end() const
		{
			return list.end();
		}
		
        void clear();
        void copy(const orderedLinkedList &other);
		// number of items in the list
		virtual std::size_t size() const
        {
            return list.size();
        }
		// is the list empty (true) or does it have entries (false)
		virtual bool empty() const
        {
            return list.empty();
        }
		// print the items in the list
        virtual void print() const
        {
            print(std::cout);
        }
		// display the contents of the list to the ostream&
        virtual void print(std::ostream &out) const
        {
            list.print(out);
        }
		// display debug information on the passed in ostream
		virtual void debug(std::ostream &out) const
        {
            list.debug(out);
        }
		// find the element and return an interator for it
		virtual iterator find(const DataType &existingItem)
        {
            return list.find(existingItem);
        }
		// remove the node equal to currentItem
		virtual bool erase(const DataType &currentItem)
        {
            return list.erase(currentItem);
        }
		// remove the node by address existingNode
		virtual iterator erase(iterator iter)
        {
            return list.erase(iter);
        }
		// insert the new item into the list (in sorted order)
		// a duplicate entry will be ignored
		virtual void insert(const DataType &newItem);
		// get the last entry
		iterator back() 
		{
		   return list.back();
		}
		
		const_iterator back() const
		{
		   return list.back();
		}
};

template<class DataType>
orderedLinkedList<DataType>::orderedLinkedList()
    : list()
{
}
//copy constructor
template<class DataType>
orderedLinkedList<DataType>::orderedLinkedList(const orderedLinkedList& other)
{
    list.copy(other);
}

template <class DataType>
orderedLinkedList<DataType>::~orderedLinkedList()
{
}

template<class DataType>
orderedLinkedList<DataType>& orderedLinkedList<DataType>::operator=(const orderedLinkedList &other)
{
    if(this != &other)
    {
        list.clear();
        list.copy(other);
    }
    return *this;
}

template <class DataType>
void orderedLinkedList<DataType>::clear()
{
    while(!empty())
        list.pop_back();
}

template <class DataType>
void orderedLinkedList<DataType>::copy(const orderedLinkedList &other)
{
    list.copy(other);
}

template <class DataType>
void orderedLinkedList<DataType>::insert(const DataType &newItem)
{
    list.insertSorted(newItem);
}
#endif /* ORDEREDLINKEDLIST_H_ */
