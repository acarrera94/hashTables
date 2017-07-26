/********************************************
*** PLEASE PUT YOUR NAME IN THE SPACE BELOW:
*** Andre Carrera
***
***
********************************************/

// You may only modify the public methods of this file.  Do not modify any of
// the private declarations, or your project will not compile.

#pragma once

#include <exception>
using namespace std;

namespace cs235
{
	const size_t HASH_MAX = 23;

	class HashSet
	{
	private:
		// Do not modify any of these private declarations.
		friend class TestHashSet;
		static const int BLANK1 = -2147483648;
		static const int BLANK2 = 2147483647;

		size_t _count;
		int _data[HASH_MAX];

	public:
		// Delete the throw-statement in the body of this constructor, and 
		// initialize the fields in your class.  Remember to use a member-initializer
		// list.
        static const int START= 0;
        
		HashSet() :
			_count(0)
		{
            for (int i = 0; i< HASH_MAX; i++) {
                _data[i] = BLANK1;
            }
		}


		// This method should add a value into your set.  If there is no more 
		// room the hash-table, throw an exception.
		void Add(int value)
		{
            if (_count >= HASH_MAX)
                throw std::exception ();
            int address = value % HASH_MAX;
            
            while (_data[address] != BLANK1 && _data[address] != BLANK2)
            {
                if (_data[address]== value) {
                    return;
                }
                
                address ++;
                if (address >= HASH_MAX) {
                    address = START;
                }
                
            }
            
            _data[address]= value;
            _count++;
            
		}


		// This method should destroy the contents of the hash=table, and reset
		// the count to zero.
		void Clear()
		{
            for (int i = 0; i<HASH_MAX; i++) {

                _data[i]=BLANK1;
            }
            _count = START;
		}


		// This method should return the maximum capacity for your hash-table.
		size_t GetCapacity()
		{
            return HASH_MAX;
		}


		// This method should provide an up-to-date count of how many items are 
		// stored in your hash-table.  When your hash-table is first created, 
		// this should return zero.  Whenever you add or remove a value, this 
		// method should get updated accordingly.
		size_t GetCount()
		{
            return _count;
		}


		// This should return true if an integer is a member of the hash-table,
		// and false if the integer is not a member of the hash-table.
		bool Contains(int value)
        {
            int address = value % HASH_MAX;
            bool result = false;
            
            for (int i = 0; i< HASH_MAX; i++) {
                if (_data[address]== value) {
                    result = true;
                    break;
                }
                address++;
                if (address>= HASH_MAX) {
                    address=START;
                }
            }
            return result;
        }


		// This removes an item from the hash-table.  Mark the item with an
		// alternative blank value.
		void Remove(int value)
		{
            int address = value % HASH_MAX;
            
            for (int i = 0; i< HASH_MAX; i++) {
                if (_data[address]== value) {
                    _data[address]= BLANK2;
                    _count--;
                    return;
                }
                if (_data[address]== BLANK1) {//or 2?
                    return;
                }
                
                address++;
                if (address>= HASH_MAX) {
                    address=START;
                }
            }
            
        }
	};
}
