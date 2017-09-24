1)
// constructing priority queues
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};

int main ()
{
  int myints[]= {10,60,50,20};

  std::priority_queue<int> first;
  std::priority_queue<int> second (myints,myints+4);
  std::priority_queue<int, std::vector<int>, std::greater<int> >
                            third (myints,myints+4);
  // using mycomparison:
  typedef std::priority_queue<int,std::vector<int>,mycomparison> mypq_type;

  mypq_type fourth;                       // less-than comparison
  mypq_type fifth (mycomparison(true));   // greater-than comparison

  return 0;
}

output:
--------
- First is empty.
- Second contains the four ints defined for myints, with 60 (the highest) at its top.
- Third has the same four ints, but because it uses greater instead of the default (which is less), it has 10 as its top element.
- Fourth and fifth are very similar to first: they are both empty, except that these use mycomparison for comparisons, which is a special stateful comparison function that behaves differently depending on a flag set on construction.


2) 
#include <iostream>
#include <queue>
#include <vector>
using std::priority_queue;
using std::vector;
using std::cout;
using std::endl;


class Toast
{
public:
	int bread;
	int butter;

	Toast(int bread, int butter)
		: bread(bread), butter(butter)
	{

	}
};

struct ToastCompare
{
	bool operator()(const Toast &t1, const Toast &t2) const
	{
		int t1value = t1.bread;
		int t2value = t2.bread;
		return t1value > t2value;
	}
};

// outputs 2,3,4,5
int main(int argc, char ** argv)
{
	Toast toast1(2, 200);
	Toast toast2(3, 30);
	Toast toast3(4, 10);
	Toast toast4(5, 1);

	//priority_queue<Toast> queue;
	priority_queue<Toast, vector<Toast>, ToastCompare> queue;

	queue.push(toast1);
	queue.push(toast2);
	queue.push(toast3);
	queue.push(toast4);

	while (!queue.empty())
	{
		Toast t = queue.top();
		cout << "bread " << t.bread << " butter " << t.butter << std::endl;
		queue.pop();
	}

	return 0;
}


3)
#include <queue>
#include <iostream>
using namespace std;

class Person {
public:
    Person(int age) : age(age) {}
    int age;
};

bool operator<(const Person& a, const Person& b) {
    return a.age > b.age;
}

// outputs : 1,2,3,4..8,9,10
int main() {
    priority_queue<Person> Q;
    for (int i : {1, 10, 2, 9, 3, 8, 4, 7, 5, 6})
        Q.push(Person(i));
    while (!Q.empty()) {
        Person p = Q.top();
        Q.pop();
        cout << p.age << " ";
    }
    return 0;
}


4)
// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main () {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  std::sort (myvector.begin(), myvector.end(), std::greater<int>()); //80 71 53 45 33 32 26 12

  // using function as comp
  std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

  // using object as comp
  std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

