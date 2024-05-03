#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;

class school {
private:
    int yearinschool, phonenumber, clas, RollNum;
    string name, fathername, subject, lastname, qualifications;
public:
	school() : name(""), fathername(""),phonenumber(11),clas(0),RollNum(0){};
	
	void get_rollNum(int rollnum) {
        RollNum = rollnum;
    }
    void get_Name(string nam) {
        name = nam;
    }
    void get_FatherName(string fname) {
        fathername = fname;
    }
    void get_subject(string sub) {
        subject = sub;
    }
    void get_lastName(string Lname) {
        lastname = Lname;
    }
    void get_number(int num) {
        phonenumber = num;
    }
    void get_yearinschool(int yisl) {
        yearinschool = yisl;
    }
    void get_clas(int cl) {
        clas = cl;
    }
    void get_qualifications(string qlfcations) {
        qualifications = qlfcations;
    }
    string get_name() {
        return name;
    }
    string get_fathername() {
        return fathername;
    }
    string get_subject() {
        return subject;
    }
    string get_lastName() {
        return lastname;
    }
    string get_qualifications() {
        return qualifications;
    }
    int get_yearinschool() {
        return yearinschool;
    }
    int get_phonenumber() {
        return phonenumber;
    }
    int get_clas() {
        return clas;
    }
    int get_rollNum(){
    	return RollNum;
	}
};

