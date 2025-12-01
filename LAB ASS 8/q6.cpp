#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int idx) {
        if (!idx) return;
        int parent = (idx - 1) / 2;
        if (heap[parent] < heap[idx]) {
            swap(heap[parent], heap[idx]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int idx) {
        int left = 2 * idx + 1, right = 2 * idx + 2, largest = idx;
        if (left < heap.size() && heap[left] > heap[largest]) largest = left;
        if (right < heap.size() && heap[right] > heap[largest]) largest = right;
        if (largest != idx) {
            swap(heap[largest], heap[idx]);
            heapifyDown(largest);
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        if (heap.empty()) throw runtime_error("Empty");
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    PriorityQueue pq;
    pq.push(10);
    pq.push(4);
    pq.push(15);
    pq.push(7);
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    return 0;
}
