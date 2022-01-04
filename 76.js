// /**
//  * @param {string} s
//  * @param {string} t
//  * @return {string}
//  */
// var minWindow = function(s, t) {
//     var need=new Map();
//     var window=new Map();
//     var left=0,right=0,start=0,len=Number.MAX_VALUE;
//     var valid=0;
//     var allneed=0;
//     for(var it of t) {
//         if(need.has(it)) need.set(it,need.get(it)+1);
//         else need.set(it,1);
//         allneed++;
//     }
//     console.log(need);
//     while(right<s.length) {
//         console.log(left,right,"valid:",valid);
//         console.log(s.slice(left,right),':',s.slice(start,start+len));
//         var ch=s[right];
//         right++;
//         if(need.has(ch)) {
//             if(window.has(ch)) window.set(ch,window.get(ch)+1);
//             else window.set(ch,1);
//             if(window.get(ch)==need.get(ch)) {
//                 valid++;
//             }
//         }
//         console.log(left,right,"valid:",valid);

//         //while(valid==need.length) {//存疑，不知道Js能不能这么写
//         while(valid==allneed) {//allneed
//             console.log('答案削减中：',s.slice(start,start+len));
//             if(right-left<len) {
//                 start=left;
//                 len=right-left;
//             }
//             var d=s[left];
//             left++;
//             if(need.has(d)) {
//                 if(window.get(d)==need.get(d)) {
//                     valid--;
//                 }
//                 window.set(d,window.get(d)-1);
//             }
//         }

//     }
//     return len==Number.MAX_VALUE?"":s.slice(start,start+len);
// };


var minWindow = function (s, t) {
    let need = {};//需要覆盖的字符串频数
    let window = {};//滑动窗口的字符串频数
    for (let a of t) {
        need[a] = (need[a] || 0) + 1;//统计t中字符频数
    }
    //左右指针
    let left = 0,
        right = 0;
    let valid = 0;//滑动窗口中能覆盖的字符种类数
    let start = 0,//最小覆盖子串的起始索
        len = Number.MAX_VALUE;//最小覆盖子串长度
    while (right < s.length) {
        let c = s[right];//进入滑动窗口右边的字符
        right++;//右移窗口
        if (need[c]) {//如果当前字符在need字符中 更新window中字符数
            window[c] = (window[c] || 0) + 1;
            if (window[c] == need[c]) {//如果当前窗口和需要的字符数量一致时，字符种类+1
                valid++;
            }
        }

        while (valid == Object.keys(need).length) {//字符种类与需要的字符个数一致时，就收缩窗口
            if (right - left < len) {//当前窗口长度小于之前窗口的长度len 更新最小覆盖子串的起始位置和长度
                start = left;
                len = right - left;
            }
            let d = s[left];//需要被移除的字符
            left++;//左移窗口 从窗口中移除字符
            if (need[d]) {//如果在需要的字符中 更新window中字符数
                if (window[d] == need[d]) {//如果当前窗口和需要的字符数量一致时，字符种类-1
                    valid--;
                }
                window[d]--;
            }
        }
    }
    //没有找到覆盖子串 返回'' 否则返回覆盖子串
    return len == Number.MAX_VALUE ? "" : s.substr(start, len);
};


// 作者：chen-wei-f
// 链接：https://leetcode-cn.com/problems/minimum-window-substring/solution/76-zui-xiao-fu-gai-zi-chuan-hua-dong-chu-dvlt/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。