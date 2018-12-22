#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <stdio.h>

using namespace std;

int check = 0;   

int limit = 99;

struct StudentRec 

{
    string Name;                       
   
    string ID;                
   
    string Programme;
   
    double GPA;        
   
    bool compare(StudentRec valid)   
   
    {
        if(Name == valid.Name && ID == valid.ID && Programme == valid.Programme && GPA == valid.GPA) 
            return true;                                            
                return false;                                      
    }
};

void read_a_record(StudentRec students[100], int &limit) 

{

    StudentRec cow;
    
    int check = 0;
    
	string full, 
    
	lastnm,  
    
	firstnm,  
    
	id,    
	
	Programme, 
    
    name;
    
	double gpa;  
    
	ifstream file; 
    
	file.open("StudentRecords.txt"); 
    
	if (!file)
  
    for(int x = 0;x <= check; x++)  
  
    {
        file >> firstnm >> lastnm >> id >> gpa; 
    }
  
    name = lastnm + ", " +firstnm;
  
    cow.Name = name;  
  
    cow.ID = id; 
  
    cow.GPA = gpa;
	   
    cow.Programme;
    
	file.close();   
  
    check++;      
}

void print_a_record(StudentRec show) 

{

    cout
  
    << left << setw(15) << show.Name
  
    << setw(11) << show.ID
    
	<< setw(7) << show.Programme
    
    << setw(3) << fixed << setprecision(2) <<  show.GPA << endl;
}


int end()

{
    return 0;
}

void addsrecord (StudentRec students[100], int &limit)

{

StudentRec apple;

string full;

string lname; 

string fname; 

string id;

string Programme;

double gpa; 

int location=limit+1;

if(location == 99)

{
    cout << "Error, array has been exceded!!" << endl;
    return;
}

limit ++;

cout << "Please enter the students last name.." << endl;
    cin >> lname;

cout << "Please enter the students first name.." << endl;
    cin >> fname;

    full = lname + ", " + fname;

    apple.Name = full;

cout << "Please enter the student Id number beginning with M for Male or F for Female" << endl;
    cin >> id;

    apple.ID = id;

cout << "Please enter the type of Programme" <<endl;
    cin >> Programme;
    
    apple.Programme = Programme;

cout << "Please enter the students GPA" << endl;
    cin >> gpa;

    apple.GPA = gpa;

students[location]= apple;

}

void disall (StudentRec students[100], int limit)

{

    int x;                                                      
    
      
	cout << left << setw(5) << "No." << left << setw(15) << "Name" << setw(11) << "ID" << setw(7) << "Programme" << setw(3) << "GPA" << endl;
    
	cout << "--------------------------------------------------------------------\n";
    
    for(x = 0; x <= limit; x++)
    {
        
	    cout << x+1 << ".   ";          
        
		print_a_record(students[x]);
        
}

}
void delsrecord ()
{
}

void findsrecord(StudentRec students[100], int limit)

{
    string input;
    
	cout << "Enter the ID number of the student you wish to find (M or F ########) " << endl;
    cin >> input;
    
    int count;
    for (count=0; count <= limit; count++)
    
	{
        if(students[count].ID == input)
       
	{
	    cout << "Student has been found." << endl;
        
		cout << "Name: " << students[count].Name << endl << "GPA: " << students[count].GPA << endl <<
     
	    "ID: " << students[count].ID << endl << "Programme: " << students[count].Programme << endl;
     
	    return;
    }
        cout << count << limit << endl;
      
	    if (count==limit)
      
	    {
            cout << "Can't find student!" << endl;
        }
       
	    else
       
	    {
            continue;
        }
    }
}

void save (StudentRec students [], int limit)

{
    ofstream file;

    file.open("StudentRecords.txt");

    string temper; 

    for(int p =0; p <=limit; p++)

    {
        file << students[p].Name<< " " << students[p].ID << " " << students[p].Programme << " " << students[p].GPA << endl;
    }

    file.close ();

}


void displayMenu(StudentRec students [100])
{
    cout << endl;
  
    cout << "Please Choose:" << endl;
  
    cout << "(1) Add a student record" << endl;
  
    cout << "(2) Delete a student record" << endl;
  
    cout << "(3) Find a student's information" << endl;
  
    cout << "(4) Display all information in the database" << endl;
  
    cout << "(5) Exit Program" << endl;
  
    int input;
  
    cin >> input;

    while (input < 1 || input > 5)
  
    {
        cout << "You did not enter a correct choice!!" << endl;
            cin >> input;
    }
    
    switch(input)
    {
        case 1: addsrecord(students,limit);
            save(students,limit);
        break;
      
	    case 2: delsrecord;
        break;
      
	    case 3: findsrecord(students,limit);
        break;
      
	    case 4: disall(students, limit);
        break;
      
	    case 5: end ();
        break;
      
	    default: cout << "You did not enter a correct choice!!" << endl;
        break;
    }
}


int main() 

{

    char loop;
    StudentRec students[100];
    read_a_record(students, limit);
    do

{
    displayMenu(students);
    cout << "To continue, Please press Y, otherwise any key to quit" << endl;
    cin >> loop;
}

    while(loop =='Y' || loop =='y');

{

return 0;

}

system("pause");

return 0;

}

