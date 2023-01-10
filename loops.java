class psp
{
public static void main(String gg[])
{
int e,f;

//while loop

e=0;
while(e<=5)
{
if(e==3)   e++;
System.out.println(e);
e++;
}

System.out.println("----------");

//if-else

if(e==6)
{
System.out.println(e);
System.out.println("----------");
}
else
{
f=3;
//swithc case
switch(f)
{
case 1:
System.out.println(f);
break;
case 2:
System.out.println(f);
break;
case 3:
System.out.println(f);
break;
default:
System.out.println(f);
}
System.out.println("----------");
}
//for loop
for(e=0;e<5;e++)    System.out.println(e);
System.out.println("----------");
}

}