void waitforenter(){
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    cin.get();
}
void studentinfo(){

	main:
	system("cls");
    string nam, fname;
    int choice, num, cl,rollnum;

    cout << "\t\tStudent Information" << endl << endl;
    cout << "\n\t(1). Add Student" << endl;
    cout << "\n\t(2). Find Student" << endl;
    cout << "\n\t(3). Delete Student" << endl;
    cout << "\n\t(4). All Student Data" << endl;
    cout << "\n\t(5). Exit" << endl;
    cout << "\n\tEnter Your Choice 1 to 5: ";
    cin >> choice;

switch (choice) {
	case 1:{
		school sys;
		start:
        system("cls");
        cout << "\n\t\tStudent Information" << endl << endl;
        
        cout << "\tEnter Student Roll Number: ";
        cin>> rollnum;
//Roll Number Checker IF it ALready Exixts.....		
        ifstream infile("StudentDetailes.txt");
        if (!infile){
        	cout<<"Error: File opening Error";
        	break;
		}
		string line;
		bool found = false;
		while(getline(infile,line)){
			stringstream ss(line);
			int rnum;
			ss >> rnum;
	
        if (rollnum == rnum){
        	found = true;
        	cout<<"\tRoll Number Already Exists "<<endl;
        	waitforenter();
        	goto start;
        	break;
    }}
    if(!found){
	
        sys.get_rollNum(rollnum);
        }
//Roll Number Checker End.....
        
       cout << "\n\tEnter Student Name: ";
       cin.ignore();
	    getline(cin,nam);
	    sys.get_Name(nam);

        cout << "\n\tEnter Student Father Name: ";
        getline(cin, fname);
        sys.get_FatherName(fname);

        cout << "\n\tEnter Student Class: ";
        cin>> cl;
        sys.get_clas(cl);

        cout << "\n\tEnter Phone Number: ";
        cin>>num;
        sys.get_number(num);
        
       ofstream outfile("StudentDetailes.txt", ios::app);
       
       
    if (!outfile) {
        cout << "\n\tError: File opening error" << endl;
        return;
    }
		
			outfile << sys.get_rollNum() <<" : "<< sys.get_name() << " : " << sys.get_fathername() << " : " << sys.get_clas() << " : " << sys.get_phonenumber() << endl << endl;
			cout<<"\n\tStudent Data successfully Added!"<<endl;
			outfile.close();
			waitforenter();
			goto main;
			break;
	
		}
case 2:{
	
	school sys;
		int rnum,rolnum;
        system("cls");
        cout << "\n\t\tFind Student" << endl << endl;
        cout<<"\n\tEnter Student Roll Number: ";
        cin>>rnum;
        
        ifstream outfile("StudentDetailes.txt");
        if (!outfile){
        	cout<<"\n\tError: File opening error";
        	return;
		}

		string line;
		bool found = false;
		while(getline(outfile,line)){
			stringstream ss(line);
			string name,fname,lname,flname,rollnumber,phonenumber,clas;
			char delimiter;
			ss >> rollnumber >> delimiter >> name >> lname>> delimiter >> fname >> flname >> delimiter >> clas >> delimiter >> phonenumber;
			stringstream(rollnumber) >> rolnum;
			
			if (rnum == rolnum){
				found = true;
				cout<<"\n\tStudent Name: "<<name<<" "<<lname;
				cout<<"\n\tStudent Father Name: "<<fname<<" "<<flname;
				cout<<"\n\tStudent Class: "<<clas;
				cout<<"\n\tStudent Phone Number: "<<phonenumber;
				break;
			}
			}	if (!found){
				cout<<"\n\tError: Invalid User Roll Number"<<endl;
				waitforenter();
				break;
			}
	
		outfile.close();
		waitforenter();
		goto main;
        break;
}
case 3:{
		school sys;
		int rnum,rolnum;
        system("cls");
        cout << "\n\t\tDelete Student" << endl << endl;
        cout<<"\n\tEnter Student Roll Number: ";
        cin>>rnum;
        
        ifstream outfile("StudentDetailes.txt");
        ofstream infile("StudentTempDetailes.txt");
          
        if (!outfile ||!infile){
        	cout<<"\n\tError: File opening error";
		}

		string line;
		bool found = false;
		while(getline(outfile,line)){
			stringstream ss(line);
			string name,fname,lname,flname,rollnumber,phonenumber,clas;
			char delimiter;
			ss >> rollnumber >> delimiter >> name >> lname>> delimiter >> fname >> flname >> delimiter >> clas >> delimiter >> phonenumber;
			stringstream(rollnumber) >> rolnum;
			
			if (rnum == rolnum){
				found = true;
				cout<<"\n\tStudent Name: "<<name<<" "<<lname;
				cout<<"\n\tStudent Father Name: "<<fname<<" "<<flname;
				cout<<"\n\tStudent Class: "<<clas;
				cout<<"\n\tStudent Phone Number: "<<phonenumber<<endl<<endl;
				
				string confirmation;
				cout<<"\n\tAre you Sure You wanna Delete This Student? Y or N ";
				cin>>confirmation;
				if (confirmation == "N" || confirmation == "n"){
					infile.close();
					outfile.close();
					remove("StudentTempDetailes.txt");
					cout<<"\n\n\tYou are a Life save Of "<<rnum<<" Roll Number"<<endl;
					waitforenter();
					goto main;
					break;
					}
			}
			else{
				infile << line<<endl;
			}
		}
			infile.close();
			outfile.close();
			remove("StudentDetailes.txt");
			rename("StudentTempDetailes.txt","StudentDetailes.txt");
			cout << "\n\tAccount Deleted\n";
			waitforenter();
			goto main;
			break;
}
case 4:{
	school sys;
        system("cls");
        cout << "\n\t\tAll Students Data" << endl << endl;
        cout<<"\n\t-------------------------------------------------------"<<endl;;
        cout<<"\n\t    Name         Father Name      Class  Phone Number"<<endl;
		cout<<"\n\t-------------------------------------------------------"<<endl;
		
		ifstream outfile ("StudentDetailes.txt");
		if (!outfile){
			cout<<"\n\tError: File opening error";
		}
		else{
			string line;
		while(getline(outfile,line)){
			stringstream ss(line);
			string name,fname,lname,flname;
			int rollnumber,phonenumber,clas;
			char delimiter;
			ss >> rollnumber >> delimiter >> name >> lname>> delimiter >> fname >> flname >> delimiter >> clas >> delimiter >> phonenumber;
			cout<<"\t"<<name<<" "<<lname<<"     "<<fname<<" "<<flname<<"     "<<clas<<"     "<<phonenumber<<"\n";
		}
		}
		outfile.close();
		waitforenter();
		goto main;
		break;
}
	}	
};

//*Teacher Information Section*//
class Teacher {
private:
    string TeacherName, TeacherLastname, TeacherBloodGroup, TeacherSubject;
    int TeacherPhoneNumber, YearSchool, TeacherQualification;

public: 
    Teacher(): TeacherName(""), TeacherLastname(""), TeacherBloodGroup(""), TeacherSubject(""), TeacherPhoneNumber(0), YearSchool(0), TeacherQualification(0) {}
    
    void setTeacherName(string name) {
        TeacherName = name;
    }
    
    void setTeacherLastname(string lastname) {
        TeacherLastname = lastname;
    }
    
    void setTeacherBloodGroup(string bloodGroup) {
        TeacherBloodGroup = bloodGroup;
    }
    
    void setTeacherSubject(string subject) {
        TeacherSubject = subject;
    }
    
    void setTeacherPhoneNumber(int phoneNumber) {
        TeacherPhoneNumber = phoneNumber;
    }
    
    void setYearInSchool(int years) {
        YearSchool = years;
    }
    
    void setTeacherQualification(int qualification) {
        TeacherQualification = qualification;
    }
    
