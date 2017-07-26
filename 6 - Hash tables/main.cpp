// DO NOT MODIFY THIS FILE.

#include <exception>
#include <iostream>
#include "HashSet.h"
#include "TestCase.h"

using namespace std;
using namespace cs235;

namespace cs235
{
	class TestHashSet
	{
	public:
		static int Blank1() { return HashSet::BLANK1; }
		static int Blank2() { return HashSet::BLANK2; }
		static int GetDataAt(HashSet &set, int idx) { return set._data[idx]; }
	};
}

//##############################################################################
//###   Constructor tests
//##############################################################################

/**************************************/
void ConstructorBasic()
{
    TestCase tc("Make a new instance of HashSet.");

    try
    {
        HashSet set;
        tc.LogResult(true, "Make an instance of an HashSet");
		tc.AssertEquals(23, HASH_MAX, "Check HASH_MAX.");
		tc.AssertEquals(-2147483648, TestHashSet::Blank1(), "Check BLANK1");
		tc.AssertEquals(2147483647, TestHashSet::Blank2(), "Check BLANK1");
		for (int i = 0; i < HASH_MAX; i++)
			tc.AssertEquals(-2147483648, TestHashSet::GetDataAt(set, i), "Validate element init.");
    }
    catch (exception ex)
    {
        tc.LogException(ex);
    }
}


