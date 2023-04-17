## 例程功能解释
### 继承
#### 原则
1. 首先说明一点：类实例（即类对象）不能直接访问类的 private成员和protected成员，但是能直接访问类的public成员。

2. 另外无论哪种继承方式，子类都不能直接访问父类的 private成员；但是能直接访问父类的 protected成员和public成员（注意：是子类，而不是类实例），并且能通过父类的protected成员函数和public成员函数间接访问父类的private成员；这句话强调了类与类之间通过继承方式的访问规则，而非类与实例之间的访问规则。

3. 子类通过public方式继承父类，则父类中的public、protected和private属性的成员在 子类 中 依次 是 public、protected和private属性，即通过public继承并不会改变父类原来的数据属性。

4. 子类通过protected方式继承父类，则父类中的public、protected和private属性的成员在 子类 中 依次 是 protected、protected和private属性，即通过protected继承原来父类中public属性降级为子类中的protected属性，其余父类属性在子类中不变。

5. 子类通过private方式继承父类，则父类中的public、protected和private属性的成员在 子类 中 依次 是 private、private和private属性，即通过private继承原来父类中public属性降级为子类中的private属性，protected属性降级为子类中的private属性，其余父类属性在子类中不变。
#### 父类指针访问子类

1. 可以通俗的理解，子类可能含有一些父类没有的成员变量或者方法函数，但是子类肯定继承了父类所有的成员变量和方法函数。所以用父类指针指向子类时，没有问题，因为父类有的，子类都有，不会出现非法访问问题。但是如果用子类指针指向父类的话，一旦访问子类特有的方法函数或者成员变量，就会出现非法。

#### 例子
inherit6：子类向父类传参数
inherit7：父类指针指向子类实例对象


### 类
#### 传参
Class_Object_as_func_para：对象作为函数参数传递
#### 自定义类的对象 做函数参数为什么一定要用 引用传值？
1. 函数参数有直接变量(如int、char、double等)类型、指针类型和引用类型。
2. 如果参数是变量，传递方式是传值，就是将实参的值复制(复制，意味着空间消耗和时间消耗)到“栈”空间中。
3. 如果参数是指针，传递方式是传址，需将指针复制(同样也消耗空间和时间，对于数组而言，只需存储数组首地址)到“栈”空间中。
4. 如果是引用，则既不是传值，也不是传址，主调函数和被调函数共享参数的存放地址，与全局变量共享方式相同。
5. 对于拷贝(复制)构造函数而言，类对象通常需要较多的存储空间，如果按值传递，必然会较大消耗“栈”空间，也需要较多的时间实施复制过程。因为复制构造函数不会修改参数的内容，也不会修改参数的属性，所以构造函数的参数应该是常量引用传递，如 ClassName(const ClassName &obj)
6. 如果参数是类对象，就是值传递，就要复制，复制就要调拷贝构造函数。这就形成了拷贝构造函数再调拷贝构造函数，无限递归下去。因此只能用引用的方法
7. 有时，一些函数（包括拷贝构造函数）参数要求用（不是必须用）常引用，目的是为了避免函数体中无意地修改指针所指对象的值

### Eigen
#### Drived
eigen_test1:  Eigen库类类型作为函数参数