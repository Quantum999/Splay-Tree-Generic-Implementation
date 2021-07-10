/**
 * Generic Splay Trees
 *
 * Example Implementation
 * This test file provides examples to use all methods of the splay tree library.
 *
 * To better visualize the splay tree, you can try using this tool, https://www.cs.usfca.edu/~galles/visualization/SplayTree.html
 */

#include<iostream>
#include <vector>
#include <list>

#include "splay.h"

using namespace std;


// Sample User Defined Class
class Year
{
    //This class only compares the year. Example taken for simplicity.
    public:
    Year():yyyy_(0) {}
    Year(int yyyy) : yyyy_(yyyy) { }
    bool operator<(const Year& rhs) const
    {
        return yyyy_<rhs.yyyy_;
    }
    bool operator>(const Year& rhs) const
    {
        return yyyy_>rhs.yyyy_;
    }
    bool operator==(const Year& rhs) const
    {
        return yyyy_==rhs.yyyy_;
    }
    bool operator!=(const Year& rhs) const
    {
        return !(*this==rhs);
    }

    friend ostream& operator<<(ostream& os, const Year& y);

    private:
    int yyyy_;

};

ostream& operator<<(ostream& os, const Year& y)
{
        os << y.yyyy_;
        return os;
}

template<typename ptr_t>
ptr_t my_advance_(ptr_t it, int n, random_access_iterator_tag)
{
	cout << "random access\n";
	return it + n;
}

template<typename ptr_t>
ptr_t my_advance_(ptr_t it, int n, input_iterator_tag)
{
	cout << "input iterator\n";
	while(n--)
	{
		++it;
	}
	return it;
}

template<typename ptr_t>
ptr_t my_advance(ptr_t it, int n)
{
	return my_advance_(it, n, typename iterator_traits<ptr_t>::iterator_category());
}


