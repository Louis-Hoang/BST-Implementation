#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "bst.cpp"
// #include "usecase.cpp"

using namespace std;

void test_empty()
{
	try
	{
		// <string, int>
		BST<string, int> bst;
		if (!bst.empty())
		{
			cout << "Incorrect empty result." << endl;
		}

		bst.insert("one", 1);
		if (bst.empty())
		{
			cout << "Incorrect empty result." << endl;
		}

		// <int, string>
		BST<int, string> bst1;
		if (!bst1.empty())
		{
			cout << "Incorrect empty result." << endl;
		}

		bst1.insert(1, "one");
		if (bst1.empty())
		{
			cout << "Incorrect empty result." << endl;
		}

		// <double, char>
		BST<double, char> bst2;
		if (!bst2.empty())
		{
			cout << "Incorrect empty result." << endl;
		}

		bst2.insert(1.23455, 'a');
		if (bst2.empty())
		{
			cout << "Incorrect empty result." << endl;
		}

		// <double, double>
		BST<double, double> bst3;
		if (!bst3.empty())
		{
			cout << "Incorrect empty result." << endl;
		}

		bst3.insert(1.23455, 3.1415192);
		if (bst3.empty())
		{
			cout << "Incorrect empty result." << endl;
		}
	}
	catch (exception &e)
	{
		cerr << "Error in determining if BST is empty : " << e.what() << endl;
	}
}

void test_insert()
{
	try
	{
		// <string, int>
		BST<string, int> bst;
		bst.insert("one", 1);
		string bst_str = bst.to_string();
		if (bst_str != "1")
		{
			cout << "Incorrect result of inserting (\"one\", 1). This is what you got : " << bst_str << endl;
		}
		for (int i = 2; i <= 10; i++)
		{
			bst.insert("some data", i);
		}

		bst_str = bst.to_string();
		if (bst_str != "1 2 3 4 5 6 7 8 9 10")
		{
			cout << "Incorrect result of inserting keys 1-10 in order. This is what you got : " << bst_str << endl;
		}

		// <int, double>
		double vals[10] = {5.1212, 2.1212, 7.1212, 1.1212, 3.1212, 4.1212, 6.1212, 9.1212, 8.1212, 10.111};
		BST<int, double> balanced_bst;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst.insert(100, vals[i]);
		}

		bst_str = balanced_bst.to_string();
		if (bst_str != "5.1212 2.1212 7.1212 1.1212 3.1212 6.1212 9.1212 4.1212 8.1212 10.111")
		{
			cout << "Incorrect result of inserting keys {5.1212, 2.1212, 7.1212, 1.1212, 3.1212, 4.1212, 6.1212, 9.1212, 8.1212, 10.111}. This is what you got: " << bst_str << endl;
		}

		// <double, int>
		int vals1[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
		BST<double, int> balanced_bst1;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst1.insert(3.141592654, vals1[i]);
		}

		bst_str = balanced_bst1.to_string();
		if (bst_str != "5 2 7 1 3 6 9 4 8 10")
		{
			cout << "Incorrect result of inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. This is what you got : " << bst_str << endl;
		}

		// <string, char>
		char vals2[10] = {'e', 'b', 'g', 'a', 'c', 'd', 'f', 'i', 'h', 'j'};
		BST<string, char> balanced_bst2;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst2.insert("some data", vals2[i]);
		}

		bst_str = balanced_bst2.to_string();
		if (bst_str != "e b g a c f i d h j")
		{
			cout << "Incorrect result of inserting keys {'e', 'b', 'g', 'a', 'c', 'd', 'f', 'i', 'h', 'j'}. This is what you got : " << bst_str << endl;
		}
	}
	catch (exception &e)
	{
		cerr << "Error inserting into bst : " << e.what() << endl;
	}
}

