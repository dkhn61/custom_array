// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Array.h"
#include <stdexcept>
#include <iostream>
#define DEFAULT_SIZE 10

// COMMENT Do not import all the variables in the std:: namespace, or
// any namespace, into the global namepace. This can result in name clashes.



Array::Array (void)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

//moved each initialization in different lines
       : data_(nullptr) ,
         cur_size_(0),
         max_size_(0)
{
    this->data_ = new char[DEFAULT_SIZE];
    this->cur_size_ = DEFAULT_SIZE;
    this->max_size_ = DEFAULT_SIZE;
}

Array::Array (size_t length)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
        : data_(nullptr),
          cur_size_(0),
          max_size_(0)
{
    size_t max_size = (length == 0) ? DEFAULT_SIZE : length;
    this->data_ = new char[max_size];
    this->cur_size_ = length;
    this->max_size_ = max_size;

}

Array::Array (size_t length, char fill)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
        : Array(length)

{
    this->fill(fill) ;
}


Array::Array (const Array & array)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
        : data_(nullptr),
          cur_size_(0),
          max_size_(0)
{
    // COMMENT The copy constructor needs to create a deep copy of the source array. Otherwise,
    // the copy will share a pointer with the original. When one goes out of scope, the other
    // will eventually crash.

    // Added logic to perform a deep copy of the source array by copying each element into destination array
    size_t max_size = (array.max_size_ == 0) ? DEFAULT_SIZE : array.max_size_;
    this->data_ = new char[max_size];
    for(int i=0;i<array.max_size_;i++){
        this->data_[i] = array.data_[i];
    }
    this->cur_size_ = array.cur_size_;
    this->max_size_ = max_size;
}

Array::~Array (void)
{
    // COMMENT Do not catch the exception here. Instead, let it client decide
    // how to handle it. I know this was shown in the exception handling slides, but
    // it was show to illustrate failure transparency. We do not want that here.

        // COMMENT You need to delete the data before setting the pointer to null. Also
        // There is no need to reset the data_ variable since this object is no longer
        // useable after the desturctor returns.

        //deleting the data array
        delete [] this->data_;

}

const Array & Array::operator = (const Array & rhs)
{
    // COMMENT Check for self assignment first.
    if(this != &rhs)
        *data_ = *(rhs.data_);

    // COMMENT The assignment operator needs to create a deep copy of the source
    // array. Otherwise, the copy will share a pointer with the original. When one goes out
    // of scope, the other will eventually crash.

    this->cur_size_ = rhs.cur_size_;
    this->max_size_ = rhs.max_size_;

    //adding logic to perform a deep copy by copying every element into destination array
    for(int i=0;i<rhs.cur_size_;i++){
        this->data_[i] = rhs.data_[i];
    }

    return *this;
}

char & Array::operator [] (size_t index)
{
    if (index >= this->cur_size_) {
        throw std::out_of_range ("Out of Range error ");
    }
    return this->data_[index];
}

const char & Array::operator [] (size_t index) const
{
    if (index >= this->cur_size_) {
        throw std::out_of_range ("Out of Range error ");
    }

    return this->data_[index];
}

char Array::get (size_t index) const
{
    char ch;
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.

    // Removed the catch block , letting the client have the exception handling logic
        if (index >= this->cur_size_) {
            throw std::out_of_range ("Out of Range error ");
        }
        else
        {
            ch = data_[index];
        }

   return ch;
}

void Array::set (size_t index, char value)
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.
        if(index >= this->cur_size_)
        {
            throw std::out_of_range ("Out of Range error ");
        }
        else{
            data_[index]=value;

        }
}

void Array::resize (size_t new_size)
{
    // COMMENT The resize method should only increase the size of the allocation if
    // the new size is larger than the current memory allocation for the array. If resized,
    // you need to preserve the old data. Otherwise, you can just update cur_size_ to
    // reflect the new size.
    
    if(new_size > this->cur_size_ ) {

        // COMMENT There is no need to do a double copy for the data to resize
        // the array. Just create a new arary, copy over the data, and then swap
        // the pointers.

        //created a new array to copy elemnts
        char *data_new = new char[new_size];
        for (int i = 0; i < this->cur_size_; i++) {
            data_new[i] = this->data_[i];
        }

        this->data_ = data_new;
        this->cur_size_ = new_size;
        this->max_size_ = new_size + 10;

    }
    else if(new_size < this->cur_size_){
        this->cur_size_ = new_size;
    }
}

int Array::find (char ch) const
{
    for (int i = 0; i < this->cur_size_; ++i) {
        if(this->data_[i] == ch) return i;
    }
    return -1;
}

int Array::find (char ch, size_t start) const
{
    int size = this->size();
    
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.

        if(start<0 || start> size-1){
            throw std::out_of_range ("Out of Range error ");
        }
        for (int i = start; i < this->cur_size_; ++i) {
            if (this->data_[i] == ch) return i;
        }

    return -1;
}

bool Array::operator == (const Array & rhs) const
{
    // COMMENT Check for self comparison first.
    //added the self comparison before comparing the array elements
    if(this == &rhs)
        return true;

    // COMMENT Two arrays are equal if there content is the same. Just
    // comparing the address of the arrays will not suffice.

    //Comparing the elements of the array using a loop
    if(this->cur_size_ != rhs.cur_size_)
        return false;

    for(int i=0;i<rhs.cur_size_;i++){
        if(this->data_[i] != rhs.data_[i])
            return false;
    }

    return true;
}

bool Array::operator != (const Array & rhs) const
{
    if(this == &rhs)
        return false;

    if(this->cur_size_ != rhs.cur_size_)
        return true;

    for(int i=0;i<rhs.cur_size_;i++){
        if(this->data_[i] != rhs.data_[i])
            return true;
    }
    return false;
}

void Array::fill (char ch)
{
    for(int i=0; i<this->cur_size_;i++){
        this->data_[i] = ch;
    }

}

void Array::shrink (void)
{
    // COMMENT Purpose of the shrink method is to recover an unused
    // memory allocation. For example, if the array has allocated 10, and
    // the current size is 5, then 5 spaces us wasted. The shrink method
    // we reclaim the 5 unused spaces so the array only has an allocation
    // large enough to fits is current size (i.e., 5 in this example).
    
    // COMMENT You should use the cur_size_ and max_size_ to determine if you
    // must shrink the array allocation.

    //used the curr size and max size for shrinking
    if(this->cur_size_ < this->max_size_)
      {
        this->max_size_ = this->cur_size_;
      }

}

void Array::reverse (void)
{
    int  temp, i, j;
    for ( i = 0, j = this->cur_size_ - 1; i < this->cur_size_/2; i++, j--)
    {
        temp = this->data_[i];
        this->data_[i] = this->data_[j];
        this->data_[j] = temp;
    }

}

Array Array::slice (size_t begin) const
{
    int slice_length = this->cur_size_- begin-1;
    Array array(slice_length);
        for(int i= 0;i<slice_length;i++)
        {
          array.data_[i] = this->data_[begin+i];
        }
  return array;
}

Array Array::slice (size_t begin, size_t end) const
{
    int slice_length = end-begin;
    Array array(slice_length);
        for(int i= 0;i<slice_length;i++)
        {
          array.data_[i] = this->data_[begin+i];
        }
    return array;
}

void Array::printArray ()
{
    int i;
    for (i = 0; i < this->cur_size_; i++)
        std::cout << this->data_[i] << " ";
    std::cout << std::endl;
}
