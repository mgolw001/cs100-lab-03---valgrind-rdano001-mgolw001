#include "person.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

Person::Person(const char *name_, Person* father_, Person* mother_){
<<<<<<< HEAD
    name = new char[strlen(name_)+1];
=======
    name = new char[strlen(name_)+1]; // have to add +1 because strcpy takes in the null space after as well, so needs more length
>>>>>>> f2ec427e26ec82bac6bcad84c13dfd1c551022f0
    strcpy(name, name_);
    father =  father_;
    mother =  mother_;
    capacity = 1;
    numChildren = 0;
    children = new Person*[capacity];
}

Person::~Person(){
    delete [] children;
    delete [] name;
<<<<<<< HEAD
   // delete father;//unsure if this needs to be deleted
   // delete mother;//unsure if this needs to be deleted
=======
    //delete father;//unsure if this needs to be deleted
    //delete mother;//unsure if this needs to be deleted
>>>>>>> f2ec427e26ec82bac6bcad84c13dfd1c551022f0
}

void Person::addChild(Person *newChild){
    if(numChildren == capacity) expand(&children, &capacity);
    children[numChildren++] = newChild;
}

void Person::printAncestors(){
    cout << endl << "Ancestors of " << name << endl;
    printLineage('u', 0);
}

void Person::printDecendents(){
    cout << endl << "Decendents of " << name << endl;
    printLineage('d', 0);
}

void Person::printLineage(char dir, int level){
    char *temp = compute_relation(level);

    if(dir == 'd'){
        for(int i = 0; i < numChildren; i++){
            cout << temp << "child: " << children[i]->getName() << endl;
            children[i]->printLineage(dir, level + 1);
        }
    } else {
        if(mother){
            cout << temp << "mother: " << mother->getName() << endl;
            mother->printLineage(dir, level + 1);
        }
        if(father){
            cout << temp << "father: " << father->getName() << endl;
            father->printLineage(dir, level + 1);
        }
    }
<<<<<<< HEAD
   delete[] temp;
=======
  delete[] temp; // delete temp for compute_relation
>>>>>>> f2ec427e26ec82bac6bcad84c13dfd1c551022f0
}

/* helper function to compute the lineage
* if level = 0 then returns the empty string
* if level >= 1 then returns ("great ")^(level - 1) + "grand "
*/

//new is used may be causing a leak
char* Person::compute_relation(int level){
    if(level == 0) return strcpy(new char[1], "");

    char *temp = strcpy(new char[strlen("grand ") + 1], "grand ");;
    
    for(int i = 2; i <= level; i++){
        char *temp2 = new char[strlen("great ") + strlen(temp) + 1];
        strcat(strcpy(temp2, "great "), temp);
<<<<<<< HEAD
        delete[] temp;
=======
        delete[] temp; //delete old memory so can hold new memory
>>>>>>> f2ec427e26ec82bac6bcad84c13dfd1c551022f0
        temp = temp2;
    }
    return temp;
}

/* non-member function which doubles the size of t
 * NOTE: t's type will be a pointer to an array of pointers
 */
void expand(Person ***t, int *MAX){
  Person **temp = new Person*[2 * *MAX];
  memcpy(temp, *t, *MAX * sizeof(**t));
  *MAX *= 2;
<<<<<<< HEAD
  delete[] *t; 
  *t = temp;
=======
  delete[] *t; // have to delete the memory address of the old array to hold to new array's address
  *t = temp;
  //delete temp;//unsure if this is the correct delete 
>>>>>>> f2ec427e26ec82bac6bcad84c13dfd1c551022f0
  }
