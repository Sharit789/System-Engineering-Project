#include <iostream>
#include <list>
using namespace std;

// Structure for memory block
struct Block {
    int id;        // process id (-1 if free)
    int size;
    bool isFree;
};

// Making Memory list
list<Block> memory;
int processCounter = 1;

// Display memory
void displayMemory() {
    cout << "\nMemory State:\n";
    for (auto &block : memory) {
        if (block.isFree)
            cout << "[Free: " << block.size << "] ";
        else
            cout << "[P" << block.id << ": " << block.size << "] ";
    }
    cout << endl;
}

// Merging free blocks
void mergeFreeBlocks() {
    auto it = memory.begin();
    while (it != memory.end()) {
        auto next = it;
        next++;
        if (next != memory.end() && it->isFree && next->isFree) {
            it->size += next->size;
            memory.erase(next);
        } else {
            it++;
        }
    }
}

// Allocating memory
void allocate(int size, int strategy) {
    auto selected = memory.end();

    if (strategy == 1) { // First Fit
        for (auto it = memory.begin(); it != memory.end(); it++) {
            if (it->isFree && it->size >= size) {
                selected = it;
                break;
            }
        }
    }
    else if (strategy == 2) {
        int minDiff = 1e9;
        for (auto it = memory.begin(); it != memory.end(); it++) {
            if (it->isFree && it->size >= size && (it->size - size) < minDiff) {
                minDiff = it->size - size;
                selected = it;
            }
        }
    }
    else if (strategy == 3) {
        int maxSize = -1;
        for (auto it = memory.begin(); it != memory.end(); it++) {
            if (it->isFree && it->size >= size && it->size > maxSize) {
                maxSize = it->size;
                selected = it;
            }
        }
    }

    if (selected == memory.end()) {
        cout << "Allocation failed! Not enough memory.\n";
        return;
    }

    // Split block if needed
    if (selected->size > size) {
        Block newBlock = { -1, selected->size - size, true };
        memory.insert(next(selected), newBlock);
    }

    selected->id = processCounter++;
    selected->size = size;
    selected->isFree = false;

    cout << "Memory allocated successfully.\n";
}

// Memory Deallocation
void deallocate(int pid) {
    for (auto &block : memory) {
        if (!block.isFree && block.id == pid) {
            block.isFree = true;
            block.id = -1;
            cout << "Process " << pid << " deallocated.\n";
            mergeFreeBlocks();
            return;
        }
    }
    cout << "Process not found!\n";
}


int main() {
    int totalMemory;
    cout << "Enter total memory size: ";
    cin >> totalMemory;

    // Initializing memroy
    memory.push_back({ -1, totalMemory, true });

    int choice;
    while (true) {
        cout << "\n1. Allocate\n2. Deallocate\n3. Display\n4. Exit\nChoice: ";
        cin >> choice;

        //Chosing strategy
        if (choice == 1) {
            int size, strategy;
            cout << "Enter process size: ";
            cin >> size;
            cout << "Strategy (1=First Fit, 2=Best Fit, 3=Worst Fit): ";
            cin >> strategy;
            allocate(size, strategy);
        }
        else if (choice == 2) {
            int pid;
            cout << "Enter process id: ";
            cin >> pid;
            deallocate(pid);
        }
        else if (choice == 3) {
            displayMemory();
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
