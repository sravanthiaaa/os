#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >>n;

    int arr[n];

    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }

    int pages;
    cin >>pages;
    int ans[pages];
    for(int i = 0 ; i < pages ; i ++) ans[i] = -1;
    int rear = 0,front = 0;
    int ct = 0;
    int pagehit = 0;
    int pagefault = 0;
    for(int i = 0 ; i < n ; i ++)
    {
        int f = 0;
        for(int j = 0 ; j < rear ; j ++) 
        {
            if(ans[j] == arr[i])
            {
                ct ++;
                f = 1;
                break;
            }
        }
        if(f == 1)
        {
            pagehit ++;
        }
        else if(front == rear)
        {
            ans[rear] = arr[i];
            rear ++;
            pagefault ++;
        }
        else if(rear < pages)
        {
            ans[rear] = arr[i];
            rear ++;
            pagefault ++;
        }
        else
        {
            ans[front] = arr[i];
            front ++;
            pagefault ++;
            if(front >= pages)
            {
                front = 0;
            }
        }
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    }    

    cout<<"PageHit :" <<pagehit<<"PageFault :"<<pagefault;

}



// #include <iostream>
// #include <queue>
// #include <unordered_set>

// using namespace std;

// void fifoPageReplacement(int pages[], int n, int capacity) {
//     queue<int> pageQueue;
//     unordered_set<int> pageSet; // To check if a page is in memory

//     int pageFaults = 0;

//     for (int i = 0; i < n; ++i) {
//         if (pageSet.find(pages[i]) == pageSet.end()) {
//             // Page fault: Page is not in memory
//             ++pageFaults;

//             if (pageQueue.size() == capacity) {
//                 // Remove the oldest page
//                 int oldestPage = pageQueue.front();
//                 pageQueue.pop();
//                 pageSet.erase(oldestPage);
//             }

//             // Add the new page to memory
//             pageQueue.push(pages[i]);
//             pageSet.insert(pages[i]);
//         }

//         // Display the current state of memory
//         cout << "Memory state after accessing page " << pages[i] << ": ";
//         queue<int> tempQueue = pageQueue;
//         while (!tempQueue.empty()) {
//             cout << tempQueue.front() << " ";
//             tempQueue.pop();
//         }
//         cout << endl;
//     }

//     cout << "Total Page Faults: " << pageFaults << endl;
// }

// int main() {
//     int n;
//     cout << "Enter the number of pages: ";
//     cin >> n;

//     int pages[n];
//     cout << "Enter the sequence of pages: ";
//     for (int i = 0; i < n; ++i) {
//         cin >> pages[i];
//     }

//     int capacity;
//     cout << "Enter the capacity of the memory: ";
//     cin >> capacity;

//     fifoPageReplacement(pages, n, capacity);

//     return 0;
// }
