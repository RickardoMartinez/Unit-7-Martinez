/* Folder/CPP: Class2_Martinez
    10-3-2023, 10-3-2023 Dr. Tyson McMillan
    Working with class (object) Data Type         and functions
    //private attributes (variables)
    //setter and getter MVC method
    //Note: I removed the spaces between the brackets that away I don't get it confused and! To make mines different from some people that love to cheat. :/ 
*/
#include<iostream>
#include<string>
using namespace std; //std:: this prevents having to type std::cout << etc.

/********GreenTea Class Declaration****/
class GreenTea 
{
    private: 
        bool delicious; 
        string nameTea; 
    public:
      void setDelicious(bool);
      bool getDelicious(); 
      void setNameTea(string);
      string getNameTea(); 
}; 

void GreenTea::setDelicious(bool d)
{
    delicious = d; 
}

bool GreenTea::getDelicious()
{
    return delicious; 	
}

void GreenTea::setNameTea(string nt)
{
    nameTea = nt; 
}

string GreenTea::getNameTea()
{
    return nameTea; 
}

/********Student Class Declaration****/
class Student 
{
    private: 
      string name;
      int id;
      char letterGrade; 
      GreenTea preference;
    public:
      void setName(string);
      string getName();
      void setId(int);
      int getId(); 
      void setLetterGrade(char);
      char getLetterGrade(); 
    void setPreference(GreenTea);
		GreenTea getPreference();  
		void printTranscript(); 
    void showStudentMenu();
};

void Student::setName(string n)
{
	name = n; 
}

string Student::getName()
{
	return name; 
}

void Student::setId(int i)
{
	id = i; 
}

int Student::getId()
{
  return id; 
}

void Student::setLetterGrade(char lg)
{
  letterGrade = lg; 
}

char Student::getLetterGrade()
{
  return letterGrade; 
}

void Student::setPreference(GreenTea p)
{
  preference = p; 
}

void Student::showStudentMenu()
{
    cout << "\nStudent Menu: " << endl;
    cout << "1. change student name" << endl;
    cout << "2. change student ID" << endl;
    cout << "3. Update Green Tea Preference" << endl;
    cout << "4. Clear the screen" << endl;
    cout << "5. Exit" << endl;
}

GreenTea Student::getPreference()
{
  return preference; 
}

void Student::printTranscript() //the member function has direct access to the member variables
{
    cout << "\nName: " << name; 
    cout << "\nID: " << id; 
    cout << "\nGrade: " <<letterGrade; 
    cout << "\nTea Name: " << preference.getNameTea(); 
	
if(preference.getDelicious() == true)
	{
    cout << "\nWell said, McMillanite, "<< preference.getNameTea() <<", green tea is great!!!" << endl; 
	}
else
	{
  cout << "\n :'(" << endl;  
	}
}
/********Function Definitions (above int main() style****/
void populateStudentWithDefaultData(Student &s)
{
	
    GreenTea ut; 
    ut.setNameTea("Matcha Green Tea - China"); 
    ut.setDelicious(true); 
	
    s.setName("YourName"); 
    s.setId(123456); 
    s.setLetterGrade('F');  
    s.setPreference(ut); 
	
    cout << "Start Data: "; 
    s.printTranscript(); 
	
}

void fnClass(Student student)
{
    cout << "\nA pass by value object process (least effective):"; 
    char newGrade = '\0';
//a function to pass a class by value
    cout << "\nINSIDE fnClass()" << endl; 
    cout << "\t" << student.getId() << ":" << student.getName() << " earned a(n): " << student.getLetterGrade();
//one can also change values in the function 
    cout << "\nWhat would like the new grade to be: ";
    cin >> newGrade; 
    student.setLetterGrade(newGrade); //change   the letter grade of the student	 
    cout << "\n\t" << student.getId() << ":" << student.getName() << " earned a(n): " <<     student.getLetterGrade();
    cout << "\nUPDATED TRANSCRIPT *** pass by value ****" << endl; 
    student.printTranscript();
}

