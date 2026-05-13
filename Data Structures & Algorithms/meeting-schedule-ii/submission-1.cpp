/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        if (intervals.empty()) return 0;
        //sort intervals
        sort(intervals.begin(), intervals.end(), [](const Interval& a, Interval& b){
            return a.start < b.start; 
        });

        //init count of rooms at 1
        vector<int> rooms = {intervals[0].end}; 
        //if conflict, room count++
        for(int i = 1; i<intervals.size(); i++){
            bool roomFound = false;
            for(int j = 0; j < rooms.size(); j++){
                //if the end time of a room is greater than 
                //start time of this interval, there's a conflict
                if(intervals[i].start >= rooms[j]){
                    //if that is the last room, add more room
                    //with the end time of this one
                    //cout << rooms.size() -1 << endl; 
                    roomFound = true;
                    rooms[j] = intervals[i].end;
                    break;
                }
            }
            if(!roomFound) rooms.push_back(intervals[i].end); 
        }

        return rooms.size();
    }
};
