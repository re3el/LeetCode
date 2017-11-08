class Solution {
public:
    bool judgeCircle(string moves) 
    {
        int cntV = 0, cntH = 0;
        for(int i=0; i<moves.length(); i++)
        {
            if(moves[i] == 'D') cntV++;
            else if(moves[i] == 'U') cntV--;
            else if(moves[i] == 'L') cntH++;
            else if(moves[i] == 'R') cntH--;
        }
        
        return (cntV+cntH == 0) ? true : false;
    }
};