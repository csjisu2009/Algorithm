//Race Condition and Mutex
//(https://www.youtube.com/watch?v=3ZxZPeXPaM4)

//ver 1
/*
#include <iostream>
#include <thread>
#include <string>

using namespace std;

void function_1() {
	for (int i = 0; i > -100; --i)
		cout << "From t1: " << i << endl;
}

int main() {
	thread t1(function_1);

	for (int i = 0; i < 100; ++i)
		cout << "From main: " << i << endl;

	t1.join();

	return 0;
}
*/


//ver 2
/*
#include <iostream>
#include <thread>
#include <string>
#include <mutex>

using namespace std;

mutex mu;

void shared_print(string msg, int id) {
	mu.lock();
	cout << msg << id << endl;
	mu.unlock();
}

void function_1() {
	for (int i = 0; i > -100; --i)
		shared_print(string("From t1: "), i);//cout << "From t1: " << i << endl;
}

int main() {
	thread t1(function_1);

	for (int i = 0; i < 100; ++i)
		shared_print(string("From main: "), i);//cout << "From main: " << i << endl;

	t1.join();

	return 0;
}
*/


//ver 3
/*
#include <iostream>
#include <thread>
#include <string>
#include <mutex>

using namespace std;

mutex mu;

void shared_print(string msg, int id) {
	lock_guard<mutex> guard(mu);	//RAII
	//mu.lock();
	cout << msg << id << endl;
	//mu.unlock();
}

void function_1() {
	for (int i = 0; i > -100; --i)
		shared_print(string("From t1: "), i);
}

int main() {
	thread t1(function_1);

	for (int i = 0; i < 100; ++i)
		shared_print(string("From main: "), i);

	t1.join();

	return 0;
}
*/


//ver 4
/*
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>

using namespace std;

class LogFile {
	mutex m_mutex;
	ofstream f;
public:
	LogFile() {
		f.open("log.txt");
	}//Need destructor to close file

	void shared_print(string msg, int id) {
		lock_guard<mutex> locker(m_mutex);
		f << "From " << msg << ": " <<  id << endl;
	}

	//Never return f  to the outside world
	ofstream& getStream() { return f; }

	//Never pass f as an argument to user provided function
	void processf(void fun(ofstream&)) {
		fun(f);
	}
};

void function_1(LogFile& log) {
	for (int i = 0; i > -100; --i)
		log.shared_print(string("From t1: "), i);
}

int main() {
	LogFile log;
	thread t1(function_1, ref(log));

	for (int i = 0; i < 100; ++i)
		log.shared_print(string("From main: "), i);

	t1.join();

	return 0;
}
*/


//ver 5(not an executable code)
/*
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>

using namespace std;

class LogFile {
	mutex m_mutex;
	ofstream f;
public:
	LogFile() {
		f.open("log.txt");
	}//Need destructor to close file

	void shared_print(string msg, int id) {
		lock_guard<mutex> locker(m_mutex);
		f << "From " << msg << ": " << id << endl;
	}

	//Never return f  to the outside world
	ofstream& getStream() { return f; }

	//Never pass f as an argument to user provided function
	void processf(void fun(ofstream&)) {
		fun(f);
	}
};

class stack {
	int* _data;
	mutex _mu;
public:
	int& pop();//void pop();//pops off the item on top of the stack
	int& top();//returns the item on top
	//...
};

void function_1(stack& st) {
	//int v = st.top();
	//st.pop();
	int v = st.pop();
	process(v);
}

/*
Avoiding Data Race
1.Use mutex to synchronize data access
2.Never leak a handle of data to outside
3.Design interface appropriately
*/
/*
int main() {
	LogFile log;
	thread t1(function_1, ref(log));

	for (int i = 0; i < 100; ++i)
		log.shared_print(string("From main: "), i);

	t1.join();

	return 0;
}
*/
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//Deadlock
//(https://www.youtube.com/watch?v=_N0B5ua7oN8&t=9s)

