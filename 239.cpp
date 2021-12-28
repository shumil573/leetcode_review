//待办：解决
//函数名（形参列表）: gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)) {函数体}
//的实际含义

//mt19937 & uniform_int_distribution<int>的联合使用


class Solution {
private:
    mt19937 gen;
    uniform_int_distribution<int> dis;
    vector<int> pre;
public:
    Solution(vector<int>& w): gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)) {//0表示累加的初值为0，即为w求和
        partial_sum(w.begin(), w.end(), back_inserter(pre));//partial_sum的结果给了back_inserter(pre)，使得pre{不断}插入w的子串和
        for(auto it:pre) cout<<it<<" ";
        cout<<endl<<"---------------"<<endl;
    }
    int pickIndex() {
        int x = dis(gen);
        return lower_bound(pre.begin(), pre.end(), x) - pre.begin();
    }
};

/**
    mt19937头文件是<random> 是伪随机数产生器，用于产生高性能的随机数
    uniform_int_distribution 头文件在<random>中，是一个随机数分布类，参数为生成随机数的类型，构造函数接受两个值表示区间段
    accumulate 头文件在<numeric>中，求特定范围内所有元素的和。
    spartial_sum函数的头文件在<numeric>，对(first, last)内的元素逐个求累计和，放在result容器内
    back_inserter函数头文件<iterator>，用于在末尾插入元素。
    lower_bound头文件在<algorithm>，用于找出范围内不大于num的第一个元素

    贺补充：lower_bound处理有序数据，在pre.begin(), pre.end()区间内找到第一个{不小于x}的值

 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */