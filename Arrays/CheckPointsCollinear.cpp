float slope(vector<int> c1, vector<int> c2){
    if(c1[0] - c2[0] == 0){
        return M_PI/2;
    }
    return float(c1[1] - c2[1])/float(c1[0] - c2[0]);
}
class Solution {
public:
    
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // float slope = slope(coordinated[0], coordinate[1]);
        for(int i=2; i<coordinates.size(); i++){
            if(slope(coordinates[i], coordinates[i-1]) != slope(coordinates[i-1], coordinates[i-2])){
                return false;
            }
        }
        return true;
    }
};