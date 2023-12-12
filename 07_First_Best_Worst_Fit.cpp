#include <iostream>
using namespace std; 

void firstFit(int blockSize[], int m, int processSize[], int n) { 
	// Stores block id of the 
	// block allocated to a process 
	int allocation[n];

    // To initialize all elements of allocation to -1
    for (int i = 0; i < n; i++)  allocation[i] = -1; 

	// pick each process and find suitable blocks 
	// according to its size ad assign to it 
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) { 
			if (blockSize[j] >= processSize[i]) { 
				// allocate block j to p[i] process 
				allocation[i] = j; 

				// Reduce available memory in this block. 
				blockSize[j] -= processSize[i]; 

				break; 
			} 
		} 
	} 

	cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
	for (int i = 0; i < n; i++) { 
		cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t"; 
		if (allocation[i] != -1) cout << allocation[i] + 1; 
		else cout << "Not Allocated"; 
		cout << endl; 
	} 
}

void bestFit(int blockSize[], int m, int processSize[], int n)  {  
    // Stores block id of the block allocated to a process  
    int allocation[n];  
  
    // Initially no block is assigned to any process  
    for (int i = 0; i < n; i++)  allocation[i] = -1;  
  
    // pick each process and find suitable blocks  
    // according to its size ad assign to it  
    for (int i = 0; i < n; i++) {  
        // Find the best fit block for current process  
        int bestIdx = -1;  
        for (int j = 0; j < m; j++)  {  
            if (blockSize[j] >= processSize[i])  {  
                if (bestIdx == -1)  bestIdx = j;  
                else if (blockSize[bestIdx] > blockSize[j])  bestIdx = j;  
            }  
        }  
  
        // If we could find a block for current process  
        if (bestIdx != -1)  {  
            // allocate block j to p[i] process  
            allocation[i] = bestIdx;  
  
            // Reduce available memory in this block.  
            blockSize[bestIdx] -= processSize[i];  
        }  
    }  
  
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";  
    for (int i = 0; i < n; i++)  {  
        cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";  
        if (allocation[i] != -1)  cout << allocation[i] + 1;  
        else cout << "Not Allocated";  
        cout << endl;  
    }  
}

void worstFit(int blockSize[], int m, int processSize[], int n) { 
    // Stores block id of the block allocated to a 
    // process 
    int allocation[n]; 
  
    // Initially no block is assigned to any process 
    for (int i = 0; i < n; i++)  allocation[i] = -1; 
  
    // pick each process and find suitable blocks 
    // according to its size ad assign to it 
    for (int i=0; i<n; i++) { 
        // Find the best fit block for current process 
        int wstIdx = -1; 
        for (int j=0; j<m; j++) { 
            if (blockSize[j] >= processSize[i]) { 
                if (wstIdx == -1) wstIdx = j; 
                else if (blockSize[wstIdx] < blockSize[j]) wstIdx = j; 
            } 
        } 
  
        // If we could find a block for current process 
        if (wstIdx != -1) { 
            // allocate block j to p[i] process 
            allocation[i] = wstIdx; 
  
            // Reduce available memory in this block. 
            blockSize[wstIdx] -= processSize[i]; 
        } 
    } 
  
    cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
    for (int i = 0; i < n; i++) { 
        cout << "   " << i+1 << "\t\t" << processSize[i] << "\t\t"; 
        if (allocation[i] != -1) cout << allocation[i] + 1; 
        else cout << "Not Allocated"; 
        cout << endl; 
    } 
}

int main() { 
	int blockSize[] = {100, 500, 200, 300, 600}; 
	int processSize[] = {212, 417, 112, 426}; 
	int m = sizeof(blockSize) / sizeof(blockSize[0]); 
	int n = sizeof(processSize) / sizeof(processSize[0]); 

    int choice;
    cout << "Press 1 for First Fit\nPress 2 for Best Fit\nPress 3 for Worst Fit\nPress Anything else to exit" << endl;
    cin >> choice;
    switch(choice) {
        case 1:
            cout << "\nMemory Allocation according to First Fit" << endl;
	        firstFit(blockSize, m, processSize, n);
            break;

        case 2:
            cout << "\nMemory Allocation according to Best Fit" << endl;
            bestFit(blockSize, m, processSize, n);
            break;

        case 3:
            cout << "\nMemory Allocation according to Worst Fit" << endl;
            worstFit(blockSize, m, processSize, n);
            break;
    }

	return 0 ; 
} 