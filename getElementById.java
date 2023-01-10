// to compile : java -classpath c:\mysqljar\*;. getElementById.java

import java.util.*;
import java.math.*;
import java.sql.*;

class psp
{
public static void main(String gg[])
{
int actualEmployeeId=100003;

try
{
Class.forName("com.mysql.cj.jdbc.Driver");
Connection connection=DriverManager.getConnection("jdbc:mysql://localhost:3306/tmdb","tmdbuser","tmdbuser");
PreparedStatement preparedStatement;
preparedStatement=connection.prepareStatement("select employee.id,employee.name,employee.designation_code,designation.title,employee.date_of_birth,employee.gender,employee.is_indian,employee.basic_salary,employee.pan_number,employee.aadhar_card_number from employee inner join designation on employee.designation_code=designation.code and id=?");
preparedStatement.setInt(1,actualEmployeeId);
ResultSet resultSet=preparedStatement.executeQuery();
if(resultSet.next()==false)
{
resultSet.close();
preparedStatement.close();
connection.close();
System.out.println("Invalid employee id. : "+actualEmployeeId);
return;
}
int id;
String name;
int designationCode;
String title;
java.sql.Date dateOfBirth;
String gender;
boolean isIndian;
BigDecimal basicSalary;
String panNumber;
String aadharCardNumber;
id=resultSet.getInt("id");
name=resultSet.getString("name").trim();
designationCode=resultSet.getInt("designation_code");
title=resultSet.getString("title").trim();     //trim is very important
dateOfBirth=resultSet.getDate("date_of_birth");
gender=resultSet.getString("gender");
isIndian=resultSet.getBoolean("is_indian");
basicSalary=resultSet.getBigDecimal("basic_salary");
panNumber=resultSet.getString("pan_number").trim();
aadharCardNumber=resultSet.getString("aadhar_card_number").trim();

System.out.println("EmplyeeId : "+id);
System.out.println("Name : "+name);
System.out.println("Designation Code : "+designationCode);
System.out.println("Title : "+title);
System.out.println("Date Of Birth : "+dateOfBirth);
System.out.println("Gender : "+gender);
System.out.println("Nationality : "+isIndian);
System.out.println("Basic Salary : "+basicSalary);
System.out.println("PAN Number : "+panNumber);
System.out.println("Aadhar Card Number : "+aadharCardNumber);

resultSet.close();
preparedStatement.close();
connection.close();
}catch(Exception exception)
{
System.out.println(exception.getMessage());
}

}
}