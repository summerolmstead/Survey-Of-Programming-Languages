 // link to online C++ compiler https://cpp.sh/?source=%2F%2F+Example+program%0A%23include+%3Ciostream%3E%0A%23include+%3Cstring%3E%0A%0Aint+main()%0A%7B%0A++std%3A%3Astring+name%3B%0A++std%3A%3Acout+%3C%3C+%22What+is+your+name%3F+%22%3B%0A++getline+(std%3A%3Acin%2C+name)%3B%0A++std%3A%3Acout+%3C%3C+%22Hello%2C+%22+%3C%3C+name+%3C%3C+%22!%5Cn%22%3B%0A%7D

// Summer Olmstead Assignment 7 Survery of Programming Languages 
// Singly linked list manipulation
#include <iostream>
#include <stdlib.h>
using namespace std;
struct NODE
{
int data;
NODE * next ;
};

NODE* CreateList(NODE *head)
{
return NULL;
}

NODE* DeleteList(NODE *head)
{
NODE *cur;
cur = head;

while (cur != NULL)
{
cur = head->next;
delete head;
head = cur;
}
return NULL;
}

NODE* InsertElement(NODE *head, int value, bool& result)
{
NODE *cur, *previous, *tmp;
result = false;
tmp = new NODE;
if (tmp == NULL)
return head;
tmp->data = value;
tmp->next = NULL;
if (head == NULL)
{
tmp->next = head;
head = tmp;
result = true;
return head;
}

if (value <= head->data)
{
tmp->next = head;
head = tmp;
result = true;
return head;
}

cur = head;
previous = NULL;
while ((cur != NULL) && (cur->data < value))
{
previous = cur;
cur = cur->next;
}
previous->next = tmp;
tmp->next = cur;
result = true;
return head;
}

NODE* DeleteElement(NODE *head, int value, bool& result)
{
NODE *cur, *previous;
result = false;
if (head == NULL)
return head;
if (value == head->data)
{
cur = head->next;
delete head ;
result = true;
head = cur;
return head;
}

cur = head;
while ((cur != NULL) && (cur->data != value))
{
previous = cur;
cur = cur->next;
}

if (cur == NULL)
return head;
previous->next = cur->next;
delete cur;
result = true;
return head;
}
NODE* ModifyElement(NODE *head, int oldValue, int newValue, bool& result)
{
NODE *cur;
result = false;
cur = head;
while ((cur != NULL) && (cur->data != oldValue))
cur = cur->next;
if (cur == NULL)
return head;
cur->data = newValue;
result = true;
return head;
}
NODE* SearchElement(NODE *head, int value)
{
NODE *cur;
if (head == NULL)
return head;
cur = head;;
while ((cur != NULL) && (cur->data != value))
cur = cur->next;
return cur;
}
bool IsInList(NODE *head, int value)
{
NODE *cur;
if (head == NULL)
return false;
cur = head;;
while ((cur != NULL) && (cur->data != value))
cur = cur->next;
if (cur == NULL)
return false;
return true;
}

int GetEltNbr(NODE *head)
{
NODE *cur;
int nbr = 0;
if (head == NULL)
return 0;
cur = head;
while (cur != NULL)
{
nbr++;
cur = cur->next;
}
return nbr;
}

int GetEltNbrRec(NODE *head)
{
if(!head) return 0;
return 1+ GetEltNbrRec(head->next);
}

void PrintList(NODE *head)
{
NODE *cur;
if (head == NULL)
{
cout << "The list is empty" << endl;
return;
}

cur = head;
while (cur != NULL)
{
cout << cur->data << "\t";
cur = cur->next;
}
cout << endl;
}

//function for reversing list 
void reverseList(NODE*& head) {
NODE* prev = NULL; //prev is NULL which is the end of the reversed list
NODE* current = head; //start with the head of the list
NODE* next = NULL; //next will store the next node temporarily 
while (current != NULL) {
next = current->next; //save the next node
current->next = prev; //reverse the current nodes next pointer
prev = current; //move prev to the current node
current = next; //move to the next node in the list
}
head = prev;  //after the loop, prev will be the new head to insert it backwards basically!
}

//merging function made 
NODE* mergeSortedLists(NODE* l1, NODE* l2) {
//base cases just incase if a list is empty:
if (l1 == NULL) return l2;  //if the first list is empty, return the second list
if (l2 == NULL) return l1;  //if the second list is empty, return the first list
//recursive method to keep going through to merge
if (l1->data <= l2->data) {
l1->next = mergeSortedLists(l1->next, l2);  //attach list 1's node and merge the rest
return l1;  //return l1 as the head of the merged list
} else {
l2->next = mergeSortedLists(l1, l2->next);  //attach l2's node and merge the rest
return l2;  //return l2 as the head of the merged list
}
}

