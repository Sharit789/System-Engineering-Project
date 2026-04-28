# System Engineering Project
🧠 Memory Allocation Simulator (C++)

This project is a simple Memory Management Simulator written in C++. It demonstrates how different memory allocation strategies work in Operating Systems.

🚀 Features
Simulates dynamic memory allocation
Supports three allocation strategies:
✅ First Fit
✅ Best Fit
✅ Worst Fit
Memory deallocation by process ID
Automatic merging of adjacent free blocks
Real-time memory state visualization
🏗️ How It Works
Memory is represented using a list of blocks.
Each block contains:
Process ID
Block size
Free/Allocated status
When allocating:
The program selects a suitable block based on the chosen strategy
Splits the block if necessary
When deallocating:
Marks the block as free
Merges adjacent free blocks to reduce fragmentation

📋 Menu Options
1. Allocate Memory
2. Deallocate Memory
3. Display Memory
4. Exit

⚙️ Allocation Strategies
🔹 First Fit

Allocates the first block that is large enough.

🔹 Best Fit

Allocates the smallest block that fits the process (minimizes wasted space).

🔹 Worst Fit

Allocates the largest available block (leaves larger remaining blocks).

🖥️ Sample Output
Enter total memory size: 1000

1. Allocate
2. Deallocate
3. Display
4. Exit

Memory State:
[Free: 1000]

Allocate 200 (First Fit)

Memory State:
[P1: 200] [Free: 800]


🛠️ Technologies Used
C++
Standard Template Library (STL)
list


📚 Concepts Covered
Memory Management
Fragmentation
Dynamic Allocation
Data Structures (Linked List via STL)
📌 Future Improvements
Add GUI visualization
Support paging and segmentation
Add statistics (fragmentation %, usage)
File input/output support
🤝 Contributing

Contributions are welcome! Feel free to fork the repo and submit a pull request.

📄 License

This project is open-source and available under the MIT License.
