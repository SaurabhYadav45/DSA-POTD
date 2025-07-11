class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long>roomAvailableAt(n, 0);
        vector<int>roomUsedCount(n, 0);
        
        for(auto& meet: meetings){
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;

            long long earlyEndRoomTime = LLONG_MAX;
            int earlyEndRoom = 0;
            bool found = false;
            for(int room=0; room < n; room++){
                if(roomAvailableAt[room] <= start){
                    roomAvailableAt[room] = end;
                    roomUsedCount[room]++;
                    found = true;
                    break;
                }

                if(roomAvailableAt[room] < earlyEndRoomTime){
                    earlyEndRoomTime = roomAvailableAt[room];
                    earlyEndRoom = room;
                }
            }
            if(!found){
                long long newEndTime = earlyEndRoomTime + duration;
                roomAvailableAt[earlyEndRoom] = newEndTime;
                roomUsedCount[earlyEndRoom]++;
            }
        }

        int maxCount = 0;
        int resultRoom = -1;
        for(int room =0; room<n; room++){
            if(roomUsedCount[room] > maxCount){
                maxCount = roomUsedCount[room];
                resultRoom = room;
            }
        }
        return resultRoom;
    }
};