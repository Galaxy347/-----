#include <bits/stdc++.h>
using namespace std;
string Account_teacher;
string Account_student;
int Initial()
{
    cout<<"------------------------------\n";
    cout<<"|  ��ӭʹ�ð༶����ϵͳ2.0!  |\n";
    cout<<"------------------------------\n";
    cout<<"|��ѡ�������������:         |\n";
    cout<<"|                            |\n";
    cout<<"|          1.����Ա          |\n";
    cout<<"|          2.��ʦ            |\n";
    cout<<"|          3.ѧ��            |\n";
    cout<<"|                            |\n";
    cout<<"------------------------------\n";
    cout<<"|->�������������ѡ�����:";
    int a;
    cin>>a;
    system("cls");
    return a;
}//��ʼ��
//�˺���
class Identity_verification{
public:
    bool Read_Account_manager()
    {
        string a;
        cout<<"|->�������˺�:";
        cin>>a;
        Account=a;
        cout<<"|->����������:";
        cin>>a;
        password=a;
        ifstream ifs("E:\\�ۺϹ���ϵͳ vs2.0\\account_manager.txt",ios::in);
        if(!ifs)cout<<"���ļ�ʧ��!\n";
        while(!ifs.eof()){
            string ac,pa;
            ifs>>ac>>pa;
            if(ac==Account&&pa==password)return true;
        }
        ifs.close();
        return false;
    }//��ȡ����Ա�˺�����
    bool Read_Account_teacher()
    {
        string a;
        cout<<"|->�������˺�:";
        cin>>a;
        Account=a;
        Account_teacher=a;
        cout<<"|->����������:";
        cin>>a;
        password=a;
        ifstream ifs("E:\\�ۺϹ���ϵͳ vs2.0\\account_teacher.txt",ios::in);
        if(!ifs)cout<<"���ļ�ʧ��!\n";
        while(!ifs.eof()){
            string ac,pa;
            ifs>>ac>>pa;
            if(ac==Account&&pa==password)return true;
        }
        ifs.close();
        return false;
    }//��ȡ��ʦ�˺�����
    bool Read_Account_Student()
    {
        string a;
        cout<<"|->�������˺�:";
        cin>>a;
        Account=a;Account_student=a;
        cout<<"|->����������:";
        cin>>a;
        password=a;
        ifstream ifs("E:\\�ۺϹ���ϵͳ vs2.0\\account_student.txt",ios::in);
        if(!ifs)cout<<"���ļ�ʧ��!\n";
        while(!ifs.eof()){
            string ac,pa;
            ifs>>ac>>pa;
            if(ac==Account&&pa==password)return true;
        }
        ifs.close();
        return false;
    }//��ȡѧ���˺�����
    void enroll_manager()
    {
        ofstream of("E:\\�ۺϹ���ϵͳ vs2.0\\account_manager.txt",ios::app);
        if(!of)cout<<"���ļ�ʧ��!\n";
        string a,b;
        cout<<"|->�������˺�:";cin>>a;
        cout<<"|->����������:";cin>>b;
        of<<a<<" "<<b<<" \n";
        of.close();
    }//�������Աע���˺�����
    void enroll_teacher()
    {
        ofstream of("E:\\�ۺϹ���ϵͳ vs2.0\\account_teacher.txt",ios::app);
        if(!of)cout<<"���ļ�ʧ��!\n";
        string a,b;
        cout<<"|->�������˺�:";cin>>a;Account_teacher=a;
        cout<<"|->����������:";cin>>b;
        of<<a<<" "<<b<<"\n";
        of.close();
    }//������ʦע���˺�����
    void enroll_student()
    {
        ofstream of("E:\\�ۺϹ���ϵͳ vs2.0\\account_student.txt",ios::app);
        if(!of)cout<<"���ļ�ʧ��!\n";
        string a,b;
        cout<<"|->�������˺�:";cin>>a;Account_student=a;
        cout<<"|->����������:";cin>>b;
        of<<a<<" "<<b<<"\n";
        of.close();
    }//����ѧ��ע���˺�����
private:
    string Account,password;
};//�˺ź���
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
        cout<<"|->������༶����:";
        string a;
        cin>>a;
        cout<<"|->����γ�����:";
        name=a;
        cin>>course.name;
    }
    void Display_classroom()
    {
        cout<<"-------------------------------------------------------------------------------------\n";
        cout<<"�༶����Ϊ: "<<name<<"     ";
        cout<<"��ؿγ�: "<<course.name<<"      ";
        if(teacher.empty())cout<<"����ʦ�ڿ�    ";
        else cout<<teacher<<"��ʦ�ڿ�   ";
        cout<<"�༶����Ϊ:"<<students_num<<endl;
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
    manager()//�ļ���־���������������
    {
        Read_Student();
        Read_Teacher();
        Read_class();//��ȡ�༶��Ϣ
        Read_class_student();//��ȡ�༶��ѧ����ϵ��Ϣ
    }
    void Creat_classroom()
    {
        Classroom c;
        c.Creat_a_classroom();
        cout<<"------------------------------\n";
        cout<<"|          �����ɹ���        |\n";
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
        ifstream ifs("E:\\�ۺϹ���ϵͳ vs2.0\\class_message.txt",ios::in);
        if(!ifs)cout<<"���ļ�ʧ��!\n";
//        while(!ifs.eof()){
//            Course c;
//            ifs>>classroom[classroom_num].name>>c.name;
//            classroom[classroom_num].course=c;
//            if(ifs.fail())break;
//            classroom_num++;
//        }
//���ַ�����ȡ����ֻ����ÿ�й̶�������������̫ʵ��
//���������ַ�����ȡ����ÿ�������������ޣ��Ƚ�ʵ��
        string op;int num;//������¼ÿһ�ж�ȡ���ٸ�����
        classroom_num=0;
        while(getline(ifs,op)){
            num=0;string b="";
            classroom[classroom_num].students_num=0;
            for(int i=0;i<op.size();i++){
                if(op[i]!=' ')b+=op[i];
                else
                {
                    //cout<<"��ȡ����bΪ: "<<b<<endl;
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
        ofstream of("E:\\�ۺϹ���ϵͳ vs2.0\\class_message.txt",ios::out);
        if(!of)cout<<"���ļ�ʧ��!\n";
        for(int i=0;i<classroom_num;i++)
        {
            of<<classroom[i].name<<" "<<classroom[i].course.name<<" ";
            if(!classroom[i].teacher.empty())of<<classroom[i].teacher;
            of<<" \n";//�ӿո���Ϊ�˷����ȡ�������ʷ�ֹ��������
        }
        of.close();
    }
    void Invite_teacher()
    {
        cout<<"------------------------------------------------------------\n";
        cout<<"������������ʦ�����Ͱ༶����: \n";
        cout<<"��ʦ: ";for(int i=0;i<teacher_num;i++)cout<<te[i].name<<"   ";cout<<endl;
        cout<<"�༶: ";for(int i=0;i<classroom_num;i++)cout<<classroom[i].name<<"   ";cout<<endl;
        cout<<"------------------------------------------------------------\n";
        cout<<"|->��������ʦ����:";
        string a,b;
        cin>>a;
        cout<<"|->�༶����:";
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
            cout<<"|      ��ʦ�ɹ�����༶!     |\n";
            cout<<"------------------------------\n";
        }
        else if(!one||!two)
        {
            cout<<"------------------------------\n";
            cout<<"|��������ʦ��༶������ʧ��! |\n";
            cout<<"------------------------------\n";
        }
        else if(!classroom[i].teacher.empty())
        {
            cout<<"----------------------------------\n";
            cout<<"|�ð༶�Ѿ������ڿ���ʦ,����ʧ��!|\n";
            cout<<"----------------------------------\n";
        }
        else if(!te[j].Class.empty())
        {
            cout<<"------------------------------\n";
            cout<<"|����ʦ���н�ѧ����,����ʧ��!|\n";
            cout<<"------------------------------\n";
        }
    }
    void Read_Teacher()
    {
        ifstream ifs("E:\\�ۺϹ���ϵͳ vs2.0\\teacher.txt",ios::in);
        if(!ifs)cout<<"���ļ�ʧ��!\n";
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
        ofstream of("E:\\�ۺϹ���ϵͳ vs2.0\\teacher.txt",ios::out);
        if(!of)cout<<"���ļ�ʧ��!\n";
        for(int i=0;i<teacher_num;i++)of<<te[i].account<<" "<<te[i].name<<" "<<te[i].sex<<" "<<te[i].tele_num<<"\n";
        of.close();
    }
    void Read_Student()
    {
        ifstream ifs("E:\\�ۺϹ���ϵͳ vs2.0\\student.txt",ios::in);
        if(!ifs)cout<<"���ļ�ʧ��!\n";
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
        ofstream of("E:\\�ۺϹ���ϵͳ vs2.0\\student.txt",ios::out);
        if(!of)cout<<"���ļ�ʧ��!\n";
        for(int i=0;i<student_num;i++)
            of<<stu[i].account<<" "<<stu[i].name<<" "<<stu[i].sex<<" "<<stu[i].age<<"\n";
        of.close();
    }
    void Display_all_teacher()
    {
        cout<<"------------------------------------------------------------------------------\n";
        for(int i=0;i<teacher_num;i++)
        {
            cout<<"����: "<<te[i].name<<"     �Ա�: "<<te[i].sex<<"     �绰����: "<<te[i].tele_num;
            if(!te[i].Class.empty())cout<<"     �ڿΰ༶: "<<te[i].Class;
            else cout<<"    ��ʱû���ڿ�����";
        }
        cout<<"\n------------------------------------------------------------------------------\n";
    }
    void Display_all_student()
    {
        cout<<"------------------------------------------------------------------------------\n";
        for(int i=0;i<student_num;i++)
        {
            cout<<"����: "<<stu[i].name<<"     �Ա�: "<<stu[i].sex<<"     ����: "<<stu[i].age<<"     ����γ�:"<<stu[i].Class;
            cout<<endl;
        }
        cout<<"------------------------------------------------------------------------------\n";
    }
    void Delete_class()
    {
        cout<<"|->�����뱻ɾ���༶����: ";
        string a;
        cin>>a;
        int pos;
        for(pos=0;pos<classroom_num;pos++)if(classroom[pos].name==a)break;
        if(pos==classroom_num)
        {
            cout<<"--------------\n";
            cout<<"|�����ڸð༶|\n";
            cout<<"--------------\n";
            return;
        }
        if(!classroom[pos].teacher.empty())
        {
            cout<<"----------------------------------------------------\n";
            cout<<"|��⵽�ð༶�����ڿ���ʦ......����ɾ����ʦ�ڿ���Ϣ|\n";
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
        cout<<"|          ɾ���ɹ���        |\n";
        cout<<"------------------------------\n";
        write_class();
        write_class_student();
    }
    void Delete_Teacher()
    {
        cout<<"|->�����뱻ɾ����ʦ����: ";
        string a;
        cin>>a;
        int pos;
        for(pos=0;pos<teacher_num;pos++)if(te[pos].name==a)break;
        if(pos==teacher_num)
        {
            cout<<"--------------\n";
            cout<<"|�����ڸ���ʦ|\n";
            cout<<"--------------\n";
            return;
        }
        if(!te[pos].Class.empty())
        {
            cout<<"-----------------------------------------\n";
            cout<<"|��⵽����ʦ���ڿ����񣬼������.......|\n";
            cout<<"-----------------------------------------\n";
            for(int i=0;i<classroom_num;i++)
                if(te[pos].Class==classroom[i].course.name)
                {
                    //cout<<"��ʦ����:"<<classroom[i].teacher<<endl;
                    classroom[i].teacher="";
                    break;
                }
            write_class();
        }
        for(int i=pos;i<teacher_num;i++)te[i]=te[i+1];
        teacher_num--;
        cout<<"------------------------------\n";
        cout<<"|          ɾ���ɹ���        |\n";
        cout<<"------------------------------\n";
        write_Teacher();
    }
    void Read_class_student()
    {
        ifstream ifs("E:\\�ۺϹ���ϵͳ vs2.0\\class_student.txt",ios::in);
        if(!ifs)cout<<"���ļ�ʧ��!\n";
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
        ofstream of("E:\\�ۺϹ���ϵͳ vs2.0\\class_student.txt",ios::out);
        if(!of)cout<<"���ļ�ʧ��!\n";
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
            cout<<"|����δ����༶|\n";
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
        cout<<"|�ɹ��˳��༶!|\n";
        cout<<"---------------\n";
    }
    void Register()
    {
        teacher t;
        cout<<"����������|�Ա�|�绰��\n";
        cout<<"|->����������:";
        cin>>t.name;
        cout<<"|->�������Ա�:";
        cin>>t.sex;
        cout<<"|->������绰��:";
        cin>>t.tele_num;
        t.account=Account_teacher;
        man.te[man.teacher_num++]=t;
        man.write_Teacher();
        ones=t;
    }
    void Read_ones_Teacher()
    {
        bool exist=false;//�Ƿ�����˻�
        for(int i=0;i<man.teacher_num;i++)
            if(man.te[i].account==Account_teacher)
            {
                cout<<"-----------------------\n";
                cout<<"|�����˻�,���������˻�|\n";
                cout<<"-----------------------\n";
                ones=man.te[i];
                exist=true;
                break;
            }
        if(!exist)
        {
            cout<<"------------------------\n";
            cout<<"|�������˻�,��ע����Ϣ!|\n";
            cout<<"------------------------\n";
            Register();
        }
    }
    void Display()
    {
        cout<<"---------------------------------------------------------------------------\n";
        cout<<"����: "<<ones.name<<"     �Ա�: "<<ones.sex<<"     �绰����: "<<ones.tele_num;
        if(!ones.Class.empty())cout<<"     �ڿΰ༶: "<<ones.Class<<endl;
        else cout<<"    ��ʱû���ڿ�����\n";
        cout<<"---------------------------------------------------------------------------\n";
    }
    void Display_class(){
        int pos;
        for(pos=0;pos<man.classroom_num;pos++)
            if(ones.Class==man.classroom[pos].course.name)break;
        if(pos==man.classroom_num)
        {
            cout<<"-----------------\n";
            cout<<"|����δ����༶!|\n";
            cout<<"-----------------\n";
            return;
        }
        cout<<"-----------------------------------\n";
        cout<<"�༶����:"<<man.classroom[pos].name<<endl;
        cout<<"�༶�γ�:"<<man.classroom[pos].course.name<<endl;
        cout<<"�༶��Ա:";
        for(int i=0;i<man.classroom[pos].students_num;i++)cout<<man.classroom[pos].students[i]<<" ";
        cout<<endl;
        cout<<"-----------------------------------\n";
    }
    void join_class()
    {
        if(!ones.Class.empty())
        {
            cout<<"---------------------------------\n";
            cout<<"|���Ѽ���༶�����ܼ��������༶!|\n";
            cout<<"---------------------------------\n";
            return;
        }
        cout<<"----------------------------------------------------------------\n";
        cout<<"���������а༶����: \n";
        cout<<"�༶: ";
        for(int i=0;i<man.classroom_num;i++)cout<<man.classroom[i].name<<"   ";cout<<endl;
        cout<<"----------------------------------------------------------------\n";
        cout<<"|->������༶����:";
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
            cout<<"|�����ڸð༶!|\n";
            cout<<"---------------\n";
            return;
        }
        if(!man.classroom[i].teacher.empty())
        {
            cout<<"---------------------------------\n";
            cout<<"|�ð༶�Ѵ����ڿ���ʦ����ֹ����!|\n";
            cout<<"---------------------------------\n";
            return ;
        }
        man.classroom[i].teacher=ones.name;
        man.write_class();
        ones.Class=man.classroom[i].course.name;
        cout<<"-------------------\n";
        cout<<"|��ʦ�ɹ�����༶!|\n";
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
            cout<<"|����δ����༶!|\n";
            cout<<"-----------------\n";
            return;
        }
        cout<<"|->����ѧ������:";
        string a;
        cin>>a;
        int pos_2,i;
        for(pos_2=0;pos_2<man.classroom[pos].students_num;pos_2++)
            if(a==man.classroom[pos].students[pos_2])break;
        if(pos_2==man.classroom[pos].students_num)
        {
            cout<<"---------------\n";
            cout<<"|�����ڸ�ѧ��!|\n";
            cout<<"---------------\n";
            return;
        }
        for(i=0;i<man.student_num;i++)if(a==man.stu[i].name)break;
        cout<<"----------------------------------------------\n";
        cout<<"����: "<<man.stu[i].name<<"     �Ա�: "<<man.stu[i].sex<<"     ����: "<<man.stu[i].age<<endl;
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
            cout<<"|����δ����༶!|\n";
            cout<<"-----------------\n";
            return;
        }
        cout<<"-----------------\n";
        cout<<"����Ϊ����ѧ������:\n";
        for(int i=0;i<man.student_num;i++)cout<<man.stu[i].name<<endl;
        cout<<"-----------------\n";
        cout<<"|->������ѧ������:";
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
            cout<<"|�����ڸ�ѧ��!|\n";
            cout<<"---------------\n";
            return ;
        }
        for(int i=0;i<man.classroom[pos].students_num;i++)
        {
            if(a==man.classroom[pos].students[i])
            {
                cout<<"--------------------------\n";
                cout<<"|��ѧ���ڰ༶��,����ʧ��!|\n";
                cout<<"--------------------------\n";
                return;
            }
        }
        if(!man.stu[data1].Class.empty())
        {
            cout<<"--------------------------------\n";
            cout<<"|��ѧ���Ѽ��������༶,����ʧ��!|\n";
            cout<<"--------------------------------\n";
            return;
        }
        man.classroom[pos].students[man.classroom[pos].students_num++]=a;
        man.write_class_student();
        cout<<"-----------\n";
        cout<<"|����ɹ�!|\n";
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
            cout<<"|����δ����༶!|\n";
            cout<<"-----------------\n";
            return;
        }
        cout<<"|->������ѧ������:";
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
            cout<<"|�����ڸ�ѧ��!|\n";
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
            cout<<"|��ѧ�����˳��༶!|\n";
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
        bool exist=false;//�Ƿ�����˻�
        for(int i=0;i<m.student_num;i++)
            if(m.stu[i].account==Account_student)
            {
                cout<<"-----------------------\n";
                cout<<"|�����˻�,���������˻�|\n";
                cout<<"-----------------------\n";
                stu=m.stu[i];
                exist=true;
                break;
            }
        if(!exist)
        {
            cout<<"------------------------\n";
            cout<<"|�������˻�,��ע����Ϣ!|\n";
            cout<<"------------------------\n";
            Register();
        }

    }
    void Register()
    {
        student s;
        cout<<"|->����������:";
        cin>>s.name;
        cout<<"|->�������Ա�:";
        cin>>s.sex;
        cout<<"|->����������:";
        cin>>s.age;
        s.account=Account_student;
        m.stu[m.student_num++]=s;
        m.write_Student();
        stu=s;
    }
    void Display()
    {
        cout<<"--------------------------------------------------------------------\n";
        cout<<"����: "<<stu.name<<"     �Ա�: "<<stu.sex<<"     ����: "<<stu.age;
        cout<<"     ѡ��γ�:    ";
        cout<<stu.Class<<endl;
        cout<<"--------------------------------------------------------------------\n";
    }
    void choose_course()
    {
        if(!stu.Class.empty())
        {
            cout<<"---------------\n";
            cout<<"|���Ѽ���γ�!|\n";
            cout<<"---------------\n";
            return;
        }
        cout<<"--------------------\n";
        cout<<"�������¿γ�:\n";
        for(int i=0;i<m.classroom_num;i++)
            cout<<m.classroom[i].course.name<<endl;
        cout<<"--------------------\n";
        cout<<"|->������ѡ��γ�:";
        string a;
        cin>>a;
        int i;
        for(i=0;i<m.classroom_num;i++)if(m.classroom[i].course.name==a)break;
        if(i==m.classroom_num)
        {
            cout<<"---------------\n";
            cout<<"|�����ڸð༶!|\n";
            cout<<"---------------\n";
            return;
        }
        m.classroom[i].students[m.classroom[i].students_num++]=stu.name;
        m.write_class_student();
        stu.Class=a;
        cout<<"-----------\n";
        cout<<"|ѡ�γɹ�!|\n";
        cout<<"-----------\n";
    }
    void Display_class_message()
    {
        if(stu.Class=="")
        {
            cout<<"-----------------\n";
            cout<<"|����δ����༶!|\n";
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
                cout<<"���ڰ༶:";
                cout<<m.classroom[i].name<<"    ";
                cout<<"�༶�γ�:"<<m.classroom[i].course.name<<"    ";
                cout<<"��ʦ:";
                if(m.classroom[i].teacher.empty())cout<<"��     ";
                else cout<<m.classroom[i].teacher<<"    ";
                cout<<"�༶��Ա: ";
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
            cout<<"|����δ����༶!|\n";
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
        cout<<"|���˳��༶!|\n";
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
                cout<<"|��ӭ�������Աϵͳ!!!:      |\n";
                cout<<"|                            |\n";
                cout<<"|           ����             |\n";
                cout<<"|        1.�����˺�          |\n";
                cout<<"|        2.ע���˺�          |\n";
                cout<<"|        3.�˳�����          |\n";
                cout<<"|                            |\n";
                cout<<"------------------------------\n";
                cout<<"|->�������������ѡ�����:";
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
                cout<<"|��ӭ������ʦϵͳ!!!:        |\n";
                cout<<"|                            |\n";
                cout<<"|           ����             |\n";
                cout<<"|        1.�����˺�          |\n";
                cout<<"|        2.ע���˺�          |\n";
                cout<<"|        3.�˳�����          |\n";
                cout<<"|                            |\n";
                cout<<"------------------------------\n";
                cout<<"|->�������������ѡ�����:";
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
                cout<<"|��ӭ����ѧ��ϵͳ!!!:        |\n";
                cout<<"|                            |\n";
                cout<<"|           ����             |\n";
                cout<<"|        1.�����˺�          |\n";
                cout<<"|        2.ע���˺�          |\n";
                cout<<"|        3.�˳�����          |\n";
                cout<<"|                            |\n";
                cout<<"------------------------------\n";
                cout<<"|->�������������ѡ�����:";
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
                cout<<"|����!�������������ѡ��!|\n";
                cout<<"--------------------------\n";
        }
        if(Authentication&&a==1)
        {
            cout<<"------------------------------\n";
            cout<<"|       ��ݺ���ɹ���       |\n";
            cout<<"------------------------------\n";
            system("pause");
            system("cls");
            break;
        }
        else if(!Authentication&&a==1)
        {
            cout<<"------------------------------\n";
            cout<<"|  ��ݺ���ʧ��,����������!  |\n";
            cout<<"------------------------------\n";
        }
        else if(a==2)
        {
            cout<<"------------------------------\n";
            cout<<"|       ���˻�ע��ɹ���      |\n";
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
            cout<<"|            ����            |\n";
            cout<<"------------------------------\n";
            cout<<"|                            |\n";
            cout<<"|         1.�����༶         |\n";
            cout<<"|         2.ɾ���༶         |\n";
            cout<<"|     3.��ʾ���а༶��Ϣ     |\n";
            cout<<"|     4.ָ����ʦ����༶     |\n";
            cout<<"|        5.ɾ����ʦ��Ϣ      |\n";
            cout<<"|     6.��ʾ������ʦ��Ϣ     |\n";
            cout<<"|     7.��ʾ����ͬѧ��Ϣ     |\n";
            cout<<"|    8.�����û����ѡ�����  |\n";
            cout<<"|         0.��������         |\n";
            cout<<"|                            |\n";
            cout<<"------------------------------\n";
            cout<<"|->�������������ѡ����:";
            int a;
            cin>>a;
            switch(a)
            {
                case 0:
                {
                    cout<<"--------------------\n";
                    cout<<"|     �������     |\n";
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
                    cout<<"�����ʽ����ȷ������������!";
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
            cout<<"|            ����            |\n";
            cout<<"------------------------------\n";
            cout<<"|                            |\n";
            cout<<"|       1.��ʾ������Ϣ       |\n";
            cout<<"|         2.����༶         |\n";
            cout<<"|       3.�鿴�༶��Ϣ       |\n";
            cout<<"|   4.����ѧ�������Լ��༶   |\n";
            cout<<"|       5.����ѧ����Ϣ       |\n";
            cout<<"|     6.ɾ�����ڰ༶ĳѧ��   |\n";
            cout<<"|    7.�����û����ѡ�����  |\n";
            cout<<"|         8.�˳��༶         |\n";
            cout<<"|         0.��������         |\n";
            cout<<"|                            |\n";
            cout<<"------------------------------\n";
            cout<<"|->�������������ѡ����:";
            int a;
            cin>>a;
            switch(a)
            {
                case 0:
                {
                    cout<<"--------------------\n";
                    cout<<"|     �������     |\n";
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
                    cout<<"�����ʽ����ȷ������������!";
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
            cout<<"|            ����            |\n";
            cout<<"------------------------------\n";
            cout<<"|                            |\n";
            cout<<"|       1.��ʾ������Ϣ       |\n";
            cout<<"|           2.ѡ��           |\n";
            cout<<"|       3.�鿴�༶��Ϣ       |\n";
            cout<<"|           4.�˿�           |\n";
            cout<<"|   5.�����û����ѡ�����   |\n";
            cout<<"|         0.��������         |\n";
            cout<<"|                            |\n";
            cout<<"------------------------------\n";
            cout<<"|->�������������ѡ����:";
            int a;
            cin>>a;
            switch(a)
            {
                case 0:
                {
                    cout<<"--------------------\n";
                    cout<<"|     �������     |\n";
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
                    cout<<"�����ʽ����ȷ������������!";
                    system("pause");
                    system("cls");
                }

            }
        }
    }
}
