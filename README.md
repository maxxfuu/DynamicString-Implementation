# DynamicString-Implementation
The "DynamicString Implementation" project focuses on developing a custom string class named my_str in C++

# Key Ideas 
- Value Categories 
- Move & Copy Semantics 

Move Semantics Takes in R-Value Semantics. 
Assigning the Pointer to a new to the exisiting buffer variable. 
- Shallow & Deep Copy 

# Function Explanations. 
String type copy assignment operator. First, the function accepts a constant refence types. It then checks the current object with the object that it's trying to compare to. If both objects are different have different address than both objects are different. We then free the temporary memory called buffer and create a deep copy of the new object buffer using strdup(s.buffer); And then we copy the capacity. After this process we return the object using this*. This function would be invoked when using it as such. StringType a, b;    a = b;            Which invokes the copy assignment operator. 

