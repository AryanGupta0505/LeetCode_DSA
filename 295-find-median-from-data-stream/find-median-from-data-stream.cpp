class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median = 0;

    MedianFinder() {}

    int signum(int a, int b){
        if(a == b) return 0;
        else if(a > b) return 1;
        else return -1;
    }

    void callMedian(int element) {
        switch(signum(maxHeap.size(), minHeap.size())) {

            case 0:
                if(element > median){
                    minHeap.push(element);
                    median = minHeap.top();
                } else {
                    maxHeap.push(element);
                    median = maxHeap.top();
                }
                break;

            case 1: // maxHeap bigger
                if(element > median){
                    minHeap.push(element);
                } else {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(element);
                }
                median = (maxHeap.top() + minHeap.top()) / 2.0;
                break;

            case -1: // minHeap bigger
                if(element > median){
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(element);
                } else {
                    maxHeap.push(element);
                }
                median = (maxHeap.top() + minHeap.top()) / 2.0;
                break;
        }
    }

    void addNum(int num) {
        callMedian(num);
    }

    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */