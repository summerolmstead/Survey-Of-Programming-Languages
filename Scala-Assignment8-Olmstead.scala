//Note - I originally did this all on https://onecompiler.com/scala/43bwnycdd and must run each problem individually cant run all of the problems in one go bc it will only
//print one

//---1


//A company collects customer purchase records, where each purchase is represented as a tuple (customerId, product, price).
//Implement a function applyDiscount that takes a list of purchases and applies a 10% discount if the price is above $50.
//Return a new list using for-yield

object Discount extends App {
  //making a applyDiscount function where it takes in a tuple
  def applyDiscount(purchases: List[(Int, String, Double)]): List[(Int, String, Double)] = {
    for {
      (customerId, product, price) <- purchases //for these variables taken in from the tuple
      //ok lets check if apply the discount or not . if we do and its over 50 then we will just take .9 of the number to get 10% off
      discountedPrice = if (price > 50) price * 0.9 else price //if doesnt apply it will stay the same 
    } yield (customerId, product, discountedPrice) //returns in the for yield the new list 
  }
//making an example list of things  lol
  val purchases = List(
    (1, "Phone", 1000.0),
    (2, "Stuffed Animal", 40.0),
    (3, "Couch", 600.0)
  )
//printing final purchases with the discount
  println(s"Final Purchases with discounts included: ${applyDiscount(purchases)}")
}


//--- 2




//Write a function findMax(lst: List[Int]): Int that:
//Uses foldLeft to find the maximum number in a list.
//If the list is empty, return Int.MinValue.
object MaxList extends App {
  //function findMax to find max int in list
  def findMax(lst: List[Int]): Int = { //taking in list with integers
  //initally setting the min value to smallest int and then checks each number to see if its bigger
    lst.foldLeft(Int.MinValue){ (max, current) =>
    //if the new current is bigger than the max then max is the current but returns max
      if (current > max) current else max
    }
  }
//random list of numbers 
  val numbers = List(10, 35, 58, 1, 98, 42)
  //printing the result with our example list 
  println(s"The Maximum number is: ${findMax(numbers)}")
  
  //lets test in the scenario its empty
  val empty = List()
  //printing the result with our example list 
  println(s"The Maximum number is: ${findMax(empty)}")
  //result seems good for if empty its -2147483648 which is the initial accumulator val Int.MinValue
}


//---3


//Counting Word Frequency Using Map
//Write a function wordCount(sentence: String): Map[String, Int] that:
//Counts the frequency of each word in the given sentence.
//Ignores case ("Scala" and "scala" should be treated the same).
//Uses foldLeft or groupBy for counting.
//Hint: you may need to use some of the following: groupBy, identity, mapValues, length, and toMap

object WordCounter extends App {
  //wordCount funct with problem question parameters 
  def wordCount(sentence: String): Map[String, Int] = {
    
    //making the sentence lower case so its easier to count all lower than the difference of lower and upper same time like Apple vs apple 
    sentence.toLowerCase
      .split("\\s+") //splitting the sentence into words based on whitespace between words 
      .groupBy(identity) //grouping the words by their identity so we create a map where the keys are words and we can make how many times it show up as the value 
      .mapValues(_.length) //counting how many times each word shows up 
      .toMap  // convert the result to a strict map
  }
//making a prompt for user to input sentence 
  println("Enter a sentence:")
  //reading input line 
  val sentence = scala.io.StdIn.readLine()
  //printing our map of word count for our result
  println(s"Word count: ${wordCount(sentence)}")
  //tested and it works correctly! 
}



//---4  https://onecompiler.com/scala/43bwru8yd



//Lazy Evaluation with Fibonacci Sequence
//Write a function lazyFibonacci(): LazyList[Int] that generates an infinite Fibonacci 
//sequence using lazy evaluation.

object Lazy extends App {
  //lazy fibonacci function w lazy list parameter 
  def lazyFibonacci(): LazyList[Int] = {
    //nested function inside of the outer lazyfib function taking in a and b
    //only regenerates a when it needs to recursively by the old b is the new a and the new b is a+b
    def fib(a: Int, b: Int): LazyList[Int] = a #:: fib(b, a + b)
    //begins with 0 and 1 
    fib(0, 1)
  }
  //ok putting a ten limit so it doesnt keep generating for a long time bc it wont compute lol 
  val fibSeq = lazyFibonacci() //storing function results in this value to call
  //first 20 Fibonacci numbers.... putting in list because i dont like how alternatively it printing multiple lines
  println(fibSeq.take(20).toList)
}


