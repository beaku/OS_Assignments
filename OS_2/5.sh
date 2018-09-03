echo "Enter number: "
read num
 
remainder=$(( $num % 2))
 
if [ $remainder -eq 0 ]
then
  echo "$num is even number"
else
  echo "$num is odd number"
fi