//ver1
//from ver 4 of Race Condition and Mutex

/*
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>

using namespace std;

class LogFile {
	mutex _mu;
	ofstream _f;
public:
	LogFile() {
		_f.open("_log.txt");
	}//Need destructor to close file

	void shared_print(string msg, int id) {
		lock_guard<mutex> locker(_mu);
		cout << "From " << msg << ": " << id << endl;
	}
};

void function_1(LogFile& log) {
	for (int i = 0; i > -100; --i)
		log.shared_print(string("t1: "), i);
}

int main() {
	LogFile log;
	thread t1(function_1, ref(log));

	for (int i = 0; i < 100; ++i)
		log.shared_print(string("From main: "), i);

	t1.join();

	return 0;
}
*/


//ver 2.0 -- classic deadlock situation

//the t1 thread locks the mutex '_mu', and before t1 go ahead and lock '_mu2', the main thread locks the mutex '_mu2'
//so the t1 is waiting for the main thread to release '_mu2'
//and the main thread is waiting for t1 to release '_mu'
//it is a deadlock 

//To avoid deadlock, there is one thing that you can do is..
//Make sure everybody is locking the mutexes in the same order!! -- (look at the code ver 2.1 / 2.2)

/*
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>

using namespace std;

class LogFile {
	mutex _mu;
	mutex _mu2;
	ofstream _f;
public:
	LogFile() {
		_f.open("_log.txt");
	}//Need destructor to close file

	void shared_print(string msg, int id) {
		lock_guard<mutex> locker(_mu);
		lock_guard<mutex> locker2(_mu2);
		cout << "From " << msg << ": " << id << endl;
	}

	void shared_print2(string msg, int id) {
		lock_guard<mutex> locker2(_mu2);
		lock_guard<mutex> locker(_mu);
		cout << "From " << msg << ": " << id << endl;
	}
};

void function_1(LogFile& log) {
	for (int i = 0; i > -100; --i)
		log.shared_print2(string("t1: "), i);
}

int main() {
	LogFile log;
	thread t1(function_1, ref(log));

	for (int i = 0; i < 100; ++i)
		log.shared_print(string("From main: "), i);

	t1.join();

	return 0;
}
*/


//ver 2.1 -- How to avoid deadlock -- Make sure everybody is locking the mutexes in the same order!!
//(ver 2.0 -- classic deadlock situation)

/*
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>

using namespace std;

class LogFile {
	mutex _mu;
	mutex _mu2;
	ofstream _f;
public:
	LogFile() {
		_f.open("_log.txt");
	}//Need destructor to close file

	void shared_print(string msg, int id) {
		lock_guard<mutex> locker(_mu);//Make sure everybody is locking the mutexes in the same order!!
		lock_guard<mutex> locker2(_mu2);
		cout << "From " << msg << ": " << id << endl;
	}

	void shared_print2(string msg, int id) {
		lock_guard<mutex> locker(_mu);//Make sure everybody is locking the mutexes in the same order!!
		lock_guard<mutex> locker2(_mu2);
		cout << "From " << msg << ": " << id << endl;
	}
};

void function_1(LogFile& log) {
	for (int i = 0; i > -100; --i)
		log.shared_print2(string("t1: "), i);
}

int main() {
	LogFile log;
	thread t1(function_1, ref(log));

	for (int i = 0; i < 100; ++i)
		log.shared_print(string("From main: "), i);

	t1.join();

	return 0;
}
*/


//ver 2.2 -- How to avoid deadlock
//(ver 2.0 -- classic deadlock situation)

#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>

using namespace std;

class LogFile {
	mutex _mu;
	mutex _mu2;
	ofstream _f;
public:
	LogFile() {
		_f.open("_log.txt");
	}//Need destructor to close file