int main()
{

    //Example 1
    //Insertion and Iterator Traversal
    #if 0

    splay<int> s;
    s.insert(10);
    s.insert(30);
    s.insert(22);
    s.insert(18);
    s.insert(16);
    s.insert(17);

    cout<<"Inorder forward traversal:  ";
    for(auto i = s.begin(); i!=s.end(); ++i)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";

    cout<<"Inorder reverse traversal:  ";
    for(auto i = s.rbegin(); i!=s.rend(); ++i)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";
    #endif

    //Example 2
    //Search
    #if 0

    splay<int> s;
    s.insert(10);
    s.insert(30);
    s.insert(22);
    s.insert(18);
    s.insert(16);
    s.insert(17);

    cout<<"Inorder traversal before searching :";
    for(auto i = s.begin(); i!=s.end(); ++i)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";

    if(s.find(22)!=s.end())
    {
        cout<<"Find Result: 22 is present in the splay tree.\n";
    }
    else
    {
        cout<<"Find Result: 22 is not present in the splay tree.\n";
    }

    cout<<"Inorder traversal after searching for 22: ";
    for(auto i = s.begin(); i!=s.end(); ++i)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";

    #endif


    //Example 3
    //Copy Constructor, Equality Check and Deletion
    #if 0

    splay<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(22);
    s1.insert(18);
    s1.insert(16);
    s1.insert(17);

    splay<int> s2(s1);

    cout<<"Inorder traversal of s1 before deletion :";
    for(auto i = s1.begin(); i!=s1.end(); ++i) cout<<*i<<" "; cout<<"\n";
    cout<<"Inorder traversal of s2 before deletion :";
    for(auto i = s2.begin(); i!=s2.end(); ++i) cout<<*i<<" "; cout<<"\n";

    s1.erase(16);
    cout<<"Deleted 16 from s1. "<<"\n";

    cout<<"Inorder traversal of s1 after deletion from s1:";
    for(auto i = s1.begin(); i!=s1.end(); ++i) cout<<*i<<" "; cout<<"\n";
    cout<<"Inorder traversal of s2 after deletion from s1:";
    for(auto i = s2.begin(); i!=s2.end(); ++i) cout<<*i<<" "; cout<<"\n";

    #endif


    //Example 4
    //Using other inbuilt data types and remaining methods
    #if 0

    splay<char> s;
    s.insert('a');
    s.insert('f');
    s.insert('e');
    s.insert('b');
    s.insert('d');
    s.insert('c');

    cout<<"Inorder traversal of s: ";
    for(auto i = s.begin(); i!=s.end(); ++i) cout<<*i<<" "; cout<<"\n";

    cout<<boolalpha;

    cout<<"Is s empty? "<<s.empty()<<"\n";
    cout<<"Size of s: "<<s.size()<<"\n";

    s.clear();

    cout<<"s is cleared."<<"\n";

    cout<<"Is s empty? "<<s.empty()<<"\n";
    cout<<"Size of s: "<<s.size()<<"\n";
    #endif

    //Example 5
    //Using user defined type as splay value class
    //User defined types has to support comparision (<, ==, >)
    #if 0

    splay<Year> y;

    Year y1(2004);
    Year y2(2000);
    Year y3(2012);
    Year y4(2008);
    Year y5(2016);
    Year y6(2020);

    y.insert(y1);
    y.insert(y2);
    y.insert(y3);
    y.insert(y4);
    y.insert(y5);
    y.insert(y6);


    cout<<"Inorder traversal of s: ";
    for(auto i = y.begin(); i!=y.end(); ++i) cout<<*i<<" "; cout<<"\n";
    cout<<boolalpha;

    auto i = y.begin();
    auto j = i + 3;
    j += 2;
    cout << *(j) << "\n";

    cout<<"Is s empty? "<<y.empty()<<"\n";
    cout<<"Size of s: "<<y.size()<<"\n";

    y.clear();

    cout<<"s is cleared."<<"\n";

    cout<<"Is s empty? "<<y.empty()<<"\n";
    cout<<"Size of s: "<<y.size()<<"\n";

    #endif

    #if 0

    splay<Year> y;

    Year y1(2004);
    Year y2(2000);
    Year y3(2012);
    Year y4(2008);
    Year y5(2016);
    Year y6(2020);

    y.insert(y1);
    y.insert(y2);
    y.insert(y3);
    y.insert(y4);
    y.insert(y5);
    y.insert(y6);


    cout<<"Inorder traversal of y: ";
    for(auto i = y.begin(); i!=y.end(); ++i) cout<<*i<<" "; cout<<"\n";

    cout<<"\n";

    cout<<"Inorder reverse traversal:  ";
    for(auto i = y.rbegin(); i!=y.rend(); ++i)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";

    cout << y.base() << "\n";
    if(y.find(2016)!=y.end())
    {
        cout<<"Find Result: 2016 is present in the splay tree.\n";
    }
    else
    {
        cout<<"Find Result: 2016 is not present in the splay tree.\n";
    }

    cout<<"Inorder traversal after searching for 2016: ";
    for(auto i = y.begin(); i!=y.end(); ++i)
    {
        cout<<*i<<" ";
    }

    cout<<"\n";
    cout << y.base() << "\n";

    splay<Year> z;

    Year z1(2004);
    Year z2(2000);
    Year z3(2012);
    Year z4(2008);
    Year z5(2016);
    Year z6(2020);

    z.insert(z1);
    z.insert(z2);
    z.insert(z3);
    z.insert(z4);
    z.insert(z5);
    z.insert(z6);

    cout << z.base() << "\n";
    z.erase(2008);

    cout<<"Deleted 2008 from z. "<<"\n";
    cout<<"Inorder traversal of z after deletion from z:";
    for(auto i = z.begin(); i!=z.end(); ++i) cout<<*i<<" "; cout<<"\n";
    cout << z.base() << "\n";
    cout<<"Inorder traversal of y after deletion from z:";
    for(auto i = y.begin(); i!=y.end(); ++i) cout<<*i<<" "; cout<<"\n";

    auto i = y.begin();
    auto j = i + 3;
    j += 2;
    cout << *(j) << "\n";

    cout<<"Is y empty? "<<y.empty()<<"\n";
    cout<<"Size of y: "<<y.size()<<"\n";

    y.clear();

    cout<<"y is cleared."<<"\n";

    cout<<"Is y empty? "<<y.empty()<<"\n";
    cout<<"Size of y: "<<y.size()<<"\n";

    cout<<"Is z empty? "<<z.empty()<<"\n";
    cout<<"Size of z: "<<z.size()<<"\n";

    #endif

    #if 0

	splay<Year> y;

    Year y1(2004);
    Year y2(2000);
    Year y3(2012);
    Year y4(2008);
    Year y5(2016);
    Year y6(2020);

    y.insert(y1);
    y.insert(y2);
    y.insert(y3);
    y.insert(y4);
    y.insert(y5);
    y.insert(y6);

	auto i = y.begin();
	i = my_advance(i, 3);
	cout << "val : " << *i << "\n";

    #endif // 1

    #if 1
    splay<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(22);
    s1.insert(18);
    s1.insert(16);
    s1.insert(17);

    auto i = s1.begin();
	i = my_advance(i, 3);
	cout << "val : " << *i << "\n";

    #endif // 1

    return 0;
}
