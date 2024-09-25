#include <bits/stdc++.h>
using namespace std;
string Account_teacher;
string Account_student;
int Initial()
{
    cout<<"------------------------------\n";
    cout<<"|  欢迎使用班级管理系统2.0!  |\n";
    cout<<"------------------------------\n";
    cout<<"|可选择以下三种身份:         |\n";
    cout<<"|                            |\n";
    cout<<"|          1.管理员          |\n";
    cout<<"|          2.老师            |\n";
    cout<<"|          3.学生            |\n";
    cout<<"|                            |\n";
    cout<<"------------------------------\n";
    cout<<"|->请输入代号数字选择身份:";
    int a;
    cin>>a;
    system("cls");
    return a;
}//初始化
//账号类
class Identity_verification{
public:
    bool Read_Account_manager()
    {
        string a;
        cout<<"|->请输入账号:";
        cin>>a;
        Account=a;
        cout<<"|->请输入密码:";
        cin>>a;
        password=a;
        ifstream ifs("E:\\综合管理系统 vs2.0\\account_manager.txt",ios::in);
        if(!ifs)cout<<"打开文件失败!\n";
        while(!ifs.eof()){
            string ac,pa;
            ifs>>ac>>pa;
            if(ac==Account&&pa==password)return true;
        }
        ifs.close();
        return false;
    }//读取管理员账号数据
    bool Read_Account_teacher()
    {
        string a;
        cout<<"|->请输入账号:";
        cin>>a;
        Account=a;
        Account_teacher=a;
        cout<<"|->请输入密码:";
        cin>>a;
        password=a;
        ifstream ifs("E:\\综合管理系统 vs2.0\\account_teacher.txt",ios::in);
        if(!ifs)cout<<"打开文件失败!\n";
        while(!ifs.eof()){
            string ac,pa;
            ifs>>ac>>pa;
            if(ac==Account&&pa==password)return true;
        }
        ifs.close();
        return false;
    }//读取老师账号数据
    bool Read_Account_Student()
    {
        string a;
        cout<<"|->请输入账号:";
        cin>>a;
        Account=a;Account_student=a;
        cout<<"|->请输入密码:";
        cin>>a;
        password=a;
        ifstream ifs("E:\\综合管理系统 vs2.0\\account_student.txt",ios::in);
        if(!ifs)cout<<"打开文件失败!\n";
        while(!ifs.eof()){
            string ac,pa;
            ifs>>ac>>pa;
            if(ac==Account&&pa==password)return true;
        }
        ifs.close();
        return false;
    }//读取学生账号数据
    void enroll_manager()
    {
        ofstream of("E:\\综合管理系统 vs2.0\\account_manager.txt",ios::app);
        if(!of)cout<<"打开文件失败!\n";
        string a,b;
        cout<<"|->请输入账号:";cin>>a;
        cout<<"|->请输入密码:";cin>>b;
        of<<a<<" "<<b<<" \n";
        of.close();
    }//保存管理员注册账号数据
    void enroll_teacher()
    {
        ofstream of("E:\\综合管理系统 vs2.0\\account_teacher.txt",ios::app);
        if(!of)cout<<"打开文件失败!\n";
        string a,b;
        cout<<"|->请输入账号:";cin>>a;Account_teacher=a;
        cout<<"|->请输入密码:";cin>>b;
        of<<a<<" "<<b<<"\n";
        of.close();
    }//保存老师注册账号数据
    void enroll_student()
    {
        ofstream of("E:\\综合管理系统 vs2.0\\account_student.txt",ios::app);
        if(!of)cout<<"打开文件失败!\n";
        string a,b;
        cout<<"|->请输入账号:";cin>>a;Account_student=a;
        cout<<"|->请输入密码:";cin>>b;
        of<<a<<" "<<b<<"\n";
        of.close();
    }//保存学生注册账号数据
private:
    string Account,password;
};//账号核验
struct Course{
    string name;
};
struct student{
    string account;
    string name;
    string sex;
    int age;
    string Class;
};
struct teacher{
    string account;
    string name;
    string sex;
    long long tele_num;
    string Class;
};
class Classroom{
public:
    string name;
    Course course;
    string teacher;
    string students[100];
    int students_num;
    void Creat_a_classroom()
    {
        cout<<"|->请输入班级名称:";
        string a;
        cin>>a;
        cout<<"|->输入课程名称:";
        name=a;
        cin>>course.name;
    }
    void Display_classroom()
    {
        cout<<"-------------------------------------------------------------------------------------\n";
        cout<<"班级名称为: "<<name<<"     ";
        cout<<"相关课程: "<<course.name<<"      ";
        if(teacher.empty())cout<<"无老师授课    ";
        else cout<<teacher<<"老师授课   ";
        cout<<"班级人数为:"<<students_num<<endl;
        cout<<"-------------------------------------------------------------------------------------\n";
    }
};
class manager{
public:
    Classroom classroom[100];
    teacher te[100];
    student stu[100];
    int classroom_num;
    int teacher_num;
    int student_num;
    manager()//文件日志：问题出现在这里
    {
        Read_Student();
        Read_Teacher();
        Read_class();//读取班级信息
        Read_class_student();//读取班级与学生关系信息
    }
    void Creat_classroom()
    {
        Classroom c;
        c.Creat_a_classroom();
        cout<<"------------------------------\n";
        cout<<"|          创建成功！        |\n";
        cout<<"------------------------------\n";
        classroom[classroom_num]=c;
        classroom[classroom_num++].students_num=0;
        write_class();
        write_class_student();
        Read_class_student();
    }
    void Display_class_message()
    {
        for(int i=0;i<classroom_num;i++)
        {
            classroom[i].Display_classroom();
        }
    }
    void Read_class()
    {
        ifstream ifs("E:\\综合管理系统 vs2.0\\class_message.txt",ios::in);
        if(!ifs)cout<<"打开文件失败!\n";
//        while(!ifs.eof()){
//            Course c;
//            ifs>>classroom[classroom_num].name>>c.name;
//            classroom[classroom_num].course=c;
//            if(ifs.fail())break;
//            classroom_num++;
//        }
//此种方法读取到的只能是每行固定的数据数量不太实用
//而下面这种方法读取到的每行数据数量不限，比较实用
        string op;int num;//用来记录每一行读取多少个数据
        classroom_num=0;
        while(getline(ifs,op)){
            num=0;string b="";
            classroom[classroom_num].students_num=0;
            for(int i=0;i<op.size();i++){
                if(op[i]!=' ')b+=op[i];
                else
                {
                    //cout<<"读取到的b为: "<<b<<endl;
                    num++;
                    if(num==1)classroom[classroom_num].name=b;
                    if(num==2)
                    {
                        Course c;
                        c.name=b;
                        classroom[classroom_num].course=c;
                    }
                    if(num==3)
                    {
                        classroom[classroom_num].teacher=b;
                        for(int j=0;j<teacher_num;j++)
                            if(te[j].name==classroom[classroom_num].teacher)
                            {
                                te[j].Class=classroom[classroom_num].course.name;
                            }
                    }
                    b="";
                }
            }
            classroom_num++;
        }
        ifs.close();
    }
    void write_class()
    {
        ofstream of("E:\\综合管理系统 vs2.0\\class_message.txt",ios::out);
        if(!of)cout<<"打开文件失败!\n";
        for(int i=0;i<classroom_num;i++)
        {
            of<<classroom[i].name<<" "<<classroom[i].course.name<<" ";
            if(!classroom[i].teacher.empty())of<<classroom[i].teacher;
            of<<" \n";//加空格是为了方便读取整个单词防止数据遗忘
        }
        of.close();
    }
    void Invite_teacher()
    {
        cout<<"------------------------------------------------------------\n";
        cout<<"以下是所有老师名单和班级名单: \n";
        cout<<"老师: ";for(int i=0;i<teacher_num;i++)cout<<te[i].name<<"   ";cout<<endl;
        cout<<"班级: ";for(int i=0;i<classroom_num;i++)cout<<classroom[i].name<<"   ";cout<<endl;
        cout<<"------------------------------------------------------------\n";
        cout<<"|->请输入老师姓名:";
        string a,b;
        cin>>a;
        cout<<"|->班级名称:";
        cin>>b;
        bool one=false,two=false;
        int i,j;
        for(i=0;i<classroom_num;i++)
            if(classroom[i].name==b)
            {
                two=true;
                break;
            }
        for(j=0;j<teacher_num;j++)
            if(te[j].name==a)
            {
                one=true;
                break;
            }
        if(one&&two&&classroom[i].teacher.empty()&&te[j].Class.empty())
        {
            classroom[i].teacher=te[j].name;
            write_class();
            te[j].Class=classroom[i].name;
            cout<<"------------------------------\n";
            cout<<"|      老师成功加入班级!     |\n";
            cout<<"------------------------------\n";
        }
        else if(!one||!two)
        {
            cout<<"------------------------------\n";
            cout<<"|不存在老师或班级，加入失败! |\n";
            cout<<"------------------------------\n";
        }
        else if(!classroom[i].teacher.empty())
        {
            cout<<"----------------------------------\n";
            cout<<"|该班级已经存在授课老师,加入失败!|\n";
            cout<<"----------------------------------\n";
        }
        else if(!te[j].Class.empty())
        {
            cout<<"------------------------------\n";
            cout<<"|该老师已有教学任务,加入失败!|\n";
            cout<<"------------------------------\n";
        }
    }
    void Read_Teacher()
    {
        ifstream ifs("E:\\综合管理系统 vs2.0\\teacher.txt",ios::in);
        if(!ifs)cout<<"打开文件失败!\n";
        teacher_num=0;
        while(!ifs.eof()){
            ifs>>te[teacher_num].account>>te[teacher_num].name>>te[teacher_num].sex>>te[teacher_num].tele_num;
            if(ifs.fail())break;
            teacher_num++;
        }
        ifs.close();
    }
    void write_Teacher()
    {
        ofstream of("E:\\综合管理系统 vs2.0\\teacher.txt",ios::out);
        if(!of)cout<<"打开文件失败!\n";
        for(int i=0;i<teacher_num;i++)of<<te[i].account<<" "<<te[i].name<<" "<<te[i].sex<<" "<<te[i].tele_num<<"\n";
        of.close();
    }
    void Read_Student()
    {
        ifstream ifs("E:\\综合管理系统 vs2.0\\student.txt",ios::in);
        if(!ifs)cout<<"打开文件失败!\n";
        student_num=0;
        while(!ifs.eof()){
            ifs>>stu[student_num].account>>stu[student_num].name>>stu[student_num].sex>>stu[student_num].age;
            if(ifs.fail())break;
            student_num++;
        }
        ifs.close();
    }
    void write_Student()
    {
        ofstream of("E:\\综合管理系统 vs2.0\\student.txt",ios::out);
        if(!of)cout<<"打开文件失败!\n";
        for(int i=0;i<student_num;i++)
            of<<stu[i].account<<" "<<stu[i].name<<" "<<stu[i].sex<<" "<<stu[i].age<<"\n";
        of.close();
    }
    void Display_all_teacher()
    {
        cout<<"------------------------------------------------------------------------------\n";
        for(int i=0;i<teacher_num;i++)
        {
            cout<<"姓名: "<<te[i].name<<"     性别: "<<te[i].sex<<"     电话号码: "<<te[i].tele_num;
            if(!te[i].Class.empty())cout<<"     授课班级: "<<te[i].Class;
            else cout<<"    暂时没有授课任务";
        }
        cout<<"\n------------------------------------------------------------------------------\n";
    }
    void Display_all_student()
    {
        cout<<"------------------------------------------------------------------------------\n";
        for(int i=0;i<student_num;i++)
        {
            cout<<"姓名: "<<stu[i].name<<"     性别: "<<stu[i].sex<<"     年龄: "<<stu[i].age<<"     加入课程:"<<stu[i].Class;
            cout<<endl;
        }
        cout<<"------------------------------------------------------------------------------\n";
    }
    void Delete_class()
    {
        cout<<"|->请输入被删除班级名称: ";
        string a;
        cin>>a;
        int pos;
        for(pos=0;pos<classroom_num;pos++)if(classroom[pos].name==a)break;
        if(pos==classroom_num)
        {
            cout<<"--------------\n";
            cout<<"|不存在该班级|\n";
            cout<<"--------------\n";
            return;
        }
        if(!classroom[pos].teacher.empty())
        {
            cout<<"----------------------------------------------------\n";
            cout<<"|检测到该班级含有授课老师......即将删除老师授课信息|\n";
            cout<<"----------------------------------------------------\n";
            for(int i=0;i<teacher_num;i++)
            {
                if(te[i].name==classroom[pos].teacher)te[i].Class="";
                break;
            }
            write_Teacher();
        }
        for(int i=pos;i<=classroom_num;i++)classroom[i]=classroom[i+1];
        classroom_num--;
        cout<<"------------------------------\n";
        cout<<"|          删除成功！        |\n";
        cout<<"------------------------------\n";
        write_class();
        write_class_student();
    }
    void Delete_Teacher()
    {
        cout<<"|->请输入被删除老师姓名: ";
        string a;
        cin>>a;
        int pos;
        for(pos=0;pos<teacher_num;pos++)if(te[pos].name==a)break;
        if(pos==teacher_num)
        {
            cout<<"--------------\n";
            cout<<"|不存在该老师|\n";
            cout<<"--------------\n";
            return;
        }
        if(!te[pos].Class.empty())
        {
            cout<<"-----------------------------------------\n";
            cout<<"|检测到该老师有授课任务，即将解除.......|\n";
            cout<<"-----------------------------------------\n";
            for(int i=0;i<classroom_num;i++)
                if(te[pos].Class==classroom[i].course.name)
                {
                    //cout<<"老师姓名:"<<classroom[i].teacher<<endl;
                    classroom[i].teacher="";
                    break;
                }
            write_class();
        }
        for(int i=pos;i<teacher_num;i++)te[i]=te[i+1];
        teacher_num--;
        cout<<"------------------------------\n";
        cout<<"|          删除成功！        |\n";
        cout<<"------------------------------\n";
        write_Teacher();
    }
    void Read_class_student()
    {
        ifstream ifs("E:\\综合管理系统 vs2.0\\class_student.txt",ios::in);
        if(!ifs)cout<<"打开文件失败!\n";
        for(int i=0;i<classroom_num;i++){
            string class_num;int studentss_num;
            ifs>>class_num>>studentss_num;
            //cout<<"class_num: "<<class_num<<"studentss_num: "<<studentss_num<<endl;
            int j;
            for(j=0;j<classroom_num;j++)if(classroom[j].name==class_num)break;
            classroom[j].students_num=studentss_num;
            //cout<<"j: "<<j<<endl;
            string a;
            for(int k=0;k<classroom[j].students_num;k++)
            {
                ifs>>a;
                classroom[j].students[k]=a;
                for(int q=0;q<student_num;q++)
                    if(stu[q].name==a)stu[q].Class=classroom[j].course.name;
            }
        }
        ifs.close();
    }
    void write_class_student()
    {
        ofstream of("E:\\综合管理系统 vs2.0\\class_student.txt",ios::out);
        if(!of)cout<<"打开文件失败!\n";
        for(int i=0;i<classroom_num;i++)
        {
            int cnt=classroom[i].students_num;
            of<<classroom[i].name<<" "<<cnt<<" ";
            for(int j=0;j<cnt;j++)of<<classroom[i].students[j]<<" ";
            of<<"\n";
        }
        of.close();
    }
};
class Teacher{
public:
    manager man;
    teacher ones;
    Teacher()
    {
        Read_ones_Teacher();
    }
    void quit_class()
    {
        int i;
        for(i=0;i<man.classroom_num;i++)
            if(man.classroom[i].teacher==ones.name)break;
        if(i==man.classroom_num)
        {
            cout<<"----------------\n";
            cout<<"|您还未加入班级|\n";
            cout<<"----------------\n";
            return;
        }
        int j;
        for(j=0;j<man.teacher_num;j++)
            if(man.te[j].name==ones.name)break;
        man.te[j].Class="";
        ones.Class="";
        man.classroom[i].teacher="";
        man.write_class();
        man.write_Teacher();
        cout<<"---------------\n";
        cout<<"|成功退出班级!|\n";
        cout<<"---------------\n";
    }
    void Register()
    {
        teacher t;
        cout<<"请输入姓名|性别|电话号\n";
        cout<<"|->请输入姓名:";
        cin>>t.name;
        cout<<"|->请输入性别:";
        cin>>t.sex;
        cout<<"|->请输入电话号:";
        cin>>t.tele_num;
        t.account=Account_teacher;
        man.te[man.teacher_num++]=t;
        man.write_Teacher();
        ones=t;
    }
    void Read_ones_Teacher()
    {
        bool exist=false;//是否存在账户
        for(int i=0;i<man.teacher_num;i++)
            if(man.te[i].account==Account_teacher)
            {
                cout<<"-----------------------\n";
                cout<<"|已有账户,即将登入账户|\n";
                cout<<"-----------------------\n";
                ones=man.te[i];
                exist=true;
                break;
            }
        if(!exist)
        {
            cout<<"------------------------\n";
            cout<<"|您是新账户,请注册信息!|\n";
            cout<<"------------------------\n";
            Register();
        }
    }
    void Display()
    {
        cout<<"---------------------------------------------------------------------------\n";
        cout<<"姓名: "<<ones.name<<"     性别: "<<ones.sex<<"     电话号码: "<<ones.tele_num;
        if(!ones.Class.empty())cout<<"     授课班级: "<<ones.Class<<endl;
        else cout<<"    暂时没有授课任务\n";
        cout<<"---------------------------------------------------------------------------\n";
    }
    void Display_class(){
        int pos;
        for(pos=0;pos<man.classroom_num;pos++)
            if(ones.Class==man.classroom[pos].course.name)break;
        if(pos==man.classroom_num)
        {
            cout<<"-----------------\n";
            cout<<"|您还未加入班级!|\n";
            cout<<"-----------------\n";
            return;
        }
        cout<<"-----------------------------------\n";
        cout<<"班级名称:"<<man.classroom[pos].name<<endl;
        cout<<"班级课程:"<<man.classroom[pos].course.name<<endl;
        cout<<"班级成员:";
        for(int i=0;i<man.classroom[pos].students_num;i++)cout<<man.classroom[pos].students[i]<<" ";
        cout<<endl;
        cout<<"-----------------------------------\n";
    }
    void join_class()
    {
        if(!ones.Class.empty())
        {
            cout<<"---------------------------------\n";
            cout<<"|您已加入班级，不能加入其他班级!|\n";
            cout<<"---------------------------------\n";
            return;
        }
        cout<<"----------------------------------------------------------------\n";
        cout<<"以下是所有班级名单: \n";
        cout<<"班级: ";
        for(int i=0;i<man.classroom_num;i++)cout<<man.classroom[i].name<<"   ";cout<<endl;
        cout<<"----------------------------------------------------------------\n";
        cout<<"|->请输入班级名称:";
        string b;
        cin>>b;
        bool one=false,two=false;
        int i,j;
        for(i=0;i<man.classroom_num;i++)
            if(man.classroom[i].name==b)
            {
                two=true;
                break;
            }
        if(!two)
        {
            cout<<"---------------\n";
            cout<<"|不存在该班级!|\n";
            cout<<"---------------\n";
            return;
        }
        if(!man.classroom[i].teacher.empty())
        {
            cout<<"---------------------------------\n";
            cout<<"|该班级已存在授课老师，禁止加入!|\n";
            cout<<"---------------------------------\n";
            return ;
        }
        man.classroom[i].teacher=ones.name;
        man.write_class();
        ones.Class=man.classroom[i].course.name;
        cout<<"-------------------\n";
        cout<<"|老师成功加入班级!|\n";
        cout<<"-------------------\n";
    }
    void Display_Student()
    {
        int pos;
        for(pos=0;pos<man.classroom_num;pos++)
            if(ones.Class==man.classroom[pos].course.name)break;
        if(pos==man.classroom_num)
        {
            cout<<"-----------------\n";
            cout<<"|您还未加入班级!|\n";
            cout<<"-----------------\n";
            return;
        }
        cout<<"|->输入学生姓名:";
        string a;
        cin>>a;
        int pos_2,i;
        for(pos_2=0;pos_2<man.classroom[pos].students_num;pos_2++)
            if(a==man.classroom[pos].students[pos_2])break;
        if(pos_2==man.classroom[pos].students_num)
        {
            cout<<"---------------\n";
            cout<<"|不存在该学生!|\n";
            cout<<"---------------\n";
            return;
        }
        for(i=0;i<man.student_num;i++)if(a==man.stu[i].name)break;
        cout<<"----------------------------------------------\n";
        cout<<"姓名: "<<man.stu[i].name<<"     性别: "<<man.stu[i].sex<<"     年龄: "<<man.stu[i].age<<endl;
        cout<<"----------------------------------------------\n";
    }
    void Invite_student_join_class()
    {
        int pos;
        for(pos=0;pos<man.classroom_num;pos++)
            if(ones.Class==man.classroom[pos].course.name)break;
        if(pos==man.classroom_num)
        {
            cout<<"-----------------\n";
            cout<<"|您还未加入班级!|\n";
            cout<<"-----------------\n";
            return;
        }
        cout<<"-----------------\n";
        cout<<"以下为所有学生姓名:\n";
        for(int i=0;i<man.student_num;i++)cout<<man.stu[i].name<<endl;
        cout<<"-----------------\n";
        cout<<"|->请输入学生姓名:";
        string a;
        cin>>a;
        bool exist=false;
        int data1;
        for(int i=0;i<man.student_num;i++)
        {
            if(man.stu[i].name==a)
            {
                exist=true;
                data1=i;
                break;
            }
        }
        if(!exist)
        {
            cout<<"---------------\n";
            cout<<"|不存在该学生!|\n";
            cout<<"---------------\n";
            return ;
        }
        for(int i=0;i<man.classroom[pos].students_num;i++)
        {
            if(a==man.classroom[pos].students[i])
            {
                cout<<"--------------------------\n";
                cout<<"|该学生在班级中,加入失败!|\n";
                cout<<"--------------------------\n";
                return;
            }
        }
        if(!man.stu[data1].Class.empty())
        {
            cout<<"--------------------------------\n";
            cout<<"|该学生已加入其他班级,加入失败!|\n";
            cout<<"--------------------------------\n";
            return;
        }
        man.classroom[pos].students[man.classroom[pos].students_num++]=a;
        man.write_class_student();
        cout<<"-----------\n";
        cout<<"|加入成功!|\n";
        cout<<"-----------\n";
    }
    void Delete_student()
    {
        int pos;
        for(pos=0;pos<man.classroom_num;pos++)
            if(ones.Class==man.classroom[pos].course.name)break;
        if(pos==man.classroom_num)
        {
            cout<<"-----------------\n";
            cout<<"|您还未加入班级!|\n";
            cout<<"-----------------\n";
            return;
        }
        cout<<"|->请输入学生姓名:";
        string a;
        cin>>a;
        bool exist1=false,exist2=false;
        int data1=0,data2=0;
        for(int i=0;i<man.student_num;i++)
        {
            if(man.stu[i].name==a)
            {
                exist1=true;
                data1=i;
                break;
            }
        }
        for(int i=0;i<man.classroom[pos].students_num;i++)
        {
            if(a==man.classroom[pos].students[i])
            {
                exist2=true;
                data2=i;
                break;
            }
        }
        if(!exist1||!exist2)
        {
            cout<<"---------------\n";
            cout<<"|不存在该学生!|\n";
            cout<<"---------------\n";
            return ;
        }
        else
        {
            for(int i=data2;i<man.classroom[pos].students_num;i++)
                man.classroom[pos].students[i]=man.classroom[pos].students[i+1];
            man.classroom[pos].students_num--;
            man.write_class_student();
            cout<<"-------------------\n";
            cout<<"|该学生已退出班级!|\n";
            cout<<"-------------------\n";
        }
    }
};
class Student{
public:
    student stu;
    manager m;
    Student()
    {
        Read_ones_student();
    }
    void Read_ones_student()
    {
        bool exist=false;//是否存在账户
        for(int i=0;i<m.student_num;i++)
            if(m.stu[i].account==Account_student)
            {
                cout<<"-----------------------\n";
                cout<<"|已有账户,即将登入账户|\n";
                cout<<"-----------------------\n";
                stu=m.stu[i];
                exist=true;
                break;
            }
        if(!exist)
        {
            cout<<"------------------------\n";
            cout<<"|您是新账户,请注册信息!|\n";
            cout<<"------------------------\n";
            Register();
        }

    }
    void Register()
    {
        student s;
        cout<<"|->请输入姓名:";
        cin>>s.name;
        cout<<"|->请输入性别:";
        cin>>s.sex;
        cout<<"|->请输入年龄:";
        cin>>s.age;
        s.account=Account_student;
        m.stu[m.student_num++]=s;
        m.write_Student();
        stu=s;
    }
    void Display()
    {
        cout<<"--------------------------------------------------------------------\n";
        cout<<"姓名: "<<stu.name<<"     性别: "<<stu.sex<<"     年龄: "<<stu.age;
        cout<<"     选择课程:    ";
        cout<<stu.Class<<endl;
        cout<<"--------------------------------------------------------------------\n";
    }
    void choose_course()
    {
        if(!stu.Class.empty())
        {
            cout<<"---------------\n";
            cout<<"|您已加入课程!|\n";
            cout<<"---------------\n";
            return;
        }
        cout<<"--------------------\n";
        cout<<"存在以下课程:\n";
        for(int i=0;i<m.classroom_num;i++)
            cout<<m.classroom[i].course.name<<endl;
        cout<<"--------------------\n";
        cout<<"|->请输入选择课程:";
        string a;
        cin>>a;
        int i;
        for(i=0;i<m.classroom_num;i++)if(m.classroom[i].course.name==a)break;
        if(i==m.classroom_num)
        {
            cout<<"---------------\n";
            cout<<"|不存在该班级!|\n";
            cout<<"---------------\n";
            return;
        }
        m.classroom[i].students[m.classroom[i].students_num++]=stu.name;
        m.write_class_student();
        stu.Class=a;
        cout<<"-----------\n";
        cout<<"|选课成功!|\n";
        cout<<"-----------\n";
    }
    void Display_class_message()
    {
        if(stu.Class=="")
        {
            cout<<"-----------------\n";
            cout<<"|您还未加入班级!|\n";
            cout<<"-----------------\n";
            return;
        }
        for(int i=0;i<m.classroom_num;i++){
            bool br=false;
            for(int j=0;j<m.student_num;j++)if(m.classroom[i].students[j]==stu.name)
                {
                    br=true;
                    break;
                }
            if(br)
            {
                cout<<"---------------------------------------------------------------------\n";
                cout<<"所在班级:";
                cout<<m.classroom[i].name<<"    ";
                cout<<"班级课程:"<<m.classroom[i].course.name<<"    ";
                cout<<"教师:";
                if(m.classroom[i].teacher.empty())cout<<"无     ";
                else cout<<m.classroom[i].teacher<<"    ";
                cout<<"班级成员: ";
                for(int j=0;j<m.classroom[i].students_num;j++)cout<<m.classroom[i].students[j]<<" ";
                cout<<endl;
                cout<<"---------------------------------------------------------------------\n";
            }
        }
    }
    void quit_class()
    {

        int data1,data2;
        if(stu.Class=="")
        {
            cout<<"-----------------\n";
            cout<<"|您还未加入班级!|\n";
            cout<<"-----------------\n";
            return;
        }
        for(data1=0;data1<m.classroom_num;data1++)
            if(stu.Class==m.classroom[data1].course.name)break;
        for(data2=0;data2<m.classroom[data1].students_num;data2++)
            if(stu.name==m.classroom[data1].students[data2])break;
        for(int i=data2;i<m.classroom[data1].students_num;i++)
            m.classroom[data1].students[i]=m.classroom[data1].students[i+1];
        m.classroom[data1].students_num--;
        m.write_class_student();
        cout<<"-------------\n";
        cout<<"|已退出班级!|\n";
        cout<<"-------------\n";
        stu.Class="";
    }
};
int main()
{
    Role:int i=Initial();
    Identity_verification ID;
    int a;bool Authentication=false;
    while(1){
        switch(i){
            case 1:
            {
                cout<<"------------------------------\n";
                cout<<"|欢迎进入管理员系统!!!:      |\n";
                cout<<"|                            |\n";
                cout<<"|           操作             |\n";
                cout<<"|        1.登入账号          |\n";
                cout<<"|        2.注册账号          |\n";
                cout<<"|        3.退出程序          |\n";
                cout<<"|                            |\n";
                cout<<"------------------------------\n";
                cout<<"|->请输入代号数字选择操作:";
                cin>>a;
                if(a==1)
                    Authentication=ID.Read_Account_manager();
                if(a==2)
                    ID.enroll_manager();
                if(a==3)return 0;
                break;
            }
            case 2:
            {
                cout<<"------------------------------\n";
                cout<<"|欢迎进入老师系统!!!:        |\n";
                cout<<"|                            |\n";
                cout<<"|           操作             |\n";
                cout<<"|        1.登入账号          |\n";
                cout<<"|        2.注册账号          |\n";
                cout<<"|        3.退出程序          |\n";
                cout<<"|                            |\n";
                cout<<"------------------------------\n";
                cout<<"|->请输入代号数字选择操作:";
                cin>>a;
                if(a==1)
                    Authentication=ID.Read_Account_teacher();
                if(a==2)
                    ID.enroll_teacher();
                if(a==3)return 0;
                break;
            }

            case 3:
            {
                cout<<"------------------------------\n";
                cout<<"|欢迎进入学生系统!!!:        |\n";
                cout<<"|                            |\n";
                cout<<"|           操作             |\n";
                cout<<"|        1.登入账号          |\n";
                cout<<"|        2.注册账号          |\n";
                cout<<"|        3.退出程序          |\n";
                cout<<"|                            |\n";
                cout<<"------------------------------\n";
                cout<<"|->请输入代号数字选择操作:";
                cin>>a;
                if(a==1)
                    Authentication=ID.Read_Account_Student();
                if(a==2)
                    ID.enroll_student();
                if(a==3)return 0;
                break;
            }
            default:
                cout<<"--------------------------\n";
                cout<<"|警告!请在三种身份中选择!|\n";
                cout<<"--------------------------\n";
        }
        if(Authentication&&a==1)
        {
            cout<<"------------------------------\n";
            cout<<"|       身份核验成功！       |\n";
            cout<<"------------------------------\n";
            system("pause");
            system("cls");
            break;
        }
        else if(!Authentication&&a==1)
        {
            cout<<"------------------------------\n";
            cout<<"|  身份核验失败,请重新输入!  |\n";
            cout<<"------------------------------\n";
        }
        else if(a==2)
        {
            cout<<"------------------------------\n";
            cout<<"|       新账户注册成功！      |\n";
            cout<<"------------------------------\n";
            system("pause");
            system("cls");
            break;
        }
        system("pause");
        system("cls");
    }
    manager m;
    if(i==1)
    {
        while(1){
            cout<<"------------------------------\n";
            cout<<"|            功能            |\n";
            cout<<"------------------------------\n";
            cout<<"|                            |\n";
            cout<<"|         1.创建班级         |\n";
            cout<<"|         2.删除班级         |\n";
            cout<<"|     3.显示所有班级信息     |\n";
            cout<<"|     4.指定老师加入班级     |\n";
            cout<<"|        5.删除老师信息      |\n";
            cout<<"|     6.显示所有老师信息     |\n";
            cout<<"|     7.显示所有同学信息     |\n";
            cout<<"|    8.返回用户身份选择界面  |\n";
            cout<<"|         0.结束程序         |\n";
            cout<<"|                            |\n";
            cout<<"------------------------------\n";
            cout<<"|->请输入代号数字选择功能:";
            int a;
            cin>>a;
            switch(a)
            {
                case 0:
                {
                    cout<<"--------------------\n";
                    cout<<"|     程序结束     |\n";
                    cout<<"--------------------\n";
                    return 0;
                }
                case 1:
                {
                    m.Creat_classroom();
                    system("pause");
                    system("cls");
                    break;
                }
                case 4:
                {
                    m.Invite_teacher();
                    system("pause");
                    system("cls");
                    break;
                }
                case 3:
                {
                    m.Display_class_message();
                    system("pause");
                    system("cls");
                    break;
                }
                case 6:
                {
                    m.Display_all_teacher();
                    system("pause");
                    system("cls");
                    break;
                }
                case 2:
                {
                    m.Delete_class();
                    system("pause");
                    system("cls");
                    break;
                }
                case 5:
                {
                    m.Delete_Teacher();
                    system("pause");
                    system("cls");
                    break;
                }
                case 8:
                {
                    system("cls");
                    goto Role;
                }
                case 7:
                {
                    m.Display_all_student();
                    system("pause");
                    system("cls");
                    break;
                }
                default:
                {
                    cout<<"输入格式不正确，请重新输入!";
                    system("pause");
                    system("cls");
                }
            }
        }
    }
    else if(i==2){
        Teacher t;
        while(1){
            cout<<"------------------------------\n";
            cout<<"|            功能            |\n";
            cout<<"------------------------------\n";
            cout<<"|                            |\n";
            cout<<"|       1.显示个人信息       |\n";
            cout<<"|         2.加入班级         |\n";
            cout<<"|       3.查看班级信息       |\n";
            cout<<"|   4.邀请学生加入自己班级   |\n";
            cout<<"|       5.查找学生信息       |\n";
            cout<<"|     6.删除所在班级某学生   |\n";
            cout<<"|    7.返回用户身份选择界面  |\n";
            cout<<"|         8.退出班级         |\n";
            cout<<"|         0.结束程序         |\n";
            cout<<"|                            |\n";
            cout<<"------------------------------\n";
            cout<<"|->请输入代号数字选择功能:";
            int a;
            cin>>a;
            switch(a)
            {
                case 0:
                {
                    cout<<"--------------------\n";
                    cout<<"|     程序结束     |\n";
                    cout<<"--------------------\n";
                    return 0;
                }
                case 1:
                {
                    t.Display();
                    system("pause");
                    system("cls");
                    break;
                }
                case 7:
                {
                    system("cls");
                    goto Role;
                    break;
                }
                case 3:
                {
                    t.Display_class();
                    system("pause");
                    system("cls");
                    break;
                }
                case 2:
                {
                    t.join_class();
                    system("pause");
                    system("cls");
                    break;
                }
                case 5:
                {
                    t.Display_Student();
                    system("pause");
                    system("cls");
                    break;
                }
                case 4:
                {
                    t.Invite_student_join_class();
                    system("pause");
                    system("cls");
                    break;
                }
                case 6:
                {
                    t.Delete_student();
                    system("pause");
                    system("cls");
                    break;
                }
                case 8:
                {
                    t.quit_class();
                    system("pause");
                    system("cls");
                    break;
                }
                default:
                {
                    cout<<"输入格式不正确，请重新输入!";
                    system("pause");
                    system("cls");
                }

            }
        }
    }
    else if(i==3){
        Student s;
        while(1){
            cout<<"------------------------------\n";
            cout<<"|            功能            |\n";
            cout<<"------------------------------\n";
            cout<<"|                            |\n";
            cout<<"|       1.显示个人信息       |\n";
            cout<<"|           2.选课           |\n";
            cout<<"|       3.查看班级信息       |\n";
            cout<<"|           4.退课           |\n";
            cout<<"|   5.返回用户身份选择界面   |\n";
            cout<<"|         0.结束程序         |\n";
            cout<<"|                            |\n";
            cout<<"------------------------------\n";
            cout<<"|->请输入代号数字选择功能:";
            int a;
            cin>>a;
            switch(a)
            {
                case 0:
                {
                    cout<<"--------------------\n";
                    cout<<"|     程序结束     |\n";
                    cout<<"--------------------\n";
                    return 0;
                }
                case 1:
                {
                    s.Display();
                    system("pause");
                    system("cls");
                    break;
                }
                case 5:
                {
                    system("cls");
                    goto Role;
                    break;
                }
                case 2:
                {
                    s.choose_course();
                    system("pause");
                    system("cls");
                    break;
                }
                case 3:
                {
                    s.Display_class_message();
                    system("pause");
                    system("cls");
                    break;
                }
                case 4:
                {
                    s.quit_class();
                    system("pause");
                    system("cls");
                    break;
                }
                default:
                {
                    cout<<"输入格式不正确，请重新输入!";
                    system("pause");
                    system("cls");
                }

            }
        }
    }
}