void test_get()
{
	try
	{
		// <string, int>
		BST<string, int> bst;
		string val = bst.get(0);
		if (val != "")
		{
			cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
		}
		bst.insert("one", 1);

		val = bst.get(1);
		if (val != "one")
		{
			cout << "Incorrect get result. Expected \"one\" but got : " << val << endl;
		}

		// <int, double>
		BST<int, double> bst1;
		int val1 = bst1.get(3.14159265);
		if (val1 != 0) // what to return when get from empty<int, double>?
		{
			cout << "Incorrect get result from empty bst. Expected 0 but got " << val1 << endl;
		}
		bst1.insert(100, 3.14159265);
		bst1.insert(101, 3.15555555);
		bst1.insert(102, 3.16666666);

		val1 = bst1.get(3.14159265);
		if (val1 != 100)
		{
			cout << "Incorrect get result. Expected 100 but got : " << val1 << endl;
		}

		val1 = bst1.get(3.16666666);
		if (val1 != 102)
		{
			cout << "Incorrect get result. Expected 102 but got : " << val1 << endl;
		}

		// <double, string>
		BST<double, string> bst2;
		double val2 = bst2.get("a");
		if (val2 != 0) // what to return when get from empty<double, char>?
		{
			cout << "Incorrect get result from empty bst. Expected 0 but got " << val2 << endl;
		}
		bst2.insert(3.14159265, "b");
		bst2.insert(3.14159265, "c");
		bst2.insert(3.12222222, "d");

		val2 = bst2.get("b");
		if (val2 != 3.14159265)
		{
			cout << "Incorrect get result. Expected 3.14159265 but got : " << val2 << endl;
		}

		val2 = bst2.get("d");
		if (val2 != 3.12222222)
		{
			cout << "Incorrect get result. Expected 3.12222222 but got : " << val2 << endl;
		}
	}
	catch (exception &e)
	{
		cerr << "Error in getting data from bst : " << e.what() << endl;
	}
}

void test_remove()
{
	try
	{
		// <string, int>
		int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
		BST<string, int> balanced_bst;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst.insert("some data", vals[i]);
		}
		balanced_bst.remove(7);

		string bst_str = balanced_bst.to_string();
		if (bst_str != "5 2 8 1 3 6 9 4 10")
		{
			cout << "Incorrect result of removing 7. This is what you got : " << bst_str << endl;
		}

		// <char, string>
		string vals1[10] = {"eee", "bbb", "ggg", "aaa", "ccc", "ddd", "fff", "iii", "hhh", "jjj"};
		BST<char, string> balanced_bst1;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst1.insert('a', vals1[i]);
		}
		balanced_bst1.remove("iii");

		bst_str = balanced_bst1.to_string();
		if (bst_str != "eee bbb ggg aaa ccc fff jjj ddd hhh")
		{
			cout << "Incorrect result of removing \"iii\". This is what you got : " << bst_str << endl;
		}

		balanced_bst1.remove("hhh");
		balanced_bst1.remove("eee");
		balanced_bst1.remove("ggg");

		bst_str = balanced_bst1.to_string();
		if (bst_str != "fff bbb jjj aaa ccc ddd")
		{
			cout << "Incorrect result of removing {\"hhh\", \"eee\", \"ggg\"}. This is what you got : " << bst_str << endl;
		}

		// <double, double>
		double vals2[10] = {5.1212, 2.1212, 7.1212, 1.1212, 3.1212, 4.1212, 6.1212, 9.1212, 8.1212, 10.111};
		BST<double, double> balanced_bst2;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst2.insert(1.111101, vals2[i]);
		}
		balanced_bst2.remove(9.1212);

		bst_str = balanced_bst2.to_string();
		if (bst_str != "5.1212 2.1212 7.1212 1.1212 3.1212 6.1212 10.111 4.1212 8.1212")
		{
			cout << "Incorrect result of removing 9.1212. This is what you got : " << bst_str << endl;
		}

		balanced_bst2.remove(8.1212);
		balanced_bst2.remove(5.1212);
		balanced_bst2.remove(7.1212);

		bst_str = balanced_bst2.to_string();
		if (bst_str != "6.1212 2.1212 10.111 1.1212 3.1212 4.1212")
		{
			cout << "Incorrect result of removing {8.1212, 5.1212, 7.1212}. This is what you got : " << bst_str << endl;
		}
	}
	catch (exception &e)
	{
		cerr << "Error in removing node from bst : " << e.what() << endl;
	}
}