    string getTeacherName() {
        return TeacherName;
    }
    
    string getTeacherLastname() {
        return TeacherLastname;
    }
    
    string getTeacherBloodGroup() {
        return TeacherBloodGroup;
    }
    
    string getTeacherSubject() {
        return TeacherSubject;
    }
    
    int getTeacherPhoneNumber() {
        return TeacherPhoneNumber;
    }
    
    int getYearInSchool() {
        return YearSchool;
    }
    
    int getTeacherQualification() {
        return TeacherQualification;
    }
};

void AddTeacher() {
    Teacher teacher;
    string name, lastname, subject;
    int phoneNumber;
    
    system("cls");
    cout << "\n\t\tTeacher Information" << endl << endl;
    
    cout << "\n\tEnter Teacher Name: ";
    cin.ignore();
    getline(cin, name);
    teacher.setTeacherName(name);
    
    cout << "\n\tEnter Teacher Lastname: ";
    getline(cin, lastname);
    teacher.setTeacherLastname(lastname);
    
    cout << "\n\tEnter Teacher's Subject: ";
    getline(cin, subject);
    teacher.setTeacherSubject(subject);
    
    cout << "\n\tEnter Teacher Phone Number: ";
    cin >> phoneNumber;
    teacher.setTeacherPhoneNumber(phoneNumber);
    
    ofstream outfile("TeacherData.txt", ios::app);
    if (!outfile) {
        cout << "\n\tError: File Opening Error...";
        return;
    }
    
    outfile << teacher.getTeacherName() << " : " << teacher.getTeacherLastname() << " : " << teacher.getTeacherSubject() << " : " << teacher.getTeacherPhoneNumber() << endl << endl;
    cout << "\n\tTeacher Data successfully Added!" << endl;
	outfile.close(); 
	waitforenter();
	return;
		
}

void findTeacehr(){
	srt:
	system("cls");
	int Nameee,rolnum;
        system("cls");
        cout << "\n\t\tFind Teacehr" << endl << endl;
        cout<<"\n\tEnter Teacehr Name: ";
        cin>>Nameee;
        
        ifstream outfile("TeacherData.txt");
        if (!outfile){
        	cout<<"\n\tError: File opening error";
        	return;
		}
		
		string line;
		bool found = false;
		while(getline(outfile, line)){
			stringstream ss(line);
			string name,name2,lastname,lastname2, subject, phonenumber;
			char delimiter;
			ss >>name >> name2>> delimiter >> lastname >> lastname2 >> delimiter >> subject >> delimiter >> phonenumber;
			
		if (name == "Nameee" || lastname == "Nameee") {
			found = true;
			cout<<"\n\tTeacher Name: "<<name<<" "<<name2<<endl;
			cout<<"\n\tTeacher Last Name: "<<lastname<<" "<<lastname2<<endl;
			cout<<"\n\tTeacher Subject: "<<subject<<endl;
			cout<<"\n\tTeacher Phone Number: "<<phonenumber<<endl;
			
			waitforenter();
			goto srt;
			break;
		}else{
			cout<<"\n\Error: Invalid Name or Last Name..."<<endl;
			goto srt;
			break;
		}
			
		}
		
        
	
	
	
}




//*Teacher Information Section*//
int main() {
	back:
    system("cls");
    int choice;

    do {
    	system("cls");
        cout << "\n\t\tschool Management System" << endl << endl;
        cout << "\n\t(1). Students Information" << endl;
        cout << "\n\t(2). Teachers Information" << endl;
        cout << "\n\t(3). Total Numbers of Teacher && Students" << endl;
        cout << "\n\t(4). Exit" << endl;
        cout << "\n\tEnter Your Choice 1 to 4: ";
        cin >> choice;

        switch (choice) {
        case 1:
            studentinfo();
            break;
        case 2:	
        srt:
        int teacher;
		system("cls");
        cout << "\n\t\tschool Management System" << endl << endl;
        cout << "\n\t(1). Add Teacer" << endl;
        cout << "\n\t(2). Find Teachers " << endl;
        cout << "\n\t(3). See All Teachers" << endl;
        cout << "\n\t(4). Exit" << endl;
        cout << "\n\tEnter Your Choice 1 to 4: ";
        cin >> teacher;
        	switch (teacher){
        		case 1:
        			AddTeacher();
        			break;
        		case 2:
        			findTeacehr();
        			break;
			}
            break;
        case 3:

            break;
        case 4:
            system("cls");
            cout << "\n\t----------Exiting Program----------" << endl;
            break;
        default:
            cout << "Enter valid Choice";
        }
    } while (choice != 4);

    return 0;
};

