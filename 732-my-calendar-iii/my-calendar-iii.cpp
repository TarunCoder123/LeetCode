class MyCalendarThree {
public:
    map<int, int> events;

    MyCalendarThree() {}

    int book(int start, int end) {
        events[start]++;
        events[end]--;

        int active = 0;
        int maxOverlap = 0;

        for (auto &[time, delta] : events) {
            active += delta;
            maxOverlap = max(maxOverlap, active);
        }
        return maxOverlap;
    }
};