void test_max_data()
{
	try
	{
		// <string, int>
		int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
		BST<string, int> balanced_bst;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
		}

		string max_str = balanced_bst.max_data();
		if (max_str != "10 data")
		{
			cout << "Incorrect result of max_data. Expected \"10 data\" but got : " << max_str << endl;
		}

		// <char, string>
		string vals1[10] = {"eee", "bbb", "ggg", "aaa", "ccc", "ddd", "fff", "iii", "hhh", "jjj"};
		char _vals1[10] = {'e', 'b', 'g', 'a', 'c', 'd', 'f', 'i', 'h', 'j'};
		BST<char, string> balanced_bst1;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst1.insert(_vals1[i], vals1[i]);
		}

		char max_char = balanced_bst1.max_data();
		if (max_char != 'j')
		{
			cout << "Incorrect result of max_data. Expected 'j' but got : " << max_char << endl;
		}

		// // <double, char>
		char vals2[10] = {'e', 'b', 'g', 'a', 'c', 'd', 'f', 'i', 'h', 'j'};
		double _vals2[10] = {5.1212, 2.1212, 7.1212, 1.1212, 3.1212, 4.1212, 6.1212, 9.1212, 8.1212, 10.1212};
		BST<double, char> balanced_bst2;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst2.insert(_vals2[i], vals2[i]);
		}

		double max_double = balanced_bst2.max_data();
		if (max_double != 10.1212)
		{
			cout << "Incorrect result of max_data. Expected 10.1212 but got : " << max_double << endl;
		}
	}
	catch (exception &e)
	{
		cerr << "Error in determining data of max node in bst : " << e.what() << endl;
	}
}

void test_max_key()
{
	try
	{
		// <string, int>
		int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
		BST<string, int> balanced_bst;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
		}

		int max_k = balanced_bst.max_key();
		if (max_k != 10)
		{
			cout << "Incorrect result of max_key. Expected 10 but got : " << max_k << endl;
		}

		// <char, string>
		string vals1[10] = {"eee", "bbb", "ggg", "aaa", "ccc", "ddd", "fff", "iii", "hhh", "jjj"};
		BST<char, string> balanced_bst1;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst1.insert('a', vals1[i]);
		}

		string max_k1 = balanced_bst1.max_key();
		if (max_k1 != "jjj")
		{
			cout << "Incorrect result of max_key. Expected \"jjj\" but got : " << max_k1 << endl;
		}

		// <double, char>
		char vals2[10] = {'e', 'b', 'g', 'a', 'c', 'd', 'f', 'i', 'h', 'j'};
		BST<double, char> balanced_bst2;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst2.insert(3.1212, vals2[i]);
		}

		char max_k2 = balanced_bst2.max_key();
		if (max_k2 != 'j')
		{
			cout << "Incorrect result of max_key. Expected 'j' but got : " << max_k2 << endl;
		}
	}
	catch (exception &e)
	{
		cerr << "Error in determining key of max node in bst : " << e.what() << endl;
	}
}

