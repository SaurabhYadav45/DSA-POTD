// class Solution {
// public:
//     int mostBooked(int n, vector<vector<int>>& meetings) {
//         sort(meetings.begin(), meetings.end());
//         vector<long long>roomAvailableAt(n, 0);
//         vector<int>roomUsedCount(n, 0);
        
//         for(auto& meet: meetings){
//             int start = meet[0];
//             int end = meet[1];
//             int duration = end - start;

//             long long earlyEndRoomTime = LLONG_MAX;
//             int earlyEndRoom = 0;
//             bool found = false;
//             for(int room=0; room < n; room++){
//                 if(roomAvailableAt[room] <= start){
//                     roomAvailableAt[room] = end;
//                     roomUsedCount[room]++;
//                     found = true;
//                     break;
//                 }

//                 if(roomAvailableAt[room] < earlyEndRoomTime){
//                     earlyEndRoomTime = roomAvailableAt[room];
//                     earlyEndRoom = room;
//                 }
//             }
//             if(!found){
//                 long long newEndTime = earlyEndRoomTime + duration;
//                 roomAvailableAt[earlyEndRoom] = newEndTime;
//                 roomUsedCount[earlyEndRoom]++;
//             }
//         }

//         int maxCount = 0;
//         int resultRoom = -1;
//         for(int room =0; room<n; room++){
//             if(roomUsedCount[room] > maxCount){
//                 maxCount = roomUsedCount[room];
//                 resultRoom = room;
//             }
//         }
//         return resultRoom;
//     }
// };



//           *************** Optimal (Min Heap) ***************

class Solution {
public:
    typedef pair<long long, int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long>roomUsedCount(n, 0);
        priority_queue<P, vector<P>, greater<P>>roomUsed;
        priority_queue<int, vector<int>, greater<int>>availableRoom;

        for(int room=0; room<n; room++){
            availableRoom.push(room);
        }
        
        for(vector<int>& meet: meetings){
            int start = meet[0];
            int end = meet[1];
            long long duration = end-start;
            
            while(!roomUsed.empty() && roomUsed.top().first <= start){
                availableRoom.push(roomUsed.top().second);
                roomUsed.pop();
            }
            if(!availableRoom.empty()){
                int room = availableRoom.top();
                availableRoom.pop();
                roomUsed.push({end, room});
                roomUsedCount[room]++;
            }
            else{
                // room is not available, pick the smallest end time
                int room = roomUsed.top().second;
                long long endTime = roomUsed.top().first;
                roomUsed.pop();
                roomUsed.push({endTime + duration, room});
                roomUsedCount[room]++;
            }
        }
        int maxCount = -1;
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