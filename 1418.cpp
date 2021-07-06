class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> ans={{"Table"}};
        set<string> foods;
        set<int> tables;
        vector<string> ftool;
        vector<int> ttool;
        unordered_map<int, unordered_map<string, int>> foodsCnt;
        //问题：一桌一道菜，多道，需要统计
        //字典序排序后，数量发生变化
        //故而排序后需要新的计数

        //想多次处理，发现题解也是这样
        for(int i=0;i<orders.size();i++) {//提取得到菜名和桌号
            ++foodsCnt[stoi(orders[i][1])][orders[i][2]];
            foods.insert(orders[i][2]);
            tables.insert(stoi(orders[i][1]));
        }
        for(auto &it:foods) {//为菜名排字典序
            ftool.push_back(it);
        }
        sort(ftool.begin(),ftool.end());

        for(auto &it:tables) {//为桌号排字典序
            ttool.push_back(it);
        }
        sort(ttool.begin(),ttool.end());
        
        for(int i=0;i<foods.size();i++) {//创建答案第一行
            ans[0].push_back(ftool[i]);
            cout<<ans[0][i+1];
        }
        int m = foodsCnt.size();
        int n = foods.size();
        vector<vector<string>> table(m + 1, vector<string>(n + 1));
        table[0][0] = "Table";
        copy(ftool.begin(), ftool.end(), table[0].begin() + 1);
        for (int i = 0; i < m; ++i) {
            int id = ttool[i];
            auto &cnt = foodsCnt[id];
            table[i + 1][0] = to_string(id);
            for (int j = 0; j < n; ++j) {
                table[i + 1][j + 1] = to_string(cnt[ftool[j]]);
            }
        }


        return table;
    }
};