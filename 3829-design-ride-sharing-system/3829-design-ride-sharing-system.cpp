class RideSharingSystem {
public:
    deque<int> rider;
    deque<int> driver;
    unordered_map<int,bool> tracking;
    unordered_map<int,bool> riderTracking;

    RideSharingSystem() {}

    void addRider(int riderId) {
        rider.push_back(riderId);
        riderTracking[riderId] = true;
    }

    void addDriver(int driverId) {
        driver.push_back(driverId);
    }

    vector<int> matchDriverWithRider() {

       
        while (rider.size() > 0 && tracking[rider.front()] == true) {
            tracking[rider.front()] = false;
            rider.pop_front();
        }

        if (rider.size() > 0 && driver.size() > 0) {
            int r = rider.front();
            rider.pop_front();

            int d = driver.front();
            driver.pop_front();

            return {d, r};
        }

        return {-1, -1};
    }

    void cancelRider(int riderId) {
        if (riderTracking[riderId] == true) {
            tracking[riderId] = true;   
        }
    }
};