void test_min_data()
{
	try
	{
		// <string, int>
		int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
		BST<string, int> balanced_bst;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
		}

		string min_str = balanced_bst.min_data();
		if (min_str != "1 data")
		{
			cout << "Incorrect result of min_data. Expected \"1 data\" but got : " << min_str << endl;
		}

		// <char, string>
		string vals1[10] = {"eee", "bbb", "ggg", "aaa", "ccc", "ddd", "fff", "iii", "hhh", "jjj"};
		char _vals1[10] = {'e', 'b', 'g', 'a', 'c', 'd', 'f', 'i', 'h', 'j'};
		BST<char, string> balanced_bst1;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst1.insert(_vals1[i], vals1[i]);
		}

		char min_char = balanced_bst1.min_data();
		if (min_char != 'a')
		{
			cout << "Incorrect result of min_data. Expected 'a' but got : " << min_char << endl;
		}

		// <double, char>
		char vals2[10] = {'e', 'b', 'g', 'a', 'c', 'd', 'f', 'i', 'h', 'j'};
		double _vals2[10] = {5.1212, 2.1212, 7.1212, 1.1212, 3.1212, 4.1212, 6.1212, 9.1212, 8.1212, 10.1212};
		BST<double, char> balanced_bst2;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst2.insert(_vals2[i], vals2[i]);
		}

		double min_double = balanced_bst2.min_data();
		if (min_double != 1.1212)
		{
			cout << "Incorrect result of min_data. Expected 1.1212 but got : " << min_double << endl;
		}
	}
	catch (exception &e)
	{
		cerr << "Error in determining data of min node in bst : " << e.what() << endl;
	}
}

void test_min_key()
{
	try
	{
		// <string, int>
		int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
		BST<string, int> balanced_bst;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
		}

		int min_k = balanced_bst.min_key();
		if (min_k != 1)
		{
			cout << "Incorrect result of min_key. Expected 1 but got : " << min_k << endl;
		}

		// <char, string>
		string vals1[10] = {"eee", "bbb", "ggg", "aaa", "ccc", "ddd", "fff", "iii", "hhh", "jjj"};
		BST<char, string> balanced_bst1;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst1.insert('a', vals1[i]);
		}

		string min_k1 = balanced_bst1.min_key();
		if (min_k1 != "aaa")
		{
			cout << "Incorrect result of min_key. Expected \"aaa\" but got : " << min_k1 << endl;
		}

		// // <double, char>
		char vals2[10] = {'e', 'b', 'g', 'a', 'c', 'd', 'f', 'i', 'h', 'j'};
		BST<double, char> balanced_bst2;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst2.insert(3.1212, vals2[i]);
		}

		char min_k2 = balanced_bst2.min_key();
		if (min_k2 != 'a')
		{
			cout << "Incorrect result of min_key. Expected 'a' but got : " << min_k2 << endl;
		}
	}
	catch (exception &e)
	{
		cerr << "Error in determining key of min node in bst : " << e.what() << endl;
	}
}

void test_successor()
{
	try
	{
		// <string, int>
		int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
		BST<string, int> balanced_bst;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
		}
		int succ = balanced_bst.successor(4);
		if (succ != 5)
		{
			cout << "Incorrect result of successor of 4. Expected 5 but got : " << succ << endl;
		}
		succ = balanced_bst.successor(7);
		if (succ != 8)
		{
			cout << "Incorrect result of successor of 7. Expected 8 but got : " << succ << endl;
		}
		succ = balanced_bst.successor(10);
		if (succ != 0)
		{
			cout << "Incorrect result of successor of 10. Expected 0 but got : " << succ << endl;
		}

		// <char, double>
		double vals2[10] = {5.1212, 2.1212, 7.1212, 1.1212, 3.1212, 4.1212, 6.1212, 9.1212, 8.1212, 10.1212};
		BST<char, double> balanced_bst2;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst2.insert('a', vals2[i]);
		}
		double succ2 = balanced_bst2.successor(4.1212);
		if (succ2 != 5.1212)
		{
			cout << "Incorrect result of successor of 4.1212. Expected 5.1212 but got : " << succ2 << endl;
		}
		succ2 = balanced_bst2.successor(7.1212);
		if (succ2 != 8.1212)
		{
			cout << "Incorrect result of successor of 7.1212. Expected 8.1212 but got : " << succ2 << endl;
		}
		succ2 = balanced_bst2.successor(10.1212);
		if (succ2 != 0)
		{
			cout << "Incorrect result of successor of 10.1212. Expected 0 but got : " << succ2 << endl;
		}
	}
	catch (exception &e)
	{
		cerr << "Error in determining successor in bst : " << e.what() << endl;
	}
}

