import java.io.*;
 
// closures
interface SalutationInterface
{
public String salHello();
}
 
class psp
{
public static void main(String[] args)
{
// Lambda Expression
SalutationInterface obj = () ->
{
return "Hello, I am krishnansh";
}; 
// Calling the above interface
System.out.println(obj.salHello());
}
}