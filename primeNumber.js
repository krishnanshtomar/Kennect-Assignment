var num=9;
var y=2;
var z=0;
var x=num;
while(y<=x/2)
{
    if(x%y==0)    z=1;
    y++;
}
if(z==1)    console.log("Not a prime Number");
else    console.log("Prime Number");