	void shared_print(string msg, int id) {
		lock(_mu, _mu2);
		lock_guard<mutex> locker(_mu, adopt_lock);//Make sure everybody is locking the mutexes in the same order!!
		lock_guard<mutex> locker2(_mu2, adopt_lock);
		cout << "From " << msg << ": " << id << endl;
	}

	void shared_print2(string msg, int id) {
		lock(_mu, _mu2);
		lock_guard<mutex> locker(_mu, adopt_lock);//Make sure everybody is locking the mutexes in the same order!!
		lock_guard<mutex> locker2(_mu2, adopt_lock);
		cout << "From " << msg << ": " << id << endl;
	}
};

void function_1(LogFile& log) {
	for (int i = 0; i > -100; --i)
		log.shared_print2(string("t1: "), i);
}

int main() {
	LogFile log;
	thread t1(function_1, ref(log));

	for (int i = 0; i < 100; ++i)
		log.shared_print(string("From main: "), i);

	t1.join();

	return 0;
}









//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
#include <iostream>
#include <thread>
#include <string>

using namespace std;

class Fctor {
public:
	void operator()(string& msg) {//parameter to thread always passed by value!! Believe it or not!!!!
		cout << "t1 says: " << msg << endl;
		msg = "Trust is the mother of deceit.";
	}
};

int main() {
	string s = "Where there is no trust, there is no love";
	cout << this_thread::get_id() << endl;

	thread t1( (Fctor()), std::ref(s) );  //t1 starts running   //std::ref(s)
	cout << "t1.get_id(): " << t1.get_id() << endl;

	thread t2 = move(t1);
	cout << "t2.get_id(): " << t2.get_id() << endl;

	t2.join();

	cout << "from main: " << s << endl;
	return 0;
}
*/



































//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Vector

/*
#include <iostream>

using namespace std;

typedef int Rank;
#define  DEFAULT_CAPACITY 3

int max(int a, int b) {
	if (a >= b)  return a;
	else  return b;
}

class Vector {
private:
	Rank _size;  int _capacity;  int* _elem;
protected:
public:
	//constructor and destructor
	Vector(int c = DEFAULT_CAPACITY) { _elem = new int[_capacity = c];  _size = 0; }
	Vector(int * A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }
	Vector(Vector const&  V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); }
	Vector(Vector const& V) { copyFrom(V._elem, 0, V._size); }
	~Vector() { delete[] _elem; }

	void copyFrom(int* const A, Rank lo, Rank hi) {
		_elem = new int[_capacity = 2 * (hi - lo)];
		_size = 0;
		while (lo < hi)  _elem[_size++] = A[lo++];
	}

	void expand() {
		if (_size < _capacity) return;
		_capacity = max(_capacity, DEFAULT_CAPACITY);
		int* oldElem = _elem; _elem = new int[_capacity <<= 1];
		for (int i = 0; i < _size; i++)
			_elem[i] = oldElem[i];
		delete[] oldElem;
	}

	int& operator[](Rank r) const {
		return _elem[r];
	}

	int size() {
		return _size;
	}

	Rank put(Rank r, int const & e) {
		_elem[r] = e;
		return r;
	}

	Rank insert(Rank r, int const & e) {
		expand();
		for (int i = _size; i > r; i--)
			_elem[i] = _elem[i - 1];
		_elem[r] = e; _size++;
		return r;
	}

	int remove(Rank lo, Rank hi) {
		if (lo == hi) return 0;
		while (hi < _size) _elem[lo++] = _elem[hi++];
		_size = lo;
		return hi - lo;
	}

	Vector remove(Rank r) {
		int e = _elem[r];
		remove(r, r + 1);
		return e;
	}

	Rank find(int & e, Rank lo, Rank hi) const {
		while ((lo < hi--) && (e != _elem[hi]));
		return hi;
	}

	int mergeSort(Rank lo, Rank hi) {
		int count = 0;

		if (hi - lo < 2)  return 0;
		int mi = (lo + hi) >> 1;
		count = mergeSort(lo, mi);
		count += mergeSort(mi, hi);
		count += merge(lo, mi, hi);

		return count;
	}

	int merge(Rank lo, Rank mi, Rank hi) {
		int count = 0;
		int* A = _elem + lo;

		int lb = mi - lo;
		int* B = new int[lb];
		for (Rank i = 0; i < lb; B[i] = A[i++]);

		int lc = hi - mi;
		int* C = _elem + mi;
		for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc); ) {
			if ((j < lb) && (k >= lc || (B[j] <= C[k]))) { 
				A[i++] = B[j++];
				count += lc - k;
			}
			if ((k < lc) && (j >= lb || (B[j] > C[k]))) {
				A[i++] = C[k++];
				//count += lb - j;
			}
		}
		
		return count;
	}
/*
	void mergeSort(Rank lo, Rank hi) {
		if (hi - lo < 2)  return;
		int mi = (lo + hi) >> 1;
		mergeSort(lo, mi);
		mergeSort(mi, hi);
		merge(lo, mi, hi);
	}

	void merge(Rank lo, Rank mi, Rank hi) {
		int* A = _elem + lo;

		int lb = mi - lo;
		int* B = new int[lb];
		for (Rank i = 0; i < lb; B[i] = A[i++]);

		int lc = hi - mi;
		int* C = _elem + mi;
		for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc); ) {
			if ((j < lb) && (k >= lc || (B[j] <= C[k]))) A[i++] = B[j++];
			if ((k < lc) && (j >= lb || (B[j] > C[k])))  A[i++] = C[k++];
		}
	}

	*/
