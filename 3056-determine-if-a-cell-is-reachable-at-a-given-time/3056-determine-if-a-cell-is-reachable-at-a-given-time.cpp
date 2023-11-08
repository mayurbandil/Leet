class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diffx = abs(fx-sx);
        int diffy = abs(fy-sy);
        int Ddis = max(diffx, diffy);
        if(Ddis>t || (diffx == 0 && diffy == 0 && t==1)){
            return false;
        }
        return true;
        
    }
};