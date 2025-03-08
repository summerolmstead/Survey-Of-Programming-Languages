#1)parallel assign & swapping
a, b = 1, 2 #making it one and two
puts "Before swapping: a = #{a}, b = #{b}"

#swapping values without using a temp variable
a, b = b, a #lets see if it swaps! 
puts "After swapping: a = #{a}, b = #{b}" #yes it swaps 

#2)dynamic variable using instance_variable_set
class DynamicEx
  def set_variable(name, value) #function for setting the var with the value 
    instance_variable_set("@#{name}", value) #corresponding parameter inputs when called
  end

  def get_variable(name) #now we will make a get function with just the name since the value was set already
    instance_variable_get("@#{name}") #getting name 
  end
end

#making a class object to test!
obj = DynamicEx.new
obj.set_variable("example", 17) #test with 17 :)
puts "Dynamically set variable example to: #{obj.get_variable('example')}" #returns 17!!

#3)returning multiple values at the same time during assignment
x, y, z = 11, 13, 15
puts "Returned multiple values: x = #{x}, y = #{y}, z = #{z}" #returns 11,13,15 which is good

#4) lazy evaluation with short-circuit assignment use ||= conditional
def lazy_ex
  @value ||= 100  #will set value only if it's nil or false
  puts "value: #{@value}"
end

lazy_ex  #sets it to 100 here and it just returns value: 100 which makes sense

#%)define a method dynamically using define_method
class DefineEx
  define_method(:say_hello) do
    puts "Hello World! :)" #welcoming 
  end
end

#creating object of example class for welcoming
example = DefineEx.new
example.say_hello  #outputs: Hello World! :)