/**************************************/
void ConstructorCheckCount()
{
	TestCase tc("After creating a new HashSet, GetCount() returns 0.");

	try
	{
		HashSet set;
		tc.LogResult(true, "Make an instance of an HashSet.");

		tc.AssertEquals(0, set.GetCount(), "Make sure GetCount() returns a 0 for a new HashSet.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}


/**************************************/
void ConstructorCheckCapacity()
{
	TestCase tc("After creating a new HashSet, GetCapacity() returns 23.");

	try
	{
		HashSet set;
		tc.LogResult(true, "Make an instance of an HashSet.");

		tc.AssertEquals((int)HASH_MAX, (int)set.GetCapacity(), "Make sure GetCapacity() returns HASH_MAX.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}


//##############################################################################
//###   Add 
//##############################################################################

/**************************************/
void AddItemAndCheckBasic()
{
	TestCase tc("Add an item, and do basic checks.");

	try
	{
		HashSet set;
		tc.AssertEquals(0, set.GetCount(), "GetCount returns 0 on empty set.");
		set.Add(5);
		tc.AssertEquals(1, set.GetCount(), "Add 5, then make sure GetCount returns 1.");
		tc.AssertEquals(5, TestHashSet::GetDataAt(set, 5), "Data is at index 5.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void AddVariousNoCollisions()
{
	TestCase tc("Add various items without collisions.");

	try
	{
		HashSet set;
		tc.AssertEquals(0, set.GetCount(), "GetCount returns 0 on empty set.");
		set.Add(5);
		tc.AssertEquals(1, set.GetCount(), "Add 5, then make sure GetCount returns 1.");
		tc.AssertEquals(5, TestHashSet::GetDataAt(set, 5), "Data is at index 5.");
		set.Add(3);
		tc.AssertEquals(2, set.GetCount(), "Add 3, then make sure GetCount returns 2.");
		tc.AssertEquals(3, TestHashSet::GetDataAt(set, 3), "Data is at index 3.");
		set.Add(7);
		tc.AssertEquals(3, set.GetCount(), "Add 7, then make sure GetCount returns 3.");
		tc.AssertEquals(7, TestHashSet::GetDataAt(set, 7), "Data is at index 7.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void AddWithWrapAround()
{
	TestCase tc("Test hash function for items greater than HASH_MAX.");

	try
	{
		HashSet set;
		tc.AssertEquals(0, set.GetCount(), "GetCount returns 0 on empty set.");
		set.Add(66);
		tc.AssertEquals(1, set.GetCount(), "Add 66 and check count.");
		tc.AssertEquals(66, TestHashSet::GetDataAt(set, 20), "Index 20 contains 66.");
		set.Add(25);
		tc.AssertEquals(2, set.GetCount(), "Add 25 and check count.");
		tc.AssertEquals(25, TestHashSet::GetDataAt(set, 2), "Index 3 contains 25.");
		set.Add(2307);
		tc.AssertEquals(3, set.GetCount(), "Add 2307 and check count.");
		tc.AssertEquals(2307, TestHashSet::GetDataAt(set, 7), "Index 4 contains 2307.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void AddSameItemTwice()
{
	TestCase tc("Add the same item twice.");

	try
	{
		HashSet set;
		tc.AssertEquals(0, set.GetCount(), "GetCount returns 0 on empty set.");
		set.Add(5);
		set.Add(5);
		tc.AssertEquals(1, set.GetCount(), "Add 5 twice, then make sure GetCount returns 1.");
		tc.AssertEquals(5, TestHashSet::GetDataAt(set, 5), "Index 5 contains 5.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void AddToCapacity()
{
	TestCase tc("Add to capacity, and verify failure.");

	try
	{
		HashSet set;
		set.Add(1);
		tc.AssertEquals(1, set.GetCount(), "Add 1 and check count.");
		set.Add(2);
		tc.AssertEquals(2, set.GetCount(), "Add 2 and check count.");
		set.Add(3);
		tc.AssertEquals(3, set.GetCount(), "Add 3 and check count.");
		set.Add(4);
		tc.AssertEquals(4, set.GetCount(), "Add 4 and check count.");
		set.Add(5);
		tc.AssertEquals(5, set.GetCount(), "Add 5 and check count.");
		set.Add(6);
		tc.AssertEquals(6, set.GetCount(), "Add 6 and check count.");
		set.Add(7);
		tc.AssertEquals(7, set.GetCount(), "Add 7 and check count.");
		set.Add(8);
		tc.AssertEquals(8, set.GetCount(), "Add 8 and check count.");
		set.Add(9);
		tc.AssertEquals(9, set.GetCount(), "Add 9 and check count.");
		set.Add(10);
		tc.AssertEquals(10, set.GetCount(), "Add 10 and check count.");
		set.Add(11);
		tc.AssertEquals(11, set.GetCount(), "Add 11 and check count.");
		set.Add(12);
		tc.AssertEquals(12, set.GetCount(), "Add 12 and check count.");
		set.Add(13);
		tc.AssertEquals(13, set.GetCount(), "Add 13 and check count.");
		set.Add(14);
		tc.AssertEquals(14, set.GetCount(), "Add 14 and check count.");
		set.Add(15);
		tc.AssertEquals(15, set.GetCount(), "Add 15 and check count.");
		set.Add(16);
		tc.AssertEquals(16, set.GetCount(), "Add 16 and check count.");
		set.Add(17);
		tc.AssertEquals(17, set.GetCount(), "Add 17 and check count.");
		set.Add(18);
		tc.AssertEquals(18, set.GetCount(), "Add 18 and check count.");
		set.Add(19);
		tc.AssertEquals(19, set.GetCount(), "Add 19 and check count.");
		set.Add(20);
		tc.AssertEquals(20, set.GetCount(), "Add 20 and check count.");
		set.Add(21);
		tc.AssertEquals(21, set.GetCount(), "Add 21 and check count.");
		set.Add(22);
		tc.AssertEquals(22, set.GetCount(), "Add 22 and check count.");
		set.Add(23);
		tc.AssertEquals(23, set.GetCount(), "Add 23 and check count.");

		tc.AssertEquals(23, set.GetCount(), "Make sure GetCount returns 23 items.");
		try
		{
			set.Add(24);
			tc.LogResult(RESULT_FAILED, "Adding a 24th item did not throw an exception.");
		}
		catch (exception ex)
		{
			tc.LogResult(RESULT_PASSED, "Adding a 24th item threw an exception.");
		}
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}


//##############################################################################
//###   Contains 
//##############################################################################

/**************************************/
void ContainsAfterAdd()
{
	TestCase tc("Add various without collisions, and check Contains().");

	try
	{
		HashSet set;
		tc.AssertEquals(0, set.GetCount(), "GetCount returns 0 on empty set.");
		set.Add(5);
		tc.AssertEquals(1, set.GetCount(), "Add 5, then make sure GetCount returns 1.");
		tc.Assert(set.Contains(5), "Make sure hash-set contains 5");
		set.Add(3);
		tc.AssertEquals(2, set.GetCount(), "Add 3, then make sure GetCount returns 2.");
		tc.Assert(set.Contains(3), "Make sure hash-set contains 3");
		set.Add(7);
		tc.AssertEquals(3, set.GetCount(), "Add 7, then make sure GetCount returns 3.");
		tc.Assert(set.Contains(7), "Make sure hash-set contains 7");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void ContainsAfterAddNegative()
{
	TestCase tc("Add various without collisions, and check for items not in set.");

	try
	{
		HashSet set;
		tc.AssertEquals(0, set.GetCount(), "GetCount returns 0 on empty set.");
		set.Add(5);
		tc.AssertEquals(1, set.GetCount(), "Add 5, then make sure GetCount returns 1.");
		set.Add(3);
		tc.AssertEquals(2, set.GetCount(), "Add 3, then make sure GetCount returns 2.");
		set.Add(7);
		tc.AssertEquals(3, set.GetCount(), "Add 7, then make sure GetCount returns 3.");
		tc.Assert(!set.Contains(4), "Make sure hash-set does not contain 4");
		tc.AssertEquals(TestHashSet::Blank1(), TestHashSet::GetDataAt(set, 4), "Index 4 is blank.");
		tc.Assert(!set.Contains(6), "Make sure hash-set does not contain 6");
		tc.AssertEquals(TestHashSet::Blank1(), TestHashSet::GetDataAt(set, 6), "Index 4 is blank.");
		tc.Assert(!set.Contains(8), "Make sure hash-set does not contain 8");
		tc.AssertEquals(TestHashSet::Blank1(), TestHashSet::GetDataAt(set, 8), "Index 4 is blank.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}


//##############################################################################
//###   Collisions
//##############################################################################

/**************************************/
void CollisionsBasic()
{
	TestCase tc("Do a basic add with collisions.");

	try
	{
		HashSet set;
		set.Add(6);
		tc.AssertEquals(1, set.GetCount(), "Add 6 and check count.");
		tc.Assert(set.Contains(6), "List contains 6");
		set.Add(29);
		tc.AssertEquals(2, set.GetCount(), "Add 29.  GetCount returns 2.");
		tc.Assert(set.Contains(29), "List contains 29");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void CollisionsOverlapping()
{
	TestCase tc("Do some overlapping collisions.");

	try
	{
		HashSet set;
		set.Add(2);
		tc.AssertEquals(1, set.GetCount(), "Add 2 and check count.");
		tc.Assert(set.Contains(2), "List contains 2");

		set.Add(4);
		tc.AssertEquals(2, set.GetCount(), "Add 4 and check count.");
		tc.Assert(set.Contains(4), "List contains 4");

		set.Add(6);
		tc.AssertEquals(3, set.GetCount(), "Add 6 and check count.");
		tc.Assert(set.Contains(6), "List contains 6");

		set.Add(8);
		tc.AssertEquals(4, set.GetCount(), "Add 8 and check count.");
		tc.Assert(set.Contains(8), "List contains 8");

		set.Add(25);
		tc.AssertEquals(5, set.GetCount(), "Add 25.  This collides with 2 and ends up between 2 and 4.");
		tc.Assert(set.Contains(25), "List contains 25");
		tc.AssertEquals(25, TestHashSet::GetDataAt(set, 3), "Index 3 contains 25.");

		set.Add(5);
		tc.AssertEquals(6, set.GetCount(), "Add 5.  This fills a hole between 4 and 6.");
		tc.Assert(set.Contains(5), "List contains 5");

		set.Add(48);
		tc.AssertEquals(7, set.GetCount(), "Add 48.  This collides with 2 and ends up between 6 and 8.");
		tc.Assert(set.Contains(8), "List contains 8");
		tc.AssertEquals(48, TestHashSet::GetDataAt(set, 7), "Index 7 contains 48.");

		set.Add(3);
		tc.AssertEquals(8, set.GetCount(), "Add 3.  3's spot is taken, so it ends up at position 9.");
		tc.Assert(set.Contains(8), "List contains 3");
		tc.AssertEquals(3, TestHashSet::GetDataAt(set, 9), "Index 9 contains 3.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void CollisionsOverlappingWithWrap()
{
	TestCase tc("Do some overlapping collisions with wrap-round.");

	try
	{
		HashSet set;
		set.Add(20);
		tc.AssertEquals(1, set.GetCount(), "Add 20 and check count.");
		tc.Assert(set.Contains(20), "List contains 20.");

		set.Add(22);
		tc.AssertEquals(2, set.GetCount(), "Add 22 and check count.");
		tc.Assert(set.Contains(22), "List contains 22.");

		set.Add(24);
		tc.AssertEquals(3, set.GetCount(), "Add 24 and check count.");
		tc.Assert(set.Contains(24), "List contains 24.  This wraps around to position 1.");

		set.Add(26);
		tc.AssertEquals(4, set.GetCount(), "Add 26.  This wraps around to position 3.");
		tc.Assert(set.Contains(26), "List contains 26.");

		set.Add(43);
		tc.AssertEquals(5, set.GetCount(), "Add 43.  This collides with 20 and ends up between 20 and 22.");
		tc.Assert(set.Contains(43), "List contains 43.");
		tc.AssertEquals(43, TestHashSet::GetDataAt(set, 21), "Index 21 contains 43.");

		set.Add(25);
		tc.AssertEquals(6, set.GetCount(), "Add 25.  This fills a hole between 24 and 26.");
		tc.Assert(set.Contains(25), "List contains 5");

		set.Add(66);
		tc.AssertEquals(7, set.GetCount(), "Add 66.  This collides with 20 and ends up between 24 and 26.");
		tc.Assert(set.Contains(66), "List contains 8");
		tc.AssertEquals(66, TestHashSet::GetDataAt(set, 0), "Index 0 contains 66.");

		set.Add(21);
		tc.AssertEquals(8, set.GetCount(), "Add 21.  21's spot is taken, so it ends up after 26.");
		tc.Assert(set.Contains(21), "List contains 21");
		tc.AssertEquals(21, TestHashSet::GetDataAt(set, 4), "Index 4 contains 21.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void CollisionsWithOverflow()
{
	TestCase tc("Test overflow with multiple collisions.");

	try
	{
		HashSet set;
		set.Add(1);
		tc.AssertEquals(1, set.GetCount(), "Add 1 and check count.");
		set.Add(3);
		tc.AssertEquals(2, set.GetCount(), "Add 3 and check count.");
		set.Add(5);
		tc.AssertEquals(3, set.GetCount(), "Add 5 and check count.");
		set.Add(7);
		tc.AssertEquals(4, set.GetCount(), "Add 7 and check count.");
		set.Add(9);
		tc.AssertEquals(5, set.GetCount(), "Add 9 and check count.");
		set.Add(11);
		tc.AssertEquals(6, set.GetCount(), "Add 11 and check count.");
		set.Add(13);
		tc.AssertEquals(7, set.GetCount(), "Add 13 and check count.");
		set.Add(15);
		tc.AssertEquals(8, set.GetCount(), "Add 15 and check count.");
		set.Add(17);
		tc.AssertEquals(9, set.GetCount(), "Add 17 and check count.");
		set.Add(19);
		tc.AssertEquals(10, set.GetCount(), "Add 19 and check count.");
		set.Add(21);
		tc.AssertEquals(11, set.GetCount(), "Add 21 and check count.");
		set.Add(23);
		tc.AssertEquals(12, set.GetCount(), "Add 23 and check count.");
		set.Add(24);
		tc.AssertEquals(13, set.GetCount(), "Add 24 and check count.");
		set.Add(25);
		tc.AssertEquals(14, set.GetCount(), "Add 25 and check count.");
		set.Add(26);
		tc.AssertEquals(15, set.GetCount(), "Add 26 and check count.");
		set.Add(27);
		tc.AssertEquals(16, set.GetCount(), "Add 27 and check count.");
		set.Add(28);
		tc.AssertEquals(17, set.GetCount(), "Add 28 and check count.");
		set.Add(29);
		tc.AssertEquals(18, set.GetCount(), "Add 29 and check count.");
		set.Add(30);
		tc.AssertEquals(19, set.GetCount(), "Add 30 and check count.");
		set.Add(31);
		tc.AssertEquals(20, set.GetCount(), "Add 31 and check count.");
		set.Add(32);
		tc.AssertEquals(21, set.GetCount(), "Add 32 and check count.");
		set.Add(33);
		tc.AssertEquals(22, set.GetCount(), "Add 33 and check count.");
		set.Add(34);
		tc.AssertEquals(23, set.GetCount(), "Add 34 and check count.");

		tc.AssertEquals(23, set.GetCount(), "Make sure GetCount returns 23 items.");
		try
		{
			set.Add(35);
			tc.LogResult(RESULT_FAILED, "Adding a 24th item did not throw an exception.");
		}
		catch (exception ex)
		{
			tc.LogResult(RESULT_PASSED, "Adding a 24th item threw an exception.");
		}
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}


//##############################################################################
//###   Removal
//##############################################################################

/**************************************/
void RemovalBasic()
{
	TestCase tc("Do a basic add with collisions.");

	try
	{
		HashSet set;
		tc.AssertEquals(TestHashSet::Blank1(), TestHashSet::GetDataAt(set, 10), "Index 10 is marked as blank.");
		set.Add(2310);
		tc.AssertEquals(1, set.GetCount(), "Add 2310 and check count.");
		tc.Assert(set.Contains(2310), "List contains 2310");
		tc.AssertEquals(2310, TestHashSet::GetDataAt(set, 10), "Index 10 contains 2310.");

		set.Remove(2310);
		tc.AssertEquals(0, set.GetCount(), "Remove 2310, and count is 0.");
		tc.Assert(!set.Contains(2310), "List does not contain 2310.");
		tc.AssertEquals(TestHashSet::Blank2(), TestHashSet::GetDataAt(set, 10), "Index 10 is marked as blank (but previously occupied).");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void RemovalWithCollisions()
{
	TestCase tc("Remove an item that got inserted out of place.");

	try
	{
		HashSet set;
		set.Add(2);
		tc.AssertEquals(1, set.GetCount(), "Add 2 and check count.");
		tc.Assert(set.Contains(2), "List contains 2");

		set.Add(4);
		tc.AssertEquals(2, set.GetCount(), "Add 4 and check count.");
		tc.Assert(set.Contains(4), "List contains 4");

		set.Add(25);
		tc.AssertEquals(3, set.GetCount(), "Add 25 and check count.  This collides with 2 and ends up in idx 3.");
		tc.Assert(set.Contains(4), "List contains 25");
		tc.AssertEquals(25, TestHashSet::GetDataAt(set, 3), "Index 3 contains 25.");

		set.Add(27);
		tc.AssertEquals(4, set.GetCount(), "Add 27 and check count.  This collides with 4 and ends up in idx 5.");
		tc.Assert(set.Contains(4), "List contains 27");
		tc.AssertEquals(27, TestHashSet::GetDataAt(set, 5), "Index 5 contains 27.");

		set.Add(3);
		tc.AssertEquals(5, set.GetCount(), "Add 3 and check count.  This collides with 25, and ends up in idx 6.");
		tc.Assert(set.Contains(3), "List contains 3");
		tc.AssertEquals(3, TestHashSet::GetDataAt(set, 6), "Index 6 contains 3.");

		set.Remove(25);
		tc.AssertEquals(4, set.GetCount(), "Remove 25 and check count.");
		tc.Assert(!set.Contains(25), "List does not contain 2310.");
		tc.AssertEquals(TestHashSet::Blank2(), TestHashSet::GetDataAt(set, 3), "Index 3 is marked as blank (but previously occupied).");

		tc.Assert(set.Contains(3), "Make sure 3 still appears in the hash-set.");

		set.Remove(2);
		tc.AssertEquals(3, set.GetCount(), "Remove 2 and check count.");
		tc.Assert(!set.Contains(2), "List does not contain 2.");
		tc.AssertEquals(TestHashSet::Blank2(), TestHashSet::GetDataAt(set, 2), "Index 2 is marked as blank (but previously occupied).");

		tc.Assert(set.Contains(3), "Make sure 3 still appears in the hash-set.");

		set.Remove(4);
		tc.AssertEquals(2, set.GetCount(), "Remove 4 and check count.");
		tc.Assert(!set.Contains(4), "List does not contain 4.");
		tc.AssertEquals(TestHashSet::Blank2(), TestHashSet::GetDataAt(set, 4), "Index 4 is marked as blank (but previously occupied).");

		tc.Assert(set.Contains(3), "Make sure 3 still appears in the hash-set.");

		set.Remove(27);
		tc.AssertEquals(1, set.GetCount(), "Remove 27 and check count.");
		tc.Assert(!set.Contains(27), "List does not contain 27.");
		tc.AssertEquals(TestHashSet::Blank2(), TestHashSet::GetDataAt(set, 4), "Index 4 is marked as blank (but previously occupied).");

		tc.Assert(set.Contains(3), "Make sure 3 still appears in the hash-set.");

		set.Add(28);
		tc.AssertEquals(2, set.GetCount(), "Add 28 and check count.");
		tc.Assert(set.Contains(28), "List contains 28");
		tc.AssertEquals(28, TestHashSet::GetDataAt(set, 5), "Index 5 contains 28.");

		tc.Assert(set.Contains(3), "Make sure 3 still appears in the hash-set.");

		set.Add(26);
		tc.AssertEquals(3, set.GetCount(), "Add 26 and check count.");
		tc.Assert(set.Contains(28), "List contains 26");
		tc.AssertEquals(26, TestHashSet::GetDataAt(set, 3), "Index 3 contains 26.");

		tc.Assert(set.Contains(3), "Make sure 3 still appears in the hash-set.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}

/**************************************/
void Clear()
{
	TestCase tc("The clear function clears the hash table.");

	try
	{
		HashSet set;
		set.Add(2);
		tc.AssertEquals(1, set.GetCount(), "Add 2 and check count.");
		tc.Assert(set.Contains(2), "List contains 2.");

		set.Add(4);
		tc.AssertEquals(2, set.GetCount(), "Add 4 and check count.");
		tc.Assert(set.Contains(4), "List contains 4.");

		set.Add(3);
		tc.AssertEquals(3, set.GetCount(), "Add 3 and check count.");
		tc.Assert(set.Contains(3), "List contains 3.");

		set.Remove(3);
		tc.AssertEquals(2, set.GetCount(), "Remove 3 and check count.");
		tc.Assert(!set.Contains(3), "List no longer contains 3.");
		tc.AssertEquals(TestHashSet::Blank2(), TestHashSet::GetDataAt(set, 3), "Index 3 is marked as blank (but previously occupied).");

		set.Clear();

		tc.AssertEquals(0, set.GetCount(), "Count is reset to 0.");
		for (int i = 0; i < HASH_MAX; i++)
			tc.AssertEquals(TestHashSet::Blank1(), TestHashSet::GetDataAt(set, i), "Validate element init.");
	}
	catch (exception ex)
	{
		tc.LogException(ex);
	}
}



//##############################################################################
//###   main
//##############################################################################

/**************************************/
int main()
{
	// Constructor tests
	ConstructorBasic();
	ConstructorCheckCount();
	ConstructorCheckCapacity();

	// Add
	AddItemAndCheckBasic();
	AddVariousNoCollisions();
	AddWithWrapAround();
	AddSameItemTwice();
	AddToCapacity();

	// Contains
	ContainsAfterAdd();
	ContainsAfterAddNegative();

	// Collisions
	CollisionsBasic();
	CollisionsOverlapping();
	CollisionsOverlappingWithWrap();
	CollisionsWithOverflow();

	// Removal
	RemovalBasic();
	RemovalWithCollisions();
	Clear();

    TestCase::PrintSummary();
    return 0;
}
