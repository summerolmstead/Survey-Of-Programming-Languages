//Summer Olmstead - Extra Credit
//Scala application that demonstrates the various uses of the => operator in different contexts.
//Your code should include practical implementations of the
//following scenarios: anonymous functions (lambdas), function types and parameters, by-name
//parameters, partial functions, and pattern matching with case blocks

//i wanted to make a makeup store! so that is what the cohesive theme is
object SummeradiaMakeupStore extends App {
  // first lets do the anonymous func lambda applying discount
  val tenPercentOff = (price: Double) => price * 0.9 //ten off standard
  val shinePrice = 30.0 // fair random makeup price
  println(s"Shine Price after 10% discount: $$${tenPercentOff(shinePrice)}")

  //lets make a general price calculator with tax as our #2 requirement function types and parameters
  val priceWithTax: Double => Double = price => price * 1.07 // tn sale tax is 7 percent
  println(s"Price after tax: $$${priceWithTax(tenPercentOff(shinePrice))}")
  
// number 3 requirement of by-name parameters 
def printIf(show: Boolean, msg: => String): Unit = 
{
  if (show) println(msg)
  
}
printIf(false, { println("This won't be printed"); "Lipstick - Strawberry Red Matte" })
//there will be no output since the condition is false

  // 4 partial func - handle only select promotions for sales for certain products with different cases
  val applyPromotion: PartialFunction[String, String] = {
    case "Lipstick" => "Promo: Buy 1 Get 1 Free ONLY today!"
    case "Blush" => "Promo: 20% off this weekend!"
  }
  //calling each case
  println(applyPromotion("Lipstick"))
  println(applyPromotion("Blush"))

  //for pattern matching we can match makeup category
  val category = "Mascara"
  val categoryMatch = category match {
    //cases of where ppl are browsing
    case "Lipstick" => "You're browsing Lipsticks..."
    case "Foundation" => "You're browsing Foundations :)"
    case "Mascara" => "You're browsing Mascaras ️0-0"
    case _ => "Unknown category ;-; "
  }
  println(categoryMatch)

//lazy evaluation with theme of shipping cost 
def lazyShippingCost(weight: => Int): () => Int = () => weight

val shipping = lazyShippingCost {
  println("Calculating shipping cost...")
  7 //flat shipping cost for simplicity
}
println("Before accessing shipping")
println(s"Shipping cost: $$${shipping()}")

}