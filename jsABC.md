## 从零开始用javascript刷题，需要学习什么：

### 语法

#### void函数的声明的写法：

function connectStep (left,right) 

### 高级数据结构 容器

#### 优先队列

<https://github.com/datastructures-js/priority-queue#enqueue>

#### map

const count = new Map();  

map.set(a,key)  

map.get()

### 数学运算 string转换等

##### Math.floor()

下取整    

##### pow(num, 0.5)

开平方根     

##### float.is_integer(num) or num.is_integer()

判断是不是整数   

##### str.isdigit()

判断字符串是不是全由数字组成

##### ~~运算符 

将一些变量转化为Number（数字）类型的  在此的作用为： 对 x 进行取整，只取整数部分

7.整数反转

##### Number.MAX_VALUE

-1*Number.MAX_VALUE 来表示极小的负数

### 复合数据结构（js自带

#### Array

数组删除nums[0]的元素  Array.shift()

### 语法糖和新用法

### 未解之谜

while(p.right!=null) {//这句话写成while(!p.right) 会运行不了，说不能读一个Nullptr的right

​        p=p.right;

​    }





