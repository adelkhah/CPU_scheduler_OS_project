/*
___mennat khoday ra azz o va jall ke taatash mojebe ghorbat ast o be shokr andarash mazide nemat.
___har nafasi ke foro miravad momedde hayatast o chon bar miayad mofarrahe zat.
___pas dar har nafasi 2 nemat mojod ast o bar har nematy shokry vajeb.

___az dast o zabane ke barayad ?
___kaz ohdeye shokrash be dar ayad !


___man be to dami gharar natvanam kard
___va ehsane to ra shomar natvanam kard
####################
___gar bar tane man zaban shavad har moyee
___yek shokre to az hezar natvanam kard

*/

#include <bits/stdc++.h>
#define pb push_back
#define SALIMOON main
#define int long long

using namespace std;

struct process {
    string name;
    char type;
    int burst_time;
    int arrival_time;
    int rmd; // remained
    string state;
    int CPU_used;
    bool complete;

    void input() {
        cin >> name >> burst_time;
        CPU_used = 0;
        state = "ready";
        rmd = burst_time;
        complete = false;
        arrival_time = 0;
    }

};

int n;
int total_time;
vector<process> ready;
process running;


bool run(int i, int Qt) {
    if (Qt == -1) { // non preemptive
        running = ready[i];
        ready[i].state = "running";
        while (ready[i].rmd > 0) {
            ready[i].rmd--;
            ready[i].CPU_used++;
        }
        ready[i].state = "terminated";
        ready[i].complete = true;
        return true;
    } else {
        running = ready[i];
        ready[i].state = "running";
        while (ready[i].rmd > 0 && Qt > 0) {
            ready[i].rmd--;
            Qt--;
            ready[i].CPU_used++;
        }
        if (ready[i].rmd == 0) {
            ready[i].state = "terminated";
            ready[i].complete = true;
            return true;
        } else {
            ready[i].state = "ready";
            return false;
        }
    }
}

void show_queue() {
    cout << "running : " << running.name << endl;
    cout << "ready : ";
    for (int i = 0; i < ready.size(); i++) {
        cout << ready[i].name << " ";
    }
    cout << endl;
}

void First_Come_First_Served() {
    while (!ready.empty()) {
        run(0, -1);
        ready.erase(ready.begin());
        show_queue();
    }
}

bool cmp(const process &p1, const process &p2) {
    return p1.rmd < p2.rmd;
}

void Shortest_Job_First() {
    sort(ready.begin(), ready.end(), cmp);
    while (!ready.empty()) {
        run(0, -1);
        ready.erase(ready.begin());
        show_queue();
    }
}

void Round_Robin(int quantum) {
    while (!ready.empty()) {
        if (run(0, quantum)) { // process terminated
            ready.erase(ready.begin());
        } else { // process
            process pr = ready[0];
            ready.erase(ready.begin());
            ready.pb(pr);
        }
        show_queue();
    }
}

// extra credit
void HRRN() {
    int t = 0;
    while (!ready.empty()) {
        float hrr = -9999;

        // Response Ratio Variable
        float temp;

        // Variable to store next process selected
        int loc;
        for (int i = 0; i < ready.size(); i++) {

            // Checking if process has arrived and is Incomplete
            if (ready[i].arrival_time <= t && !ready[i].complete) {

                // Calculating Response Ratio
                temp = ((float) ready[i].burst_time + (t - ready[i].arrival_time)) / ready[i].burst_time;
                // Checking for Highest Response Ratio
                if (hrr < temp) {

                    // Storing Response Ratio
                    hrr = temp;

                    // Storing Location
                    loc = i;
                }
            }
        }
        run(loc, -1);
        t += ready[loc].burst_time;
        ready.erase(ready.begin() + loc);
        show_queue();
    }
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        process t;
        t.input();
        ready.pb(t);
        total_time += t.burst_time;
    }

}

int32_t SALIMOON() {
    input();
    //First_Come_First_Served();
    //Shortest_Job_First();
    //Round_Robin(1);
    HRRN();
}

// 5 A 5 B 4 C 3 D 2 E 1
