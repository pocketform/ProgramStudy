#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include"Binary_Search_Tree.h"

using std::vector;
using std::string;

/**
* Abstract Thread
*/
class Thread
{
public:
	Thread() {}
	virtual ~Thread() { CloseHandle(thread_handle); }
	virtual void start();
	virtual void join();
	virtual DWORD get_id() const { return tid; }
protected:
	virtual void run() = 0;
	friend DWORD thread_ftn(LPVOID T);
	HANDLE thread_handle;
	DWORD tid;
private:
	Thread(const Thread& src);
	Thread& operator=(const Thread& rhs);
};

/**
* standard thread function
*/
DWORD thread_ftn(LPVOID T)
{
	Thread* t = static_cast<Thread*>(T);
	t->run();
	return NULL;
}

void Thread::start()
{
	thread_handle = CreateThread(
		NULL, // default security
		0, // default stack size
		(LPTHREAD_START_ROUTINE)&thread_ftn, // thread function name
		(LPVOID)this, // argument to thread function
		0, // use default creation flags
		&tid);
}

void Thread::join()
{
	WaitForSingleObject(thread_handle, INFINITE);
}

/**
* some mutex class
*/
class MutexClass
{
public:
	MutexClass();
	virtual ~MutexClass();
	virtual void lock_mutex();
	virtual void unlock_mutex();
protected:
	HANDLE mutex;
};

MutexClass::MutexClass()
{
	mutex = CreateMutex(
		NULL, // default security
		FALSE, // initially not owned
		NULL); // unamed mutex
}

MutexClass::~MutexClass()
{
	CloseHandle(mutex);
}

void MutexClass::lock_mutex()
{
	DWORD wait_result;
	wait_result = WaitForSingleObject(
		mutex, // handle to mutex
		INFINITE); // no time-out interval
}

void MutexClass::unlock_mutex()
{
	ReleaseMutex(mutex);
}

/**
* global mutex object
*/
MutexClass mut;

/**
* shared buffer
*/
vector<string> buffer;

/**
* My Thread implementation of Thread
*/
class Producer : public Thread
{
protected:
	virtual void run();
};

/**
* His Thread implemenation of Thread
*/
class Consumer : public Thread
{
protected:
	virtual void run();
};

void Producer::run()
{
	mut.lock_mutex();
	buffer.push_back("Hello from Producer\n");
	mut.unlock_mutex();
}

void Consumer::run()
{
	BOOL done = FALSE;
	while (!done)
	{
		mut.lock_mutex();
		if (buffer.size() > 0)
		{
			std::cout << "got msg: " << buffer.front() << "\n";
			done = TRUE;
		}
		mut.unlock_mutex();
	}
}

class Hello_World : public Thread
{
protected:
	virtual void run();
};

void Hello_World::run()
{
	int times = 0;
	mut.lock_mutex();
	while (times<10)
	{
		std::cout << "Hello from Thread(handle) \n";
		times++;
	}
	mut.unlock_mutex();
}

class BTS_cg : public Thread
{
public:
protected:	
	Camparable t_BTS;
	virtual void run(int val);
private:
};

void BTS_cg::run(int val)
{
	mut.lock_mutex();
	t_BTS.set_value(val);
	mut.unlock_mutex();
}

int main()
{
	//Camparable tex;
	//tex.set_value(1);

	Producer prod;
	Consumer cons;
	Hello_World h_w;

	cons.start();
	Sleep(1000);
	prod.start();

	h_w.start();

	prod.join();
	cons.join();
	h_w.join();

	system("PAUSE");
	return 0;
}

