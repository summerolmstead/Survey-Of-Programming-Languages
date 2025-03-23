//Summer Olmstead | Assignment 10 Scala
//cant run all at once but i just seperate what you would paste into onecompiler.com with the dashes --- as per problem 
//----

//Problem 4: Tuple-Based Student Grades with Enhanced Features
//Process student grades and determine the highest and lowest grades with an additional feature to
//calculate the average grade.
//It is recommended to use (part or all of) Tuples (storing student name and grade), Lists
//(processing multiple records) Subprograms (methods to process student grades), Pattern
//Matching (extracting values from tuples)

class StudentGrades {
// Subprogram to find the highest and lowest grades
def findGradeExtremes(grades: List[(String, Int)]): (String, Int, String, Int) = {
//you can use maxBy, minBy
//think about using _
val highest = grades.maxBy(_._2)  //finds the student with the highest grade
val lowest = grades.minBy(_._2)   //finds the student with the lowest grade
(highest._1, highest._2, lowest._1, lowest._2)
}

// Subprogram to calculate the average grade
def calculateAverage(grades: List[(String, Int)]): Double = {
val total = grades.map(_._2).sum // gets all grades and sums the grades
total.toDouble / grades.length   // calculates the average by diving by length
}

// Subprogram to display results
def displayResults(grades: List[(String, Int)]): Unit = {
// To complete
// students grades all printed with other info too 
println("Student Grades:")
//for loop for each student with their grade use previous defined functions to call the lowest, hgihest, and average out of all of them
grades.foreach { case (name, grade) => println(s"$name: $grade") }
val (highestName, highestGrade, lowestName, lowestGrade) = findGradeExtremes(grades)
val average = calculateAverage(grades)
//print out indiviudal results
println(s"\nHighest Grade: $highestName with $highestGrade")
println(s"Lowest Grade: $lowestName with $lowestGrade")
println(f"Average Grade: $average%.2f")
}
}
object StudentGradesApp {
def main(args: Array[String]): Unit = {
// create your list and call for calculations
//making a list of students with ariations of my name lol
val students = List(("Summer", 99), ("Sum", 92), ("Remmus", 78), ("Sumet", 90), ("Mer", 88))
//ok now making an object of this class of grades
val studentGrades = new StudentGrades
studentGrades.displayResults(students) //getting results of class to see basically summary statistics
}
}


//----- next problem 

//problem 3

//Problem 3: List Processing with Multiple Subprograms
//Filter and transform a list of numbers with additional subprograms to handle different
//transformations.
//It is recommended to use (part or all of) Lists (list manipulation), Higher-Order Functions
//(map, filter), Subprograms (a class with utility methods to process lists).
class ListProcessor {
// Subprogram to filter even numbers – nothing to add here :)
def filterEvenNumbers(numbers: List[Int]): List[Int] = numbers.filter(_ % 2 == 0)

// Subprogram to filter odd numbers
// To complete
def filterOddNumbers(numbers: List[Int]): List[Int] = numbers.filter(_ % 2 != 0) // doesnt have remainder of 0 when diving by zero

// Subprogram to square each number
// To complete
def squareNumbers(numbers: List[Int]): List[Int] = numbers.map(x => x * x) // just mapping it to times it by itself 

// Subprogram to double each number
// To complete
def doubleNumbers(numbers: List[Int]): List[Int] = numbers.map(x => x * 2) // map it again but times by two to double 

// Subprogram to display results
def displayResults(title: String, list: List[Int]): Unit = {
//printing
println(s"$title: " + list.mkString(", "))
}
}

object ListProcessorApp {
def main(args: Array[String]): Unit = {
val processor = new ListProcessor
// create a list of numbers
// call the subprograms above and display the results
val numbers = List(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) //example list just 1-10
//calling all our functions we just defined
val evens = processor.filterEvenNumbers(numbers)
val odds = processor.filterOddNumbers(numbers)
val squared = processor.squareNumbers(numbers)
val doubled = processor.doubleNumbers(numbers)
//results
processor.displayResults("Original List", numbers)
processor.displayResults("Even Numbers", evens)
processor.displayResults("Odd Numbers", odds)
processor.displayResults("Squared Numbers", squared)
processor.displayResults("Doubled Numbers", doubled)
}
}