void test_in_order()
{
	try
	{
		// <string, int>
		BST<string, int> bst;
		for (int i = 1; i <= 10; i++)
		{
			bst.insert("some data", i);
		}

		string bst_str = bst.in_order();
		if (bst_str != "1 2 3 4 5 6 7 8 9 10")
		{
			cout << "Incorrect in_order result after inserting keys 1-10 in order. This is what you got : " << bst_str << endl;
		}

		// <string, int>
		int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
		BST<string, int> balanced_bst;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst.insert("some data", vals[i]);
		}

		bst_str = balanced_bst.in_order();
		if (bst_str != "1 2 3 4 5 6 7 8 9 10")
		{
			cout << "Incorrect in_order result after inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. This is what you got : " << bst_str << endl;
		}

		// <char, double>
		double vals1[10] = {5.1212, 2.1212, 7.1212, 1.1212, 3.1212, 4.1212, 6.1212, 9.1212, 8.1212, 10.111};
		BST<char, double> balanced_bst1;
		for (int i = 0; i < 10; i++)
		{
			balanced_bst1.insert('a', vals1[i]);
		}

		bst_str = balanced_bst1.in_order();
		if (bst_str != "1.1212 2.1212 3.1212 4.1212 5.1212 6.1212 7.1212 8.1212 9.1212 10.111")
		{
			cout << "Incorrect in_order result after inserting keys {5.1212, 2.1212, 7.1212, 1.1212, 3.1212, 4.1212, 6.1212, 9.1212, 8.1212, 10.111}. This is what you got : " << bst_str << endl;
		}

	}
	catch (exception &e)
	{
		cerr << "Error getting keys in_order from bst : " << e.what() << endl;
	}
}

void test_trim()
{
	try
	{
		// <string, int>
		BST<string, int> bst;
		int vals[3] = {1, 0, 2};
		for (int i = 0; i < 3; i++)
		{
			bst.insert(to_string(vals[i]) + " data", vals[i]);
		}
		bst.trim(1, 2);

		string bst_str = bst.to_string();
		if (bst_str != "1 2")
		{
			cout << "Incorrect tree after trimming 1 0 2 with low=1, high=2. This is what you got : " << bst_str << endl;
		}

		// <string, int>
		BST<string, int> bst2;
		int vals2[5] = {3, 0, 4, 2, 1};
		for (int i = 0; i < 5; i++)
		{
			bst2.insert(to_string(vals2[i]) + " data", vals2[i]);
		}
		bst2.trim(1, 3);

		bst_str = bst2.to_string();
		if (bst_str != "3 2 1")
		{
			cout << "Incorrect tree after trimming 3 0 4 2 1 with low=1, high=3. This is what you got : " << bst_str << endl;
		}

		// <double, char>
		BST<double, char> bst3;
		char vals3[3] = {'b', 'a', 'c'};
		for (int i = 0; i < 3; i++)
		{
			bst3.insert(5.1212, vals3[i]);
		}
		bst3.trim('a', 'c');

		bst_str = bst3.to_string();
		if (bst_str != "b a c")
		{
			cout << "Incorrect tree after trimming b a c with low='a', high='c'. This is what you got : " << bst_str << endl;
		}

		// // <char, string>
		BST<char, string> bst4;
		string vals4[5] = {"bbb", "aaa", "ccc", "fff", "ggg"};
		for (int i = 0; i < 5; i++)
		{
			bst4.insert('a', vals4[i]);
		}
		bst4.trim("aaa", "ccc");

		bst_str = bst4.to_string();
		if (bst_str != "bbb aaa ccc")
		{
			cout << "Incorrect tree after trimming bbb aaa ccc with low=\"aaa\", high='\"ccc\". This is what you got : " << bst_str << endl;
		}

	}
	catch (exception &e)
	{
		cerr << "Error in trimming the bst : " << e.what() << endl;
	}
}



int main()
{
	test_empty();
	test_insert();
	test_get();
	test_remove();
	test_max_data();
	test_max_key();
	test_min_data();
	test_min_key();
	test_successor();
	test_in_order();
	test_trim();

	cout << "Testing completed" << endl;

	return 0;
}