void fnClassRef(Student &student)
{
    cout << "\nA pass by REFERENCE object process (Best method):";
    char newGrade = '\0';
//a function to pass a class by reference
    cout << "\nINSIDE fnClassRef()" << endl; 
    cout << "\t" << student.getId() << ":"     << student.getName() << " earned a(n): " <<     student.getLetterGrade();
//one can also change values in the function 
    cout << "\nWhat would like the new grade to be: ";
    cin >> newGrade; 
    student.setLetterGrade(newGrade); //change the letter grade of the student	 
    cout << "\n\t" << student.getId() << ":" << student.getName() << " earned a(n): " <<     student.getLetterGrade();
    cout << "\nUPDATED TRANSCRIPT *** pass by references (&)) ****" << endl; 
    student.printTranscript();
}

void funClassPtr(Student* student)
{
    cout << "\nA pass by pointer * object process (Alternative method):"; 
    char newGrade = '\0';
//a function to pass a class by pointer
    cout << "\nINSIDE fnClassPtr()"<< endl; 
    cout << "\t"<< student->getId()<< ":"<< student->getName() << " earned a(n): "<<         student->getLetterGrade();
//one can also change values in the function 

    cout << "\nWhat would like the new grade to be: ";
    cin >> newGrade; 
    student->setLetterGrade(newGrade); //change the letter grade of the student	 
    cout << "\n\t" << student->getId() << ":" << student->getName() << "earned a(n): "<<     student->getLetterGrade();
    cout << "\nUPDATED TRANSCRIPT *** pass by references (*)) ****" << endl; 
    student->printTranscript();
}
void changeStudentData(Student &s, int decision)
{
    string newName = "";
   
    if (decision == 1)
{
    cout << "\nWhat new name would you like?";
    cin >> newName;
    s.setName(newName);
    cout << "\nThe students new name is now " << newName << endl;
    s.printTranscript();
}
}
int main()
{	
    int decideMain = 0;
    cout << "\nPrint Undergraduate Student" << endl;
 //instances of the Student class
    Student undergraduate; 
//using a function to put initial data into the undergraduate object
    populateStudentWithDefaultData(undergraduate); //this function will also print the Start Data
    system("clear");
do
{
    
    undergraduate.showStudentMenu();
    cout << "\nWhat data would you like to change";
    cin >> decideMain;
    changeStudentData(undergraduate, decideMain);

    cout << "undergraduate current grade: ";
    cout << undergraduate.getLetterGrade();
} while(decideMain != 5);
    cout << "Exit program.";
//Populate graduate student with default Data in int main()

GreenTea gt; 
    gt.setNameTea("Sencha"); 
    gt.setDelicious(false); 
Student graduate; 
    graduate.setId(1587); 
    graduate.setName("Cool Dude");
    graduate.setLetterGrade('C'); 
    graduate.setPreference(gt); 
    cout << "\nPrint Graduate Student" << endl; 
    cout << "Start Data: ";
    graduate.printTranscript();
  
//call the print transcript function 
//****************** Triple .dot nation accessing an object within an object*******/
  
    cout << "\nI say again..." << endl;
if(graduate.getPreference().getDelicious() == true)
	{
    cout << "\nWell said, McMillanite, "<< graduate.getPreference().getNameTea() <<",       green tea is great!!!" << endl; 
	}
else
	{
    cout << "\n :'(" << endl;   //Wish it was sweet tea.
}
	
  //Passing objects to functions, and using functions to print values in the object
  fnClass(undergraduate); //pass class by value
  fnClass(graduate); //pass class by value
  fnClassRef(undergraduate);//pass class by ref
  fnClassRef(graduate);//pass class by ref
  funClassPtr(&graduate);//pass class by pointer
  funClassPtr(&undergraduate);//pass class by pointer
	
/*
//DR. T programming challenge. 
food for thought: How might I use the combination of functions and
accessing the members of the object with ( . ) notation to create 
a functional menu? i.e. A = update undergraduate student grade....
That is, on demand be able to update the private member variables
of each instantiated class (objects student and undergraduate?)? 
*/
//start creating that menu for the DR_T programming challenge here

return 0;
}