//---

//Problem 5: Inventory Management with Stack-Dynamic Local Variables (similar to problem 3)
//Simulate an inventory system where products can be added, removed, and queried.
//It is recommended to use (part or all of) Maps (Key-Value Pair Structure), Subprograms with
//Stack-Dynamic Local Variables, Nested Functions
//remark the use of nested functions
object InventoryManager {
def manageInventory(): Unit = {
var inventory: Map[String, Int] = Map() // Stack-dynamic variable
def addProduct(product: String, quantity: Int): Unit = {
//update inventory
// just in case if the product exists add to its current quantity or just add product and start at 0
inventory = inventory.updated(product, inventory.getOrElse(product, 0) + quantity)
println(s"Added $quantity of $product. Updated stock: ${inventory(product)}") //printline to show if worked
}

def removeProduct(product: String, quantity: Int): Unit = {
//it is good to use case here
inventory.get(product) match { 
  //enough stock is available subtract the requested quantity
  case Some(stock) if stock >= quantity =>
  inventory = inventory.updated(product, stock - quantity)
  println(s"Removed $quantity of $product. Remaining stock: ${inventory(product)}")
  
  //if not enough available to remove
  case Some(stock) =>
  println(s"Cannot remove $quantity of $product. There is only $stock left. :(")

  //if case doesnt exist then 
  case None =>
  println(s"$product not found in inventory!")
}
}
//nothing to add here :)
def checkStock(product: String): Unit = {
println(s"Stock for $product: " + inventory.getOrElse(product, 0))
}
// Test the functions - makeup store! lol
addProduct("Dior Blush", 50)  
addProduct("Tarte Tube Mascara", 5)  
checkStock("Dior Blush")       
removeProduct("Tarte Tube Mascara", 3) 
removeProduct("Dior Blush", 300)
removeProduct("Fenty Highlighter", 10) 
checkStock("Tarte Tube Mascara")      
}
def main(args: Array[String]): Unit = {
manageInventory()
}
}

//----

//Problem 1: Implement a program to perform Set operations (union, intersection, and
//difference) while incorporating additional subprograms for enhanced functionality.
//It is recommended to use (part or all of) Sets (storing unique elements, performing set
//operations), Tuples (returning multiple results), Subprograms (a class with utility methods).
// Define a class to handle set operations
class SetOperations {
// Subprogram to perform set operations
def computeOperations(set1: Set[Int], set2: Set[Int]): (Set[Int], Set[Int], Set[Int]) = {
// to complete
val unionSet = set1.union(set2) //combining all elements from both sets by union
val intersectionSet = set1.intersect(set2) //common elements in both sets like inner join by intersection 
val differenceSet = set1.diff(set2) //find elements in set1 that are NOT in set2 by diff func

(unionSet, intersectionSet, differenceSet) //return the results as a tuple!
}
// Subprogram to display results
def displayResults(result: (Set[Int], Set[Int], Set[Int])): Unit = {
// to complete printing
//just print the result for each one we do in previous 
println(s"Union: ${result._1}")         
println(s"Intersection: ${result._2}")
println(s"Difference: ${result._3}")    
}
}
// Companion object to handle execution
object SetOperationsApp {
def main(args: Array[String]): Unit = {
//create an object of setOperations
//create a few sets to be tested and display the operations results (union, intersection,etc.
val setOperations = new SetOperations() //object of SetOperations
//need some overlap so will make 3-5
val setA: Set[Int] = Set(1, 2, 3, 4, 5) //1 test set
val setB: Set[Int] = Set(3, 4, 5, 6, 7) //2 test set

val results = setOperations.computeOperations(setA, setB) //doing operations defined earlier in function
setOperations.displayResults(results) //results!!
}
}


