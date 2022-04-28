#include <iostream>
#include <queue>
#include <vector>
#include <ctime>

using namespace std;

class Task{
public:
    Task(int time){
        timestamp = time;
        pages = (rand()%20) + 1;
    }

    int getStamp(){
        return timestamp;
    }

    int getPages(){
        return pages;
    }

    int waitTime(int currenttime){
        return (currenttime - timestamp);
    }
private:
    int timestamp, pages;
};

class Printer{
public:
    Printer(int pagesPerMinute){
        pagerate = pagesPerMinute;
        timeRemaining = 0;
        working = false;
    }

    void tick(){
        if (working){
            timeRemaining--;
            if (timeRemaining <= 0)
                working = false;
        }
    }

    bool busy(){
        return working;
    }

    void startNext(Task newtask){
        currentTask = newtask;
        timeRemaining = newtask.getPages()*60/pagerate;
        working = true;
    }


private:
    int pagerate, timeRemaining;
    bool working;
    Task currentTask = {0}; //default is a dummy value;

};

bool newPrintTask(){
    /*
        uses random to decide if there is a new print task.
        generates a random number from 1...180, and returns
        a boolean indicating whether or not it equals 180.
    */
    return (rand()%180 + 1) == 180;
}

void simulation(int numSeconds, int pagesPerMinute){
    Printer labprinter(pagesPerMinute);
    queue<Task> printerQueue;
    vector<int> waitingTimes;

    for (int i = 0; i < numSeconds; ++i){
        if (newPrintTask()){
            Task task(i);
            printerQueue.push(task);
        }

        if (!labprinter.busy() && !printerQueue.empty()){
            Task nextTask = printerQueue.front();
            printerQueue.pop();

            waitingTimes.push_back(nextTask.waitTime(i));
            labprinter.startNext(nextTask);
        }

        labprinter.tick();
    }

    float total = 0.;
    for (int waitTime : waitingTimes)
        total += waitTime;

    cout << "Average Wait " << total/waitingTimes.size() << " secs " 
    << printerQueue.size() << " task remaining." << endl;
}

int main(){
    srand(time(NULL));

    /*
        1 hour := 3600 seconds

        ||| Total tasks == 20 / hour ||| -> 10 students, print 2 times per hour
        @ Assumptions
        printer printing rate := pages / minute == 10

        -> To simulate how long it takes for waiting.
    */
    int numSec = 3600;
    int pagePerMin = 10;
    for (int i = 0; i < 10; ++i){
        simulation(numSec, pagePerMin);
    }
    return 0;
}