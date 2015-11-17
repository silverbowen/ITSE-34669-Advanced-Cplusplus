#include <random>
#include <time.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#define TOSSNUM 500000000 // that's 500 million
using namespace std;

template<typename t>       // this templatized function does the initial pass
void refPass(t &counter);  // to establish a reference for no extra threads

template<typename t>   // this templatized function does passes with 1, 2, 4,
void forLoop(t &counterDummy); // 8, and 16 threads to determine efficiency

template<typename t>   // this templatized function displays the results of
void printResults(t &counter, int elapsed); // each coin flip pass

struct Counter  // this struct has no safeguards and is not multithread safe
{
    long heads, tails;  // member variables

    Counter() : heads(0), tails(0) {} // constructor

    void coinToss(int toss) // do a toss, increment the result
    { (toss) ? ++heads: ++tails; }
};

struct ConcurrentCounter  // this stuct uses mutex to ensure multithread safety
{
    long heads, tails;  // member variables
    mutex m;

    ConcurrentCounter() : heads(0), tails(0) {} // constructor

    void coinToss(int toss) // lock the struct, do a toss,
    {                       // increment the result, unlock the struct
        m.lock();
        (toss) ? ++heads: ++tails;
        m.unlock();
    }
};

struct AtomicCounter  // this struct uses atomic typing to ensure multithread
{                     // safety. It is much faster than mutex version.
    atomic<long> heads, tails;  // member variables

    AtomicCounter() : heads(0), tails(0) {} // constructor

    void coinToss(int toss) // do a toss, increment the result
    { (toss) ? ++heads: ++tails; } // atomic type locks itself
};

int main () // main just calls our three types of trials
{
    cout << "Running trials with no concurrency measures in place...\n\n";
    Counter counter1;  // initialize a struce
    refPass(counter1); // send struct reference
    forLoop(counter1); // send struct reference

    cout << "Running trials using mutex concurrency measures...\n\n";
    ConcurrentCounter counter2; // as above
    refPass(counter2);
    forLoop(counter2);

    cout << "Running trials using atomic concurrency measures...\n\n";
    AtomicCounter counter3; // as above
    refPass(counter3);
    forLoop(counter3);

    return 0;
}  // end main

template<typename t>
void refPass(t &counter)
{   // reference pass without threading
    // declare variables
    time_t start, finish;
    default_random_engine dre;
    uniform_int_distribution<int> tosser(0,1);

    // print # of threads used
    cout << "Tossing " << TOSSNUM
         << " coins without spawning any extra threads...\n\n";

    //initialize start
    start = time(0);

    // toss coins
    for(int i = 0; i < TOSSNUM; ++i)
       counter.coinToss(tosser(dre));

    // initialize finish
    finish = time(0);

    // print results
    printResults(counter, finish - start);
} // end refPass

template<typename t>
void forLoop(t &counterDummy)
{   // threading starts here
    // for loop spawns 1, 2, 4, 8, then 16 threads, does tosses, prints result
    for (int i = 1; i < 17; i += i)
    {
        // declare variables
        vector<thread> threads;
        time_t start, finish;
        t counter;

        // print # of threads used for this pass
        cout << "Tossing " << TOSSNUM << " coins using "
             << i << " thread(s)...\n\n";

        //initialize start
        start = time(0);

        // for loop spawns i threads, push_backs into thread vector,
        // using lambda to do each toss
        for (int j = 0; j < i; ++j)
            threads.push_back(thread([&counter, i] ()
            {
                default_random_engine dre;
                uniform_int_distribution<int> tosser(0,1);
                for(int k = 0; k < TOSSNUM/i; ++k)
                    counter.coinToss(tosser(dre));
            }));

        // join the threads
        for(auto& thread : threads)
            thread.join();

       // initialize finish
       finish = time(0);

       // print results of pass
       printResults(counter, finish - start);
    } // end for loop
}  // end forLoop

template<typename t>
void printResults(t &counter, int elapsed)
{   // print results of pass
    cout << "Total number heads = " << counter.heads << endl
         << "Total number tails = " << counter.tails << endl
         << "Total elapsed time = " // library default is microseconds
         << elapsed << "\n\n";
}