//remove duplicate function!
void removeDuplicates(NODE* head) {
NODE* current = head; // first start at head  
//this is basically just to go through the list raverse the list
while (current != NULL && current->next != NULL) {
//checking if the current nodes data is equal to the next nodes data
if (current->data == current->next->data) {
NODE* tmp = current->next;
current->next = tmp->next;  //go to the next after the duplicate node
delete tmp;  //delete the duplicate node!
} else {
current = current->next;  //move to the next node if no duplicate
}
}
}



int main(int argc, char* argv[])
{
int choice = 1;
NODE *head = NULL; // starting with an empty list
NODE *tmp;
int val, val1;
bool result;

 // a predefined list to run with utilizing the InsertElement function
head = InsertElement(head, 10, result);  
head = InsertElement(head, 5, result);   
head = InsertElement(head, 20, result);  
head = InsertElement(head, 15, result);  
head = InsertElement(head, 15, result);  // adding this for example for remove duplicates function

cout << "A list of integers has been created (it will be sorted by increasing order) " << endl;

//for merge list defining earlier
NODE* head1 = NULL;
NODE* head2 = NULL; 
NODE* mergedHead = NULL;
//first list!
head1 = InsertElement(head1, 1, result);
head1 = InsertElement(head1, 3, result);
head1 = InsertElement(head1, 5, result);
//second list! 
head2 = InsertElement(head2, 2, result);
head2 = InsertElement(head2, 4, result);
head2 = InsertElement(head2, 6, result);

while (choice != 0)
{
cout << endl
<< " ======================" << endl
<< " 1: InsertElement() : " << endl
<< " 2: DeleteElement() : " << endl
<< " 3: SearchElement() : " << endl
<< " 4: IsInList() : " << endl
<< " 5: ModifyElement() : " << endl
<< " 6: PrintList() : " << endl
<< " 7: GetEltNbr() : " << endl
<< " 8: DeleteList() : " <<endl
<< " 9: GetEltNbrRec() : " << endl
<< " 10:reverseList() : " << endl
<< " 11:mergeSortedLists() : " << endl
<< " 12:removeDuplicates() : " << endl

<< " ======================" << endl
<< " 0: Quit" << endl
<< " ======================" << endl
<< endl
<< "Your Choice : ";
cin >> choice;
cout << endl;
switch(choice)
{
case 1 :
cout << "Type the element's value : ";
cin >> val;
head = InsertElement(head, val, result);
if (result == false)
{
cout << "Insertion failed " << val << endl;
head = DeleteList(head);
exit(0);
}
else
cout << "The value "<< val << " has been added" << endl;
break;

case 2 :
cout << "Type the value to delete : ";
cin >> val;
head = DeleteElement(head, val, result);
if (result == false)
cout << "Deletion failed : " << val << endl;
else
cout << "The value "<< val << " has been deleted" << endl;
break;

case 3 :
cout << "Type the value to search : ";
cin >> val;
tmp = SearchElement(head, val);
if (tmp == NULL)
cout << val << "is not in the list" << endl;
else
cout << "The value "<< val << "is in the list with address : " << tmp << endl;
break;

case 4 :
cout << "type the value to search : ";
cin >> val;
if (IsInList(head, val))
cout << val << " is in the list" << endl;
else
cout << val << " is not in the list " << endl;
break;

case 5 :
cout << "Type the old value : ";
cin >> val;
cout <<endl << "Type the new value : ";
cin >> val1;
head = ModifyElement(head, val, val1, result);
if (result == false)
cout << "Modification failed " << val << " en "<< val1
<<endl;
else
cout << "The value "<< val << " has been modified " << val1
<<endl;
break;

case 6 :
PrintList(head);
break;

case 7 :
cout << "The list contains " << GetEltNbr(head) << " elements."<<
endl;
break;

case 8 :
head= DeleteList(head);
cout<<"The list has been deleted " << endl;
break;

case 9 :
cout << "The list contains " << GetEltNbrRec(head) << " elements."<< endl;
break;

case 10 :
cout << "Original List: ";
PrintList(head);  //show the original list
reverseList(head); //using our reverse the list
cout << "Reversed List: "; //print the reversed list
PrintList(head);  //show the list after our reservsed function
break;

case 11: // defined lists earlier before switch to avoid errors
//printing both lists to demonstrate it 
cout << "List 1: ";
PrintList(head1);  
cout << "List 2: ";
PrintList(head2);   
//lets merge the lists with our function made 
mergedHead = mergeSortedLists(head1, head2);
cout << "Merged List: "; //result list after calling our function earlier 
PrintList(mergedHead);   
break;

case 12: 
removeDuplicates(head);  // removeDuplicates function made earlier to remove duplicates from the list
cout << "List after removing duplicates: ";
PrintList(head); 
break;

//last quit case 
case 0 :
break;
}
}
head = DeleteList(head);
cout << "The list has been deleted " << endl;
return 0;
}