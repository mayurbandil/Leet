class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> temp;
        temp.push_back(1);
        if(rowIndex == 0){
            rowIndex--;
            return temp;
        }
        temp.push_back(1);
        if(rowIndex == 1){
            rowIndex--;
            return temp;
        }
        while(rowIndex>1){
        int i = 0;
        int j = 1;
        vector<int> temp2;
        temp2.push_back(1);
        while(j!=temp.size()){
            temp2.push_back(temp[i]+temp[j]);
            i++;
            j++;
        }
        temp2.push_back(1);
        temp=temp2;
        rowIndex--;
        } 
        return temp;
    }
};