/*
};

int main() {
	Vector a;
	int nTemp;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> nTemp;
		a.insert(i, nTemp);
	}
	
	//for (int i = 0; i < 5; ++i)
	//	cout << a[i] << " ";
	//cout << endl;

	cout << a.mergeSort(0, n) << endl;

	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;
	

	return 0;
}

*/































//Initiated Beads of the first string(for example, AAABBBAAA -> -)
/*
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define Type char

char str[10001];
int n;
int indexStr;  char c;

struct ListNode {
	Type data;
	ListNode* pred;  ListNode* succ;

	ListNode();
	ListNode(Type _data, ListNode* _pred, ListNode* _succ);
}*header = nullptr, *trailer = nullptr;
ListNode::ListNode() {
	pred = nullptr;  succ = nullptr;
}
ListNode::ListNode(Type _data, ListNode* _pred, ListNode* _succ) :data(_data), pred(_pred), succ(_succ) {}

void StringToList(char* str, int len) {
	header = new ListNode();  trailer = new ListNode();
	header->pred = nullptr;  header->succ = trailer;
	trailer->pred = header;  trailer->succ = nullptr;

	if (len == 0)  return;

	int i = 0;
	while (len--) {
		ListNode* addedNode = new ListNode(str[i], trailer->pred, trailer);
		trailer->pred->succ = addedNode;
		trailer->pred = addedNode;
		i++;
	}
}

void PrintList() {
	ListNode* p = header->succ;
	//if no ZumaNode between header and trailer
	if (p == trailer)  cout << "-" << endl;

	else {
		while (p != trailer) {
			cout << p->data;
			p = p->succ;
		}
		cout << endl;
	}
}

void PrintAddressList() {
	ListNode* p = header->succ;
	//if no ZumaNode between header and trailer
	if (p == trailer)  cout << "-" << endl;

	else {
		while (p != trailer) {
			cout << p << "--";
			p = p->succ;
		}
		cout << endl;
	}
}


ListNode* InsertAtIndex(int Index, char const & c) {
	ListNode* p = header->succ;
	while (Index--)  p = p->succ;
	ListNode* insertedNode = new ListNode(c, p->pred, p);
	p->pred->succ = insertedNode;
	p->pred = insertedNode;

	return insertedNode;
}

void Remove(ListNode* p) {
	p->pred->succ = p->succ;  p->succ->pred = p->pred;
	delete p;
}

void InitiateBeads() {
	ListNode* p = nullptr;  char compareData;  int count = 1;
	ListNode* nextP = nullptr;
	if (header->succ != trailer) {
		p = header->succ;
		compareData = p->data;
	}

	while (1) {
		PrintList();
		PrintAddressList();
		if (header->succ == trailer)  break;
		if (p->succ == trailer)  break;
		cout << "p: " << p << ", p->data: " << p->data << ", compareData: " << compareData << endl;
		cout << "count: " << count << endl;
		if (p->succ->data == compareData) {
			count++;
			p = p->succ;
		}
		else {
			compareData = p->succ->data;
			nextP = p->succ;
			if(count >= 3)
				while (count--) {
					p = p->pred;
					Remove(p->succ);
				}
			p = nextP;
			count = 1;
		}
	}
	if (count >= 3)
		while (count--) {
			p = p->pred;
			Remove(p->succ);
		}
}

void RemoveBeads(ListNode* p) {
	int count = 1;
	ListNode* check = nullptr;  ListNode* temp = nullptr;

	//if no one is same with p->data, return
	if ((p->pred != nullptr) && (p->succ != nullptr))
		if (p->pred->data != p->data && p->succ->data != p->data)
			return;

	while (count != -100) {
		if (header->succ == trailer)  break;
		count = 1;
		check = p->pred;//  checkSucc = p->succ;


		//check pred beads are same with the "new added bead" or not
		//caution: "new added bead" - only at 1st time, from 2nd time it is just a one of beads added before)
		while (check != header) {
			if (check->data == p->data) {
				count++;
				check = check->pred;
			}
			else
				break;
		}

		temp = check;//store pred limit at temp
		check = p->succ;//start to check pred
		p = temp;//store pred limit at p, it's for next loop delete

				 //check succ beads are same with the "new added bead" or not
		while (check != trailer) {
			if (check->data == p->succ->data) {//bug: check->data == p->data
				count++;
				check = check->succ;
			}
			else
				break;
		}

		if (count >= 3) {
			temp = p->succ;
			while (count--) {
				temp = temp->succ;
				Remove(temp->pred);
			}
		}
		else
			count = -100;
	}
}

int main() {
	fgets(str, 10001, stdin);
	int strLen = strlen(str) - 1;

	StringToList(str, strLen);
	InitiateBeads();
	//PrintList();
	cin >> n;
	ListNode* insertedAdr;
	for (int i = 0; i < n; ++i) {
		cin >> indexStr >> c;
		insertedAdr = InsertAtIndex(indexStr, c);
		RemoveBeads(insertedAdr);
		PrintList();
	}
	return 0;
}
*/


















/*
#define  WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

DWORD WINAPI ThreadFunc(LPVOID);

int global = 1;

int main() {
	HANDLE hThrd;
	DWORD threadId;
	int i;
	for (i = 0; i < 5; i++)
		ThreadFunc((LPVOID)i);//single thread
	Sleep(3000);
	return EXIT_SUCCESS;
}

DWORD WINAPI ThreadFunc(LPVOID n) {
	int i;
	for (i = 0; i < 100; i++)
		printf("%d%d%d%d%d%d%d%d global = %d\n", n, n, n, n, n, n, n, global++);
	return 0;
}
*/





















/*
void Print(ListNode* node) {
ListNode* temp = node;
printf("ListNodes are: ");
while (temp->succ != nullptr) {
printf("%d ", temp->data);
temp = temp->succ;
}
printf("%d\n", temp->data);
}
*/











/*
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Node {
	int data;
	Node* next;

	void Insert(int _data) {
		Node* temp = new Node();
		temp->data = _data;
		temp->next = nullptr;
		head = temp;
	}

	void Print() {
		Node* temp = head;
		printf("List is: ");
		while (temp != nullptr) {
			printf("%d", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
};

Node* head;

int main() {
	head = nullptr;

	return 0;
}
*/