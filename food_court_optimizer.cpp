
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Customer {
    string name;
    int serviceTime; // time required to serve this customer
};

class FoodCourt {
    int stalls;
    vector<string> stallNames;
    vector< queue<Customer> > stallQueues;
    vector<int> totalWaitTime; // total waiting time per stall

public:
    FoodCourt(int s = 0) {
        init(s);
    }

    void init(int s) {
        stalls = s;
        stallNames.assign(stalls, "");
        stallQueues.assign(stalls, queue<Customer>());
        totalWaitTime.assign(stalls, 0);
    }

    void setStallName(int idx, const string &name) {
        if (idx >= 0 && idx < stalls) {
            stallNames[idx] = name;
        }
    }
    int getStallCount() const {
    return stalls;
}

void addCustomerToSpecificStall(int stall, const string &cname, int st) {
    Customer c{cname, st};
    stallQueues[stall].push(c);
    totalWaitTime[stall] += st;

    cout << "Customer \"" << cname << "\" added to stall "
         << stall << " (" << stallNames[stall] << ") manually.\n";
}


    // Add customer to stall with least waiting time
    void addCustomer(const string &cname, int st) {
        int bestStall = 0;
        for (int i = 1; i < stalls; i++) {
            if (totalWaitTime[i] < totalWaitTime[bestStall]) {
                bestStall = i;
            }
        }

        Customer c{cname, st};
        stallQueues[bestStall].push(c);
        totalWaitTime[bestStall] += st;

        cout << "Customer \"" << cname << "\" assigned to stall: "
             << bestStall << " (" << stallNames[bestStall] << ")\n";
    }

    // Serve (remove) first customer from a chosen stall
    void serveCustomer(int stall) {
        if (stall < 0 || stall >= stalls) {
            cout << "Invalid stall index.\n";
            return;
        }
        if (stallQueues[stall].empty()) {
            cout << "No customers in this stall.\n";
            return;
        }

        Customer c = stallQueues[stall].front();
        stallQueues[stall].pop();
        totalWaitTime[stall] -= c.serviceTime;

        cout << "Served customer \"" << c.name << "\" from stall "
             << stall << " (" << stallNames[stall] << ")\n";
    }

    // Display all queues
    void displayQueues() const {
        cout << "\n--- Current Stall Queues ---\n";
        for (int i = 0; i < stalls; i++) {
            cout << i << " (" << stallNames[i] << ") | Waiting Time: "
                 << totalWaitTime[i] << "\nQueue: ";
            queue<Customer> temp = stallQueues[i];
            if (temp.empty()) {
                cout << "EMPTY";
            } else {
                while (!temp.empty()) {
                    cout << "[" << temp.front().name
                         << ", " << temp.front().serviceTime << "] ";
                    temp.pop();
                }
            }
            cout << "\n\n";
        }
    }

    // Stall with minimum wait time
    void showBestStall() const {
        int best = 0;
        for (int i = 1; i < stalls; i++) {
            if (totalWaitTime[i] < totalWaitTime[best]) {
                best = i;
            }
        }
        cout << "Best stall to join right now: " << best
             << " (" << stallNames[best] << ")"
             << " | Wait Time = " << totalWaitTime[best] << "\n";
    }
};

void createFoodCourt(FoodCourt &fc) {
    int s;
    cout << "Enter number of stalls: ";
    cin >> s;
    cin.ignore();

    fc.init(s);

    cout << "Enter names of stalls:\n";
    for (int i = 0; i < s; i++) {
        string name;
        cout << "Stall " << i << ": ";
        getline(cin, name);
        if (name.empty()) name = "Stall_" + to_string(i);
        fc.setStallName(i, name);
    }
}

int main() {
    FoodCourt fc;
    bool initialized = false;

    while (true) {
        cout << "\n========== FOOD COURT WAITING TIME OPTIMIZER ==========\n";
        cout << "1. Create Stalls\n";
        cout << "2. Add Customer\n";
        cout << "3. Serve Customer\n";
        cout << "4. Display All Queues\n";
        cout << "5. Show Best Stall\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        int ch;
        cin >> ch;

        if (ch == 6) {
            cout << "Exiting...\n";
            break;
        }

        if (ch == 1) {
            createFoodCourt(fc);
            initialized = true;
            continue;
        }

        if (!initialized) {
            cout << "Create stalls first (Option 1).\n";
            continue;
        }

        string cname;
        int st, stall;

        switch (ch) {
            case 2:
                cout << "Enter customer name: ";
                cin >> cname;
                cout << "Enter estimated service time: ";
                cin >> st;

                cout << "\nChoose mode:\n";
                cout << "1. Select stall manually\n";
                cout << "2. Auto assign to best stall\n";
                int mode;
                cin >> mode;

                if (mode == 1) {
                    cout << "Enter stall index: ";
                    cin >> stall;

                    if (stall < 0 || stall >= fc.getStallCount()) {
                        cout << "Invalid stall index.\n";
                    } else {
                        fc.addCustomerToSpecificStall(stall, cname, st);
                    }
                }
                else if (mode == 2) {
                    fc.addCustomer(cname, st);
                }
                else {
                    cout << "Invalid choice.\n";
        }
        break;


            case 3:
                cout << "Enter stall index to serve from: ";
                cin >> stall;
                fc.serveCustomer(stall);
                break;

            case 4:
                fc.displayQueues();
                break;

            case 5:
                fc.showBestStall();
                break;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
